
#include <stdio.h>
#include <stdlib.h>
#include "contact.h"
#include "datatypes.h"

int main()
{
	DB * listSV;
    int size;
    //readFromKeyboard(&listSV,&size);
    //writetoFile ("output.dat", listSV, size);
    readFromFileBinary("contactList.dat", &listSV, &size);
    printAllList(listSV, size);
    
    /*
    char name[20],sdt[20];
    printf("SDT can tim: ");
    //clear();
    gets(name);
    DB * result = seqSearchbyNameNoCase(name,listSV,size);
    if(result==NULL)
    	printf("Khong co ten can tim trong danh ba!\n");
    else
    	printf("Thong tin tim duoc : %s %s %s %s\n",result->hoten, 
		result->sdt, result->email, result->zalo);
    */
    /*
	printf("Nhap them danh ba:\n");
	int dem = addContactFromKeyboard(listSV,&size);
	if(dem!=0) {
		printf("Danh ba moi la:\n");
		printAllList(listSV, size);
		writetoFileBinary("contactList.dat", listSV, size);
	}*/
	char name[20];
    printf("Ten can xoa: ");
    //clear();
    gets(name);
    removeContactbyName(name,listSV, &size);
    printAllList(listSV, size);
	return 0;

}
