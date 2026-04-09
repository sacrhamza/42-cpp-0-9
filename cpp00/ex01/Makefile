CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PhoneBook

FILES = ./main.cpp ./PhoneBook.cpp ./Contact.cpp

OBJECTS = $(FILES:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	$(RM) $(RM_OPTION) $(OBJECTS)

fclean: clean
	$(RM) $(RM_OPTION) $(NAME)

re: fclean $(NAME)

run: $(NAME)
	./$(NAME)


test: re
	echo 'testing'
	./"$(NAME)"
