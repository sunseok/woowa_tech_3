#include "Application.h"

//�⺻ ������
Application::Application() {
	m_command = 0;
	m_rootFolder = new FolderType;
	m_rootFolder->SetName("Root Folder");
	m_curFolder = nullptr;
}

//�Ҹ���
Application::~Application() {
	delete m_rootFolder;
}

//root������ ���ο� ������ �߰��Ѵ�.
void Application::addFolderInterface() {
	m_rootFolder->addFolder();
}

//root�������� Ư�� ������ �����Ѵ�.
void Application::deleteFolderInterface() {
	m_rootFolder->deleteFolder();
}

//root������ ���ο� ������ �߰��Ѵ�.
void Application::addPhotoInterface() {
	m_rootFolder->addPhoto();
}

//root�������� Ư�� ������ �����Ѵ�.
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
		case 1:		// ������ �߰��Ѵ�.
			addFolderInterface();
			break;
		case 2:		// ������ �����Ѵ�.
			deleteFolderInterface();
			break;
		case 3:		// root������ �����ϴ� ��� ���������� ����Ѵ�.
			m_rootFolder->DisplayFolderByName();
			break;
		case 4:		// root ������ �����Ѵ�.
			m_rootFolder->OpenFolder();
			break;
		case 5:		// ������ �߰��Ѵ�.
			addPhotoInterface();
			break;
		case 6:		// ������ �����Ѵ�.
			deletePhotoInterface();
			break;
		case 7:		// root������ �����ϴ� ��� ���������� ����Ѵ�.
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