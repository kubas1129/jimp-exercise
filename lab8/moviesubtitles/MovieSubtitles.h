//
// Created by kubas1129 on 01.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <sstream>
#include <stdexcept>

namespace moviesubs {

    class MovieSubtitles {
    public:

        virtual std::string ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) =0;

    private:


    };

    class MicroDvdSubtitles : public MovieSubtitles{
    public:

        std::string ShiftAllSubtitlesBy(int delay, int fps,std::stringstream *in, std::stringstream *out) override;


    private:


    };

    class SubRipSubtitles : public MovieSubtitles{

    public:
        std::string ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) override;

    private:

    };


    ////////////////////////EXCEPTION CLASSES/////////////////////////////////////


    class MovieSubtitlesException : public std::runtime_error{
    public:
        MovieSubtitlesException(std::string message) : std::runtime_error(message) {}
    };

    ///////////////////////MICRODVD/////////////////////////////////////

    class NegativeFrameAfterShift : public MovieSubtitlesException{
    public:
        NegativeFrameAfterShift(std::string str) : MovieSubtitlesException(str) {}
    };

    class SubtitleEndBeforeStart : public MovieSubtitlesException{
    public:
        SubtitleEndBeforeStart(std::string str, int line) : line_(line), MovieSubtitlesException(str) {}
        int LineAt() const { return line_;}

    private:
        int line_=-1;
    };

    class InvalidSubtitleLineFormat : public MovieSubtitlesException{
    public:
        InvalidSubtitleLineFormat(std::string str) : MovieSubtitlesException(str) {}
    };


    class NegativeFrameRateThrowsIlegalArgument : public std::invalid_argument{
    public:
        NegativeFrameRateThrowsIlegalArgument(std::string message) : std::invalid_argument(message) {}
    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
