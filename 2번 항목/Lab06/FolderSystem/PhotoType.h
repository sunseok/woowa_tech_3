#pragma once

#include<iostream>
#include<string>
#include <time.h>

using namespace std;

/**
*	Photo infomation class
*/
class PhotoType {
public:
	/**
	*	�⺻ ������
	*/
	PhotoType();

	/**
	*	@brief	m_includedFolderName�� ��ȯ�Ѵ�.
	*	@pre	m_includedFolderName�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	m_includedFolderName
	*/
	string GetIncludedFolderName();
	
	/**
	*	@brief	m_name�� ��ȯ�Ѵ�.
	*	@pre	m_name�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	m_name
	*/
	string GetName();

	/**
	*	@brief	m_createdTime�� ��ȯ�Ѵ�.
	*	@pre	m_createdTime�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	m_createdTime
	*/
	string GetCreatedTime();

	/**
	*	@brief	m_includedFolderName�� ���� �����Ѵ�.
	*	@pre	����
	*	@post	m_includedFolderName�� ���ŵȴ�.
	*	@param	string FolderName
	*/
	void SetIncludedFolderName(string FolderName);

	/**
	*	@brief	m_name�� ���� �����Ѵ�.
	*	@pre	����
	*	@post	m_name�� ���ŵȴ�.
	*	@param	string name
	*/
	void SetName(string Name);

	/**
	*	@brief	PhotoType ��ü�� ���� �����Ѵ�.
	*	@pre	����
	*	@post	PhotoType ��ü�� �ʱ�ȭ�ȴ�.
	*	@param	FolderName	m_includedFolderName
	*	@param	Name	m_name
	*/
	void SetPhotoType(string FolderName, string Name);

	/**
	*	@brief	m_includedFolderName�� ���� Ű����� �޾ƿ� ������ �����Ѵ�.
	*	@pre	����
	*	@post	m_includedFolderName ���� ���ŵȴ�.
	*/
	void SetIncludedFolderNameFromKB();
	
	/**
	*	@brief	m_name�� ���� Ű����� �޾ƿ� ������ �����Ѵ�.
	*	@pre	����
	*	@post	m_name ���� ���ŵȴ�.
	*/
	void SetNameFromKB();

	/**
	*	@brief	PhotoType ��ü�� ���� Ű����� �޾ƿ� ������ �����Ѵ�.
	*	@pre	����
	*	@post	PhotoType ��ü�� ���� ���ŵȴ�.
	*/
	void SetPhotoTypeFromKB();

	/**
	*	@brief	m_includedFolderName�� ȭ�鿡 ����Ѵ�.
	*	@pre	m_includedFolderName�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	m_includedFolderName�� ȭ�� �� ��µȴ�.
	*/
	void DisplayIncludedFolderNameOnScreen();

	/**
	*	@brief	m_name�� ȭ�鿡 ����Ѵ�.
	*	@pre	m_name�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	m_name�� ȭ�� �� ��µȴ�.
	*/
	void DisplayNameOnScreen();

	/**
	*	@brief	m_createdTime�� ȭ�鿡 ����Ѵ�.
	*	@pre	m_createdTime�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	m_createdTime�� ȭ�� �� ��µȴ�.
	*/
	void DisplayCreatedTimeOnScreen();
	
	/**
	*	@brief	PhotoType ��ü�� ������ ȭ�鿡 ����Ѵ�.
	*	@pre	PhotoType ��ü�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	PhotoType ��ü�� ������ ȭ�鿡 ��µȴ�.
	*/
	void DisplayPhotoTypeOnScreen();

	/**
	*	@brief	PhotoType�� ũ�Ⱑ ������ �˻��Ѵ�.
	*	@pre	PhotoType ��ü�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	PhotoType�� ������ 1, �׷��� ������ 0�� ��ȯ 
	*	@param	PhotoType	p
	*/
	bool operator < (const PhotoType& p);

	/**
	*	@brief	PhotoType�� ũ�Ⱑ ū�� �˻��Ѵ�.
	*	@pre	PhotoType ��ü�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	PhotoType�� ũ�� 1, �׷��� ������ 0�� ��ȯ
	*	@param	PhotoType	p
	*/
	bool operator > (const PhotoType& p);

	/**
	*	@brief	PhotoType�� ũ�Ⱑ ������ �˻��Ѵ�.
	*	@pre	PhotoType ��ü�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	PhotoType�� ������ 1, �׷��� ������ 0�� ��ȯ
	*	@param	PhotoType	p
	*/
	bool operator == (const PhotoType& p);

	/**
	*	@brief	���� �ð��� ��ȭ�Ѵ�.
	*	@pre	����
	*	@post	����
	*	@return	����ð�
	*/
	const string currentDateTime();

private:
	string m_includedFolderName;	///<	PhotoType�� ���Ե� ������
	string m_name;					///<	PhotoType�� �̸�(key��)
	string m_createdTime;			///<	PhotoType�� ������ �ð�
};