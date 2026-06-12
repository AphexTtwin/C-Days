#include "Serializer.hpp"

int main()
{
	Data data = {11, "gnabri", 'g'};
	Data *data_ptr = &data;
	uintptr_t raw = Serializer::serialize(data_ptr);
	Data *deserialized_ptr = Serializer::deserialize(raw);

	std::cout << "Original pointer:      " << data_ptr << std::endl;
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;
	std::cout << "Deserialized pointer:  " << deserialized_ptr << std::endl;

	if (deserialized_ptr == data_ptr)
		std::cout << "OK: deserialized pointer equals original pointer" << std::endl;
	else
		std::cout << "KO: pointers are different" << std::endl;

	return 0;
}


	// Data data;
	// data.c = 'c';
	// data.i = 17;
	// data.strin = "gnabri";

	// std::cout << &data << std::endl;

	// Serializer obj;
	// Data *data_ptr = &data;
	// std::cout << data_ptr << std::endl;
	// std::cout << data_ptr->c << std::endl;
	// std::cout << data_ptr->strin << std::endl;

	// uintptr_t addr = obj.serialize(data_ptr);
	// std::cout << std::hex << addr << std::endl;
	// std::cout << std::showbase << addr << std::endl;

	// Data *other_ptr = obj.deserialize(addr);
	// std::cout << other_ptr << std::endl;