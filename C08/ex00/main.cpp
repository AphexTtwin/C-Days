#include "easyfind.hpp"



int main()
{
	try
	{

		std::vector<int> con;

		con.push_back(10);
		con.push_back(20);
		con.push_back(30);
		con.push_back(40);

		std::vector<int>::iterator it;

		it = easyfind(con, 30);

		std::cout << "we found it -->  " << it.operator*() << std::endl;

		it = easyfind(con, 300);

		std::cout << "we found it -->  " << *it << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}

	try
	{
		std::list<char> li;

		li.push_back('a');
		li.push_back('b');
		li.push_back('c');
		li.push_back('d');
		li.push_back('e');
		li.push_back('f');
		li.push_front('x');

		std::list<char>::iterator it;

		it = easyfind(li, 'f');

		std::cout << "we found it  ! -->  " << *it << std::endl;

	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}

}