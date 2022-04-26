#include "queuelinkedlist.h"
#include "datatypes.h"
#include <stdio.h>

int count;
QNODE *front, *rear;
//khoi tao queue rong
void initQueue()
{
	front = NULL;
	rear = NULL;
	count=0;
}

int isEmpty()
{
	return count==0; 
}

int size()
{
	return count;
}
//tuong duong voi chen phan tu vao cuoi danh sach lien ket don
void enqueue(SV data)
{
	QNODE *pNew=(QNODE*)malloc(sizeof(QNODE));
	pNew->data=data;
	pNew->next=NULL;
	if(count==0)//hang doi dang rong
	{
		front=pNew;
		rear =pNew;
	}
	else//hang doi khac rong
	{
		rear->next=pNew;
		rear=pNew;
	}
	count++;
}
//Tuong duong removeFirst
SV dequeue()
{
	SV retval = front->data;
	QNODE *p= front->next;
	if(count==1)//chi co 1 phan tu,sau khi xoa thanh cong
	{
		front=NULL;
		rear=NULL;
	}
	else
	{
		front = front->next;
	}
	count--;
	free(p);//do cap phat pahn tu dong;
	return retval;
}
