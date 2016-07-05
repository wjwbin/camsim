TOP_DIR = ../../..
OBJ_DIR = $(TOP_DIR)/debug/obj/imgcodecs
OPENCV_DIR = $(TOP_DIR)/opencv
VPATH = . $(OBJ_DIR)
MKDIR = mkdir

INC_DIR := $(TOP_DIR)/include
INC_DIR += -I../include
INC_DIR += -I$(OPENCV_DIR)/core/include
INC_DIR += -I$(OPENCV_DIR)/imgproc/include
INC_DIR += -I$(OPENCV_DIR)/hal/include
INC_DIR += -I$(OPENCV_DIR)/3rdparty/libjpeg

CC = g++
LD = g++
CFLAGS = -Wall -I$(INC_DIR) -c

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(OBJS)

.PHONY: all clean setup

setup:
	$(MKDIR) -p $(OBJ_DIR)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

