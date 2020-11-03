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
	*	기본 생성자
	*/
	stackType();
	
	/**
	*	복사 생성자
	*/
	stackType(const stackType<T>& stack);
	
	/**
	*	소멸자
	*/
	~stackType();

	//Transformer//////////////////////////////////////////////////////////////////////

	/**
	*	@brief	스택에 새로운 노드를 push한다.
	*	@pre	스택이 꽉찼는지 검사해야한다.
	*	@post	스택에 새로운 노드가 push된다.
	*	@return	push에 성공하면 1, 그렇지 않으면 0을 반환한다.
	*/
	int Push(T data);

	/**
	*	@brief	스택에서 특정 노드를 pop한다.
	*	@pre	스택이 비었는지 검사해야한다.
	*	@post	스택에서 특정 노드가 pop된다.
	*	@return	pop에 성공하면 1, 그렇지 않으면 0을 반환한다.
	*/
	int Pop(T& data);

	/**
	*	@brief	스택의 모든 노드를 삭제한다.
	*	@pre	스택이 초기화 되어있어야한다.
	*	@post	스택의 모든 노드가 삭제된다.
	*/
	void MakeEmpty();

	//Observer function//////////////////////////////////////////////////////////////////////

	/**
	*	@brief	스택의 길이를 반환한다.
	*	@pre	스택이 초기화 되어있어야한다.
	*	@post	없음
	*	@return	m_length
	*/
	int GetLength();

	/**
	*	@brief	스택이 꽉 찼는지 검사한다.
	*	@pre	스택이 초기화 되어있어야한다.
	*	@post	없음
	*	@return	스택이 꽉 차있으면 1, 그렇지 않으면 0을 반환한다.
	*/
	bool isFull();

	/**
	*	@brief	스택이 비었는지 검사한다.
	*	@pre	스택이 초기화 되어있어야한다.
	*	@post	없음
	*	@return	스택이 비어있으면 1, 그렇지 않으면 0을 반환한다.
	*/
	bool isEmpty();
    
    //stackType<T>& operator=(const stackType<T>& stack);

	/**
	*	@brief	m_curPos를 초기화한다.
	*	@pre	스택이 초기화 되어있어야한다.
	*	@post	m_curPos가 nullptr이 됨
	*/
	void ResetStack();

	/**
	*	@brief	m_curPos를 m_curPos->next로 갱신한다.
	*	@pre	스택이 비어있으면 안된다.
	*	@post	m_curPos가 갱신되고 data는 m_curPos->data로 갱신된다. 
	*	@return	m_curPos (or nullptr)
	*/
	NodeType<T>* GetNextItem(T& data);


private:
	NodeType<T>* m_stack;	///<	스택 리스트
	NodeType<T>* m_top;		///<	스택의 top
	NodeType<T>* m_curPos;  ///<	스택의 순차조회를 위한 반복자
	int m_length;			///<	스택의 길이
};

//기본 생성자
template <typename T>
stackType<T>::stackType() {
	m_length = 0;
	m_stack = nullptr;
	m_top = nullptr;
	m_curPos = nullptr;
}

//복사 생성자
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

//소멸자
template <typename T>
stackType<T>::~stackType() {
	MakeEmpty();
}

//스택에 새로운 노드를 push한다.
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

//스택에서 특정 노드를 pop한다.
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

//스택의 모든 노드를 삭제한다.
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

//스택의 길이를 반환한다.
template <typename T>
int stackType<T>::GetLength() {
	return m_length;
}

//스택이 꽉 찼는지 검사한다.
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

//스택이 비었는지 검사한다.
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

//m_curPos를 초기화한다.
template <typename T>
void stackType<T>::ResetStack() {
	m_curPos = nullptr;
}

//m_curPos를 m_curPos->next로 갱신한다.
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