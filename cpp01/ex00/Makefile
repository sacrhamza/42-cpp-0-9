CPP = c++

RM = rm

RM_OPTION = -f

FILES = newZombie.cpp Zombie.cpp randomChump.cpp main.cpp

OBJECTS = $(FILES:%.cpp=%.o)

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Zombie

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

run: $(NAME)
	./$(NAME)
