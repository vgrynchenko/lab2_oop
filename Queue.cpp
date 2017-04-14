#include "Queue.h"
#include <string>
#include <cassert>

Queue::Queue(){
	top = NULL;
	bot = NULL;
	size = 0;
}

int Queue::Size() const{
	return size;
}

bool Queue::IsEmpty() const{
	return size == 0;
}

std::string Queue::ToString() const{
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

bool Queue::Push(int value){
	OneLinkNode *newNode = new OneLinkNode;
	newNode->value = value;
	newNode->Next = NULL;
	if (IsEmpty())
		top = newNode;
	else
		bot->Next = newNode;
	bot = newNode;
	size++;
	return true;
}

int Queue::Pop(){
	assert(!IsEmpty());
	int valueForReturn = top->value;
	OneLinkNode *newHeadNode = top->Next;
	delete top;
	top = newHeadNode;
	size--;
	return valueForReturn;
}

int Queue::Peek() const{
	return top->value;
}


Queue::~Queue(){
	OneLinkNode *nodeForDel;
	while (top != NULL)
	{
		nodeForDel = top->Next;
		delete top;
		top = nodeForDel;
	}
}
