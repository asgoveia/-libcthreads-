#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cthread.h"
#include "../include/cdata.h"

PFILA2 readyQueue;
PFILA2 blockedQueue;
PFILA2 finishedQueue;
PFILA2 readySuspendedQueue;
PFILA2 blockedSuspendedQueue;

TCB_t * executingThread;

ucontext_t SchedulerContext;
int tCounter = 0;
int has_init = 0;


// -----------------------------------------------------------------------------

int dispatcher()
{

    return 0;
} // end method

// -----------------------------------------------------------------------------

void createSchedulerContext()
{

    getcontext(&SchedulerContext);
    char stack_dispatcher[SIGSTKSZ];
    SchedulerContext.uc_stack.ss_sp = stack_dispatcher;
    SchedulerContext.uc_stack.ss_size = sizeof(stack_dispatcher);
    makecontext( &SchedulerContext, (void (*)(void))dispatcher, 0);
} // end method

// -----------------------------------------------------------------------------

TCB_t* createThread(int prio)
{

    TCB_t * newThread = malloc(sizeof(TCB_t));

    if(newThread != NULL)
    {
        newThread->tid = tCounter;
        newThread->state = PROCST_CRIACAO;
        newThread->prio = prio;
        tCounter++;

        newThread->context.uc_stack.ss_sp = malloc(SIGSTKSZ);
        newThread->context.uc_stack.ss_size = SIGSTKSZ;
    }
    return newThread;
}

// -----------------------------------------------------------------------------

int createMainThread(ucontext_t MainContext)
{
    int prio = 0;
    TCB_t * mainThread = createThread(prio);

    if(mainThread != NULL)
    {
        mainThread->context = MainContext;
        mainThread->context.uc_link = NULL;
        mainThread->state = PROCST_EXEC;
        executingThread = mainThread;
        return mainThread->tid;
    }
    return RETURN_ERROR;
}

// -----------------------------------------------------------------------------

int init()
{

    int returnCode;

    readyQueue = malloc(sizeof(FILA2));
    blockedQueue = malloc(sizeof(FILA2));
    finishedQueue = malloc(sizeof(FILA2));
    readySuspendedQueue = malloc(sizeof(FILA2));
    blockedSuspendedQueue = malloc(sizeof(FILA2));

    CreateFila2(readyQueue);
    CreateFila2(blockedQueue);
    CreateFila2(finishedQueue);
    CreateFila2(readySuspendedQueue);
    CreateFila2(blockedSuspendedQueue);

    executingThread = NULL;

    createSchedulerContext();

    ucontext_t MainContext;
    returnCode = getcontext(&MainContext);

    if(returnCode == RETURN_OK)
    {
        returnCode = createMainThread(MainContext);
        has_init = 1;
        return(returnCode);
    }
    return RETURN_ERROR;

} // end method

// -----------------------------------------------------------------------------

int cidentify (char *name, int size)
{
    char id_grupo[72] = "Amanda Goveia 242259\nIsadora Oliveira 264109\nVictoria Elizabetha 261575\n";


    if (size >= 72)
    {
        strcpy(name, id_grupo);
        return RETURN_OK;
    } // end if

    return RETURN_ERROR;
} // end method

// -----------------------------------------------------------------------------

int ccreate (void *(*start)(void *), void *arg, int prio)
{

    if(!has_init){
        init();
    }

    TCB_t *newThread = malloc(sizeof(TCB_t));

    newThread->tid = tCounter;
    newThread->state = PROCST_CRIACAO;
    newThread->prio = prio;
    tCounter++;

    getcontext(&newThread->context);

    newThread->context.uc_link = &SchedulerContext;
    newThread->context.uc_stack.ss_sp = malloc(SIGSTKSZ);
    newThread->context.uc_stack.ss_size = SIGSTKSZ;

    makecontext(&newThread->context, (void (*)(void)) start, 1, arg);
    newThread->state = PROCST_APTO;


    if(AppendFila2(readyQueue, (void *) newThread) != 0)
    {
        printf("Erro ao criar thread %d\n", newThread->tid);
        return RETURN_ERROR;
    }

    return newThread->tid;

} // end method

int cjoin(int tid)
{

    return 0;

}

// -----------------------------------------------------------------------------
int searchThread(int tid, PFILA2 queue)
{
    TCB_t *thread;
    PNODE2 current;

    if (FirstFila2(queue) != 0){

        printf("Erro ao setar para o primeiro da fila");
        return RETURN_ERROR;
    }

    do
        {
            current = (PNODE2)GetAtIteratorFila2(queue);
            thread = (TCB_t *) current->node;
            if(&thread->tid == tid)
            {
                return 1;
            }
        }
        while(NextFila2(queue) == 0);
    return 0;
}
