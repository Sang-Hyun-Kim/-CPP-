#pragma once
#include <iostream>
#include <exception>
#include "LinkedList.h"
// Stack의 추상 자료형
// 1. 데이터 삽입
// 2. 데이터 제거
// 3. 데이터 참조: 가장 마지막 삽입(TOP) 데이터 내용물만 참조
// 4. isEmpty(): 스택이 비었는지 검사
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

// 스택은 항상 연결리스트의 앞에 넣으니까 항상 index는 0이다.
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
		std::cout << "오류 발생: " << e.what() << endl;
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
		std::cout << "오류 발생: " << e.what() << endl;
	}
}

template<class T>
inline bool Stack<T>::IsEmpty()
{
	return (this->list.ReturnCount() == 0);
}

