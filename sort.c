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
void init(sort *s){
	s->head = NULL;
	s->tail = NULL;
	s->count = 0;
}
void insert(sort *s, char str[]){
	FILE *mf;
	node *temp;
	char temp1[1000];
	mf = fopen(str,"r");
	while(fscanf(mf, "%[^\n]\n", temp1) != EOF){
			temp = (node*)malloc(sizeof(node));
			temp->next = NULL;
			strcpy(temp->str,temp1);
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
