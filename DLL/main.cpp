#include <iostream>
#include "DLL.h"
#include "Queue.h"
#include "Deque.h"

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
	//dequeue = queue1.Dequeue();
	//if (dequeue.has_value())// if(dequeue){}else{}
	//{
	//	cout << dequeue.value() << endl;
	//}
	//else
	//{
	//	cout << "큐가 비어있어 값을 반환하지 않습니다." << endl;
	//}
	// 지저분한데 dequeue 옵셔널 변수용 함수하나 만드는게 어떤지?
	//cout << queue1.IsEmpty() << endl;
	queue1.Enqueue(9);

	queue1.Enqueue(8);
	queue1.Enqueue(3);

	queue1.Enqueue(2);
	queue1.PrintAll();
	dequeue = queue1.Dequeue();
	if (dequeue.has_value())// if(dequeue){}else{}
	{
		cout << dequeue.value() << endl;
	}
	else
	{
		cout << "큐가 비어있어 값을 반환하지 않습니다." << endl;
	}
	queue1.PrintAll();
	cout<< "-----------------덱 테스트-------------------"  << endl;

	Deque<int> deque1;

	deque1.AddFirst(5);
	deque1.AddLast(2);
	deque1.AddFirst(9);
	deque1.AddLast(8);
	deque1.PrintAll();
	
	//auto remove = deque1.RemoveLast();
	//if (remove.has_value())// if(dequeue){}else{}
	//{
	//	cout << remove.value() << endl;
	//}
	//else
	//{
	//	cout << "덱이 비어있어 값을 반환하지 않습니다." << endl;
	//}
	// 해당 과정을 이렇게 줄여보았다. 함수포인터를 사용해봄
	deque1.OptionalPrint(&Deque<int>::RemoveFirst,deque1);
	// 해당 과정을 std::function과 std::bind를 사용해보기
	// 멤버함수를 넘겨주면서 해당 멤버함수를 사용할 객체 함께 넘겨줘야함
	// 이때 해당 객체와 사용할 멤버함수를 std::bind를 통해
	// 묶어서 전달해준다.
	deque1.OptionalPrint_stdfunction(std::bind(&Deque<int>::RemoveFirst, &deque1), deque1);
	// 람다형으로 변환 예시도 사용해본다.
	deque1.OptionalPrint_lambda([&deque1]() {return deque1.RemoveLast(); }, deque1);
	deque1.OptionalPrint_lambda([&deque1]() {return deque1.RemoveFirst(); }, deque1);
	deque1.OptionalPrint_lambda([&deque1]() {return deque1.RemoveFirst(); }, deque1); // 오류 출력


	//remove = deque1.RemoveLast();
	//if (remove.has_value())// if(dequeue){}else{}
	//{
	//	cout << remove.value() << endl;
	//}
	//else
	//{
	//	cout << "덱이 비어있어 값을 반환하지 않습니다." << endl;
	//}
	
}