TOP_DIR = ../../..
OBJ_DIR = $(TOP_DIR)/debug/obj/core
OPENCV_DIR = $(TOP_DIR)/opencv
VPATH = . $(OBJ_DIR)

CC = g++
LD = g++
CFLAGS = -Wall -I$(TOP_DIR)/include  -I ../include -I$(OPENCV_DIR)/hal/include -I$(OPENCV_DIR)/imgproc/include -c

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
MKDIR = mkdir

.PHONY: all setup

all: $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

setup:
	$(MKDIR) -p $(OBJ_DIR)
