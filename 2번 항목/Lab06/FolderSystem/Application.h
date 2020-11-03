#include "PhotoType.h"
#include "FolderType.h"
#include<iostream>
#include<string>
using namespace std;


class Application {
public:
	/**
	*	�⺻ ������
	*/
	Application();
	
	/**
	*	�Ҹ���
	*/
	~Application();

	/**
	*	@brief	root������ ���ο� ������ �߰��Ѵ�.
	*	@pre	root������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	root������ ���ο� ������ �߰��ȴ�.
	*/
	void addFolderInterface();

	/**
	*	@brief	root�������� Ư�� ������ �����Ѵ�.
	*	@pre	root������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	root�������� Ư�� ������ �����ȴ�.
	*/
	void deleteFolderInterface();

	/**
	*	@brief	root������ ���ο� ������ �߰��Ѵ�.
	*	@pre	root������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	root������ ���ο� ������ �߰��ȴ�.
	*/
	void addPhotoInterface();

	/**
	*	@brief	root�������� Ư�� ������ �����Ѵ�.
	*	@pre	root������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	root�������� Ư�� ������ �����ȴ�.
	*/
	void deletePhotoInterface();
	
	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();
private:
	int m_command;
	FolderType* m_rootFolder;
	FolderType* m_curFolder;
};