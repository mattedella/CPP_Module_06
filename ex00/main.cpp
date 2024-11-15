
#include "includes/ScalarConverter.hpp"

int main (int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: invalid number of argument\n";
        return 1;
    }

    std::string toConvert = av[1];
    ScalarConverter::convert(toConvert);

    return 0;
}