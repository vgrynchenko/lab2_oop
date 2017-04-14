#pragma once
#include "Interfaces.h"
class StaticArray :
	public IndexedContainer{
private:
	int *arr, size, defaultValue;
public:
	StaticArray(int, int);
	int Size() const;
	bool IsEmpty() const;
	std::string ToString() const;
	int Get(int) const;
	void Set(int, int) const;
	~StaticArray();
};

