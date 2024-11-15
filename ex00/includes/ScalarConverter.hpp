
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter {
    private:
        ScalarConverter();

    public:
        static void convert(std::string toConvert);

        ~ScalarConverter();
};

#endif
