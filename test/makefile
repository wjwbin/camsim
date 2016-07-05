CC = g++
TOP_DIR = ..
OBJ_DIR = $(TOP_DIR)/debug/obj
INCLUDE_DIR=$(TOP_DIR)/include
CFLAGS = -c -Wall -I$(INCLUDE_DIR)
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp, %.o, $(SRCS))

all:$(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

clean:
	rm *.o
