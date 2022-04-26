#include "contact.h"
#include<stdio.h>

int main()
{
	INFOLIST myContact,myContact1;
	myContact.size=0;myContact1.size=0;
	myContact.list=NULL;myContact1.list=NULL;
	int choice,i;
	char name[100],phone[100];
	INFO *p;
    /*
	readFromTextFile(&myContact,"data1.txt");
	//readFromTextFile(&myContact1,"data2.txt");
	//mergeContactList(&myContact,&myContact1);
	printContactList(myContact);
	char name[100],phone[100];
	//INFO *p=searchbyFullNameCASEsensitive(myContact,x);
    //INFO *p=searchbyFullNamenoCASE(myContact,x);
    INFO *p=searchbyPartofName(myContact,x);
	//printf("So dien thoai tim duoc la %s\n",p->sdt);
	printContactList(myContact1);
	//removeContact(&myContact,p);
	//printContactList(myContact);
	//addNewContactFromKeyboard(&myContact);
	//printContactList(myContact);
	//checkMobilephone(myContact.list->sdt);
    //savecontactListToFile(myContact,"data.txt");
	*/	
    do{
    	printf("1.Doc du lieu tu file van ban vao va luu vao trong danh sach lien ket don.\n");
    	printf("2.In ra danh ba(so luong va thong tin contact).\n");
    	printf("3.Tim kiem theo ho ten(Bai nay co 4 phan nho).\n");
    	printf("4.Tim kiem theo mot phan cua ten.\n");
    	printf("5.Ham xoa phan tu da duoc chon boi con tro\n");
    	printf("6.Them mot contact moi tu ban phim. Yeu cau check do dien thoai khong bi trung.\n");
    	printf("7.Check so dien thoai co hop le hay khong.\n");
    	printf("8.Ghi danh ba vao file data.txt.\n");
    	printf("9.Gop hai danh ba.\n");
    	printf("10.Thoat.\n");
    	printf("Choice=");
    	scanf("%d",&choice);
    	switch(choice)
		{
			case 1:
				readFromTextFile(&myContact,"data1.txt");
				readFromTextFile(&myContact1,"data2.txt");
				break;
			case 2:
				printContactList(myContact);
				printContactList(myContact1);
				break;
			case 3:
				printf("1.Tim kiem khong phan biet hoa thuong cua data1.txt.\n");
				printf("2.Tim kiem co phan biet hoa thuong cua data1.txt.\n");
				printf("3.Tim kiem khong phan biet hoa thuong cua data2.txt.\n");
				printf("4.Tim kiem co phan biet hoa thuong cua data2.txt.\n");
				scanf("%d",&i);
				clear();
				switch(i)
				{
					case 1:
						printf("Nhap ten can tim: ");
						gets(name);
						p=searchbyFullNamenoCASE(myContact,name);
						if(NULL==p)break;
						printf("Thong tin tim duoc:\n%s\n%s\n%s\n%s\n",p->sdt,p->hoten,p->email,p->email);
						break;
					case 2:
						printf("Nhap ten can tim: ");
						gets(name);
						p=searchbyFullNameCASEsensitive(myContact,name);
						if(NULL==p)break;
						printf("Thong tin tim duoc:\n%s\n%s\n%s\n%s\n",p->sdt,p->hoten,p->email,p->email);
						break;
					case 3:
						printf("Nhap ten can tim: ");
						gets(name);
						p=searchbyFullNamenoCASE(myContact1,name);
						if(NULL==p)break;
						printf("Thong tin tim duoc:\n%s\n%s\n%s\n%s\n",p->sdt,p->hoten,p->email,p->email);
						break;
					case 4:
						printf("Nhap ten can tim: ");
						gets(name);
						p=searchbyFullNameCASEsensitive(myContact1,name);
						if(NULL==p)break;
						printf("Thong tin tim duoc:\n%s\n%s\n%s\n%s\n",p->sdt,p->hoten,p->email,p->email);
						break;
				}
				break;
			case 4:
				printf("1.Tim trong data1.txt\n");
				printf("2.Tim trong data2.txt\n");
				scanf("%d",&i);
				clear();
				printf("Nhap ten can tim: ");
				gets(name);
				if(i==1)
				{
					INFO *p=searchbyPartofName(myContact,name);
					if(NULL==p)
					{
						printf("Khong tim duoc!\n");
						break;
					}
				    printf("Thong tin tim duoc:\n");
				    while(NULL!=p)
				    {
					    printf("%s  %s  %s  %s\n",p->hoten,p->sdt,p->email,p->ghichu);
					    p=p->next;
				    }
				}else if(i==2)
				{
					INFO *p=searchbyPartofName(myContact1,name);
					if(NULL==p)
					{
						printf("Khong tim duoc!\n");
						break;
					}
				    printf("Thong tin tim duoc:\n");
				    while(NULL!=p)
				    {
					    printf("%s  %s  %s  %s\n",p->hoten,p->sdt,p->email,p->ghichu);
					    p=p->next;
				    }
				}
				break;
			case 5:
				printf("1.Tim trong data1.txt\n");
				printf("2.Tim trong data2.txt\n");
				scanf("%d",&i);
				clear();
				printf("Nhap so dien thoai can tim: ");
				gets(phone);
				if(i==1)
				{
					p=searchbyphone(myContact,phone);
					removeContact(&myContact,p);
					printContactList(myContact);
				}else if(i==2)
				{
					p=searchbyphone(myContact1,phone);
					removeContact(&myContact1,p);
					printContactList(myContact1);
				}
				break;
			case 6:
				printf("1.Them vao myContact.\n");
				printf("2.Them vao myContact1.\n");
				scanf("%d",&i);
				clear();
				if (i==1)
				{
					addNewContactFromKeyboard(&myContact);
					printContactList(myContact);
				}
				else if (i==2)
				{
					addNewContactFromKeyboard(&myContact1);
					printContactList(myContact1);
				}
				break;
			case 7:
				printf("1.Danh ba trong data1.txt\n");
				printf("2.Danh ba trong data2.txt\n");
				scanf("%d",&i);
				clear();
				if (i==1)
				{
					while(NULL!=myContact.list)
					{
						checkMobilephone(myContact.list->sdt);
						myContact.list=myContact.list->next;
					}
				}else if (i==2)
				{
					while(NULL!=myContact1.list)
					{
						checkMobilephone(myContact1.list->sdt);
						myContact1.list=myContact1.list->next;
					}
				}
				break;
			case 8:
				printf("1.Danh ba trong data1.txt\n");
				printf("2.Danh ba trong data2.txt\n");
				scanf("%d",&i);
				clear();
				if (i==1)
				{
					savecontactListToFile(myContact,"data.txt");
			    }else if(i==2)
			    {
			    	savecontactListToFile(myContact1,"data.txt");
				}
				break;
			case 9:
				mergeContactList(&myContact,&myContact1);
				printContactList(myContact);
				break;
		}
	}while(choice>=1&&choice<=9);
	return 0;
}
