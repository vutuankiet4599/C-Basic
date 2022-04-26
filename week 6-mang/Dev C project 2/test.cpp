#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

int main()
{
	DB * listSV;
    int size;
    //readFromKeyboard(&listSV,&size);
    //writetoFile ("output.dat", listSV, size);
    readFromFileBinary("contactList.dat", &listSV, &size);
    printAllList(listSV, size);
    
    char name[20],sdt[20];
    printf("SDT can tim: ");
    //clear();
    gets(sdt);
    DB * result = seqSearchbyPhone(sdt,listSV,size);
    if(result==NULL)
    	printf("Khong co SDT can tim trong danh ba!\n");
    else
    	printf("Thong tin tim duoc : %s %s %s %s\n",result->hoten, 
		result->sdt, result->email, result->zalo);
    return 0;

}
