#ifndef PERMUTATION
#define PERMUTATION
#include <stdio.h>
#include <stdlib.h>

// 순열 재귀함수
void SWAP(char *arr, int i, int j){
	int tmp = arr[j];
	arr[j] = arr[i];
	arr[i] = tmp;
}
void perm(char *list,int i,int n) {
  int j,temp;
  if(i==n) {
    for(j=0;j<=n;j++){
    	printf("%c", list[j]);	
	}
    printf("\n");
  }
  else {
    for(j=i;j<=n;j++) {
      	SWAP(list, i , j);
	  	perm(list,i+1,n);
      	SWAP(list, i , j);
    	}	
	}
}

#endif
