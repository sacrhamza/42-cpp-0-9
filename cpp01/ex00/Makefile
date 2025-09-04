#!/usr/bin/make -f

CPP = c++

RM = rm

RM_OPTION = -f

FILES = newZombie.cpp Zombie.cpp randomChump.cpp main.cpp

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = Zombie

$(TARGET):
	$(CPP) $(CPP_FLAGS) $(FILES) -o $(TARGET) 

fclean:
	$(RM) $(RM_OPTION) $(TARGET)

re: fclean $(TARGET)
