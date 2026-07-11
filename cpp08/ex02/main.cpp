#include "MutantStack.hpp"
#include <list>
#include <vector>
int main()
{
	typedef std::list<int> cont;
	typedef MutantStack<int, cont > type;
	type mstack;

		mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	type::iterator it = mstack.begin();
	type::iterator ite = mstack.end();
	++it;
	it--;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int, cont > s(mstack);
	return 0;
}
