CPP = c++

RM = rm

RM_OPTION = -f

FILES = ./main.cpp ./ClapTrap.cpp ./FragTrap.cpp ./DiamondTrap.cpp ./ScavTrap.cpp

OBJECTS = $(FILES:%.cpp=%.o)

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = DiamondTrap

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CPP) $^ -o $(NAME) 

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	$(RM) $(RM_OPTION) $(OBJECTS)

fclean: clean
	$(RM) $(RM_OPTION) $(NAME)

re: fclean $(NAME)

run: $(NAME) clean
	./$(NAME)
	rm -rf $(NAME)
