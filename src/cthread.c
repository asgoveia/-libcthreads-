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

int cidentify (char *name, int size){
	char id_grupo[72] = "Amanda Goveia 242259\nIsadora Oliveira 264109\nVictoria Elizabetha 261575\n";
	

	if (size >= 72){
		strncpy(name, id_grupo, size);
printf("%s\n", name);
		return RETURN_OK;
	}

	return RETURN_ERROR;
}
