SDIR = src/
ODIR_D = obj/Debug/
ODIR_R = obj/Release/
BDIR = bin/
IDIR = include/
CC = g++
CXXFLAGS = -std=c++11 -Wall -Wnon-virtual-dtor -Wpedantic -I$(IDIR)
EXEC_RELEASE = aow
EXEC_DEBUG = aow_d
SRC = $(wildcard $(SDIR)*.cpp)
HEADS = $(wildcard $(IDIR)*.hpp)
CLASSES = $(HEADS:$(IDIR)%.hpp=%)
OBJ = $(CLASSES:%=$(ODIR_R)%.o)
OBJ_D = $(CLASSES:%=$(ODIR_D)%.o)
MOBJ = $(ODIR_R)main.o
MOBJ_D = $(ODIR_D)main.o

Debug : $(EXEC_DEBUG)

Release : $(EXEC_RELEASE)

clean :
	rm $(OBJ) $(OBJ_D) $(MOBJ_D) $(MOBJ)

mrproper : clean
	echo $(EXEC_NAME_RELEASE) $(EXEC_NAME_DEBUG)

$(EXEC_RELEASE) : $(OBJ) $(MOBJ)
	$(CC) -o $@ $^

$(EXEC_DEBUG) : $(OBJ_D) $(MOBJ_D)
	$(CC) -o $@ $^

$(MOBJ) : $(HEADS)

$(MOBJ_D) : $(HEADS)

$(ODIR_D)%.o: $(SDIR)%.cpp 
	$(CC) -o $@ -c $< $(CXXFLAGS) -g

$(ODIR_R)%.o: $(SDIR)%.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS)

depend : $(CLASSES)
	$(CC) -MM $(CXXFLAGS) $(SDIR)main.cpp -MT $(ODIR_D)main.o >> Makefile;
	$(CC) -MM $(CXXFLAGS) $(SDIR)main.cpp -MT $(ODIR_R)main.o >> Makefile;

$(CLASSES) : 
	$(CC) -MM $(CXXFLAGS) $(SDIR)$@.cpp -MT $(ODIR_D)$@.o >> Makefile;
	$(CC) -MM $(CXXFLAGS) $(SDIR)$@.cpp -MT $(ODIR_R)$@.o >> Makefile;

obj/Debug/Archer.o: src/Archer.cpp include/Joueur.hpp include/Archer.hpp \
 include/Unite.hpp include/Attaquable.hpp include/Case.hpp
obj/Release/Archer.o: src/Archer.cpp include/Joueur.hpp \
 include/Archer.hpp include/Unite.hpp include/Attaquable.hpp \
 include/Case.hpp
obj/Debug/Catapulte.o: src/Catapulte.cpp include/Joueur.hpp \
 include/Catapulte.hpp include/Unite.hpp include/Attaquable.hpp \
 include/Case.hpp
obj/Release/Catapulte.o: src/Catapulte.cpp include/Joueur.hpp \
 include/Catapulte.hpp include/Unite.hpp include/Attaquable.hpp \
 include/Case.hpp
obj/Debug/SuperSoldat.o: src/SuperSoldat.cpp include/SuperSoldat.hpp \
 include/Fantassin.hpp include/Unite.hpp include/Attaquable.hpp \
 include/Case.hpp
obj/Release/SuperSoldat.o: src/SuperSoldat.cpp include/SuperSoldat.hpp \
 include/Fantassin.hpp include/Unite.hpp include/Attaquable.hpp \
 include/Case.hpp
obj/Debug/Unite.o: src/Unite.cpp include/Unite.hpp include/Attaquable.hpp \
 include/Case.hpp include/Joueur.hpp include/Case.hpp include/Base.hpp
obj/Release/Unite.o: src/Unite.cpp include/Unite.hpp \
 include/Attaquable.hpp include/Case.hpp include/Joueur.hpp \
 include/Case.hpp include/Base.hpp
