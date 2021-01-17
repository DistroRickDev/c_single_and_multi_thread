#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define LINES 10
#define COLS 5

int matrix[LINES][COLS] = {
    /*L1*/ {0,2,4,6,8},
    /*L2*/ {49,47,45,43,41},
    /*L3*/ {10,12,14,16,18},
    /*L4*/ {39,37,35,33,31},
    /*L5*/ {20,22,24,26,28},
    /*L6*/ {29,27,25,23,21},
    /*L7*/ {30,32,34,36,38},
    /*L8*/ {40,42,44,46,48},
    /*L9*/ {19,17,15,13,11},
    /*L10*/{50,52,54,56,58}
};


void *sum_matrix(void * pid){
    printf("Thread ID: %d\n", *(int *)pid);

    for(int i = 0; i< LINES; i++)
    {
        long int sum = 0;
        
        for(int j=0; j< COLS; j++){
            sum+=matrix[i][j];
        }
        printf("LINE %d sum: %ld\n", i, sum);
    }
    long int sum = 0;
    for(int i = 0; i< LINES; i++)
    {
        for(int j=0; j< COLS; j++){
            sum+=matrix[i][j];
        }
    }
    printf("Matrix sum: %ld\n", sum);
    pthread_exit(0);
}

int main(int argc, char* argv[]){
    clock_t begin = clock();
    pthread_t tid;
    int arg = (int)tid;
    pthread_attr_t p_atr;
    pthread_attr_init(&p_atr);

    pthread_create(&tid, &p_atr, sum_matrix, &arg);
    pthread_join(tid, NULL);

    printf("Time elapsed:%fs \n",(double)(clock() - begin)/ CLOCKS_PER_SEC);
    return 0;
}
