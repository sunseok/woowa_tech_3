#include <stdio.h>
#include "Application.h"


//������
Application::Application() {
    m_command = -1;
    m_curUser = nullptr;
    UserType Admin;
    Admin.SetRecord("admin", "pwadmin", "admin", ADMIN);
    m_AllUserList.Insert(Admin);
    SimpleUserType2 tempSimpleUser;
    tempSimpleUser.SetPtr(m_AllUserList.GetCurPtr());
    m_AllSimpleUList.Insert(tempSimpleUser);
    InitWordBook();
}

//���α׷� �����Լ�
void Application::Run() {
    while (1) {
        m_command = GetCommand();
        switch (m_command) {
        case 1: // �α���
            LogIn();
            break;
        case 2: // ȸ������
            CreateUser();
            break;
        case 3: // ��ŷ��ȸ
            ShowRanker();
            break;
        case 0:
            cout << "\t�����մϴ�.." << endl;
            return;
        default:
            cout << "Caution" << endl;
            break;
        }
    }
}

//������ ����ܾ� �н� ���α׷��� �����Ѵ�.
void Application::LogIn() {
    int permission = VerifyLogIn();
    if (permission == USER) {
        m_curUser->SetDate();
        while (1) {
            m_command = GetCommandLogIn();
            switch (m_command)
            {
            case 1:
                SearchVoca();
                break;
            case 2:
                TestVoca();
                break;
            case 3:
                LearnVoca();
                break;
            case 4:
                ManageMyVocaList();
                break;
            case 5:
                EditMyInfo();
                break;
            case 6:
                CheckMyInfo();
                break;
            case 0:
                cout << "\t�α׾ƿ�.." << endl;
                LogOut();
                return;
            default:
                cout << "Caution" << endl;
                break;
            }
        }
    }
    else if (permission == ADMIN) {
        m_curUser->SetDate();
        while (1) {
            m_command = GetCommandManageUser();
            switch (m_command)
            {
            case 1:
                DeleteUser();
                break;
            case 2:
                EditUser();
                break;
            case 3:
                CheckAllUser();
                break;
            case 0:
                cout << "\t�α׾ƿ�.." << endl;
                LogOut();
                return;
            default:
                cout << "Caution" << endl;
                break;
            }
        }
    }
    else
        return;
}

//���α׷� �����Լ����� ������� ����� �޴´�.
int Application::GetCommand() {
    int c;
    cout << endl << endl;
    cout << "\t************ ����ܾ� �н����α׷� **************" << endl << endl;
    cout << "\t    1. �α���" << endl;
    cout << "\t    2. ȸ������" << endl;
    cout << "\t    3. ��ŷ��ȸ" << endl;
    cout << "\t    0. ����" << endl << endl;
    cout << "\t****************************" << endl << endl;
    cout << endl << "\t Choose a Command--> ";
    cin >> c;
    cout << endl;
    return c;
}

//�н� ���α׷����� ������� ����� �Է¹޴´�.
int Application::GetCommandLogIn() {
    int c;
    cout << endl << endl;
    cout << "\t******** " << m_curUser->GetName() << "��, �ȳ��ϼ��� **********" << endl << endl;
    cout << "\t    1. �ܾ� �˻��ϱ�" << endl;
    cout << "\t    2. �ܾ� ���躸��" << endl;
    cout << "\t    3. �ܾ� �н��ϱ�" << endl;
    cout << "\t    4. �� �ܾ��� �����ϱ�" << endl;
    cout << "\t    5. �� ���� �����ϱ�" << endl;
    cout << "\t    6. �� ���� ��ȸ�ϱ�" << endl;
    cout << "\t    0. �α׾ƿ�" << endl << endl;
    cout << "\t****************************" << endl << endl;
    cout << endl << "\t Choose a Command--> ";
    cin >> c;
    cout << endl;
    return c;
}

