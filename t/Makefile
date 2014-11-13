CC     := clang
CFLAGS := -g -O0 -Wall
TARGETS := t1 t2 t3 t4 

all: $(TARGETS)


t1: t1.o
	$(CC) $^ $(CFLAGS) -o $@

%.o: %.c 
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(TARGETS) *~ *breakpoint* *.o *.dSYM	

