//
// Created by kubas1129 on 11.03.17.
//

#include "Polybius.h"

using std::map;

std::string PolybiusCrypt(std::string message)
{
    map<char,int> crypt_table = MakeCryptTable();
    std::string crypted_message{""};

    for(int i = 0; i < message.length();i++)
    {
        for(const auto &n : crypt_table)
        {
            if(n.first == message[i] || (n.first+32) == message[i])
            {
                std::ostringstream osstream;
                osstream << n.second;
                crypted_message += (osstream.str());
                break;
            }else if('J' == message[i] || 'j' == message[i])
            {
                crypted_message += "24";
                break;
            }
        }
    }
    std::cout << crypted_message << std::endl;
    return crypted_message;
}

std::string PolybiusDecrypt(std::string crypted)
{
    std::map<char,int> crypt_table = MakeCryptTable();

    std::string decrypted_message{""};
    std::string temp_number{""};
    crypted += " ";
    int counter = 0;

    for(int i=0;i<crypted.length();i++)
    {
        if(counter == 1)
        {
            temp_number += crypted[i];
            int crypt_number = 0;
            std::istringstream isstream(temp_number);
            isstream >> crypt_number;
            temp_number = "";
            for(const auto &n : crypt_table)
            {
                if(n.second == crypt_number)
                {
                    decrypted_message += (n.first+32);
                    break;
                }
            }
            counter=0;
        }
        else
        {
            temp_number += crypted[i];
            counter++;
        }
    }
    return decrypted_message;
}

std::map<char,int> MakeCryptTable()
{
    map<char,int> crypt_table;
    int char_counter=65;

    for(int i =1;i<6;i++)
    {
        for(int k=1;k<6;k++)
        {
            crypt_table.emplace((char)char_counter, (i*10)+ k);
            if(char_counter == 73) char_counter++; //Dla J i j przesuwamy
            char_counter++;
        }
    }
    return crypt_table;
}

void PrintMap(const std::map<char, int> &v)
{
    bool first = true;
    for(const auto &n : v)
    {
        if(!first)
        {
            std::cout << " , ";
        }
        else
        {
            first = false;
        }
        std::cout << n.first << "->" << n.second;
    }
    std::cout << std::endl;
}
