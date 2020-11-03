#pragma once
#pragma once
#include<iostream>
using namespace std;

template <typename T>
struct NodeType
{
	T data;							//NodeType�� ������
	NodeType<T>* pre = nullptr;		//���� Node�� ����Ű�� ������
	NodeType<T>* next = nullptr;	//���� Node�� ����Ű�� ������
};

template <typename T>
class SortedLinkedListType {
public:
	/**
	*	@brief	�⺻ ������
	*	@post	LinkedList�� ��� ��������� �ʱ�ȭ�Ѵ�.
	*/
	SortedLinkedListType();

	/**
	*	@brief	�Ҹ���
	*	@post	LinkedList�� �����Ҵ�� ��� ��ҵ��� �Ҵ� �����Ѵ�.
	*/
	~SortedLinkedListType();

	/**
	*	@brief	���� ������
	*	@post	������ �����ϴ� SortedLinkedListType�� ��ü�κ��� ��� ������ deep copy�Ѵ�.
	*/
	SortedLinkedListType(const SortedLinkedListType& list);

	/**
	*	@brief	LinkedList�� ���ο� ��带 �߰��Ѵ�.
	*	@pre	        data�� �Է¹޴´�.
	*	@post	LinkedList�� ���ο� ��尡 �߰��ȴ�.
	*   @return     ��� �߰��� �����ϸ� 1, �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int Insert(T& data);

	/**
	*	@brief	LinkedList���� Ư�� ��带 �����Ѵ�.
	*	@pre	        Get�Լ��� �ߺ� data���� Node�� �˻��ؾ��Ѵ�.
	*	@post	LinkedList���� Ư�� ��尡 �����ȴ�.
	*       @return     ��� ������ �����ϸ� 1, �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int Delete(T& data);

	/**
	*    @brief    LinkedList���� Ư�� ��带 �����Ѵ�.
	*    @pre    Get�Լ��� �ߺ� data���� Node�� �˻��ؾ��Ѵ�.
	*    @post    LinkedList���� Ư�� ��尡 �����ȴ�.
	*/
	void Replace(const T& data);

	/**
	*	@brief	LinkedList�� ��� ��ҵ��� �����Ѵ�.
	*	@pre	Get�Լ��� ������� data�� ���� Node�� �����ϴ��� �˻��ؾ��Ѵ�.
	*	@post	LinkedList�� ��� ��ҵ��� �����ȴ�.
	*/
	void MakeEmpty();

	/**
	*	@brief	LinkedList���� �ݺ��ڸ� �̵����� �ش� �ݺ��ڰ� ����Ű�� Node�� data�� �����Ѵ�.
	*	@pre	data�� �Է¹޴´�.
	*	@post	LinkedList���� �ݺ��ڸ� �̵��ǰ� �ش� �ݺ��ڰ� ����Ű�� Node�� data�� ���ŵȴ�.
	*	@return	�ݺ��ڰ� ������ ���ٸ� nullptr, �ƴ϶�� �ݺ��ڰ� ����Ű�� Node�� �����͸� ��ȯ�Ѵ�.
	*/
	NodeType<T>* GetNext(T& data);

	//LinkedList�� �ݺ��ڸ� pre�������� �̵���Ű�� �׶� ����Ű�� Node�� data�� ��ȯ�Ѵ�.
	NodeType<T>* GetPre(T& data);

	/**
	*	@brief	LinkedList�� �ݺ��ڸ� �ʱ�ȭ�Ѵ�.
	*	@pre	LinkedLIst�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	LinkedList�� �ݺ��ڰ� �ʱ�ȭ�ȴ�.
	*/
	void ResetList();

	//LinkedList�� �ݺ��ڸ� pre�������� ��ȸ�ϵ��� �ʱ�ȭ�Ѵ�.
	void ResetListForGetPre();

