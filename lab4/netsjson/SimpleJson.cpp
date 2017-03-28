//
// Created by kubas1129 on 26.03.17.
//

#include "SimpleJson.h"

namespace nets{


    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {

    }

    std::string JsonValue::ToString() const {
        std::string local_value;

        if(used_type == VALUE::VECTOR)
        {
            local_value += "[";
            for(const auto &v : vec_)
            {
                local_value += v.ToString();
                local_value += ", ";
            }
            local_value = local_value.substr(0, local_value.length()-2);
            local_value += "]";
            return local_value;
        }
        else if(used_type == VALUE::MAP)
        {
            local_value += "{";
            for(const auto &v : map_)
            {
                local_value += "\"" + v.first + "\": ";
                local_value += v.second.ToString();
            }
            local_value += "}";
            return local_value;
        }
        else
        {
            return value_;
        }
    }
}