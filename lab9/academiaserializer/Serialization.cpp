//
// Created by kubas1129 on 04.05.17.
//

#include "Serialization.h"

namespace academia{


    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        (*out_serializator) << std::string("\""s + field_name + "\": "s + std::to_string(value));
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        (*out_serializator) << std::string("\""s + field_name + "\": " + std::to_string(value));
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        (*out_serializator) << std::string("\""s + field_name + "\": "s + "\""s + value + "\""s);
    }

    void JsonSerializer::Header(const std::string &object_name) {
        (*out_serializator) << std::string(object_name);
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        (*out_serializator) << std::string(object_name);
    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        (*out_serializator) << std::string("<" + field_name + ">" + std::to_string(value) + "<\\" + field_name + ">");
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        (*out_serializator) << std::string("<" + field_name + ">" + std::to_string(value) + "<\\" + field_name + ">");
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        (*out_serializator) << std::string("<" + field_name + ">" + value + "<\\" + field_name + ">");
    }

    void XmlSerializer::Header(const std::string &object_name) {
        (*out_serializator) << std::string("<" + object_name + ">");
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        (*out_serializator) << std::string("<\\" + object_name + ">");
    }
}