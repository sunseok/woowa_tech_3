/**
*	@date			2019.11.22
*	@author			서원석
*	@프로젝트 내용	폴더 시스템 구현
*	@필요 클래스	
					(o)Application.h
					(o)SortedLinkedlistType.h
					(o)FolderType.h
					(o)PhotoType.h

	@오류 목록
					1,2,5 이유 깨닫고 오늘 코딩 끝내기
	@특이사항(이유 파악하기)
					1. SortedLinkedList 복사생성자를 deep copy로 바꾸니 오류가 사라진 점
						이렇게 하니까 deep copy 비활성화 해도 진행이 된다.  					
						-> Get 수정함(data = m_curPos->data)
						-> operator==(const FolderType& f)
						-> '=' 오버로딩 활성
						=> Deep copy 활성
						=> Add(T&) 활성
					2. SortedLinkedList의 대입 연산자를 overloading하니까 오류가 사라진 점
					3. Get함수 인자로 T&해주는 이유를 몸소 느끼게 됨
					4. Delete함수도 인자로 T&해주는 이유를 몸소 느끼게 됨
					5. Add함수에서 인자로 T&를 해도 되는지 테스트 필요함
						->인자로 전달된 data는 바로 node->data를 향해 오퍼레이팅 오버로딩 된다.
						->그러므로 reference로 넘긴다하더라도 아무 문제가 없다.(실제 data가 되는 애는 결국 reference로
						넘어온 애의 데이터가 아니라 새로 만들어지는 애이기 때문이다.)
						->이렇게 했을 때의 장점은 Add함수로 넘어왔을때 객체의 생성자가 호출되지 않는다는 점이다.
						(특히 FolderType에는 객체형식의 변수가 3개 있다)
					6. SortedLinkedListType.h 전체적으로 한 번 보강이 필요함
					7. PhotoType의 연산자에도 const와 &를 붙임(쓸데없는 생성자 호출 안되도록)
					8. FolderType의 소멸자를 주석처리함(List형 멤버변수의 MakeEmpty를 호출했지만 결국 그 멤버변수들은 알아서
					소멸자를 호출하는 애들)
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