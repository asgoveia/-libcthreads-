#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cthread.h"
#include "../include/cdata.h"

int main(int argc, const char * argv[]){

char * name = NULL;

int i = cidentify (name, 72);

printf("%d\n", i);
printf("%s\n", name);

return 0;
}
