#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
typedef struct node {
	char str[1000];
	struct node *next;
}node;
typedef struct sort{
	node  *head;
	node *tail;
	int count;
}sort;
typedef struct estruct{
	char str[1000];
	int i;
	struct estruct *next;
}estruct;
estruct *h;
void insert(sort *s,char str[]);
void init(sort *s);
void numsort(sort *s);//NUMERIC SORT
void dictsort(sort *s);//dictionary sort;
void koption(sort *s,char str[10]);
void printlist(sort s);
sort copy(sort s);
void reverse(sort *s);
void merge(sort *s, sort t);
void moption(sort *s);
void sort1(sort *s);
void ignorecase(sort *s);
void esort(char s[]);
void writetofile(sort *s,FILE *tf);
void insert1by1(sort *s,char s1[]);
