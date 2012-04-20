#Makeile for the Kernel

DEBUG_ENABLE = -D DEBUG
CFLAGS = -lpython2.7 -I /usr/include/python2.7 -g

kernel: kernel.c kernel_data.c lookup.c dummy.c kernel.h pyBindings.h pyBindings.c tuioDriver.c tuioDriver.h
	gcc $(CFLAGS) kernel.c kernel_data.c lookup.c dummy.c pyBindings.c tuioDriver.c -o kernel

debug: kernel.c kernel_data.c lookup.c dummy.c kernel.h
	gcc $(DEBUG_ENABLE) $(CFLAGS) kernel.c kernel_data.c lookup.c dummy.c kernel.h pyBindings.h pyBindings.c tuioDriver.c -o kernel

kernel.c: kernel.strl
	esterel kernel.strl
clean:
	rm *~
	

