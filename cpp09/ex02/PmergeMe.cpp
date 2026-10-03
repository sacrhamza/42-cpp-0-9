#include "PmergeMe.hpp"


int PmergeMeVec::num;


PmergeMeVec::PmergeMeVec() {}
PmergeMeVec::PmergeMeVec(const PmergeMeVec& other) {
	(void)other;
}
PmergeMeVec& PmergeMeVec::operator=(const PmergeMeVec& other) {
	(void)other;
	return (*this);
}

PmergeMeVec::~PmergeMeVec() {}



	std::pair<std::size_t, std::size_t> jacobstal(std::pair<std::size_t, std::size_t> num) {
		return (std::make_pair(num.first + 2 * num.second,
					num.first));
	}

void PmergeMeVec::printrange(ContConstIter begin, ContConstIter last, const std::string& name) {
	std::cout << name << "\n";
	for (; begin != last; ++begin)	 {
		std::cout << *begin << " ";
	}
	std::cout << "\n";
}

bool PmergeMeVec::less_than(int a, int b){
	PmergeMeVec::num++;
	return (a < b);
}

void PmergeMeVec::swap_pairs(std::size_t idx, ContIter& begin, std::size_t first_pair_idx, std::size_t second_pair_idx) {
	ContIter begin1 = begin + idx;
	ContIter end1 = begin + first_pair_idx + 1;
	ContIter begin2 = end1;

	if (less_than(*(begin + second_pair_idx), *(begin + first_pair_idx))) {
		std::swap_ranges(begin1, end1, begin2);
	}
}

void PmergeMeVec::divideToPairs(Cont& cont, Cont& odd, int pair_size) {
	if ((cont.size() / pair_size) % 2 != 0)
	{
		ContIter odd_iter_start = cont.end() - pair_size;
		odd.insert(odd.end(), odd_iter_start, cont.end());
		cont.erase(odd_iter_start, cont.end());
	}
	std::size_t second_idx;
	std::size_t first_idx;
	int first;
	int second;
	ContIter begin = cont.begin();
	for (std::size_t idx = 0; idx + pair_size * 2 - 1 < cont.size(); idx += pair_size * 2) {

		first_idx = idx + pair_size - 1;
		second_idx = idx + pair_size * 2 - 1;

		first = cont[first_idx];
		second = cont[second_idx];

		swap_pairs(idx, begin, first_idx, second_idx);
	}
	}

	void PmergeMeVec::addToTransitUnit(ContTransit& transit_unit, std::size_t pos) {
		for (std::size_t i = 0; i < transit_unit.size(); ++i) {
			if (transit_unit[i].second >= pos)
				transit_unit[i].second++;
		}
	}


	PmergeMeVec::Cont PmergeMeVec::toNormalVec(const Cont& cont, int pair_size) {
		Cont res;
		for (std::size_t idx = 0; idx + pair_size - 1 < cont.size(); idx += pair_size) {
			res.push_back(cont[idx + pair_size - 1]);
		}
		return (res);
	}


	void PmergeMeVec::binaryInsertion(Cont& main, Cont& pend, ContTransit& transit_unit, int pair_size) {
		if (pend.empty())
			return ;
		Cont res = main;
		std::pair<std::size_t, std::size_t> jacob(1, 1);
		std::size_t inserted_nums = 1;

		// insert the first element
		res.insert(res.begin(), pend.begin(), pend.begin() + pair_size);
		std::size_t idx;
		ContIter pos;

		for (std::size_t idx = 1; idx < transit_unit.size(); idx++) {
			transit_unit[idx].second++;
		}
		while (inserted_nums < (pend.size() / pair_size)) {
			jacob = jacobstal(jacob);
			std::size_t begin_jacob = jacob.first;
			if (begin_jacob > pend.size() / pair_size - 1) {
				begin_jacob = pend.size() / pair_size;
			}
			for (; begin_jacob > jacob.second; --begin_jacob) {
				++inserted_nums;
				idx = (begin_jacob  - 1) * pair_size;
				Cont tmp = toNormalVec(res, pair_size);
				ContIter pos = std::lower_bound(tmp.begin(), tmp.begin() + transit_unit[idx / pair_size].second + 1, pend[idx + pair_size -1], less_than);
				ContIter real_pos = (pos - tmp.begin()) * pair_size + res.begin();
				res.insert(real_pos, pend.begin() + idx, pend.begin() + idx + pair_size);
				addToTransitUnit(transit_unit, pos - tmp.begin());
			}
		}
		main = res;
	}

	void PmergeMeVec::insertLosers(Cont& cont, int pair_size) {
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
		binaryInsertion(main, pend, transit_unit, pair_size);
		cont = main;
	}

	void PmergeMeVec::insertOdd(Cont& cont, const Cont& odd, int pair_size) {
		for (std::size_t idx = 0; idx + pair_size - 1 < odd.size(); idx += pair_size) {
			Cont tmp = toNormalVec(cont, pair_size);
			// std::cout << "insert" << odd[idx + pair_size - 1] << "\n";
			ContIter pos = std::lower_bound(tmp.begin(), tmp.end(), odd[idx + pair_size - 1], less_than);
			ContIter real_pos = (pos - tmp.begin()) * pair_size + cont.begin();
			cont.insert(real_pos, odd.begin() + idx, odd.begin() + idx + pair_size);
		}
	}

	void PmergeMeVec::mergeInsertion(Cont& cont, int pair_size) {
		if (cont.size() / pair_size < 2)
		{
			return ;
		}
		Cont odd;
		divideToPairs(cont, odd, pair_size);
		mergeInsertion(cont, pair_size * 2);
		insertLosers(cont, pair_size); 
		insertOdd(cont, odd, pair_size );
	}

