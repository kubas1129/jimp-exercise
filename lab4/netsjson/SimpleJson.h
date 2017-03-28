//
// Created by kubas1129 on 26.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>
#include <sstream>

namespace nets{

    enum VALUE {
        NONE = 0,
        DOUBLE = 1,
        INT = 2,
        BOOL = 3,
        STRING = 4,
        VECTOR = 5,
        MAP = 6
    };

    class JsonValue{

    public:

        //Konstruktory
        JsonValue(const double &arg){
            std::stringstream ss;
            ss<<arg;
            value_ = ss.str();
            used_type = VALUE::DOUBLE;
        }
        JsonValue(const int &arg){
            std::stringstream ss;
            ss<<arg;
            value_ = ss.str();
            used_type = VALUE::INT;
        }
        JsonValue(const char* arg){

        }
        JsonValue(const std::string &arg) {

            value_ += "\"";
            for(auto v : arg)
            {
                value_ += v;
            }
            value_ += "\"";
            used_type = VALUE::STRING;
        }
        JsonValue(bool arg) : value_((arg == true? "true":"false")) {}
        JsonValue(std::vector<JsonValue> arg) : vec_(arg), used_type(VALUE::VECTOR) {}
        JsonValue(std::map<std::string, JsonValue> arg) : map_(arg), used_type(VALUE::MAP) {}


        //Metody
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;



    private:

        std::string value_;
        std::vector<nets::JsonValue> vec_;
        std::map<std::string, nets::JsonValue> map_;
        nets::VALUE used_type {VALUE::NONE};


    };



}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
