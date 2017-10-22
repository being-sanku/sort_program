typedef struct node {
	char str[1000];
	struct node *next;
}node;
typedef struct sort{
	node  *head;
	node *tail;
	int count;
}sort;
void insert(sort *s,char str[]);
void init(sort *s);
void numsort(sort *s);//NUMERIC SORT
void dictsort(sort *s);//dictionary sort;
void koption(sort *s,char str[10]);
void printlist(sort s);
