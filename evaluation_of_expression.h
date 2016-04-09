#ifndef EVALUATATION_OF_EXPRESSON
#define EVALUATATION_OF_EXPRESSON

#include <stdio.h>
#include <stdlib.h>

#define PLUS_PRECEDENCE 1

int get_precedence(char oper){
	switch(oper){
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		default:
			printf("유효하지 않은 연산자입니다\n");
			return -1;
	}
}

void evaluate(char *str){
	char tmp[100];
    int num_of_char, len, i, start_index;
	len=strlen(str);
    for(i=0;i<len;i++)
    {   
		start_index = i;
        num_of_char = 1; 
    	//숫자인 경우	
        if('0'<=str[i] && str[i]<='9'){
        	// 뒤에 숫자가 더 있는 경우(2의자리 이상) 
        	while('0'<=str[i+1] && str[i+1]<='9' && str[i+1] != '\0'){
        		num_of_char++;
        		i++;
        	};
			printf("%d자리 숫자\n", num_of_char);
        	strncpy(tmp, str+start_index,num_of_char);
        	tmp[num_of_char] = '\0';
        	printf("숫자 인식 : %d\n", atoi(tmp));
        }
        //연산자인 경우  
//        else{
//        	while(('0'> str[i+1] || str[i+1] > '9') && str[i+1] != '\0'){
//        		num_of_char++;
//        	};
//			printf("%d자리 연산자\n", num_of_char);
//        	strncpy(tmp, str+start_index,num_of_char);
//        	tmp[num_of_char] = '\0';
//        	printf("연산자 인식 : %s\n", tmp);
//		}
	}
    
}

#endif
