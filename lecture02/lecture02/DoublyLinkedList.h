#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H


typedef int ElementType; // 확장성 때문에

typedef struct _node {

	ElementType data;
	struct _node* pre_node;  //이전 Node의 주소를 저장
	struct _node* next_node; //다음 Node의 주소를 저장

}Node;

Node* DLL_CreateNode(ElementType NewData);
void DLL_AppendNode(Node** Head, Node* Node);
Node* DLL_GetNodeAt(Node* Head, int Location);
void DLL_RemoveNode(Node** Head, Node* Remove); 
void DLL_InsertAfter(Node* Current, Node* NewNode);
int DLL_GetNodeCount(Node* Head);


#endif
