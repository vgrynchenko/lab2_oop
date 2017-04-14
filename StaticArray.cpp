#include "StaticArray.h"
#include <string>
#include <cassert>


StaticArray::StaticArray(int size, int defaultValue){
	this->size = size;
	this->defaultValue = defaultValue;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = defaultValue;
}

int StaticArray::Size() const {
	return size;
}

bool StaticArray::IsEmpty() const {
	return size == 0;
}

std::string StaticArray::ToString() const{
	if (IsEmpty())
		return std::string("...");
	std::string resultString = "";
	for (int i = 0; i < size; i++)
		//if(arr[i] != defaultValue)
			resultString += std::to_string(arr[i]) + " ";
	return resultString;
}

int StaticArray::Get(int index) const{
	assert(!(index >= size || index < 0));
	return arr[index];
}

void StaticArray::Set(int index = 0, int value = 0) const{
	assert(!(index >= size || index < 0));
	arr[index] = value;
}


StaticArray::~StaticArray(){
	delete[] arr;
}
