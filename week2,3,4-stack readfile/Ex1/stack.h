#ifndef FILE_STACK
#define FILE_STACK
#include "datatype.h"
const int MAX_LEN = 50;

void init();
int isFull();
int isEmpty();
void push(SV data);
SV pop();
#endif
