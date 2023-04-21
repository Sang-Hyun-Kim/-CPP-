#pragma once
#include "DLL.h"
#include "Node.h"
#include <exception>
#include <optional>// C++17 �̻󿡼� std ���Ե�

// Queue �����ϱ�
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
	/*T _data; // ���� �߻��ϸ� ��Ե� ��ȯ���� ��ȯ�Ϸ��� T Dequeue()�� �����Ϸ���
				// C++ 17�� optional ���̺귯���� �˰ԵǾ� ����غô�.
	try {
		return this->dll.DeleteLast();
	}
	catch(const exception &e)
	{
		std::cout << "���� �߻�: " << e.what() << endl;
	}
	*/
	try {
		T data = this->dll.DeleteLast();
		return data;
	}
	catch (const std::exception& e)
	{
		std::cout << "���� �߻�: " << e.what() << endl;
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
		std::cout << "���� �߻�: " << e.what() << endl;
		return std::nullopt;// ���� �߻��ϸ� ��Ե� ��ȯ���� ��ȯ�Ϸ��� T Dequeue()�� �����Ϸ���
		// C++ 17�� optional ���̺귯���� �˰ԵǾ� ����غô�.
	}
}

template<class T>
inline bool Queue<T>::IsEmpty()
{
	return (this->dll.ReturnCount() == 0);
}


