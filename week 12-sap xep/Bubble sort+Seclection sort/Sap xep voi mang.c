#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(double *list, int i, int j)
{
	double tmp=list[i];
	list[i]=list[j];
	list[j]=tmp;
}
void bubblesort(double *list,int size)
{
	int i,j;
	for (i=size;i>=2;i--)
		for(j=0;j<i-1;j++)
			if(list[j-1]>list[j])swap(list,j-1,j);
}
//sx lua chon
void selectionSort(double *list,int size)
{
	int i,j,VTmax;
	for(i=size;i>=2;i--)
	{
		VTmax=0;
		for(j=1;j<i;j++)
		if(list[j]>list[VTmax]) VTmax=j;
		swap(list,VTmax,i-1);
	}
}

//Ham sinh mang ngau nhien
double *generateList(int size)
{
	double *list=(double*)malloc(sizeof(double)*size);
	srand(time(NULL));//khoi tao nhan ngau nhien
	int i;
	for(i=0;i<size;i++)
	list[i]=rand();
	return list;
}
//in 10 phan tu dau va 10 phan tu cuoi
void printTest(const double *list,int size, int limit)
{
	int i;
	printf("Front: ");
	for(i=0;i<limit;i++)
	printf(" %.2f ",list[i]);
	printf("\nTail: ");
	for(i=size-limit-1;i<size;i++)
	printf(" %.2f ",list[i]);
	printf("\n");
}

int main()
{
	double *l1, *l2;
	int size = 50000, limit = 10;
	l1=generateList(size);
	printf("Chua sap xep:\n");
	printTest(l1,size,limit);
	bubblesort(l1,size);
	printf("\nSap xep:\n");
    printTest(l1,size,limit);
    selectionSort(l1,size);
    printf("\nSap xep:\n");
    printTest(l1,size,limit);
    return 0;
}
