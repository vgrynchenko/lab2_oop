#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"
#include "StaticArray.h"
#include "LinkedDeque.h"

#include <string>
using namespace std;

void main() {
	setlocale(LC_ALL, "ru");

	/*LinkedList *my_lst = new LinkedList();*/
	/*cout << "Is Empty: " << my_lst->IsEmpty() << "\n";
	for (int i = 0; i < 10; i++)
		my_lst->Insert(i, i);
	cout << my_lst->ToString() << "\nSize: " << my_lst->Size() << "\nIs Empty: " << my_lst->IsEmpty() << "\n";
	my_lst->Insert(5, 21);
	cout << my_lst->ToString()<< "\nSize: " << my_lst->Size() << "\nIs Empty: " << my_lst->IsEmpty() << "\n";
	my_lst->Remove(5);
	cout << my_lst->ToString() << "\nSize: " << my_lst->Size() << "\nIs Empty: " << my_lst->IsEmpty() << "\n";
	for (int i = 0; i < 10; i++)
		cout << my_lst->Get(i) << " ";
	cout << "\n";
	for (int i = 0; i < 10; i++) {
		my_lst->Set(i, 7);
		cout << my_lst->ToString() << "\n";
	}
	for (int i = 0; i < 10; i++)
		cout << my_lst->Pop() << "\n";
		cout << my_lst->ToString()<< "\nSize: " << my_lst->Size() << "\n";*/

		/*Queue*my_que = new Queue();
		cout << "Is Empty: " << my_que->IsEmpty() << "\n";
		for (int i = 0; i < 10; i++)
			my_que->Push(i);
			cout << my_que->Pop() << "\n";
			cout << my_que->Peek()<< "\n";
			cout << my_que->ToString().c_str() << "\nSize: " << my_que->Size() << "\n";
		StaticArray* my_Arr = new StaticArray (10,6);
		cout << my_Arr->ToString() << "\nSize: " << my_Arr->Size() << "\nIs Empty: " << my_Arr->IsEmpty() << "\n";
		for (int i = 0; i < 10; i++)
			cout << my_Arr->Get(i) << " ";
		cout << "\n";
			my_Arr->Set(6, 7);
			cout << my_Arr->ToString() << "\nSize: " << my_Arr->Size() << "\n";*/
			/*PushPopContainer *elem[3];
			elem[0] = new Stack();
			elem[1] = new Queue();
			elem[2] = new LinkedList ();

			for (int i = 0; i < 3; i++)
			{
				elem[i]->Push(1);
				cout << elem[i]->ToString() << "\n";

				elem[i]->Push(2);
				cout << elem[i]->ToString() << "\n";
				elem[i]->Push(3);
				cout << elem[i]->ToString() << "\n";


			}*/
			/*for (int i = 0; i < 3; i++)
			{
				elem[i]->Pop();
				cout<< elem[i]->ToString() <<"\n";
			}*/
	Container *elem[3];
	elem[0] = new Stack();
	elem[1] = new StaticArray(5, 0);
	elem[2] = new LinkedList();
	for (int i = 0; i < 3; i++)
	{
		InsertableContainer *Insertable = dynamic_cast <InsertableContainer*>(elem[i]);
		if (Insertable != NULL)
		{
			if (Insertable->Insert(1, 10))
			{
				cout << "Inserted!" << endl;
			}
			else
				cout << "Error" << endl;
			//Insertable->Insert(1, 10);
			//cout << "!" << Insertable->ToString() << endl;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		IndexedContainer *Indexed = dynamic_cast <IndexedContainer*>(elem[i]);
		if (elem[i]->Size() < 4)
		{
			continue;
		}
		if (Indexed != NULL)
		{
			cout << Indexed->Get(3) << endl;
			Indexed->Set(3, 20);
			cout << Indexed->Get(3) << endl;

		}
	}

	Deque *deque = new LinkedDeque();
	for (int i = 0; i < 5; i++)
	{
		deque->PushBack(i);
		deque->PushFront(i);
		cout << "*" << deque->ToString() << endl;
	}
	
		while (!deque->IsEmpty())
		{
			cout << deque->PopBack() << endl;
		}




		//cout << my_Arr->ToString().c_str() << "\nSize: " << my_Arr->Size() << "\n";

		system("pause");
}