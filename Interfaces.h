#pragma once
#include <iostream>
#include "Nodes.h"

class Container {
	public:
	virtual int Size() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual std::string ToString() const = 0;
	virtual ~Container() {};
	
};

class PushPopContainer :
	public virtual Container {
public:
	virtual bool Push(int) = 0;
	virtual int Pop() = 0;
	virtual int Peek() const = 0;
	virtual ~PushPopContainer() {};
};

class Deque :

	public virtual Container {
public:
	virtual bool PushFront(int) = 0;
	virtual bool PushBack(int) = 0;
	virtual int PopFront() = 0;
	virtual int PopBack() = 0;
	virtual int PeekFront() const = 0;
	virtual int PeekBack() const = 0;
	virtual ~Deque() {};
};

class IndexedContainer :

	public virtual Container {
public:
	virtual int Get(int) const = 0;
	virtual void Set(int, int) const = 0;
	virtual ~IndexedContainer() {};
};

class InsertableContainer :

	public virtual IndexedContainer {
public:
	virtual bool Insert(int, int) = 0;
	virtual int Remove(int) = 0;
	virtual ~InsertableContainer() {};
};