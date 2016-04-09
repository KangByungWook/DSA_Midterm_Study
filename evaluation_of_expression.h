#ifndef EVALUATATION_OF_EXPRESSON
#define EVALUATATION_OF_EXPRESSON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int get_precedence(char *oper){
	if(!strcmp(oper, "AND") || !strcmp(oper, "OR"))return 1;
	else if(*oper == '+' || *oper == '-') return 2;
	else if(*oper == '*' || *oper == '/') return 3;
	else if(*oper == '(' || *oper == ')') return 4;
	else return -1;
}

void evaluate(char *str){
	char tmp[100];
    int num_of_char, len, i, start_index;
	len=strlen(str);
	element newElement;
    for(i=0;i<len;i++)
    {   
		start_index = i;
        num_of_char = 1; 
    	//������ ���	
        if('0'<=str[i] && str[i]<='9'){
        	// �ڿ� ���ڰ� �� �ִ� ���(2���ڸ� �̻�) 
        	while('0'<=str[i+1] && str[i+1]<='9'){
        		num_of_char++;
        		i++;
        	};
			strncpy(tmp, str+start_index,num_of_char);
        	tmp[num_of_char] = '\0';
        	printf("%d ", atoi(tmp));
        }
        //�������� ���  
        else{
        	while('0'> str[i+1] || str[i+1] > '9'){
        		num_of_char++;
        		i++;
        	};
			strncpy(tmp, str+start_index,num_of_char);
        	tmp[num_of_char] = '\0';
        	while(!isEmpty(stack) && stack[top].precedence >= get_precedence(tmp)){
        		printf("%s ", stack[top].oper);
        		Pop(&top);
			}
			strcpy(newElement.oper,tmp);
			newElement.precedence = get_precedence(tmp);
			Push(&top, newElement);
        	}
	}
    while(!isEmpty(stack)){
    	printf("%s ", stack[top].oper);
        Pop(&top);
	}
}

#endif
