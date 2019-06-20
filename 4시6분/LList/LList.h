#pragma once
//------------
//|  |  1  | |
//------------
//------------
//|  |  2  | |
//------------
//------------
//|  |  3  | |
//------------
class Node
{
public:
	int Value;

	Node* Prev;
	Node* Next;
};

class LList
{
public:
	LList();
	virtual ~LList();

	class Iterator
	{
	private:
		Node* Current;
	public:
		Iterator(Node* init = nullptr) : Current(init) {}
		Iterator& operator++()
		{
			Current = Current->Next;
			return *this;
		}

		Iterator operator++(int)
		{
			Node Temp = *Current;
			Current = Current->Next;
			return Iterator(&Temp);
		}

		Node* operator* ()
		{
			return Current;
		}

		bool operator!=(const Iterator& rhs)
		{
			return (Current != rhs.Current);
		}

		bool operator==(const Iterator& rhs)
		{
			return (Current == rhs.Current);
		}
	};

	void PushBack(int NewValue); //Tail 앞에 추가
	void PushFront(int NewValue); //Head 앞에 추가

	void InsertAfter(LList::Iterator Where, int SearchValue);
	Iterator Find(int SearchValue);

	Iterator Begin() { return Iterator(Head->Next);  }
	Iterator End() { return Iterator(Tail); }

protected:
	Node* Tail;
	Node* Head;

	Node* MakeNode(int NewValue);
};

