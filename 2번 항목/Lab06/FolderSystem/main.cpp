/**
*	@date			2019.11.22
*	@author			������
*	@������Ʈ ����	���� �ý��� ����
*	@�ʿ� Ŭ����	
					(o)Application.h
					(o)SortedLinkedlistType.h
					(o)FolderType.h
					(o)PhotoType.h

	@���� ���
					1,2,5 ���� ���ݰ� ���� �ڵ� ������
	@Ư�̻���(���� �ľ��ϱ�)
					1. SortedLinkedList ��������ڸ� deep copy�� �ٲٴ� ������ ����� ��
						�̷��� �ϴϱ� deep copy ��Ȱ��ȭ �ص� ������ �ȴ�.  					
						-> Get ������(data = m_curPos->data)
						-> operator==(const FolderType& f)
						-> '=' �����ε� Ȱ��
						=> Deep copy Ȱ��
						=> Add(T&) Ȱ��
					2. SortedLinkedList�� ���� �����ڸ� overloading�ϴϱ� ������ ����� ��
					3. Get�Լ� ���ڷ� T&���ִ� ������ ���� ������ ��
					4. Delete�Լ��� ���ڷ� T&���ִ� ������ ���� ������ ��
					5. Add�Լ����� ���ڷ� T&�� �ص� �Ǵ��� �׽�Ʈ �ʿ���
						->���ڷ� ���޵� data�� �ٷ� node->data�� ���� ���۷����� �����ε� �ȴ�.
						->�׷��Ƿ� reference�� �ѱ���ϴ��� �ƹ� ������ ����.(���� data�� �Ǵ� �ִ� �ᱹ reference��
						�Ѿ�� ���� �����Ͱ� �ƴ϶� ���� ��������� ���̱� �����̴�.)
						->�̷��� ���� ���� ������ Add�Լ��� �Ѿ������ ��ü�� �����ڰ� ȣ����� �ʴ´ٴ� ���̴�.
						(Ư�� FolderType���� ��ü������ ������ 3�� �ִ�)
					6. SortedLinkedListType.h ��ü������ �� �� ������ �ʿ���
					7. PhotoType�� �����ڿ��� const�� &�� ����(�������� ������ ȣ�� �ȵǵ���)
					8. FolderType�� �Ҹ��ڸ� �ּ�ó����(List�� ��������� MakeEmpty�� ȣ�������� �ᱹ �� ����������� �˾Ƽ�
					�Ҹ��ڸ� ȣ���ϴ� �ֵ�)
*/

#include<iostream>
#include<string>
#include"Application.h"
#include"PhotoType.h"
#include"SortedLinkedListType.h"
#include"FolderType.h"
using namespace std;

int main() {
	Application app;
	app.Run();

	return 0;
}