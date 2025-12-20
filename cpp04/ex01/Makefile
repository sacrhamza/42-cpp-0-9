CPP = c++

RM = rm

RM_OPTION = -f

FILES = ./Dog.cpp ./Animal.cpp ./Cat.cpp ./main.cpp ./WrongCat.cpp ./WrongAnimal.cpp ./Brain.cpp

OBJECTS = $(FILES:%.cpp=%.o)

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -g

TARGET = polymorphism

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $^ -o $(TARGET) 

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	$(RM) $(RM_OPTION) $(OBJECTS)

fclean: clean
	$(RM) $(RM_OPTION) $(TARGET)

re: fclean $(TARGET)

run: $(TARGET)
	./$(TARGET)
