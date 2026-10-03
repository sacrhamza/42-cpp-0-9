CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm
RM_OPTION = -f

SRCS = main.cpp

OBJECTS = $(SRCS:%.cpp=%.o)

NAME = main

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
