#ifndef _ITER_H
#define _ITER_H

template <typename T> void iter(T* array, const unsigned int size,void (*func)(const T&)) {
	for (unsigned int idx = 0; idx < size; idx++)
	{
		func(array[idx]);
	}
}

#endif
