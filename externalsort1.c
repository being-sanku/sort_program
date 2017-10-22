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
int main(int argc, char *argv[]){
	FILE *mf;
	char c[1000];
	FILE *fd[10];
	char temp[100][100];
	char temp1[100];
	int i=0;
	FILE *tf;
	int e=0;
	int flag=0;
	int x=0;
	char tmp[100];
	char filename[10];
	int y;
	int pos=0;
	int var;
	int a[10];
	mf = fopen(argv[1],"r");
	abc:
	while(i<18){
	if(EOF != fscanf(mf, "%[^\n]\n", c)) {
        	strcpy(temp[i],c);
 		i++;
  	}	
  	else{
	//fclose(mf);
	e=1;
	goto xyz;
	}
	}
	xyz:
	for(x=0;x<i;x++){
		for(y=x+1;y<i;y++){
			if(strcmp(temp[x],temp[y])>0){
				strcpy(tmp,temp[x]);
				strcpy(temp[x],temp[y]);
				strcpy(temp[y],tmp);
			}
		}
	}
	
  	itoa(flag,filename);
  	tf = fopen(strcat(filename,".txt"),"w");
  	for(x=0;x<i;x++)
	{
		fprintf(tf,"%s\n",temp[x]);
	}
	flag++;
	i=0;
	fclose(tf);	
	if(e!=1){
	goto abc;
	}
	fclose(mf);
	
	
	
	for(x=0;x<flag;x++){
	itoa(x,filename);
	fd[x]=fopen(strcat(filename,".txt"),"r");
	fscanf(fd[x],"%[^\n]\n",temp[x]);
	printf("%s\n",temp[x]);
	}
	for(x=0;x<flag;x++){
	fscanf(fd[x],"%[^\n]\n",temp[x]);
	printf("%s\n",temp[x]);
	}
	mf = fopen("file1.txt","r+");
	int q=0;
	strcpy(temp1,temp[0]);
	pos=0;
	printf("%d",flag);
	for(y=0;y<10;y++){
		a[y] = -1;
	}
	y=0;
	int z;
	int flag1 = 0;
	while(q<36){
	strcpy(temp1,temp[y]);
	var =0;
	pos=0;
	for(x=0;x<flag;x++) {
		flag1 = 0;
		for(z=0; z < 10;z++){
			if(x == a[z])
			flag1 =1;
		}
		if(flag1 != 1)
		if(strcmp(temp1,temp[x])>0){
			strcpy(temp1,temp[x]);
			printf("%s",temp1);
			pos=x;	
		}
	}
	fprintf(mf,"%s\n",temp1);
	if(fscanf(fd[pos],"%[^\n]\n",temp[pos])==EOF){
	a[y]=pos;
	y++;
	}
	printf("%s",temp[pos]);
	q++;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*strcpy(temp1,temp[0]);
	pos=0;
	pqr:
	for(x=0;x<flag;x++){
		if(strcmp(temp1,temp[x])>0){
		pos=x;
		strcpy(temp1,temp[x]);
		}
	}
	if(fscanf(fd[pos],"%s\n",temp[pos])!=EOF){
	fprintf(mf,"%s\n",temp1);
	strcpy(temp1,temp[pos]);
	goto pqr;
	}else{
	goto mno;
	}
	mno:printf("HI");
	*/
	
	return 0;
}
