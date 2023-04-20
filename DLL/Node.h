#pragma once
#include <iostream>
#include <stdexcept>
//����: ���Ḯ��Ʈ�� �߻��ڷ���
// ���� ���Ḯ��Ʈ(Doubly Linked List)�� ���� ���
//1. ��� ������ ���
//2. ��� ������ ����
//3. �ε��� ����(���ϴ� ��ġ�� ����)
//4. ������ ����(������ ��ġ ����� �ʿ��ؼ� ���� ����)
//5. �ε��� ����
//6. ������ ����
//7. �ε��� �б�
template<class T>
class Node
{
public:
	Node(T _data, Node<T>* _prev, Node<T>* _next )
		: data(_data), prev(_prev), next(_next)
	{

	}

	void SetPrev(Node<T>* newprev);
	void SetNext(Node<T>* newnext);
	void SetData(T _newdata);

	T ReturnData();

	Node<T>* ReturnPrev();
	Node<T>* ReturnNext();
private:
	T data;

	Node<T>* prev;
	Node<T>* next;
};


template<class T>
inline void Node<T>::SetPrev(Node<T>* newprev)
{
	this->prev = newprev;
}

template<class T>
inline void Node<T>::SetNext(Node<T>* newnext)
{
	this->next = newnext;
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
inline Node<T>* Node<T>::ReturnPrev()
{
	return this->prev;
}

template<class T>
inline Node<T>* Node<T>::ReturnNext()
{
	return this->next;
}
