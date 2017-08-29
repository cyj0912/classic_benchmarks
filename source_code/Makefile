CC=gcc
CFLAGS=-static -O3 -mcpu=cortex-a53 -mtune=cortex-a53 -funroll-loops
CFLAGS+=-Icommon_64bit -lrt -lm

all: dhry1 dhry2 whets lloops lpack

clean:
	rm -f dhry1 dhry2 whets lloops lpack

dhry1: dhrystone1/dhry1.c common_64bit/cpuidc64.c
	$(CC) $^ $(CFLAGS) -o $@

dhry2: dhrystone2/dhry_1.c dhrystone2/dhry_2.c common_64bit/cpuidc64.c
	$(CC) $^ $(CFLAGS) -o $@

whets: whetstone/whets.c common_64bit/cpuidc64.c
	$(CC) $^ $(CFLAGS) -o $@

lloops: livermore_loops/lloops.c common_64bit/cpuidc64.c
	$(CC) $^ $(CFLAGS) -o $@

lpack: linpack/linpack.c common_64bit/cpuidc64.c
	$(CC) $^ $(CFLAGS) -o $@
