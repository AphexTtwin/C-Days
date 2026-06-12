#include <iostream>

template<typename T,int N>

class Temp
{
private:
	T str[N];
public:
	int get_str_size()
	{return N;}
};


int main()
{
	Temp<int, 5> array;

std::cout << array.get_str_size() << std::endl;

}