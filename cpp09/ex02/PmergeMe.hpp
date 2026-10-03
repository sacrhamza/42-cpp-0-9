#ifndef _PMERGEME_H
#define _PMERGEME_H

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

class PmergeMeVec {
	private:
		typedef std::vector<int> Cont;
		typedef std::vector<int>::iterator ContIter;
		typedef std::vector<int>::const_iterator ContConstIter;
		typedef std::pair<std::size_t, std::size_t> UnitPair;
		typedef std::vector<UnitPair> ContTransit;
		void divideToPairs(Cont& cont, Cont& odd, int pair_size);
		void swap_pairs(std::size_t idx, ContIter& begin, std::size_t first_pair_idx, std::size_t second_pair_idx);
		void print(const Cont& cont, const std::string& name);
		void printrange(ContConstIter begin, ContConstIter last, const std::string& name);
		void insertLosers(Cont& cont, int pair_size);
		void insertOdd(Cont& cont, const Cont& odd, int pair_size);
		void addToTransitUnit(ContTransit& transit_unit, std::size_t pos);
		void binaryInsertion(Cont& main, Cont& pend, ContTransit& transit_unit, int pair_size);
		Cont toNormalVec(const Cont& cont, int pair_size);
		static bool less_than(int a, int b);
	public:	
		PmergeMeVec();
		PmergeMeVec(const PmergeMeVec& other);
		PmergeMeVec& operator=(const PmergeMeVec& other);
		~PmergeMeVec();
		void mergeInsertion(Cont& cont, int pair_size);
		static int num;
};

class PmergeMeDeque {
	private:
		typedef std::deque<int> Cont;
		typedef std::deque<int>::iterator ContIter;
		typedef std::deque<int>::const_iterator ContConstIter;
		typedef std::pair<std::size_t, std::size_t> UnitPair;
		typedef std::deque<UnitPair> ContTransit;
		void divideToPairs(Cont& cont, Cont& odd, int pair_size);
		void swap_pairs(std::size_t idx, ContIter& begin, std::size_t first_pair_idx, std::size_t second_pair_idx);
		void print(const Cont& cont, const std::string& name);
		void printrange(ContConstIter begin, ContConstIter last, const std::string& name);
		void insertLosers(Cont& cont, int pair_size);
		void insertOdd(Cont& cont, const Cont& odd, int pair_size);
		void addToTransitUnit(ContTransit& transit_unit, std::size_t pos);
		void binaryInsertion(Cont& main, Cont& pend, ContTransit& transit_unit, int pair_size);
		Cont toNormalVec(const Cont& cont, int pair_size);
		static bool less_than(int a, int b);
	public:	



		PmergeMeDeque();
		PmergeMeDeque(const PmergeMeDeque& other);
		PmergeMeDeque& operator=(const PmergeMeDeque& other);

		~PmergeMeDeque();
		void mergeInsertion(Cont& cont, int pair_size);

		static int num;
};


#endif
