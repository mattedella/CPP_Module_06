
#include "includes/Serializer.hpp"

int	main()
{
	Data		*d = new Data;
	Data		*result;
	uintptr_t	num;

	num = Serializer::serialize(d);
	result = Serializer::deserialize(num);
	result->setData(32);
	if (d == result) {
		std::cout << "THEY ARE THE SAME!!!\n";
		std::cout << d << " " << d->getData() << std::endl;
		std::cout << result << " " << result->getData() << std::endl;
	}
    else {
		std::cout << "THEY ARE NOT THE SAME!!!\n";
		std::cout << d << std::endl;
		std::cout << result << std::endl;
	}
	delete result;
}