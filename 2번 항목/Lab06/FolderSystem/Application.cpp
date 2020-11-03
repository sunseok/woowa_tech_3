#include "Application.h"

//기본 생성자
Application::Application() {
	m_command = 0;
	m_rootFolder = new FolderType;
	m_rootFolder->SetName("Root Folder");
	m_curFolder = nullptr;
}

//소멸자
Application::~Application() {
	delete m_rootFolder;
}

//root폴더에 새로운 폴더를 추가한다.
void Application::addFolderInterface() {
	m_rootFolder->addFolder();
}

//root폴더에서 특정 폴더를 삭제한다.
void Application::deleteFolderInterface() {
	m_rootFolder->deleteFolder();
}

//root폴더에 새로운 사진을 추가한다.
void Application::addPhotoInterface() {
	m_rootFolder->addPhoto();
}

//root폴더에서 특정 사진을 삭제한다.
void Application::deletePhotoInterface() {
	m_rootFolder->deletePhoto();
}

//Program driver.
void Application::Run() {
	/*while (1)
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
		case 3:		// root폴더에 존재하는 모든 폴더정보를 출력한다.
			m_rootFolder->DisplayFolderByName();
			break;
		case 4:		// root 폴더에 진입한다.
			m_rootFolder->OpenFolder();
			break;
		case 5:		// 사진을 추가한다.
			addPhotoInterface();
			break;
		case 6:		// 사진을 삭제한다.
			deletePhotoInterface();
			break;
		case 7:		// root폴더에 존재하는 모든 사진정보를 출력한다.
			m_rootFolder->DisplayPhotoByName();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
	*/
	m_rootFolder->RunFolder();
}

//Display command on screen and get a input from keyboard.
int Application::GetCommand() {
	cout << endl << endl;
	cout << "\t--- Folder Name: Root Folder ----- " << endl;
	cout << "\t   1 : Add Folder" << endl;
	cout << "\t   2 : Delete Folder" << endl;
	cout << "\t   3 : Display All Folders in Root Folder" << endl;
	cout << "\t   4 : Click Folder" << endl;
	cout << "\t   5 : Add Photo" << endl;
	cout << "\t   6 : Delete Photo" << endl;
	cout << "\t   7 : Display All Photos in Root Folder" << endl;
	cout << "\t   0 : Exit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> m_command;
	cout << endl;

	return m_command;
}