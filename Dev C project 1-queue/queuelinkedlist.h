#ifndef FILE_QUEUE_HEADER
#define FILE_QUEUE_HEADER
#include "datatypes.h"
typedef struct QueueNode
{
	SV data;
	struct QueueNode *next;
}QNODE;
void initQueue();
int isEmpty();
//int isFull(); chi day khi khong the cap phat bo nho
int size();
void enqueue(SV data);
SV dequeue();
#endif
