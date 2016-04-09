#ifndef FACT
#define FACT

#include <stdio.h>
#include <stdlib.h>

int fact(int n){
	return (n != 1)? n*fact(n-1):n;
}

#endif
