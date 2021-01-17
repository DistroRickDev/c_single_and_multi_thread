TARGET_1 = singlethreaded
TARGET_2 = multithreaded
TARGET_3 = test_sthread
TARGET_4 = test_mthread
CROSSTOOL =

CC_CPP = $(CROSSTOOL)g++
CC_C = $(CROSSTOOL)gcc

C_LIB = -lpthread

CFLAGS = -Wall -g -std=c99

BUILD_F = build/

build:
	mkdir $(BUILD_F)

single: 
		$(CC_C) $(CFLAGS) $(TARGET_1).c $(C_LIB) -o $(BUILD_F)$(TARGET_1)

multi:  
		$(CC_C) $(CFLAGS) $(TARGET_2).c $(C_LIB) -o $(BUILD_F)$(TARGET_2)
ssingle:  
		$(CC_C) $(CFLAGS) $(TARGET_3).c $(C_LIB) -o $(BUILD_F)$(TARGET_3)

mmulti:  
		$(CC_C) $(CFLAGS) $(TARGET_4).c $(C_LIB) -o $(BUILD_F)$(TARGET_4)

all: clean build single multi ssingle mmulti

clean:
	rm -f -r $(BUILD_F)