#include <iostream>

using namespace std;

struct elements
{
	int value;
	string data;
	elements *next;
};
class List
{
private:
	elements *head, *tail;
	int size;
public:
	List()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	List(int value, string data = "")
	{
		elements *new_elem = new elements;
		new_elem->value = value;
		new_elem->data = data;
		head = new_elem;
		tail = new_elem;
		size = 1;
	}
	bool empty_list()
	{
		if (size == 0 || tail == NULL || head == NULL)
		{
			return true;
		}
		else
			return false;
	}
	void Add(int value, string data = "")
	{
		elements *tmp = new elements;
		tmp->value = value;
		tmp->data = data;
		tmp->next = head;
		head = tmp;
		if (empty_list())
		{
			tail = tmp;
		}
		size++;
	}
	void print()
	{
		elements *f_print = head;
		while (f_print != NULL)
		{
			cout << f_print->value << ' ' << f_print->data.c_str() << ' ';
			f_print = f_print->next;
		}

	}
	void Add_End(int value, string data = "")
	{
		elements *tmp = new elements;
		tmp->value = value;
		tmp->data = data;
		tmp->next = NULL;
		if (empty_list())
		{
			tail = tmp;
			head = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
		size++;
	}
	void Delete(int index)
	{
		if (index < 0 || index >= size || empty_list())
		{
			return;
		}
		else if (index == 0)
		{
			if (head->next != NULL)
			{
				elements *tmp = head->next;
				delete head;
				head = tmp;
			}
			else
			{
				delete head;
				head = NULL;
			}
			size--;
		}
		else
		{
			elements *tmp = head, *for_del;
			for (int i = 0; i < index - 1 && tmp != NULL; i++)
			{
				tmp = tmp->next;
			}
			for_del = tmp->next->next;
			delete tmp->next;
			tmp->next = for_del;
			if (index == size - 1)
				tail = tmp;
		}

	}
	void free()
	{
		elements *tmp;
		while (head != NULL)
		{
			tmp = head->next;
			delete head;
			head = tmp;
		}
	}

	int LookUp(int value)
	{
		elements *f_lookup = head;
		int index = 0;
		while (f_lookup != NULL)
		{
			if (f_lookup->value == value)
			{
				return index;
			}
			f_lookup = f_lookup->next;
			index++;

		}
		return -1;
	}
};
class Stack
{
private:
	elements *tail, *head;
	int size;
public:
	Stack()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	Stack(int value, string data = "")
	{
		elements *new_elem = new elements;
		new_elem->value = value;
		new_elem->data = data;
		head = new_elem;
		tail = new_elem;
		size = 1;
	}
	bool empty_stack()
	{
		if (size == 0 || tail == NULL || head == NULL)
		{
			return true;
		}
		else
			return false;
	}

	void push(int value, string data = "")
	{
		elements *tmp = new elements;
		tmp->value = value;
		tmp->data = data;
		tmp->next = NULL;
		if (empty_stack())
		{
			tail = tmp;
			head = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
		size++;

	}
	void print()
	{
		elements *f_print = head;
		while (f_print != NULL)
		{
			cout << f_print->value << ' ' << f_print->data.c_str() << ' ';
			f_print = f_print->next;
		}
	}
	int pop()
	{
		if (empty_stack())
		{
			return -1;
		}
		else
		{
			elements *tmp = head, *for_del;
			int rem;
			rem = tail->value;
			for (int i = 1; i <= size - 2 && tmp != NULL; i++)
			{
				tmp = tmp->next;
			}
			for_del = tmp->next->next;
			delete tmp->next;
			tmp->next = for_del;
			tail = tmp;
			size--;
			return rem;
		}
	}

};
class Queue
{
private:
	elements *head, *tail;
	int size;
public:
	Queue()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	Queue(int value, string data = "")
	{
		elements *new_elem = new elements;
		new_elem->value = value;
		new_elem->data = data;
		head = new_elem;
		tail = new_elem;
		size = 1;
	}
	bool empty_queue()
	{
		if (size == 0 || tail == NULL || head == NULL)
		{
			return true;
		}
		else
			return false;
	}

