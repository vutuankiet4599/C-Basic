#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum {SUCCESS,FAIL};
typedef struct sinhvien
{
	char hoten[255];
	char mssv[255];
}SV;
typedef struct listsinhvien
{
	SV data;
	struct listsinhvien *next;
}LSV;
void insert(SV **sv)
{
	SV *tsv=(SV*)malloc(sizeof(SV));
	fflush(stdin);
	printf("Nhap thong tin cua sinh vien \n");
	printf("Ho ten: ");
	gets(tsv->hoten);
	printf("Ma so sinh vien: ");
	gets(tsv->mssv);
	*sv=tsv;
}
void insertFirst(LSV **sinhvien, SV *data)
{
	int i;
	LSV *head = (LSV*)malloc(sizeof(LSV));
	head->data=*data;
	head->next=*sinhvien;
	*sinhvien=head;
}
void print(LSV *sv)
{
	printf("========================\n");
	while(NULL!=sv)
	{
	    printf("Ho ten: %35s || Ma so sinh vien: %s\n",(sv->data).hoten,(sv->data).mssv);
		sv=sv->next;
	}
	printf("========================\n");
}
int search(LSV *ssvv)
{
	char s[255];
	printf("Nhap tu khoa can tim: ");
	gets(s);
	do{
		if (strstr((ssvv->data).hoten,s)!=NULL||strstr((ssvv->data).mssv,s)!=NULL)
		{
			printf("Ho ten: %35s || Ma so sinh vien: %s\n",(ssvv->data).hoten,(ssvv->data).mssv);
			return 1;
		}
		ssvv=ssvv->next;
	}while(1);
	return 0;
}

void remove1(LSV **sv)
{
	*sv=(*sv)->next;
}
int main()
{
	SV *dulieu;
	LSV *sv=NULL;
	int i;
	for(i=0;i<3;i++)
	{
	    insert(&dulieu);
		insertFirst(&sv,dulieu);
	}
	//print(sv);
	//search(sv);
	remove1(&sv);
	print(sv);
	return 0;
}
