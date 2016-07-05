# Comment here.
#
CC = gcc
LD = g++
MAKE = make
OPENCV_DIR = opencv/
CFLAGS = -c -Wall -I include -I$(OPENCV_DIR)/core/include -I$(OPENCV_DIR)/imgcodecs/include -I$(OPENCV_DIR)/hal/include
OBJ_DIR = debug/obj

# Assign SRCS with all cpp source file
SRCS = $(wildcard *.cpp)
# OBJS contains all the object file
OBJS=$(patsubst %.cpp, %.o, $(SRCS))

#TODO: automatically search sub directory.
SUBDIR = test/ opencv/
#SUBDIRS=$(shell ls -l | grep ^d | awk '{if($$9 != "debug") print $$9}')
RM = rm -rf

all: $(SUBDIR) $(OBJS) target

# call subdirectory makefile
$(SUBDIR):echo
	make -C $@

echo:
	@echo $(SUBDIR)

$(OBJS):%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

target:
	make -C debug

clean:
	$(RM) $(OBJ_DIR)