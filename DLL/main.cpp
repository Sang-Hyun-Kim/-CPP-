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
		cout << "ť�� ����־� ���� ��ȯ���� �ʽ��ϴ�." << endl;
	}
	dequeue = queue1.Front();
	if (dequeue)
	{
		cout << "�����α�" << endl;
		cout << dequeue.value() << endl;
	}
	else
	{
		cout << "���зα�" << endl;
		cout << "ť�� ����־� ���� ��ȯ���� �ʽ��ϴ�." << endl;
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
		cout << "ť�� ����־� ���� ��ȯ���� �ʽ��ϴ�." << endl;
	}
	dequeue = queue1.Dequeue();
	if (dequeue.has_value())// if(dequeue){}else{}
	{
		cout << dequeue.value() << endl;
	}
	else
	{
		cout << "ť�� ����־� ���� ��ȯ���� �ʽ��ϴ�." << endl;
	}
	//dequeue = queue1.Dequeue();
	//if (dequeue.has_value())// if(dequeue){}else{}
	//{
	//	cout << dequeue.value() << endl;
	//}
	//else
	//{
	//	cout << "ť�� ����־� ���� ��ȯ���� �ʽ��ϴ�." << endl;
	//}
	// �������ѵ� dequeue �ɼų� ������ �Լ��ϳ� ����°� ���?
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
		cout << "ť�� ����־� ���� ��ȯ���� �ʽ��ϴ�." << endl;
	}
	queue1.PrintAll();
	cout<< "-----------------�� �׽�Ʈ-------------------"  << endl;

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
	//	cout << "���� ����־� ���� ��ȯ���� �ʽ��ϴ�." << endl;
	//}
	// �ش� ������ �̷��� �ٿ����Ҵ�. �Լ������͸� ����غ�
	deque1.OptionalPrint(&Deque<int>::RemoveFirst,deque1);
	// �ش� ������ std::function�� std::bind�� ����غ���
	// ����Լ��� �Ѱ��ָ鼭 �ش� ����Լ��� ����� ��ü �Բ� �Ѱ������
	// �̶� �ش� ��ü�� ����� ����Լ��� std::bind�� ����
	// ��� �������ش�.
	deque1.OptionalPrint_stdfunction(std::bind(&Deque<int>::RemoveFirst, &deque1), deque1);
	// ���������� ��ȯ ���õ� ����غ���.
	deque1.OptionalPrint_lambda([&deque1]() {return deque1.RemoveLast(); }, deque1);
	deque1.OptionalPrint_lambda([&deque1]() {return deque1.RemoveFirst(); }, deque1);
	deque1.OptionalPrint_lambda([&deque1]() {return deque1.RemoveFirst(); }, deque1); // ���� ���


	//remove = deque1.RemoveLast();
	//if (remove.has_value())// if(dequeue){}else{}
	//{
	//	cout << remove.value() << endl;
	//}
	//else
	//{
	//	cout << "���� ����־� ���� ��ȯ���� �ʽ��ϴ�." << endl;
	//}
	
}