//������������ ������� ����� �޴´�.
int Application::GetCommandManageUser() {
    int c;
    cout << endl << endl;
    cout << "\t******** �����ڴ�, �ȳ��ϼ��� **********" << endl << endl;
    cout << "\t    1. �������� �����ϱ�" << endl;
    cout << "\t    2. �������� �����ϱ�" << endl;
    cout << "\t    3. �������� ��ȸ�ϱ�" << endl;
    cout << "\t    0. �α׾ƿ�" << endl << endl;
    cout << "\t****************************" << endl << endl;
    cout << endl << "\t Choose a Command--> ";
    cin >> c;
    cout << endl;
    return c;
}

//������ �α��� ������ �Է¹ް� ������ �������� �˻��ϰ� ������ �з��Ѵ�.
int Application::VerifyLogIn() {
    /*UserType temp;
    UserType dummy;
    cout << "\n\t**** �α��� ****\n";
    temp.SetIdFromKB();
    temp.SetPwFromKB();
    m_AllUserList.ResetList();
    while (m_AllUserList.GetNext(dummy) != nullptr) {
        if (dummy.GetId().compare(temp.GetId()) == 0) {
            if (dummy.GetPassword().compare(temp.GetPassword()) == 0) {
                m_curUser = m_AllUserList.GetCurPtr();
                if (m_curUser->GetStatus() == USER) {
                    cout << "\n\t**** ���� �α��� ����****\n";
                    return USER;
                }
                else {
                    cout << "\n\t**** ������ �α��� ����****\n";
                    return ADMIN;
                }
            }
            else {
                cout << "\n\t**** ��й�ȣ ������ �ùٸ��� �ʽ��ϴ� ****\n";
                return 0;
            }
        }
    }
    cout << "\n\t**** id ������ �ùٸ��� �ʽ��ϴ� ****\n";
    return 0;*/

    UserType temp;
    UserType dummy;
    SimpleUserType2 temp2;
    SimpleUserType2 dummy2;
    cout << "\n\t**** �α��� ****\n";
    temp.SetIdFromKB();
    temp.SetPwFromKB();
    temp2.SetPtr(&temp);
    dummy2.SetPtr(&temp);
    m_AllSimpleUList.ResetList();
    if (m_AllSimpleUList.Get(dummy2)) {
        if (dummy2.GetPtr()->GetPassword().compare(temp2.GetPtr()->GetPassword()) == 0) {
            m_curUser = m_AllSimpleUList.GetCurPtr()->GetPtr();
            if (m_curUser->GetStatus() == USER) {
                cout << "\n\t**** ���� �α��� ����****\n";
                return USER;
            }
            else {
                cout << "\n\t**** ������ �α��� ����****\n";
                return ADMIN;
            }
        }
        else {
            cout << "\n\t**** ��й�ȣ ������ �ùٸ��� �ʽ��ϴ� ****\n";
            return 0;
        }
    }
    else {
        cout << "\n\t**** id ������ �ùٸ��� �ʽ��ϴ� ****\n";
    }
    return 0;
}

//������ ����ܾ� �н� ���α׷����� ������.
void Application::LogOut() {
    m_curUser = nullptr;
}

