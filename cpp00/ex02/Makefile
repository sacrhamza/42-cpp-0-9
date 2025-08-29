CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = a.out

SOURCE_FILES = Account.cpp tests.cpp

$(TARGET): $(SOURCE_FILES)
	$(CPP) $(CPP_FLAGS) $^ -o $@

test: $(TARGET)
	@./a.out > file.log
	@bash test.sh
