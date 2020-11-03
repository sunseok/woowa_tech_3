#include "PhotoType.h"

//�⺻ ������
PhotoType::PhotoType() {
	m_name = " ";
	m_includedFolderName = " ";
	m_createdTime = currentDateTime();
}

//m_includedFolderName�� ��ȯ�Ѵ�.
string PhotoType::GetIncludedFolderName() {
	return m_includedFolderName;
}

//	m_name�� ��ȯ�Ѵ�.
string PhotoType::GetName() {
	return m_name;
}

//m_createdTime�� ��ȯ�Ѵ�.
string PhotoType::GetCreatedTime() {
	return m_createdTime;
}

//m_includedFolderName�� ���� �����Ѵ�.
void PhotoType::SetIncludedFolderName(string FolderName) {
	m_includedFolderName = FolderName;
}

//m_name�� ���� �����Ѵ�.
void PhotoType::SetName(string Name) {
	m_name = Name;
}

//PhotoType ��ü�� ���� �����Ѵ�.
void PhotoType::SetPhotoType(string FolderName, string Name) {
	SetIncludedFolderName(FolderName);
	SetName(Name);
}

//m_includedFolderName�� ���� Ű����� �޾ƿ� ������ �����Ѵ�.
void PhotoType::SetIncludedFolderNameFromKB() {
	cout << "\n\tFolder name that this photo is included: ";
	cin >> m_includedFolderName;
}

//m_name�� ���� Ű����� �޾ƿ� ������ �����Ѵ�.
void PhotoType::SetNameFromKB() {
	cout << "\n\tPhoto name: ";
	cin >> m_name;
}

//PhotoType ��ü�� ���� Ű����� �޾ƿ� ������ �����Ѵ�.
void PhotoType::SetPhotoTypeFromKB() {
	cout << "\n\t--- Input photo info ---";
	SetIncludedFolderNameFromKB();
	SetNameFromKB();
}

//m_includedFolderName�� ȭ�鿡 ����Ѵ�.
void PhotoType::DisplayIncludedFolderNameOnScreen() {
	cout << "\n\tFolder that this photo is included: " << m_includedFolderName << endl;
}

//m_name�� ȭ�鿡 ����Ѵ�.
void PhotoType::DisplayNameOnScreen() {
	cout << "\n\tPhoto name: " << m_name << endl;
}

//m_createdTime�� ȭ�鿡 ����Ѵ�.
void PhotoType::DisplayCreatedTimeOnScreen() {
	cout << "\n\tCreated time: " << m_createdTime << endl;
}

//PhotoType ��ü�� ������ ȭ�鿡 ����Ѵ�.
void PhotoType::DisplayPhotoTypeOnScreen() {
	DisplayIncludedFolderNameOnScreen();
	DisplayNameOnScreen();
	DisplayCreatedTimeOnScreen();
}

//PhotoType�� ũ�Ⱑ ������ �˻��Ѵ�.
bool PhotoType::operator<(const PhotoType& p) {
	return (m_name.compare(p.m_name) < 0);
}

//PhotoType�� ũ�Ⱑ ū�� �˻��Ѵ�.
bool PhotoType::operator>(const PhotoType& p) {
	return (m_name.compare(p.m_name) > 0);
}

//PhotoType�� ũ�Ⱑ ������ �˻��Ѵ�.
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
