//
// Created by kubas1129 on 01.05.17.
//

#include <iostream>
#include "MovieSubtitles.h"


namespace moviesubs{


    std::string
    MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        if(fps < 0) throw NegativeFrameRateThrowsIlegalArgument(std::to_string(fps));
        int delayInFramerate = ((delay/100)*fps)/10;
        bool waitForBrackets = true;
        std::string input = "";
        std::string temp = "";
        std::string output = "";
        int line = 0;

        if(in && out)
        {
            if(delay == 0 || fps == 0) return in->str();

            input = in->str();

            if(delayInFramerate < 0) throw NegativeFrameAfterShift(input);
        }
        else
        {
            throw MovieSubtitlesException("Plik wejsciowy lub wyjsciowy nieprawidlowy!");
        }

        char lastAddWord = '\n';
        int first_fps=-1, second_fps=-1;
        int indexBrackets=0;

        for(int i = 0; i < input.length();i++){
            if(input[i] == '{' && !(input[i+1] < '0' || input[i+1] > '9')){
                i++;
                if(first_fps == -1 && second_fps == -1) {
                    indexBrackets = i-1;
                    line++;
                }

                while(input[i] != '}'){
                    if(i == input.length()-1) throw InvalidSubtitleLineFormat(input);
                    temp += input[i];
                    i++;
                }

                if(temp == "") throw InvalidSubtitleLineFormat(input);

                if(first_fps == -1)
                {
                    first_fps = std::stoi(temp);
                    first_fps += delayInFramerate;
                    output += '{' + std::to_string(first_fps) + '}';
                    temp = "";
                }
                else
                {
                    second_fps = std::stoi(temp);
                    second_fps += delayInFramerate;
                    output += '{' + std::to_string(second_fps) + '}';
                    temp = "";
                }
            }
            else
            {

                if((first_fps != -1 && second_fps != -1) && (first_fps > second_fps))
                {
                    std::string str = "At line " + std::to_string(line) + ": " + input.substr(indexBrackets,input.length()-indexBrackets-1);
                    throw SubtitleEndBeforeStart(str, line);
                }

                if(first_fps != -1 && second_fps == -1) throw InvalidSubtitleLineFormat(input);

                output += input[i];
                lastAddWord = input[i];
                first_fps=-1;
                second_fps=-1;
            }
        }

        if(lastAddWord != '\n') output += '\n';

        out->str(output);
        return output;

    }
}