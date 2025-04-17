#include <iostream>
#include "CircularDoublyLinkedList.h"

using namespace std;


int main()
{
	Node* NewNode = NULL;
	Node* List = NULL;
	Node* Current = NULL;
	int count = 0;


	for (int i = 0; i < 8; i++) {
		NewNode = CDLL_CreateNode(20*i + 10);
		CDLL_AppendNode(&List, NewNode);
	}
	
	Current = List;

	while (true) {
		cout << Current->data << "->";
		Current = Current->next_node;
		if (Current == List) {
			break;
		}
	}

	cout << endl << endl;

	//삭제연산 테스트 1번 2번은 앞에서 삭제 , 3번은 index번호 3번 삭제(4번째 node삭제)
	Current = CDLL_GetNodeAt(List, 0);
	CDLL_RemoveNode(&List, Current);
	cout << Current->data << " 삭제" << endl;
	free(Current);

	Current = CDLL_GetNodeAt(List, 0);
	CDLL_RemoveNode(&List, Current);
	cout << Current->data << " 삭제" << endl;
	free(Current);

	Current = CDLL_GetNodeAt(List, 3);
	CDLL_RemoveNode(&List, Current);
	cout << Current->data << " 삭제" << endl;
	free(Current);
	
	Current = List;

	while (Current != NULL)
	{
		cout << Current->data << "->";
		Current = Current->next_node;

		if (Current == List)
		{
			break;
		}
	}
	cout << endl<<endl<<endl;

	//삽입 연산 확인

	count = CDLL_GetNodeCount(List);
	cout << "개수는 : " << count << endl;
	NewNode = CDLL_CreateNode(999);
	Current = CDLL_GetNodeAt(List, count-1);
	cout << "현재 노드의 값은 : " << Current->data << endl;
	CDLL_InsertAfter(Current, NewNode);


	//제대로 연결 됐으면 Head에서 Tail로 바로 이동 가능
	cout << List->data << " Head의 값" << endl;
	cout << List->pre_node->data << " Tail의 값" << endl << endl;

	Current = List;

	while (Current!=NULL) 
	{
		cout << Current->data << "->";
		Current = Current->next_node;

		if (Current == List) 
		{
			break;
		}
	}
	cout << endl;


	//동적할당 해제
	Current = List;
	Node* Next = NULL;

	while (Current!=NULL) {

		Next = Current->next_node;
		cout << Current->data << "삭제 " << endl;
		free(Current);
		Current = Next;

		if (Current == List) {
			break;
		}

	}

	cout << endl << endl;


}


//1. 노드 생성
Node* CDLL_CreateNode(Element NewData) {
	
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = NewData;
	NewNode->next_node = NULL;
	NewNode->pre_node = NULL;

	return NewNode;
}


//2. 노드 추가
void CDLL_AppendNode(Node** Head, Node* NewNode) {

	if (*Head == NULL) 
	{
		*Head = NewNode;
		(*Head)->next_node = *Head;
		(*Head)->pre_node = *Head;

	}
	else
	{
		Node* Tail = (*Head)->pre_node;
		
		//책은 아래처럼 표현했는데, 밑에 표현이 좀 더 쉬운 것 같아서 아래로 바꿈 실행결과는 같음
		//Tail->next_node->pre_node = NewNode;

		(*Head)->pre_node = NewNode;
		Tail->next_node = NewNode;
		
		NewNode->pre_node = Tail;
		NewNode->next_node = *Head;

	}

}

//3. 노드 탐색
Node* CDLL_GetNodeAt(Node* Head, int Location) {

	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0) {
		
		Current = Current->next_node;

		//환형 리스트이기 때문에 숫자가 초과되면 반복해서 탐색을 진행함
		//그래서 아래 코드를 넣어서 Head로 이동했다면, Tail로 이동 후 break;
		if (Current == Head) 
		{
			Current = Current->pre_node;
			break;
		}

	}

	return Current;

}

//4. 노드 삭제
void CDLL_RemoveNode(Node** Head, Node* Remove) {

	if (*Head == Remove) {

		(*Head)->pre_node->next_node = Remove->next_node;
		(*Head)->next_node->pre_node = Remove->pre_node;

		*Head = (*Head)->next_node;

		Remove->next_node = NULL;
		Remove->pre_node = NULL;
		
	}
	else {


		Remove->next_node->pre_node = Remove->pre_node;
		Remove->pre_node->next_node = Remove->next_node;

		Remove->next_node = NULL;
		Remove->pre_node = NULL;

	}


}

//5. 노드 중간 추가.
void CDLL_InsertAfter(Node* Current, Node* NewNode) {

	NewNode->pre_node = Current;
	NewNode->next_node = Current->next_node;

	if (Current->next_node != NULL) {
		Current->next_node->pre_node = NewNode;
	}
	Current->next_node = NewNode;


}



//6. 노드 개수 세기
int CDLL_GetNodeCount(Node* Head) {

	Node* Current = Head;
	int Count = 0;

	while (Current != NULL) {
		Current = Current->next_node;
		Count++;

		if (Current == Head) {
			break;
		}

	}
	return Count;
}