	/**
	*	@brief	LinkedList ���� ��� ������ ��ȯ�Ѵ�.
	*	@pre	LinkedList�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	LinkedList ���� ��� ������ ��ȯ�ȴ�.
	*	@return	LinkedList ���� ��� ����
	*/
	int GetLength() const;

	/**
	*	@brief	LinkedList ���� ��尡 ������� �˻��Ѵ�.
	*	@pre	LinkedList�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	LinkedList ���� ��尡 ������� �˻��ϰԵȴ�.
	*	@return	������� true, �ƴ϶�� false�� ��ȯ
	*/
	bool isEmpty() const;

	/**
	*	@brief	�޸𸮻� ��尡 �� �� �� �ִ��� �˻��Ѵ�.
	*	@pre	LinkedList�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	�޸𸮻� ��尡 �� �� �� �ִ��� �˻��ϰԵȴ�.
	*	@return	��á���� true, �ƴ϶�� false�� ��ȯ
	*/
	bool isFull() const;

	/**
	*	@brief	LinkedList�� ������ data�� ���� Node�� �����ϴ��� �˻��Ѵ�.
	*	@pre	data�� �Է¹޴´�.
	*	@post	LinkedList ���� ���� data�� ���� Node�� ���� ���θ� �˰� �ȴ�.
	*	@return	�����Ѵٸ� 1, �ƴ϶�� 0�� ��ȯ
	*/
	int Get(T& data);

	//LinkedList �ǵ��� data�� ã������ data�� ���ؼ� ������ 1 otherwise 0 ��ȯ.
	int CheckBack(T& data);
	
	//LinkedList �ǵ��� data���� �������� data�� ū ��� data�� �� �ڿ� �����Ѵ�(������� ��쿡�� �ִ´�), ������ 1 otherwise 0��ȯ.
	int InsertTail(T& data);

	//LinkedList �ǵ��� data�� �����Ϸ��� data�� ���� ���� ��� �����Ѵ�, ������ 1 otherwise 0��ȯ.
	int DeleteTail(T& data);

	// �ݺ��ڰ� ����Ű�� �������� �����͸� ��ȯ�Ѵ�.
	T* GetCurPtr() {
		return &(m_curPtr->data);
	}

	// ���� ������ �����ε�
	SortedLinkedListType<T>& operator=(const SortedLinkedListType<T>& list);

private:
	NodeType<T>* m_head;			//LinkedList���� ���� �տ� ��ġ�� ��带 ����Ű�� ������
	NodeType<T>* m_tail;			//LinkedList���� ���� �ڿ� ��ġ�� ��带 ����Ű�� ������
	NodeType<T>* m_curPtr;			//LinkedList���� �����ϴ� ����� ������ �����ϴ� int�� ����
	int m_length;
};

//LinkedList�� ����������� �ʱ�ȭ�Ѵ�.
template <typename T>
SortedLinkedListType<T>::SortedLinkedListType() {
	m_head = new NodeType<T>;
	m_tail = new NodeType<T>;
	m_head->pre = nullptr;
	m_head->next = m_tail;
	m_tail->next = nullptr;
	m_tail->pre = m_head;
	m_curPtr = m_head;
	m_length = 0;
}

//������ �����ϴ� SortedLinkedListType�� ��ü�κ��� ��� ������ deep copy�Ѵ�.
template <typename T>
SortedLinkedListType<T>::SortedLinkedListType(const SortedLinkedListType& list) {
	m_head = new NodeType<T>;
	m_tail = new NodeType<T>;
	m_head->pre = nullptr;
	m_head->next = m_tail;
	m_tail->next = nullptr;
	m_tail->pre = m_head;
	m_curPtr = m_head;
	m_length = list.m_length;
	/*
		list ���� ��� ��忡�� data���� �̾ƿ� �ش� SortedLinkedListType��ü�� ����Ʈ�� �����Ѵ�.
	*/
	NodeType<T>* list_curPtr = list.m_head;
	while (list_curPtr->next != list.m_tail) {
		list_curPtr = list_curPtr->next;
		NodeType<T>* tempPtr = new NodeType<T>;
		tempPtr->data = list_curPtr->data;
		while (m_curPtr->next != m_tail)
			m_curPtr = m_curPtr->next;
		m_curPtr->next->pre = tempPtr;
		tempPtr->next = m_curPtr->next;
		tempPtr->pre = m_curPtr;
		m_curPtr->next = tempPtr;
	}
}

