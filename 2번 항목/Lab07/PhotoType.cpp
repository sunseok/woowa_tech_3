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
	cout << "\n\tFolder name that this photo is included: ";
	cin >> m_includedFolderName;
}

//m_name의 값을 키보드로 받아온 값으로 갱신한다.
void PhotoType::SetNameFromKB() {
	cout << "\n\tPhoto name: ";
	cin >> m_name;
}

//PhotoType 객체의 값을 키보드로 받아온 값으로 갱신한다.
void PhotoType::SetPhotoTypeFromKB() {
	cout << "\n\t--- Input photo info ---";
	SetIncludedFolderNameFromKB();
	SetNameFromKB();
}

//m_includedFolderName을 화면에 출력한다.
void PhotoType::DisplayIncludedFolderNameOnScreen() {
	cout << "\n\tFolder that this photo is included: " << m_includedFolderName << endl;
}

//m_name을 화면에 출력한다.
void PhotoType::DisplayNameOnScreen() {
	cout << "\n\tPhoto name: " << m_name << endl;
}

//m_createdTime을 화면에 출력한다.
void PhotoType::DisplayCreatedTimeOnScreen() {
	cout << "\n\tCreated time: " << m_createdTime << endl;
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
	time_t now = time(NULL);
    tm* ptm = localtime(&now);
    char buffer[32];
    strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
    string date = buffer;
    return date;
}
