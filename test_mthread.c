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

void *matrix_build(void * line){
    int iLine = *(int *)line;
    for (int i = 0; i < COLS; i++)
    {
        srand(time(NULL));
        mega_array[iLine][i] = rand()%100;
    }
    pthread_exit(line);
}

int main(int argc, char* argv[]){
    clock_t begin = clock();
    pthread_t tids[LINES];

     for (int i = 0; i < LINES; i++)
    {
        //pthread_attr_t p_atr;
        //pthread_attr_init(&p_atr);
        pthread_create(&tids[i], NULL, matrix_build, &i);
        pthread_join(tids[i], NULL);
    }

    printf("Time elapsed:%fs \n",(double)(clock() - begin)/ CLOCKS_PER_SEC);
    return 0;
}
