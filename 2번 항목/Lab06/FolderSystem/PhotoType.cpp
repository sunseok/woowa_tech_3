#include "PhotoType.h"

//기본 생성자
PhotoType::PhotoType() {
	m_name = " ";
	m_includedFolderName = " ";
	m_createdTime = currentDateTime();
}

//m_includedFolderName을 반환한다.
string PhotoType::GetIncludedFolderName() {
	return m_includedFolderName;
}

//	m_name을 반환한다.
string PhotoType::GetName() {
	return m_name;
}

//m_createdTime을 반환한다.
string PhotoType::GetCreatedTime() {
	return m_createdTime;
}

//m_includedFolderName의 값을 갱신한다.
void PhotoType::SetIncludedFolderName(string FolderName) {
	m_includedFolderName = FolderName;
}

//m_name의 값을 갱신한다.
void PhotoType::SetName(string Name) {
	m_name = Name;
}

//PhotoType 객체의 값을 갱신한다.
void PhotoType::SetPhotoType(string FolderName, string Name) {
	SetIncludedFolderName(FolderName);
	SetName(Name);
}

//m_includedFolderName의 값을 키보드로 받아온 값으로 갱신한다.
void PhotoType::SetIncludedFolderNameFromKB() {
	cout << "\n\t해당 사진이 포함된 폴더명: ";
	cin >> m_includedFolderName;
}

//m_name의 값을 키보드로 받아온 값으로 갱신한다.
void PhotoType::SetNameFromKB() {
	cout << "\n\t사진명: ";
	cin >> m_name;
}

//PhotoType 객체의 값을 키보드로 받아온 값으로 갱신한다.
void PhotoType::SetPhotoTypeFromKB() {
	cout << "\n\t--- 사진정보 입력 ---";
	SetIncludedFolderNameFromKB();
	SetNameFromKB();
}

//m_includedFolderName을 화면에 출력한다.
void PhotoType::DisplayIncludedFolderNameOnScreen() {
	cout << "\n\t사진이 속한 폴더: " << m_includedFolderName << endl;
}

//m_name을 화면에 출력한다.
void PhotoType::DisplayNameOnScreen() {
	cout << "\n\t사진명: " << m_name << endl;
}

//m_createdTime을 화면에 출력한다.
void PhotoType::DisplayCreatedTimeOnScreen() {
	cout << "\n\t생성시간: " << m_createdTime << endl;
}

//PhotoType 객체의 정보를 화면에 출력한다.
void PhotoType::DisplayPhotoTypeOnScreen() {
	DisplayIncludedFolderNameOnScreen();
	DisplayNameOnScreen();
	DisplayCreatedTimeOnScreen();
}

//PhotoType이 크기가 작은지 검사한다.
bool PhotoType::operator<(const PhotoType& p) {
	return (m_name.compare(p.m_name) < 0);
}

//PhotoType이 크기가 큰지 검사한다.
bool PhotoType::operator>(const PhotoType& p) {
	return (m_name.compare(p.m_name) > 0);
}

//PhotoType이 크기가 같은지 검사한다.
bool PhotoType::operator==(const PhotoType& p) {
	return (m_name.compare(p.m_name) == 0);
}

string const PhotoType::currentDateTime() {
	time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "%Y%m%d%H%M%S", &tstruct); // YyyymmddhhMMSS 형태의 스트링

	return buf;
}