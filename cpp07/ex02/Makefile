CPP = c++

SRCS = main.cpp

OBJS = $(SRCS:%.cpp=%.o)

CPP_FLAGS = -std=c++98 -Wall -Werror -Wextra

NAME = array

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -o "$@" -c "$<"

clean:
	$(RM) $(RM_OPTIONS) $(OBJS)

fclean: clean
	$(RM) $(RM_OPTIONS) $(NAME)

run: $(NAME)
	./"$(NAME)"

re: fclean $(NAME)
