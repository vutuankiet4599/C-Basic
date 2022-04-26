#include "contact.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const int MAX_LEN  = 100;

void clear (void)
{    
    int c;
    while((c = getchar()) != '\n' && c != EOF); 
}
void insertFirst(INFO **head, INFO *data)
{
	INFO *p = (INFO*)malloc(sizeof(INFO));
	strcpy(p->email,data->email);
	strcpy(p->ghichu,data->ghichu);
	strcpy(p->hoten,data->hoten);
	strcpy(p->sdt,data->sdt);
	p->next = *head;
	*head=p;
}

void readFromTextFile(INFOLIST *infoList, const char* filename)
{
	FILE *fptr;
	int i;
	INFO *head=NULL;
	INFO data;
	
	if ((fptr = fopen(filename, "r")) == NULL){
		printf("Cannot open %s.\n", filename);
		return;
	} 
	
	strcpy(infoList->filename,filename);
	fscanf(fptr,"%d",&infoList->size,1);
	fgetc(fptr);
	
	// lap va doc vao noi dung tung truong trong contact
	// cap phat dong va gan vao infoList->list (gan vao dau cho don gian)
	
	for(i=0;i<infoList->size;i++)
	{
		fgets(data.sdt,255,fptr);
		if(data.sdt[strlen(data.sdt)-1]=='\n')
		data.sdt[strlen(data.sdt)-1]='\0';
		
		fgets(data.hoten,255,fptr);
		if(data.hoten[strlen(data.hoten)-1]=='\n')
		data.hoten[strlen(data.hoten)-1]='\0';
		
		fgets(data.email,255,fptr);
		if(data.email[strlen(data.email)-1]=='\n')
		data.email[strlen(data.email)-1]='\0';
		
		fgets(data.ghichu,255,fptr);
		if(data.ghichu[strlen(data.ghichu)-1]='\n')
		data.ghichu[strlen(data.ghichu)-1]='\0';
		
		insertFirst(&head,&data);
	}
	infoList->list=head;
    fclose(fptr);
    return ;
}
void printContactList(INFOLIST contactList)
{
	INFOLIST *p=&contactList;
	//char name[255];
	//strcpy(name,p->filename);
	printf("=========================\n");
    printf("So Contact trong danh ba %s la:%d\n",p->filename,p->size);
	while(NULL!=p->list)
	{
		printf("%s\n",((p->list)->sdt));
		printf("%s\n",((p->list)->hoten));
		printf("%s\n",((p->list)->email));
		printf("%s\n",((p->list)->ghichu));
		p->list=(p->list)->next;
	}
	printf("=========================\n");
}
INFO* searchbyFullNameCASEsensitive(INFOLIST contactList, const char* name)
{
	INFOLIST *p = &contactList;
	while (NULL != p->list)
    {
    	//p->list->hoten[strlen(p->list->hoten)-1]='\0';
        if (strcmp(p->list->hoten, name) == 0)
        {
            return p->list;
        }else
        p->list = p->list->next;
    }
	return NULL;
}
INFO* searchbyFullNamenoCASE(INFOLIST contactList, const char* name)
{
	INFOLIST *p = &contactList;
	char namelower[100],hotenlower[100];
	strcpy(namelower,name);
	int i;
	for (i=0;i<strlen(namelower);i++)
	{
		namelower[i]=tolower(namelower[i]);
	}
	while (NULL != p->list)
    {
    	strcpy(hotenlower,p->list->hoten);
    	for (i=0;i<strlen(hotenlower);i++)
	{
		hotenlower[i]=tolower(hotenlower[i]);
	}
	
        if (strcmp(hotenlower, namelower) == 0)
        {
            return p->list;
        }else
        p->list = p->list->next;
    }
	return NULL;
}
INFO* searchbyPartofName(INFOLIST contactList, const char* partofname)
{
	INFOLIST *p = &contactList;
	INFO *head=NULL;
	INFO *data;
	char namelower[100],hotenlower[100];
	strcpy(namelower,partofname);
	int i;
	for (i=0;i<strlen(namelower);i++)
	{
		namelower[i]=tolower(namelower[i]);
	}
	while (NULL != p->list)
    {
    	strcpy(hotenlower,p->list->hoten);
    	for (i=0;i<strlen(hotenlower);i++)
	{
		hotenlower[i]=tolower(hotenlower[i]);
	}
	
        if (strstr(hotenlower, namelower) != NULL)
        {
            data=p->list;
            insertFirst(&head,data);
        }
    p->list = p->list->next;
    }
	return head;
}

