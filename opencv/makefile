TOP_DIR = ../
CC = g++
INCLUDE_DIR = $(TOP_DIR)/include
CFLAGS = -c -Wall -I$(INCLUDE_DIR)
SUBDIR = imgcodecs/ hal/ core/

all: $(SUBDIR)

$(SUBDIR):echo
	make -C $@

echo:
	@echo $(SUBDIR)
