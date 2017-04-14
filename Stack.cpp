#include "Stack.h"
#include <string>
#include <cassert>
#include <iostream>

Stack::Stack(){
	top = NULL;
	bot = NULL;
	size = 0;
}

int Stack::Size() const{
	return size;
}

bool Stack::IsEmpty() const{
	return size == 0;
}

std::string Stack::ToString() const{
	if (IsEmpty())
		return std::string("...");
	OneLinkNode *stringNode = top;
	std::string resultString = "";
	while (stringNode != NULL)
	{
		resultString += std::to_string(stringNode->value) + ' ';
		stringNode = stringNode->Next;
	}
	return resultString;
}

bool Stack::Push(int value){
	OneLinkNode *newNode = new OneLinkNode;
	newNode->value = value;
	newNode->Next = top;
	if (IsEmpty())
		bot = newNode;
	top = newNode;
	size++;
	return true;
}

int Stack::Pop(){
	assert(!IsEmpty());
	int valueForReturn = top->value;
	OneLinkNode *newHeadNode = top->Next;
	delete top;
	top = newHeadNode;
	size--;
	return valueForReturn;
}

int Stack::Peek() const{
	return top->value;
}


Stack::~Stack(){
	OneLinkNode *nodeForDel;
	while (top != NULL)
	{
		nodeForDel = top->Next;
		delete top;
		top = nodeForDel;
	}
	std::cout << "Destroy";
}
