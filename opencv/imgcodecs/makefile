TOP_DIR = ../
CC = g++
INCLUDE_DIR = $(TOP_DIR)/include
CFLAGS = -c -Wall -I$(INCLUDE_DIR)
SUBDIR = src/

all: $(SUBDIR)

$(SUBDIR):echo
	cd $(SUBDIR) && make setup
	make -C $@

echo:
	@echo $(SUBDIR)
