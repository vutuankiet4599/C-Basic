#ifndef CONTACT_HEADER
#define CONTACT_HEADER

// cau truc 1 contact trong danh ba

typedef struct CONTACT
{
    char sdt[20];
    char hoten[100];
    char email[100];
    char ghichu[100];
    struct CONTACT *next;
} INFO; 
// cau truc thong tin danh ba
typedef struct CONTACTLIST
{
   INFO* list; // con tro toi dau danh dach chua cac contact
   int size; // so luong phan tu trong danh ba
   char filename[255]; // file dau vao cua danh ba
} INFOLIST;

// tao danh sach lien ket chua danh ba tu file
// cap phat dong, va tra ve dau danh sach tro boi contactList
void readFromTextFile(INFOLIST *infoList, const char* filename);
void insertFirst(INFO **head, INFO *data);

void printContactList(INFOLIST contactList);
void clear (void);
 
INFO* searchbyFullNamenoCASE(INFOLIST contactList, const char* name);
INFO* searchbyFullNameCASEsensitive(INFOLIST contactList, const char* name);

// ham tim kiem theo 1 phan cua ten, tra ve danh sach cac ten da tim thay neu co
INFO* searchbyPartofName(INFOLIST contactList, const char* partofname);
INFO* searchbyphone(INFOLIST contactList, const char* phone);
// Ham xoa 1 phan tu dang duoc tro boi pContact
void removeContact(INFOLIST *contactList, INFO* pContact);
void addNewContactFromKeyboard(INFOLIST *contactList);

// kiem tra sdt hop le
int checkMobilephone(const char* sdt);

void savecontactListToFile(INFOLIST contactList,const char* filename);

// them cac contact trong contactList2 vao contactlist1 neu khong bi trung SDT
void mergeContactList(INFOLIST *contactList1, INFOLIST *contactList2);
int checksdt(char *num1, char *num2);


#endif