//������ �߰��Ѵ�.
void Application::CreateUser() {
    /*UserType tempUser;
    cout << "\n\t**** ȸ������ ****\n";
    tempUser.SetIdFromKB();
    while (m_AllUserList.Get(tempUser)) {
        cout << "\n\t�̹� �����ϴ� id�Դϴ�.\n";
        tempUser.SetIdFromKB();
    }
    tempUser.SetNameFromKB();
    tempUser.SetPwFromKB();
    tempUser.SetStatus(USER);
    if (m_AllUserList.Insert(tempUser)) {
        cout << "\n\t������ �����Ǿ����ϴ�.\n";
    }
    else {
        cout << "\n\t���������� �����Ͽ����ϴ�.\n";
    }
    return;
    */
    UserType tempUser;
    SimpleUserType2 tempSimpleUser;
    cout << "\n\t**** ȸ������ ****\n";
    tempUser.SetIdFromKB();
    tempSimpleUser.SetPtr(&tempUser);
    if (m_AllSimpleUList.Get(tempSimpleUser)) {
        cout << "\n\t�̹� �����ϴ� id�Դϴ�.\n";
        return;
    }
    else {
        tempUser.SetNameFromKB();
        tempUser.SetPwFromKB();
        tempUser.SetStatus(USER);
        if (m_AllUserList.Insert(tempUser)) {
            tempSimpleUser.SetPtr(m_AllUserList.GetCurPtr());
            if (!m_AllSimpleUList.Insert(tempSimpleUser)) {
                m_AllSimpleUList.ExpandSize();
                m_AllSimpleUList.Insert(tempSimpleUser);
            }
            cout << "\n\t������ �����Ǿ����ϴ�.\n";

        }
        else {
            cout << "\n\t���������� �����Ͽ����ϴ�.\n";
        }
        return;
    }
}

//������ �����Ѵ�.
void Application::DeleteUser() {
    /*UserType tempUser;
    cout << "\n\t**** ������ ����id �Է� ****\n";
    tempUser.SetIdFromKB();
    if (!m_AllUserList.Get(tempUser)) {
        cout << "\n\t�ش� id�� �����ϴ�.\n";
        return;
    }
    else {
        if (tempUser.GetStatus() == ADMIN) {
            cout << "\n\t������ ������ ������ �� �����ϴ�.\n";
            return;
        }
        else {
            if (m_AllUserList.Delete(tempUser)) {
                cout << "\n\t������ �����Ǿ����ϴ�.\n";
            }
            else {
                cout << "\n\tt���������� �����Ͽ����ϴ�.\n";
            }
        }
    }*/

    UserType tempUser;
    SimpleUserType2 tempSimpleUser;
    cout << "\n\t**** ������ ����id �Է� ****\n";
    tempUser.SetIdFromKB();
    tempSimpleUser.SetPtr(&tempUser);
    if (!m_AllSimpleUList.Get(tempSimpleUser)) {
        cout << "\n\t�ش� id�� �����ϴ�.\n";
        return;
    }
    else {
        if (tempSimpleUser.GetPtr()->GetStatus() == ADMIN) {
            cout << "\n\t������ ������ ������ �� �����ϴ�.\n";
            return;
        }
        else {
            if (m_AllSimpleUList.Delete(tempSimpleUser) && m_AllUserList.Delete(tempUser))
            {
                m_AllSimpleUList.ReduceSize();
                cout << "\n\t������ �����Ǿ����ϴ�.\n";
            }     
            else {
                cout << "\n\tt���������� �����Ͽ����ϴ�.\n";
            }
        }
    }
}

//��� ���������� ȭ�鿡 ����Ѵ�.
void Application::CheckAllUser() {
    /*cout << "\n\t**** ��ü �������� ****\n";
    UserType tempUser;
    m_AllUserList.ResetList();
    while (m_AllUserList.GetNext(tempUser) != nullptr) {
        if (tempUser.GetStatus() != ADMIN) {
            tempUser.DisplayAll();
            cout << "\n\t------------\n";
        }
    }*/
    cout << "\n\t**** ��ü �������� ****\n";
    SimpleUserType2 tempSimpleUser;
    m_AllSimpleUList.ResetList();
    while (m_AllSimpleUList.GetNext(tempSimpleUser) != -1) {
        if (tempSimpleUser.GetPtr()->GetStatus() != ADMIN) {
            tempSimpleUser.GetPtr()->DisplayAll();
            cout << "\n\t------------\n";
        }
    }
}

