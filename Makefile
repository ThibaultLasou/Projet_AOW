CC = g++
CXXFLAGS = -std=c++11 -Wall -Wnon-virtual-dtor -Wpedantic
EXEC_NAME = aow
SRC = src/main.cpp src/Attaquable.cpp src/Jeu.cpp src/Joueur.cpp src/Base.cpp src/Case.cpp src/Unite.cpp
OBJ_FILES = $(SRC:.cpp=.o)

all : $(EXEC_NAME)

clean :
	rm $(OBJ_FILES)

mrproper : clean
	rm $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $@ $^

%.o: %.cpp %.hpp
	$(CC) -o $@ -c $< $(CXXFLAGS) 
