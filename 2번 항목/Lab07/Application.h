#include "PhotoType.h"
#include "FolderType.h"
#include "StackType.h"
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
	*	@pre        	root������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	root������ ���ο� ������ �߰��ȴ�.
	*/
	void addFolderInterface();

	/**
	*	@brief	root�������� Ư�� ������ �����Ѵ�.
	*	@pre        	root������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	root�������� Ư�� ������ �����ȴ�.
	*/
	void deleteFolderInterface();

	/**
	*	@brief	root������ ���ο� ������ �߰��Ѵ�.
	*	@pre	        root������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	root������ ���ο� ������ �߰��ȴ�.
	*/
	void addPhotoInterface();

	/**
	*	@brief	root�������� Ư�� ������ �����Ѵ�.
	*	@pre	        root������ �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	root�������� Ư�� ������ �����ȴ�.
	*/
	void deletePhotoInterface();
	
    //������ �����Ѵ�
	void OpenFolder();

	/**
	*	@brief	Program driver.
	*	@pre        	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre        	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();
    
    //���� ������ �̵��Ѵ�.
    int JumpToPreFolder();
    
	//���� ������ ��θ� ����Ѵ�.
    void PrintPath();
private:
	int m_command;                  //��ɹ�ȣ
	FolderType* m_rootFolder;       //��Ʈ����
	FolderType* m_curFolder;        //���� ������ ����Ű�� ������ ������
    stackType<FolderType*> m_chase;  //���� ���Ա���� �����ϴ� ����
};
