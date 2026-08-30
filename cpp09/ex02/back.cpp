#include "PmergeMe.hpp"
#include <algorithm>

int var;
void PmergeMe::print(const Cont& cont, const std::string& name) {
	std::cout << name << "\n";
	for (std::size_t idx = 0; idx < cont.size(); ++idx)	 {
		std::cout << cont[idx] << " ";
	}
	std::cout << "\n";
}

bool less_than(int a, int b){
	var++;
	return (a < b);
}

bool equal_to(int a, int b) {
	var++;
	return (a == b);
}

void PmergeMe::divideToPairs(const Cont& cont, Cont& main, Cont& pend, Cont& odd) {
	if (cont.size() % 2 != 0) {
		// add the last element to odd
		odd.push_back(cont[cont.size() - 1]);
	}
	int loser;
	int winner;
	for (std::size_t idx = 0; idx + 1 < cont.size(); idx += 2)	 {
		loser = cont[idx];
		winner = cont[idx + 1];
		if (less_than(winner, loser)) {
			std::swap(loser, winner);
		}
		main.push_back(winner);
		pend.push_back(loser);
	}
}

std::size_t PmergeMe::getPos(Cont& main, const Cont& chain, int n) {
	ContConstIter pos_iter = std::find(chain.begin(), chain.end(), n);
	return (pos_iter - chain.begin());
}


void PmergeMe::insertPend(Cont& pend, Cont& main, Cont& chain) {
	std::size_t pos;
	int num;
	ContIter main_iter;
	if (!pend.empty())
	{
		pos = getPos(main, chain, main.at(0));
		main.insert(main.begin(), pend[pos]);
		pend.erase(pos + pend.begin());
		chain.erase(pos + chain.begin());
	}
	for (ContConstIter iter = chain.begin(); iter != chain.end(); ++iter) {
		pos = getPos(main, chain, *iter);
		num = pend[pos];
		main_iter = std::lower_bound(main.begin(), main.end(), num, less_than);
		main.insert(main_iter, num);
	}
}



void PmergeMe::mergeInsertion(Cont& cont) {
	// if (notSorted()) {
	//
	// }
	Cont main;
	Cont pend;
	Cont chain;
	Cont odd;

	if (cont.size() == 1)
		return ;
	divideToPairs(cont, main, pend, odd);
	chain = main;
	mergeInsertion(main);
	insertPend(pend, main, chain);
	// insertOdd(odd, main);
	cont = main;

	print(main, "main");
	// print(pend, "pend");
	// print(odd, "odd");
	std::cout << "hey " << var << "\n";
}
