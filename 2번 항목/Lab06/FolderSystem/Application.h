#include "PhotoType.h"
#include "FolderType.h"
#include<iostream>
#include<string>
using namespace std;


class Application {
public:
	/**
	*	기본 생성자
	*/
	Application();
	
	/**
	*	소멸자
	*/
	~Application();

	/**
	*	@brief	root폴더에 새로운 폴더를 추가한다.
	*	@pre	root폴더가 초기화 되어있어야한다.
	*	@post	root폴더에 새로운 폴더가 추가된다.
	*/
	void addFolderInterface();

	/**
	*	@brief	root폴더에서 특정 폴더를 삭제한다.
	*	@pre	root폴더가 초기화 되어있어야한다.
	*	@post	root폴더에서 특정 폴더가 삭제된다.
	*/
	void deleteFolderInterface();

	/**
	*	@brief	root폴더에 새로운 사진을 추가한다.
	*	@pre	root폴더가 초기화 되어있어야한다.
	*	@post	root폴더에 새로운 사진이 추가된다.
	*/
	void addPhotoInterface();

	/**
	*	@brief	root폴더에서 특정 사진을 삭제한다.
	*	@pre	root폴더가 초기화 되어있어야한다.
	*	@post	root폴더에서 특정 사진이 삭제된다.
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