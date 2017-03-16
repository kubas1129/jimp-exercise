//
// Created by kubas1129 on 14.03.17.
//

#include "XorCypherBreaker.h"


std::string
XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<string> &dictionary)
{
    string word = "";
    int iterator = 0;
    int found_words = 0;
    string key = "aaa";




    for(int i = 97 ; i < 123 ; i++)
    {
        key[0] =(char) i;
        for(int j = 97 ; j < 123 ; j++)
        {
            key[1] = (char) j;
            for (int k = 97; k < 123; k++)
            {
                key[2] = (char) k;
                for (char ch : cryptogram)
                {
                    if (iterator == key_length)
                    {
                        iterator = 0;
                    }
                    if ((ch ^ key[iterator]) == ' ' || (ch ^ key[iterator]) == '?' || (ch ^ key[iterator]) == '!' ||
                        (ch ^ key[iterator]) == '.')
                    {
                        if (FoundInDictionary(dictionary, word))
                        {
                            found_words++;
                            iterator++;
                            word = "";
                        }
                        else
                        {
                            word = "";
                            iterator++;
                        }
                    }
                    else
                    {
                        word += ch ^ key[iterator];
                        iterator++;
                    }
                }
                if (found_words > 17)
                {
                    return key;
                }
                else
                {
                    found_words = 0;
                }
                iterator = 0;
            }
        }
    }
    return 0;
}



bool FoundInDictionary(const std::vector<string> &dictionary, string searching) {
    int k = 0;
    while (searching[k] != '\0')
    {
        searching[k] = tolower(searching[k]);
        k++;
    }

    for(string dictionary_word : dictionary)
    {
        if(!dictionary_word.compare(searching))
        {
            return true;
        }
    }
    return false;

}
