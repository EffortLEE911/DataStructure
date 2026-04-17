#include <iostream>

using namespace std;

typedef int ElementType; //확장성 때문에 

typedef struct node {

	ElementType data;
	struct node* next_node;

}Node;


int main() 
{
	int data = 10;

	int* ptr = &data;

	int** double_p = &ptr;

	cout << "data의 값은 : " << data << endl;
	cout << "data의 주소는 : " << &data << endl << endl;

	cout << "포인터 ptr의 값은 : " << ptr << endl;
	cout << "포인터 ptr의 주소는 : " << &ptr << endl;
	cout << "포인터 *ptr(ptr이 역참조하는 값)은 : " << *ptr << endl << endl;

	cout << "이중 포인터 double_p의 값은 : " << double_p << endl;
	cout << "이중포인터 *double_p의 값은 : " << *double_p << endl;


	cout<<endl<<endl <<"=======================" << endl << endl;


	Node a;
	a.data = 10;
	a.next_node = NULL;

	Node b;
	b.data = 100;
	b.next_node = NULL;

	a.next_node = &b;

	Node* p = &a;

	cout << "a노드가 가지고 있는 데이터는 : " << a.data << endl;
	cout << "b노드가 가지고 있는 데이터는 : " << b.data << endl;

	cout << endl;
	cout << "b의 주소는 : "<<a.next_node << endl;
	cout << a.next_node->data << endl;

	cout << "p가 가르키는 Node의 데이터는? : " << p->data << endl;
	cout << "p가 가르키는 Node의 다음node는? : " << p->next_node << endl;
	cout << "p가 가르키는 Node의 다음 node의 데이터는? : " << (p->next_node)->data << endl;

}