#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	// Print Original Vector
	std::cout << "Original vector :";

	for (unsigned long i = 0; i < vec.size(); i++)
	std::cout << " " << vec[i];

	std::cout << std::endl;

	int ser = 30;
 
	std::cout << CYAN << "********* Test with existing value *********" << RESET << std::endl;
	int position;
	try {
		position = easyfind(vec, ser);
		std::cout << GREEN << "Value " << ser << " is at position " << position << RESET << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cout << RED_BOLD << e.what() << RESET << std::endl;
	}


	std::cout << std::endl;
	ser = 0;
	std::cout << CYAN << "********* Test with unexisting value *********" << RESET << std::endl;
	try {
		position = easyfind(vec, ser);
		std::cout << GREEN << "Value " << ser << " is at position " << position << RESET << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cout << RED_BOLD << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::list<int> myList;

	myList.push_back(0);
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);

    std::list<int>::iterator it;
	std::cout << "Original list : ";
    for (it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

	std::cout << CYAN << "********* Test with existing value *********" << RESET << std::endl;
	try {
		position = easyfind(myList, ser);
		std::cout << GREEN << "Value " << ser << " is at position " << position << RESET << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cout << RED_BOLD << e.what() << RESET << std::endl;
	}


	std::cout << std::endl;
	ser = -42;
	std::cout << CYAN << "********* Test with unexisting value *********" << RESET << std::endl;
	try {
		position = easyfind(myList, ser);
		std::cout << GREEN << "Value " << ser << " is at position " << position << RESET << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cout << RED_BOLD << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;


	return 0;
}