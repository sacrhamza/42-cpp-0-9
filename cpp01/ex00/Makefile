CPP = c++

RM = rm

RM_OPTION = -f

FILES = newZombie.cpp Zombie.cpp randomChump.cpp main.cpp

OBJECTS = $(FILES:%.cpp=%.o)

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = Zombie

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CPP) $^ -o $(TARGET) 

%.o: %.cpp
	$(CPP) -c $< -o $@

clean:
	$(RM) $(RM_OPTION) $(OBJECTS)

fclean: clean
	$(RM) $(RM_OPTION) $(TARGET)

re: fclean $(TARGET)
