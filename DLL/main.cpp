#include <iostream>
#include "DLL.h"
#include "Queue.h"

int main()
{
	//DLL<int> dll1;
	//dll1.InsertAt(0,1);
	//dll1.InsertAt(1, 2);
	//dll1.InsertAt(1, 5);
	//dll1.InsertAt(2, 3);
	//dll1.InsertLast(4);

	//dll1.PrintAll();

	//cout <<dll1.DeleteAt(3) << endl;
	//cout << dll1.DeleteLast() << endl;
	//cout << dll1.GetNodeAt(2) << endl;
	//cout << dll1.GetNodeAt(1) << endl;
	//
	//dll1.PrintAll();
	cout << boolalpha;
	Queue<int> queue1;
	cout << queue1.IsEmpty() << endl;
	
	queue1.Enqueue(9);
	queue1.Enqueue(6);
	queue1.Enqueue(0);
	queue1.Enqueue(3);
	queue1.Enqueue(2);
	queue1.Enqueue(2);
	
	cout << queue1.IsEmpty() << endl;
	cout << queue1.Front() << endl;
	cout << queue1.Dequeue() << endl;
	cout << queue1.Front() << endl;
	cout << queue1.Dequeue() << endl;
	cout << queue1.Dequeue() << endl;
	cout << queue1.Dequeue() << endl;
	cout << queue1.Dequeue() << endl;
	cout << queue1.Dequeue() << endl;
	cout << queue1.IsEmpty() << endl;

}