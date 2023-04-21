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
	queue1.Enqueue(8);
	cout << queue1.IsEmpty() << endl;
	auto dequeue = queue1.Dequeue();
	if (dequeue.has_value())// if(dequeue){}else{}
	{
		cout << dequeue.value()<< endl;
	}
	else
	{
		cout << "큐가 비어있어 값을 반환하지 않습니다." << endl;
	}
	dequeue = queue1.Front();
	if (dequeue)
	{
		cout << "성공로그" << endl;
		cout << dequeue.value() << endl;
	}
	else
	{
		cout << "실패로그" << endl;
		cout << "큐가 비어있어 값을 반환하지 않습니다." << endl;
	}
	queue1.Enqueue(9);
	
	queue1.Enqueue(8);
	dequeue = queue1.Dequeue();
	if (dequeue.has_value())// if(dequeue){}else{}
	{
		cout << dequeue.value() << endl;
	}
	else
	{
		cout << "큐가 비어있어 값을 반환하지 않습니다." << endl;
	}
	dequeue = queue1.Dequeue();
	if (dequeue.has_value())// if(dequeue){}else{}
	{
		cout << dequeue.value() << endl;
	}
	else
	{
		cout << "큐가 비어있어 값을 반환하지 않습니다." << endl;
	}
	dequeue = queue1.Dequeue();
	if (dequeue.has_value())// if(dequeue){}else{}
	{
		cout << dequeue.value() << endl;
	}
	else
	{
		cout << "큐가 비어있어 값을 반환하지 않습니다." << endl;
	}
	// 지저분한데 dequeue 옵셔널 변수용 함수하나 만드는게 어떤지?
	//cout << queue1.IsEmpty() << endl;

}