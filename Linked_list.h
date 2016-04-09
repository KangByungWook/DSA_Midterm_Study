#ifndef LINKED_LIST
#define LINKED_LIST

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *link;
}Node;

typedef struct LinkedList{
	int currCount;
	Node headNode;
}LinkedList;

LinkedList* createLinkedList();
int addNode(LinkedList *pList, int pos, Node node);
void deleteLinkedList(LinkedList *pList);
int removeNode(LinkedList *pList, int pos);
Node* getNode(LinkedList *pLIst, int pos);
void displayLinkedList(LinkedList *pList);

LinkedList* createLinkedList(){
	LinkedList *tmp = (LinkedList*)malloc(sizeof(LinkedList));
	if(tmp == NULL){
		printf("LinkedList를 생성하는 도중 에러 발생\n");
		return tmp;
	}
	tmp->headNode.link = NULL;
	tmp->currCount = 0;
	return tmp;
};

void deleteLinkedList(LinkedList *pList){
	if(pList == NULL){
		printf("리스트가 존재하지 않습니다");
		return; 
	}
	int i;
	Node* target;
	int num = pList->currCount;
	for(i = 0 ; i < num ; i++){
		removeNode(pList,0);
	}
	free(pList);
};

int addNode(LinkedList *pList, int pos, Node node){
	if(pList == NULL){
		printf("해당 LinkedList가 존재하지 않습니다\n");
		return FALSE;
	}
	if(pos < 0 || pos > pList->currCount){
		printf("범위를 초과하였습니다.\n");
		return FALSE;
	}
	Node *pTmpNode;
	Node *NewNode;
	NewNode = (struct Node*)malloc(sizeof(Node));
	*NewNode = node;

	pTmpNode = &(pList->headNode);
	int i;
	for(i = 0 ; i < pos ; i++){
		pTmpNode = pTmpNode->link;
	}
	NewNode->link = pTmpNode->link;
	pTmpNode->link = NewNode;
	
	pList->currCount++;
	printf("%d번째에 %d 추가\n", pos, node.data);
	return TRUE;
};

void displayLinkedList(LinkedList *pList){
	if(pList == NULL){
		printf("LinkedList가 존재하지 않습니다\n");
	}
	Node *pTmp = &(pList->headNode);
	int i;
	printf("-------------------------\n");
	printf("현재 노드의 갯수 : %d\n", pList->currCount);
	for(i = 0, pTmp = pTmp->link ; i < pList->currCount ; i++, pTmp = pTmp->link){
		printf("[%d] data : %d\n", i, pTmp->data);
	}
	printf("-------------------------\n");
}

int removeNode(LinkedList *pList, int pos){
	if(pList == NULL){
		printf("해당 LinkedList가 존재하지 않습니다\n");
		return FALSE;
	}
	if(pos < 0 || pos >= pList->currCount){
		printf("범위를 초과하였습니다.\n");
		return FALSE;
	}
	Node *pTmpNode = &(pList->headNode);
	int i;
	for(i = 0 ; i < pos ; i++){
		pTmpNode = pTmpNode->link;
	}
	Node *pTargetNode = pTmpNode->link;
	pTmpNode->link = pTargetNode->link;
	free(pTargetNode);
	pList->currCount--;
	printf("%d번째 데이터 삭제\n",pos);
	return TRUE;
}

Node* getNode(LinkedList *pList, int pos){
	if(pList == NULL){
		printf("해당 LinkedList가 존재하지 않습니다\n");
		return FALSE;
	}
	if(pos < 0 || pos >= pList->currCount){
		printf("범위를 초과하였습니다.\n");
		return FALSE;
	}
	Node *pTmpList = &(pList->headNode);
	int i;
	for(i = 0, pTmpList = pTmpList->link; i < pos ; i++,pTmpList = pTmpList->link){}
	return pTmpList;
}


#endif
