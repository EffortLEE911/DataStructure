#include <iostream>

using namespace std;

typedef int ElementType; //Ȯ�强 ������ 

typedef struct node {

	ElementType data;
	struct node* next_node;

}Node;


int main() 
{
	int i = 10;
	int* j = &i;
	int** k = &j;

	cout << "i�� ���� : " << i << endl;
	cout << "i�� �ּҴ� : " << &i << endl << endl;

	cout << "������ j�� ���� : " << j << endl;
	cout << "������ j�� �ּҴ� : " << &j << endl;
	cout << "������ *j(j�� �����ϴ� ��)�� : " << *j << endl<<endl;

	cout << "���� ������ k�� ���� : " << k << endl;
	cout << "���������� *k�� ���� : " << *k << endl;


	cout<<endl<<endl <<"=======================" << endl << endl;


	Node a;
	a.data = 10;
	a.next_node = NULL;

	Node b;
	b.data = 100;
	b.next_node = NULL;

	a.next_node = &b;

	Node* p = &a;

	cout << "a��尡 ������ �ִ� �����ʹ� : " << a.data << endl;
	cout << "b��尡 ������ �ִ� �����ʹ� : " << b.data << endl;

	cout << endl;
	cout << "b�� �ּҴ� : "<<a.next_node << endl;
	cout << a.next_node->data << endl;

	cout << "p�� ����Ű�� Node�� �����ʹ�? : " << p->data << endl;
	cout << "p�� ����Ű�� Node�� ����node��? : " << p->next_node << endl;
	cout << "p�� ����Ű�� Node�� ���� node�� �����ʹ�? : " << (p->next_node)->data << endl;

}