#pragma once
#include "SortedLinkedListType.h"
#include "PhotoType.h"
#include<string>

using namespace std;

class FolderType {
public:
	/**
	*	�⺻ ������
	*/
	FolderType();

	/**
	*	�Ҹ���
	*/
	//~FolderType();
	
	/**
	*	@brief	���ο� ������ �ش� ������ �߰��Ѵ�.
	*	@pre	��������Ʈ�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	�ش� ������ ���ο� ������ �߰��ȴ�.
	*	@return	������ ���������� �߰��Ǹ� 1 �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	void addFolder();

	/**
	*	@brief	���ο� ������ �ش� ������ �߰��Ѵ�.
	*	@pre	��������Ʈ�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	�ش� ������ ���ο� ������ �߰��ȴ�.
	*	@return	������ ���������� �߰��Ǹ� 1 �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	void addPhoto();

	/**
	*	@brief	������ �ش� �������� �����Ѵ�.
	*	@pre	��������Ʈ�� �ּ� �ϳ��� ������ �����ؾ��Ѵ�.
	*	@post	�ش� �������� ������ �����ȴ�.
	*	@return	������ ���������� �����Ǹ� 1 �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	void deleteFolder();

	/**
	*	@brief	������ �ش� �������� �����Ѵ�.
	*	@pre	��������Ʈ�� �ּ� �ϳ��� ������ �����ؾ��Ѵ�.
	*	@post	�ش� �������� ������ �����ȴ�.
	*	@return	������ ���������� �����Ǹ� 1 �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	void deletePhoto();

	/**
	*	@brief	������ ��ɾ� ���ѿ� �����Ѵ�.
	*	@pre	��ɾ� ������ ȹ���Ϸ��� ������ �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	������ ��ɾ� ���ѿ� �����ϰ� �ȴ�.
	*/
	void RunFolder();

	/**
	*	@brief	������ �����Ѵ�.
	*	@pre	�����Ϸ��� ������ �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	������ �����ϰ� �ȴ�.
	*/
	void OpenFolder();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	FolderType ��ü�� ������ ȭ�鿡 ����Ѵ�.
	*	@pre	FolderType ��ü�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	FolderType ��ü�� ������ ȭ�鿡 ��µȴ�.
	*/
	void DisplayFolderTypeOnScreen();

	/**
	*	@brief	���� ���� ��� ������ �̸� ������ ȭ�鿡 ����Ѵ�.
	*	@pre	����
	*	@post	����
	*/
	void DisplayFolderByName();
	
	/**
	*	@brief	���� ���� ��� ������ �̸� ������ ȭ�鿡 ����Ѵ�.
	*	@pre	����
	*	@post	����
	*/
	void DisplayPhotoByName();

	/**
	*	@brief	m_numberOfHavingPhoto�� ��ȯ�Ѵ�.
	*	@pre	m_numberOfHavingPhoto�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	m_numberOfHavingPhoto
	*/
	int GetNumberOfHavingPhoto();

	/**
	*	@brief	m_numberOfHavingFolder�� ��ȯ�Ѵ�.
	*	@pre	m_numberOfHavingFolder�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	m_numberOfHavingFolder
	*/
	int GetNumberOfHavingFolder();

	/**
	*	@brief	m_name�� ��ȯ�Ѵ�.
	*	@pre	m_name�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	m_name
	*/
	string GetName();

	/**
	*	@brief	m_name�� ���� �����Ѵ�.
	*	@pre	����
	*	@post	m_name�� ���ŵȴ�.
	*	@param	string Name
	*/
	void SetName(string Name);

	/**
	*	@brief	m_name�� ���� Ű����� �޾ƿ� ������ �����Ѵ�.
	*	@pre	����
	*	@post	m_name ���� ���ŵȴ�.
	*/
	void SetNameFromKB();

	/**
	*	@brief	FolderType�� ũ�Ⱑ ������ �˻��Ѵ�.
	*	@pre	FolderType ��ü�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	FolderType�� ������ 1, �׷��� ������ 0�� ��ȯ
	*	@param	FolderType	f
	*/
	bool operator < (const FolderType& f);
	
	/**
	*	@brief	FolderType�� ũ�Ⱑ ū�� �˻��Ѵ�.
	*	@pre	FolderType ��ü�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	FolderType�� ũ�� 1, �׷��� ������ 0�� ��ȯ
	*	@param	FolderType	f
	*/
	bool operator > (const FolderType& f);
	
	/**
	*	@brief	FolderType�� ũ�Ⱑ ������ �˻��Ѵ�.
	*	@pre	FolderType ��ü�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	FolderType�� ������ 1, �׷��� ������ 0�� ��ȯ
	*	@param	FolderType	f
	*/
	bool operator == (const FolderType& f);

	/**
	*	@brief	���� �ð��� ��ȯ�Ѵ�.
	*	@pre	����
	*	@post	����
	*	@return	����ð�
	*/
	const string currentDateTime();

private:
	string m_name;								///<	������(key��)
	string m_createdTime;						///<	���� �����ð�
	int m_numberOfHavingPhoto;					///<	������ �����ִ� ������ ��
	int m_numberOfHavingFolder;					///<	������ �����ִ� ������ ��
	SortedLinkedList<PhotoType> m_PhotoList;	///<	���� ����Ʈ
	SortedLinkedList<FolderType> m_FolderList;	///<	���� ����Ʈ
	int m_command;								///<	������ ��� ��ȣ
};