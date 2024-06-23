

INCLUDES = lib/raywin.cpp lib/alg.cpp lib/graph.cpp
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
all:
	g++ main.cpp $(INCLUDES) $(LIBS) -o target.out