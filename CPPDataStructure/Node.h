#pragma once
#include <iostream>
#include <stdexcept>
//예시: 연결리스트의 추상자료형
//1. 모든 데이터 출력
//2. 모든 데이터 제거
//3. 인덱스 삽입(원하는 위치에 삽입)
//4. 마지막 삽입(마지막 위치 계산이 필요해서 따로 구현)
//5. 인덱스 삭제
//6. 마지막 삭제
//7. 인덱스 읽기
template<class T>
class Node
{
public:
	Node(T _data, Node<T>* _link)
		: data(_data), link(_link)
	{

	}
	void SetLink(Node<T>* newlink);
	void SetData(T _newdata);
	T ReturnData();
	Node<T>* ReturnLink();
private:
	T data;
	Node<T>* link;
};

template<class T>
inline void Node<T>::SetLink(Node<T>* _newlink)
{
	this->link = _newlink;
}

template<class T>
inline void Node<T>::SetData(T _newdata)
{
	this->data = _newdata;
}

template<class T>
inline T Node<T>::ReturnData()
{
	return this->data;
}

template<class T>
inline Node<T>* Node<T>::ReturnLink()
{
	return this->link;
}
