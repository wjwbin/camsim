OBJS = $(wildcard obj/*.o)
OBJS += $(wildcard obj/core/*.o)
OBJS += $(wildcard obj/hal/*.o)
OBJS += $(wildcard obj/imgcodecs/*.o)

CC = g++
LD = g++
LDFLAGS = -ldl -lpthread

camsim: $(OBJS)
	$(LD)  -o $@ $^ $(LDFLAGS)

