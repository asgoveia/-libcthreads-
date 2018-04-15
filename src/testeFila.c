#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cthread.h"
#include "../include/cdata.h"

/* Teste da função searchThreads. Essa função retorna 1 se existir
   determinada thread em uma fila, caso contrário retorna 0*/



int main()
{

    PFILA2 queue;
    queue = malloc(sizeof(FILA2));
    CreateFila2(queue);

    TCB_t *thread1 = malloc(sizeof(TCB_t));
    TCB_t *thread2 = malloc(sizeof(TCB_t));
    TCB_t *thread3 = malloc(sizeof(TCB_t));

    thread1->tid = 1;
    thread1->state = PROCST_CRIACAO;
    thread1->prio = 0;

    thread2->tid = 2;
    thread2->state = PROCST_CRIACAO;
    thread2->prio = 0;

    thread3->tid = 3;
    thread3->state = PROCST_CRIACAO;
    thread3->prio = 0;


    if(AppendFila2(queue, (void *) thread1) != 0)
    {
        printf("Erro ao criar thread%d\n", thread1->tid);
        return RETURN_ERROR;
    }

    if(AppendFila2(queue, (void *) thread2) != 0)
    {
        printf("Erro ao criar thread %d\n", thread2->tid);
        return RETURN_ERROR;
    }

    if(AppendFila2(queue, (void *) thread3) != 0)
    {
        printf("Erro ao criar thread %d\n", thread3->tid);
        return RETURN_ERROR;
    }

    printf("Append feito \n");

    if(searchThread(5, queue))
    {
        printf("Encontrou :)\n");
    }
    else
    {
        printf("Não encontrou :(\n");
    }

    return 0;
}