//LinkedList�� �����Ҵ�� ��� ��ҵ��� �Ҵ� �����Ѵ�.
template <typename T>
SortedLinkedListType<T>::~SortedLinkedListType() {
	MakeEmpty();
	delete m_head;
	delete m_tail;
}

//LinkedList�� ���ο� ��带 �߰��Ѵ�.
template <typename T>
int SortedLinkedListType<T>::Insert(T& data) {
	if (isFull()) {
		return 0;
	}
	else if (InsertTail(data)) {
		return 1;
	}
	else {
		NodeType<T>* tempPtr = new NodeType<T>;
		tempPtr->data = data;

		m_curPtr = m_head;
		while (m_curPtr->next != m_tail) {            //�������� Node�� �� �ڿ� �ٴ°� �ƴ� ���
			m_curPtr = m_curPtr->next;
			if (m_curPtr->data > data) {
				m_curPtr->pre->next = tempPtr;
				tempPtr->pre = m_curPtr->pre;
				m_curPtr->pre = tempPtr;
				tempPtr->next = m_curPtr;
				m_length++;
				return 1;
			}
		}
		return 0;
	}
}

//LinkedList���� Ư�� ��带 �����Ѵ�.
template <typename T>
int SortedLinkedListType<T>::Delete(T& data) {
	if (isEmpty()) {
		return 0;
	}
	else if (DeleteTail(data)) {
		return 1;
	}
	else {
		m_curPtr = m_head;
		while (m_curPtr->next != m_tail) {
			m_curPtr = m_curPtr->next;
			if (m_curPtr->data == data) {
				m_curPtr->next->pre = m_curPtr->pre;
				m_curPtr->pre->next = m_curPtr->next;
				delete m_curPtr;
				m_length--;
				return 1;
			}
		}
		return 0;
	}
}

//LinkedList���� Ư�� ��带 �����Ѵ�.
template <typename T>
void SortedLinkedListType<T>::Replace(const T& data) {
	m_curPtr = m_head;
	while (m_curPtr->next != m_tail) {
		m_curPtr = m_curPtr->next;
		if (m_curPtr->data == data) {
			m_curPtr->data = data;
			return;
		}
	}
}

//LinkedList�� ��� ��ҵ��� �����Ѵ�.
template <typename T>
void SortedLinkedListType<T>::MakeEmpty() {
	while (m_tail->pre != m_head) {
		m_curPtr = m_tail->pre;
		m_curPtr->next->pre = m_curPtr->pre;
		m_curPtr->pre->next = m_curPtr->next;
		delete m_curPtr;
	}
	m_length = 0;
}

//LinkedList���� �ݺ��ڸ� �̵����� �ش� �ݺ��ڰ� ����Ű�� Node�� data�� �����Ѵ�.
template <typename T>
NodeType<T>* SortedLinkedListType<T>::GetNext(T& data) {
	if (m_curPtr->next != m_tail) {
		m_curPtr = m_curPtr->next;
		data = m_curPtr->data;
		return m_curPtr;
	}
	else {
		m_curPtr = m_head;
		return nullptr;
	}
}

template <typename T>
NodeType<T>* SortedLinkedListType<T>::GetPre(T& data) {
	if (m_curPtr->pre != m_head) {
		m_curPtr = m_curPtr->pre;
		data = m_curPtr->data;
		return m_curPtr;
	}
	else {
		m_curPtr = m_tail;
		return nullptr;
	}
}



