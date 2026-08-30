#ifndef _PMERGEME_H
#define _PMERGEME_H

#include <iostream>
#include <vector>
#include <algorithm>

class PmergeMe {
	private:
		typedef std::vector<int> Cont;
		typedef std::vector<int>::iterator ContIter;
		typedef std::vector<int>::const_iterator ContConstIter;
	public:	
		void mergeInsertion(Cont& cont);
		void FordJohnson(Cont& cont);
		void divideToPairs(const Cont& cont, Cont& main, Cont& pend, Cont& odd);
		void print(const Cont& cont, const std::string& name);
		void insertPend(Cont& pend, Cont& main, Cont& chain);
		std::size_t getPos(Cont& main, const Cont& chain, int n);

};

#endif
