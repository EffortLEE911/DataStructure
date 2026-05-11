#include <iostream>
#include "CircularDoublyLinkedList.h"

using namespace std;

int main()
{
	Node* List = NULL;
	Node* new_node = NULL;
	Node* current = NULL;

	//1. 노드 추가(main)

	List = CDLL_CreateNode(10);
	new_node = CDLL_CreateNode(20);

	List->pre_node = List;
	List->next_node = List;

	////////////////

	
}

//1. 노드 생성
Node* CDLL_CreateNode(Element NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = NewData;
	NewNode->next_node = NULL;
	NewNode->pre_node = NULL;

	return NewNode;

}


