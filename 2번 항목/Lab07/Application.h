#include "PhotoType.h"
#include "FolderType.h"
#include "StackType.h"
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
	*	@pre        	root폴더가 초기화 되어있어야한다.
	*	@post	root폴더에 새로운 폴더가 추가된다.
	*/
	void addFolderInterface();

	/**
	*	@brief	root폴더에서 특정 폴더를 삭제한다.
	*	@pre        	root폴더가 초기화 되어있어야한다.
	*	@post	root폴더에서 특정 폴더가 삭제된다.
	*/
	void deleteFolderInterface();

	/**
	*	@brief	root폴더에 새로운 사진을 추가한다.
	*	@pre	        root폴더가 초기화 되어있어야한다.
	*	@post	root폴더에 새로운 사진이 추가된다.
	*/
	void addPhotoInterface();

	/**
	*	@brief	root폴더에서 특정 사진을 삭제한다.
	*	@pre	        root폴더가 초기화 되어있어야한다.
	*	@post	root폴더에서 특정 사진이 삭제된다.
	*/
	void deletePhotoInterface();
	
    //폴더에 진입한다
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
    
    //이전 폴더로 이동한다.
    int JumpToPreFolder();
    
	//현재 폴더의 경로를 출력한다.
    void PrintPath();
private:
	int m_command;                  //명령번호
	FolderType* m_rootFolder;       //루트폴더
	FolderType* m_curFolder;        //현재 폴더를 가리키는 폴더형 포인터
    stackType<FolderType*> m_chase;  //폴더 진입기록을 저장하는 스택
};
