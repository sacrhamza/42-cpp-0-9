CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = PhoneBooK 

SOURCE_FILES = ./main.cpp ./PhoneBook.cpp ./Contact.cpp

$(TARGET): $(SOURCE_FILES)
	$(CPP) $(CPP_FLAGS) $^ -o $@

fclean:
	$(RM) $(RM_OPTION) $(TARGET)

re: fclean $(TARGET)


test: $(TARGET)
	@./a.out > file.log
	@bash test.sh

run: $(TARGET)
	./PhoneBooK