int PmergeMeDeque::num;


PmergeMeDeque::PmergeMeDeque() {}
PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque& other) {
	(void)other;
}
PmergeMeDeque& PmergeMeDeque::operator=(const PmergeMeDeque& other) {
	(void)other;
	return (*this);
}

PmergeMeDeque::~PmergeMeDeque() {}


void PmergeMeDeque::print(const Cont& cont, const std::string& name) {
	std::cout << name << "{";
	for (std::size_t idx = 0; idx < cont.size(); ++idx)	 {
		std::cout << cont[idx] << " ";
	}
	std::cout << "}\n";
}
void PmergeMeDeque::printrange(ContConstIter begin, ContConstIter last, const std::string& name) {
	std::cout << name << "\n";
	for (; begin != last; ++begin)	 {
		std::cout << *begin << " ";
	}
	std::cout << "\n";
}

bool PmergeMeDeque::less_than(int a, int b){
	PmergeMeDeque::num++;
	return (a < b);
}

void PmergeMeDeque::swap_pairs(std::size_t idx, ContIter& begin, std::size_t first_pair_idx, std::size_t second_pair_idx) {
	ContIter begin1 = begin + idx;
	ContIter end1 = begin + first_pair_idx + 1;
	ContIter begin2 = end1;

	if (less_than(*(begin + second_pair_idx), *(begin + first_pair_idx))) {
		std::swap_ranges(begin1, end1, begin2);
	}
}

void PmergeMeDeque::divideToPairs(Cont& cont, Cont& odd, int pair_size) {
	if ((cont.size() / pair_size) % 2 != 0)
	{
		ContIter odd_iter_start = cont.end() - pair_size;
		odd.insert(odd.end(), odd_iter_start, cont.end());
		cont.erase(odd_iter_start, cont.end());
	}
	std::size_t second_idx;
	std::size_t first_idx;
	int first;
	int second;
	ContIter begin = cont.begin();
	for (std::size_t idx = 0; idx + pair_size * 2 - 1 < cont.size(); idx += pair_size * 2) {

		first_idx = idx + pair_size - 1;
		second_idx = idx + pair_size * 2 - 1;

		first = cont[first_idx];
		second = cont[second_idx];

		swap_pairs(idx, begin, first_idx, second_idx);
	}
	}

	void PmergeMeDeque::addToTransitUnit(ContTransit& transit_unit, std::size_t pos) {
		for (std::size_t i = 0; i < transit_unit.size(); ++i) {
			if (transit_unit[i].second >= pos)
				transit_unit[i].second++;
		}
	}


	PmergeMeDeque::Cont PmergeMeDeque::toNormalVec(const Cont& cont, int pair_size) {
		Cont res;
		for (std::size_t idx = 0; idx + pair_size - 1 < cont.size(); idx += pair_size) {
			res.push_back(cont[idx + pair_size - 1]);
		}
		return (res);
	}


	void PmergeMeDeque::binaryInsertion(Cont& main, Cont& pend, ContTransit& transit_unit, int pair_size) {
		if (pend.empty())
			return ;
		Cont res = main;
		std::pair<std::size_t, std::size_t> jacob(1, 1);
		std::size_t inserted_nums = 1;

		// insert the first element
		res.insert(res.begin(), pend.begin(), pend.begin() + pair_size);
		std::size_t idx;
		ContIter pos;

		for (std::size_t idx = 1; idx < transit_unit.size(); idx++) {
			transit_unit[idx].second++;
		}
		while (inserted_nums < (pend.size() / pair_size)) {
			jacob = jacobstal(jacob);
			std::size_t begin_jacob = jacob.first;
			if (begin_jacob > pend.size() / pair_size - 1) {
				begin_jacob = pend.size() / pair_size;
			}
			for (; begin_jacob > jacob.second; --begin_jacob) {
				++inserted_nums;
				idx = (begin_jacob  - 1) * pair_size;
				Cont tmp = toNormalVec(res, pair_size);
				ContIter pos = std::lower_bound(tmp.begin(), tmp.begin() + transit_unit[idx / pair_size].second + 1, pend[idx + pair_size -1], less_than);
				ContIter real_pos = (pos - tmp.begin()) * pair_size + res.begin();
				res.insert(real_pos, pend.begin() + idx, pend.begin() + idx + pair_size);
				addToTransitUnit(transit_unit, pos - tmp.begin());
			}
		}
		main = res;
	}

	void PmergeMeDeque::insertLosers(Cont& cont, int pair_size) {
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
		binaryInsertion(main, pend, transit_unit, pair_size);
		cont = main;
	}

	void PmergeMeDeque::insertOdd(Cont& cont, const Cont& odd, int pair_size) {
		for (std::size_t idx = 0; idx + pair_size - 1 < odd.size(); idx += pair_size) {
			Cont tmp = toNormalVec(cont, pair_size);
			// std::cout << "insert" << odd[idx + pair_size - 1] << "\n";
			ContIter pos = std::lower_bound(tmp.begin(), tmp.end(), odd[idx + pair_size - 1], less_than);
			ContIter real_pos = (pos - tmp.begin()) * pair_size + cont.begin();
			cont.insert(real_pos, odd.begin() + idx, odd.begin() + idx + pair_size);
		}
	}

	void PmergeMeDeque::mergeInsertion(Cont& cont, int pair_size) {
		if (cont.size() / pair_size < 2)
		{
			return ;
		}
		Cont odd;
		divideToPairs(cont, odd, pair_size);
		mergeInsertion(cont, pair_size * 2);
		insertLosers(cont, pair_size); 
		insertOdd(cont, odd, pair_size );
	}
