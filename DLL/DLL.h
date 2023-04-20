#pragma once
#include <iostream>
#include <exception>
#include "Node.h"
// 이중 연결리스트 만들기
// 기존 단방향 연결리스트를 복사한다음 수정한다.
// head말고 tail도 만들고
// tail방향에서 역참조도 가능하도록
// node.h도 양방향 주소를 저장하는 변수를 각각 선언해줌
// getter, setter 추가 및 변경에 따른 전체적인 DLL.h 가 필요
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
	void ClearAll(); //Delete 구현 후 사용
	void InsertLast(T _newdata);
	T DeleteAt(int _newindex);
	T DeleteLast();
	T GetNodeAt(int index);
private:
	Node<T>* head;  // 연결리스트의 시작노드를 가르키는 헤드
	Node<T>* tail;	// 연결리스트의 마지막 노드를 가르키는 헤드
	int count;		// 총 노드의 수를 저장하는 값

};

// 연결리스트의 특정 인덱스 위치에 삽입하려는 함수
// 음수 위치나, 연결리스트보다 지금 크기보다 큰 값을 삽입하려하면 에러 반환
// 이중 연결리스트부턴 tail에 삽입될때 추가되는 부분도 생각해야함
template<class T>
inline void DLL<T>::InsertAt(int index, T _data) // 1
{
	if (index > ReturnCount() || index < 0)
	{
		throw std::invalid_argument("범위를 초과함");
	}
	Node<T>* newNode = new Node<T>(_data, nullptr, nullptr);
	//newNode->data = _data; 
	// 인덱스 값에 따른 위치 선정
	// 1). 가장 앞부분에 해당할때, head가 되어버림
	// 2). 중간의 해당할 경우 head에서 index값 만큼 계속 참조해서 이동
	if (index == 0) //1) + 헤드의 삽입하는 경우 + 아무것도 없는 경우
	{
		newNode->SetNext(this->head);// 아무것도 없을 경우 nullptr, 있을 경우 기존 첫 노드의 주소를 저장
		if (this->head != nullptr)// 기존에 뭔가 있을 경우
		{
			this->head->SetPrev(newNode);// 기존 헤드가 가르키고 있던 (구)노드는 새로 생기는 노드를 가르킴
		}// tail 설정은 밑에 공용으로 해놓음
		// 이때 밀리면서 tail은 그냥 다음 노드와 함께 유지
		this->head = newNode;// 헤드 값 변경
	}
	else if (index == ReturnCount())// tail(마지막)에 삽입하는 경우, index번호가 마지막 번호일 경우
	{
		// 앞뒤 전부 설정해주자
		newNode->SetNext(nullptr);
		newNode->SetPrev(this->tail);// 기존 마지막 노드를 가리킴
		this->tail->SetNext(newNode);
		
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
			currentNode = currentNode->ReturnNext();
		}// 목표 index -1  도착, 목표 인덱스의 이전 노드의 위치
		
		// newNode->SetNext(currentNode->ReturnNext());
		// 새로운 노드는 넣으려는 목표 인덱스의 위치에 넣어야하고
		// 새로운 노드가 가르키는 것은 목표 인덱스의 이전 위치
		newNode->SetNext(currentNode->ReturnNext());// 새로운 노드는 기존노드를 밀어내고
		// 그자리에 들어가니까 이전 노드의 다음 방향, 즉 밀어낸 노드를 가리킨다.
		// 밀린 노드 또한 이전 방향으로 새 노드를 가리킨다.
		currentNode->ReturnNext()->SetPrev(newNode);
		// 이전노드 다음->구노드->의 앞방향은 newNode
		// 이제 목표 이전 노드의 다음 방향은 새 노드를 가리키고
		// 새 노드의 이전 방향은 목표 이전 노드를 가리킨다.
		currentNode->SetNext(newNode);
		newNode->SetPrev(currentNode);
		// 
		
	}

	if (newNode->ReturnNext() == nullptr) // 아무 것도 없었거나 마지막에 삽입했을 경우
	{
		this->tail = newNode;
	}
	// 하나가 새로 삽입되었으면 전체 수를 증가
	this->count++;
}

template<class T>
inline void DLL<T>::PrintAll() // 7
{
	// index를 link를 통해 순회하면서 출력, 마지막 값일때 끝냄
	Node<T>* currentNode = this->head;
	cout << "list 내부 값 출력: " << endl;
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
	// 음수 또는 리스트 크기를 넘어가는 index 
	if (index > ReturnCount() || index < 0)
	{
		throw std::invalid_argument("범위를 초과함");
	}
	Node<T>* currentNode = this->head;
	T _data = 0;
	// 1). 첫번째 노드를 제거하는 상황과
	// 2). 중간 노드를 제거하는 상황을 나눠야함
	if (index == 0) //1)
	{
		Node<T>* deletedNode = this->head;// 삭제될 노드 임시 저장
		_data = deletedNode->ReturnData(); // 삭제할 데이터 임시 저장
		if (this->head->ReturnNext() == nullptr)// 마지막 데이터 인지 판단해야함
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
		else // 두개 이상일때 
		{
			this->head = this->head->ReturnNext(); // head는 head의 다음 노드를 가르킴
			this->head->SetPrev(nullptr); // 새로운 head가 된 node의 이전 연결을 끊어줘야 함
			 
		}
		this->head = this->head->ReturnNext(); // 헤드는 원래 노드의 다음 링크로 연결

		delete deletedNode; // 동적할당 해제
		
	}
	else if (index == this->count - 1) // 마지막(tail) 에서 삭제되는 경우도 고려해줘야함
	{
		Node<T>* deletedNode = this->tail;
		_data = deletedNode->ReturnData();
		this->tail = this->tail->ReturnPrev();
		this->tail->SetNext(nullptr);
		delete deletedNode;
		
	}
	else // 중간 노드를 제거하는 경우
	{
		for (int i = 0; i < index - 1; i++)// 목표 index 전까지 이동
		{
			currentNode = currentNode->ReturnNext();
		}// 목표 index -1 도착
		Node<T>* deletedNode = currentNode->ReturnNext();
		
		_data = deletedNode->ReturnData();

		deletedNode->ReturnNext()->SetPrev(currentNode);// 삭제 노드의 다음 노드의 이전 방향을
		// 삭제 이전 노드로 연결
		currentNode->SetNext(deletedNode->ReturnNext());  // 삭제 노드의 이전 노드의 다음 방향을
		// 삭제 다음 노드로 연결
		
		delete deletedNode; // 삭제노드 해제
		
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
		throw std::invalid_argument("범위를 초과함");
	}
	Node<T>* currentNode = this->head;
	for (int i = 0; i < index; i++)// 목표 index 전까지 이동
	{
		currentNode = currentNode->ReturnNext();
	}// 목표 index 도착
	return currentNode->ReturnData();
}
