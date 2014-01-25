# The name of the executable to produce
EXE = clock.exe
# The objects to link
OBJS = clock.o

# Compiler flags:
FLAGS = $(shell sdl-config --cflags)
LIBS = $(shell sdl-config --static-lib)

# Put it all together and compile to .os:
$(EXE) : $(OBJS)
	g++ -o $(EXE) $(OBJS) $(LIBS) $(FLAGS)

# Compile all .cpps into .os:
%.o : %.cpp
	g++ $< -c $(LIBS) $(FLAGS)
