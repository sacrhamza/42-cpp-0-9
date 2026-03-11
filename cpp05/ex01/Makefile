CPP = c++

RM = rm

RM_OPTION = -f

FILES = ./Dog.cpp ./Animal.cpp ./Cat.cpp ./main.cpp ./WrongCat.cpp ./WrongAnimal.cpp

OBJECTS = $(FILES:%.cpp=%.o)

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = polymorphism

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
