TOP_DIR = ../../..
OBJ_DIR = $(TOP_DIR)/debug/obj/imgcodecs
#3rdparty/libjpeg
OPENCV_DIR = $(TOP_DIR)/opencv
VPATH = . $(OBJ_DIR)
INC_DIR := ../include
INC_DIR += -I$(TOP_DIR)/include
INC_DIR += -I$(OPENCV_DIR)/hal/include
INC_DIR += -I$(OPENCV_DIR)/imgproc/include
INC_DIR += -I$(OPENCV_DIR)/core/include

CC = gcc
LD = gcc

CFLAGS = -Wall -I$(INC_DIR) -c

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
MKDIR = mkdir

.PHONY: all setup

all: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

setup:
	$(MKDIR) -p $(OBJ_DIR)
