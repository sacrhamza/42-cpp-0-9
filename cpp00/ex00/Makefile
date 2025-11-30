#!/usr/bin/make -f
CPP = c++
RM = rm
RM_OPTION = -f

FLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = megaphone

$(TARGET): megaphone.cpp
	$(CPP) $(FLAGS) megaphone.cpp -o $(TARGET) 

fclean:
	$(RM) $(RM_OPTION) $(TARGET)

re: fclean $(TARGET)
