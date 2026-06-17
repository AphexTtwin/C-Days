#include <iostream>
#include <vector>
int main()
{
	std::vector<int> vivi;

	vivi.reserve(2);


	vivi.push_back(19);
	vivi.push_back(37);
	vivi.push_back(1937);

	std::cout << vivi.size() << "\n";
	std::vector<int>::iterator it;

	it = vivi.begin();

	std::cout << vivi.capacity() << std::endl;
	std::cout << vivi.size() << std::endl;

}