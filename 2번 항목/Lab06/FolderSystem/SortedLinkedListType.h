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
	SortedLinkedList();												//������(m_Length, m_List, m_curPos�� �ʱ�ȭ�Ѵ�)

	SortedLinkedList(const SortedLinkedList<T>& s_l);				//���������(s_l������ ��� ���� �ʱ�ȭ�ȴ�.)

	~SortedLinkedList();											//�Ҹ���(��ü�� �����Ҵ� ��ҵ��� ���� �Ҵ� ����)

	int Add(T& data);												//����Ʈ ���� ��� �߰��Լ�(������ 1, ���н� 0 ��ȯ)
			
	int Delete(T& data);											//����Ʈ ���� ��� �����Լ�(������ 1, ���н� 0 ��ȯ)

	void MakeEmpty();												//����Ʈ ���� ��� ��� �����Լ�(��ü�� �����Ҵ� ��ҵ��� ���� �Ҵ� ����)

	int GetLength();												//����Ʈ ���� ��� ���� ��ȯ�Լ�

	bool IsEmpty();													//����Ʈ�� ������� �˻��ϴ� �Լ�

	int Get(T& data);												//�Է¹��� ��ҿ� ���� ���� ���� ��Ұ� ����Ʈ ���� �ִ��� �˻��Ѵ�
																	//(������ 1, ������ 0��ȯ)

	void GetNext(T& data);											//����Ʈ ���� ��Ҹ� ����Ű�� m_curPos�� ���� ��Ҹ� ����Ű���� �����δ�.

	void ResetList();												//����Ʈ ���� ��Ҹ� ����Ű�� m_curPos�� ���� ó�� �������� �ǵ�����.
	
	T* GetCurData();												//����Ʈ ���� Actual Data�� ������ �ּҸ� ��ȯ�Ѵ�.

	SortedLinkedList<T>* GetList();									//����Ʈ �ڽ��� ������ �ּҸ� ��ȯ�Ѵ�.

	SortedLinkedList<T>& operator=(const SortedLinkedList<T>& s_l);	//���Կ����� �����ε�

private:
	int m_Length;													//����Ʈ ���� ��ҵ��� ����
	NodeType<T>* m_List;											//����Ʈ�� ������
	NodeType<T>* m_curPos;											//����Ʈ ���� ��ҵ��� ����ų �� �ִ� ������
};

//������
template <typename T>
SortedLinkedList<T>::SortedLinkedList() {
	m_Length = 0;
	m_List = nullptr;
	m_curPos = nullptr;
}

//���� ������
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

//�Ҹ���
template <typename T>
SortedLinkedList<T>::~SortedLinkedList() {
	MakeEmpty();
}

//����Ʈ ���� ���ڷ� ���� ������ �߰�
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

//����Ʈ���� ���ڷ� ���� ������ ����
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

//����Ʈ ���� ��� �����͸� ���� �Ҵ� ����
template <typename T>
void SortedLinkedList<T>::MakeEmpty() {
	while (m_List != nullptr) {
		NodeType<T>* tempPtr = m_List;
		m_List = m_List->next;
		delete tempPtr;
	}
	m_Length = 0;
}

//����Ʈ ���� �������� ������ ��ȯ�Ѵ�.
template <typename T>
int SortedLinkedList<T>::GetLength() {
	return m_Length;
}

//����Ʈ�� ������� �� ����� ��ȯ�Ѵ�.
template <typename T>
bool SortedLinkedList<T>::IsEmpty() {
	return (m_Length == 0);
}

//����Ʈ ���� ���޹��� �����Ͱ� �����ϴ��� �˻��Ѵ�.
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

//����Ʈ ���� �����Ͱ� ���� ��Ҹ� ����Ű���� �����δ�.
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

//����Ʈ ���� �������� �ʱ�ȭ�Ѵ�.
template <typename T>
void SortedLinkedList<T>::ResetList() {
	m_curPos = nullptr;
}

//����Ʈ ���� Actual Data�� ������ �ּҸ� ��ȯ�Ѵ�.
template <typename T>
T* SortedLinkedList<T>::GetCurData() {
	return &(m_curPos->data);
}

//����Ʈ �ڽ��� ������ �ּҸ� ��ȯ�Ѵ�.
template <typename T>
SortedLinkedList<T>* SortedLinkedList<T>::GetList() {
	return this;
}

//���Կ����� �����ε�
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