TOP_DIR = ../../..
OBJ_DIR = $(TOP_DIR)/debug/obj/core
OPENCV_DIR = $(TOP_DIR)/opencv
VPATH = . $(OBJ_DIR)

INC_DIR := ../include
INC_DIR += -I$(TOP_DIR)/include
INC_DIR += -I$(OPENCV_DIR)/hal/include
INC_DIR += -I$(OPENCV_DIR)/imgproc/include
INC_DIR += -I$(OPENCV_DIR)/imgcodecs/include

CC = g++
LD = g++
CFLAGS = -Wall -I$(INC_DIR) -c

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
MKDIR = mkdir

.PHONY: all setup

all: $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

setup:
	$(MKDIR) -p $(OBJ_DIR)
