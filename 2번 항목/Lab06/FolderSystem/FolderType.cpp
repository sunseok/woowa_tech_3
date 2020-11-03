#include "FolderType.h"

//�⺻ ������
FolderType::FolderType() {
	m_name = " ";
	m_createdTime = currentDateTime();
	m_numberOfHavingFolder = 0;
	m_numberOfHavingPhoto = 0;
	m_command = 0;
}

////�Ҹ���
//FolderType::~FolderType() {
//	m_FolderList.MakeEmpty();
//	m_PhotoList.MakeEmpty();
//}

//���ο� ������ �ش� ������ �߰��Ѵ�.
void FolderType::addFolder() {
	FolderType tempFolder;				
	tempFolder.SetNameFromKB();
	if (!m_FolderList.Get(tempFolder)) {//���� �������� �����ϴ��� �˻�
		m_FolderList.Add(tempFolder);
		m_numberOfHavingFolder++;
	}
	else {								//���� �������� ������ ��
		cout << "\n\t�̹� ���� �������� �����մϴ�. �ٽ� �õ����ּ���.\n";
	}
}

//���ο� ������ �ش� ������ �߰��Ѵ�.
void FolderType::addPhoto() {
	PhotoType tempPhoto;
	tempPhoto.SetNameFromKB();
	tempPhoto.SetIncludedFolderName(this->GetName());
	if (!m_PhotoList.Get(tempPhoto)) {	//���� �������� �����ϴ��� �˻�
		m_PhotoList.Add(tempPhoto);
		m_numberOfHavingPhoto++;
	}
	else {								//���� �������� ������ ��
		cout << "\n\t�̹� ���� �������� �����մϴ�. �ٽ� �õ����ּ���.\n";
	}
}

//������ �ش� �������� �����Ѵ�.
void FolderType::deleteFolder() {
	FolderType tempFolder;
	tempFolder.SetNameFromKB();
	if (m_FolderList.Get(tempFolder)) {	//�����Ϸ��� ������ �����ϴ��� �˻�
		m_FolderList.Delete(tempFolder);
		m_numberOfHavingFolder--;
	}
	else {								//�����Ϸ��� ������ �������� ���� ��
		cout << "\n\t�����Ϸ��� ������ �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n";
	}
}

//������ �ش� �������� �����Ѵ�.
void FolderType::deletePhoto() {
	PhotoType tempPhoto;
	tempPhoto.SetNameFromKB();
	if (m_PhotoList.Get(tempPhoto)) {	//�����Ϸ��� ������ �����ϴ��� �˻�
		m_PhotoList.Delete(tempPhoto);
		m_numberOfHavingPhoto--;
	}
	else {								//�����Ϸ��� ������ �������� ���� ��
		cout << "\n\t�����Ϸ��� ������ �������� �ʽ��ϴ�. �ٽ� �õ����ּ���.\n";
	}
}

