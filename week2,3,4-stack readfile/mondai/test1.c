#include <string.h>
#include <stdio.h>
#include<stdlib.h>
typedef struct Sinhvien
{
	char hoten[80];
	char mssv[80];
}SV;
//Nhap thong tin sinh vien tu ban phim.
//Viet thong tin sinh vien vua nhap vao file nhi phan roi in ra man hinh.
//Doc thong tin tu file nhi phan va in ra.
/*
void insert(SV **listSV,int *n)
{
	int pn,i;
	SV *p;
	printf("Nhap so sinh vien can nhap: ");
	scanf("%d",&pn);
	p = (SV*)malloc(sizeof(SV)*pn);
	for(i=0;i<pn;i++)
	{
		fflush(stdin);
		printf("Nhap ten sinh vien: ");
		gets(p[i].hoten);
		printf("Nhap ma so sinh vien: ");
		gets(p[i].mssv);
	}
	*listSV=p;
	*n=pn;
}
void writetoFILE(char *filename, SV *listSV, int n)
{
	FILE *fptr = fopen(filename,"wb+");
	fwrite(&n,sizeof(int),1,fptr);
	fwrite(listSV,sizeof(SV),n,fptr);
	fclose(fptr);
}
int readformFILE(char *filename, SV **listSV, int *n)
{
	int pn;
	SV *retval;
	FILE *fptr;
	fptr = fopen (filename, "rb");
	fread(&pn,sizeof(int),1,fptr);
	retval = (SV*) malloc(sizeof(SV)*pn);
	fread(retval,sizeof(SV),pn,fptr);
	*n=pn;
	*listSV=retval;
	fclose(fptr);
	return 1;
}
void print1(SV *listSV, int n)
{
	int i;
	printf("============================================\n");
	printf("So luong sinh vien in ra: %d\n",n);
	for(i=0;i<n;i++)
	{
		printf("Ho ten: %40s || Ma so sinh vien: %s\n",listSV[i].hoten,listSV[i].mssv);
	}
	printf("============================================\n");
}
void print2(SV *listSV, int n)
{
	int i;
	printf("============================================\n");
	printf("In thong tin sinh vien doc tu file\n");
	for(i=0;i<n;i++)
	{
		printf("Ho ten: %40s || Ma so sinh vien: %s\n",listSV[i].hoten,listSV[i].mssv);
	}
	printf("============================================\n");
}
int main1()
{
	SV *sv1,*sv2;
	int n;
	insert(&sv1,&n);
	writetoFILE("output.dat",sv1,n);
	//readformFILE("output.dat",&sv2,&n);
	//print1(sv1,n);
	//print2(sv2,n-1);
	return 0;
}
*/


//danh sach lien ket don
typedef struct sinhvien
{
	char hoten[80];
	char mssv[80];
	struct sinhvien *next;
}sv;
//nhap thong tinh danh sach sinh vien
/*
void insert(sv **lsv,int *n)
{
	int pn,i;
	sv *p;
	printf("Nhap so sinh vien can nhap: ");
	scanf("%d",&pn);
	p = (sv*)malloc(sizeof(sv)*pn);
	for(i=0;i<pn;i++)
	{
		fflush(stdin);
		printf("Nhap ten sinh vien: ");
		gets(p[i].hoten);
		printf("Nhap ma so sinh vien: ");
		gets(p[i].mssv);
	}
	*lsv=p;
	*n=pn;
}
*/

//chen thong tin vao dau
void insertFirst(sv **head)
{
	sv *pNew = (sv*)malloc(sizeof(sv));
	printf("Nhap thong tin sinh vien moi:\n");
	fflush(stdin);
	printf("Ho ten: ");
	gets(pNew->hoten);
	printf("Ma so sinh vien: ");
	gets(pNew->mssv);
	pNew->next=*head;
	*head=pNew;
}
//chen thong tin vao dau
void insertFirst2(sv **head, SV* data)
{
    sv *pNew = (sv *)malloc(sizeof(sv));
    strcpy(pNew->hoten, data->hoten);
    strcpy(pNew->mssv, data->mssv);
    // gan phan tu moi vao dau danh sach
    pNew->next = *head;
    *head = pNew;
}

//chen thong tin vao phan tu thu i trong danh sach lien ket
void insertAt(sv *head, int index)
{
	sv *pPre = head;
	int i;
	sv *pNew = (sv*)malloc(sizeof(sv)*1);
	printf("Nhap thong tin sinh vien moi:\n");
	fflush(stdin);
	printf("Ho ten: ");
	gets(pNew->hoten);
	printf("Ma so sinh vien: ");
	gets(pNew->mssv);
	for(i=1;i<index;i++)
	pPre=pPre->next;
	pNew->next=pPre->next;
	pPre->next=pNew;
}
//in ra man hinh
void print(sv *lsv)
{
	sv *p=lsv;
	printf("============================================\n");
	while (NULL!=p)
	{
		printf("Ho ten: %s || Ma so sinh vien: %s\n",p->hoten,p->mssv);
        p=p->next;
	}
	printf("============================================\n");
}

//doc tu file binary
void readFormFile(char *filename,sv**sv1)
{
	FILE *fptr = fopen(filename,"rb");
	int i=0,n;
	fread(&n,sizeof(int),1,fptr);
	SV *sv11 = (SV*)malloc(sizeof(SV));
	sv *sinhvien=NULL;
	for(i=0;i<n;i++)
	{
	    fread(sv11,sizeof(SV),1,fptr);
	    insertFirst2(&sinhvien,sv11);
	}
	*sv1=sinhvien;
	fclose(fptr);
}
void main()
{
	sv *sv1=NULL;
	//insertFirst(&sv1);
	//print(sv1);
	//insertAt(sv1,1);
	readFormFile("output.dat",&sv1);
	print(sv1);
}

