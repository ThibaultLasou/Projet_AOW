CC = g++
CXXFLAGS = -std=c++11 -Wall -Wnon-virtual-dtor -Wpedantic
EXEC_NAME = aow
EXEC_NAME_DEBUG = aowd

SRC = src/main.cpp src/Attaquable.cpp src/Jeu.cpp src/Joueur.cpp src/Base.cpp src/Case.cpp src/Unite.cpp src/Catapulte.cpp src/Archer.cpp src/Fantassin.cpp

OBJ_FILES = $(SRC:.cpp=.o)

Debug: $(EXEC_NAME_DEBUG)

all : $(EXEC_NAME)

clean :
	rm $(OBJ_FILES)

mrproper : clean
	rm $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $@ $^

$(EXEC_NAME_DEBUG) : $(OBJ_FILES)
	$(CC) -o $@ $^

$(OBJ_FILES_DEBUG): $(OBJ_FILES)

%.o: %.cpp %.hpp
	$(CC) -o $@ -c $< $(CXXFLAGS) 
