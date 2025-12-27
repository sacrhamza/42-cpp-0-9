CPP = c++

RM = rm

RM_OPTION = -f

FILES = main.cpp Zombie.cpp zombieHorde.cpp


OBJECTS = $(FILES:%.cpp=%.o)

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ZombieHorde

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CPP) $^ -o $(NAME) 

%.o: %.cpp
	$(CPP) -c $< -o $@

clean:
	$(RM) $(RM_OPTION) $(OBJECTS)

fclean: clean
	$(RM) $(RM_OPTION) $(NAME)

re: fclean $(NAME)
