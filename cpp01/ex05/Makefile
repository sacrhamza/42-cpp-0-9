CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

OBJECTS = $(FILES:%.cpp=%.o)

RM = rm

RM_OPTION = -f

FILES = main.cpp Harl.cpp

NAME = Harl

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