INFO* searchbyphone(INFOLIST contactList, const char* phone)
{
	while(NULL!=contactList.list)
	{
		if(strcmp(contactList.list->sdt,phone)!=0)
		{
			contactList.list=contactList.list->next;
		}else
		{
			return contactList.list;
		}
	}
	return NULL;
}
void removeContact(INFOLIST *contactList, INFO* pContact)
{
	if(NULL==pContact||NULL==contactList->list)return;
	INFO *p=contactList->list;
	if(pContact==contactList->list)
	{
		contactList->list=contactList->list->next;
		contactList->size--;
		free(pContact);
		return;
	}
	while (p->next != pContact)
    p = p->next;
    p->next = pContact->next;
    contactList->size--;
    free(pContact);
}
void addNewContactFromKeyboard(INFOLIST *contactList)
{
	INFO *p = (INFO*)malloc(sizeof(INFO));
	INFO *test=contactList->list;
	INFO *test1=contactList->list;
	printf("Nhap so dien thoai va kiem tra co trung hay khong:\n");
	gets(p->sdt);
	while(NULL!=test)
	{
		if(NULL!=strstr(test->sdt,p->sdt))
		{
			printf("Da ton tai sdt!\n");
			free(p);
			return;
		}else
		{
			test=test->next;
		}
	}
	printf("Nhap ten: ");
	gets(p->hoten);
	printf("Nhap email: ");
	gets(p->email);
	printf("Nhap ghi chu: ");
	gets(p->ghichu);
	p->next=contactList->list;
	contactList->list=p;
	contactList->size++;
	printf("Nhap vao thanh cong!\n");
}
int checkMobilephone(const char* sdt)
{
	char p[20];
	strcpy(p,sdt);
	if(strlen(sdt)!=10)
	{
		printf("SDT %s khong hop le!\n",sdt);
		return 0;
	}
	int i;
	if(p[0]!='0')
	{
		printf("SDT %s khong hop le!\n",sdt);
		return 0;
	}
	for(i=0;i<10;i++)
	{
		if('0'>p[i]||p[i]>'9')
		{
			printf("SDT %s khong hop le!\n",sdt);
		    return 0;
		}
	}
	printf("SDT %s la hop le\n",sdt);
	return 1;
}
void savecontactListToFile(INFOLIST contactList,const char* filename)
{
	FILE *fptr = fopen(filename,"w+");//neu khong co thi tao mot file;
	fprintf(fptr,"%d\n",contactList.size);
	while(NULL!=contactList.list)
	{
		fprintf(fptr,"%s\n",contactList.list->sdt);
		fprintf(fptr,"%s\n",contactList.list->hoten);
		fprintf(fptr,"%s\n",contactList.list->email);
		fprintf(fptr,"%s\n",contactList.list->ghichu);
		contactList.list=contactList.list->next;
	}
	fclose(fptr);
}
void mergeContactList(INFOLIST *contactList1, INFOLIST *contactList2)
{
	INFO *p,*p1;
	p1=contactList2->list;
	int i,count;
	while(NULL!=p1)
	{
		p=contactList1->list;
		count=0;
		for(i=0;i<contactList1->size;i++)
		{
			if(strcmp(p->sdt,p1->sdt)!=0)count++;
			p=p->next;
		}
		if(count==contactList1->size)
		{
		    insertFirst(&contactList1->list,p1);
		    contactList1->size++;	
		}
		p1=p1->next;
	}
}
