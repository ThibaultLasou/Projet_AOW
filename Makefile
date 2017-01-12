CC = g++
CXXFLAGS = -std=c++11 -Wall -Wnon-virtual-dtor -Wpedantic
EXEC_RELEASE = aow
EXEC_DEBUG = aow_d
SDIR = src/
ODIR_D = obj/Debug/
ODIR_R = obj/Release/
BDIR = bin/
IDIR = include/
SRC = $(wildcard src/*.cpp)
HEADS = $(wildcard src/*.hpp)
CLASSES = $(HEADS:$(SDIR)%.hpp=%)
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
