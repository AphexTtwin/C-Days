#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <typeinfo>

Base *generate(void)
{
	int rand = std::rand() % 101;
	if (rand >= 0 && rand < 33)
		return new A;
	else if (rand >= 33 && rand < 68)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	Base *a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return;
	}
	Base *b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return;
	}
	Base *c = dynamic_cast<C *>(p);
	if (c)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::bad_cast & e)
	{
		(void)e;
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...)
	{
	}
}

int main()
{
	std::srand(std::time(0));
	Base *obj = generate();
		identify(obj);
	delete obj;
	Base *obj2 = generate();
	Base &ref = *obj2;
		identify(&ref);
	delete obj2;
}