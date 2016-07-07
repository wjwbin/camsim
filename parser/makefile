#specify the useful path
TOP_DIR = ..
OPENCV_DIR = $(TOP_DIR)/opencv
OBJ_DIR = $(TOP_DIR)/debug/obj/parser
VPATH = . $(OBJ_DIR)
INC_DIR := $(TOP_DIR)/include
INC_DIR += -I$(OPENCV_DIR)/core/include
INC_DIR += -I$(OPENCV_DIR)/hal/include
INC_DIR += -I$(OPENCV_DIR)/imgcodecs/include
INC_DIR += -I$(OPENCV_DIR)/imgproc/include

CC = g++
LD = g++
CFLAGS = -c -Wall -I $(INC_DIR)

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))



RM = rm -rf
MKDIR = mkdir

all: setup $(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

setup:
	$(MKDIR) -p $(OBJ_DIR)
