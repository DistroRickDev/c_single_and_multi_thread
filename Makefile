TARGET_1 = singlethreaded

CROSSTOOL =

CC_CPP = $(CROSSTOOL)g++
CC_C = $(CROSSTOOL)gcc

C_LIB = -lpthread

CFLAGS = -Wall -g -std=c99

all: clean $(TARGET_1)

$(TARGET_1): 
	$(CC_C) $(CFLAGS) $@.c $(C_LIB) -o $@

clean:
	rm -f $(TARGET_1)