	int queue_size()
	{
		return size;
	}
	void queue_enqueue(int value, string data = "")
	{
		elements *tmp = new elements;
		tmp->value = value;
		tmp->data = data;
		tmp->next = NULL;
		if (empty_queue())
		{
			tail = tmp;
			head = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
		size++;

	}
	void print_queue()
	{
		elements *f_print = head;
		while (f_print != NULL)
		{
			cout << f_print->value << ' ' << f_print->data.c_str() << ' ';
			f_print = f_print->next;
		}
	}
	void free()
	{
		elements *tmp;
		while (head != NULL)
		{
			tmp = head->next;
			delete head;
			head = tmp;
		}
	}
	int queue_dequeue()
	{
		if (empty_queue())
		{
			return -1;
		}
		else
		{
			int rem_head;
			rem_head = head->value;
			if (head->next != NULL)
			{

				elements *tmp = head->next;
				delete head;
				head = tmp;
			}
			else
			{
				delete head;
				head = NULL;
			}
			size--;
			return rem_head;
		}
	}
};
class Deck
{
private:
	elements *head, *tail;
	int size;
public:
	Deck()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	Deck(int value, string data = "")
	{
		elements *new_elem = new elements;
		new_elem->value = value;
		new_elem->data = data;
		head = new_elem;
		tail = new_elem;
		size = 1;
	}
	bool empty_deck()
	{
		if (size == 0 || tail == NULL || head == NULL)
		{
			return true;
		}
		else
			return false;
	}
	int deck_size()
	{
		return size;
	}
	void Push_Front(int value, string data = "")
	{
		elements *tmp = new elements;
		tmp->value = value;
		tmp->data = data;
		tmp->next = head;
		head = tmp;
		if (empty_deck())
		{
			tail = tmp;
		}
		size++;
	}
	void Push_End(int value, string data = "")
	{
		elements *tmp = new elements;
		tmp->value = value;
		tmp->data = data;
		tmp->next = NULL;
		if (empty_deck())
		{
			tail = tmp;
			head = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
		size++;
	}
	int Deck_Delete_End()
	{
		if (empty_deck())
		{
			return -1;
		}
		else
		{
			elements *tmp = head;
			int rem;
			rem = tail->value;
			for (int i = 1; i <= size - 2 && tmp != NULL; i++)
			{
				tmp = tmp->next;
			}
			delete tmp->next;
			tail = tmp;
			tmp->next = NULL;
			size--;
			return rem;
		}
	}
	int Delete_Deck()
	{
		if (empty_deck())
		{
			return -1;
		}
		else
		{
			int rem_head;
			rem_head = head->value;
			if (head->next != NULL)
			{

				elements *tmp = head->next;
				delete head;
				head = tmp;
			}
			else
			{
				delete head;
				head = NULL;
			}
			size--;
			return rem_head;
		}
	}
	void print()
	{
		elements *f_print = head;
		while (f_print != NULL)
		{
			cout << f_print->value << ' ' << f_print->data.c_str() << ' ';
			f_print = f_print->next;
		}
	}
};
void main()
{
	int counter = 0, tmp;
	List *MyList = new List();
	for (int i = 1; i < 21; i++)
	{
		MyList->Add_End(i, "A");
	}
	MyList->print();
	cout << endl;
	for (int i = 19; i >= 10; i--)
		MyList->Delete(i);
	MyList->print();
	cout << endl;

	Queue *MyQueue = new Queue();
	int a = MyQueue->queue_size();
	for (int i = 1; i < 11; i++)
	{
		MyQueue->queue_enqueue(i, "A");
	}

	MyQueue->print_queue();
	cout << endl;
	for (int i = 1; i < 6; i++)
	{
		cout << MyQueue->queue_dequeue() << ' ';

	}

	cout << endl;
	Stack *MyStack = new Stack();
	for (int i = 1; i < 9; i++)
	{
		MyStack->push(i, "A");
	}
	MyStack->print();
	cout << endl;
	for (int i = 1; i < 6; i++)
	{
		cout << MyStack->pop() << ' ';
	}
	cout << endl;
	Deck *MyDeck1 = new Deck;
	for (int i = 1; i < 15; i++)
	{
		MyDeck1->Push_Front(i, "A");
	}
	MyDeck1->print();
	cout << endl;

	Deck *MyDeck2 = new Deck;
	while (!MyDeck1->empty_deck())
	{
		tmp = MyDeck1->Deck_Delete_End();
		MyDeck2->Push_Front(tmp);
		counter++;
	}
	while (!MyDeck2->empty_deck())
	{
		tmp = MyDeck2->Deck_Delete_End();
		MyDeck1->Push_Front(tmp);
	}
	cout << counter;
	cout << endl;
	system("pause");
}
