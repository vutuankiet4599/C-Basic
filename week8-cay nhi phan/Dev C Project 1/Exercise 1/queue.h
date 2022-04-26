#ifndef QUEUE_HEADER
#define QUEUE_HEADER
#include "binarytree.h"
typedef struct QUEUE
{
	TN *data;
	struct QUEUE *next;
}QE;
void initQueue();
int isEmpty();
void enqueue(TN *node);
TN *dequeue();
#endif
