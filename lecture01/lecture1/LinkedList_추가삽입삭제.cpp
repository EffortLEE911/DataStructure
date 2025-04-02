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
		cout << "��ũ�� ����Ʈ ���� ���α׷��Դϴ�." << endl;
		cout << "0. ����, 1. ��� �߰�, 2. ��� Ž��, 3.��� ����, 4. ��� ����, 5. ��� ���� ����"<< endl;
		

		cin >> sw;
		switch (sw)
		{
			case 0:
				break;

			case 1:
				cout << "������ �Է��Ͻÿ�. ������ ���Ե� ��尡 �߰��˴ϴ�. " << endl;
				cin >> data;

				NewNode=SLL_CreateNode(data);
				SLL_AppendNode(&List, NewNode);
				break;

			case 2:
				cout << "Ž���ϰ� ���� ����� ��ġ�� �Է��Ͻÿ�." << endl;
				cin >> data;

				current = SLL_GetNodeAt(List, data);
				if (current == NULL) {
					cout << "Ž���ϰ� ���� ����� ��ġ�� �������� �ʽ��ϴ�." << endl;
				}
				else {
					cout << "����� ���� " << current->data << endl;
				}

				break;

			case 3:
				cout << "�����ϰ� ���� ����� ��ġ�� �Է��Ͻÿ�" << endl;
				cin >> data;

				current = SLL_GetNodeAt(List, data);

				if (current == NULL) {
					cout << "Ž���ϰ� ���� ����� ��ġ�� �������� �ʽ��ϴ�." << endl;
				}
				else
				{
					SLL_RemoveNode(&List, current);
					cout << current->data << " ���� �����մϴ�." << endl;
					free(current);
				}
				break;

			case 4:
				cout << "�����ϰ� ���� ����� ��ġ�� �Է��Ͻÿ�" << endl;
				cin >> data;

				current = SLL_GetNodeAt(List, data);
				if (current == NULL) {
					cout << "Ž���ϰ� ���� ����� ��ġ�� �������� �ʽ��ϴ�." << endl;
				}
				else {
					cout << "������ �Է��Ͻÿ�. ������ ���Ե� ��尡 �߰��˴ϴ�. " << endl;
					cin >> data;
					
					NewNode = SLL_CreateNode(data);
					SLL_InsertAfter(current, NewNode);

				}
				break;

			case 5:
				data = SLL_GetNodeCount(List);
				cout << "���� ����� ������ " << data << endl;
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
	cout << "======����======" << endl;

	count = SLL_GetNodeCount(List);

	for (int i = 0; i < count; i++) {

		current = SLL_GetNodeAt(List, 0);
		SLL_RemoveNode(&List, current);
		cout << current->data << " ����" << endl;
		free(current);
	}

	//��Ļ��� ����
	//while (current != NULL) {
	//	next = current->next_node;
	//	cout << current->data << " ����" << endl;
	//	free(current);
	//	current = next;
	//}


}

//1. ����� ����

Node* SLL_CreateNode(ElementType NewData) {

	Node* NewNode = (Node*)malloc(sizeof(Node)); // malloc(sizeof(�ڷ�)) �����Ҵ� �Ѵٴ� ����
	NewNode->data = NewData;					// ������ �⺻������ void�����̱� ������ (Node*)�� ������ ����ȯ
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

		Tail->next_node = NewNode; //���ο� ��� NewNode�� ������ ��带 ����

	}

}

//3.����� Ž��

Node* SLL_GetNodeAt(Node* Head, int Location) {

	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0) // --Location ����������, Location++���� ������.
	{
		Current = Current->next_node;
	}

	return Current;
}

//4. ����� ����
void SLL_RemoveNode(Node** Head, Node* Remove) 
{
	if (*Head == Remove)
	{
		*Head = Remove->next_node;	//�����ϰ� ���� ��ġ�� ���� ���� �����, ���� ���� ����� ������ ����, �� ���� ��带 head�� ����
	}
	else
	{
		Node* Current = *Head;	//���� ��带 List�� ���� ������ ����(Head�� ����)
		while (Current != NULL && Current->next_node!=Remove) //Current!=NULL�� ������ �����ϰ� ���� �����Ͱ� ���� ��� NULL������ �������� �ʰ� ������ ���� ����.
		{
			Current = Current->next_node;	//��带 �����ϰ� ���� ��ġ���� �̵�
		}

		if (Current != NULL)
		{
			Current->next_node = Remove->next_node;	//���� ��ġ ���� ��忡�� ������ġ ����� �ּҸ� ����, ������� ���� ���� ����
		}

	}

}

//5. ����� ����
void SLL_InsertAfter(Node* Current, Node* NewNode) 
{
	
	NewNode->next_node = Current->next_node;	//������ �߿��մϴ�.
	Current->next_node = NewNode;

	// Current->next_node = NewNode;			//�̿� ���� �����̸� ���� ��ġ���� ��������� ��ġ�� �Ҿ����
	// NewNode->next_node = Current->next_node;	//�Ʒ��� ���� �� �� �����ϴ�.
	
}

//6. ����� ���� ���� 
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

