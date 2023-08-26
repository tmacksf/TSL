
CC := clang
CFLAGS := -Wall -g
# BINS := libTSL.a main

all: libTSL.a

libTSL.o:  
	$(CC) $(CFLAGS) -c datastructures/*.c search/search.c sort/sort.c str/str.c 

libTSL.a: libTSL.o 
	ar rcs libTSL.a sort.o linkedlist.o dlinkedlist.o search.o str.o hashtable.o vector.o 

# for testing
debug: libTSL.a main.c 
	$(CC) $(CFLAGS) -o main main.c libTSL.a 

clean: 
	rm *.o *.so 
