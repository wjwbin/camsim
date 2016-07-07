DEPS := $(wildcard obj/*.o)
DEPS += $(wildcard obj/core/*.o)
DEPS += $(wildcard obj/hal/*.o)
DEPS += $(wildcard obj/imgcodecs/*.o)
DEPS += $(wildcard obj/imgproc/*.o)
DEPS += $(wildcard obj/3rdparty/libjpeg/*.o)
DEPS += $(wildcard obj/test/*.o)
DEPS += $(wildcard obj/isp/*.o)
DEPS += $(wildcard obj/parser/*.o)

CC = g++
LD = g++
LDFLAGS = -ldl -lpthread

camsim: $(DEPS)
	$(LD) -o $@ $^ $(LDFLAGS)

