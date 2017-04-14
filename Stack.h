#pragma once
#include "Interfaces.h"
class Stack :
	public PushPopContainer{
private:
	OneLinkNode *top, *bot;
	int size;
public:
	Stack();
	int Size() const;
	bool IsEmpty() const;
	std::string ToString() const;
	bool Push(int);
	int Pop();
	int Peek() const;
	~Stack();
};

