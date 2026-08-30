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
		typedef std::pair<std::size_t, std::size_t> UnitPair;
		typedef std::vector<UnitPair> ContTransit;
	public:	
		void mergeInsertion(Cont& cont, int pair_size);
		void divideToPairs(Cont& cont, Cont& odd, int pair_size);
		void swap_pairs(std::size_t idx, ContIter& begin, std::size_t first_pair_idx, std::size_t second_pair_idx);

	void print(const Cont& cont, const std::string& name);
	void printrange(ContConstIter begin, ContConstIter last, const std::string& name);
	void insertLosers(Cont& cont, int pair_size);
	void insertOdd(Cont& cont, const Cont& odd, int pair_size);
	void addToTransitUnit(ContTransit& transit_unit, std::size_t pos);

	void binaryInsertion(Cont& main, Cont& pend, ContTransit& transit_unit, int pair_size);
	PmergeMe::Cont toNormalVec(const Cont& cont, int pair_size);
	bool isSorted(const Cont& cont);
	static int num;
};

#endif
