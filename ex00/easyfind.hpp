#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>

// Macros pour les couleurs
# define RESET   "\033[0m"
# define CYAN    "\033[36m"
# define GREEN   "\033[32m"
# define RED_BOLD  "\033[1;31m"


template <typename T>
size_t easyfind(const T& content, int value)
{
	typename T::const_iterator it = std::find(content.begin(), content.end(), value);
	if ( it == content.end())
		throw std::runtime_error("*** Value not found... ***");
	return std::distance(content.begin(), it);
}


#endif