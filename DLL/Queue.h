#pragma once
#include "DLL.h"
#include "Node.h"
#include <exception>


// Queue 구현하기
// 1. Enqueue()
// 2. Dequeue()
// 3. Front()
// 4. Isempty()
template<class T>
class Queue
{
public:
	Queue() {};
	void Enqueue(T _data);
	T Dequeue();
	T Front();
	bool IsEmpty();
private:
	DLL<T> dll;
};

template<class T>
inline void Queue<T>::Enqueue(T _data)
{
	this->dll.InsertAt(0, _data);
}

template<class T>
inline T Queue<T>::Dequeue()
{
	try {
		return this->dll.DeleteLast();
	}
	catch(const exception &e)
	{
		std::cout << "오류 발생: " << e.what() << endl;
	}
	
}

template<class T>
inline T Queue<T>::Front()
{
	try {
		return this->dll.ReturnTail()->ReturnData();
		
	}
	catch (const exception& e)
	{
		std::cout << "오류 발생: " << e.what() << endl;
	}
}

template<class T>
inline bool Queue<T>::IsEmpty()
{
	return (this->dll.ReturnCount() == 0);
}