//������ ��ɾ� ���ѿ� �����Ѵ�.
void FolderType::RunFolder() {
	while (1)
	{
		m_command = GetCommand();

		switch (m_command)
		{
		case 1:		// ������ �߰��Ѵ�.
			addFolder();
			break;
		case 2:		// ������ �����Ѵ�.
			deleteFolder();
			break;
		case 3:		// ������ �����ϴ� ��� ���������� ����Ѵ�.
			DisplayFolderByName();
			break;
		case 4:		// Ư�� ������ �����Ѵ�.
			OpenFolder();
			break;
		case 5:		// ������ �߰��Ѵ�.
			addPhoto();
			break;
		case 6:		// ������ �����Ѵ�.
			deletePhoto();
			break;
		case 7:		// ������ �����ϴ� ��� ���������� ����Ѵ�.
			DisplayPhotoByName();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

//������ �����Ѵ�.
void FolderType::OpenFolder() {
	if (!m_FolderList.IsEmpty()) {
		FolderType tempFolder;
		cout << "\n\t�����Ϸ��� �������� �Է�: ";
		tempFolder.SetNameFromKB();
		if (m_FolderList.Get(tempFolder)) {
			m_FolderList.GetCurData()->RunFolder();
		}
		else {
			cout << "\n\t�Է��� ������ �������� �ʽ��ϴ�.\n";
		}
	}
	else {
		cout << "\n\t������ �������� �ʽ��ϴ�.\n";
	}
}

//Display command on screen and get a input from keyboard.
int FolderType::GetCommand() {
	cout << endl << endl;
	cout << "\t--- Folder Name: " << m_name << " ----- " << endl;
	cout << "\t   1 : Add Folder" << endl;
	cout << "\t   2 : Delete Folder" << endl;
	cout << "\t   3 : Display All Folders in this Folder" << endl;
	cout << "\t   4 : Click Folder" << endl;
	cout << "\t   5 : Add Photo" << endl;
	cout << "\t   6 : Delete Photo" << endl;
	cout << "\t   7 : Display All Photos in this Folder" << endl;
	cout << "\t   0 : Exit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> m_command;
	cout << endl;

	return m_command;
}

//FolderType ��ü�� ������ ȭ�鿡 ����Ѵ�.
void FolderType::DisplayFolderTypeOnScreen() {
	cout << "\n\t--- �������� ---\n";
	cout << "\n\t������: " << m_name << endl;
	cout << "\n\t�����ð�: " << m_createdTime << endl;
	cout << "\n\t���� ���� ����: " << m_numberOfHavingFolder << endl;
	cout << "\n\t���� ���� ����: " << m_numberOfHavingPhoto << endl;
}

//���� ���� ��� ������ �̸� ������ ȭ�鿡 ����Ѵ�.
void FolderType::DisplayFolderByName() {
	if (m_numberOfHavingFolder) {
		FolderType tempFolder;
		m_FolderList.ResetList();
		cout << "\n\t--- All Folder in Current Folder ---\n";
		for (int i = 0; i < m_numberOfHavingFolder; i++) {
			m_FolderList.GetNext(tempFolder);
			tempFolder.DisplayFolderTypeOnScreen();
		}
	}
	else {
		cout << "\n\t������ �������� �ʽ��ϴ�.\n";
	}
}

//���� ���� ��� ������ �̸� ������ ȭ�鿡 ����Ѵ�.
void FolderType::DisplayPhotoByName() {
	if (m_numberOfHavingPhoto) {
		PhotoType tempPhoto;
		m_PhotoList.ResetList();
		cout << "\n\t--- All Photo in Current Folder ---\n";
		for (int i = 0; i < m_numberOfHavingPhoto; i++) {
			m_PhotoList.GetNext(tempPhoto);
			tempPhoto.DisplayPhotoTypeOnScreen();
		}
	}
	else {
		cout << "\n\t������ �������� �ʽ��ϴ�.\n";
	}
}

//m_numberOfHavingPhoto�� ��ȯ�Ѵ�.
int FolderType::GetNumberOfHavingPhoto() {
	return m_numberOfHavingPhoto;
}

//m_numberOfHavingFolder�� ��ȯ�Ѵ�.
int FolderType::GetNumberOfHavingFolder() {
	return m_numberOfHavingFolder;
}

//m_name�� ��ȯ�Ѵ�.
string FolderType::GetName() {
	return m_name;
}

//m_name�� ���� �����Ѵ�.
void FolderType::SetName(string Name) {
	m_name = Name;
}

//m_name�� ���� Ű����� �޾ƿ� ������ �����Ѵ�.
void FolderType::SetNameFromKB() {
	cout << "\n\t������: ";
	cin >> m_name;
}

//FolderType�� ũ�Ⱑ ������ �˻��Ѵ�.
bool FolderType::operator<(const FolderType& f) {
	return(m_name.compare(f.m_name) < 0);
}

//FolderType�� ũ�Ⱑ ū�� �˻��Ѵ�.
bool FolderType::operator>(const FolderType& f) {
	return(m_name.compare(f.m_name) > 0);
}

//FolderType�� ũ�Ⱑ ������ �˻��Ѵ�.
bool FolderType::operator==(const FolderType& f) {
	return(m_name.compare(f.m_name) == 0);
}

//���� �ð��� ��ȯ�Ѵ�.
string const FolderType::currentDateTime() {
	time_t     now = time(0); //���� �ð��� time_t Ÿ������ ����
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "%Y%m%d%H%M%S", &tstruct); // YyyymmddhhMMSS ������ ��Ʈ��

	return buf;
}