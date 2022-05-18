# A simple Makefile for compiling small SDL projects

# set the compiler
CC := clang++

# set the compiler flags
CXXFLAGS := -std=c++11 -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends `sdl2-config --libs --cflags` -ggdb3 -O0 -g -Wall -Wformat -lSDL2 -lm -fopenmp
# add header files here
# Scene.h utils/Point.h utils/Ray.h utils/Sphere.h utils/Vec.h PinholeCamera.h utils/Light.h utils/Hittable.h prims/Materials/Lambertian.h prims/Materials/Metal.h utils/Functions.h gui/nuklear/nuklear.h
HDRS := $(shell find './' ! -path '*/extraneous/*' -name '*.h')

IMGUI_DIR = gui/imgui/

# Source files
# main.cpp Scene.cpp utils/Point.cpp utils/Ray.cpp utils/Sphere.cpp utils/Vec.cpp PinholeCamera.cpp utils/Light.cpp utils/Functions.cpp
SRCS := $(shell find './' ! -path '*/extraneous/*' -name '*.cpp' -or -name '*.c')

# generate names of object files
OBJS := $(SRCS:.cpp=.o)

# name of executable
EXEC := Joetracer

# libaries
LIBS += -lGL -ldl `sdl2-config --libs` -I/usr/include/

# default recipe
all: $(EXEC)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CXXFLAGS) $(LIBS)

# recipe for building object files
$(OBJS): $(@:.o=.cpp) $(HDRS) Makefile
	$(CC) -o $@ $(@:.o=.cpp) -c $(CFLAGS) 

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean