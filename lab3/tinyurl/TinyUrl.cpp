//
// Created by kubas1129 on 19.03.17.
//

#include "TinyUrl.h"


namespace tinyurl
{

    std::unique_ptr<TinyUrlCodec> Init()
    {
        std::unique_ptr<TinyUrlCodec> codec = std::make_unique<TinyUrlCodec>();
        return codec;
    }

    void NextHash(std::array<char, 6> *state)
    {

        if(state != nullptr)
        {
            for(int r = 5; r >= 0;r--)
            {
                if((*state)[r] == 'z')
                {
                    (*state)[r] = '0';
                    continue;
                }

                if((*state)[r] == 'Z')
                {
                    (*state)[r] = 'a';
                    break;
                }
                if((*state)[r] == '9')
                {
                    (*state)[r] = 'A';
                    break;
                }

                ++(*state)[r];
                break;
            }
        }

    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec)
    {
        std::string short_url = "http://tinyurl.com/";


        for(auto &v : (*codec)->state)
        {
           short_url += v;
        }

        (*codec)->urls.emplace(url, short_url);

        return short_url;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash)
    {
        for(auto v : codec->urls)
        {
            if(v.second == hash)
            {
                return v.first;
            }
        }

        return "Nie znaleziono!";
    }


}