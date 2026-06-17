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

	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;

	it = vivi.end();
	std::cout << *it << std::endl;

	*it = 20;
	std::cout << *it << std::endl;
	it = it + 100000000;
	std::cout << *it << std::endl;


}