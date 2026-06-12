#include <iostream>

// template<class t> you can type class there
template<typename t> // evaluated at compile time
//we can aslo do


//this function is a templet created when only called
//without using it it will not exist or compile
void print(t value)
{
	// std::cout << val << std::endl;
	std::cout << value << std::endl;
}

// void print(int value)
// {
// 	std::cout << value << std::endl;
// }


// void print(float value)
// {
// 	std::cout << value << std::endl;
// }

// void print(std::string  value)
// {
// 	std::cout << value << std::endl;
// }
int main()
{
	print<int>(13);
	print(12);
	print("sogoy");
	print<std::string>("tanaka senpai");
	print(12.78f);

}