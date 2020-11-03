#include "FolderType.h"

//기본 생성자
FolderType::FolderType() {
	m_name = " ";
	m_createdTime = currentDateTime();
	m_numberOfHavingFolder = 0;
	m_numberOfHavingPhoto = 0;
}

////소멸자
//  FolderType::~FolderType() {
//	m_FolderList.MakeEmpty();
//	m_PhotoList.MakeEmpty();
//}

//새로운 폴더를 해당 폴더에 추가한다.
int FolderType::addFolder(FolderType& f) {
	if (!m_FolderList.Get(f)) {//같은 폴더명이 존재하는지 검사
        if(m_FolderList.Add(f)) {
            m_numberOfHavingFolder++;
            return 1;
        }
        else {
            return 0;
        }
	}
	else {								//같은 폴더명이 존재할 시
		return 0;
	}
}

//새로운 사진을 해당 폴더에 추가한다.
int FolderType::addPhoto(PhotoType& p) {
	p.SetIncludedFolderName(this->GetName());
	if (!m_PhotoList.Get(p)) {	//같은 폴더명이 존재하는지 검사
        if(m_PhotoList.Add(p)) {
            m_numberOfHavingPhoto++;
            return 1;
        }
        else {
            return 0;
        }
	}
	else {								//같은 사진명이 존재할 시
        return 0;
	}
}

//폴더를 해당 폴더에서 삭제한다.
int FolderType::deleteFolder(FolderType& f) {
	if (m_FolderList.Get(f)) {	//삭제하려는 폴더가 존재하는지 검사
        if(m_FolderList.Delete(f)) {
            m_numberOfHavingFolder--;
            return 1;
        }
        else {
            return 0;
        }
	}
	else {								//삭제하려는 폴더가 존재하지 않을 시
        return 0;
	}
}

//사진을 해당 폴더에서 삭제한다.
int FolderType::deletePhoto(PhotoType& p) {
	if (m_PhotoList.Get(p)) {	//삭제하려는 사진이 존재하는지 검사
        if(m_PhotoList.Delete(p)) {
            m_numberOfHavingPhoto--;
            return 1;
        }
        else {
            return 0;
        }
	}
	else {								//삭제하려는 사진이 존재하지 않을 시
        return 0;
	}
}

//폴더의 명령어 권한에 진입한다.
//void FolderType::RunFolder() {
//	while (1)
//	{
//		m_command = GetCommand();
//
//		switch (m_command)
//		{
//		case 1:		// 폴더를 추가한다.
//			addFolder();
//			break;
//		case 2:		// 폴더를 삭제한다.
//			deleteFolder();
//			break;
//		case 3:		// 폴더에 존재하는 모든 폴더정보를 출력한다.
//			DisplayFolderByName();
//			break;
//		case 4:		// 특정 폴더에 진입한다.
//			OpenFolder();
//			break;
//		case 5:		// 사진을 추가한다.
//			addPhoto();
//			break;
//		case 6:		// 사진을 삭제한다.
//			deletePhoto();
//			break;
//		case 7:		// 폴더에 존재하는 모든 사진정보를 출력한다.
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

//폴더에 진입한다.
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

//FolderType 객체의 정보를 화면에 출력한다.
void FolderType::DisplayFolderTypeOnScreen() {
	cout << "\n\tFolder name: " << m_name << endl;
	cout << "\n\tCreated time: " << m_createdTime << endl;
	cout << "\n\tHaving folders: " << m_numberOfHavingFolder << endl;
	cout << "\n\tHaving Photos: " << m_numberOfHavingPhoto << endl;
}

//폴더 내의 모든 폴더를 이름 순으로 화면에 출력한다.
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

//폴더의 이름을 화면에 출력한다.
void FolderType::DisplayName() { 
	cout << m_name;
	return;
}

//폴더 내의 모든 사진을 이름 순으로 화면에 출력한다.
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
	cout << "\n\tFolder name: ";
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
	time_t now = time(NULL);
    tm* ptm = localtime(&now);
    char buffer[32];
    strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
    string date = buffer;
    return date;
}
