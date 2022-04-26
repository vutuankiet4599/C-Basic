#include "hashtable.h"
#include <string.h>
#include <stdlib.h>

DICT* initDict(int size)
{
	DICT* newdict = (DICT*) malloc(sizeof(DICT));
	newdict->size = size;
	newdict->data = (WORD**) malloc(sizeof(WORD*)*size);
	// reset con tro dau cac dslk don ve NULL
	for(int i=0; i<size; i++)
		(newdict->data)[i]= NULL;
	
	return newdict;
}

// lay het cac ky tu trong tu lam ham bam
// tu dien = 128
int hash(char* key, int size)
{
	int hashvalue = key[0]%size;
	for(int i=1; i<strlen(key); i++)
	{
		hashvalue = (hashvalue * 128 + key[i])%size;
	}
	return hashvalue;
}

void addWord(DICT* dict, char* word, char *mean)
{
	// khi them, phai cap phat dong bo nho
	WORD *pNew = (WORD*) malloc(sizeof(WORD));
	strcpy(pNew->word, word);
	strcpy(pNew->mean, mean);
	int idx = hash(word, dict->size);
	pNew->next = (dict->data)[idx];
	(dict->data)[idx] = pNew;
}

char *lookupWord(DICT* dict, char* word)
{
	int idx = hash(word, dict->size);
	WORD* head = (dict->data)[idx];
	while(NULL!=head)
		if(strcmp(head->word,word)==0) return head->mean;
		else head=head->next;
	return NULL;
}
