#pragma once
#include "DLL.h"
#include "Node.h"
#include <exception>
#include <optional>// C++17 이상에서 std 포함됨

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
	optional<T> Dequeue();
	optional<T> Front();
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
inline optional<T> Queue<T>::Dequeue()
{
	/*T _data; // 오류 발생하면 어떻게든 반환값을 반환하려는 T Dequeue()를 수정하려고
				// C++ 17의 optional 라이브러리를 알게되어 사용해봤다.
	try {
		return this->dll.DeleteLast();
	}
	catch(const exception &e)
	{
		std::cout << "오류 발생: " << e.what() << endl;
	}
	*/
	try {
		T data = this->dll.DeleteLast();
		return data;
	}
	catch (const std::exception& e)
	{
		std::cout << "오류 발생: " << e.what() << endl;
		return std::nullopt;
	}
}

template<class T>
inline optional<T> Queue<T>::Front()
{
	try {
		optional<Node<T>*> nodelink;
		nodelink = this->dll.ReturnTail();
		if (nodelink)
		{
			T data = nodelink.value()->ReturnData();
			return data;
		}
		else
		{
			return std::nullopt;
		}
		//T data = this->dll.ReturnTail()->ReturnData();
		
	}
	catch (const std::exception& e)
	{
		std::cout << "오류 발생: " << e.what() << endl;
		return std::nullopt;// 오류 발생하면 어떻게든 반환값을 반환하려는 T Dequeue()를 수정하려고
		// C++ 17의 optional 라이브러리를 알게되어 사용해봤다.
	}
}

template<class T>
inline bool Queue<T>::IsEmpty()
{
	return (this->dll.ReturnCount() == 0);
}


