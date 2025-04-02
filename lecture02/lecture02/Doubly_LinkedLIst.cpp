#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
	int i = 10;
	Node* List = NULL;
	Node* NewNode = NULL;

	Node* current = NULL;
	Node* next = NULL;

	for (int j = 1; j <= i; j++) {
		NewNode = DLL_CreateNode(10*j);
		DLL_AppendNode(&List, NewNode);
	}
	current = List;
	while (current!= NULL)
	{
		cout << current->data << "->";
		current = current->next_node;
	}
	cout << endl;
	cout << "노드 " << i <<"개 생성" << endl << endl;




	//노드삭제
	current = DLL_GetNodeAt(List, 3);
	cout << "현재 값" << current->data << " 삭제" << endl;
	DLL_RemoveNode(&List, current);
	free(current);
	cout << "현재 노드의 갯수는 : " << DLL_GetNodeCount(List) <<  endl;

	current = List;
	while (current != NULL)
	{
		cout << current->data << "->";
		current = current->next_node;
	}
	cout << endl<<endl;


	//노드 삭제2
	current = DLL_GetNodeAt(List, 4);
	cout << "현재 노드는 " << current->data << ", 그리고 삭제" << endl;
	DLL_RemoveNode(&List, current);
	free(current);	

	current = List;
	while (current != NULL)
	{
		cout << current->data << "->";
		current = current->next_node;
	}
	cout << endl<<endl;

	//노드 삽입 
	current = DLL_GetNodeAt(List, 6);
	cout << "현재 노드의 값은 " << current->data << endl;
	NewNode = DLL_CreateNode(300);
	DLL_InsertAfter(current, NewNode);
	
	current = List;
	while (current != NULL)
	{
		cout << current->data << "->";
		current = current->next_node;
	}
	cout << endl << endl;

	//노드의 탐색
	cout << "노드의 탐색을 시작합니다" << endl;
	current = List;
	while(current->next_node!=NULL)
	{
		cout <<current->data << "->";
		current = current->next_node;
	}
	

	while (current!= NULL)
	{
		cout << current->data << "->";
		current = current->pre_node;
	}

	cout << endl << endl;
	cout << "==========삭제==========" << endl;

	for (int j = 0; j < i - 1; j++)
	{
		current = DLL_GetNodeAt(List, 0);
		DLL_RemoveNode(&List, current);
		cout << current->data << "삭제" << endl;
		free(current);

	}


}

//1. 노드생성
Node* DLL_CreateNode(ElementType NewData)
{

	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->data = NewData;
	NewNode->next_node = NULL;
	NewNode->pre_node = NULL;

	return NewNode;

}


//2. 노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode) {


	if (*Head == NULL) //List가 비어 있다면, 즉, Head가 아무것도 없다면
	{
		*Head = NewNode;
	}

	else {

		Node* Tail = *Head;

		while (Tail->next_node != NULL)
		{
			Tail = Tail->next_node;
		}
		Tail->next_node = NewNode;
		NewNode->pre_node = Tail; //NewNode의 pre_node 포인터가 기존의 Node를 가르키게 하면됨

	}
	

}

//3. 노드 탐색
Node* DLL_GetNodeAt(Node* Head, int Location) {

	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0) 
	{
		Current = Current->next_node;
	}

	return Current;

}


//4. 노드 삭제
void DLL_RemoveNode(Node** Head, Node* Remove) {

	if (*Head == Remove) 
	{
		*Head = (*Head)->next_node;
		if (*Head != NULL) 
		{
			(*Head)->pre_node = NULL;
		}

		Remove->next_node = NULL;
		Remove->pre_node = NULL;

	}
	else 
	{
		Node* Temp = Remove; //Temp는 임시 포인터, 이를 활용하여 원하는 Node 제거
		if (Remove->pre_node != NULL) 
		{
			Remove->pre_node->next_node = Temp->next_node;
		}

		if (Remove->next_node != NULL)
		{
			Remove->next_node->pre_node = Temp->pre_node;
		}

		Remove->next_node = NULL;
		Remove->pre_node = NULL;

	}
}


//5. 노드 삽입
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->next_node = Current->next_node;
	NewNode->pre_node = Current;

	if (Current->next_node != NULL) 
	{
		Current->next_node->pre_node = NewNode;
		Current->next_node = NewNode;
	}


}

//6. 노드 숫자 세기
int DLL_GetNodeCount(Node* Head) 
{
	int count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->next_node;
		count++;

	}
	return count;

}

