#pragma once
#include<iostream>

using namespace std;

template <typename T>
struct SinglyNodeType
{
	T data;
	SinglyNodeType<T>* next = nullptr;
};

template <typename T>
class UnsortedLinkedList {
public:
	UnsortedLinkedList();									//������(m_Length, m_List, m_curPos�� �ʱ�ȭ�Ѵ�)

	UnsortedLinkedList(const UnsortedLinkedList<T>& u_l);	//���������

	~UnsortedLinkedList();									//�Ҹ���(��ü�� �����Ҵ� ��ҵ��� ���� �Ҵ� ����)

	int Insert(T& data);									//����Ʈ ���� ��� �߰��Լ�(������ 1, ���н� 0 ��ȯ)

	int Delete(T& data);									//����Ʈ ���� ��� �����Լ�(������ 1, ���н� 0 ��ȯ)

	void Replace(const T& data);

	void MakeEmpty();				//����Ʈ ���� ��� ��� �����Լ�(��ü�� �����Ҵ� ��ҵ��� ���� �Ҵ� ����)

	int GetLength() const;				//����Ʈ ���� ��� ���� ��ȯ�Լ�

	bool IsFull() const;					//����Ʈ�� ��á���� �˻��ϴ� �Լ�

	bool IsEmpty() const;					//����Ʈ�� ������� �˻��ϴ� �Լ�

	int Get(T data);				//�Է¹��� ��ҿ� ���� ���� ���� ��Ұ� ����Ʈ ���� �ִ��� �˻��Ѵ�
									//(������ 1, ������ 0��ȯ)

	void GetNext(T& data);			//����Ʈ ���� ��Ҹ� ����Ű�� m_curPos�� ���� ��Ҹ� ����Ű���� �����δ�.

	void ResetList();				//����Ʈ ���� ��Ҹ� ����Ű�� m_curPos�� ���� ó�� �������� �ǵ�����.

	UnsortedLinkedList<T>& operator= (const UnsortedLinkedList<T> & u_l);

	// �ݺ��ڰ� ����Ű�� �������� �����͸� ��ȯ�Ѵ�.
	T* GetCurPtr() {
		return &(m_curPos->data);
	}
private:
	int m_Length;					//����Ʈ ���� ��ҵ��� ����
	SinglyNodeType<T>* m_List;			//����Ʈ�� ������
	SinglyNodeType<T>* m_curPos;			//����Ʈ ���� ��ҵ��� ����ų �� �ִ� ������
};

template <typename T>
UnsortedLinkedList<T>::UnsortedLinkedList() {
	m_Length = 0;
	m_List = nullptr;
	m_curPos = nullptr;
}

template <typename T>
UnsortedLinkedList<T>::UnsortedLinkedList(const UnsortedLinkedList<T>& u_l) {
	MakeEmpty();
	m_Length = u_l.m_Length;
	m_curPos = u_l.m_List;
	SinglyNodeType<T>* temp_cur = nullptr;
	int cnt = 0;
	while (m_curPos != nullptr) {
		SinglyNodeType<T>* temp = new SinglyNodeType<T>;
		temp->data = m_curPos->data;
		if (cnt == 0) {
			m_List = temp;
			temp_cur = temp;
			cnt++;
		}
		else {
			temp_cur->next = temp;
			temp_cur = temp_cur->next;
		}
		m_curPos = m_curPos->next;
	}
	m_curPos = nullptr;
}

template <typename T>
UnsortedLinkedList<T>::~UnsortedLinkedList() {
	MakeEmpty();
}

template <typename T>
int UnsortedLinkedList<T>::Insert(T& data) {
	if (IsFull()) {
		return 0;
	}
	else {
		SinglyNodeType<T>* node = new SinglyNodeType<T>;
		SinglyNodeType<T>* preLoc = m_List;
		node->data = data;
		if (IsEmpty()) {
			m_List = node;
			m_Length++;
			m_curPos = m_List;
		}
		else {
			m_curPos = m_List;
			while (m_curPos != nullptr) {
				preLoc = m_curPos;
				m_curPos = m_curPos->next;
			}
			m_curPos = node;
			preLoc->next = m_curPos;
			m_Length++;
		}
		return 1;
	}
}

template <typename T>
int UnsortedLinkedList<T>::Delete(T& data) {
	if (IsEmpty()) {
		return 0;
	}
	else {
		m_curPos = m_List;
		SinglyNodeType<T>* preLoc = nullptr;
		while (m_curPos != nullptr) {
			if (m_curPos->data == data) {
				SinglyNodeType<T>* tempPtr = m_curPos;
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
	}
	return 0;
}

//LinkedList���� Ư�� ��带 �����Ѵ�.
template <typename T>
void UnsortedLinkedList<T>::Replace(const T& data) {
	m_curPos = m_List;
	while (m_curPos != nullptr) {
		if (m_curPos->data == data) {
			m_curPos->data = data;
			return;
		}
		m_curPos = m_curPos->next;
	}
}

template <typename T>
void UnsortedLinkedList<T>::MakeEmpty() {
	while (m_List != nullptr) {
		SinglyNodeType<T>* tempPtr = m_List;
		m_List = m_List->next;
		delete tempPtr;
	}
	m_Length = 0;
}

template <typename T>
int UnsortedLinkedList<T>::GetLength() const {
	return m_Length;
}

//�޸𸮻� ��尡 �� �� �� �ִ��� �˻��Ѵ�.
template <typename T>
bool UnsortedLinkedList<T>::IsFull() const {
	SinglyNodeType<T>* tempPtr;
	try
	{
		tempPtr = new SinglyNodeType<T>;
		delete tempPtr;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

template <typename T>
bool UnsortedLinkedList<T>::IsEmpty() const {
	return (m_Length == 0);
}

template <typename T>
int UnsortedLinkedList<T>::Get(T data) {
	m_curPos = m_List;
	while (m_curPos != nullptr) {
		if (data == m_curPos->data) {
			return 1;
		}
		m_curPos = m_curPos->next;
	}
	return 0;
}

template <typename T>
void UnsortedLinkedList<T>::GetNext(T& data) {
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

template <typename T>
void UnsortedLinkedList<T>::ResetList() {
	m_curPos = nullptr;
}

template <typename T>
UnsortedLinkedList<T>& UnsortedLinkedList<T>::operator= (const UnsortedLinkedList<T> & u_l){
	MakeEmpty();
	m_Length = u_l.m_Length;
	m_curPos = u_l.m_List;
	SinglyNodeType<T>* temp_cur = nullptr;
	int cnt = 0;
	while (m_curPos != nullptr) {
		SinglyNodeType<T>* temp = new SinglyNodeType<T>;
		temp->data = m_curPos->data;
		if (cnt == 0) {
			m_List = temp;
			temp_cur = temp;
			cnt++;
		}
		else {
			temp_cur->next = temp;
			temp_cur = temp_cur->next;
		}
		m_curPos = m_curPos->next;
	}
	m_curPos = nullptr;
	return *this;
}