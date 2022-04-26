#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
void swap(double *list, int i, int j)
{
	double tmp = list[i];
	list[i]=list[j];
	list[j]=tmp;
}
void bubbleSort(double *list,int size)
{
	int i,j;
	for(i=size;i>=2;i--)
		for(j=0;j<i;j++)
			if(list[j-1]>list[j])
				swap(list,j-1,j);
}

void selectionSort(double *list,int size)
{
	int i,j;
	for(i=size; i>=2; i--)
	{
		int vtMax = 0;
		for(j=1; j<i; j++)
			if(list[j]>list[vtMax]) vtMax=j;
		swap(list,vtMax,i-1);	
	}
}


void quickSort(double *list, int s, int e)
{
	if(s>=e) return;
	int pivot = list[s];
	int i=s+1, j=e;
	while(j>=i)
	{
		if(list[j]<pivot)
		{
			swap(list,i,j);
			i++;
		}
		else j--;		
	}
	swap(list,j,s); // dao lai vi tri cua pivot
	
	quickSort(list,s,j-1);
	quickSort(list,j+1,e);
}

// sinh ngau nhien mang kich thuoc size
double *generateList(int size)
{
	double* list = (double*)malloc(sizeof(double)*size);
	srand(time(NULL)); //khoi tao nhan ngau nhien
	for(int i=0; i<size; i++)
		list[i] = rand();
	return list;
}

// 10 phan tu dau va 10 cuoi
void printTest(const double *list,int size, int limit)
{
	printf("front: ");
	int i;
	for(i=0;i<limit;i++)
		printf("%.2lf, ",list[i]);
	printf("\ntail: ");
	
	for(i= size-limit-1;i<size;i++)
		printf("%.2lf, ",list[i]);
	printf("\n");
}

void printAll(const double *list,int size)
{
	printf("Data:");
	for(int i=0;i<size;i++)
		printf("%.2lf, ",list[i]);
	printf("\n");
}
double *generateCopy(double *list, int size)
{
	double *copy=(double*)malloc(sizeof(double)*size);
	int i;
	for(i=0;i<size;i++)
	{
		copy[i]=list[i];
	}
	return copy;
}
int main()
{
	double *list, *list1, *list2;
	int SIZE = 1e4, LIMIT = 20;
	list= generateList(SIZE);
	//printf("Chua sap xep:\n");
	//printTest(list,SIZE,LIMIT);
	
	//bubbleSort(list,SIZE);
	//selectionSort(list,SIZE);
	//double list[]={7,3,5,9,12};
	//SIZE = 5;
	//printAll(list, SIZE);
	list1=generateCopy(list,SIZE);
	list2=generateCopy(list,SIZE);
	struct timeval start, stop;
	double secs = 0;
	


	gettimeofday(&start, NULL);

	//quickSort(list,0,SIZE-1);
	bubbleSort(list,SIZE);
	gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	printf("Bubblesort time taken %f\n",secs);
	
	gettimeofday(&start, NULL);

	selectionSort(list1,SIZE);
	gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	printf("Selectionsort time taken %f\n",secs);
	free(list1);
	
	gettimeofday(&start, NULL);

	quickSort(list2,0,SIZE-1);
	gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	printf("Quicksort time taken %f\n",secs);
	free(list2);
	//printAll(list, SIZE);
	//printTest(l1,SIZE,LIMIT);
	
	return 0;
}


