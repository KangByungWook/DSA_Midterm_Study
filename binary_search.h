#ifndef BINARY
#define BINARY

#include <stdio.h>
#include <stdlib.h>

// ����Ž�� �Ϲݹ��� 
int binarySearch(int* sortedList, int num, int targetValue){
	int left = 0, middle, right = num - 1, diff;
	while(left < right){
		middle =  (left+ right) / 2;
		diff = sortedList[middle] - targetValue;
		if(diff){
			if(diff >0){
				right = middle - 1;
			}
			else{
				left = middle + 1;
			}
		}
		else return middle;
	}
	return -1;
}
// ����Ž�� ����Լ� ����


#endif
