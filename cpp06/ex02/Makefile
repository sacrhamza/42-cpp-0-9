CPP = c++

RM = rm

RM_OPTION = -f

FILES = ./main.cpp ./Base.cpp ./utils.cpp ./Factory.cpp ./FactoryA.cpp ./FactoryB.cpp ./FactoryC.cpp

OBJECTS = $(FILES:%.cpp=%.o)

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = identify

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
	./"$(NAME)"

test: re
	echo 'testing'
	./"$(NAME)"
