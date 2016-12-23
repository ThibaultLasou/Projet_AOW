CC = g++
CXXFLAGS = -std=c++11 -Wall -Wnon-virtual-dtor -Wpedantic
EXEC_NAME = aow
SDIR = src/
ODIR = obj/
SRC = $(wildcard $(SDIR)*.cpp)
#OBJ_FILES = $(ODIR)$(SRC:.cpp=.o)
OBJ_FILES = $(patsubst $(SDIR)%,$(ODIR)%, $(SRC:.cpp=.o))

all : $(EXEC_NAME)

clean :
	rm $(OBJ_FILES)

mrproper : clean
	rm $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

$(OBJ_FILES) : $(ODIR)%.o: $(SDIR)%.cpp 
	$(CC) $(CXXFLAGS) -o $@ -c $<


