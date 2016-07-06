OBJS = $(wildcard obj/*.o)
OBJS += $(wildcard obj/core/*.o)
OBJS += $(wildcard obj/hal/*.o)
OBJS += $(wildcard obj/imgcodecs/*.o)
OBJS += $(wildcard obj/imgproc/*.o)
OBJS += $(wildcard obj/3rdparty/libjpeg/*.o)
OBJS += $(wildcard obj/test/*.o)

CC = g++
LD = g++
LDFLAGS = -ldl -lpthread

camsim: $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

