#pragma once
#include <iostream>
#include <exception>
#include "Node.h"
//예시: 연결리스트의 추상자료형
//1. 모든 데이터 출력
//2. 모든 데이터 제거
//3. 인덱스 삽입(원하는 위치에 삽입)
//4. 마지막 삽입(마지막 위치 계산이 필요해서 따로 구현)
//5. 인덱스 삭제
//6. 마지막 삭제
//7. 인덱스 읽기
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
	void ClearAll(); //Delete 구현 후 사용
	void InsertLast(T _newdata);
	T DeleteAt(int _newindex);
	T DeleteLast();
	T GetNodeAt(int index);
private:
	Node<T>* head;  // 연결리스트의 시작노드를 가르키는 헤드
	int count;		// 총 노드의 수를 저장하는 값

};

// 연결리스트의 특정 인덱스 위치에 삽입하려는 함수
// 음수 위치나, 연결리스트보다 지금 크기보다 큰 값을 삽입하려하면 에러 반환
template<class T>
inline void LinkedList<T>::InsertAt(int index, T _data) // 1
{
	if (index > ReturnCount() || index < 0)
	{
		throw std::invalid_argument("범위를 초과함");
	}
	Node<T>*  newNode = new Node<T>(_data, nullptr);
	//newNode->data = _data; 
	// 인덱스 값에 따른 위치 선정
	// 1). 가장 앞부분에 해당할때, head가 되어버림
	// 2). 중간의 해당할 경우 head에서 index값 만큼 계속 참조해서 이동
	if (index == 0) //1)
	{	
		//newNode->link = this->head;
		newNode->SetLink(this->head);
		this->head = newNode;
	}
	else // 2) newNode가 index번째 노드가 되려면
		// index 값만큼 이동
		// newNode가 (구) index번째 노드를 가르켜야함=> (index-1)번째 노드가 가르키는 주소값을 그대로 넣어줌
		// (index-1)번째 노드의 link가 newNode를 주시해야함
		// 코드: currentNode라는 주소값 저장용 변수 생성후 (index-1)번째로 이동, 주소값 변경을 진행
	{
		Node<T>* currentNode = this->head;// 주소 이동을 체크할 변수 생성
		for (int i = 0; i < index - 1; i++)// 목표 index 전까지 이동
		{
			currentNode = currentNode->ReturnLink();
		}// 목표 index -1  도착
		newNode->SetLink(currentNode->ReturnLink());
		currentNode->SetLink(newNode);
		// 하나가 새로 삽입되었으면 전체 수를 증가
	}
	this->count++;
}

template<class T>
inline void LinkedList<T>::PrintAll() // 7
{
	// index를 link를 통해 순회하면서 출력, 마지막 값일때 끝냄
	Node<T>* currentNode = this->head;
	cout << "list 내부 값 출력: " << endl;
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
	// 음수 또는 리스트 크기를 넘어가는 index 
	if (index > ReturnCount() || index < 0)
	{
		throw std::invalid_argument("범위를 초과함");
	}
	Node<T>* currentNode = this->head;
	// 1). 첫번째 노드를 제거하는 상황과
	// 2). 중간 노드를 제거하는 상황을 나눠야함
	if (index == 0) //1)
	{
		Node<T>* deletedNode = this->head;// 삭제될 노드 임시 저장
		T _data = deletedNode->ReturnData(); // 삭제할 데이터 임시 저장
		this->head = this->head->ReturnLink(); // 헤드는 원래 노드의 다음 링크로 연결
		
		delete deletedNode;
		this->count--;
		return _data;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)// 목표 index 전까지 이동
		{
			currentNode = currentNode->ReturnLink();
		}// 목표 index -1 도착
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
		throw std::invalid_argument("범위를 초과함");
	}
	Node<T>* currentNode = this->head;
	for (int i = 0; i < index; i++)// 목표 index 전까지 이동
	{
		currentNode = currentNode->ReturnLink();
	}// 목표 index 도착
	return currentNode->ReturnData();
}
