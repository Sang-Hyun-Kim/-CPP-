#pragma once
#include <iostream>
#include <stdexcept>
//����: ���Ḯ��Ʈ�� �߻��ڷ���
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
