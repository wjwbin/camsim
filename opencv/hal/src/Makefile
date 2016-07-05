TOP_DIR = ../../..
OBJ_DIR = $(TOP_DIR)/debug/obj/hal
VPATH= . $(OBJ_DIR)
OPENCV_DIR = $(TOP_DIR)/opencv

CC = g++
#LD = g++
CFLAGS = -I$(TOP_DIR)/include  -I ../include -I$(OPENCV_DIR)/core/include -c
MKDIR = mkdir

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

.PHONY: all setup

all: $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

setup:
	$(MKDIR) -p $(OBJ_DIR)

