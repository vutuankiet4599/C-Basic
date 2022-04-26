#ifndef HASHTABLE_HEADER
#define HASHTABLE_HEADER
typedef struct NODE
{
	char word[21];
	char mean[255];
	struct NODE *next;
} WORD;

typedef struct DICTIONARY
{
	int size;
	WORD **data;
} DICT;

// khoi tao tu dien kich thuoc size
DICT* initDict(int size);

// ham bam
int hash(char* key, int size);

// them tu vao tu dien
void addWord(DICT* dict, char* word, char *mean);

// tra cuu nghia cua tu
char *lookupWord(DICT* dict, char* word);

// xoa tu khoi tu dien
void removeWord(DICT* dict, char* word);
#endif
