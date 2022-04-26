#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"


// chen them phan tu moi vao vi tri sau phan tu thu i trong danh sach
// i = 1,2,...n
void insertAt(lSV* head, int index, SV* data)
{
    lSV* pPre = head;
    int i = 1;
    // chu y: can check them so luong phan tu thuc te danh sach
    while (i < index)
    {
        i++;
        pPre = pPre->next;
    }

    lSV* pNew = (lSV*)malloc(sizeof(lSV));
    pNew->data = *data;
    // gan phan tu moi vao dau danh sach
    pNew->next = pPre->next;
    pPre->next = pNew;
}

// in noi dung danh sach
void printList(lSV* head)
{
    lSV* p = head;
    int count = 0;
    printf("Noi dung danh sach:\n");
    while (NULL != p)
    {
        printf("Data: %s %s %s %s \n", (p->data).hoten, (p->data).sdt, (p->data).email, (p->data).zalo);
        p = p->next;
        count++;
    }
    printf("Total %d contacts\n", count);
    printf("\n===============================\n");
}


// doc va hien thi noi dung file ra man hinh
// listSV danh sach doc duoc
// nsize la so phan tu doc duoc
int readFromFile(const char* filename, lSV** listSV)
{
    int size;
    lSV* head = NULL;
    SV* data;
    FILE* fptr;
    fptr= fopen(filename, "rb"); 
    if (fptr == NULL) {
        printf("Cannot open %s.\n", filename);
        return FAIL;
    }
    fread(&size, sizeof(int), 1, fptr);
    printf("loading %d contacts..\n", size);

    if (size <= 0) {  // danh sach rong
        fclose(fptr);
        return SUCCESS;
    }

    // cap phat dong mang luu danh sach phan tu
    data = (SV*)malloc(sizeof(SV));
    head = (lSV*)malloc(sizeof(lSV));
    fread(data, sizeof(SV), 1, fptr);
    head->data = *data;
    head->next = NULL;

	//int i;
    for (int i = 1; i < size; i++)
    {
        fread(data, sizeof(SV), 1, fptr);
        insertAt(head, i, data);
    }
    *listSV = head;

    fclose(fptr);
    return SUCCESS;
}

// tim va in ra thong tin
void find1(lSV* listSV, const char* key)
{
    printf("\n==============================\n");
    printf("Searching for %s...\n", key);
    int dem = 0;
    lSV* p = listSV;
    while (NULL != p)
    {
        if (strstr((p->data).hoten, key) != NULL)// tim thay
        {
            // in ra thong tin
            printf("Data: %s %s %s %s \n", (p->data).hoten,
                (p->data).sdt, (p->data).email, (p->data).zalo);
            dem++;
        }
        p = p->next;
    }
    if (dem == 0)
        printf("Contact not found!\n");
    else
        printf("Found : %d\n", dem);
}


// tim va tra ve dia chi phan tu chua khoa tim kiem
// tra ve phan tu dau tien chua khoa can tim
lSV* find2(lSV* listSV, const char* key)
{
    //printf("\n==============================\n");
    //printf("Searching for %s...\n", key);
    lSV* p = listSV;
    while (NULL != p)
    {
        if (strstr((p->data).hoten, key) != NULL)// tim thay
        {
            return p;
        }
        p = p->next;
    }
    return NULL; // khong tim thay
}

// xoa phan tu dau tien trong DSLK
lSV* removeFirst1(lSV* listSV)
{
    lSV* p = listSV;
    listSV = listSV->next;
    free(p);
    return listSV; // tra ve dia chi moi cua head
}

// xoa phan tu dau tien trong DSLK
void removeFirst2(lSV** listSV)
{
    lSV* p = *listSV;
    *listSV = (*listSV)->next;
    free(p);
}

// xoa phan tu o giua/cuoi
// rContact la con tro tro toi phan tu se bi xoa o giua/cuoi
void removeAt(lSV* listSV, lSV* rcontact)
{
    lSV* preP = listSV;
    while (preP->next != rcontact)
        preP = preP->next;
    preP->next = rcontact->next;
    free(rcontact);
}

// Ham xoa phan tu theo khoa can tim
// lSV** listSV: cho truong hop neu phan tu can xoa o dau
void removeContact1(lSV** listSV, const char* key)
{
    lSV* rContact = find2(*listSV, key);
    if (rContact != NULL)
    {
        if (rContact == *listSV)// phan tu can xoa la dau tien
            removeFirst2(listSV);
        else
            removeAt(*listSV, rContact);
    }
}

// Ham xoa phan tu theo khoa can tim
// lSV** listSV: cho truong hop neu phan tu can xoa o dau
lSV* removeContact2(lSV* listSV, const char* key)
{
    lSV* rContact = find2(listSV, key);
    if (rContact != NULL)
    {
        if (rContact == listSV)// phan tu can xoa la dau tien
            listSV = removeFirst1(listSV);
        else
            removeAt(listSV, rContact);
    }
    return listSV;
}

// trong ham co lam thay doi gia tri cua con tro dau danh sach
// dau ds co the thay bang phan tu moi
lSV* sortContactList(lSV* head)
{
	if(NULL==head) return NULL;
	lSV* h2 = head->next;
	head->next = NULL;
	// lap lay tung phan tu con lai chen vao day da sap xep
	while(NULL!=h2)
	{
		lSV* p=h2;
		h2=h2->next;
		// chen p vao danh sach da sap xep tro boi head
		// TH1. Chen ngay truoc dau cu
		if(strcmp((p->data).hoten,(head->data).hoten)<0)
		{
			p->next = head;
			head = p;
		}
		else // chen vao giua hoac cuoi
		{
			lSV* p2 = head;
			while(NULL!=p2->next && 
				strcmp((p2->next->data).hoten,(p->data).hoten)<=0)
				p2=p2->next;
			{
				p->next = p2->next;
				p2->next = p;
			}			
		}
	}
	return head;
}

int main()
{
    lSV* head = NULL; // danh sach ban dau rong
    readFromFile("contactList.dat", &head);
    printList(head);
	printf("sap xep lai danh sach theo ho ten:\n");
	head=sortContactList(head);
    printList(head);   
    
    return 0;
}
