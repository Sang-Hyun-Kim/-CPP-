#pragma once
#include <iostream>
#include <exception>
#include "Node.h"
//����: ���Ḯ��Ʈ�� �߻��ڷ���
//1. ��� ������ ���
//2. ��� ������ ����
//3. �ε��� ����(���ϴ� ��ġ�� ����)
//4. ������ ����(������ ��ġ ����� �ʿ��ؼ� ���� ����)
//5. �ε��� ����
//6. ������ ����
//7. �ε��� �б�
using namespace std;
template<class T>
class LinkedList
{
public:
	LinkedList() { this->count = 0; this->head = nullptr; };
	void SetHead(Node<T>* _newHead) { this->head = _newHead; }
	Node<T>* ReturnHead() { return this->head; }
	/*void PlusCount() { this->count++; }
	void MinusCount() { this->count--; }*/
	int ReturnCount() { return this->count; }
	void InsertAt(int index, T _count);
	//void Init() { this->count = 0; this->head = nullptr; }
	void PrintAll();
	void ClearAll(); //Delete ���� �� ���
	void InsertLast(T _newdata);
	T DeleteAt(int _newindex);
	T DeleteLast();
	T GetNodeAt(int index);
private:
	Node<T>* head;  // ���Ḯ��Ʈ�� ���۳�带 ����Ű�� ���
	int count;		// �� ����� ���� �����ϴ� ��

};

// ���Ḯ��Ʈ�� Ư�� �ε��� ��ġ�� �����Ϸ��� �Լ�
// ���� ��ġ��, ���Ḯ��Ʈ���� ���� ũ�⺸�� ū ���� �����Ϸ��ϸ� ���� ��ȯ
template<class T>
inline void LinkedList<T>::InsertAt(int index, T _data) // 1
{
	if (index > ReturnCount() || index < 0)
	{
		throw std::invalid_argument("������ �ʰ���");
	}
	Node<T>*  newNode = new Node<T>(_data, nullptr);
	//newNode->data = _data; 
	// �ε��� ���� ���� ��ġ ����
	// 1). ���� �պκп� �ش��Ҷ�, head�� �Ǿ����
	// 2). �߰��� �ش��� ��� head���� index�� ��ŭ ��� �����ؼ� �̵�
	if (index == 0) //1)
	{	
		//newNode->link = this->head;
		newNode->SetLink(this->head);
		this->head = newNode;
	}
	else // 2) newNode�� index��° ��尡 �Ƿ���
		// index ����ŭ �̵�
		// newNode�� (��) index��° ��带 �����Ѿ���=> (index-1)��° ��尡 ����Ű�� �ּҰ��� �״�� �־���
		// (index-1)��° ����� link�� newNode�� �ֽ��ؾ���
		// �ڵ�: currentNode��� �ּҰ� ����� ���� ������ (index-1)��°�� �̵�, �ּҰ� ������ ����
	{
		Node<T>* currentNode = this->head;// �ּ� �̵��� üũ�� ���� ����
		for (int i = 0; i < index - 1; i++)// ��ǥ index ������ �̵�
		{
			currentNode = currentNode->ReturnLink();
		}// ��ǥ index -1  ����
		newNode->SetLink(currentNode->ReturnLink());
		currentNode->SetLink(newNode);
		// �ϳ��� ���� ���ԵǾ����� ��ü ���� ����
	}
	this->count++;
}

template<class T>
inline void LinkedList<T>::PrintAll() // 7
{
	// index�� link�� ���� ��ȸ�ϸ鼭 ���, ������ ���϶� ����
	Node<T>* currentNode = this->head;
	cout << "list ���� �� ���: " << endl;
	cout << " [ ";
	while (currentNode != nullptr)
	{
		cout << currentNode->ReturnData();
		currentNode = currentNode->ReturnLink();
		if (currentNode != nullptr)
		{
			cout << " -> ";
		}
	}
	cout << " ]" << endl;
	
}

template<class T>
inline void LinkedList<T>::ClearAll()
{
	
}

template<class T>
inline void LinkedList<T>::InsertLast(T _newdata)
{
	this->InsertAt(this->count, _newdata);
}

template<class T>
inline T LinkedList<T>::DeleteAt(int index)
{
	// ���� �Ǵ� ����Ʈ ũ�⸦ �Ѿ�� index 
	if (index > ReturnCount() || index < 0)
	{
		throw std::invalid_argument("������ �ʰ���");
	}
	Node<T>* currentNode = this->head;
	// 1). ù��° ��带 �����ϴ� ��Ȳ��
	// 2). �߰� ��带 �����ϴ� ��Ȳ�� ��������
	if (index == 0) //1)
	{
		Node<T>* deletedNode = this->head;// ������ ��� �ӽ� ����
		T _data = deletedNode->ReturnData(); // ������ ������ �ӽ� ����
		this->head = this->head->ReturnLink(); // ���� ���� ����� ���� ��ũ�� ����
		
		delete deletedNode;
		this->count--;
		return _data;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)// ��ǥ index ������ �̵�
		{
			currentNode = currentNode->ReturnLink();
		}// ��ǥ index -1 ����
		Node<T>* deletedNode = currentNode->ReturnLink();
		T _data = deletedNode->ReturnData();
		currentNode->SetLink(deletedNode->ReturnLink()); 
		delete deletedNode;
		this->count--;
		return _data;
	}

}

template<class T>
inline T LinkedList<T>::DeleteLast()
{
	return DeleteAt(this->count - 1);

}

template<class T>
inline T LinkedList<T>::GetNodeAt(int index)
{
	if (index > ReturnCount() || index < 0)
	{
		throw std::invalid_argument("������ �ʰ���");
	}
	Node<T>* currentNode = this->head;
	for (int i = 0; i < index; i++)// ��ǥ index ������ �̵�
	{
		currentNode = currentNode->ReturnLink();
	}// ��ǥ index ����
	return currentNode->ReturnData();
}
