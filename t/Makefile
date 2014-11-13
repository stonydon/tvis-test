ifndef CC 
CC := clang
endif 
CFLAGS := -g -O0 -Wall
TARGETS := t1 t2 t3 t4 

all: $(TARGETS)

check: sharness-test.t $(TARGETS)
	sharness-test.t

t1: t1.o
	$(CC) $^ $(CFLAGS) -o $@

%.o: %.c 
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(TARGETS) *~ *breakpoint* *.o *.dSYM	

