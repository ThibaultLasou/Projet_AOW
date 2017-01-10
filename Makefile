CC = g++
CXXFLAGS = -std=c++11 -Wall -Wnon-virtual-dtor -Wpedantic
EXEC_NAME_RELEASE = aow
EXEC_NAME_DEBUG = aow_d
SRC = src/main.cpp src/Attaquable.cpp src/Jeu.cpp src/Joueur.cpp src/Base.cpp src/Case.cpp src/Unite.cpp src/Catapulte.cpp src/Archer.cpp src/Fantassin.cpp
OBJ_FILES = $(SRC:.cpp=.o)
OBJ_FILES_DEBUG = $(OBJ_FILES)

Debug : $(EXEC_NAME_DEBUG)

Release : $(EXEC_NAME_RELEASE)

all : $(EXEC_NAME_RELEASE) $(EXEC_NAME_DEBUG)

clean :
	rm $(OBJ_FILES)

mrproper : clean
	rm $(EXEC_NAME_RELEASE) $(EXEC_NAME_DEBUG)

$(EXEC_NAME_RELEASE) : $(OBJ_FILES)
	$(CC) -o $@ $^

$(EXEC_NAME_DEBUG) : $(OBJ_FILES_DEBUG)
	$(CC) -o $@ $^

$(OBJ_FILES_DEBUG): %.o : %.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS) -g

%.o: %.cpp %.hpp
	$(CC) -o $@ -c $< $(CXXFLAGS) 
