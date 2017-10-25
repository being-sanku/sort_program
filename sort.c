#include "sort.h"
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
void init(sort *s){
	s->head = NULL;
	s->tail = NULL;
	s->count = 0;
}
void sort1(sort *s) {
	node *temp = s->head;
	node *temp1;
	char str[1000];
	while(temp != NULL){
		temp1 = temp->next;
		while(temp1 != NULL) {
			if(strcmp(temp->str, temp1->str) > 0){
				strcpy(str, temp->str);
				strcpy(temp->str, temp1->str);
				strcpy(temp1->str, str);
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
}
void insert(sort *s, char str[]){
	FILE *mf;
	node *temp;
	char temp1[1000];
	mf = fopen(str,"r");
	while(fscanf(mf, "%[^\n]\n", temp1) != EOF){
			temp = (node*)malloc(sizeof(node));
			temp->next = NULL;
			strcpy(temp->str, temp1);
			if(s->count == 0){
				s->head = temp;
				s->tail = temp;		
			}
			else {
				s->tail->next = temp;
				s->tail = temp;
			}
			s->count++;
		
	}
}
void numsort(sort *s){
	char str[1000];
	node *temp;
	temp = s->head;
	node *temp1;
	while(temp != NULL){
		temp1 = temp -> next;
		while(temp1 != NULL){
			if(atoi(temp->str) > atoi(temp1->str)){
				strcpy(str, temp->str);
				strcpy(temp->str, temp1->str);
				strcpy(temp1->str, str);
			}
			temp1 = temp1->next;
		}
		temp = temp -> next;
	}
	
}
sort copy(sort s){
	node *temp = s.head;
	node *temp1;	
		sort t;
		init(&t);
		t.count = 0;
		while(temp!=NULL){
			temp1 = (node*)malloc(sizeof(node));
			temp1->next = NULL;
			strcpy(temp1->str, temp->str);
			if(t.count == 0){
				t.head = temp1;
				t.tail = temp1;
			}
			else{
				t.tail->next = temp1;
				t.tail = temp1;
			
			}
			t.count++;
			temp = temp->next;	
		}
		return t;
}
void koption(sort *s,char str[]){
	int k = atoi(str);
	if(k == 0){
		printf("Field number is zero:Invalid Field Specification");
		return ;
	}
	sort t;
	t = copy(*s);
	node *temp = t.head;
	char str1[100][100];
	char *t1;
	char t2[100];
	int i = 0 ;
	int j = 0;
	int x;
	node *temp1;
	while(temp != NULL){
		if(strlen(temp->str) < k) {
			strcpy(str1[i], "");
			i++;
			temp = temp->next;
			break;
		}
		t1 = strtok(temp->str," ");
		j = 1;
		while( j < k ){
		t1 = strtok(NULL," ");
		j++;
		}
		strcpy(str1[i], t1);
		i++;
		temp = temp->next;
	}
	j = 0;
	for(j = 0; j < i; j++) {
		for(k = j + 1; k < i ; k++){
			if(strcmp(str1[j],str1[k]) > 0){
				strcpy(t2,str1[j]);
				strcpy(str1[j],str1[k]);
				strcpy(str1[k],t2);
				temp = s->head;
				for(x = 0;x < j;x++)
					temp = temp->next;
				temp1 =s->head;
				for(x = 0;x < k;x++)
					temp1 =temp1->next;
				strcpy(t2,temp->str);
				strcpy(temp->str,temp1->str);
				strcpy(temp1->str,t2);
					
			}
		} 
	}	
	/*int k = atoi(str);
	node *temp;
	char c1,c2;
	node *temp1;
	temp = s->head;
	//printf("%d\n",k);
	while(temp != NULL){
		c1 = temp->str[k];
		temp1 = temp -> next;
		while(temp1->next != NULL){
			c2 = temp1->str[k];
			printf("%c\n",c1);
			if(c1 < c2 ){
				strcpy(str,temp->str);
				strcpy(temp->str,temp1->str);
				strcpy(temp1->str,str);
			}
			temp1=temp1->next;
		}
		temp = temp -> next;
	}*/
}
void printlist(sort s){
	node *temp;
	temp = s.head;
	while(temp != NULL){
		printf("%s\n", temp->str);
		temp = temp->next;
	}
}
void reverse(sort *s) {
	int i = 0;
	node *temp = s->head;
	node *prev;
	node *next = s->tail;
	while(i < s->count-2){
		temp = s->head;
		while(temp ->next != next){
			prev = temp;
			temp = temp->next;
		}
		temp->next = NULL;
		s->tail->next = temp;
		s->tail = temp;
		prev->next = next;
		i++;
	}
	s->head->next = NULL;
	s->tail->next = s->head;
	s->tail = s->head;
	s->head = next;
	
	
	/*while(i < s->count){
		while(temp->next != next){
			prev = temp;
			temp = temp->next;
		}
	if(i == 0){
	s->head = s->tail;
	}	
	prev->next = s->tail;
	s->tail->next = temp;
	temp->next = NULL;
	s->tail = temp;
	i++;
	}*/		
		
}
void insert1by1(sort *s, char str[]) {
	node *temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	strcpy(temp->str, str);
	if(s->count == 0){
		s->head = temp;
		s->tail =temp;
	}
	else {
		s->tail->next = temp;
		s->tail = temp;
	}
	s->count++;	
}
void moption(sort *s){
	node *temp = s->head;
	char *t1;
	int i = 0;
	sort m[12];
	sort t,n;
	init (&t);
	t = copy(*s);
	node *temp1 = t.head;
	init(&n);
	for(i = 0; i < 12;i++){
	init(&m[i]);
	}
	while(temp1 != NULL) {
		t1 = strtok(temp1->str," ");
		for(int i = 0; t1[i]; i++){
		  t1[i] = tolower(t1[i]);
		}
			if(strcmp(t1,"jan")==0 ||  strcmp(t1,"january")==0)
				insert1by1(&m[0], temp->str);
			else if(strcmp(t1,"feb")==0 || strcmp(t1,"february")==0)
				insert1by1(&m[1], temp->str);
			else if(strcmp(t1, "mar")==0 ||strcmp(t1, "march")==0)
				insert1by1(&m[2], temp->str);
			else if(strcmp(t1,"apr")==0 || strcmp(t1,"april")==0)
				insert1by1(&m[3], temp->str);
			else if(strcmp(t1,"may")==0)
				insert1by1(&m[4], temp->str);
			else if(strcmp(t1, "jun")==0 || strcmp(t1,"june")==0)
				insert1by1(&m[5], temp->str);
			else if(strcmp(t1,"jul")==0 || strcmp(t1, "july")==0)
				insert1by1(&m[6], temp->str);
			else if(strcmp(t1,"aug")==0 || strcmp(t1,"august")==0)
				insert1by1(&m[7], temp->str);
			else if(strcmp(t1,"sept")==0 || strcmp(t1,"september")==0)
				insert1by1(&m[8], temp->str);
			else if(strcmp(t1,"oct")==0 || strcmp(t1,"october")==0)
				insert1by1(&m[9], temp->str);
			else if(strcmp(t1,"nov")==0 || strcmp(t1,"november")==0)
				insert1by1(&m[10], temp->str);
			else if(strcmp(t1,"dec")==0 || strcmp(t1,"december")==0){
				insert1by1(&m[11], temp->str);
				}
			else {
				
				insert1by1(&n, temp->str);
			}
		temp = temp->next;
		temp1 = temp1->next;
	}
	sort1(&n);
	printlist(n);
	for(i = 0;i < 12;i++){
		koption(&m[i], "2");
		printlist(m[i]);
	}
	//for(i = 1;i < 12; i++)
	//merge(&m[0], m[1]);
	//merge(&n, m[0]);
		
	//s->head = n.head;
}
void merge(sort *s, sort t){
	s->tail->next = t.head;
	s->count += t.count;
	s->tail = t.tail;
}
void destroy(sort *s){
	node *temp =  s->head;
	init(s);
	node *temp1;
	while(temp != NULL){
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	
}
void itoa(int n, char s[]){
	int i, sign;
	if ((sign = n) < 0)
		n = - n;
		i = 0 ;
		do{
		s[i++]=n%10+'0';
		
		}while((n/=10)>0);
		if(sign < 0){
			s[i++]='-';
		}
		s[i]='\0';
		//reverse(s);
}
void esort(char s1[]){
/*	typedef struct E{
		char str[1000];
		int i;
	}E;
	*/
	//E e[100];
	FILE *mf = fopen(s1, "r");
	FILE *tf[20];
	int y = 0 ;
	int flag = 0;
	estruct *e;
	estruct *h;
	estruct *t;
	estruct *etmp2;
	estruct *etmp;
	sort s;
	init(&s);
	char temp[1000];
	char filename[10];
	int i = 0 ;
	abc :
	i = 0;	
	while(i < 2000) {
		if(fscanf(mf, "%[^\n]\n", temp)!= EOF){
		insert1by1(&s, temp);	
		}
		else {
			flag = 1;
		}
	i++;	
	}
	sort1(&s);
	itoa(y,filename);
	tf[y] = fopen(strcat(filename, ".txt"),"w");	
	writetofile(&s, tf[y]);
	fclose(tf[y]);
	destroy(&s);
	y++;
	if(flag != 1)
	goto abc;
	fclose(mf);
	printf("%d",y);
	/*for(i = 0;i<y;i++){
		itoa(i,filename);
		tf[i] = fopen(strcat(filename,".txt"),"r");
		if(fscanf(mf,"%[^\n]\n",temp)!=EOF)
		strcpy(e[i].str,temp);
		e[i].i = i;	
	}*/
	mf = fopen("b.txt", "w");
	for(i = 0;i < y ;i++){
		printf("HI");
		itoa(i, filename);
		tf[i] = fopen(strcat(filename,".txt"),"r");
		e = (estruct*)malloc(sizeof(estruct));
		e->next = NULL;
		e->i = i;
		if(fscanf(tf[i],"%[^\n]\n",temp)!=EOF)
			strcpy(e->str,temp);
		printf("%s",e->str);
		if(i==0){
			h = e;
			t = e;
		}
		else{
			t->next = e;
			t = e;
		}
	}
	k:
	etmp = h;
	i = etmp->i;
	strcpy(temp,etmp->str);
	etmp2 = etmp;
	while(etmp != NULL){
		if(strcmp(temp,etmp->str) > 0){
			strcpy(temp, etmp->str);
			i = etmp->i;
			etmp2 = etmp;
		}
		etmp = etmp->next;
	}
	fprintf(mf,"%s\n",temp);
	if(fscanf(tf[i],"%[^\n]\n",temp)!=EOF)
		strcpy(etmp2->str,temp);
	else{
		fclose(tf[i]);
		itoa(i,filename);
		flag =remove(strcat(filename,".txt"));
		if(etmp2 != h) {
			etmp = h;
			while(etmp->next !=etmp2){
				etmp = etmp->next;
		}
			etmp->next = etmp2->next;
		}
		else {
			h = h->next;
			etmp = h;
		}
		y--;
		if(y == 0)
		goto end;
	}
	goto k;
	end :
		fclose(mf);
	/*strcpy(temp,e[0].str);
	flag = 0;
	for(i = 0;i<y;i++) {
		if(strcmp(temp,e[i].str) < 0){
			strcpy(temp,e[i].str);
			flag = i;
		}	
	}
	fprintf(mf,"%s\n",temp);
	if(fscanf(tf[flag],"%[^\n]\n",temp)!=EOF)
	strcpy(e[flag].str,temp);
	goto k;
	*/
	
	
}
void writetofile(sort *s,FILE *tf) {
	node *temp = s-> head;
	while(temp != NULL){
		fprintf(tf,"%s\n",temp->str);
		temp = temp->next;
	}	
}

