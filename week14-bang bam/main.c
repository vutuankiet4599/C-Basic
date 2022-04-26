#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	DICT *myDict;
	myDict = initDict(1009);
	addWord(myDict,"hello","Xin chao ban");
	addWord(myDict,"phone","Dien thoai");
	addWord(myDict,"laptop","May tinh cam tay");
	addWord(myDict,"noel","co ong gia noel");
	char word[21];
	char *mean;
	do
	{
		printf("Tu can tra: ");
		gets(word);
		if(strcmp(word,"")==0) {
			printf("Cam on ban da dung tu dien cua chung toi!\n");
			break;
		}
		mean = lookupWord(myDict,word);
		if(NULL==mean)
			printf("Tu ban vua nhap %s KHONG dung!\n", word);
		else
			printf("%s = %s\n",word, mean);
	}
	while(1);
	
	return 0;
}
