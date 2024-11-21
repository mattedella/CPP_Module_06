
#include "../includes/Data.hpp"

Data::Data(void) : _data(42) {
}

Data::Data(const Data& copy) : _data(copy._data) {
}

int Data::getData(void) const {
    return _data;
}

void Data::setData(int num) {
    _data = num;
}

Data::~Data(void) {
}