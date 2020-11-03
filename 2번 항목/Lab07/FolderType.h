#pragma once
#include "SortedLinkedListType.h"
#include "PhotoType.h"
#include <ctime>
#include<string>

using namespace std;

class FolderType {
public:
	/**
	*	기본 생성자
	*/
	FolderType();

	/**
	*	소멸자
	*/
	//~FolderType();
	
	/**
	*	@brief	새로운 폴더를 해당 폴더에 추가한다.
	*	@pre	폴더리스트가 초기화 되어있어야한다.
	*	@post	해당 폴더에 새로운 폴더가 추가된다.
	*	@return	폴더가 성공적으로 추가되면 1 그렇지 않으면 0을 반환한다.
	*/
	int addFolder(FolderType& f);

	/**
	*	@brief	새로운 사진을 해당 폴더에 추가한다.
	*	@pre	        사진리스트가 초기화 되어있어야한다.
	*	@post	해당 폴더에 새로운 사진이 추가된다.
	*	@return	사진이 성공적으로 추가되면 1 그렇지 않으면 0을 반환한다.
	*/
	int addPhoto(PhotoType& p);

	/**
	*	@brief	폴더를 해당 폴더에서 삭제한다.
	*	@pre	        폴더리스트에 최소 하나의 폴더가 존재해야한다.
	*	@post	해당 폴더에서 폴더가 삭제된다.
	*	@return	폴더가 성공적으로 삭제되면 1 그렇지 않으면 0을 반환한다.
	*/
	int deleteFolder(FolderType& f);

	/**
	*	@brief	사진을 해당 폴더에서 삭제한다.
	*	@pre	        사진리스트에 최소 하나의 사진이 존재해야한다.
	*	@post	해당 폴더에서 사진이 삭제된다.
	*	@return	사진이 성공적으로 삭제되면 1 그렇지 않으면 0을 반환한다.
	*/
	int deletePhoto(PhotoType& p);

	/**
	*	@brief	폴더의 명령어 권한에 진입한다.
	*	@pre	        명령어 권한을 획득하려는 폴더가 초기화되어있어야한다.
	*	@post	폴더에 명령어 권한에 진입하게 된다.
	*/
	//void RunFolder();

	/**
	*	@brief	폴더에 진입한다.
	*	@pre	        진입하려는 폴더가 초기화되어있어야한다.
	*	@post	폴더에 진입하게 된다.
	*/
	void OpenFolder(FolderType& f, FolderType*& c);

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	//int GetCommand();

	/**
	*	@brief	FolderType 객체의 정보를 화면에 출력한다.
	*	@pre        	FolderType 객체가 초기화 되어있어야한다.
	*	@post	FolderType 객체의 정보가 화면에 출력된다.
	*/
	void DisplayFolderTypeOnScreen();

	/**
	*	@brief	폴더 내의 모든 폴더를 이름 순으로 화면에 출력한다.
	*	@pre	없음
	*	@post	없음
	*/
	void DisplayFolderByName();

	/**
	*	@brief	폴더의 이름을 출력한다.
	*	@pre	없음
	*	@post	없음
	*/
	void DisplayName();
	
	/**
	*	@brief	폴더 내의 모든 사진을 이름 순으로 화면에 출력한다.
	*	@pre	        없음
	*	@post	없음
	*/
	void DisplayPhotoByName();

	/**
	*	@brief	m_numberOfHavingPhoto를 반환한다.
	*	@pre	        m_numberOfHavingPhoto가 초기화되어있어야한다.
	*	@post	없음
	*	@return	m_numberOfHavingPhoto
	*/
	int GetNumberOfHavingPhoto();

	/**
	*	@brief	m_numberOfHavingFolder를 반환한다.
	*	@pre	        m_numberOfHavingFolder가 초기화되어있어야한다.
	*	@post	없음
	*	@return	m_numberOfHavingFolder
	*/
	int GetNumberOfHavingFolder();

	/**
	*	@brief	m_name를 반환한다.
	*	@pre	        m_name가 초기화되어있어야한다.
	*	@post	없음
	*	@return	m_name
	*/
	string GetName();

	/**
	*	@brief	m_name의 값을 갱신한다.
	*	@pre	        없음
	*	@post	m_name이 갱신된다.
	*/
	void SetName(string Name);

	/**
	*	@brief	m_name의 값을 키보드로 받아온 값으로 갱신한다.
	*	@pre	        없음
	*	@post	m_name 값이 갱신된다.
	*/
	void SetNameFromKB();

	/**
	*	@brief	FolderType이 크기가 작은지 검사한다.
	*	@pre	        FolderType 객체가 초기화되어있어야한다.
	*	@post	없음
	*	@return	FolderType이 작으면 1, 그렇지 않으면 0을 반환
	*/
	bool operator < (const FolderType& f);
	
	/**
	*	@brief	FolderType이 크기가 큰지 검사한다.
	*	@pre	        FolderType 객체가 초기화되어있어야한다.
	*	@post	없음
	*	@return	FolderType이 크면 1, 그렇지 않으면 0을 반환
	*/
	bool operator > (const FolderType& f);
	
	/**
	*	@brief	FolderType이 크기가 같은지 검사한다.
	*	@pre	        FolderType 객체가 초기화되어있어야한다.
	*	@post	없음
	*	@return	FolderType이 같으면 1, 그렇지 않으면 0을 반환
	*/
	bool operator == (const FolderType& f);

	/**
	*	@brief	현재 시간을 반환한다.
	*	@pre	없음
	*	@post	없음
	*	@return	현재시간
	*/
	const string currentDateTime();

    //폴더가 가진 폴더리스트의 포인터를 반환한다.
	SortedLinkedList<FolderType>* GetFList() {
		return &(m_FolderList);
	}
    
    //폴더가 가진 포토리스트의 포인터를 반환한다.
	SortedLinkedList<PhotoType>* GetPList() {
		return &(m_PhotoList);
	}

private:
	string m_name;								///<	폴더명(key값)
	string m_createdTime;						///<	폴더 생성시간
	int m_numberOfHavingPhoto;					///<	폴더가 갖고있는 사진의 수
	int m_numberOfHavingFolder;					///<	폴더가 갖고있는 폴더의 수
	SortedLinkedList<PhotoType> m_PhotoList;	///<	사진 리스트
	SortedLinkedList<FolderType> m_FolderList;	///<	폴더 리스트
};
