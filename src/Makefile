
CC := clang
CFLAGS := -Wall -g
# BINS := libTSL.a main

all: libTSL.a

libTSL.o:  
	$(CC) $(CFLAGS) -c -std=c99 datastructures/*.c search/search.c sort/sort.c str/str.c search/search.c 

libTSL.a: libTSL.o 
	ar rcs libTSL.a sort.o linkedlist.o dlinkedlist.o queue.o search.o str.o hashtable.o vector.o search.o

# for testing
debug: libTSL.a main.c 
	$(CC) $(CFLAGS) -o main main.c libTSL.a 

clean: 
	rm *.o *.so 
