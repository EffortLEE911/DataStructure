#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H


typedef int ElementType; // Ȯ�强 ������

typedef struct _node {

	ElementType data;
	struct _node* pre_node;  //���� Node�� �ּҸ� ����
	struct _node* next_node; //���� Node�� �ּҸ� ����

}Node;

Node* DLL_CreateNode(ElementType NewData);
void DLL_AppendNode(Node** Head, Node* Node);
Node* DLL_GetNodeAt(Node* Head, int Location);
void DLL_RemoveNode(Node** Head, Node* Remove); 
void DLL_InsertAfter(Node* Current, Node* NewNode);
int DLL_GetNodeCount(Node* Head);


#endif
