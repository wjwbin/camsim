TOP_DIR = ../
CC = g++
INCLUDE_DIR = $(TOP_DIR)/include
CFLAGS = -c -Wall -I$(INCLUDE_DIR)
SUBDIR = imgcodecs/ hal/ core/ 3rdparty/ imgproc/

all: $(SUBDIR)

$(SUBDIR):echo
	make -C $@

echo:
	@echo $(SUBDIR)
