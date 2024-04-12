#include "Span.hpp"

int main()
{
	std::cout << CYAN <<  "- Subject's tests -" << RESET << std::endl;
	
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << CYAN << "-------------------"<< RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "    - Try to add 6th value -" << RESET << std::endl;
	try{
		sp.addNumber(42);
	}
	catch(std::exception& e){
		std::cout << RED <<  e.what() << RESET << std::endl;
	}
	std::cout << CYAN << "---------------------------------"<< RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "- Create empty Span and try to call shortestSpan() -" << RESET << std::endl;
	Span test = Span(0);
	try{
		test.shortestSpan();
	}
	catch(std::exception& e){
		std::cout << RED <<  e.what() << RESET << std::endl;
	}
	std::cout << CYAN << "-------------------------------------------------------"<< RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "- Test add numbers by range of iterators -" << RESET << std::endl;
	Span test1 = Span(10);
	test1.addNumber(1);
	test1.addNumber(2);
	test1.addNumber(3);
	test1.addNumber(4);
	test1.addNumber(5);
	std::vector<int> v;
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);

	test1.addRangeNumber(v);
	std::cout << "Shortest span = " <<  test1.shortestSpan() << std::endl;
	std::cout << "Longest span = " << test1.longestSpan() << std::endl;
	std::cout << CYAN << "------------------------------------------"<< RESET << std::endl;
	std::cout << std::endl;

	return 0;
}