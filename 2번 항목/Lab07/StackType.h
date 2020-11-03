#pragma once
#include<iostream>
#include "NodeType.hpp"
using namespace std;

/**
*	stackType using pointer
*/
template <typename T>
class stackType {
public:
	/**
	*	�⺻ ������
	*/
	stackType();
	
	/**
	*	���� ������
	*/
	stackType(const stackType<T>& stack);
	
	/**
	*	�Ҹ���
	*/
	~stackType();

	//Transformer//////////////////////////////////////////////////////////////////////

	/**
	*	@brief	���ÿ� ���ο� ��带 push�Ѵ�.
	*	@pre	������ ��á���� �˻��ؾ��Ѵ�.
	*	@post	���ÿ� ���ο� ��尡 push�ȴ�.
	*	@return	push�� �����ϸ� 1, �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int Push(T data);

	/**
	*	@brief	���ÿ��� Ư�� ��带 pop�Ѵ�.
	*	@pre	������ ������� �˻��ؾ��Ѵ�.
	*	@post	���ÿ��� Ư�� ��尡 pop�ȴ�.
	*	@return	pop�� �����ϸ� 1, �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int Pop(T& data);

	/**
	*	@brief	������ ��� ��带 �����Ѵ�.
	*	@pre	������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	������ ��� ��尡 �����ȴ�.
	*/
	void MakeEmpty();

	//Observer function//////////////////////////////////////////////////////////////////////

	/**
	*	@brief	������ ���̸� ��ȯ�Ѵ�.
	*	@pre	������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	m_length
	*/
	int GetLength();

	/**
	*	@brief	������ �� á���� �˻��Ѵ�.
	*	@pre	������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	������ �� �������� 1, �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	bool isFull();

	/**
	*	@brief	������ ������� �˻��Ѵ�.
	*	@pre	������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	������ ��������� 1, �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	bool isEmpty();
    
    //stackType<T>& operator=(const stackType<T>& stack);

	/**
	*	@brief	m_curPos�� �ʱ�ȭ�Ѵ�.
	*	@pre	������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	m_curPos�� nullptr�� ��
	*/
	void ResetStack();

	/**
	*	@brief	m_curPos�� m_curPos->next�� �����Ѵ�.
	*	@pre	������ ��������� �ȵȴ�.
	*	@post	m_curPos�� ���ŵǰ� data�� m_curPos->data�� ���ŵȴ�. 
	*	@return	m_curPos (or nullptr)
	*/
	NodeType<T>* GetNextItem(T& data);


private:
	NodeType<T>* m_stack;	///<	���� ����Ʈ
	NodeType<T>* m_top;		///<	������ top
	NodeType<T>* m_curPos;  ///<	������ ������ȸ�� ���� �ݺ���
	int m_length;			///<	������ ����
};

//�⺻ ������
template <typename T>
stackType<T>::stackType() {
	m_length = 0;
	m_stack = nullptr;
	m_top = nullptr;
	m_curPos = nullptr;
}

//���� ������
template <typename T>
stackType<T>::stackType(const stackType<T>& stack) {
	m_length = stack.m_length;
	m_stack = nullptr;
	NodeType<T>* itor = stack.m_stack;
	if (itor != nullptr) {
		while (itor != nullptr) {
			NodeType<T>* tempPtr = new NodeType<T>;
			tempPtr->data = itor->data;
			if (m_stack == nullptr) {
				m_stack = tempPtr;
				m_top = tempPtr;
			}
			else {
				m_top->next = tempPtr;
				m_top = m_top->next;
			}
			itor = itor->next;
		}
	}
	else {
		m_top = nullptr;
	}
}

//�Ҹ���
template <typename T>
stackType<T>::~stackType() {
	MakeEmpty();
}

//���ÿ� ���ο� ��带 push�Ѵ�.
template <typename T>
int stackType<T>::Push(T data) {
	NodeType<T>* tempPtr = new NodeType<T>;
	tempPtr->data = data;
	if (m_stack == nullptr) {
		m_stack = tempPtr;
		m_top = tempPtr;
	}
	else {
		m_top->next = tempPtr;
		m_top = m_top->next;
	}
	m_length++;
	return 1;
}

//���ÿ��� Ư�� ��带 pop�Ѵ�.
template <typename T>
int stackType<T>::Pop(T& data) {
	data = m_top->data;
	if (m_stack == m_top) {
		delete m_top;
		m_top = nullptr;
		m_stack = nullptr;
	}
	else {
		NodeType<T>* tempPtr = m_stack;
		while (tempPtr->next != m_top) {
			tempPtr = tempPtr->next;
		}
		delete m_top;
		m_top = tempPtr;
		m_top->next = nullptr;
	}
	m_length--;
	return 1;
}

//������ ��� ��带 �����Ѵ�.
template <typename T>
void stackType<T>::MakeEmpty() {
	while (m_stack != nullptr) {
		NodeType<T>* tempPtr = m_stack;
		m_stack = m_stack->next;
		delete tempPtr;
	}
	m_top = nullptr;
	m_length = 0;
}

//������ ���̸� ��ȯ�Ѵ�.
template <typename T>
int stackType<T>::GetLength() {
	return m_length;
}

//������ �� á���� �˻��Ѵ�.
template <typename T>
bool stackType<T>::isFull() {
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

//������ ������� �˻��Ѵ�.
template <typename T>
bool stackType<T>::isEmpty() {
	return (m_length == 0);
}
//
//template <typename T>
//stackType<T>& stackType<T>::operator=(const stackType<T>& stack) {
//    MakeEmpty();
//    m_length = stack.m_length;
//    m_stack = nullptr;
//    NodeType<T>* itor = stack.m_stack;
//    if (itor != nullptr) {
//        while (itor != nullptr) {
//            NodeType<T>* tempPtr = new NodeType<T>;
//            tempPtr->data = itor->data;
//            if (m_stack == nullptr) {
//                m_stack = tempPtr;
//                m_top = tempPtr;
//            }
//            else {
//                m_top->next = tempPtr;
//                m_top = m_top->next;
//            }
//            itor = itor->next;
//        }
//    }
//    else {
//        m_top = nullptr;
//    }
//    return *this;
//}

//m_curPos�� �ʱ�ȭ�Ѵ�.
template <typename T>
void stackType<T>::ResetStack() {
	m_curPos = nullptr;
}

//m_curPos�� m_curPos->next�� �����Ѵ�.
template <typename T>
NodeType<T>* stackType<T>::GetNextItem(T& data) {
	if (m_curPos == nullptr) {
		m_curPos = m_stack;
		data = m_curPos->data;
		return m_curPos;
	}
	else {
		m_curPos = m_curPos->next;
		if (m_curPos == nullptr) {
			return m_curPos;
		}
		else {
			data = m_curPos->data;
			return m_curPos;
		}
	}
}