#include "LinkedDeque.h"
#include <string>
#include <cassert>

LinkedDeque::LinkedDeque()
{
	bot = NULL;
	top = NULL;
	size = 0;
}
int LinkedDeque:: Size() const {
	return size;
}
bool LinkedDeque::IsEmpty() const {
	return size == 0;
}
std::string LinkedDeque::ToString() const {
	if (IsEmpty())
		return std::string("...");
	TwoLinkNode *stringNode = top;
	std::string resultString = "";
	while (stringNode)
	{
		resultString += std::to_string(stringNode->value) + ' ';
		stringNode = stringNode->Next;
	}
	return resultString;
}
bool LinkedDeque::PushFront(int value) {
	TwoLinkNode *newNode = new TwoLinkNode;
	newNode->value = value;
	newNode->Prev = NULL;
	newNode->Next = top;
	if (IsEmpty())
		bot = newNode;
	else
		top->Prev = newNode;
	top = newNode;
	size++;
	return true;
}
bool LinkedDeque::PushBack(int value) {
	TwoLinkNode *newNode = new TwoLinkNode;
	newNode->value = value;
	newNode->Next = NULL;
	newNode->Prev = bot;
	if (IsEmpty())
		top = newNode;
	else
		bot->Next = newNode;
	bot = newNode;
	size++;
	return true;
}
int LinkedDeque::PopFront() {
	assert(!IsEmpty());
	TwoLinkNode *newHeadNode = top->Next;
	int valueForReturn = top->value;
	delete top;
	top = newHeadNode;
	if (top)
		top->Prev = NULL;
	else
		bot = NULL;
	size--;
	return valueForReturn;
}
int LinkedDeque::PopBack() {
	assert(!IsEmpty());
	TwoLinkNode *newHeadNode = bot->Prev;
	int valueForReturn = bot->value;
	delete bot;
	bot = newHeadNode;
	if (bot)
		bot->Next = NULL;
	else
		top = NULL;
	size--;
	return valueForReturn;
}
int LinkedDeque::PeekFront() const {
	return top->value;
}
int LinkedDeque::PeekBack() const {
	return bot->value;
}

LinkedDeque::~LinkedDeque()
{
	TwoLinkNode *nodeForDel;
	while (top)
	{
		nodeForDel = top->Next;
		delete top;
		top = nodeForDel;
	}
}
