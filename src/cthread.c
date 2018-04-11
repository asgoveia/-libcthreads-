#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cthread.h"
#include "../include/cdata.h"

FILA2 readyQueue;
FILA2 blockedQueue;
FILA2 finishedQueue;
FILA2 readySuspendedQueue;
FILA2 blockedSuspendedQueue;

TCB_t * executingThread;

// -----------------------------------------------------------------------------
int init(){}

// -----------------------------------------------------------------------------

int cidentify (char *name, int size){
	char id_grupo[72] = "Amanda Goveia 242259\nIsadora Oliveira 264109\nVictoria Elizabetha 261575\n";
	

	if (size >= 72){
		strcpy(name, id_grupo);
		return RETURN_OK;
	} // end if

	return RETURN_ERROR;
} // end method

// -----------------------------------------------------------------------------

int ccreate (void *(*start)(void *), void *arg, int prio){

	TCB_t *newThread = malloc(sizeof(TCB_t));
	
	newThread->tid = 1;
	newThread->state = PROCST_CRIACAO;
	newThread->prio = prio;
	
	getcontext(&newThread->context);

	
} // end method
