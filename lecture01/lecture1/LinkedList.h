#ifndef LINKED_LIST
#define LINKED_LIST

// __LINKED.....  << __ 이유는 기본 헤더파일과 충돌을 피하기 위해 현대 스타일은 없애는 추세

typedef int ElementType; //확장성 때문에 


typedef struct _node {
	ElementType data;
	struct _node* next_node;
} Node;

//_node인 이유는 c언어 스타일 때문에 
// _node a =>불가능
// struct _node a라고 해야하기 때문에 귀찮아서 뒤에 이름을 따로 붙혀준다.
// Node a 가능


Node* SLL_CreateNode(ElementType NewData); 
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
Node* SLL_GetNodeAt(Node* Head, int Location);
void SLL_RemoveNode(Node** Head, Node* Remove);
void SLL_InsertAfter(Node* Current, Node* NewNode);
int SLL_GetNodeCount(Node* Head);



#endif