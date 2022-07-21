#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 랜덤값을 가져오기 위한 라이브러리*/
#include <time.h>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/**
게임에서 무언가 구분할 필요가 있다면 열거형을 정의합니다.
열거형의 요소를 보면 문자열처럼 보입니다. 가독성이 좋습니다.
열거형의 요소는 내부적으로 정수값입니다. 값을 비교할 때 빠릅니다.
변수 이름만 보더라도 열거형인것을 알 수 있도록 접두사 E를 붙여 줍는다.

예, 아이템 구분, 몬스터 구분, 플레이어 직업 구분, 스테이지 구분등
*/

/**
이제 누가 이겼는지 비교해 봅니다. 규칙을 정해 주도록 합니다.
바위는 가위를 이깁니다. 바위에서 가위를 빼면 1입니다.
보는 바위를 이깁니다. 보에서 바위를 빼면 1입니다.
가위는 보를 이깁니다. 가위에서 보를 빼면 -2입니다.
승리 조건이 정해졌습니다.
*/
enum ERockPaperScissors
{
    Scissors,   // 0
    Rock,       // 1
    Paper,      // 2
    Max         // 3  Max가 있는 이유는 열거형의 요소의 수를 알기 위함입니다. 
};


int main()
{
    /**
    랜덤으로 값을 가져오기 위해서 난수 테이블을 생성합니다.
    srand((unsigned int)time(0));
    NULL은 상수 0으로 정의되어 있습니다.
    */
    srand((unsigned int)time(NULL));

    /** 플레이어가 가위, 바우, 보를 냈을 대 저장할 변수를 선언해 줍니다. */
    int playerSelect;

    /** 상대방이 가위, 바위, 보를 냈을 때 저장할 변수를 선언해 줍니다. */
    int opponentSelect;

    /**
    반복문 안에서 처리 해 줍니다.
    while (true) : 무한 반복을 의미합니다.
    */
    while (true)
    {
        cout << "0. Scissors" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. End" << endl;
        cout << "메뉴를 선택하세요 : ";

        cout << "" << endl;
        /**
        cout : 값을 출력합니다.
        cin : 값을 입력받습니다.
        */
        cin >> playerSelect;

        cout << "playerSelect : " << playerSelect << endl;

        /** 만일 플레이어가 가위를 냈다면? */
        if (playerSelect == 0)
        {
            cout << "플레이어는 가위를 냈습니다. " << endl;
        }
        /** 만일 플레이어가 바위를 냈다면? */
        else if (playerSelect == 1)
        {
            cout << "플레이어는 바위를 냈습니다. " << endl;
        }
        /** 만일 플레이어가 보를 냈다면? */
        else if (playerSelect == 2)
        {
            cout << "플레이어는 보를 냈습니다.  " << endl;
        }

        cout << "" << endl;

        /**
        플레이어가 가위, 바위, 보를 선택하지 않았을 경우 처리를 해 줍니다.
        ERockPaperScissors::Scissors  : 0
        ERockPaperScissors::Max       : 3
        */
        if (playerSelect < ERockPaperScissors::Scissors || playerSelect > ERockPaperScissors::Max)
        {
            cout << "잘못된 값을 입력하셨습니다. " << endl;
            /** 일시 정지합니다. */
            system("pause");
            /** 반복문의 시작점으로 이동합니다. */
            continue;
        }
        /** 만일 종료를 선택했을 경우 게임을 빠져 나갑니다. */
        else if (playerSelect == ERockPaperScissors::Max)
        {
            break;
        }

        /**
        상대방은 0, 1, 2 사이의 값을 랜덤으로 선택합니다.
        ERockPaperScissors::Max 는 3입니다.
        rand() % ERockPaperScissors::Max;  0과 2 사이의 랜덤값을 반환합니다.
        */
        opponentSelect = rand() % ERockPaperScissors::Max;

        cout << "opponentSelect : " << opponentSelect << endl;

        cout << "" << endl;

        /** 이제 플레이어가 선택한 값을 가지고 비교합니다. */
        switch (opponentSelect)
        {
        case ERockPaperScissors::Scissors:
            cout << "opponentSelect : Scissors" << endl;
            break;
        case ERockPaperScissors::Rock:
            cout << "opponentSeelct : Rock" << endl;
            break;
        case ERockPaperScissors::Paper:
            cout << "opponentSelect : Paper" << endl;
            break;
        default:
            break;
        }



        if (playerSelect == 0)
        {
            if (opponentSelect == 0)
            {

            }
            else if (opponentSelect == 1)
            {

            }
            else if (opponentSelect == 2)
            {

            }
        }
        else if (playerSelect == 1)
        {
            if (opponentSelect == 0)
            {

            }
            else if (opponentSelect == 1)
            {

            }
            else if (opponentSelect == 2)
            {

            }
        }
        else if (playerSelect == 2)
        {
            if (opponentSelect == 0)
            {

            }
            else if (opponentSelect == 1)
            {

            }
            else if (opponentSelect == 2)
            {

            }
        }


        /** 조건을 검사합니다. */
        int winCondition = playerSelect - opponentSelect;

        /** if문으로 확인합니다. */
        //if (winCondition == 1 || winCondition == -2)
        //{
        //    cout << " 플레어어가 이겼습니다. " << endl;
        //}
        //else if (winCondition == 0)
        //{
        //    cout << "비겼습니다. " << endl;
        //}
        //else
        //{
        //    cout << "상대방이 이겼습니다. " << endl;
        //}

        /** switch문으로 확인합니다. */
        switch (winCondition)
        {
        case 1:
        case -2:
            cout << "플레이어가 이겼습니다. " << endl;
            break;
        case 0:
            cout << "비겼습니다. " << endl;
            break;
        default:
            cout << "상대방이 이겼습니다. " << endl;
            break;
        }
    }
}