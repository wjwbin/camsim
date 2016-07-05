TOP_DIR = ../
CC = g++
INCLUDE_DIR = $(TOP_DIR)/include
CFLAGS = -c -Wall -I$(INCLUDE_DIR)
SUBDIR = libjpeg #libpng

all: $(SUBDIR)

$(SUBDIR):echo
	for dir in $(SUBDIR); do\
		cd $$dir && make setup && cd ..;\
		done
	make -C $@

echo:
	@echo $(SUBDIR)
