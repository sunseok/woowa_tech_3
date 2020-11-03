#include "FolderType.h"

//기본 생성자
FolderType::FolderType() {
	m_name = " ";
	m_createdTime = currentDateTime();
	m_numberOfHavingFolder = 0;
	m_numberOfHavingPhoto = 0;
	m_command = 0;
}

////소멸자
//FolderType::~FolderType() {
//	m_FolderList.MakeEmpty();
//	m_PhotoList.MakeEmpty();
//}

//새로운 폴더를 해당 폴더에 추가한다.
void FolderType::addFolder() {
	FolderType tempFolder;				
	tempFolder.SetNameFromKB();
	if (!m_FolderList.Get(tempFolder)) {//같은 폴더명이 존재하는지 검사
		m_FolderList.Add(tempFolder);
		m_numberOfHavingFolder++;
	}
	else {								//같은 폴더명이 존재할 시
		cout << "\n\t이미 같은 폴더명이 존재합니다. 다시 시도해주세요.\n";
	}
}

//새로운 사진을 해당 폴더에 추가한다.
void FolderType::addPhoto() {
	PhotoType tempPhoto;
	tempPhoto.SetNameFromKB();
	tempPhoto.SetIncludedFolderName(this->GetName());
	if (!m_PhotoList.Get(tempPhoto)) {	//같은 폴더명이 존재하는지 검사
		m_PhotoList.Add(tempPhoto);
		m_numberOfHavingPhoto++;
	}
	else {								//같은 사진명이 존재할 시
		cout << "\n\t이미 같은 사진명이 존재합니다. 다시 시도해주세요.\n";
	}
}

//폴더를 해당 폴더에서 삭제한다.
void FolderType::deleteFolder() {
	FolderType tempFolder;
	tempFolder.SetNameFromKB();
	if (m_FolderList.Get(tempFolder)) {	//삭제하려는 폴더가 존재하는지 검사
		m_FolderList.Delete(tempFolder);
		m_numberOfHavingFolder--;
	}
	else {								//삭제하려는 폴더가 존재하지 않을 시
		cout << "\n\t삭제하려는 폴더가 존재하지 않습니다. 다시 시도해주세요.\n";
	}
}

//사진을 해당 폴더에서 삭제한다.
void FolderType::deletePhoto() {
	PhotoType tempPhoto;
	tempPhoto.SetNameFromKB();
	if (m_PhotoList.Get(tempPhoto)) {	//삭제하려는 사진이 존재하는지 검사
		m_PhotoList.Delete(tempPhoto);
		m_numberOfHavingPhoto--;
	}
	else {								//삭제하려는 사진이 존재하지 않을 시
		cout << "\n\t삭제하려는 사진이 존재하지 않습니다. 다시 시도해주세요.\n";
	}
}

//폴더의 명령어 권한에 진입한다.
void FolderType::RunFolder() {
	while (1)
	{
		m_command = GetCommand();

		switch (m_command)
		{
		case 1:		// 폴더를 추가한다.
			addFolder();
			break;
		case 2:		// 폴더를 삭제한다.
			deleteFolder();
			break;
		case 3:		// 폴더에 존재하는 모든 폴더정보를 출력한다.
			DisplayFolderByName();
			break;
		case 4:		// 특정 폴더에 진입한다.
			OpenFolder();
			break;
		case 5:		// 사진을 추가한다.
			addPhoto();
			break;
		case 6:		// 사진을 삭제한다.
			deletePhoto();
			break;
		case 7:		// 폴더에 존재하는 모든 사진정보를 출력한다.
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

//폴더에 진입한다.
void FolderType::OpenFolder() {
	if (!m_FolderList.IsEmpty()) {
		FolderType tempFolder;
		cout << "\n\t진입하려는 폴더명을 입력: ";
		tempFolder.SetNameFromKB();
		if (m_FolderList.Get(tempFolder)) {
			m_FolderList.GetCurData()->RunFolder();
		}
		else {
			cout << "\n\t입력한 폴더가 존재하지 않습니다.\n";
		}
	}
	else {
		cout << "\n\t폴더가 존재하지 않습니다.\n";
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

//FolderType 객체의 정보를 화면에 출력한다.
void FolderType::DisplayFolderTypeOnScreen() {
	cout << "\n\t--- 폴더정보 ---\n";
	cout << "\n\t폴더명: " << m_name << endl;
	cout << "\n\t생성시간: " << m_createdTime << endl;
	cout << "\n\t가진 폴더 갯수: " << m_numberOfHavingFolder << endl;
	cout << "\n\t가진 사진 갯수: " << m_numberOfHavingPhoto << endl;
}

//폴더 내의 모든 폴더를 이름 순으로 화면에 출력한다.
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
		cout << "\n\t폴더가 존재하지 않습니다.\n";
	}
}

//폴더 내의 모든 사진을 이름 순으로 화면에 출력한다.
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
		cout << "\n\t사진이 존재하지 않습니다.\n";
	}
}

//m_numberOfHavingPhoto를 반환한다.
int FolderType::GetNumberOfHavingPhoto() {
	return m_numberOfHavingPhoto;
}

//m_numberOfHavingFolder를 반환한다.
int FolderType::GetNumberOfHavingFolder() {
	return m_numberOfHavingFolder;
}

//m_name를 반환한다.
string FolderType::GetName() {
	return m_name;
}

//m_name의 값을 갱신한다.
void FolderType::SetName(string Name) {
	m_name = Name;
}

//m_name의 값을 키보드로 받아온 값으로 갱신한다.
void FolderType::SetNameFromKB() {
	cout << "\n\t폴더명: ";
	cin >> m_name;
}

//FolderType이 크기가 작은지 검사한다.
bool FolderType::operator<(const FolderType& f) {
	return(m_name.compare(f.m_name) < 0);
}

//FolderType이 크기가 큰지 검사한다.
bool FolderType::operator>(const FolderType& f) {
	return(m_name.compare(f.m_name) > 0);
}

//FolderType이 크기가 같은지 검사한다.
bool FolderType::operator==(const FolderType& f) {
	return(m_name.compare(f.m_name) == 0);
}

//현재 시간을 반환한다.
string const FolderType::currentDateTime() {
	time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "%Y%m%d%H%M%S", &tstruct); // YyyymmddhhMMSS 형태의 스트링

	return buf;
}