#ifndef _EASYFIND_H
#define _EASYFIND_H

#include <algorithm>

template <typename T> typename T::iterator easyfind(T& cont, int num) {
	return (std::find(cont.begin(), cont.end(), num));
}

#endif
