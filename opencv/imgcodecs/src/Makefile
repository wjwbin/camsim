TOP_DIR = ../../..
OBJ_DIR = $(TOP_DIR)/debug/obj/imgcodecs
OPENCV_DIR = $(TOP_DIR)/opencv
VPATH = . $(OBJ_DIR)
MKDIR = mkdir

CC = g++
LD = g++
CFLAGS = -Wall -I$(TOP_DIR)/include  -I ../include -I$(OPENCV_DIR)/core/include \
				 -I$(OPENCV_DIR)/imgproc/include \
				 -I$(OPENCV_DIR)/hal/include -I$(OPENCV_DIR)/3rdparty/libjpeg -c

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(OBJS)

.PHONY: all clean setup

setup:
	$(MKDIR) -p $(OBJ_DIR)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

