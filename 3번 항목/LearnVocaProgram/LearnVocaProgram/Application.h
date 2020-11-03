#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include "QueueType.h"
#include "StackType.h"
#include "VocaType.h"
#include "SimpleVocaType.h"
#include "SortedArrayListType.h"
#include "SortedLinkedListType.h"
#include "User.h"
#include "SimpleUserType.h"
#include "SimpleUserType2.h"
#include "MaxHeap.h"
#include "UnsortedLinkedListType.h"
#define FILENAMESIZE 1024

using namespace std;

class Application {
public:
	Application();					//������
	void Run();						//���α׷� �����Լ�
	void LogIn();					//������ ����ܾ� �н� ���α׷��� �����Ѵ�.
	int GetCommand();				//���α׷� �����Լ����� ������� ����� �޴´�.
	int GetCommandLogIn();			//�н� ���α׷����� ������� ����� �Է¹޴´�.
	int GetCommandManageUser();		//������������ ������� ����� �޴´�.
	/**
	*	@brief      ������ �α��� ������ �Է¹ް� ������ �������� �˻��ϰ� ������ �з��Ѵ�.
	*	@pre	        ��������Ʈ�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post       m_curUser�� �α����� ������ ����Ű�� �ȴ�.
	*	@return     �α��ο� �����ϸ� 0, �Ϲ� ���� �α��ο� �����ϸ� 1, ������ �α��ο� �����ϸ� 2�� ��ȯ�Ѵ�.
	*/
	int VerifyLogIn();
	void LogOut();					//������ ����ܾ� �н� ���α׷����� ������.
	void CreateUser();				//������ �߰��Ѵ�.
	void DeleteUser();				//������ �����Ѵ�.
	void CheckAllUser();			//��� ���������� ȭ�鿡 ����Ѵ�.
	void EditUser();				//���� ������ �����Ѵ�.
	void ShowRanker();				//��Ŀ�� ������ ȭ�鿡 ����Ѵ�.
	void CheckMyInfo();				//���� ������ ������ ȭ�鿡 ����Ѵ�.
	void EditMyInfo();				//���� ������ ������ �����Ѵ�.
	void SearchVoca();			    //����ܾ �˻��Ѵ�.
	void TestVoca();				//����ܾ� ������ ����.
	void LearnVoca();				//����ܾ� �н� �����Լ�
	int GetCommandLearnLevel();	    //�н����� ���ÿ��� ������� ����� �Է¹޴´�.
	void SetLearnList(int level);	//�����н� �ܾ��Ʈ�� �Էµ� ������ �°� ä������.
	int ExecuteLearn();			    //�־��� �����н� �ܾ��Ʈ�� ���� �н��� �����Ѵ�.
	void ManageMyVocaList();		//�� �ܾ��� ���� �����Լ�
	int GetCommandMyVocaList();	    //�� �ܾ��� �������� ������� ����� �Է¹޴´�.
	void AddMyVoca();				//�� �ܾ��忡 ����ܾ �߰��Ѵ�.
	void DeleteMyVoca();			//�� �ܾ��忡�� ����ܾ �����Ѵ�.
	void InitWordBook();			//���α׷� ����ܾ ���Ϸκ��� �ʱ�ȭ�Ѵ�.

private:
	int m_command;										//����� ��ɾ�
	SortedArrayList<VocaType> m_AllVocaList;			//��� ����ܾ��Ʈ
	SortedArrayList<SimpleVocaType> m_AllSimpleList;	//��� ����� ����ܾ��Ʈ
	StackType<SimpleVocaType> m_TestVocaList;			//����ܾ� ����� ����Ʈ
	Queue<SimpleVocaType> m_LearnVocaList;				//����ܾ� �н��� ����Ʈ
	ifstream m_InFile;									//�Է����� ��ũ����
	ofstream m_OutFile;									//������� ��ũ����
	UnsortedLinkedList<UserType> m_AllUserList;			//��� ��������Ʈ
	SortedArrayList<SimpleUserType2> m_AllSimpleUList;	//��� ����� ��������Ʈ
	UserType* m_curUser;								//���� �α��ε� ����
	//SortedArrayList<SimpleUserType> m_RankerList;     //��Ŀ ����Ʈ
};
