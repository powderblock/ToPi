# The name of the executable to produce
EXE = clock.exe
# The objects to link
OBJS = clock.o

# Compiler flags:
LIBS = $(shell sdl-config --static-lib --cflags)

# Put it all together and compile to .os:
$(EXE) : $(OBJS)
	g++ -o $(EXE) $(OBJS) $(LIBS)

# Compile all .cpps into .os:
%.o : %.cpp
	g++ $< -c
