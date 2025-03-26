#ifndef LINKED_LIST
#define LINKED_LIST

// __LINKED.....  << __ ������ �⺻ ������ϰ� �浹�� ���ϱ� ���� ���� ��Ÿ���� ���ִ� �߼�

typedef int ElementType; //Ȯ�强 ������ 


typedef struct _node {
	ElementType data;
	struct _node* next_node;
} Node;

//_node�� ������ c��� ��Ÿ�� ������ 
// _node a =>�Ұ���
// struct _node a��� �ؾ��ϱ� ������ �����Ƽ� �ڿ� �̸��� ���� �����ش�.
// Node a ����


Node* SLL_CreateNode(ElementType NewData); 
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
Node* SLL_GetNodeAt(Node* Head, int Location);
void SLL_RemoveNode(Node** Head, Node* Remove);
void SLL_InsertAfter(Node* Current, Node* NewNode);
int SLL_GetNodeCount(Node* Head);



#endif