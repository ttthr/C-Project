#include<iostream>
using namespace std;

class Node
{
public:
	Node* Parent;
	Node* Left;
	Node* Right;
	int Data;
};

class Tree
{
public:
	Tree()
	{
		Root = new Node();
		Root->Data = 1;
	}
public:
	Node* Root;
	//Tree& CreateLeftNode(Tree& NewNode , int Value)
	//{
	//	NewNode.Root->Left = new Node();
	//	NewNode.Root->Left->Data = Value;
	//	
	//	return *this;
	//};
	Node* CreateNode()
	{
		Node* NewNode = new Node;
		NewNode->Left = nullptr;
		NewNode->Right = nullptr;
		return NewNode;
	};
	void insertData(Node* insertNode, int Value)
	{
		insertNode->Data = Value;
	}
	int GetData(Node* GetNode)
	{
		return GetNode->Data;
	}
	//노드 순회하는 함수가 필요함
	void NodeSerach(Node* CurrentNode, Node* NextNode)
	{
	
	}

};

int main()
{
	Tree Number;
	Number.Root->Left = Number.CreateNode();
	Number.insertData(Number.Root->Left, 2);

	Number.Root->Right = Number.CreateNode();
	Number.insertData(Number.Root->Right, 3);


	//Number.CreateLeftNode(Number, 2);
	//Number.Root->Left->Data = 2;

	//Number.Root->Right = new Node();
	//Number.Root->Right->Data = 3;


	//Number.Root->Left->Left = new Node();
	//Number.Root->Left->Left->Data = 4;

	//Number.Root->Left->Right = new Node();
	//Number.Root->Left->Right->Data = 5;


	//Number.Root->Right->Left = new Node();
	//Number.Root->Right->Left->Data = 6;

	//Number.Root->Right->Right = new Node();
	//Number.Root->Right->Right->Data = 7;


	return 0;
}