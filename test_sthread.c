/*
    ALUNOS: RICARDO DUARTE
            VENTURA TAMBA
    CURSO: LICENCIATURA EM ENGENHARIA ELETROTECNICA E COMPUTADORES 2 ANO
    UC: ARQUITETURA DE SISTEMAS COMPUTACIONAIS
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define LINES 5
#define COLS 600000
int mega_array[LINES][COLS];

void *sum_matrix(void * pid){
    for (int j = 0; j < LINES; j++)
    {
        for (int i = 0; i < COLS; i++)
        {
            srand(time(NULL));
            mega_array[j][i] = rand()%100;
        }
    }
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
