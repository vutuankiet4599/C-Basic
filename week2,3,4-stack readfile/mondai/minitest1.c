#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct sinhvien
{
	char name[30];
	char mssv[8];
}SV;
typedef struct listsinhvien
{
	char name[30];
	char mssv[8];
	struct listsinhvien *next;
}lSV;
//Doc thong tin tu ban phim
void readFormKeyborad(SV **sv,int *index)
{
	int n;
	printf("So luong sinh vien can nhap: ");
	scanf("%d",&n);
	int i;
	SV *data;
	data = (SV*)malloc(sizeof(SV)*n);
	for(i=0;i<n;i++)
	{
		printf("Thong tin sinh vien thu %d\n",i+1);
		printf("Ho ten: ");
		fflush(stdin);
		gets(data[i].name);
		printf("Ma so sinh vien: ");
		gets(data[i].mssv);
	}
	*sv=data;
	*index=n;
}
//Ghi thong tin vao file nhi phan
void writetoFile(SV *sv, int index,char *filename)
{
	FILE *fptr = fopen(filename,"wb+");  //Neu file khong co thi tao file moi
	printf("So phan tu ghi vao file la: %d\n",index);
	fwrite(&index,sizeof(int),1,fptr);
	fwrite(sv,sizeof(SV),index,fptr);
	fclose(fptr);
}
//Doc thong tin ra tu file nhi phan
int readFormFile(SV **sv,char *filename)
{
	FILE *fptr = fopen(filename,"rb+");
	int n;
	fread(&n,sizeof(int),1,fptr);
	if(n<=0)
	{
		printf("File %d la file rong\n",filename);
		return 0;
	}
	SV *data = (SV*)malloc(sizeof(SV)*n);
	fread(data,sizeof(SV),n,fptr);
	*sv=data;
	fclose(fptr);
	return 1;
}
//Luu thong tin vao danh sach lien ket don
void insertFirst(lSV **head,SV *data1)
{
	int i;
	lSV *pNew;
	pNew=(lSV*)malloc(sizeof(lSV));
	strcpy(pNew->name,data1->name);
	strcpy(pNew->mssv,data1->mssv);
	pNew->next=*head;
	*head=pNew;
}

//In ra man hinh
void print(lSV *list,int index)
{
	printf("=====================================================================\n");
	lSV *p=list;
	printf("So sinh vien duoc in ra: %d\n",index);
	while(NULL!=p)
	{
		printf("Ho va ten: %30s || Ma so sinh vien : %s\n",p->name,p->mssv);
		p=p->next;
	}
	printf("=====================================================================\n");
}
//Tim kiem theo ten sinh vien
void search(lSV *list)
{
	char str[80];
	lSV *p = list;
	printf("Nhap string: ");
	gets(str);
	while(NULL!=p)
	{
		if(strstr(p->name,str)!=NULL)
		printf("Ho va ten: %30s || Ma so sinh vien : %s\n",p->name,p->mssv);
		p=p->next;
	}
}
//xoa phan tu dau cua danh sach lien ket
void removeFirst(lSV **list)
{
	*list=(*list)->next;
}
void removeAt(lSV **list,int n)
{
	int i;
	lSV *p =*list;
	for(i=1;i<n-1;i++)
	{
	p=p->next;
    }
	p->next=(p->next)->next;
	*list=p;
}
int main()
{
	SV *sv1,*sv2;
	lSV *list=NULL;
	int index,i;
	readFormKeyborad(&sv1,&index);
	writetoFile(sv1,index,"thongtin.dat");
	readFormFile(&sv2,"thongtin.dat");
	for(i=0;i<index;i++)
	{
		insertFirst(&list,sv2+i); 
	}
	removeAt(&list,2);
	print(list,index);
	return 0;
}

