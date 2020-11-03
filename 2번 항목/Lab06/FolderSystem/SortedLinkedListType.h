#pragma once
#include<iostream>

using namespace std;

template <typename T>
struct NodeType
{
	T data;
	NodeType<T>* next = nullptr;
};


template <typename T>
class SortedLinkedList {
public:
	SortedLinkedList();												//생성자(m_Length, m_List, m_curPos를 초기화한다)

	SortedLinkedList(const SortedLinkedList<T>& s_l);				//복사생성자(s_l로인해 모든 값이 초기화된다.)

	~SortedLinkedList();											//소멸자(객체내 동적할당 요소들을 전부 할당 해제)

	int Add(T& data);												//리스트 내에 요소 추가함수(성공시 1, 실패시 0 반환)
			
	int Delete(T& data);											//리스트 내에 요소 제거함수(성공시 1, 실패시 0 반환)

	void MakeEmpty();												//리스트 내의 모든 요소 제거함수(객체내 동적할당 요소들을 전부 할당 해제)

	int GetLength();												//리스트 내의 요소 개수 반환함수

	bool IsEmpty();													//리스트가 비었는지 검사하는 함수

	int Get(T& data);												//입력받은 요소와 같은 값을 갖는 요소가 리스트 내에 있는지 검사한다
																	//(있으면 1, 없으면 0반환)

	void GetNext(T& data);											//리스트 내의 요소를 가리키는 m_curPos를 다음 요소를 가르키도록 움직인다.

	void ResetList();												//리스트 내의 요소를 가리키는 m_curPos를 제일 처음 설정으로 되돌린다.
	
	T* GetCurData();												//리스트 내의 Actual Data의 포인터 주소를 반환한다.

	SortedLinkedList<T>* GetList();									//리스트 자신의 포인터 주소를 반환한다.

	SortedLinkedList<T>& operator=(const SortedLinkedList<T>& s_l);	//대입연산자 오버로딩

private:
	int m_Length;													//리스트 내의 요소들의 갯수
	NodeType<T>* m_List;											//리스트의 시작점
	NodeType<T>* m_curPos;											//리스트 내의 요소들을 가리킬 수 있는 포인터
};

//생성자
template <typename T>
SortedLinkedList<T>::SortedLinkedList() {
	m_Length = 0;
	m_List = nullptr;
	m_curPos = nullptr;
}

//복사 생성자
template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T>& s_l) {
	m_Length = s_l.m_Length;
	m_List = nullptr;
	NodeType<T>* itor = s_l.m_List;
	if(itor != nullptr) {
		while (itor != nullptr) {
			NodeType<T>* tempPtr = new NodeType<T>;
			tempPtr->data = itor->data;
			if (m_List == nullptr) {
				m_List = tempPtr;
				m_curPos = tempPtr;
			}
			else {
				m_curPos->next = tempPtr;
				m_curPos = m_curPos->next;
			}
			itor = itor->next;
		}
	}
	m_curPos = nullptr;
}

//소멸자
template <typename T>
SortedLinkedList<T>::~SortedLinkedList() {
	MakeEmpty();
}

//리스트 내에 인자로 받은 데이터 추가
template <typename T>
int SortedLinkedList<T>::Add(T& data) {
	NodeType<T>* node = new NodeType<T>;
	node->data = data;
	node->next = nullptr;
	NodeType<T>* preLoc = nullptr;
	m_curPos = m_List;
	if (IsEmpty()) {
		m_List = node;
		m_Length++;
	}
	else {
		while (m_curPos != nullptr) {
			if (node->data < m_curPos->data) {
				node->next = m_curPos;
				if (preLoc == nullptr) {
					m_List = node;
				}
				else {
					preLoc->next = node;
				}
				m_Length++;
				return 1;
			}
			else {
				preLoc = m_curPos;
				m_curPos = m_curPos->next;
			}
		}
		preLoc->next = node;
		m_Length++;
	}
	return 1;
}

//리스트에서 인자로 받은 데이터 삭제
template <typename T>
int SortedLinkedList<T>::Delete(T& data) {
	m_curPos = m_List;
	NodeType<T>* preLoc = nullptr;
	while (m_curPos != nullptr) {
		if (m_curPos->data == data) {
			NodeType<T>* tempPtr = m_curPos;
			m_curPos = m_curPos->next;
			delete tempPtr;
			m_Length--;
			if (preLoc == nullptr) {
				m_List = m_curPos;
			}
			else {
				preLoc->next = m_curPos;
			}
			return 1;
		}
		else {
			preLoc = m_curPos;
			m_curPos = m_curPos->next;
		}
	}
	return 0;
}

//리스트 내의 모든 데이터를 동적 할당 해제
template <typename T>
void SortedLinkedList<T>::MakeEmpty() {
	while (m_List != nullptr) {
		NodeType<T>* tempPtr = m_List;
		m_List = m_List->next;
		delete tempPtr;
	}
	m_Length = 0;
}

//리스트 내의 데이터의 갯수를 반환한다.
template <typename T>
int SortedLinkedList<T>::GetLength() {
	return m_Length;
}

//리스트가 비었는지 그 결과를 반환한다.
template <typename T>
bool SortedLinkedList<T>::IsEmpty() {
	return (m_Length == 0);
}

//리스트 내에 전달받은 데이터가 존재하는지 검사한다.
template <typename T>
int SortedLinkedList<T>::Get(T& data) {
	m_curPos = m_List;
	while (m_curPos != nullptr) {
		if (data == m_curPos->data) {
			data = m_curPos->data;
			return 1;
		}
		m_curPos = m_curPos->next;
	}
	return 0;
}

//리스트 내의 포인터가 다음 요소를 가르키도록 움직인다.
template <typename T>
void SortedLinkedList<T>::GetNext(T& data) {
	if (m_curPos == nullptr) {
		m_curPos = m_List;
		if (m_curPos != nullptr)
			data = m_curPos->data;
	}
	else {
		m_curPos = m_curPos->next;
		if (m_curPos != nullptr)
			data = m_curPos->data;
	}
}

//리스트 내의 포인터을 초기화한다.
template <typename T>
void SortedLinkedList<T>::ResetList() {
	m_curPos = nullptr;
}

//리스트 내의 Actual Data의 포인터 주소를 반환한다.
template <typename T>
T* SortedLinkedList<T>::GetCurData() {
	return &(m_curPos->data);
}

//리스트 자신의 포인터 주소를 반환한다.
template <typename T>
SortedLinkedList<T>* SortedLinkedList<T>::GetList() {
	return this;
}

//대입연산자 오버로딩
template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& s_l) {
	m_Length = s_l.m_Length;
	m_List = nullptr;
	NodeType<T>* itor = s_l.m_List;
	if (itor != nullptr) {
		while (itor != nullptr) {
			NodeType<T>* tempPtr = new NodeType<T>;
			tempPtr->data = itor->data;
			if (m_List == nullptr) {
				m_List = tempPtr;
				m_curPos = tempPtr;
			}
			else {
				m_curPos->next = tempPtr;
				m_curPos = m_curPos->next;
			}
			itor = itor->next;
		}
	}
	m_curPos = nullptr;
	return *this;
}