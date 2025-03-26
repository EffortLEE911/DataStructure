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
		cout << "������ �Է��ϼ��� (0�� �Է��ϸ� ���α׷��� ����˴ϴ�)";
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
	cout << "======����======" << endl;

	current = List;

	while (current != NULL) {
		next = current->next_node;
		cout << current->data << " ����" << endl;
		free(current);
		current = next;
	}


}

//1. ����� ����

Node* SLL_CreateNode(ElementType NewData) {

	Node* NewNode = (Node*)malloc(sizeof(Node)); // malloc(sizeof(�ڷ�)) �����Ҵ� �Ѵٴ� ����
													// ������ �⺻������ void�����̱� ������ (Node*)�� ������ ����ȯ
	NewNode->data = NewData;
	NewNode->next_node = NULL;

	return NewNode;

}


//2. ����� �߰�.
void SLL_AppendNode(Node** Head, Node* NewNode) 
{

	if (*Head == NULL) 
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = *Head;
		while (Tail->next_node != NULL) //����� ������ ���� �̵��ϴ� ���� 
		{
			Tail = Tail->next_node;
		}
		Tail->next_node = NewNode;

	}

}
