#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

	Node* List = NULL;
	Node* NewNode = NULL;
	Node* current = NULL;
	Node* next = NULL;
	int sw;

	int data;
	int count = 0;

	while (true)
	{
		data = -99;
		sw = -99;
		cout << "링크드 리스트 예제 프로그램입니다." << endl;
		cout << "0. 종료, 1. 노드 추가, 2. 노드 탐색, 3.노드 삭제, 4. 노드 삽입, 5. 노드 개수 새기"<< endl;
		

		cin >> sw;
		switch (sw)
		{
			case 0:
				break;

			case 1:
				cout << "정수를 입력하시오. 정수가 포함된 노드가 추가됩니다. " << endl;
				cin >> data;

				NewNode=SLL_CreateNode(data);
				SLL_AppendNode(&List, NewNode);
				break;

			case 2:
				cout << "탐색하고 싶은 노드의 위치를 입력하시오." << endl;
				cin >> data;

				current = SLL_GetNodeAt(List, data);
				if (current == NULL) {
					cout << "탐색하고 싶은 노드의 위치가 존재하지 않습니다." << endl;
				}
				else {
					cout << "노드의 값은 " << current->data << endl;
				}

				break;

			case 3:
				cout << "삭제하고 싶은 노드의 위치를 입력하시오" << endl;
				cin >> data;

				current = SLL_GetNodeAt(List, data);

				if (current == NULL) {
					cout << "탐색하고 싶은 노드의 위치가 존재하지 않습니다." << endl;
				}
				else
				{
					SLL_RemoveNode(&List, current);
					cout << current->data << " 값을 삭제합니다." << endl;
					free(current);
				}
				break;

			case 4:
				cout << "삽입하고 싶은 노드의 위치를 입력하시오" << endl;
				cin >> data;

				current = SLL_GetNodeAt(List, data);
				if (current == NULL) {
					cout << "탐색하고 싶은 노드의 위치가 존재하지 않습니다." << endl;
				}
				else {
					cout << "정수를 입력하시오. 정수가 포함된 노드가 추가됩니다. " << endl;
					cin >> data;
					
					NewNode = SLL_CreateNode(data);
					SLL_InsertAfter(current, NewNode);

				}
				break;

			case 5:
				data = SLL_GetNodeCount(List);
				cout << "현재 노드의 개수는 " << data << endl;
				break;


		}

		current = List;
		while (current != NULL) {
			cout << current->data << "->";
			current = current->next_node;
		}
		cout << endl<<endl;
		
		if (sw == 0)
		{
			break;
		}
		


	}

	current = List;
	while (current != NULL) {
		cout << current->data << "->";
		current = current->next_node;
	}
	cout << endl;
	cout << "======삭제======" << endl;

	count = SLL_GetNodeCount(List);

	for (int i = 0; i < count; i++) {

		current = SLL_GetNodeAt(List, 0);
		SLL_RemoveNode(&List, current);
		cout << current->data << " 삭제" << endl;
		free(current);
	}

	//약식삭제 연산
	//while (current != NULL) {
	//	next = current->next_node;
	//	cout << current->data << " 삭제" << endl;
	//	free(current);
	//	current = next;
	//}


}

//1. 노드의 생성

Node* SLL_CreateNode(ElementType NewData) {

	Node* NewNode = (Node*)malloc(sizeof(Node)); // malloc(sizeof(자료)) 동적할당 한다는 내용
	NewNode->data = NewData;					// 하지만 기본적으로 void형태이기 때문에 (Node*)로 적절한 형변환
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

		Tail->next_node = NewNode; //새로운 노드 NewNode와 마지막 노드를 연결

	}

}

//3.노드의 탐색

Node* SLL_GetNodeAt(Node* Head, int Location) {

	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0) // --Location 전위연산자, Location++후위 연산자.
	{
		Current = Current->next_node;
	}

	return Current;
}

//4. 노드의 삭제
void SLL_RemoveNode(Node** Head, Node* Remove) 
{
	if (*Head == Remove)
	{
		*Head = Remove->next_node;	//삭제하고 싶은 위치가 가장 앞의 노드라면, 가장 앞의 노드의 연결을 끊고, 그 다음 노드를 head로 지정
	}
	else
	{
		Node* Current = *Head;	//현재 노드를 List의 가장 앞으로 설정(Head로 설정)
		while (Current != NULL && Current->next_node!=Remove) //Current!=NULL인 이유는 삭제하고 싶은 데이터가 없을 경우 NULL포인터 접근하지 않게 안전을 위해 존재.
		{
			Current = Current->next_node;	//노드를 삭제하고 싶은 위치까지 이동
		}

		if (Current != NULL)
		{
			Current->next_node = Remove->next_node;	//삭제 위치 이전 노드에서 삭제위치 노드의 주소를 끊고, 삭제노드 다음 노드와 연결
		}

	}

}

//5. 노드의 삽입
void SLL_InsertAfter(Node* Current, Node* NewNode) 
{
	
	NewNode->next_node = Current->next_node;	//순서가 중요합니다.
	Current->next_node = NewNode;

	// Current->next_node = NewNode;			//이와 같은 순서이면 현재 위치에서 다음노드의 위치를 잃어버려
	// NewNode->next_node = Current->next_node;	//아래와 연결 할 수 없습니다.
	
}

//6. 노드의 개수 세기 
int SLL_GetNodeCount(Node* Head) 
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->next_node;
		Count++;
	}

	return Count;

}