//���� ������ �����Ѵ�.
void Application::EditUser() {
    UserType tempUser;
    SimpleUserType2 tempSimpleUser;
    cout << "\n\t**** ������ ����id �Է� ****\n";
    tempUser.SetIdFromKB();
    tempSimpleUser.SetPtr(&tempUser);
    if (!m_AllSimpleUList.Get(tempSimpleUser)) {
        cout << "\n\t�ش� id�� �����ϴ�.\n";
        return;
    }
    else {
        if (tempSimpleUser.GetPtr()->GetStatus() == ADMIN) {
            cout << "\n\t������ ������ ������ �� �����ϴ�.\n";
            return;
        }
        else {
            
            tempSimpleUser.GetPtr()->SetPwFromKB();
            tempSimpleUser.GetPtr()->SetNameFromKB();
            cout << "\n\t---------- �������� ������Ʈ �Ϸ� ----------\n";
            tempSimpleUser.GetPtr()->DisplayAll();
        }
    }
}

//��Ŀ�� ������ ȭ�鿡 ����Ѵ�.
void Application::ShowRanker() {
    //      �迭�� ������ showRanker();
    //    SortedArrayList<SimpleUserType> RankerList;
    //    int rank = 1;
    //    cout << "\n\t**** ��ũ ���� ****\n";
    //    UserType tempUser;
    //    SimpleUserType tempSimpleUser;
    //    m_AllUserList.ResetList();
    //    while(m_AllUserList.GetNext(tempUser) != nullptr) {
    //        if(tempUser.GetTestScore() != -1) {
    //            tempSimpleUser.SetPtr(m_AllUserList.GetCurPtr());
    //            RankerList.Insert(tempSimpleUser);
    //        }
    //    }
    //    RankerList.ResetList();
    //    while(RankerList.GetNext(tempSimpleUser) != -1) {
    //        cout << "\n\t" << rank << "��: " << tempSimpleUser.GetPtr()->GetId() << ", ����: " << tempSimpleUser.GetPtr()->GetTestScore() << endl;
    //        rank++;
    //    }

    MaxHeap<SimpleUserType> RankingList(m_AllUserList.GetLength());
    int Rank = 0;
    int cnt = 0;
    cout << "\n\t**** ��ũ ���� ****\n";
    UserType tempUser;
    SimpleUserType tempSimpleUser;
    SimpleUserType2 tempSimpleUser2;
    m_AllSimpleUList.ResetList();
    while (m_AllSimpleUList.GetNext(tempSimpleUser2) != -1) {
        if (tempSimpleUser2.GetPtr()->GetTestScore() != -1) {
            tempSimpleUser.SetPtr(tempSimpleUser2.GetPtr());
            RankingList.Add(tempSimpleUser);
        }
    }
    while (1) {
        if (RankingList.IsEmpty() || cnt == 100)
            break;
        SimpleUserType simple;
        simple = RankingList.Pop();
        cout << "\n\t" << Rank << "��(ID): " << simple.GetPtr()->GetId() << ", ����: " << simple.GetPtr()->GetTestScore() << "��" << endl;

        Rank++;
        cnt++;
    }
}

//���� ������ ������ ȭ�鿡 ����Ѵ�.
void Application::CheckMyInfo() {
    cout << "\n\t**** �� ���� ****\n";
    m_curUser->DisplayAll();
}

//���� ������ ������ �����Ѵ�.
void Application::EditMyInfo() {
    cout << "\n\t**** �������� ****\n";
    m_curUser->SetPwFromKB();
    m_curUser->SetNameFromKB();
}

//����ܾ �˻��Ѵ�.
void Application::SearchVoca() {
    VocaType Item;
    SimpleVocaType simpleItem;
    Item.SetEnglishFromKB();
    m_AllVocaList.ResetList();

    //���� �ܾ� ���α׷��� ã�� ����ܾ ������������ ���
    if (!m_AllVocaList.Get(Item)) {
        cout << "\n\t�˻��� ����ܾ�� ���α׷� ���� �������� �ʽ��ϴ�." << endl;
    }
    //���� �ܾ� ���α׷��� ã�� ����ܾ ������ ���
    else {
        Item.DisplayKorean();
        simpleItem.SetPtr(&Item);
        m_AllSimpleList.Get(simpleItem);
        m_curUser->GetQueue()->enQueue(simpleItem);
    }
}

