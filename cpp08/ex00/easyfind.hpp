#ifndef _EASYFIND_H
#define _EASYFIND_H

template <typename T> typename T::iterator easyfind(T& cont, int num) {

	typename T::iterator it = cont.begin();

	for (; it != cont.end(); it++) {
		if (*it == num)
			return (it);
	}

	return (cont.end());
}

#endif
