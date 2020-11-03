#include "Application.h"

//�⺻ ������
Application::Application() {
	m_command = 0;
	m_rootFolder = new FolderType;
	m_rootFolder->SetName("Root");
	m_curFolder = m_rootFolder;
}

//�Ҹ���
Application::~Application() {
	delete m_rootFolder;
}

//���� ������ ���ο� ������ �߰��Ѵ�.
void Application::addFolderInterface() {
	FolderType tempFolder;
    cout << "\n\t****** Add folder ******\n";
	tempFolder.SetNameFromKB();
	if (m_curFolder->addFolder(tempFolder)) {//���ο� Folder�� ���� ������ �߰�
		cout << "\n\tSuccess: adding folder.\n";
	}
	else {								//���� �������� ������ ��
		cout << "\n\tThere is a folder that already have same name, please retry\n";
	}
}

//���� �������� Ư�� ������ �����Ѵ�.
void Application::deleteFolderInterface() {
    FolderType tempFolder;
    cout << "\n\t****** Delete folder ******\n";
    tempFolder.SetNameFromKB();
    if(m_curFolder->deleteFolder(tempFolder)) {////���� Folder�� ����
        cout << "\n\tSuccess: deleting folder.\n";
    }
    else {
        cout << "\n\tThere is no folder you input, please retry\n";
    }
}

//���� ������ ���ο� ������ �߰��Ѵ�.
void Application::addPhotoInterface() {
    PhotoType tempPhoto;
    cout << "\n\t****** Add photo ******\n";
    tempPhoto.SetNameFromKB();
    if (m_curFolder->addPhoto(tempPhoto)) {//���ο� Photo�� ���� ������ �߰�
        cout << "\n\tSuccess: adding photo.\n";
    }
    else {                                //������ photo���� ������ ��
        cout << "\n\tThere is a photo that already have same name, please retry\n";
    }
}

//���� �������� Ư�� ������ �����Ѵ�.
void Application::deletePhotoInterface() {
    PhotoType tempPhoto;
    cout << "\n\t****** Delete photo ******\n";
    tempPhoto.SetNameFromKB();
    if(m_curFolder->deletePhoto(tempPhoto)) {////���� Folder�� ����
        cout << "\n\tSuccess: deleting photo.\n";
    }
    else {
        cout << "\n\tThere is no photo you input, please retry\n";
    }
}

//���� ������ ���ϴ� ���� �߿� �ϳ��� �����Ѵ�.
void Application::OpenFolder() {
	if (!(m_curFolder->GetFList()->IsEmpty())) {
		FolderType tempFolder;
		cout << "\n\tInput folder name you'll entry: ";
		tempFolder.SetNameFromKB();
        m_chase.Push(m_curFolder);
        m_curFolder->OpenFolder(tempFolder, m_curFolder);
	}
	else {
		cout << "\n\tThere are no folders.\n";
	}
}

//Program driver.
void Application::Run() {
	while (1)
	{
		m_command = GetCommand();

		switch (m_command)
		{
		case 1:		// ������ �߰��Ѵ�.
			addFolderInterface();
			break;
		case 2:		// ������ �����Ѵ�.
			deleteFolderInterface();
			break;
		case 3:		// ���� ������ �����ϴ� ��� ���������� ����Ѵ�.
			m_curFolder->DisplayFolderByName();
			break;
		case 4:		// ���� ������ �����ϴ� ������ �߿� �� ������ �����Ѵ�.
			OpenFolder();
			break;
		case 5:		// ������ �߰��Ѵ�.
			addPhotoInterface();
			break;
		case 6:		// ������ �����Ѵ�.
			deletePhotoInterface();
			break;
		case 7:		// ���� ������ �����ϴ� ��� ���������� ����Ѵ�.
			m_curFolder->DisplayPhotoByName();
			break;
		case 8:		// ���� ������ �̵��Ѵ�.
//          StackType���� pop�� �� ������ m_curFolder�� �����Ѵ�.
//          ����ó��: ���� Root Folder�� �̰� �õ��Ѵٸ� default�� �Ȱ��� ó���Ѵ�.
            if(JumpToPreFolder()) {
                break;
            }
            else {
                cout << "\tIllegal selection...\n";
                break;
            }
        case 0:     // ����ó��: Root_Folder������ �ƴ϶�� ���α׷��� ���� �� ����.
            if(m_curFolder == m_rootFolder) {
                return;
            }
            else {
                cout << "\tIllegal selection...\n";
                break;
            }
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

//Display command on screen and get a input from keyboard.
int Application::GetCommand() {
	cout << endl << endl;
	cout << "\t--- Command Lists ---" << endl;
	cout << "\t   1 : Add Folder" << endl;
	cout << "\t   2 : Delete Folder" << endl;
	cout << "\t   3 : Display All Folders" << endl;
	cout << "\t   4 : Entry Folder" << endl;
	cout << "\t   5 : Add Photo" << endl;
	cout << "\t   6 : Delete Photo" << endl;
	cout << "\t   7 : Display All Photos" << endl;
    if(m_curFolder != m_rootFolder) {
        cout << "\t   8 : Jump to pre folder" << endl;
    }
    if(m_curFolder == m_rootFolder) {
        cout << "\t   0 : Exit" << endl;
    }
	cout << endl << "\tCD:";
	PrintPath();
	cout << m_curFolder->GetName() << ">";
	cin >> m_command;
	cout << endl;

	return m_command;
}

//���� ������ �̵��Ѵ�.
int Application::JumpToPreFolder() {
    if(m_curFolder != m_rootFolder) {
        m_chase.Pop(m_curFolder);
        return 1;
    }
    else {
        return 0;
    }
}
//
//void Application::PrintCurPath() {
//    cout << endl;
//    if(m_curFolder == m_rootFolder) {
//        cout << "\troot ->";
//    }
//    else {
//        FolderType* tempFolder;
//        stackType<FolderType*> tempPath;
//        stackType<FolderType*> tempPath2;
//        tempPath = m_path;
//        int length = tempPath.GetLength();
//        for(int i = 0; i < length ; i++) {
//            tempPath.Pop(tempFolder);
//            tempPath2.Push(tempFolder);
//        }
//
//        cout << "\t";
//        for(int i = 0; i < length; i++) {
//            tempPath2.Pop(tempFolder);
//            cout << tempFolder->GetName() << "/";
//        }
//        cout << " ->";
//    }
//}

//���� ������ ��θ� ����Ѵ�.
void Application::PrintPath() {
	if (m_chase.isEmpty()) {
		return;
	}
	else {
		FolderType* dummy = nullptr;
		m_chase.ResetStack();
		while (m_chase.GetNextItem(dummy) != nullptr) {
			dummy->DisplayName();
			cout << "/";
		}
		return;
	}
}