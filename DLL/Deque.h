#pragma once
#include "DLL.h"
#include "Node.h"
#include <exception>
#include <optional>// C++17 �̻󿡼� std ���Ե�
#include <functional>

//ADT
// PrintAll ��� ���
// addFirst
// removeFirst ��忡�� ����
// addLast
// removeLast
// IsEmpty
template<class T>
class Deque
{
public:
	Deque() {};
	void  PrintAll();
	void AddFirst(T _data);
	void AddLast(T _data);
	optional<T> RemoveFirst();
	optional<T> RemoveLast();
	bool IsEmpty();
	void OptionalPrint(std::optional<T>(Deque<T>::* RemoveFunc)(), Deque& _deque);
	void OptionalPrint_stdfunction(std::function<optional<T>()> _RemoveFunc, Deque& _deque);//std::function ����غ���
	void OptionalPrint_lambda(function<optional<T>()> _RemoveFunc, Deque& deque);
private:
	DLL<T> dll;
};

template<class T>
inline void Deque<T>::PrintAll()
{
	return this->dll.PrintAll();
}

template<class T>
inline void Deque<T>::AddFirst(T _data)
{
	this->dll.InsertAt(0,_data);
}

template<class T>
inline void Deque<T>::AddLast(T _data)
{
	//this->dll.InsertLast(_data);
	// �Լ� ���ȣ�⺸�� �ٷ� ���°� �� ������?
	//this->dll.InsertAt(this->dll.ReturnCount(), _data);
	// �ٵ� �ᱹ ��ȸ�ϰԵ�
	this->dll.InsertLast(_data);
	// ��ȸ ���� ���� ������ this->tail�� ����Ű�� ���� �ֵ��� ����
}

template<class T>
inline optional<T> Deque<T>::RemoveFirst()
{
	try {
		T data = this->dll.DeleteAt(0);
		return data;
	}
	catch (const std::exception& e)
	{
		std::cout << "���� �߻�: " << e.what() << endl;
		return std::nullopt;
	}
}

template<class T>
inline optional<T> Deque<T>::RemoveLast()
{
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
inline bool Deque<T>::IsEmpty()
{
	return (this->dll.ReturnCount() == 0);
}

// Optional �Լ��� ���ǹ��� ������ �ִ� �Լ�
template<class T>
inline void Deque<T>::OptionalPrint(std::optional<T> (Deque<T>::* RemoveFunc)(), Deque& _deque)
{
	// �����ϴ� optional �Լ��� �Ķ���͸� �޾�
	// �ش� �Լ��� ���� ���� �ɼų� ������ ���� ���� ���� ����� �޾Ƽ�
	// ��ȯ �������� ��� ��ȯ�� ���
	// �ȵ� ��� ���� �ڵ� �� ����ϴ� �Լ�
	auto remove = (_deque.*RemoveFunc)();
	if (remove.has_value())// if(dequeue){}else{}
	{
		cout << remove.value() << endl;
	}
	else
	{
		cout << "���� ����־� ���� ��ȯ���� �ʽ��ϴ�." << endl;
	}

}

template<class T>
inline void Deque<T>::OptionalPrint_stdfunction(std::function<optional<T>()> _RemoveFunc, Deque& _deque)
{
	auto remove = _RemoveFunc();
	if (remove.has_value())// if(dequeue){}else{}
	{
		cout << remove.value() << endl;
	}
	else
	{
		cout << "���� ����־� ���� ��ȯ���� �ʽ��ϴ�." << endl;
	}
}

template<class T>
inline void Deque<T>::OptionalPrint_lambda(function<optional<T>()> _RemoveFunc, Deque& deque)
{
	auto remove = _RemoveFunc();
	if (remove.has_value())
	{
		cout << remove.value() << endl;
	}
	else
	{
		cout << "���� ����־� ���� ��ȯ���� �ʽ��ϴ�." << endl;
	}
}