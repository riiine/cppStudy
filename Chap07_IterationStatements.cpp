
#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 배열의 사이즈를 가져오기 위한 라이브러리*/
#include <array>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

int main()
{
    /** using namespace std;*/
    std::cout << "C++ 공부하고 있어요. !!" << std::endl;

    cout << "C++ 공부하고 있어요. !!" << endl;

    /**
    반복문
    1. for문
    2. foreach문
    3. while문
    4. do while문
    */

    /**
    점프문
    1. continue
    2. break
    3. goto : C언어 때부터 안씁니다. 코드 분석을 난해하게 합니다. 
    */

    /**
    for문 사용법

    for (초기화; 조건식; 반복식;)
        반복 실행할 코드

    초기화는 딱 한번 실행됩니다. 
    조건식은 반복을 할지 결정하는 식입니다. 주로 몇번 반복할 지 결정합니다. 
    반복식은 반복이 끝날때 마다 실행되며 , 초기화된 변수의 값을 조정합니다. 
    반복식 다음 조건식으로 가서 다시 조건을 판단합니다. 
    조건식이 거짓일 때까지 계속 반복합니다. 
    */

    cout << "< 0 ~ 9 >" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
    }
    cout << "" << endl;
    cout << "" << endl;


    cout << "< 0 ~ 9 >" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "< 0 ~ 10 >" << endl;

    for (int i = 0; i <= 10; i++)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "< 0 ~ 10 >" << endl;

    for (int i = 0; i <= 10; ++i)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "< 10 ~ 1 >" << endl;

    for (int i = 10; i > 0; i--)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;
        
    cout << "< 1 ~ 9 홀수 >" << endl;

    for (int i = 1; i < 10; i = i + 2)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 전치 증가 연산자와 후치 증가 연산자에 대해서 알아 봅니다. 문장을 추가해 줍니다. */
    int intValue5 = 10;
    int intValue6;
    /**
    전치 증가 연산은 ++intValue5처럼 변수앞에 연산자를 씁니다. 
    intValue6 = ++intValue5; 라고 쓰면
    intValue5 가 1 증가된 상태에서 intValue6에 들어갑니다. 
    따라서 intValue5도 11이 되고, intValue6도 11이 됩니다. 
    */
    intValue6 = ++intValue5;
    cout << "전치 증가 연산자 intValue5 : " << intValue5 << endl;
    cout << "전치 증가 연산자 intValue6 : " << intValue6 << endl;
    cout << "" << endl;

    /** 테스트를 위해서 초기화 해 줍니다. */
    intValue5 = 10;
    /**
    후치 증가 연산든 intValue5++ 처럼 변수 뒤에 연산자를 씁니다. 
    intValue6 = intValue5++; 라고 쓰면
    intValue5값이 intValue6에 들어가고
    그런 다음에 intValue5값이 1 증가합니다. 
    따라서 intValue5의 값은 11이 되고, intValue6의 값은 10이 됩니다. 
    */
    intValue6 = intValue5++;
    cout << "후치 증가 연산자 intValue5 : " << intValue5 << endl;
    cout << "후치 증가 연산자 intValue6 : " << intValue6 << endl;
    cout << "" << endl;

    /** 구구단을 구현해 봅니다. */
    for (int i = 2; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cout << i << " X " << j << " = " << i * j << endl;
        }
    }
    cout << "" << endl;
    cout << "" << endl;

    /**
    foreach문은 배열이나 컬렉션의 요소에 차례대로 접근할 수 있습니다. 
    배열, 컬렉션은 여러 개의 요소로 구성되어 있고, 해당 배열이나 컬렉션의 
    마지막 요소까지 접근하기 때문에 여기서 반복이 이루어집니다. 

    foreach문의 장점이자 단점은 한번 실행하면 끝까지 실행한다는 점입니다. 
    중간에 중단이 불가능합니다. 때문에 if문을 활용한 break는 불가능합니다. 

    for문은 if문을 통해서 반복문을 빠져나갈 수 있습니다. 
    */
    /**
    int타입을 여러개 저장할 수 있는 배열타입의 intArray1이라는 이름의 배열 변수를 선언합니다. 
    10, 20, 30, 5, 10, 15, 20, 25, 30 값을 intArray1이라는 배열 변수에 
    대입함으로써 초기화했습니다. 
    */
    int intArray1[] = {10, 20, 30, 5, 10, 15, 20, 25, 30};

    cout << "for문" << endl;
    /**
    배열은 배열 자체로 사이즈를 알 수 있는 방법이 없습니다. 
    #include <array>로 배열의 사이즈를 가져오기 위한 라이브러리 추가했습니다. 
    size() 함수를 통해서 배열의 사이즈를 가져올 수 있습니다. 
    */
    for (int i = 0; i < size(intArray1); i++)
    {
        cout << intArray1[i] << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "foreach 문" << endl;
    /**
    foreach문은 주머니에서 요소를 꺼내서 확인하는 느낌입니다. 
    주머니에 요소가 없을 때까지 반복합니다. 
    num은 지역변수입니다. 여러분 마음대로 변수 이름을 지으셔도 상관없습니다. 
    : intArray1       intArray1 배열 안에
    */
    for (int num : intArray1)
    {
        cout << num << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /**
    string타입을 여러개 저장할 수 있는 names라는 이름의 배열변수를 선언합니다. 
    "John", "Jane", "Tom", "Smith", "Joe" 라는 문자열을 대입함으로써
    names라는 이름의 배열 변수를 초기화 했습니다. 
    */
    string names[] = {"John", "Jane", "Tom", "Smith", "Joe"};

    cout << "for문" << endl;

    for (int i = 0; i < size(names); i++)
    {
        cout << names[i] << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "foreach문" << endl;

    for (string name : names)
    {
        cout << name << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "foreach문" << endl;
    /** & 앰퍼샌드, 참조자(Reference)*/
    for (string& i : names)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "foreach문" << endl;
    /** 
    auto : 모든 자료형을 담을 수 있는 타입
    귀찮아 하는 사람들이 주로 씁니다. 
    되도록이면 쓰지 않는 것이 좋은 습관입니다. 
    */
    for (auto name : names)
    {
        cout << name << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "foreach문" << endl;

    for (auto& name : names)
    {
        cout << name << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /**
    while 문     ~하는 동안

    while (조건식)
        반복 실행할 코드

    조건식은 bool형태이어야 합니다. 반복 실행 코드가 2줄 이상이면 블록으로 지정하면 됩니다. 

    while (조건식)
    {
        반복실행할 코드
        반복실행할 코드
    }
    */

    /**
    게임을 만들기 위해서는 C++ 문법의 전체적인 부분에 익숙해져 있어야 합니다. 
    디테일한 부분은 구글 검색하면 다 나옵니다. 

    그런데 꼭 자세하게 알아야 하는 문법적 요소가 있습니다. 
    1. 포인터      : Pointer
    2. 참조자      : Reference
    3. 상수        : Constant
    4. 동적할당     : Dynamic Memory Allocation
    5. 스마트 포인터 : Smart Pointer  2011년도 부터 지원합니다. 
        unique_ptr : 객체의 유일한 소유권을 가지는 스마트 포인터
        shared_ptr : 객체간의 공유가 가능한 스마트 포인터
        weak_ptr   : shared_ptr의 단점인 순환참조 문제를 해결한 약한 참조의 스마트 포인터
    */

    int intValue1 = 10;

    cout << "while 문" << endl;
    /** intValue1 변수의 값이 0보다 클 동안 반복합니다. */
    while(intValue1 > 0)
    {
        cout << intValue1 << " ";
        /**
        꼭 while반복문을 빠져나갈 수 있는 조건을 만들어 주어야 합니다. 
        안 그러면 무한 반복 됩니다. 
        */
        intValue1--;
    }
    cout << "" << endl;
    cout << "" << endl;
    /**
    이 예제에서는 intValue2 = 0으로 초기화 시킨 다음에
    total += ++intValue2; 와 같이 ++(전치 증가 연산자)를 intValue2앞에 붙입니다. 
    이렇게 해야만 정확한 결과가 얻어집니다. 
    */
    int intValue2 = 0;
    int total = 0;
    /** total 변수의 값이 10000보다 작을 때까지 반복합니다. */
    while (total < 10000)
    {
        /** while 반복문을 빠져 나갈 수 있는 조건을 만들어 주어야 합니다. */
        // total += ++intValue2;
        total = total + (++intValue2);
    }

    cout << "Total from " << 1 << " to " << intValue2 << " is " << total << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    반복문을 통해서 0부터 9까지의 숫자를 더합니다. 
    하지만 중간에 if (sum > 5) break;를 통해서 0부터 9까지를 반복문을 통해서 더하는 중에
    덧셈의 결과 값이 4를 넘는 경우 break를 통해서 반복문을 빠져나가도록 해 봅니다. 
    
    1회 : sum = 0
    2회 : sum = 0 + 1 = 1
    3회 : sum = 0 + 1 + 2 = 3
    4회 : sum = 0 + 1 + 2 + 3 = 6

    이렇게 4회를 돌고 sum의 결과 값이 6이 되었울 때 if (sum > 5) 를 만족하게 되어 break가 걸리게 됩니다. 
    이렇게 break키워드에 의해서 반복문에서 빠져 나올 수 있습니다. 
    */

    int intValue3 = 0;
    int sum = 0;
    /** 0부터 9까지 10회 반복합니다. */
    while (intValue3 < 10)
    {
        /** 만일 합이 5보다 크면 break;로 반복문을 빠져나갑니다. */
        if (sum > 5)
        {
            break;
        }
        /** while문에서는 반복문을 빠져나갈 수 있는 조건을 만들어 주어야 합니다. */
        sum += intValue3;

        cout << intValue3 + 1 << "회" << endl;

        ++intValue3;
    }

    cout << "sum : " << sum << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 1 ~ 100까지 홀수의 합을 구해 봅니다. */
    int intValue4 = 1;
    int oddSum = 0;

    /** 1에서 100까지 100회 반복합니다. */
    while (intValue4 <= 100)
    {
        /** 2로 나누었을 때 나머지가 1이면 홀수 입니다. */
        if (intValue4 % 2 == 1)
        {
            oddSum += intValue4;
        }
        /** while 반복문을 빠져나갈 수 있는 조건을 만들어 주어야 합니다. */
        ++intValue4;
    }

    cout << "1부터 100까지 홀수의 합 : " << oddSum << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    3 % 2  3을 2로 나눈 나머지는 1입니다. 
    5 % 2  5를 2로 나눈 나머지는 1입니다. 
    */

    /** 
    별 찍기를 해 봅니다. 
    반복문 안에 반복문이 들어가는 2중 while문으로 만들어 봅니다. 
    i가 1에서 10까지 돌면서
    j는 1번 별을 찍고, 2번 별을 찍고..  9번 별을 찍고 10번 별을 찍습니다. 

    i는 가장 큰 횟수는 10번이고, j는 그 사이사이에서 가로로 별을 찍는 방식입니다. 
    */
    int i = 1;
    int j = 0; 
    /** i가 10보다 작거나 같을 때까지 1회 반복합니다. */
    while (i <= 10)
    {
        j = 0;
        /** i가 1이면 1반복, i가 2이면 2반복합니다. */
        while (j < i)
        {
            cout << "*";
            ++j;
        }

        cout << "" << endl;
        /** while문을 빠져 나갈 수 있는 조건을 만들어 줍니다. */
        ++i;
    }

    cout << "" << endl;
    cout << "" << endl;

    /**
    do while문 

    do
    {
        반복 실행할 코드 // 무조건 최초 한번은 실행됩니다. 
    }
    while (조건문);

    조건과 무관하게 반복 실행할 코드를 최초 한번 실행 후에 조건식이 참이면 다시 do블록으로
    돌아와 반복 실행할 코드를 실행하비다. 조건이 거짓일 때까지 반복합니다. 
    */
    int intValue7 = 20;

    do
    {
        cout << intValue7 << " ";
        /** while반복문을 빠져 나갈 수 있는 조건을 만들어 줍니다. */
        intValue7--;
    } while (intValue7 > 0); /** intValue7 변수의 값이 0보다 클때까지 반복합니다. */

    cout << "" << endl;
    cout << "" << endl;

    /**
    점프문에 대해서 알아 봅니다. 
    점프문(Jump Statement)는 특정 부분에서 건너뛰어 실행하는 제어 구문입니다. 
    점프문을 break, continue가 있습니다. 
    */
    /**
    break;
    break문은 현재 실행중인 반복문, switch문의 실행을 중단할 때 사용합니다. 

    결과를 확인해 보면 i가 100이라면 반복문을 빠져 나갑니다. 

    어떤 조건에 의해서 반복문을 빠져나가야 할 때 break문을 쓰게 됩니다. 
    반복문, switch문 안에서 break를 만나면 해당 반복문, switch문을 빠져 나옵니다. 
    */
    for (int i = 0; i < 1000000; i++)
    {
        /** 만약 i가 100이라면? */
        if (i == 100)
        {
            /** 반복문을 빠져 나갑니다. */
            break;
        }

        cout << "break : " << i << endl;
    }
    cout << "" << endl;

    /**
    continue;

    continue문은 이후의 코드를 실행하지 않고 다시 반복으로 넘어갑니다. 
    반복문에서 사용할 수 있으며 다시 조건을 검사하는 부분으로 넘어갑니다. 
    */

    /** 홀수만을 찾아 봅니다. */
    for (int i = 0; i < 100; i++)
    {
        /** i를 2로 나눈 나머지가 0이면 짝수이므로 문장을 실행하지 않고 다시 조건문으로 갑니다. */
        if (i % 2 == 0)
        {
            continue;
        }

        cout << "odd number : " << i << endl;
    }

    cout << "" << endl;
    cout << "" << endl;


    /** 짝수만을 찾아 봅니다. */
    for (int i = 0; i < 100; i++)
    {
        /** 어떤 값을 2로 나눈 나머지가 1이면 홀수 이므로 이후 문장을 실행하지 않고 다시 조건 검사합니다. */
        if (i % 2 == 1)
        {
            continue;
        }

        cout << "even number : " << i << endl;
    }

    cout << "" << endl;
    cout << "" << endl;
}

