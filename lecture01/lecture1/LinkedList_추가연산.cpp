#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

	Node* List = NULL;
	Node* NewNode = NULL;
	Node* current = NULL;
	Node* next = NULL;
	
	int f;

	while (true) 
	{
		cout << "정수를 입력하세요 (0을 입력하면 프로그램이 종료됩니다)";
		cin >> f;

		if (f == 0) 
		{
			break;
		}
		else 
		{

			NewNode = SLL_CreateNode(f);
			SLL_AppendNode(&List, NewNode);
		}
				
	}

	current = List;
	while (current != NULL) {
		cout << current->data << "->";
		current = current->next_node;
	}
	cout << endl;
	cout << "======삭제======" << endl;

	current = List;

	while (current != NULL) {
		next = current->next_node;
		cout << current->data << " 삭제" << endl;
		free(current);
		current = next;
	}


}

//1. 노드의 생성

Node* SLL_CreateNode(ElementType NewData) {

	Node* NewNode = (Node*)malloc(sizeof(Node)); // malloc(sizeof(자료)) 동적할당 한다는 내용
													// 하지만 기본적으로 void형태이기 때문에 (Node*)로 적절한 형변환
	NewNode->data = NewData;
	NewNode->next_node = NULL;

	return NewNode;

}


//2. 노드의 추가.
void SLL_AppendNode(Node** Head, Node* NewNode) 
{

	if (*Head == NULL) 
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = *Head;
		while (Tail->next_node != NULL) //노드의 마지막 까지 이동하는 로직 
		{
			Tail = Tail->next_node;
		}
		Tail->next_node = NewNode;

	}

}
