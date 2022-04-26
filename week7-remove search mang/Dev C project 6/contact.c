#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

const int MAX_LEN = 255;
const int MAX_CONTACT_SIZE = 500; // toi da 500 contact

// doc vao danh sach tu ban phim
void clear (void)
{    
    int c;
    while((c = getchar()) != '\n' && c != EOF); 
}

// fullname la ten day du can tach
// name la ten tach ra (bo nho da dc cap phat)
void tachTen(const char* fullname, char *name)
{
	int idx = strlen(fullname)-1;
	while(idx>=0 && fullname[idx]!=' ') idx--;
	if(idx==-1) // ko co dau cach trong
		strcpy(name, fullname);
	else // copy phan ten tu idx+1
	{
		int j=0;
		idx++; // bat dau ky tu khong phai cach trong
		for(;idx<strlen(fullname);idx++)
		{
			name[j]=fullname[idx];
			j++;
		}
		name[j] = '\0';
	}
}


int readFromKeyboard(DB ** listContact, int* nsize)
{
	DB * retval;
    int size;
    printf("Kich thuoc danh ba can nhap: ");
    scanf("%d",&size);
    clear();
    retval = (DB*) malloc(sizeof(DB)*MAX_CONTACT_SIZE);
    char buff[MAX_LEN];

    for(int i=0; i<size; i++)
    {
        printf("Hoten: ");
        gets(retval[i].hoten);
        //strcpy(retval[i].hoten,buff);
        printf("sdt: ");
        gets(retval[i].sdt);
        printf("email: ");
        gets(retval[i].email);
        printf("zalo: ");
        gets(retval[i].zalo);
        tachTen(retval[i].hoten, retval[i].ten);
    }
    *listContact = retval;
    *nsize = size;
}
// doc danh ba vao tu file TEXT
int readFromFileText(char *filename, DB ** listContact, int *size)
{
	// TODO
	return SUCCESS;
}
int readFromFileBinary(char *filename, DB ** listContact, int *nsize)
{
	int size;
    DB *retval;
    FILE *fptr;
    if ((fptr = fopen(filename, "rb")) == NULL){
		printf("Cannot open %s.\n", filename);
		return FAIL;
	}
	fread(&size, sizeof(int), 1, fptr);
    
	if(size<=0){  // danh sach rong
	    fclose(fptr); 
	    *nsize =0;
	    return SUCCESS; 
	}
	// cap phat dong mang luu danh sach phan tu
	retval = (DB*) malloc(sizeof(DB)*MAX_CONTACT_SIZE);
	fread(retval, sizeof(DB), size, fptr);
	*listContact = retval;
	*nsize = size;
	fclose(fptr);
	return SUCCESS;
}

// ghi danh ba vao file TEXT
int writetoFileText(char *filename, const DB * listSV, int size)
{
	// TODO
	return SUCCESS;
}
int writetoFileBinary(char *filename, const DB * listSV, int size)
{
    if (size == 0)
        return SUCCESS;
    FILE *fptr;
    if ((fptr = fopen(filename, "wb")) == NULL){
		printf("Cannot open %s.\n", filename);
		return FAIL;
	}
	fwrite(&size, sizeof(int), 1, fptr);
	fwrite(listSV, sizeof(DB), size, fptr);
	fclose(fptr);
	return SUCCESS;
}

void printAllList(DB *listContact, int size)
{
	printf("Danh ba hien tai: \n");
	printf("Number of contacts : %d\n", size);
    for(int i=0;i<size;i++)
    {
        printf("%d |%s|%s|%s %s %s\n",i+1,listContact[i].hoten,listContact[i].ten, 
            listContact[i].email,listContact[i].zalo,listContact[i].sdt);
    }
    printf("================================\n");

}

// tim kiem va tra ve nguoi dau tien co ten 
DB * seqSearchbyName(const char* name, DB * listContact, int size)
{
	for(int i=0;i<size; i++)
	{
		if(strstr(listContact[i].hoten,name)!=NULL)
			return &listContact[i];
	}
	return NULL; // khong thay
}

int tolower2(char c)
{
	if(c>='A' && c<='Z') c = c+32;
	return c;
}
// tim kiem va tra ve nguoi dau tien co ten 
// khon phan biet hoa/thuong
DB * seqSearchbyNameNoCase(const char* name, DB * listContact, int size)
{
	char namelower[255];
	strcpy(namelower, name);
	for(int i=0;i<strlen(namelower);i++)
		namelower[i] = tolower2(namelower[i]);
		
	for(int i=0;i<size; i++)
	{
		char hotenlower[255];
		strcpy(hotenlower, listContact[i].hoten);
		for(int i=0;i<strlen(hotenlower);i++)
			hotenlower[i] = tolower2(hotenlower[i]);
		
		if(strstr(hotenlower,namelower)!=NULL)
			return &listContact[i];
	}
	return NULL; // khong thay
}

DB * seqSearchbyPhone(const char* sdt, DB * listContact, int size)
{
	for(int i=0;i<size; i++)
	{
		if(strcmp(listContact[i].sdt,sdt)==0)
			return &listContact[i];
	}
	return NULL;
}

int addContactFromKeyboard(DB *listContact, int* nsize)
{
	
	int size = *nsize;
	if(size>=MAX_CONTACT_SIZE)
	{
		printf("Danh ba da day! Vui long xoa bot truoc khi them!\n");
		return 0;
	}
	char sdt[20];
    printf("SDT can them: ");
    gets(sdt);
    DB *check = seqSearchbyPhone(sdt,listContact,size); 
    if(check!=NULL)
    {
    	printf("SDT %s da ton tai!\n",sdt);
    	return 0;
	}
	printf("Bo sung thong tin\n");
	strcpy(listContact[size].sdt,sdt);
	// bo sung du thong tin
	printf("Hoten: ");
    gets(listContact[size].hoten);
        //strcpy(retval[i].hoten,buff);
    printf("email: ");
    gets(listContact[size].email);
    printf("zalo: ");
    gets(listContact[size].zalo); 
    tachTen(listContact[size].hoten, listContact[size].ten);
    *nsize = size+1;
    return 1;
}

void removeContactbyName(const char* name, DB * listContact, int *size)
{
	// tim toi phan tu co ten chua phan cua ten
	int idx;
	for(idx=0; idx<*size; idx++)
		if(strstr(listContact[idx].hoten,name)!=NULL) break;
	if(idx>=*size)//ko co phan tu nao se bi xoa
		return;
	DB tmp = listContact[*size-1];
	listContact[*size-1] = listContact[idx];
	listContact[idx] = tmp;
	(*size)--;
}

void sortContactList_BubbleSort(DB * listContact, int size)
{
	for(int i=size;i>1;i--)
		for(int j=1;j<i;j++)
		if(strcmp(listContact[j-1].ten,listContact[j].ten)>0)
		{
			DB tmp = listContact[j-1];
			listContact[j-1]=listContact[j];
			listContact[j]=tmp;			
		}
}

// start=0 va end = size-1
DB * binSearchbyName(const char* name, DB * listContact, int start, int end)
{
	if(start>end) return NULL;
	int mid = (start + end)/2;
	if(strcmp(listContact[mid].ten, name)==0) return &listContact[mid];
	if(strcmp(listContact[mid].ten, name)<0) 
		return binSearchbyName(name,listContact,mid+1,end);
	else 
		return binSearchbyName(name,listContact,start,mid-1);
}
