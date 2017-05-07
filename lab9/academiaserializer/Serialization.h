//
// Created by kubas1129 on 04.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include<string>
#include <vector>
#include <functional>

using namespace std;
using namespace std::literals;

namespace academia {

    class Serializable;

    class Serializer{
    public:

        Serializer(std::ostream *out): out_serializator(out) {}

        virtual void IntegerField(const std::string &field_name, int value) {}
        virtual void DoubleField(const std::string &field_name, double value) {}
        virtual void StringField(const std::string &field_name, const std::string &value) {}
        virtual void BooleanField(const std::string &field_name, bool value) {}
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) {}
        virtual void ArrayField(const std::string &field_name, const vector<reference_wrapper<const academia::Serializable>> &value) {}
        virtual void Header(const std::string &object_name) {}
        virtual void Footer(const std::string &object_name) {}

    protected:
        std::ostream *out_serializator;
    };


    class Serializable{
    public:
        virtual void Serialize(Serializer *serializer) =0;

    };

    class Room : public Serializable{
    public:

        enum Type{
            COMPUTER_LAB,
            OTHER_LAB,
            SOME_LAB,
        };

        std::string EnumToString(Type type) {
            switch(type) {
                case Type::COMPUTER_LAB:
                    return "first lab";
                case Type::OTHER_LAB:
                    return "other lab";
                case Type::SOME_LAB:
                    return "some lab";
            }
        }

        void Serialize(Serializer *serializer) override{
            serializer->Header("Room");
            serializer->IntegerField("Id", id_);
            serializer->StringField("room number", room_number_);
            serializer->StringField("type", EnumToString(typ_));
            serializer->Footer("Room");
        }

        Room(int id, std::string room_number, Type typ): id_(id), room_number_(room_number), typ_(typ) {}

    private:
        int id_;
        std::string room_number_;
        Type typ_;
    };



}

#endif //JIMP_EXERCISES_SERIALIZATION_H
