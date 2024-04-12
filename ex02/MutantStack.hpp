#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>


template<class T>
class MutantStack : public std::stack<T>
{

public:
	//Alias for stack member types
	typedef std::stack<T> stack;
	typedef typename stack::container_type container;
	typedef typename container::iterator iterator;

	MutantStack(): stack(){}

	~MutantStack(){}

	MutantStack(const stack& other): stack(other){
	}

	stack& operator=(const stack & other){
		*this = other;
		return *this;
	}

	iterator begin(){
		return stack::c.begin();
	}

	iterator end(){
		return stack::c.end();
	}

};


#endif