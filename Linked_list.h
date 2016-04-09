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
		printf("LinkedList�� �����ϴ� ���� ���� �߻�\n");
		return tmp;
	}
	tmp->headNode.link = NULL;
	tmp->currCount = 0;
	return tmp;
};

void deleteLinkedList(LinkedList *pList){
	if(pList == NULL){
		printf("����Ʈ�� �������� �ʽ��ϴ�");
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
		printf("�ش� LinkedList�� �������� �ʽ��ϴ�\n");
		return FALSE;
	}
	if(pos < 0 || pos > pList->currCount){
		printf("������ �ʰ��Ͽ����ϴ�.\n");
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
	printf("%d��°�� %d �߰�\n", pos, node.data);
	return TRUE;
};

void displayLinkedList(LinkedList *pList){
	if(pList == NULL){
		printf("LinkedList�� �������� �ʽ��ϴ�\n");
	}
	Node *pTmp = &(pList->headNode);
	int i;
	printf("-------------------------\n");
	printf("���� ����� ���� : %d\n", pList->currCount);
	for(i = 0, pTmp = pTmp->link ; i < pList->currCount ; i++, pTmp = pTmp->link){
		printf("[%d] data : %d\n", i, pTmp->data);
	}
	printf("-------------------------\n");
}

int removeNode(LinkedList *pList, int pos){
	if(pList == NULL){
		printf("�ش� LinkedList�� �������� �ʽ��ϴ�\n");
		return FALSE;
	}
	if(pos < 0 || pos >= pList->currCount){
		printf("������ �ʰ��Ͽ����ϴ�.\n");
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
	printf("%d��° ������ ����\n",pos);
	return TRUE;
}

Node* getNode(LinkedList *pList, int pos){
	if(pList == NULL){
		printf("�ش� LinkedList�� �������� �ʽ��ϴ�\n");
		return FALSE;
	}
	if(pos < 0 || pos >= pList->currCount){
		printf("������ �ʰ��Ͽ����ϴ�.\n");
		return FALSE;
	}
	Node *pTmpList = &(pList->headNode);
	int i;
	for(i = 0, pTmpList = pTmpList->link; i < pos ; i++,pTmpList = pTmpList->link){}
	return pTmpList;
}


#endif
