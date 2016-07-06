CC = g++
MKDIR = mkdir


TOP_DIR = ..
OBJ_DIR = $(TOP_DIR)/debug/obj/test

OPENCV_DIR = $(TOP_DIR)/opencv
INC_DIR := $(TOP_DIR)/include
INC_DIR += -I$(OPENCV_DIR)/core/include
INC_DIR += -I$(OPENCV_DIR)/hal/include
INC_DIR += -I$(OPENCV_DIR)/imgcodecs/include
INC_DIR += -I$(OPENCV_DIR)/imgproc/include

CFLAGS = -c -Wall -I$(INC_DIR)
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp, %.o, $(SRCS))

all:setup $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

setup:
	$(MKDIR) -p $(OBJ_DIR)
