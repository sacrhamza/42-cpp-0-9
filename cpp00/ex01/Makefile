CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = PhoneBook

FILES = ./main.cpp ./PhoneBook.cpp ./Contact.cpp

OBJECTS = $(FILES:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	$(RM) $(RM_OPTION) $(OBJECTS)

fclean: clean
	$(RM) $(RM_OPTION) $(TARGET)

re: fclean $(TARGET)

run: $(TARGET)
	./$(TARGET)
