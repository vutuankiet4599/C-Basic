#ifndef FILE_DATA_TYPE
#define FILE_DATA_TYPE
enum {SUCCESS, FAIL};

typedef struct DANHBADIENTHOAI
{
  char hoten[50];
  char ten[50]; // de tim kiem theo ten
  char sdt[20];
  char email[255];
  char zalo[25];
} DB;
#endif
