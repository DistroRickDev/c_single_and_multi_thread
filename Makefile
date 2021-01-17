TARGET_1 = singlethreaded
TARGET_2 = multithreaded
TARGET_3 = test_sthread
TARGET_4 = test_mthread
CROSSTOOL =

CC_CPP = $(CROSSTOOL)g++
CC_C = $(CROSSTOOL)gcc

C_LIB = -lpthread

CFLAGS = -Wall -g -std=c99

single: 
		$(CC_C) $(CFLAGS) $(TARGET_1).c $(C_LIB) -o $(TARGET_1)

multi:  
		$(CC_C) $(CFLAGS) $(TARGET_2).c $(C_LIB) -o $(TARGET_2)
ssingle:  
		$(CC_C) $(CFLAGS) $(TARGET_3).c $(C_LIB) -o $(TARGET_3)

mmulti:  
		$(CC_C) $(CFLAGS) $(TARGET_4).c $(C_LIB) -o $(TARGET_4)

all: clean single multi ssingle mmulti

clean:
	rm -f $(TARGET_1) $(TARGET_2) $(TARGET_3) $(TARGET_4)