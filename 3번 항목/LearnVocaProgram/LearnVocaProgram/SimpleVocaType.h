#include "VocaType.h"

#pragma once
class SimpleVocaType {
public:

	//�⺻������
	SimpleVocaType() {
		m_ptr = nullptr;
	}

	//m_ptr ���� �ʱ�ȭ�Ѵ�.
	void SetPtr(VocaType* ptr) {
		m_ptr = ptr;
	}

	//m_ptr�� ��ȯ�Ѵ�.
	VocaType* GetPtr() const {
		return m_ptr;
	}

	//���ڰ� ����Ű�� VocaType�� id���� ���ϰ� ���ں��� ������ true��ȯ, �ƴϸ� false
	bool operator < (const SimpleVocaType& s_voca) {
		return (m_ptr->GetId() < s_voca.GetPtr()->GetId());
	}

	//���ڰ� ����Ű�� VocaType�� id���� ���ϰ� ���ں��� ũ�� true��ȯ, �ƴϸ� false
	bool operator > (const SimpleVocaType& s_voca) {
		return (m_ptr->GetId() > s_voca.GetPtr()->GetId());
	}

	//���ڰ� ����Ű�� VocaType�� id���� ���ϰ� ���ڿ� ������ true��ȯ, �ƴϸ� false
	bool operator == (const SimpleVocaType& s_voca) {
		return (m_ptr->GetId() == s_voca.GetPtr()->GetId());
	}

	//m_id ���� �ʱ�ȭ�Ѵ�.
	/*
	void SetId(int id) {
		m_id = id;
	}
	*/

	//m_id�� ��ȯ�Ѵ�.
	/*
	int GetId() {
		return m_id;
	}
	*/

private:
	//int m_id;				//SimpleVoca�� ���� id��
	VocaType* m_ptr;		//SimplaVoca�� ������ ����
};