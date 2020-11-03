#include "Application.h"

//기본 생성자
Application::Application() {
	m_command = 0;
	m_rootFolder = new FolderType;
	m_rootFolder->SetName("Root");
	m_curFolder = m_rootFolder;
}

//소멸자
Application::~Application() {
	delete m_rootFolder;
}

//현재 폴더에 새로운 폴더를 추가한다.
void Application::addFolderInterface() {
	FolderType tempFolder;
    cout << "\n\t****** Add folder ******\n";
	tempFolder.SetNameFromKB();
	if (m_curFolder->addFolder(tempFolder)) {//새로운 Folder를 현재 폴더에 추가
		cout << "\n\tSuccess: adding folder.\n";
	}
	else {								//같은 폴더명이 존재할 시
		cout << "\n\tThere is a folder that already have same name, please retry\n";
	}
}

//현재 폴더에서 특정 폴더를 삭제한다.
void Application::deleteFolderInterface() {
    FolderType tempFolder;
    cout << "\n\t****** Delete folder ******\n";
    tempFolder.SetNameFromKB();
    if(m_curFolder->deleteFolder(tempFolder)) {////기존 Folder를 삭제
        cout << "\n\tSuccess: deleting folder.\n";
    }
    else {
        cout << "\n\tThere is no folder you input, please retry\n";
    }
}

//현재 폴더에 새로운 사진을 추가한다.
void Application::addPhotoInterface() {
    PhotoType tempPhoto;
    cout << "\n\t****** Add photo ******\n";
    tempPhoto.SetNameFromKB();
    if (m_curFolder->addPhoto(tempPhoto)) {//새로운 Photo를 현재 폴더에 추가
        cout << "\n\tSuccess: adding photo.\n";
    }
    else {                                //동일한 photo명이 존재할 시
        cout << "\n\tThere is a photo that already have same name, please retry\n";
    }
}

//현재 폴더에서 특정 사진을 삭제한다.
void Application::deletePhotoInterface() {
    PhotoType tempPhoto;
    cout << "\n\t****** Delete photo ******\n";
    tempPhoto.SetNameFromKB();
    if(m_curFolder->deletePhoto(tempPhoto)) {////기존 Folder를 삭제
        cout << "\n\tSuccess: deleting photo.\n";
    }
    else {
        cout << "\n\tThere is no photo you input, please retry\n";
    }
}

//현재 폴더에 속하는 폴더 중에 하나에 진입한다.
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
		case 1:		// 폴더를 추가한다.
			addFolderInterface();
			break;
		case 2:		// 폴더를 삭제한다.
			deleteFolderInterface();
			break;
		case 3:		// 현재 폴더에 존재하는 모든 폴더정보를 출력한다.
			m_curFolder->DisplayFolderByName();
			break;
		case 4:		// 현재 폴더에 존재하는 폴더들 중에 한 곳으로 진입한다.
			OpenFolder();
			break;
		case 5:		// 사진을 추가한다.
			addPhotoInterface();
			break;
		case 6:		// 사진을 삭제한다.
			deletePhotoInterface();
			break;
		case 7:		// 현재 폴더에 존재하는 모든 사진정보를 출력한다.
			m_curFolder->DisplayPhotoByName();
			break;
		case 8:		// 이전 폴더로 이동한다.
//          StackType에서 pop을 한 다음에 m_curFolder를 갱신한다.
//          예외처리: 만약 Root Folder가 이걸 시도한다면 default와 똑같이 처리한다.
            if(JumpToPreFolder()) {
                break;
            }
            else {
                cout << "\tIllegal selection...\n";
                break;
            }
        case 0:     // 예외처리: Root_Folder에서가 아니라면 프로그램을 나갈 수 없다.
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

//이전 폴더로 이동한다.
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

//현재 폴더의 경로를 출력한다.
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