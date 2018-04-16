#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cthread.h"
#include "../include/cdata.h"

void* func0(void *arg) {
	printf("Eu sou a thread ID0 imprimindo %d\n", *((int *)arg));
	return;
}

int main(int argc, const char * argv[]){

char * name = (char*) malloc(sizeof(char)*72);

int a = cidentify (name, 72);

printf("%s\n", name);

int j = init();

int i;
int	id0;

	id0 = ccreate(func0, (void *)&i, 0);


return 0;
}