//����ܾ� ������ ����.
void Application::TestVoca() {
    //  ���α׷��� �ܾ ���Ƿ� �����Ͽ� ��� ���� �ܾ�ϱ� ������ �׽�Ʈ�ϴ� �Լ�
    SimpleVocaType simpleTempVoca;
    m_AllSimpleList.ResetList();
    srand(time(NULL));
    int randArr[50];
    for (int i = 0; i < 50; i++) {                                    //0~999�� �������� 50���� �������� �����ؼ�
                                                                    //�迭 randArr[]�� �ִ´�.
        randArr[i] = rand() % 1000; //0~999�� ����
        for (int j = 0; j < i; j++) {
            if (randArr[j] == randArr[i]) {
                i--;
                break;
            }
        }
    }
    //�迭 randArr[]�� ���� ���ڵ鿡 �����ϴ� �迭�� �����͵���
    //�ܾ� �׽�Ʈ�� ���ÿ� �ִ´�.
    for (int i = 0; i < 50; i++) {
        simpleTempVoca = m_AllSimpleList.GetIndexOfData(randArr[i]);
        m_TestVocaList.push(simpleTempVoca);
    }

    int count = 1, correct = 0, incorrect = 0;
    string English;
    if (m_TestVocaList.isEmpty())
        Run();
    else {
        cout.precision(3); //���� �ڸ����� 3�������� ��µǰ� ����
        while (1) {
            if (m_TestVocaList.getLength() == 0)
                break;
            else {
                cout << "\t�ܾ��׽�Ʈ ( " << count << "/ 50 ) => ���� : " << correct << " ���� : " << incorrect << endl;

                m_TestVocaList.pop(simpleTempVoca);
                cout << "\n\tKorean: " << simpleTempVoca.GetPtr()->GetKorean() << "( �����: " << simpleTempVoca.GetPtr()->GetCorrectPercent() << "% )" << endl;
                cout << "\n\t0. ������ " << endl;
                cout << "\n\t->"; cin >> English; cout << endl;
                if (English == "0") {
                    cout << endl << "\t<<���>> ���� : " << correct << " ���� : " << incorrect << " ���� : " << correct * 2 << "�� " << endl;
                    m_TestVocaList.MakeEmpty();
                    if ((correct * 2) > m_curUser->GetTestScore()) {
                        m_curUser->SetTestScore(correct * 2);
                    }
                    return;
                }
                else if (simpleTempVoca.GetPtr()->GetEnglish().compare(English) != 0) {
                    incorrect++;
                    count++;
                    English = simpleTempVoca.GetPtr()->GetEnglish();
                    cout << "\t\t����!! (" << English << ")" << endl;
                    simpleTempVoca.GetPtr()->PlusWrong();
                    if (!(m_curUser->GetList()->Get(simpleTempVoca))) {
                        cout << "\n\t\t�ش� �ܾ �� �ܾ��忡 �߰��Ͻðڽ��ϱ�?\n\t\t(Y/N):"; cin >> English;
                        cout << endl;
                        if (English.compare("Y") == 0) {
                            if (m_curUser->AddVoca(simpleTempVoca)) {
                                cout << "\t\t�� �ܾ��忡 �߰��Ǿ����ϴ�!!\n";
                            }
                            else {
                                cout << "\t\t�� �ܾ��� �߰��� �����Ͽ����ϴ�..\n";
                            }
                        }
                    }
                }
                else {
                    correct++;
                    count++;
                    simpleTempVoca.GetPtr()->PlusCorrect();
                    cout << "\t\t����!!" << endl << endl;
                }
            }
        }
        ios_base::fmtflags f(cout.flags()); //precision ��¼��� �ʱ�ȭ
        cout << endl << "\t<<���>> ���� : " << correct << " ���� : " << incorrect << " ���� : " << correct * 2 << "�� " << endl;
        m_TestVocaList.MakeEmpty();
        if ((correct * 2) > m_curUser->GetTestScore()) {
            m_curUser->SetTestScore(correct * 2);
        }
    }
}

