#!/usr/bin/make -f

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm

RM_OPTION = -f

FILES = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp


TARGET = Weapon

$(TARGET): $(FILES)
	@$(CPP) $(CPP_FLAGS) $^ -o $@

fclean:
	@$(RM) $(RM_OPTION) $(TARGET)

re: fclean $(TARGET)

run:
	@./$(TARGET)
