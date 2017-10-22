#include "sort.h"
#include <stdio.h>
int main(int argc,char *argv[]){
	sort s;
	init(&s);
	insert(&s,argv[1]);
	//printlist(s);
	//numsort(&s);
	koption(&s,"3");
	printlist(s);
	return 0;
}
