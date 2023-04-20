#pragma once
#include <iostream>
#include <exception>
#include "Node.h"
// ���� ���Ḯ��Ʈ �����
// ���� �ܹ��� ���Ḯ��Ʈ�� �����Ѵ��� �����Ѵ�.
// head���� tail�� �����
// tail���⿡�� �������� �����ϵ���
// node.h�� ����� �ּҸ� �����ϴ� ������ ���� ��������
// getter, setter �߰� �� ���濡 ���� ��ü���� DLL.h �� �ʿ�
using namespace std;
template<class T>
class DLL
{
public:
	DLL() { this->count = 0; this->head = nullptr; this->tail = nullptr; }
	void SetHead(Node<T>* _newhead) { this->head = _newhead; }
	void SetTail(Node<T>* _newtail) { this->tail = _newtail; }
	Node<T>* ReturnHead() { return this->head; }
	Node<T>* ReturnTail() { return this->tail; }
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
	Node<T>* tail;	// ���Ḯ��Ʈ�� ������ ��带 ����Ű�� ���
	int count;		// �� ����� ���� �����ϴ� ��

};

// ���Ḯ��Ʈ�� Ư�� �ε��� ��ġ�� �����Ϸ��� �Լ�
// ���� ��ġ��, ���Ḯ��Ʈ���� ���� ũ�⺸�� ū ���� �����Ϸ��ϸ� ���� ��ȯ
// ���� ���Ḯ��Ʈ���� tail�� ���Եɶ� �߰��Ǵ� �κе� �����ؾ���
template<class T>
inline void DLL<T>::InsertAt(int index, T _data) // 1
{
	if (index > ReturnCount() || index < 0)
	{
		throw std::invalid_argument("������ �ʰ���");
	}
	Node<T>* newNode = new Node<T>(_data, nullptr, nullptr);
	//newNode->data = _data; 
	// �ε��� ���� ���� ��ġ ����
	// 1). ���� �պκп� �ش��Ҷ�, head�� �Ǿ����
	// 2). �߰��� �ش��� ��� head���� index�� ��ŭ ��� �����ؼ� �̵�
	if (index == 0) //1) + ����� �����ϴ� ��� + �ƹ��͵� ���� ���
	{
		newNode->SetNext(this->head);// �ƹ��͵� ���� ��� nullptr, ���� ��� ���� ù ����� �ּҸ� ����
		if (this->head != nullptr)// ������ ���� ���� ���
		{
			this->head->SetPrev(newNode);// ���� ��尡 ����Ű�� �ִ� (��)���� ���� ����� ��带 ����Ŵ
		}// tail ������ �ؿ� �������� �س���
		// �̶� �и��鼭 tail�� �׳� ���� ���� �Բ� ����
		this->head = newNode;// ��� �� ����
	}
	else if (index == ReturnCount())// tail(������)�� �����ϴ� ���, index��ȣ�� ������ ��ȣ�� ���
	{
		// �յ� ���� ����������
		newNode->SetNext(nullptr);
		newNode->SetPrev(this->tail);// ���� ������ ��带 ����Ŵ
		this->tail->SetNext(newNode);
		
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
			currentNode = currentNode->ReturnNext();
		}// ��ǥ index -1  ����, ��ǥ �ε����� ���� ����� ��ġ
		
		// newNode->SetNext(currentNode->ReturnNext());
		// ���ο� ���� �������� ��ǥ �ε����� ��ġ�� �־���ϰ�
		// ���ο� ��尡 ����Ű�� ���� ��ǥ �ε����� ���� ��ġ
		newNode->SetNext(currentNode->ReturnNext());// ���ο� ���� ������带 �о��
		// ���ڸ��� ���ϱ� ���� ����� ���� ����, �� �о ��带 ����Ų��.
		// �и� ��� ���� ���� �������� �� ��带 ����Ų��.
		currentNode->ReturnNext()->SetPrev(newNode);
		// ������� ����->�����->�� �չ����� newNode
		// ���� ��ǥ ���� ����� ���� ������ �� ��带 ����Ű��
		// �� ����� ���� ������ ��ǥ ���� ��带 ����Ų��.
		currentNode->SetNext(newNode);
		newNode->SetPrev(currentNode);
		// 
		
	}

	if (newNode->ReturnNext() == nullptr) // �ƹ� �͵� �����ų� �������� �������� ���
	{
		this->tail = newNode;
	}
	// �ϳ��� ���� ���ԵǾ����� ��ü ���� ����
	this->count++;
}