//����ܾ� �н���� driver
void Application::LearnVoca() {
    while (1)
    {
        m_command = GetCommandLearnLevel();
        if (m_command == 0) {
            return;
        }
        else if (m_command >= 1 && m_command <= 5) {
            SetLearnList(m_command);
        }
        else {
            cout << "\tIllegal selection...\n";
        }
    }
}

//�н����� ���ÿ��� ������� ����� �Է¹޴´�.
int Application::GetCommandLearnLevel() {
    int command;
    cout << endl << endl;
    cout << "\t---Select Learn Level -- Command ----- " << endl;
    cout << "\t   1 : Level1(001~200)" << endl;
    cout << "\t   2 : Level2(201~400)" << endl;
    cout << "\t   3 : Level3(401~600)" << endl;
    cout << "\t   4 : Level4(601~800)" << endl;
    cout << "\t   5 : Level5(801~1000)" << endl;
    cout << "\t   0 : Exit" << endl;

    cout << endl << "\t Choose a Level--> ";
    cin >> command;
    cout << endl;

    return command;
}

//�����н� �ܾ��Ʈ�� �Էµ� ������ �°� ä������.
void Application::SetLearnList(int l) {
    int LearnLevel = m_curUser->GetLearnLevel();
    if (LearnLevel < l - 1) {
        cout << "\n\tLevel" << LearnLevel + 1 << "���� �н����ּ���.\n";
        return;
    }
    SimpleVocaType simpleTempVoca;
    m_LearnVocaList.MakeEmpty();
    m_AllSimpleList.ResetList();
    srand(time(NULL));
    int randArr[200];
    for (int i = 0; i < 200; i++) {
        randArr[i] = rand() % 200 + (((l - 1) * 200));    //c�� ���õ� �����̴�. c�� 1�̸� 0~199 index�� ��ġ�� ������
        for (int j = 0; j < i; j++) {                    //                       c�� 2�� 200~399 index�� ��ġ�� ������
            if (randArr[j] == randArr[i]) {
                i--;
                break;
            }
        }
    }
    // m_LearnVocaList�� m_id 1~200�� �ش��ϴ� VocaType�� enQueue�Ѵ�.
    for (int i = 0; i < 200; i++) {
        simpleTempVoca = m_AllSimpleList.GetIndexOfData(randArr[i]);    //0~199�� �ε����� ��ġ�� �����Ͱ� ��������
        m_LearnVocaList.enQueue(simpleTempVoca);                        //�н��� ť�� ä������.
    }

    //������ ������ ����ܾ� 200���� ���� �н��� �ݺ��Ѵ�.
    ExecuteLearn();                                                        //������ ä���� �н��� ť�� ���� �ݺ��н��� ���۵ȴ�.
}


