#pragma once
/*
*	@To do list:
					1.=������ �����ε�
					2.�ø��� ���̱�(Ư�� ���ؿ����� �絿���Ҵ�)
*/

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class SortedArrayList {
public:
	
	/*
	*	�⺻ ������
	*/
	SortedArrayList();

	//���������
	SortedArrayList(const SortedArrayList<T>& s_l);

	~SortedArrayList();

	//����Ʈ�� �ݺ��ڸ� ����(���� �����͸� ����Ű����)
	int GetNext(T& data);

	//����Ʈ�� �ݺ��ڸ� �ʱ�ȭ
	int ResetList();

	//����Ʈ���� �Է¹��� ���ڰ� �����ϴ��� �˻�
	int Get(T& data);

	// ����Ʈ�� �����͸� �߰�
	int Insert(T& data);

	int Delete(T& data);

	// �ݺ��ڰ� ����Ű�� �������� �����͸� ��ȯ�Ѵ�.
	T* GetCurPtr() const;

	/**
	*	@brief      ���ڿ� ������ �ε����� ��ġ�� �����͸� ������������ ��ȯ�Ѵ�.
	*	@pre	        i�� m_length�� ������ �ȵȴ�.
	*	@post       ����
	*	@return     m_AllVocaList�� i��° ������
	*/
	T GetIndexOfData(int i);

	//����Ʈ ���� ������ ��ȯ�Ѵ�.
	int GetLength() const;

	//����Ʈ�� ������� �˻��Ѵ�.
	bool isEmpty() const;

	//����Ʈ��  ��á���� �˻��Ѵ�.
	bool isFull() const;

	//����Ʈ�� ����.
	void MakeEmpty();

	/*
	*	@brief	�迭����Ʈ�� ����� 500��ŭ Ȯ���Ѵ�.
	*	@pre	�迭����Ʈ�� �������Ѵ�.
	*	@post	�迭����Ʈ�� ����� 500����ŭ Ŀ����.
	*/
	void ExpandSize();


	/*
	*	@brief	�迭����Ʈ�� ����� 500��ŭ ���δ�.
	*	@pre	�迭����Ʈ�� ����ְų� m_maxsize�� 1000�̸� ������� �ʴ´�.
	*	@post	�迭����Ʈ�� ����� 500�� �پ���.
	*/
	void ReduceSize();


	SortedArrayList<T>& operator=(const SortedArrayList<T>& s_l);

private:
	T* m_List;					//����Ʈ
	int m_maxsize;				//����Ʈ�� ������
	int m_curPos;				//����Ʈ�� �ݺ���
	int m_length;				//����Ʈ ���� �����ϴ� �������� ����
};

/**
*	�⺻ ������
*/
template <typename T>
SortedArrayList<T>::SortedArrayList() {
	m_length = 0;
	m_curPos = -1;
	m_maxsize = 1000;
	m_List = new T[m_maxsize];
}

template <typename T>
SortedArrayList<T>::SortedArrayList(const SortedArrayList<T>& s_l) {
	MakeEmpty();
	m_length = s_l.m_length;
	m_maxsize = s_l.m_maxsize;
	if (m_maxsize > 1000) {
		m_List = new T[m_maxsize];
	}
	else {
		m_List = new T[m_maxsize];
	}
	for (int i = 0; i < m_length; i++) {
		m_List[i] = s_l.m_List[i];
	}
	m_curPos = -1;
}

template <typename T>
SortedArrayList<T>::~SortedArrayList() {
	delete[] m_List;
}

//����Ʈ�� �ݺ��ڸ� ����(���� �����͸� ����Ű����)
template <typename T>
int SortedArrayList<T>::GetNext(T& data) {
	m_curPos++;	// list pointer ����
	if (m_curPos >= m_length)	// end of list�̸� -1�� ����
		return -1;

	data = m_List[m_curPos];	// ���� list pointer�� ���ڵ带 ����
	return m_curPos;
}

//����Ʈ�� �ݺ��ڸ� �ʱ�ȭ
template <typename T>
int SortedArrayList<T>::ResetList() {
	m_curPos = -1;
	return 1;
}

//����Ʈ���� �Է¹��� ���ڰ� �����ϴ��� �˻�
template <typename T>
int SortedArrayList<T>::Get(T& data) {
	if (m_length > 0)
	{
		ResetList();
		int head = 0;
		int tail = m_length - 1;

		while (head <= tail)
		{
			m_curPos = (tail + head) / 2;
			if (data == m_List[m_curPos]) {
				data = m_List[m_curPos];
				return 1;
			}
			else if (data > m_List[m_curPos]) {
				head = m_curPos + 1;
			}
			else if (data < m_List[m_curPos]) {
				tail = m_curPos - 1;
			}
		}
		return 0;
	}
	else
		return 0;
}

