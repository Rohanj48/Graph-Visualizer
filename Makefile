

INCLUDES = lib/raywin.cpp lib/alg.cpp 

all:
	g++ main.cpp $(INCLUDES) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o target.out