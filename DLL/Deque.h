#pragma once
#include "DLL.h"
#include "Node.h"
#include <exception>
#include <optional>// C++17 이상에서 std 포함됨
#include <functional>

//ADT
// PrintAll 모두 출력
// addFirst
// removeFirst 헤드에서 제거
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
	void OptionalPrint_stdfunction(std::function<optional<T>()> _RemoveFunc, Deque& _deque);//std::function 사용해보기
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
	// 함수 재귀호출보단 바로 쓰는게 더 좋을까?
	//this->dll.InsertAt(this->dll.ReturnCount(), _data);
	// 근데 결국 순회하게됨
	this->dll.InsertLast(_data);
	// 순회 없이 직접 포인터 this->tail이 가르키는 곳에 넣도록 수정
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
		std::cout << "오류 발생: " << e.what() << endl;
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
		std::cout << "오류 발생: " << e.what() << endl;
		return std::nullopt;
	}
}

template<class T>
inline bool Deque<T>::IsEmpty()
{
	return (this->dll.ReturnCount() == 0);
}

// Optional 함수의 조건문을 수행해 주는 함수
template<class T>
inline void Deque<T>::OptionalPrint(std::optional<T> (Deque<T>::* RemoveFunc)(), Deque& _deque)
{
	// 제거하는 optional 함수를 파라미터를 받아
	// 해당 함수의 실행 값을 옵셔널 변수의 저장 제거 실행 결과를 받아서
	// 반환 가능했을 경우 반환값 출력
	// 안될 경우 에러 코드 를 출력하는 함수
	auto remove = (_deque.*RemoveFunc)();
	if (remove.has_value())// if(dequeue){}else{}
	{
		cout << remove.value() << endl;
	}
	else
	{
		cout << "덱이 비어있어 값을 반환하지 않습니다." << endl;
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
		cout << "덱이 비어있어 값을 반환하지 않습니다." << endl;
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
		cout << "덱이 비어있어 값을 반환하지 않습니다." << endl;
	}
}