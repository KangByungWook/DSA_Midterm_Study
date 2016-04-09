#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Linked_list.h"
#include "factorial.h"
#include "binary_search.h"
#include "permutation.h"
#include "evaluation_of_expression.h"
#include "stack.h"

int main(){
	char str[100];
	scanf("%s", str);
	evaluate(str);
//	char tmp = '+';
//	printf("%d",get_precedence(&tmp));
	
    return 0;
}