// ����Ʈ�� �����͸� �߰�
template <typename T>
int SortedArrayList<T>::Insert(T& data) {
	if (isFull()) {
		return 0;
	}
	else {
		T tempData;
		ResetList();
		while (GetNext(tempData) != -1) {
			if ((tempData > data)) {	//�������� ���� �迭 �� �����ͺ��� �۴ٸ� �� ������ m_curPos���� ������Ŵ
				break;
			}
		}
		for (int i = m_length; i > m_curPos; i--) {
			m_List[i] = m_List[i - 1];
		}
		m_List[m_curPos] = data;
		m_length++;
		return 1;
	}
}

template <typename T>
int SortedArrayList<T>::Delete(T& data) {
	if (isEmpty())
	{
		return 0;
	}
	else {
		T tempData;
		ResetList();
		while (GetNext(tempData) != -1) {
			if ((tempData == data)) {	//�������� ���� �迭 �� �����ͺ��� �۴ٸ� �� ������ m_curPos���� ������Ŵ
				for (int i = m_curPos + 1; i < m_length; i++) {
					m_List[i - 1] = m_List[i];
				}
				m_length--;
				return 1;
			}
		}
		return 0;
	}
}

// �ݺ��ڰ� ����Ű�� �������� �����͸� ��ȯ�Ѵ�.
template <typename T>
T* SortedArrayList<T>::GetCurPtr() const {
	return &m_List[m_curPos];
}

/**
*	@brief      ���ڿ� ������ �ε����� ��ġ�� �����͸� ������������ ��ȯ�Ѵ�.
*	@pre	    i�� m_length�� ������ �ȵȴ�.
*	@post       ����
*	@return     m_List�� i��° ������
*/
template <typename T>
T SortedArrayList<T>::GetIndexOfData(int i) {
	return (m_List[i]);
}

//����Ʈ ���� ������ ��ȯ�Ѵ�.
template <typename T>
int SortedArrayList<T>::GetLength() const {
	return m_length;
}

//����Ʈ�� ������� �˻��Ѵ�.
template <typename T>
bool SortedArrayList<T>::isEmpty() const {
	return (m_length == 0);
}

//����Ʈ��  ��á���� �˻��Ѵ�.
template <typename T>
bool SortedArrayList<T>::isFull() const {
	return (m_length == m_maxsize);
}

template <typename T>
void SortedArrayList<T>::MakeEmpty() {
	m_length = 0;
	m_curPos = -1;
	if (m_maxsize > 1000) {
		m_maxsize = 1000;
		delete[] m_List;
		m_List = new T[m_maxsize];
	}
}

/*
*	@brief	�迭����Ʈ�� ����� 500��ŭ Ȯ���Ѵ�.
*	@pre	�迭����Ʈ�� �������Ѵ�.
*	@post	�迭����Ʈ�� ����� 500����ŭ Ŀ����.
*/
template <typename T>
void SortedArrayList<T>::ExpandSize() {
	if (isFull()) {
		SortedArrayList<T> temp(*this);
		delete[] m_List;
		m_List = new T[temp.m_maxsize + 500];
		m_maxsize = temp.m_maxsize + 500;
		m_length = temp.m_length;
		m_curPos = -1;
		for (int i = 0; i < m_length; i++) {
			m_List[i] = temp.m_List[i];
		}
		return;
	}
	else {
		return;
	}
}

template <typename T>
void SortedArrayList<T>::ReduceSize() {
	if (isEmpty() || m_maxsize == 1000) {
		return;
	}
	else if(m_maxsize - m_length > 500){
		SortedArrayList<T> temp(*this);
		delete[] m_List;
		m_List = new T[temp.m_maxsize - 500];
		m_maxsize = temp.m_maxsize - 500;
		m_length = temp.m_length;
		m_curPos = -1;
		for (int i = 0; i < m_length; i++) {
			m_List[i] = temp.m_List[i];
		}
		return;
	}
	else {
		return;
	}
}

//���Կ�����
template <typename T>
SortedArrayList<T>& SortedArrayList<T>::operator=(const SortedArrayList<T>& s_l) {
	MakeEmpty();
	m_length = s_l.m_length;
	m_maxsize = s_l.m_maxsize;
	if (m_maxsize > 1000) {
		m_List = new T[m_maxsize];
	}
	else {
		m_List = new T[m_maxsize];
	}
	for (int i = 0; i < m_length; i++) {
		m_List[i] = s_l.m_List[i];
	}
	m_curPos = -1;
	return *this;
}