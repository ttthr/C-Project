#pragma once
//--------
//| 1  | |
//--------
//--------
//| 2  | |
//--------
//--------
//| 3  | |
//--------
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

		Node* operator* ()
		{
			return Current;
		}

		bool operator!=(const Iterator& rhs)
		{
			return (Current != rhs.Current);
		}
	};

	void Insert(int NewValue);

	void Insert(int NewValue, int SearchValue);
	Iterator Find(int SearchValue);

	Iterator Begin() { return Iterator(Head->Next);  }
	Iterator End() { return Iterator(Tail); }

protected:
	Node* Tail;
	Node* Head;
};

