#include <stdio.h>
#include <unistd.h>
#include "sort.h"
int main (int argc, char ** argv)
{
    char i[10];
    sort s;
    init(&s);
     char str[1000];
    if(argc == 1) {
    while(scanf("%s",str)!=-1){
    	insert1by1(&s,str);
    	
    }
    sort1(&s);
    	printlist(s);
    }
    else{
    insert(&s, argv[2]);
 	printf("%s",argv[1]);
    while (1) {
        char c;
        c = getopt (argc, argv, "mkgrp");
        if (c == -1) {
            break;
        }
        switch (c) {
        case 'M': moption(&s);
            break;
        case 'k':
        	scanf("%s", i);
        	koption(&s, i);
            break;
        case 'g': numsort(&s);
        	break;
        case 'r': reverse(&s);
       		break;
     	case 'p': printlist(s);
     		break;
        default:
        	
            printf ("Usage: %s [-a] [-b <something>].\n", argv[0]);
        }
    }
}
    argc -= optind;
    argv += optind;

    	
    return 0;
}