template<class T>
inline void DLL<T>::PrintAll() // 7
{
	// index�� link�� ���� ��ȸ�ϸ鼭 ���, ������ ���϶� ����
	Node<T>* currentNode = this->head;
	cout << "list ���� �� ���: " << endl;
	cout << " [ ";
	while (currentNode != nullptr)
	{
		cout << currentNode->ReturnData();
		currentNode = currentNode->ReturnNext();
		if (currentNode != nullptr)
		{
			cout << " -> ";
		}
	}
	cout << " ]" << endl;

}

template<class T>
inline void DLL<T>::ClearAll()
{

}

template<class T>
inline void DLL<T>::InsertLast(T _newdata)
{
	this->InsertAt(this->count, _newdata);
}

template<class T>
inline T DLL<T>::DeleteAt(int index)
{
	// ���� �Ǵ� ����Ʈ ũ�⸦ �Ѿ�� index 
	if (index > ReturnCount() || index < 0)
	{
		throw std::invalid_argument("������ �ʰ���");
	}
	Node<T>* currentNode = this->head;
	T _data = 0;
	// 1). ù��° ��带 �����ϴ� ��Ȳ��
	// 2). �߰� ��带 �����ϴ� ��Ȳ�� ��������
	if (index == 0) //1)
	{
		Node<T>* deletedNode = this->head;// ������ ��� �ӽ� ����
		_data = deletedNode->ReturnData(); // ������ ������ �ӽ� ����
		if (this->head->ReturnNext() == nullptr)// ������ ������ ���� �Ǵ��ؾ���
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
		else // �ΰ� �̻��϶� 
		{
			this->head = this->head->ReturnNext(); // head�� head�� ���� ��带 ����Ŵ
			this->head->SetPrev(nullptr); // ���ο� head�� �� node�� ���� ������ ������� ��
			 
		}
		this->head = this->head->ReturnNext(); // ���� ���� ����� ���� ��ũ�� ����

		delete deletedNode; // �����Ҵ� ����
		
	}
	else if (index == this->count - 1) // ������(tail) ���� �����Ǵ� ��쵵 ����������
	{
		Node<T>* deletedNode = this->tail;
		_data = deletedNode->ReturnData();
		this->tail = this->tail->ReturnPrev();
		this->tail->SetNext(nullptr);
		delete deletedNode;
		
	}
	else // �߰� ��带 �����ϴ� ���
	{
		for (int i = 0; i < index - 1; i++)// ��ǥ index ������ �̵�
		{
			currentNode = currentNode->ReturnNext();
		}// ��ǥ index -1 ����
		Node<T>* deletedNode = currentNode->ReturnNext();
		
		_data = deletedNode->ReturnData();

		deletedNode->ReturnNext()->SetPrev(currentNode);// ���� ����� ���� ����� ���� ������
		// ���� ���� ���� ����
		currentNode->SetNext(deletedNode->ReturnNext());  // ���� ����� ���� ����� ���� ������
		// ���� ���� ���� ����
		
		delete deletedNode; // ������� ����
		
	}
	this->count--;
	return _data;
}

template<class T>
inline T DLL<T>::DeleteLast()
{
	return DeleteAt(this->count - 1);

}

template<class T>
inline T DLL<T>::GetNodeAt(int index)
{
	if (index > ReturnCount() || index < 0)
	{
		throw std::invalid_argument("������ �ʰ���");
	}
	Node<T>* currentNode = this->head;
	for (int i = 0; i < index; i++)// ��ǥ index ������ �̵�
	{
		currentNode = currentNode->ReturnNext();
	}// ��ǥ index ����
	return currentNode->ReturnData();
}
