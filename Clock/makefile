UNAME = $(shell uname)

# The name of the executable to produce
EXE = clock.exe
# The objects to link
OBJS = clock.o

# Compiler flags:
ifeq ($(UNAME), $(filter $(UNAME),Linux Darwin))
LIBS = $(shell sdl-config --static-libs)
FLAGS = $(shell sdl-config --cflags)
else
LIBS = -lmingw32 -lSDLMain -lSDL -lopengl32
FLAGS = #WINDOWS FLAGS HERE
endif

# Put it all together and compile to .os:
$(EXE) : $(OBJS)
	g++ -o $(EXE) $(OBJS) $(LIBS) $(FLAGS)

# Compile all .cpps into .os:
%.o : %.cpp
	g++ $< -c $(FLAGS)
