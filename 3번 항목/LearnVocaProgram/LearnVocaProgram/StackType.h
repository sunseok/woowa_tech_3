#pragma once
#define MAX_SIZE 50

#include <iostream>
using namespace std;

class FullStack {
public:
	void print() { cout << "Caution" << endl; }
};
class EmptyStack {
public:
	void print() { cout << "Caution" << endl; }
};

template <typename T>
class StackType {
	T m_TestVocaList[MAX_SIZE];
	int m_top;
	int m_length;
public:
	StackType() {
		m_length = 0;
		m_top = -1;
	}
	int push(T& voca) {
		//�׽�Ʈ �ܾ� ��Ͽ� �ܾ �߰��Ѵ�.
		if (!isFull()) {
			m_TestVocaList[++m_top] = voca;
			m_length++;
			return 1;
		}
		else
			throw FullStack();
	}
	int pop(T& voca) {
		//�׽�Ʈ �ܾ� ��Ͽ��� �ܾ �����Ѵ�.
		if (!isEmpty()) {
			voca = m_TestVocaList[m_top--];
			m_length--;
			return 1;
		}
		else
			throw EmptyStack();
	}
	bool isFull() const {
		//�׽�Ʈ �ܾ� ����� �� á���� �˻��Ѵ�.
		if (m_length == MAX_SIZE)
			return 1;
		else
			return 0;
	}
	bool isEmpty() const {
		//�׽�Ʈ �ܾ� ����� ������� �˻��Ѵ�.
		if (m_length == 0)
			return 1;
		else
			return 0;
	}
	int getLength() const {
		//�׽�Ʈ �ܾ� ����� �ܾ� ���� ��ȯ�Ѵ�.
		return m_length;
	}
	void MakeEmpty() {
		//�׽�Ʈ �ܾ� ����� ����.
		m_top = -1;
		m_length = 0;
	}
};
