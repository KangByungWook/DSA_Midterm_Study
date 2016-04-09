#ifndef EVALUATATION_OF_EXPRESSON
#define EVALUATATION_OF_EXPRESSON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//postFix : prefix에서 변환된 postfix 문자열이 저장되는 주소 
char postFix[100];
int postFixBuffIndex = 0;


int get_precedence(char *oper){
	if(!strcmp(oper, "AND") || !strcmp(oper, "OR"))return 1;
	else if(*oper == '+' || *oper == '-') return 2;
	else if(*oper == '*' || *oper == '/') return 3;
	else if(*oper == '(' || *oper == ')') return 4;
	else return -1;
}

char* prefix_to_postfix(char *str){
	char tmp[100];
    int num_of_char, len, i, start_index;
	len=strlen(str);
	element newElement;
    for(i=0;i<len;i++)
    {   
		start_index = i;
        num_of_char = 1; 
    	//숫자인 경우	
        if('0'<=str[i] && str[i]<='9'){
        	// 뒤에 숫자가 더 있는 경우(2의자리 이상) 
        	while('0'<=str[i+1] && str[i+1]<='9'){
        		num_of_char++;
        		i++;
        	};
			strncpy(tmp, str+start_index,num_of_char);
			strncpy(postFix+postFixBuffIndex, tmp, num_of_char);
			strncpy(postFix+postFixBuffIndex+1, " ", 1);
			postFixBuffIndex+=num_of_char+1;
        	tmp[num_of_char] = '\0';
        	
        	printf("%d", atoi(tmp));
        }
        //연산자인 경우  
        else{
        	while('0'> str[i+1] || str[i+1] > '9'){
        		num_of_char++;
        		i++;
        	};
			strncpy(tmp, str+start_index,num_of_char);
			
        	tmp[num_of_char] = '\0';
        	while(!isEmpty(stack) && stack[top].precedence >= get_precedence(tmp)){
        		strncpy(postFix+postFixBuffIndex, stack[top].oper, strlen(stack[top].oper));
        		// 공백 넣어주기 
        		strncpy(postFix+postFixBuffIndex+1, " ", 1);
				postFixBuffIndex+=strlen(stack[top].oper)+1;
        		printf("%s", stack[top].oper);
        		Pop(&top);
			}
			strcpy(newElement.oper,tmp);
			newElement.precedence = get_precedence(tmp);
			Push(&top, newElement);
        	}
	}
    while(!isEmpty(stack)){
    	strncpy(postFix+postFixBuffIndex, stack[top].oper, strlen(stack[top].oper));
    	// 공백 넣어주기 
    	strncpy(postFix+postFixBuffIndex+1, " ", 1);
		postFixBuffIndex+=strlen(stack[top].oper) + 1;
    	printf("%s", stack[top].oper);
    	Pop(&top);
	}
	return postFix;	
}

#endif
