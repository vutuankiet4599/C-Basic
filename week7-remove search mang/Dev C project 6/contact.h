#ifndef FILE_CONTACT_HEADER
#define FILE_CONTACT_HEADER
#include "datatypes.h"

int readFromKeyboard(DB ** listContact, int* nsize);
int readFromFileText(char *filename, DB ** listContact, int *size);
int readFromFileBinary(char *filename, DB ** listContact, int *size);
int writetoFileText (char *filename, const DB * listContact, int size);
int writetoFileBinary(char *filename, const DB * listContact, int size);
void printAllList(DB *listContact, int size);
DB * seqSearchbyName(const char* name, DB * listContact, int size);
DB * seqSearchbyNameNoCase(const char* name, DB * listContact, int size);
DB * seqSearchbyPhone(const char* sdt, DB * listContact, int size);
// tim kiem nhi phan tu 0 toi size-1
DB * binSearchbyName(const char* name, DB * listContact, int start, int end);
//DB * binSearchbyPhone(const char* name, DB * listContact, int start, int end);

// mang listContact da co, nen khong can thay doi --> con tro *
int addContactFromKeyboard(DB *listContact, int* nsize);
// tim va xoa phan tu co ten 
void removeContactbyName(const char* name, DB * listContact, int *size);

// sap xep danh ba truoc khi thuc hien tim kiem
void sortContactList_BubbleSort(DB * listContact, int size);

#endif
