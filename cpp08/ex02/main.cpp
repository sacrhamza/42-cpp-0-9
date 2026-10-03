#include "MutantStack.hpp"
#include <list>


void test()
{
	typedef std::list<int> cont;
	typedef cont type;
	type mstack;

		mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << "size = " <<  mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
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

	std::cout << "\n";
}

int main()
{
	typedef std::list<int> cont;
	typedef MutantStack<int, cont > type;
	type mstack;

		mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size = " <<  mstack.size() << std::endl;
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

	std::cout << "\n";
	test();
	std::cout << "\n";

	type mystack;
	mystack.push(20);
	mystack.push(30);

	std::cout << (mystack.begin() == mystack.begin()++) << "\n";
	std::cout << (mystack.begin() == ++mystack.begin()) << "\n";

	std::cout << (mystack.begin() == mystack.begin()--) << "\n";

	std::cout << (mystack.end() == mystack.end()--) << "\n";

	std::cout << (mystack.begin() == --(--mystack.end())) << "\n";

	type another(mystack);
	std::cout << "another.size = " << another.size();

	return 0;
}
