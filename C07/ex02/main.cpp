#include <iostream>
#include "Array.hpp"
#include <cstdlib>

int main()
{
    Array<int> obj(5);

    for (int i = 0; i < 5; i++)
    {
        obj[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << obj[i] << std::endl;
    }
	std::cout << "---------------\n";
	Array<int> bj(6);
    for (int i = 0; i < 6; i++)
    {
        bj[i] = i + 10;
	}
    for (int i = 0; i < 6; i++)
    {
        std::cout << bj[i] << std::endl;
    }
	std::cout << "---------------\n";

	bj = obj;
	for (int i = 0; i < 5; i++)
    {
        std::cout << bj[i] << std::endl;
    }
	std::cout << "---------------\n";

    try
    {
        Array<int> obj(5);

        for (int i = 0; i < 5; i++)
        {
            obj[i] = i;
        }
        for (int i = 0; i < 5; i++)
        {
            std::cout << obj[i] << std::endl;
        }
        std::cout << obj[-2];
    }
    catch (std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }
}
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }