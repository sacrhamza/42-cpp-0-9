#include "PmergeMe.hpp"
#include <algorithm>
#include <utility>

int PmergeMe::num;

bool PmergeMe::isSorted(const Cont& cont) {
	std::vector<int> hey = cont;	
	std::sort(hey.begin(), hey.end());
	return (hey == cont);
}

void PmergeMe::print(const Cont& cont, const std::string& name) {
	std::cout << name << "{";
	for (std::size_t idx = 0; idx < cont.size(); ++idx)	 {
		std::cout << cont[idx] << " ";
	}
	std::cout << "}\n";
}
void PmergeMe::printrange(ContConstIter begin, ContConstIter last, const std::string& name) {
	std::cout << name << "\n";
	for (; begin != last; ++begin)	 {
		std::cout << *begin << " ";
	}
	std::cout << "\n";
}

bool less_than(int a, int b){
	PmergeMe::num++;
	return (a < b);
}

// bool equal_to(int a, int b) {
// 	var++;
// 	return (a == b);
// }
void PmergeMe::swap_pairs(std::size_t idx, ContIter& begin, std::size_t first_pair_idx, std::size_t second_pair_idx) {
	ContIter begin1 = begin + idx;
	ContIter end1 = begin + first_pair_idx + 1;
	ContIter begin2 = end1;
	ContIter end2 = begin + second_pair_idx + 1;

	// std::cout << "before: (" << *(begin +first_pair_idx) << "," << (*(begin + second_pair_idx)) << ")" << "\n";
	if (less_than(*(begin + second_pair_idx), *(begin + first_pair_idx))) {
		// printrange(begin1, end1, "first one");
		// printrange(begin2, end2, "second one");
		std::swap_ranges(begin1, end1, begin2);
		// std::cout << "after: (" << *(begin +first_pair_idx) << "," << (*(begin + second_pair_idx)) << ")" << "\n";
	}
}

void PmergeMe::divideToPairs(Cont& cont, Cont& odd, int pair_size) {
if ((cont.size() / pair_size) % 2 != 0)
{
    ContIter odd_iter_start = cont.end() - pair_size;

	// if ((cont.size() / (pair_size * 2))  != 0)
	// {
		// ContIter odd_iter_start = cont.size() / (pair_size * 2) * 2 + cont.begin();
		odd.insert(odd.end(), odd_iter_start, cont.end());
		cont.erase(odd_iter_start, cont.end());
	}
	std::size_t second_idx;
	std::size_t first_idx;
	int first;
	int second;
	ContIter begin = cont.begin();
	for (std::size_t idx = 0; idx + pair_size * 2 - 1 < cont.size(); idx += pair_size * 2) {
		// std::cout  << (idx + pair_size - 1) << "\n";
		// std::cout  << (idx + pair_size * 2 - 1) << "\n";
		first_idx = idx + pair_size - 1;
		second_idx = idx + pair_size * 2 - 1;

		first = cont[first_idx];
		second = cont[second_idx];

		// std::cout << "1 begin: " << (idx) << "\n";
		// std::cout << "1 end: " << (first_idx + 1) << "\n";
		// //
		// //
		// std::cout << "2 begin: " << (first_idx + 1) << "\n";
		// std::cout << "2 end: " << (second_idx + 1) << "\n";
		swap_pairs(idx, begin, first_idx, second_idx);
	}
}

// void PmergeMe::addToTransitUnit(ContTransit& transit_unit, std::size_t pos) {
// 	for (; pos  < transit_unit.size(); ++pos) {
// 		transit_unit[pos].second++;
// 	}
// }
void PmergeMe::addToTransitUnit(ContTransit& transit_unit, std::size_t pos) {
    for (std::size_t i = 0; i < transit_unit.size(); ++i) {
        if (transit_unit[i].second >= pos)
            transit_unit[i].second++;
    }
}


PmergeMe::Cont PmergeMe::toNormalVec(const Cont& cont, int pair_size) {
	Cont res;
	for (std::size_t idx = 0; idx + pair_size - 1 < cont.size(); idx += pair_size) {
		res.push_back(cont[idx + pair_size - 1]);
	}
	return (res);
}

void PmergeMe::binaryInsertion(Cont& main, Cont& pend, ContTransit& transit_unit, int pair_size) {
	if (pend.empty())
		return ;
	Cont res = main;

	// insert the first element
	res.insert(res.begin(), pend.begin(), pend.begin() + pair_size);
	std::size_t idx;
	ContIter pos;

	for (std::size_t idx = 1; idx < transit_unit.size(); idx++) {
		transit_unit[idx].second++;
	}
	for (std::size_t idx = pair_size; idx + pair_size - 1 < pend.size(); idx += pair_size) {
		std::cout << "insert " << pend[idx + pair_size -1] << "\n";
		std::cout << "idx = " << idx << "\n";
		std::cout << "pair_size = " << pair_size << "\n";
		Cont tmp = toNormalVec(res, pair_size);
		// print(tmp, "tmp");
		// std::cout << "index in result" << transit_unit[idx].second << "\n";
		ContIter pos = std::lower_bound(tmp.begin(), tmp.begin() + transit_unit[idx / pair_size].second + 1, pend[idx + pair_size -1], less_than);
		std::cout << "important: "<< (pos - tmp.begin()) << "\n";
		print(res, "before inserting");;
		ContIter real_pos = (pos - tmp.begin()) * pair_size + res.begin();
		res.insert(real_pos, pend.begin() + idx, pend.begin() + idx + pair_size);
		print(res, "after inserting");;
		addToTransitUnit(transit_unit, pos - tmp.begin());
	}
	// print(res, "result");
	main = res;
}

void PmergeMe::insertLosers(Cont& cont, int pair_size) {
	Cont main;
	Cont pend;
	ContIter begin = cont.begin();
	std::size_t second_idx;
	std::size_t first_idx;
	std::size_t num = 0;
	ContTransit transit_unit;

	for (std::size_t idx = 0; idx + pair_size * 2 - 1 < cont.size(); idx += pair_size * 2) {
		first_idx = idx + pair_size - 1;
		second_idx = idx + pair_size * 2 - 1;
		transit_unit.push_back(std::make_pair(num, num));
		pend.insert(pend.end(), begin + idx, begin + first_idx + 1);
		main.insert(main.end(), begin + first_idx + 1, begin + second_idx + 1);
		num++;
	}
	std::cout << pair_size << "\n";
	print(pend, "pend");
	print(main, "main");
	// print(cont, "result");
	binaryInsertion(main, pend, transit_unit, pair_size);
	cont = main;
}

void PmergeMe::insertOdd(Cont& cont, const Cont& odd, int pair_size) {
	for (std::size_t idx = 0; idx + pair_size - 1 < odd.size(); idx += pair_size) {
		Cont tmp = toNormalVec(cont, pair_size);
		ContIter pos = std::lower_bound(tmp.begin(), tmp.end(), odd[idx + pair_size - 1], less_than);
		ContIter real_pos = (pos - tmp.begin()) * pair_size + cont.begin();
		cont.insert(real_pos, odd.begin() + idx, odd.begin() + idx + pair_size);
	}
}

void PmergeMe::mergeInsertion(Cont& cont, int pair_size) {
	if (cont.size() / pair_size < 2)
		return ;
	Cont odd;
	divideToPairs(cont, odd, pair_size);
	mergeInsertion(cont, pair_size * 2);
	if (pair_size > 1)
		insertLosers(cont, pair_size / 2); 
	print(odd, "insert odd");
	print(cont, "before");
		// insertOdd(cont, odd, pair_size);
	print(cont, "after");
}