obj/Debug/Attaquable.o: src/Attaquable.cpp include/Attaquable.hpp
obj/Release/Attaquable.o: src/Attaquable.cpp include/Attaquable.hpp
obj/Debug/Fantassin.o: src/Fantassin.cpp include/Joueur.hpp \
 include/Fantassin.hpp include/Unite.hpp include/Attaquable.hpp \
 include/Case.hpp
obj/Release/Fantassin.o: src/Fantassin.cpp include/Joueur.hpp \
 include/Fantassin.hpp include/Unite.hpp include/Attaquable.hpp \
 include/Case.hpp
obj/Debug/Case.o: src/Case.cpp include/Case.hpp include/Jeu.hpp \
 include/Joueur.hpp include/Case.hpp include/Unite.hpp \
 include/Attaquable.hpp
obj/Release/Case.o: src/Case.cpp include/Case.hpp include/Jeu.hpp \
 include/Joueur.hpp include/Case.hpp include/Unite.hpp \
 include/Attaquable.hpp
obj/Debug/NotInListException.o: src/NotInListException.cpp \
 include/NotInListException.hpp
obj/Release/NotInListException.o: src/NotInListException.cpp \
 include/NotInListException.hpp
obj/Debug/Base.o: src/Base.cpp include/Jeu.hpp include/Joueur.hpp \
 include/Case.hpp include/Joueur.hpp include/Base.hpp \
 include/Attaquable.hpp include/Attaquable.hpp include/Unite.hpp
obj/Release/Base.o: src/Base.cpp include/Jeu.hpp include/Joueur.hpp \
 include/Case.hpp include/Joueur.hpp include/Base.hpp \
 include/Attaquable.hpp include/Attaquable.hpp include/Unite.hpp
obj/Debug/Jeu.o: src/Jeu.cpp include/Jeu.hpp include/Joueur.hpp \
 include/Case.hpp include/Base.hpp include/Attaquable.hpp \
 include/JoueurHumain.hpp include/NotInListException.hpp
obj/Release/Jeu.o: src/Jeu.cpp include/Jeu.hpp include/Joueur.hpp \
 include/Case.hpp include/Base.hpp include/Attaquable.hpp \
 include/JoueurHumain.hpp include/NotInListException.hpp
obj/Debug/Joueur.o: src/Joueur.cpp include/Joueur.hpp include/Base.hpp \
 include/Attaquable.hpp include/Case.hpp include/Fantassin.hpp \
 include/Unite.hpp include/Archer.hpp include/Catapulte.hpp \
 include/Jeu.hpp include/Joueur.hpp include/NotInListException.hpp \
 include/CinException.hpp
obj/Release/Joueur.o: src/Joueur.cpp include/Joueur.hpp include/Base.hpp \
 include/Attaquable.hpp include/Case.hpp include/Fantassin.hpp \
 include/Unite.hpp include/Archer.hpp include/Catapulte.hpp \
 include/Jeu.hpp include/Joueur.hpp include/NotInListException.hpp \
 include/CinException.hpp
obj/Debug/JoueurHumain.o: src/JoueurHumain.cpp include/JoueurHumain.hpp \
 include/Joueur.hpp include/Joueur.hpp include/Base.hpp \
 include/Attaquable.hpp include/Case.hpp include/Fantassin.hpp \
 include/Unite.hpp include/Archer.hpp include/Catapulte.hpp \
 include/CinException.hpp
obj/Release/JoueurHumain.o: src/JoueurHumain.cpp include/JoueurHumain.hpp \
 include/Joueur.hpp include/Joueur.hpp include/Base.hpp \
 include/Attaquable.hpp include/Case.hpp include/Fantassin.hpp \
 include/Unite.hpp include/Archer.hpp include/Catapulte.hpp \
 include/CinException.hpp
obj/Debug/CinException.o: src/CinException.cpp include/CinException.hpp
obj/Release/CinException.o: src/CinException.cpp include/CinException.hpp
obj/Debug/main.o: src/main.cpp include/Jeu.hpp include/Joueur.hpp \
 include/Case.hpp
obj/Release/main.o: src/main.cpp include/Jeu.hpp include/Joueur.hpp \
 include/Case.hpp
