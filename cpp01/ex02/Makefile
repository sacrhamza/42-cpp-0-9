#!/usr/bin/make -f

CPP = c++

RM = rm

RM_OPTION = -f

FILES = main.cpp

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = Reference

$(TARGET): $(FILES)
	$(CPP) $(CPP_FLAGS) $< -o $@

fclean:
	$(RM) $(RM_OPTION) $(TARGET)

re: fclean $(TARGET)
