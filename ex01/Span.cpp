#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int n){
	std::vector<int> vec(n);
	nMax = n;
}

Span::Span(const Span& other){
	*this = other;
}

Span & Span::operator=(const Span& other){
	if (!vec.empty())
		vec.clear();
	nMax = other.nMax;
	this->addRangeNumber(other.vec);
	return *this;
}

Span::~Span(){}

void Span::addNumber(int nb){
	if (vec.size() >= nMax)
		throw FullVectorException();
	vec.push_back(nb);
}

size_t Span::shortestSpan() const{
	Span tmp = *this;
	int sub;
	if (tmp.vec.empty() || tmp.vec.size() == 1)
	{
		throw NoDistanceException();
	}
	std::vector<int>::const_iterator it;
	std::sort(tmp.vec.begin(), tmp.vec.end());
	int shortest = abs(tmp.vec[1] - tmp.vec[0]);
	for (size_t i = 1; i < (tmp.vec.size() - 1); i++)
	{
		sub = abs(tmp.vec[i+1] - tmp.vec[i]);
		shortest = (sub < shortest)? sub : shortest;
	}
	return shortest;
}

size_t Span::longestSpan() const{
	Span tmp = *this;
	if (tmp.vec.empty() || tmp.vec.size() == 1)
	{
		throw NoDistanceException();
	}
	std::sort(tmp.vec.begin(), tmp.vec.end());
	return (tmp.vec[tmp.vec.size()-1] - tmp.vec[0]);
}

void Span::addRangeNumber(const std::vector<int>& numbers){
	if (numbers.size() > nMax || (vec.size() + numbers.size()) > nMax)
		throw FullVectorException();
	std::vector<int>::iterator position = (vec.empty())? vec.begin() : vec.end();
	vec.insert(position, numbers.begin(), numbers.end());
}


const char *Span::FullVectorException::what() const throw(){
	return ("***** Span is already full *****");
}

const char *Span::NoDistanceException::what() const throw(){
	return ("***** No distance can be calculated... *****");
}