//����ܾ� 200���� ���� �н��� �ݺ��Ѵ�.
int Application::ExecuteLearn() {
    int LearnLevel = m_curUser->GetLearnLevel();
    string tempString;
    SimpleVocaType simpleTempVoca;

    // m_LearnVocaList�� VocaType�� ���� �������� ������ �ݺ��н� ����
    while (m_LearnVocaList.GetLength() != 0)
    {
        m_LearnVocaList.deQueue(simpleTempVoca);
        simpleTempVoca.GetPtr()->DisplayKorean();
        cout << "\t�ش��ϴ� �ܾ��Է�(�߰�����: Y): ";
        cin >> tempString;
        if (simpleTempVoca.GetPtr()->GetEnglish().compare(tempString) != 0)    //������ ���
        {
            if (tempString == "Y")    //������ ���� ���
            {
                cout << "\n\tLevel" << LearnLevel + 1 << "�� �����մϴ�.\n";
                m_LearnVocaList.MakeEmpty();
                return 0;
            }
            m_LearnVocaList.enQueue(simpleTempVoca);
            tempString = simpleTempVoca.GetPtr()->GetEnglish();
            cout << "\twrong(" << tempString << "), ���� �н��ܾ�: " << m_LearnVocaList.GetLength() << "��" << endl;
            if (!(m_curUser->GetList()->Get(simpleTempVoca))) {
                cout << "\n\t\t�ش� �ܾ �� �ܾ��忡 �߰��Ͻðڽ��ϱ�?\n\t\t(Y/N):"; cin >> tempString;
                if (tempString.compare("Y") == 0) {
                    if (m_curUser->AddVoca(simpleTempVoca)) {
                        cout << "\t\t�� �ܾ��忡 �߰��Ǿ����ϴ�!!\n";
                    }
                    else {
                        cout << "\t\t�� �ܾ��� �߰��� �����Ͽ����ϴ�..\n";
                    }
                }
            }
        }
        else
        {                                                    //������ ���
            cout << "\tright!, ���� �н��ܾ�: " << m_LearnVocaList.GetLength() << "��" << endl;
        }
    }
    cout << "\n\tLevel" << LearnLevel + 1 << "�ܰ踦 �н� �Ϸ��߽��ϴ�.\n";
    if (LearnLevel < 4) {
        LearnLevel++;
        m_curUser->SetLearnLevel(LearnLevel);
    }
    return 1;
}

//�� �ܾ��� ���� driver
void Application::ManageMyVocaList() {
    while (1)
    {
        m_command = GetCommandMyVocaList();

        switch (m_command)
        {
        case 1:        // �� �ܾ��� ����Ʈ�� ����ܾ �߰��Ѵ�.
            AddMyVoca();
            break;
        case 2:        // �� �ܾ��� ����Ʈ���� Ư�� ����ܾ �����Ѵ�.
            DeleteMyVoca();
            break;
        case 3:        // �� �ܾ����� ��� ����ܾ ȭ�鿡 ����Ѵ�.
            m_curUser->DisplayVoca();
            break;
        case 4:        // �� �ܾ����� ��� ����ܾ �������� ȭ�鿡 ����Ѵ�.
            m_curUser->DisplayVocaReverse();
            break;
        case 5:        // �� �ܾ��忡 �ִ� ��� ����ܾ �� �ܾ��� ����Ʈ���� �����Ѵ�.
            m_curUser->DeleteAllVoca();
            break;
        case 0:
            return;
        default:
            cout << "\tIllegal selection...\n";
            break;
        }
    }
}

//ȭ�鿡 �� �ܾ��� ���� ��ɾ� ����� ����ϰ� Ű����� ���õ� ����� �Է¹޴´�.
int Application::GetCommandMyVocaList() {
    int command;
    cout << endl << endl;
    cout << "\t -------Manage my voca------- " << endl;
    cout << "\t   1 : Add voca" << endl;
    cout << "\t   2 : Delete voca" << endl;
    cout << "\t   3 : Display voca" << endl;
    cout << "\t   4 : Display voca(In reverse order)" << endl;
    cout << "\t   5 : Delete my voca list" << endl;
    cout << "\t   0 : Exit" << endl;

    cout << endl << "\t Choose a Command Number--> ";
    cin >> command;
    cout << endl;

    return command;
}

