#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), m_target(target){}

void ShrubberyCreationForm::takeAction() const {
	std::string fileName = m_target + "_shrubbery";
	std::fstream f(fileName.c_str(), std::ios_base::out | std::ios_base::trunc);

	if (!f.is_open())
	{
		std::cerr << "can' create the file and open it to write my awesome tree\n";
		return ;
	}

std::string tree =
    "                                                  .         ;\n"
    "                 .              .              ;%     ;;\n"
    "                   ,           ,                :;%  %;\n"
    "                    :         ;                   :;%;'     .,\n"
    "           ,.        %;     %;            ;        %;'    ,;\n"
    "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
    "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
    "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
    "                `%;.     ;%;     %;'         `;%%;.%;'\n"
    "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
    "                    `:%;.  :;bd%;          %;@%;'\n"
    "                      `@%:.  :;%.         ;@@%;'\n"
    "                        `@%.  `;@%.      ;@@%;\n"
    "                          `@%%. `@%%    ;@@%;\n"
    "                            ;@%. :@%%  %@@%;\n"
    "                              %@bd%%%bd%%:;\n"
    "                                #@%%%%%:;;\n"
    "                                %@@%%%::;\n"
    "                                %@@@%(o);  . '\n"
    "                                %@@@o%;:(.,'\n"
    "                            `.. %@@@o%::;\n"
    "                               `)@@@o%::;\n"
    "                                %@@(o)::;\n"
    "                               .%@@@@%::;\n"
    "                               ;%@@@@%::;.\n"
    "                              ;%@@@@%%:;;;.\n"
    "                          ...;%@@@@@%%:;;;;,.. \n";
	f << tree;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other),
m_target(other.m_target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	m_target = other.m_target;
	return (*this);
}


ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
