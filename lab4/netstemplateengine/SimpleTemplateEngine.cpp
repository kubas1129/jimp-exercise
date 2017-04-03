//
// Created by kubas1129 on 25.03.17.
//

#include "SimpleTemplateEngine.h"


namespace nets {


    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {

        std::string str_end = "";

        for(int i = 0; i < arg_.length();i++)
        {
            if(arg_[i] == '{' && arg_[i+1] == '{' && arg_[i+2] != '{')
            {
                std::string str_temp = "";
                i += 2; //Przeskakuje z indeksem od razu do pierwszej literki
                //zapisuje nazwe ktora musze znalezc w map-ie
                while(arg_[i] != '}')
                {
                    str_temp += arg_[i];
                    i++;
                }
                //Sprawdzamy czy nasza sekwencja konczy sie odpowiednio
                if(arg_[i+1] != '}' && arg_[i+2] != '}')
                {
                    str_end += "{{" + str_temp + arg_[i];
                    continue;
                }
                i++;
                //Szukam klucza do zamiany
                for(const auto v : model)
                {
                    if(v.first == str_temp)
                    {
                        str_end += v.second;
                        break;
                    }
                }
                continue;
            }
            str_end += arg_[i];
        }
        return str_end;
    }
}