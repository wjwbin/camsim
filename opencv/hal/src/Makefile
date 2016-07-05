TOP_DIR = ../../..
OBJ_DIR = $(TOP_DIR)/debug/obj/hal
VPATH= . $(OBJ_DIR)
OPENCV_DIR = $(TOP_DIR)/opencv

INC_DIR := ../include
INC_DIR += -I$(TOP_DIR)/include
INC_DIR += -I$(OPENCV_DIR)/core/include

CC = gcc
#LD = g++

CFLAGS = -Wall -I$(INC_DIR) -c
MKDIR = mkdir

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

.PHONY: all setup

all: $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

setup:
	$(MKDIR) -p $(OBJ_DIR)

