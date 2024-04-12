#include "MutantStack.hpp"
#include <list>

int main()
{

	std::cout << "# Test from the subject using MutantStack #" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
	std::cout << "# Same code using std::list instead of MutantStack #" << std::endl;
	std::list<int> test2;
	test2.push_back(5);
	test2.push_back(17);
	std::cout << test2.back() << std::endl;
	test2.pop_back();
	std::cout << test2.size() << std::endl;
	test2.push_back(3);
	test2.push_back(5);
	test2.push_back(737);
	test2.push_back(0);
	std::list<int>::iterator it2 = test2.begin();
	std::list<int>::iterator ite2 = test2.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << std::endl;
	
	std::cout << "# Test copy constructor of MutantStack #" << std::endl;
	std::stack<int> test3(mstack);
	std::cout << "mtack.top() = " << mstack.top() << " and test3.top() = " << test3.top() << std::endl;
	std::cout << "mtack.size() = " << mstack.size() << " and test3.size() = " << test3.size()<< std::endl;

	return 0;
}