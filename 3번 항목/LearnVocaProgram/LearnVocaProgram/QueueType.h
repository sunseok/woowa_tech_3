#pragma once
#include<iostream>
using namespace std;

#define maxQueue 200

/**
*	@brief	Exception class thrown by Enqueue when queue is full.
*/
class FullQueue
{
public:
	/**
	*	@brief	Display a message for full queue on screen.
	*/
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};


/**
*	@brief	Exception class thrown by Dequeue when queue is empty.
*/
class EmptyQueue
{
public:
	/**
	*	@brief	Display a message for empty queue on screen.
	*/
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};


template <typename T>					//����ܾ� �н� ���α׷������� T�� VocaType�� ���� �������� �� ����.
class Queue {
public:
	Queue();							//������
	int GetLength() const;					//�н��ܾ� ��Ͽ��� �����ִ� �ܾ� ������ ��ȯ
	void enQueue(T& voca);				//�н��ܾ� ��Ͽ� �ܾ �߰��Ѵ�.
	int deQueue(T& voca);				//�н��ܾ� ��Ͽ��� �ܾ �����Ѵ�.
	bool isFull() const;						//�н��ܾ� ����� �� á���� �˻��Ѵ�.
	bool isEmpty() const;						//�н��ܾ� ����� ������� �˻��Ѵ�.
	void MakeEmpty();					//�н��ܾ� ����� ����.
	void ResizeQueue(int i);
private:
	T* m_LearnVocaList;	//T�� ������ Ÿ���� ��ҷ� ���� ũ�� 200�� �迭
	int m_iFront;						//Queue�� First ������
	int m_iRear;						//Queue�� Rear ������
	int m_length;						//Queue �ڷᱸ�� ���� ���Ե� �������� ����
	int m_MaxSize;						//Queue �ڷᱸ���� ������
};

//������
template <typename T>
Queue<T>::Queue() {
	m_LearnVocaList = new T[maxQueue + 1];
	m_MaxSize = maxQueue + 1;
	m_iFront = maxQueue;
	m_iRear = maxQueue;
	m_length = 0;
}

//�н��ܾ� ����� �� á���� �˻��Ѵ�.
template <typename T>
bool Queue<T>::isFull() const {
	return(m_iFront == ((m_iRear + 1) % m_MaxSize));
}

//�н��ܾ� ����� ������� �˻��Ѵ�.
template <typename T>
bool Queue<T>::isEmpty() const {
	return(m_iFront == m_iRear);
}

//�н��ܾ� ����� ����.
template <typename T>
void Queue<T>::MakeEmpty() {
	m_iFront = maxQueue;
	m_iRear = maxQueue;
	m_length = 0;
	return;
}

//�н��ܾ� ��Ͽ� �ܾ �߰��Ѵ�.
template <typename T>
void Queue<T>::enQueue(T& item) {
	if (isFull()) {
		//throw FullQueue();
		T dummy;
		deQueue(dummy);
		enQueue(item);
	}
	else {
		m_iRear = (m_iRear + 1) % m_MaxSize;
		m_LearnVocaList[m_iRear] = item;
		//cout << "\t\nenQueue ����\n";
		m_length++;
	}
	return;
}

//�н��ܾ� ��Ͽ��� �ܾ �����Ѵ�.
template <typename T>
int Queue<T>::deQueue(T& item) {
	if (isEmpty()) {
		//throw EmptyQueue();
		return 0;
	}
	else {
		m_iFront = (m_iFront + 1) % m_MaxSize;
		item = m_LearnVocaList[m_iFront];
		m_length--;
		return 1;
	}
}

//�н��ܾ� ��Ͽ��� �����ִ� �ܾ� ������ ��ȯ
template <typename T>
int Queue<T>::GetLength() const {
	return m_length;
}

template <typename T>
void Queue<T>::ResizeQueue(int i) {
	delete[] m_LearnVocaList;
	m_LearnVocaList = new T[i + 1];
	m_MaxSize = i + 1;
	m_iFront = i;
	m_iRear = i;
	m_length = 0;
}