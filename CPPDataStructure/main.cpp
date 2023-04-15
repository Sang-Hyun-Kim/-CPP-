#include <iostream>
#include "LinkedList.h"


int main()
{
	LinkedList<int> list1;
	
	// list1.Insertat(1, 1); // 범위초과 출력
	list1.InsertAt(0, 1);
	list1.InsertAt(0, 2);
	list1.InsertAt(1, 3);
	list1.InsertAt(3, 4);
	list1.InsertAt(2, 5);
	list1.InsertAt(0, 6);
	cout << list1.ReturnCount() << endl; // 1증가
	list1.PrintAll();
	list1.InsertLast(3);
	list1.InsertLast(8);
	list1.InsertLast(6);
	cout << list1.ReturnCount() << endl; // 1증가
	list1.PrintAll();

	list1.DeleteAt(3);
	cout << list1.ReturnCount() << endl; // 1증가
	list1.PrintAll();
	list1.DeleteAt(0);
	cout << list1.ReturnCount() << endl; // 1증가
	list1.PrintAll();
	list1.DeleteAt(5);
	cout << list1.ReturnCount() << endl; // 1증가
	list1.PrintAll();
	list1.DeleteLast();
	cout << list1.ReturnCount() << endl; // 1증가
	list1.PrintAll();
	list1.DeleteLast();
	cout << list1.ReturnCount() << endl; // 1증가
	list1.PrintAll();
	list1.GetNodeAt(list1.ReturnCount()-1);
	list1.GetNodeAt(list1.ReturnCount() - 2);
}