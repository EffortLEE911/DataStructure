#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

typedef int Element;

typedef struct _node {

	Element data;
	struct _node* next_node;
	struct _node* pre_node;

}Node;

Node* CDLL_CreateNode(Element NewData);
void CDLL_AppendNode(Node** Head, Node* NewNode);
Node* CDLL_GetNodeAt(Node* Head, int Location);
void CDLL_RemoveNode(Node** Head, Node* Remove);
void CDLL_InsertAfter(Node* Current, Node* NewNode);
int CDLL_GetNodeCount(Node* Head);


#endif
