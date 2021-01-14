#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <time.h>

#define LINES 10
#define COLS 5

static volatile int mSum = 0;
int line_sum = 0;

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
    /*L10*/{40,42,44,46,48}
};

void *matrix_sums(void * line);

int main(int argc, char* argv[]){

    printf("This system has %d processors configured and "
        "%d processors available.\n",
        get_nprocs_conf(), get_nprocs());

    clock_t begin = clock();
    pthread_t tids[LINES];

    for (int i = 0; i <= LINES; i++)
    {
        //pthread_attr_t p_atr;
        //pthread_attr_init(&p_atr);
        pthread_create(&tids[i], NULL, matrix_sums, &i);
        pthread_join(tids[i], NULL);
        printf("LINE %d sum is: %d\n", i , line_sum);
    }
    printf("Matrix sum is: %d\n", mSum);
    printf("Time elapsed:%fs \n",(double)(clock() - begin)/ CLOCKS_PER_SEC);
    return 0;
}

void *matrix_sums(void * line){
    line_sum = 0;
    int iLine = *(int *)line;
    for(int j=0; j< COLS; j++){
        line_sum+=matrix[iLine][j];
    }
    mSum += line_sum;    
    pthread_exit(line);
}


