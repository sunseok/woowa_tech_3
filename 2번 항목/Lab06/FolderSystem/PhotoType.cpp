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
	cout << "\n\t�ش� ������ ���Ե� ������: ";
	cin >> m_includedFolderName;
}

//m_name�� ���� Ű����� �޾ƿ� ������ �����Ѵ�.
void PhotoType::SetNameFromKB() {
	cout << "\n\t������: ";
	cin >> m_name;
}

//PhotoType ��ü�� ���� Ű����� �޾ƿ� ������ �����Ѵ�.
void PhotoType::SetPhotoTypeFromKB() {
	cout << "\n\t--- �������� �Է� ---";
	SetIncludedFolderNameFromKB();
	SetNameFromKB();
}

//m_includedFolderName�� ȭ�鿡 ����Ѵ�.
void PhotoType::DisplayIncludedFolderNameOnScreen() {
	cout << "\n\t������ ���� ����: " << m_includedFolderName << endl;
}

//m_name�� ȭ�鿡 ����Ѵ�.
void PhotoType::DisplayNameOnScreen() {
	cout << "\n\t������: " << m_name << endl;
}

//m_createdTime�� ȭ�鿡 ����Ѵ�.
void PhotoType::DisplayCreatedTimeOnScreen() {
	cout << "\n\t�����ð�: " << m_createdTime << endl;
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
	time_t     now = time(0); //���� �ð��� time_t Ÿ������ ����
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "%Y%m%d%H%M%S", &tstruct); // YyyymmddhhMMSS ������ ��Ʈ��

	return buf;
}