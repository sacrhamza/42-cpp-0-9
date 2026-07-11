#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137){

	std::string fileName = target + "_shrubbery";
	std::fstream f(fileName.c_str(), std::ios_base::out | std::ios_base::trunc);

	if (!f.is_open())
	{
		std::cerr << "can' create the file and open it to write my awesome tree\n";
		return ;
	}

	std::string tree =
		"                                                  .         ;  "
		"                 .              .              ;%     ;;   "
		"                   ,           ,                :;%  %;   "
		"                    :         ;                   :;%;'     .,   "
		"           ,.        %;     %;            ;        %;'    ,;"
		"             ;       ;%;  %%;        ,     %;    ;%;    ,%'"
		"              %;       %;%;      ,  ;       %;  ;%;   ,%;' "
		"               ;%;      %;        ;%;        % ;%;  ,%;'"
		"                `%;.     ;%;     %;'         `;%%;.%;'"
		"                 `:;%.    ;%%. %@;        %; ;@%;%'"
		"                    `:%;.  :;bd%;          %;@%;'"
		"                      `@%:.  :;%.         ;@@%;'   "
		"                        `@%.  `;@%.      ;@@%;         "
		"                          `@%%. `@%%    ;@@%;        "
		"                            ;@%. :@%%  %@@%;       "
		"                              %@bd%%%bd%%:;     "
		"                                #@%%%%%:;;"
		"                                %@@%%%::;"
		"                                %@@@%(o);  . '         "
		"                                %@@@o%;:(.,'         "
		"                            `.. %@@@o%::;         "
		"                               `)@@@o%::;         "
		"                                %@@(o)::;        "
		"                               .%@@@@%::;         "
		"                               ;%@@@@%::;.          "
		"                              ;%@@@@%%:;;;. "
		"                          ...;%@@@@@%%:;;;;,.. ";

	f << tree;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
