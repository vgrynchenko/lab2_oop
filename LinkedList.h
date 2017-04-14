#pragma once
#include "Interfaces.h"
class LinkedList :
	public  virtual InsertableContainer,
	public virtual PushPopContainer{
private:
	OneLinkNode *bot, *top;
	int size;
public:
	LinkedList();
	int Size() const;
	bool IsEmpty() const;
	std::string ToString() const;
	bool Push(int);
	int Pop();
	int Peek() const;
	int Get(int) const;
	void Set(int, int) const;
	bool Insert(int, int);
	int Remove(int);
	~LinkedList();
};

