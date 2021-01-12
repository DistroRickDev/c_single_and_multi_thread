TARGET_1 = singlethreaded
TARGET_2 = multithreaded
CROSSTOOL =

CC_CPP = $(CROSSTOOL)g++
CC_C = $(CROSSTOOL)gcc

C_LIB = -lpthread

CFLAGS = -Wall -g -std=c99

single: 
		$(CC_C) $(CFLAGS) $(TARGET_1).c $(C_LIB) -o $(TARGET_1)

multi:  
		$(CC_C) $(CFLAGS) $(TARGET_2).c $(C_LIB) -o $(TARGET_2)


all: clean single multi 

clean:
	rm -f $(TARGET_1) $(TARGET_2)