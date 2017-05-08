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


    std::string
    SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        if(fps < 0) throw NegativeFrameRateThrowsIlegalArgument(std::to_string(fps));
        std::string output = "";
        std::string temp_line = "";
        int line = 0;
        int number = 1;
        const int timing_length = 29;
        if(delay == 0 || fps == 0) return in->str();

        //if(delay < 0) throw NegativeFrameAfterShift(in->str());


        while(getline(*in, temp_line))
        {

            std::regex time_searching {R"((\d{2}:\d{2}:\d{2},\d{3}) --> (\d{2}:\d{2}:\d{2},\d{3}))"};
            std::smatch match;

            if(std::regex_search(temp_line, match, time_searching))
            {
                line++;

                if(match.length() != 29) throw InvalidSubtitleLineFormat(in->str());

                std::cout << "Znazlem czas: " << temp_line << std::endl;


                int begin_hours,begin_minutes,begin_seconds,begin_miliseconds;
                int end_hours, end_minutes, end_seconds, end_miliseconds;

                int bdt = (std::stoi(std::string(temp_line, 0,1))*1000*60*60 + std::stoi(std::string(temp_line, 3,4))*60*1000 + std::stoi(std::string(temp_line, 6,7))*1000 + std::stoi(std::string(temp_line, 9,11))) + delay;
                int edt = (std::stoi(std::string(temp_line, 17,18))*1000*60*60 + std::stoi(std::string(temp_line, 20,21))*60*1000 + std::stoi(std::string(temp_line, 23,24))*1000 + std::stoi(std::string(temp_line, 26,29))) + delay;


                if(edt < bdt) {
                    std::string str = "At line " + std::to_string(line) + ": " + temp_line;
                    throw SubtitleEndBeforeStart(str, line);
                }

                if(bdt < 0) throw NegativeFrameAfterShift(in->str());


                begin_miliseconds = bdt % 1000;
                bdt /= 1000;
                begin_seconds = bdt % 60;
                bdt /= 60;
                begin_minutes = bdt % 60;
                bdt /= 60;
                begin_hours = bdt % 60;
                bdt /= 60;

                end_miliseconds = edt % 1000;
                edt /= 1000;
                end_seconds = edt % 60;
                edt /= 60;
                end_minutes = edt % 60;
                edt /= 60;
                end_hours = edt % 60;
                edt /= 60;

                output += (begin_hours<10 ? "0":"") + std::to_string(begin_hours)  + ":" + (begin_minutes<10 ? "0":"") + std::to_string(begin_minutes) + ":" + (begin_seconds<10 ? "0":"") + std::to_string(begin_seconds) + "," + (begin_miliseconds<100 ? "0":"") + std::to_string(begin_miliseconds) + " --> ";
                output += (end_hours<10 ? "0":"") + std::to_string(end_hours) + ":" + (end_minutes<10 ? "0":"") + std::to_string(end_minutes) + ":" + (end_seconds<10 ? "0":"") + std::to_string(end_seconds) + "," + (end_miliseconds<100 ? "0":"") + std::to_string(end_miliseconds);
                output += '\n';
            }
            else
            {
                std::regex exceptio_searching {R"(\d:\d)"};
                std::smatch ex_match;
                if(std::regex_search(temp_line, ex_match, exceptio_searching)) throw InvalidSubtitleLineFormat(in->str());


                std::regex number_search {R"(\d)"};
                std::smatch num_match;
                if(std::regex_search(temp_line, num_match, number_search)) {
                    if (std::stoi(temp_line) == number) {
                        number++;
                    } else {
                        throw OutOfOrderFrames(in->str());
                    }
                }


                output += temp_line;
                output += '\n';
            }
        }



        out->str(output);
        return output;

    }
}