//�� �ܾ��� ����Ʈ�� ����ܾ �߰��Ѵ�.
void Application::AddMyVoca() {
    VocaType tempVoca;
    SimpleVocaType simpleTempVoca;

    if (m_curUser->GetQueue()->GetLength() != 0) {
        cout << "\n\t�ֱ� �˻��� �ܾ�: \n";
        while (m_curUser->GetQueue()->deQueue(simpleTempVoca)) {
            cout << "\tEnglish: " << simpleTempVoca.GetPtr()->GetEnglish() << ", Korean: " << simpleTempVoca.GetPtr()->GetKorean() << endl;
        }
    }

    cout << "\n\t�� �ܾ��� ����Ʈ�� �߰��Ϸ��� ����ܾ� �˻�: ";
    tempVoca.SetEnglishFromKB();
    if (m_AllVocaList.Get(tempVoca)) {        //����ܾ� ���α׷��� �˻��� ����ܾ �����ϴ��� �˻�
        simpleTempVoca = m_AllSimpleList.GetIndexOfData(tempVoca.GetId() - 1);
        if (m_curUser->AddVoca(simpleTempVoca)) {
            cout << "\n\t�� �ܾ��� ����Ʈ ������Ʈ �Ϸ�\n";
        }
        else {
            cout << "\n\t�� �ܾ��� ����Ʈ ������Ʈ ����\n";
        }
    }
    else {                                    //����ܾ� ���α׷��� �������� �ʴ� ����ܾ��� ���
        cout << "\n\t�ش� �ܾ�� ����ܾ� ���α׷��� �������� �ʽ��ϴ�.\n";
    }
}

//�� �ܾ��� ����Ʈ���� Ư�� ����ܾ �����Ѵ�.
void Application::DeleteMyVoca() {
    VocaType tempVoca;
    SimpleVocaType simpleTempVoca;

    cout << "\n\t�� �ܾ��� ����Ʈ���� �����Ϸ��� ����ܾ� �Է�: ";
    tempVoca.SetEnglishFromKB();
    if (m_AllVocaList.Get(tempVoca)) {                //���α׷��� �����Ϸ��� ����ܾ �����ϴ��� �˻�
        simpleTempVoca = m_AllSimpleList.GetIndexOfData(tempVoca.GetId() - 1);
        if (m_curUser->DeleteVoca(simpleTempVoca)) {
            cout << "\n\t�� �ܾ��� ����Ʈ ������Ʈ �Ϸ�\n";
        }
        else {
            cout << "\n\t�� �ܾ��� ����Ʈ ������Ʈ ����\n";
        }
    }
    else {                                            //���α׷��� �����Ϸ��� ����ܾ �������� �ʴ� ���
        cout << "\n\t�ش� �ܾ�� ���α׷��� �������� ����\n";
    }
}

//���α׷� ����ܾ ���Ϸκ��� �ʱ�ȭ�Ѵ�.
void Application::InitWordBook() {
    m_InFile.open("WordFile.txt");
    VocaType item;                            //Item ������ ���ܾ� ������ ���� VocaType ��ü
    SimpleVocaType simpleItem;                //�о�� �����Ͱ� ��� item ��ü�� SimpleVocaType ��ü���ڷ� �Ѱ���
    m_AllVocaList.ResetList();

    //���Ϸκ��� voca������ �ҷ��ͼ� m_AllVocaList�� �����Ѵ�.
    while (!m_InFile.eof()) {
        item.ReadDataFromFile(m_InFile);
        m_AllVocaList.Insert(item);//���� ������ ��ġ�� �о�� �����Ͱ� ��� item ��ü�� ���� ����
    }
    m_InFile.close();

    //m_AllSimpleList�� 1000���� Voca ��ü ������ �����Ѵ�.
    m_AllVocaList.ResetList();
    while (m_AllVocaList.GetNext(item) != -1) {        //m_AllVocaList�� ��� ��Ҹ� m_AllSimpleList�� �����ϴ� ����

        simpleItem.SetPtr(m_AllVocaList.GetCurPtr());    //  m_AllVocaList.GetCurPtr()�� �ܾ��Ʈ �� �� ����� �����͸� �̾ƿ´�.
                                                        // ( while���� GetNextVoca()�� ����Ʈ ���� ��� ��ҿ� �����ϱ� ���� �ݺ�����)

        m_AllSimpleList.Insert(simpleItem);            // m_AllVocaList�� ������� �����͸� �����ִ�
                                                        //simpleItem�� m_AllSimpleList�� �ִ´�.
    }
}