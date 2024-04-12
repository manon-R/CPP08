#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// Macros pour les couleurs
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define YELLOW_BOLD  "\033[1;33m"


class Span {

public:

	class FullVectorException : public std::exception{

	public:

		virtual const char *what() const throw();
	};

	class NoDistanceException : public std::exception{

	public:

		virtual const char *what() const throw();
	};

	Span(unsigned int n);
	Span(const Span& other);
	Span &operator=(const Span& other);
	~Span();

	void addNumber(int nb);
	size_t shortestSpan() const;
	size_t longestSpan() const;

	void addRangeNumber(const std::vector<int>& numbers);

private:
	Span();
	std::vector<int> vec;
	unsigned int	nMax;
};

#endif