//LinkedList�� �ݺ��ڸ� �ʱ�ȭ�Ѵ�.
template <typename T>
void SortedLinkedListType<T>::ResetList() {
	m_curPtr = m_head;
}

//LinkedList�� �ݺ��ڸ� �ʱ�ȭ�Ѵ�.
template <typename T>
void SortedLinkedListType<T>::ResetListForGetPre() {
	m_curPtr = m_tail;
}

//LinkedList ���� ��� ������ ��ȯ�Ѵ�.
template <typename T>
int SortedLinkedListType<T>::GetLength() const {
	return m_length;
}

//LinkedList ���� ��尡 ������� �˻��Ѵ�.
template <typename T>
bool SortedLinkedListType<T>::isEmpty() const {
	return (m_length == 0);
}

//�޸𸮻� ��尡 �� �� �� �ִ��� �˻��Ѵ�.
template <typename T>
bool SortedLinkedListType<T>::isFull() const {
	NodeType<T>* tempPtr;
	try
	{
		tempPtr = new NodeType<T>;
		delete tempPtr;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

//LinkedList�� ������ data�� ���� Node�� �����ϴ��� �˻��Ѵ�.
template <typename T>
int SortedLinkedListType<T>::Get(T& data) {
	if (m_length == 0) {
		return 0;
	}
	else if (CheckBack(data)){
		return 1;
	}
	else {
		m_curPtr = m_head;
		while (m_curPtr->next != m_tail) {
			m_curPtr = m_curPtr->next;
			if (m_curPtr->data == data) {
				data = m_curPtr->data;
				return 1;
			}
		}
	}
	return 0;
}

template <typename T>
int SortedLinkedListType<T>::CheckBack(T& data) {
	if (m_length == 0) {
		return 0;
	}
	else if(m_tail->pre->data == data) {
		data = m_tail->pre->data;
		return 1;
	}
	else {
		return 0;
	}
}

template <typename T>
int SortedLinkedListType<T>::InsertTail(T& data) {
	if (isFull()) {
		return 0;
	}
	else {
		if (m_length == 0 || m_tail->pre->data < data) {
			NodeType<T>* temp = new NodeType<T>;
			temp->data = data;
			
			temp->next = m_tail;
			temp->pre = m_tail->pre;
			m_tail->pre->next = temp;
			m_tail->pre = temp;

			m_length++;
			return 1;
		}
		else {
			return 0;
		}
	}
}


template <typename T>
int SortedLinkedListType<T>::DeleteTail(T& data) {
	if (m_length == 0) {
		return 0;
	}
	else if (m_tail->pre->data == data) {
		m_curPtr = m_tail->pre;
		m_curPtr->pre->next = m_tail;
		m_tail->pre = m_curPtr->pre;
		m_length--;
		delete m_curPtr;
		m_curPtr = nullptr;
		return 1;
	}
	else {
		return 0;
	}
}

//���Կ����� �����ε�
template <typename T>
SortedLinkedListType<T>& SortedLinkedListType<T>::operator=(const SortedLinkedListType<T>& list) {
	MakeEmpty();
	m_head->pre = nullptr;
	m_head->next = m_tail;
	m_tail->next = nullptr;
	m_tail->pre = m_head;
	m_curPtr = m_head;
	m_length = list.m_length;
	/*
		list ���� ��� ��忡�� data���� �̾ƿ� �ش� SortedLinkedListType��ü�� ����Ʈ�� �����Ѵ�.
	*/
	NodeType<T>* list_curPtr = list.m_head;
	while (list_curPtr->next != list.m_tail) {
		list_curPtr = list_curPtr->next;
		NodeType<T>* tempPtr = new NodeType<T>;
		tempPtr->data = list_curPtr->data;
		while (m_curPtr->next != m_tail)
			m_curPtr = m_curPtr->next;
		m_curPtr->next->pre = tempPtr;
		tempPtr->next = m_curPtr->next;
		tempPtr->pre = m_curPtr;
		m_curPtr->next = tempPtr;
	}
	return *this;
}



