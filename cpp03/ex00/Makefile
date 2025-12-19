CPP = c++

RM = rm

RM_OPTION = -f

FILES = ./main.cpp ./ClapTrap.cpp

OBJECTS = $(FILES:%.cpp=%.o)

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = ClapTrap

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CPP) $^ -o $(TARGET) 

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	$(RM) $(RM_OPTION) $(OBJECTS)

fclean: clean
	$(RM) $(RM_OPTION) $(TARGET)

re: fclean $(TARGET)

run: $(TARGET)
	@./$(TARGET)
