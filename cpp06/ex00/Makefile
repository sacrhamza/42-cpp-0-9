CPP = c++

CPP_FLAGS = -std=c++98 -Wall -Werror -Wextra

SRCS = ./main.cpp ./ScalarConverter.cpp

OBJS = $(SRCS:%.cpp=%.o)

NAME = convert

$(NAME) : $(OBJS)
	$(CPP) $(CPP_FLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@
