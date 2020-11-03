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
	*	기본 생성자
	*/
	PhotoType();

	/**
	*	@brief	m_includedFolderName을 반환한다.
	*	@pre	m_includedFolderName이 초기화되어있어야한다.
	*	@post	없음
	*	@return	m_includedFolderName
	*/
	string GetIncludedFolderName();
	
	/**
	*	@brief	m_name을 반환한다.
	*	@pre	m_name이 초기화되어있어야한다.
	*	@post	없음
	*	@return	m_name
	*/
	string GetName();

	/**
	*	@brief	m_createdTime을 반환한다.
	*	@pre	m_createdTime이 초기화되어있어야한다.
	*	@post	없음
	*	@return	m_createdTime
	*/
	string GetCreatedTime();

	/**
	*	@brief	m_includedFolderName의 값을 갱신한다.
	*	@pre	없음
	*	@post	m_includedFolderName이 갱신된다.
	*	@param	string FolderName
	*/
	void SetIncludedFolderName(string FolderName);

	/**
	*	@brief	m_name의 값을 갱신한다.
	*	@pre	없음
	*	@post	m_name이 갱신된다.
	*	@param	string name
	*/
	void SetName(string Name);

	/**
	*	@brief	PhotoType 객체의 값을 갱신한다.
	*	@pre	없음
	*	@post	PhotoType 객체가 초기화된다.
	*	@param	FolderName	m_includedFolderName
	*	@param	Name	m_name
	*/
	void SetPhotoType(string FolderName, string Name);

	/**
	*	@brief	m_includedFolderName의 값을 키보드로 받아온 값으로 갱신한다.
	*	@pre	없음
	*	@post	m_includedFolderName 값이 갱신된다.
	*/
	void SetIncludedFolderNameFromKB();
	
	/**
	*	@brief	m_name의 값을 키보드로 받아온 값으로 갱신한다.
	*	@pre	없음
	*	@post	m_name 값이 갱신된다.
	*/
	void SetNameFromKB();

	/**
	*	@brief	PhotoType 객체의 값을 키보드로 받아온 값으로 갱신한다.
	*	@pre	없음
	*	@post	PhotoType 객체의 값이 갱신된다.
	*/
	void SetPhotoTypeFromKB();

	/**
	*	@brief	m_includedFolderName을 화면에 출력한다.
	*	@pre	m_includedFolderName이 초기화 되어있어야한다.
	*	@post	m_includedFolderName이 화면 상에 출력된다.
	*/
	void DisplayIncludedFolderNameOnScreen();

	/**
	*	@brief	m_name을 화면에 출력한다.
	*	@pre	m_name이 초기화 되어있어야한다.
	*	@post	m_name이 화면 상에 출력된다.
	*/
	void DisplayNameOnScreen();

	/**
	*	@brief	m_createdTime을 화면에 출력한다.
	*	@pre	m_createdTime이 초기화 되어있어야한다.
	*	@post	m_createdTime이 화면 상에 출력된다.
	*/
	void DisplayCreatedTimeOnScreen();
	
	/**
	*	@brief	PhotoType 객체의 정보를 화면에 출력한다.
	*	@pre	PhotoType 객체가 초기화 되어있어야한다.
	*	@post	PhotoType 객체의 정보가 화면에 출력된다.
	*/
	void DisplayPhotoTypeOnScreen();

	/**
	*	@brief	PhotoType이 크기가 작은지 검사한다.
	*	@pre	PhotoType 객체가 초기화되어있어야한다.
	*	@post	없음
	*	@return	PhotoType이 작으면 1, 그렇지 않으면 0을 반환 
	*	@param	PhotoType	p
	*/
	bool operator < (const PhotoType& p);

	/**
	*	@brief	PhotoType이 크기가 큰지 검사한다.
	*	@pre	PhotoType 객체가 초기화되어있어야한다.
	*	@post	없음
	*	@return	PhotoType이 크면 1, 그렇지 않으면 0을 반환
	*	@param	PhotoType	p
	*/
	bool operator > (const PhotoType& p);

	/**
	*	@brief	PhotoType이 크기가 같은지 검사한다.
	*	@pre	PhotoType 객체가 초기화되어있어야한다.
	*	@post	없음
	*	@return	PhotoType이 같으면 1, 그렇지 않으면 0을 반환
	*	@param	PhotoType	p
	*/
	bool operator == (const PhotoType& p);

	/**
	*	@brief	현재 시간을 반화한다.
	*	@pre	없음
	*	@post	없음
	*	@return	현재시간
	*/
	const string currentDateTime();

private:
	string m_includedFolderName;	///<	PhotoType이 포함된 폴더명
	string m_name;					///<	PhotoType의 이름(key값)
	string m_createdTime;			///<	PhotoType이 생성된 시간
};