#pragma once
#include "Interfaces.h"
class LinkedDeque :
	public Deque {
private:
	TwoLinkNode *bot, *top;
	int size;
public:
	LinkedDeque();
	int Size() const;
	bool IsEmpty() const;
	std::string ToString() const;
	bool PushFront(int);
	bool PushBack(int);
	int PopFront();
	int PopBack();
	int PeekFront() const;
	int PeekBack() const;
	~LinkedDeque();
};
	


