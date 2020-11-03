#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class VocaType {
public:
	VocaType();												//������(m_id, m_english, m_korean�� �ʱ�ȭ�Ѵ�.)
	int GetId() const;											//id�� ��ȯ�Ѵ�.
	string GetEnglish() const;									//spelling�� ��ȯ�Ѵ�.
	string GetKorean() const;										//���� ��ȯ�Ѵ�
	double GetCorrect() const;
	double GetWrong() const;
	double GetCorrectPercent() const;
	void PlusCorrect();
	void PlusWrong();
	void SetId(int id);										//id�� �Է��Ѵ�.
	void SetEnglish(string english);						//spelling�� �Է��Ѵ�.
	void SetKorean(string korean);							//���� �Է��Ѵ�.
	void SetVoca(int id, string english, string korean);	//id, spelling, ���� �Է��Ѵ�.
	void SetIdFromKB();										//id�� Ű����� �Է��Ѵ�.
	void SetEnglishFromKB();								//spelling�� Ű����� �Է��Ѵ�.
	void SetKoreanFromKB();									//���� Ű����� �Է��Ѵ�.
	void SetVocaFromKB();									//id, spelling, ���� �Է��Ѵ�.
	void DisplayId() const;										//id���� ȭ�鿡 ����Ѵ�.
	void DisplayEnglish() const;									//spelling�� ȭ�鿡 ����Ѵ�.
	void DisplayKorean() const;									//���� ȭ�鿡 ����Ѵ�.
	void DisplayVoca() const;										//id, spelling, ���� ȭ�鿡 ����Ѵ�.
	void DisplayCorrectPercent() const;
	bool operator<(const VocaType& voca);					//���ڿ� spelling�� ���ϰ� ���ں��� ������ true��ȯ, �ƴϸ� false
	bool operator>(const VocaType& voca);					//���ڿ� spelling�� ���ϰ� ���ں��� ũ�� true��ȯ, �ƴϸ� false
	bool operator==(const VocaType& voca);					//���ڿ� spelling�� ���ϰ� ���ں��� ������ true��ȯ, �ƴϸ� false
	int ReadDataFromFile(ifstream& fin);					//�Է� ���ϵ�ũ���ͷκ��� VocaŸ���� �����ؿ´�. id, english, korean������ �޾ƿ´ٴ� ���� ���
	int WriteDataToFile(ofstream& fout);					//��� ���ϵ�ũ���Ϳ� VocaŸ���� �ۼ��Ѵ�.

private:
	int m_id;												//�ܾ��� ���� id��
	string m_english;										//�ܾ��� spelling�� �����ϴ� �����̸� �ܾ�˻�, �� �ܾ��� �������� key��
	string m_korean;										//�ܾ��� ���� �����ϴ� ����
	double m_correct;
	double m_wrong;
};