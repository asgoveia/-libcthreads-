#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cthread.h"
#include "../include/cdata.h"

void* func0(void *arg) {
	printf("Eu sou a thread ID0 imprimindo %d\n", *((int *)arg));
	return;
}

void* func1(void *arg) {
	printf("Eu sou a thread ID1 imprimindo %d\n", *((int *)arg));
}

int main(int argc, const char * argv[]){

char * name = (char*) malloc(sizeof(char)*72);

cidentify (name, 72);

printf("%s\n", name);


int i =2;
int	id0, id1;

	id0 = ccreate(func0, (void *)&i, 0);
	id1 = ccreate(func1, (void *)&i, 0);

	printf("Eu sou a main após a criação de ID0 e ID1\n");

	cjoin(id0);
	cjoin(id1);


return 0;
}
