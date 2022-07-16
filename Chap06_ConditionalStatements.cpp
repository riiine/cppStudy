
/** C++ 표준 입출력 클래스*/
#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

int main()
{
    /**
    조건문
    1. if문
    2. switch문
    */

    /**
    if 조건문 (if conditional statement)

    if (조건식)
    {
        // 조건이 참일 경우 실행될 문장
    }
    */

    /** 문장을 추가해 줍니다. */
    int intValue1 = 50;
    int intValue2 = 100;

    if (intValue1 > intValue2)
    {
        cout << intValue1 << " is greater than " << intValue2 << endl;
    }

    if (intValue1 < intValue2)
    {
        cout << intValue1 << " is less than " << intValue2 << endl;
    }

    cout << "" << endl;

    /**
    if (조건식)
    {
        // 참일 경우의 실행될 문장
    }
    else
    {
        // 위의 조건식에 아무 것도 해당되지 않을 때 실행될 문장
    }
    */
    if (intValue1 > intValue2)
    {
        cout << intValue1 << " is greater than " << intValue2 << endl;
    }
    else
    {
        cout << intValue1 << " is less than " << intValue2 << endl;
    }

    cout << "" << endl;

    /**
    프로그래머는 경우의 수를 코딩하는 직업입니다. 
    else 구문안에 조건이 명확하지 않습니다. 
    */

    /** 
    if (조건식)
    {
        // 조건식에 맞았을 때 실행될 문장
    }
    else if (조건식)
    {
        // 조건식에; 맞았을 때 실행될 문장
    }
    else
    {
        // 위의 조건식에 아무것도 해당되지 않을 때 실행될 문장
    }
    */
    if (intValue1 > intValue2)
    {
        cout << intValue1 << " is greater than " << intValue2 << endl;
    }
    else if (intValue1 == intValue2)
    {
        cout << intValue1 << " is equal to " << intValue2 << endl;
    }
    else
    {
        cout << intValue1 << " is less than " << intValue2 << endl;
    }

    cout << "" << endl;

    /** 다음과 같이 문장을 표현할 수 있습니다. */
    if (intValue1 > intValue2)
    {
        cout << intValue1 << " is greater than " << intValue2 << endl;
    }
    else
    {
        if (intValue1 == intValue2)
        {
            cout << intValue1 << " is equal to " << intValue2 << endl;
        }
        else
        {
            cout << intValue1 << " is less than " << intValue2 << endl;
        }
    }

    cout << "" << endl;

    /**
    프로그래밍은 경우의 수를 코딩합니다. 명료하게 조건 검사를 하면 좋습니다. 
    else문에 다양한 조건이 있을 수 있습니다. 
    else문 보다는 명료하게 else if문을 쓰는 것이 좋습니다. 

    문장을 수정해 줍니다. 
    */
    if (intValue1 > intValue2)
    {
        cout << intValue1 << " is greater than " << intValue2 << endl;
    }
    else if (intValue1 == intValue2)
    {
        cout << intValue1 << " is equal to " << intValue2 << endl;
    }
    else if (intValue1 < intValue2)
    {
        cout << intValue1 << " is less than " << intValue2 << endl;
    }

    cout << "" << endl;

    /**
    if 문 중첩(Nestring if statements)

    if문을 다른 if문 안에 중첩할 수 있습니다. 
    헷갈릴 수 있습니다. 안좋은 습관입니다. 
    */
    if (intValue1 >= 10)
    {
        if (intValue1 <= 20)
        {
            cout << intValue1 << " is between 10 and 20" << endl;
        }
        else
        {
            cout << intValue1 << " is greater than 20" << endl;
        }
    }

    /**
    다른 조건문인 switch문을 보도록 합니다. 

    조건문 switch문
    switch문은 if문과 같이 조건 제어문에 속합니다. 
    하지만 switch문은 if문 처럼 <, <=, >, >= 와 같은 이상, 이하, 미만, 초과와 같은 부등식이 사용될 수 없습니다. 
    if문이 조건식이 true일 경우에 블록이 실행된다고 하면 switch문은 비교할 변수가 어떤 값을 가지냐에 따라서
    실행문이 실행됩니다. 오직 == 만 비교할 수 있습니다. 

    그러므로 모든 switch문은 if문으로 바꿀 수 있지만 if문에서 부등식이 사용된 경우에는 switch문으로 변경할 수 없습니다. 

    하지만 switch문을 사용함으로써 if문 보다는 좀 더 코드의 가독성이 좋게 작성할 수 있고 if문 보다 미세하게
    switch문이 빠르기에 switch문으로 작성할 수 있는 코드가 있다고 하면 if문보다 switch문이 좋습니다. 

    switch문을 쓸 때 주의할 점은 다음과 같습니다. 
    1. switch문 뒤에 오는 변수는 반드시 정수형(char, short, int, long과 각각의 unsigned형) 이어야 합니다. 
    2. case 문 뒤에 포함된 명령어에는 반드시 break문이 있어야 합니다. 
    */

    /**
    switch (변수)
    {
        case 값1:
            실행문;
            break;
        case 값2:
            실행문;
            break;
        default:
            실행문;
    }
    */

    int intValue3 = 200;

    switch (intValue3)
    {
    case 100:
        cout << "intValue3 : " << intValue3 << endl;
        break;
    case 200:
        cout << "intValue3 : " << intValue3 << endl;
        break;
    case 300:
        cout << "intValue3 : " << intValue3 << endl;
    default:
        /** 조건에 맞는 값이 없으면 default 쪽이 실행됩니다. */
        cout << "맞는 값이 없습니다. " << endl;
        break;
    }
    
    cout << "" << endl;

    /** 같은 결과는 같은 case로 묶을 수가 있습니다. */
    int month = 6;

    switch (month)
    {
    case 1:
    case 2:
    case 12:
        cout << "Winter" << endl;
        break;
    case 3:
    case 4:
    case 5:
        cout << "Spring" << endl;
        break;
    case 6:
    case 7:
    case 8:
        cout << "Summer" << endl;
        break;
    case 9:
    case 10:
    case 11:
        cout << "Autumn" << endl;
        break;
    default:
        cout << "Wrong choice" << endl;
        break;
    }

    /**
    삼항연산자(조건연산자) 에 의한 조건문

    C++에서는 if / else 문을 삼항연산자를 이용하게 간단하게 표현이 가능합니다. 
    (조건식) ? 표현식1 : 표현식2;
    삼항연산자는 조건식이 참일 경우에는 표현식1을 선택하고
    조건식이 거짓일 경우에는 표현식2를 선택합니다. 
    표현식에는 상수, 변수, 수식, 함수 호출등이 올 수 있습니다. 

    if문을 삼항연산자로 변경해 봅니다. 
    */
    if (intValue1 > intValue2)
    {
        cout << intValue1 << " is greater than " << intValue2 << endl;
    }
    else
    {
        cout << intValue1 << " is less than " << intValue2 << endl;
    }

    cout << "" << endl;
    /** to_string() : 정수값을 문자열로 변경해주는 함수*/
    string greaterMessage = to_string(intValue1) + " is greater than " + to_string(intValue2);

    string greaterMessage1 = intValue1 + " is greater than " + intValue2; // (X)
    cout << "greaterMessage1 : " << greaterMessage1 << endl;
    
    string lessMessage = to_string(intValue1) + " is less than " + to_string(intValue2);
    string resultString = (intValue1 > intValue2) ? greaterMessage : lessMessage;

    cout << "resultString : " << resultString << endl;

    cout << "" << endl;

    /**
    C           : 할아버지 50년
    C++         : 아버지   39년
    C#, java    : 아들     15년       
    */

    /** 
    두 수 중에서 큰 수를 구해 봅니다. 
    if문으로 구현해 봅니다. 
    */
    int intValue4 = 15;
    int intValue5 = 17;
    int bigNumber;

    if (intValue4 > intValue5)
    {
        bigNumber = intValue4;
    }
    else
    {
        bigNumber = intValue5;
    }

    cout << "if문 bigNumber: " << bigNumber << endl;
    cout << "" << endl;

    /** 삼항연산자로 구해 봅니다. */
    bigNumber = (intValue4 > intValue5) ? intValue4 : intValue5;

    cout << "삼항연산자 bigNumber : " << bigNumber << endl;
    cout << "" << endl;

}
