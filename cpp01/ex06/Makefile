#!/usr/bin/make -f

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm

RM_OPTION = -f

FILES = main.cpp Harl.cpp

NAME = harlFilter

$(NAME): $(FILES)
	@$(CPP) $(CPP_FLAGS) $^ -o $@

fclean:
	@$(RM) $(RM_OPTION) $(NAME)

re: fclean $(NAME)

run:
	@./$(NAME)
