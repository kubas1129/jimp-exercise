//
// Created by kubas1129 on 25.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>

namespace nets {

    class View {

    public:

        View(std::string arg) : arg_(arg){};


        std::string Render(const std::unordered_map <std::string, std::string> &model) const;


    private:

        std::string arg_;

    };

}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
