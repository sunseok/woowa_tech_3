#include "FolderType.h"

//�⺻ ������
FolderType::FolderType() {
	m_name = " ";
	m_createdTime = currentDateTime();
	m_numberOfHavingFolder = 0;
	m_numberOfHavingPhoto = 0;
}

////�Ҹ���
//  FolderType::~FolderType() {
//	m_FolderList.MakeEmpty();
//	m_PhotoList.MakeEmpty();
//}

//���ο� ������ �ش� ������ �߰��Ѵ�.
int FolderType::addFolder(FolderType& f) {
	if (!m_FolderList.Get(f)) {//���� �������� �����ϴ��� �˻�
        if(m_FolderList.Add(f)) {
            m_numberOfHavingFolder++;
            return 1;
        }
        else {
            return 0;
        }
	}
	else {								//���� �������� ������ ��
		return 0;
	}
}

//���ο� ������ �ش� ������ �߰��Ѵ�.
int FolderType::addPhoto(PhotoType& p) {
	p.SetIncludedFolderName(this->GetName());
	if (!m_PhotoList.Get(p)) {	//���� �������� �����ϴ��� �˻�
        if(m_PhotoList.Add(p)) {
            m_numberOfHavingPhoto++;
            return 1;
        }
        else {
            return 0;
        }
	}
	else {								//���� �������� ������ ��
        return 0;
	}
}

//������ �ش� �������� �����Ѵ�.
int FolderType::deleteFolder(FolderType& f) {
	if (m_FolderList.Get(f)) {	//�����Ϸ��� ������ �����ϴ��� �˻�
        if(m_FolderList.Delete(f)) {
            m_numberOfHavingFolder--;
            return 1;
        }
        else {
            return 0;
        }
	}
	else {								//�����Ϸ��� ������ �������� ���� ��
        return 0;
	}
}

//������ �ش� �������� �����Ѵ�.
int FolderType::deletePhoto(PhotoType& p) {
	if (m_PhotoList.Get(p)) {	//�����Ϸ��� ������ �����ϴ��� �˻�
        if(m_PhotoList.Delete(p)) {
            m_numberOfHavingPhoto--;
            return 1;
        }
        else {
            return 0;
        }
	}
	else {								//�����Ϸ��� ������ �������� ���� ��
        return 0;
	}
}

//������ ��ɾ� ���ѿ� �����Ѵ�.
//void FolderType::RunFolder() {
//	while (1)
//	{
//		m_command = GetCommand();
//
//		switch (m_command)
//		{
//		case 1:		// ������ �߰��Ѵ�.
//			addFolder();
//			break;
//		case 2:		// ������ �����Ѵ�.
//			deleteFolder();
//			break;
//		case 3:		// ������ �����ϴ� ��� ���������� ����Ѵ�.
//			DisplayFolderByName();
//			break;
//		case 4:		// Ư�� ������ �����Ѵ�.
//			OpenFolder();
//			break;
//		case 5:		// ������ �߰��Ѵ�.
//			addPhoto();
//			break;
//		case 6:		// ������ �����Ѵ�.
//			deletePhoto();
//			break;
//		case 7:		// ������ �����ϴ� ��� ���������� ����Ѵ�.
//			DisplayPhotoByName();
//			break;
//		case 0:
//			return;
//		default:
//			cout << "\tIllegal selection...\n";
//			break;
//		}
//	}
//}

//������ �����Ѵ�.
void FolderType::OpenFolder(FolderType& f, FolderType*& c) {
	if (!m_FolderList.IsEmpty()) {
//		FolderType tempFolder;
//		cout << "\n\tInput folder name you'll entry: ";
//		tempFolder.SetNameFromKB();
		if (m_FolderList.Get(f)) {
			c = m_FolderList.GetCurData();
		}
		else {
			cout << "\n\tThere is not exist folder you input.\n";
		}
	}
	else {
		cout << "\n\tThere are no folders\n";
	}
}

//Display command on screen and get a input from keyboard.
//int FolderType::GetCommand() {
//	cout << endl << endl;
//	cout << "\t--- Folder Name: " << m_name << " ----- " << endl;
//	cout << "\t   1 : Add Folder" << endl;
//	cout << "\t   2 : Delete Folder" << endl;
//	cout << "\t   3 : Display All Folders in this Folder" << endl;
//	cout << "\t   4 : Click Folder" << endl;
//	cout << "\t   5 : Add Photo" << endl;
//	cout << "\t   6 : Delete Photo" << endl;
//	cout << "\t   7 : Display All Photos in this Folder" << endl;
//	cout << "\t   0 : Exit" << endl;
//
//	cout << endl << "\t Choose a Command--> ";
//	cin >> m_command;
//	cout << endl;
//
//	return m_command;
//}

//FolderType ��ü�� ������ ȭ�鿡 ����Ѵ�.
void FolderType::DisplayFolderTypeOnScreen() {
	cout << "\n\tFolder name: " << m_name << endl;
	cout << "\n\tCreated time: " << m_createdTime << endl;
	cout << "\n\tHaving folders: " << m_numberOfHavingFolder << endl;
	cout << "\n\tHaving Photos: " << m_numberOfHavingPhoto << endl;
}

//���� ���� ��� ������ �̸� ������ ȭ�鿡 ����Ѵ�.
void FolderType::DisplayFolderByName() {
	if (m_numberOfHavingFolder) {
        int cnt = 1;
		FolderType tempFolder;
		m_FolderList.ResetList();
		cout << "\n\t--- All Folder in Current Folder ---\n";
		for (int i = 0; i < m_numberOfHavingFolder; i++) {
            cout << "\n\t" << cnt++ << ". folder: \n";
			m_FolderList.GetNext(tempFolder);
			tempFolder.DisplayFolderTypeOnScreen();
		}
	}
	else {
		cout << "\n\tThere are no folders.\n";
	}
}

//������ �̸��� ȭ�鿡 ����Ѵ�.
void FolderType::DisplayName() { 
	cout << m_name;
	return;
}

//���� ���� ��� ������ �̸� ������ ȭ�鿡 ����Ѵ�.
void FolderType::DisplayPhotoByName() {
	if (m_numberOfHavingPhoto) {
        int cnt = 1;
		PhotoType tempPhoto;
		m_PhotoList.ResetList();
		cout << "\n\t--- All Photo in Current Folder ---\n";
		for (int i = 0; i < m_numberOfHavingPhoto; i++) {
            cout << "\n\t" << cnt++ << ". photo: \n";
			m_PhotoList.GetNext(tempPhoto);
			tempPhoto.DisplayPhotoTypeOnScreen();
		}
	}
	else {
		cout << "\n\tThere are no photos.\n";
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
	cout << "\n\tFolder name: ";
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
	time_t now = time(NULL);
    tm* ptm = localtime(&now);
    char buffer[32];
    strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
    string date = buffer;
    return date;
}
