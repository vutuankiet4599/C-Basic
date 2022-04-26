#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
QE *front, *rear;
int count = 0;
void initQueue()
{
	count =0;
	front = NULL;
	rear = NULL;
}
int isEmpty()
{
	return count == 0;
}
void enqueue(TN *node)
{
	QE *pNew = (QE*)malloc(sizeof(QE));
	pNew->data=node;
	pNew->next=NULL;
	if(count==0)
	{
		front = pNew;
		rear = pNew;
	}
	else//hang doi khac rong-->chi can cap nhat con tro cuoi hang
	{
		rear->next=pNew;
		rear = rear->next;
	}
	count ++;
}
TN *dequeue()
{
	TN *retval = front->data;
	QE *p=front;
	if (count == 1)
	{
		front=NULL;
		rear=NULL;
	}
	else
	{
		front = front->next;
	}
	count --;
	free (p);
	return retval;
}
