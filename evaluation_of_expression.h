#ifndef EVALUATATION_OF_EXPRESSON
#define EVALUATATION_OF_EXPRESSON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//postFix : prefix���� ��ȯ�� postfix ���ڿ��� ����Ǵ� �ּ� 
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
    	//������ ���	
        if('0'<=str[i] && str[i]<='9'){
        	// �ڿ� ���ڰ� �� �ִ� ���(2���ڸ� �̻�) 
        	while('0'<=str[i+1] && str[i+1]<='9'){
        		num_of_char++;
        		i++;
        	};
        	// ���� ���ڿ��� ����� tmp �� ���� ���ڿ��� ���� 
			strncpy(tmp, str+start_index,num_of_char);
			// ������ �޸� ������ null���� ���� 
			tmp[num_of_char] = '\0';
			
			strcat(postFix, tmp);
			strcat(postFix, " ");
			
			printf("%d", atoi(tmp));
        }
        //�������� ���  
        else{
        	// ������ �ڸ� ���� 1�̻��� AND �Ǵ� OR�� ���. 
			while('0'> str[i+1] || str[i+1] > '9'){
				// �׷��� )* �� ���� ���� ������ �ϳ��̹Ƿ� ���� ó��.
				// �� �ϳ��� ���� �ȵ� 
        		if(str[i+1] == '*' || str[i+1] == '/' || str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '(' || str[i+1] == ')')break;
        		
        		num_of_char++;
        		i++;
        	};
			strncpy(tmp, str+start_index,num_of_char);
			
        	tmp[num_of_char] = '\0';
        	while(!isEmpty(stack) && stack[top].precedence >= get_precedence(tmp)){
        		
        		printf("%s", stack[top].oper);
        		
        		strcat(postFix, stack[top].oper);
				strcat(postFix, " ");
				
        		Pop(&top);
			}
			strcpy(newElement.oper,tmp);
			newElement.precedence = get_precedence(tmp);
			Push(&top, newElement);
        	}
	}
    while(!isEmpty(stack)){
    	printf("%s", stack[top].oper);
    	
		strcat(postFix, stack[top].oper);
		strcat(postFix, " ");
		
    	Pop(&top);
	}
	return postFix;	
}


#endif
