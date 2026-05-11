#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define	CIRCULAR_DOUBLY_LINKEDLIST_H

typedef int Element;

typedef struct _node 
{
	Element data;
	struct _node* next_node;
	struct _node* pre_node;
		

}Node;

Node* CDLL_CreateNode(Element NewData);




#endif