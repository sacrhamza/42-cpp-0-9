#ifndef _ITER_H
#define _ITER_H

template <typename T, typename FuncType> void iter(T* array, const unsigned int size, FuncType func) {
	for (unsigned int idx = 0; idx < size; idx++)
	{
		func(array[idx]);
	}
}

#endif
