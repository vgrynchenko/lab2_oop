#pragma once
#include "Interfaces.h"
class Queue :
	public PushPopContainer{
private:
	OneLinkNode *top, *bot;
	int size;
public:
	Queue();
	int Size() const;
	bool IsEmpty() const;
	std::string ToString() const;
	bool Push(int);
	int Pop();
	int Peek() const;
	~Queue();
};

