vrf_setsockopt.o: vrf_setsockopt.c
	clang-9 -target bpf -c -O2 vrf_setsockopt.c -I/usr/include/x86_64-linux-gnu/

all: vrf_setsockopt.o

