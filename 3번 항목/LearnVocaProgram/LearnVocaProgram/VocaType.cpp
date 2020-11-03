#include "VocaType.h"

//������(m_id, m_english, m_korean�� �ʱ�ȭ�Ѵ�.)
VocaType::VocaType() {
	m_id = -1;
	m_english = " ";
	m_korean = " ";
	m_correct = 0;
	m_wrong = 0;
}

//id�� ��ȯ�Ѵ�.
int VocaType::GetId() const {
	return m_id;
}

//spelling�� ��ȯ�Ѵ�.
string VocaType::GetEnglish() const {
	return m_english;
}

//���� ��ȯ�Ѵ�.
string VocaType::GetKorean() const {
	return m_korean;
}


double VocaType::GetCorrect() const {
	return m_correct;
}

double VocaType::GetWrong() const {
	return m_wrong;
}

double VocaType::GetCorrectPercent() const {
	if (m_correct == 0 && m_wrong == 0)
		return 0;
	else if (m_correct > 0 && m_wrong == 0)
		return 100;
	else {
		double m_correctPercent = double(double(m_correct / (m_correct + m_wrong)) * 100);
		return m_correctPercent;
	}
}

void VocaType::PlusCorrect() {
	++m_correct;
}

void VocaType::PlusWrong() {
	++m_wrong;
}


//id�� �Է��Ѵ�.
void VocaType::SetId(int id) {
	m_id = id;
}

//spelling�� �Է��Ѵ�.
void VocaType::SetEnglish(string english) {
	m_english = english;
}

//���� �Է��Ѵ�.
void VocaType::SetKorean(string korean) {
	m_korean = korean;
}

//id, spelling, ���� �Է��Ѵ�.
void VocaType::SetVoca(int id, string english, string korean) {
	SetId(id);
	SetEnglish(english);
	SetKorean(korean);
}

//id�� Ű����� �Է��Ѵ�.
void VocaType::SetIdFromKB() {
	cout << "\n\tid: ";
	cin >> m_id;
}

//spelling�� Ű����� �Է��Ѵ�.
void VocaType::SetEnglishFromKB() {
	cout << "\n\t English: ";
	cin >> m_english;
}

//���� Ű����� �Է��Ѵ�.
void VocaType::SetKoreanFromKB() {
	cout << "\n\t Korean: ";
	cin >> m_korean;
}

//id, spelling, ���� �Է��Ѵ�.
void VocaType::SetVocaFromKB() {
	SetIdFromKB();
	SetEnglishFromKB();
	SetKoreanFromKB();
}

//id���� ȭ�鿡 ����Ѵ�.
void VocaType::DisplayId() const {
	cout << "\n\tid: " << m_id << endl;
}

//spelling�� ȭ�鿡 ����Ѵ�.
void VocaType::DisplayEnglish() const {
	cout << "\n\tEnglish: " << m_english << endl;
}

//���� ȭ�鿡 ����Ѵ�.
void VocaType::DisplayKorean() const {
	cout << "\n\tKorean: " << m_korean << endl;
}

//id, spelling, ���� ȭ�鿡 ����Ѵ�.
void VocaType::DisplayVoca() const {
	DisplayId();
	DisplayEnglish();
	DisplayKorean();
}

void VocaType::DisplayCorrectPercent() const {
	cout << "\n\t( �����: " << GetCorrectPercent() << "% )" << endl;
}

//���ڿ� spelling�� ���ϰ� ���ں��� ������ true��ȯ, �ƴϸ� false
bool VocaType::operator<(const VocaType& voca) {
	return(m_english.compare(voca.m_english) < 0);
}

//���ڿ� spelling�� ���ϰ� ���ں��� ũ�� true��ȯ, �ƴϸ� false
bool VocaType::operator>(const VocaType& voca) {
	return(m_english.compare(voca.m_english) > 0);
}

//���ڿ� spelling�� ���ϰ� ���ں��� ������ true��ȯ, �ƴϸ� false
bool VocaType::operator==(const VocaType& voca) {
	return(m_english.compare(voca.m_english) == 0);
}

//�Է� ���ϵ�ũ���ͷκ��� VocaŸ���� �����ؿ´�.
int VocaType::ReadDataFromFile(ifstream& fin) {
	fin >> m_id;
	fin >> m_english;
	fin >> m_korean;
	return 1;
}

//��� ���ϵ�ũ���Ϳ� VocaŸ���� �ۼ��Ѵ�.
int VocaType::WriteDataToFile(ofstream& fout) {
	fout << m_id << " ";
	fout << m_english << " ";
	fout << m_korean << " " << endl;
	return 1;
}

