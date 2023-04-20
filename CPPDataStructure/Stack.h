#pragma once
#include <iostream>
#include <exception>
#include "LinkedList.h"
// Stack�� �߻� �ڷ���
// 1. ������ ����
// 2. ������ ����
// 3. ������ ����: ���� ������ ����(TOP) ������ ���빰�� ����
// 4. isEmpty(): ������ ������� �˻�
using namespace std;

template<class T>
class Stack
{
public:
	LinkedList<T> list;
	Stack();
	void Push(T _data);
	T Pop();
	T Peek();
	bool IsEmpty();
};

template<class T>
inline Stack<T>::Stack()
{
	
}

// ������ �׻� ���Ḯ��Ʈ�� �տ� �����ϱ� �׻� index�� 0�̴�.
template<class T>
inline void Stack<T>::Push(T _data)
{
	this->list.InsertAt(0, _data);
}

template<class T>
inline T Stack<T>::Pop()
{
	try {
		return this->list.DeleteAt(0);
	}
	catch (const exception &e)
	{
		std::cout << "���� �߻�: " << e.what() << endl;
	}
	
}

template<class T>
inline T Stack<T>::Peek()
{
	try {
		return this->list.GetNodeAt(0);
	}
	catch (const exception& e)
	{
		std::cout << "���� �߻�: " << e.what() << endl;
	}
}

template<class T>
inline bool Stack<T>::IsEmpty()
{
	return (this->list.ReturnCount() == 0);
}

