CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = Account

FILES = ./tests.cpp ./Account.cpp 

OBJECTS = $(FILES:%.cpp=%.o)

$(TARGET): $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	$(RM) $(RM_OPTION) $(OBJECTS)

fclean: clean
	$(RM) $(RM_OPTION) $(TARGET)

re: fclean $(TARGET)

test: $(TARGET)
	@./$(TARGET) > file.log
	@bash test.sh
