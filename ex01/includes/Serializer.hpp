
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"

class Data;

class Serializer {

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif