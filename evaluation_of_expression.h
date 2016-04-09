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
			printf("��ȿ���� ���� �������Դϴ�\n");
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
    	//������ ���	
        if('0'<=str[i] && str[i]<='9'){
        	// �ڿ� ���ڰ� �� �ִ� ���(2���ڸ� �̻�) 
        	while('0'<=str[i+1] && str[i+1]<='9' && str[i+1] != '\0'){
        		num_of_char++;
        		i++;
        	};
			printf("%d�ڸ� ����\n", num_of_char);
        	strncpy(tmp, str+start_index,num_of_char);
        	tmp[num_of_char] = '\0';
        	printf("���� �ν� : %d\n", atoi(tmp));
        }
        //�������� ���  
//        else{
//        	while(('0'> str[i+1] || str[i+1] > '9') && str[i+1] != '\0'){
//        		num_of_char++;
//        	};
//			printf("%d�ڸ� ������\n", num_of_char);
//        	strncpy(tmp, str+start_index,num_of_char);
//        	tmp[num_of_char] = '\0';
//        	printf("������ �ν� : %s\n", tmp);
//		}
	}
    
}

#endif
