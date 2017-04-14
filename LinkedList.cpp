#include "LinkedList.h"
#include <cassert>
#include <string>

LinkedList::LinkedList() {
	bot = NULL;
	top = NULL;
	size = 0;
}

int LinkedList::Size() const {
	return size;
}

bool LinkedList::IsEmpty() const {
	return size == 0;
}

std::string LinkedList::ToString() const {
	if (IsEmpty())
		return std::string("...");
	OneLinkNode *stringNode = bot;
	std::string resultString = "";
	while (stringNode != NULL)
	{
		resultString = std::to_string(stringNode->value) + ' ' + resultString;
		stringNode = stringNode->Next;
	}
	return resultString;
}

bool LinkedList::Push(int value) {
	OneLinkNode *newNode = new OneLinkNode;
	newNode->value = value;
	newNode->Next = bot;
	if (IsEmpty())
		top = newNode;
	bot = newNode;
	size++;
	return true;
	 
}

int LinkedList::Pop() {
	assert(!IsEmpty());
	int valueForReturn = bot->value;
	OneLinkNode *newHeadNode = bot->Next;
	delete bot;
	bot = newHeadNode;
	size--;
	return valueForReturn;
}

int LinkedList::Peek() const {
	return bot->value;
}

int LinkedList::Get(int index) const{
	assert(!(IsEmpty() || index >= size || index < 0));
	OneLinkNode *forGetNode = bot;
	for (int i = 1; i <= size - 1 - index; i++)
		forGetNode = forGetNode->Next;
	return forGetNode->value;
}

void LinkedList::Set(int index, int value) const{
	assert(!(IsEmpty() || index >= size || index < 0));
	OneLinkNode *forSetNode = bot;
	for (int i = 1; i <= size - 1 - index; i++)
		forSetNode = forSetNode->Next;
	forSetNode->value = value;
}

bool LinkedList::Insert(int index, int value){
	if (index > size || index < 0 || IsEmpty() && index != 0)
		return false;
	Push(value);
	int swapValue;
	for (int i = size - 1; i > index; i--) {
		swapValue = Get(i - 1);
		Set(i - 1, Get(i));
		Set(i, swapValue);
	}
	return true;
}

int LinkedList::Remove(int index){
	if (index >= size || index < 0 || IsEmpty())
		return -1;
	int tmpDel = Pop();
	for (int i = index; i < size - 1; i++)
		Set(i, Get(i + 1));
	if (index != size)
		Set(size - 1, tmpDel);
	return 0;
}

LinkedList::~LinkedList() {
	OneLinkNode *nodeForDel;
	while (bot != NULL)
	{
		nodeForDel = bot->Next;
		delete bot;
		bot = nodeForDel;
	}
}