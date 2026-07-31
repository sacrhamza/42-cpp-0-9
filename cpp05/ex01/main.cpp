#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

void test_beSigned_signForm(void)
{
	// good alan will sign the form3
	try {
		Bureaucrat bureaucrat("Alan", 20);
		Form form("form3", 30, 20);
		bureaucrat.signForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}

	try {
		Bureaucrat bureaucrat("lee", 20);
		Form form("form4", 10, 20);
		bureaucrat.signForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}	
}

void testFormInsertionOp(void) {
	try {
		Form form("form2", 150, 150);
		std::cout << form;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what()	 << "\n";
	}
}

void testFormConstructors(void) {
	// too low
	try {
		Form form1("form1", 152, 200);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	// too high
	try {
		Form form1("form1", 0, 0);
	}
	catch(const std::runtime_error &e)
	{
		std::cerr << e.what() << "\n";
	}

	try {
		Form form1("form1", 150, 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	try{
		Form form1("form1", 22, 22);	
		Form form2(form1);	
		std::cout << form2;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
}

int main(void) {

	testFormConstructors();
	testFormInsertionOp();
	test_beSigned_signForm();

	return (0);

}
