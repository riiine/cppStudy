/** 2022.07.18 복습완료 */



#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리(C++ Standard Library) 사용합니다. */
using namespace std;

int main()
{
    /**
    연산자 (Operator)

    1. 산술 연산자 : 산술 연산자는 사칙연산과 같은 숫자의 연산을 하기 위해서 사용됩니다. 
    + 더하기   x + y
    - 빼기    x - y
    * 곱하기   x * y
    / 나누기   x / y
    % 나머지   x % y

    2. 대입 연산자 : 대입 연산자는 변수에 값을 대입(할당)하기 위해 사용됩니다. 
    =   x = 2       x = 2
    +=  x += 2      x = x + 2
    -=  x -= 2      x = x - 2
    *=  x *= 2      x = x * 2
    /=  x /= 2      x = x / 2
    %=  x %= 2      x = x % 2


    3. 비교 연산자 : 비교 연산자는 두 개의 값을 비교하기 위해 사용됩니다. 
    ==  양쪽의 값이 같으면 true를 리턴 (equal to)                                          x == y
    !=  양쪽의 값이 같지 않으면 true를 리턴 (not equal to)                                   x != y
    >   왼쪽의 값이 더 크면 true를 리턴 (greater than)                                     x > y
    <   왼쪽의 값이 더 작으면 true 리턴 (less than)                                        x < y
    >=  왼쪽의 값이 오른쪽의 값보다 같거나 더 크면 true를 리턴 (greater than or equal to)    x >= y
    <=  왼쪽의 값이 오른쪽의 값보다 같거나 더 작으면 true를 리턴 (less than or equal to)      x <= y


    4. 논리 연산자
    &&(and) 2개 모두 true이어야 true를 반환      x < 5 && x < 10
    ||(or)  2개 중 하나가 true이면 true를 반환    x < 5 || x < 10
    ! (not) true면 false, false면 true를 반환    !(x < 5 && x < 10)
    */
    /**
    int타입의 intValue1이라는 이름의 변수를 선언했습니다. 
    10의 값을 intValue1이라는 변수에 대입해서 초기화 했습니다. 
    */
    int intValue1 = 10;

    /**
    int타입의 intValue2라는 이름의 변수를 선언했습니다. 
    3의 값을 intValue2라는 변수에 대입해서 초기화 했습니다. 
    */
    int intValue2 = 3;

    int addition = intValue1 + intValue2;
    cout << "더하기 : " << intValue1 << " + " << intValue2 << " = " << addition << endl;
    cout << "" << endl;

    int subtraction = intValue1 - intValue2;
    cout << "빼기 : " << intValue1 << " - " << intValue2 << " = " << subtraction << endl;
    cout << "" << endl;

    int multiplication = intValue1 * intValue2;
    cout << "곱하기 : " << intValue1 << " * " << intValue2 << " = " << multiplication << endl;
    cout << "" << endl;

    int division = intValue1 / intValue2;
    cout << "나누기 : " << intValue1 << " / " << intValue2 << " = " << division << endl;
    cout << "" << endl;

    /**
    % : 모듈러(modular) 연산자입니다. intValue1변수의 값을 intValue2변수의 값으로 나누었을 때의 나머지 값입니다. 
    */
    int remainder = intValue1 % intValue2;
    cout << "나머지 : " << intValue1 << " % " << intValue2 << " = " << remainder << endl;
    cout << "" << endl;

    /**
    나누기 결과가 잘 못 나오는 것을 볼 수 있습니다. 나머지의 결과는 실수로 나올 수도 있기 때문입니다. 
    그런 어떻게 해야 할까요? 문장을 수정해 줍니다. 
    */
    float division1 = intValue1 / intValue2;
    cout << "나누기 : " << intValue1 << " / " << intValue2 << " = " << division1 << endl;
    cout << "" << endl;

    /** 나누기의 결과가 여전히 틀립니다. 문장을 수정해 주도록 합니다. */

    /**
    정수값을 실수값으로 바꾸어서 계산을 했습니다. 
    이렇게 괄호 안에 바꿀 자료형을 넣어주는 것을 명시적 형변환 이라고 합니다. 
    나누기의 경우 주의를 해야만 합니다. 


    정수 / 정수 -> 정수
    실수 / 정수 -> 실수
    정수 / 실수 -> 실수
    실수 / 실수 -> 실수
    */

    float division2 = (float)intValue1 / (float)intValue2;
    cout << "나누기 : " << intValue1 << " / " << intValue2 << " = " << division2 << endl;
    cout << "" << endl;

    /** 형변환에 대한 테스트를 좀 더 해 보도록 합니다. 문장을 추가해 줍니다. */
    /** int타입의 변수에 float타입의 값을 대입했습니다. 자동형변환(암묵적, 묵시적 형변환)이 이루어 집니다. */
    int intValue3 = 1.414f; // (X)
    /** float타입의 변수에 int 타입의 변수의 값을 대입했읍니다. 자동형변환(암묵적, 묵시적 형변환)이 이루어 집니다. */
    float floatValue3 = 1024;

    /** 이렇게 자동 형변환이 이루어졌지만 결과가 이상합니다. 프로그래밍은 내부적으로 산술연산이므로 조심해야 합니다. */

    /** 실수타입을 정수 타입의 변수에 자동형변환 하는 것은 절대로 피해야 합니다. */

    cout << "intValue3 : " << intValue3 << ", floatValue3 : " << floatValue3 << endl;
    cout << "" << endl;

    /** 평균값을 구해 보도록 합니다. 문장을 추가해 줍니다. */
    int math = 90;
    int history = 95;
    int english = 84;

    int total = math + history + english;
    /**
    정수값을 실수값으로 바꾸어서 계산을 했습니다. 
    이렇게 괄호 안에 바꿀 자료형을 넣어주는 것을 명시적 형변환이라고 합니다. 
    나누기의 경우 주의를 해야만 합니다. 

    정수 / 정수 -> 정수
    실수 / 정수 -> 실수
    정수 / 실수 -> 실수
    실수 / 실수 -> 실수
    */
    float average = (float)total / 3;

    cout << "total : " << total << ", average : " << average << endl;

    /**
    주석에 대해서 알아 봅니다. 주석은 설명글이라고 볼 수 있습니다. 
    실제 연산에 포함되지 않습니다. 문장을 추가해 줍니다. 
    */

    // 나는 한줄 주석입니다. !!

    /** 나는 여러줄 주석입니다. */

    /**
     나는 첫번째 주석입니다. 
     나는 두번째 주석입니다. 
     나는 세번째 주석입니다
    */

    /** 대입(할당) 연산자에 대해서 알아 봅니다. */

    int intValue4 = 35;
    cout << "before intValue4 : " << intValue4 << endl;
    cout << "" << endl;
    /** intValue4변수의 값에 5을 더해서 intValue4 변수에 대입했습니다. */
    intValue4 = intValue4 + 5;
    cout << "after intValue4 : " << intValue4 << endl;
    cout << "" << endl;

    /** 다음은 증감연산자 입니다. 1이 증가하는 문장을 추가해 줍니다. */
    intValue4++;
    cout << "intValue4++ : " << intValue4 << endl;
    cout << "" << endl;

    ++intValue4;
    cout << "++intValue4 : " << intValue4 << endl;
    cout << "" << endl;

    intValue4 += 1;
    cout << "intValue4 += 1 : " << intValue4 << endl;
    cout << "" << endl;

    intValue4 = intValue4 + 1;
    cout << "intValue4 = intValue4 + 1 : " << intValue4 << endl;

    /** 1이 감소하는 문장을 추가해 줍니다. */
    intValue4--;
    cout << "intValue4-- : " << intValue4 << endl;
    cout << "" << endl;

    --intValue4;
    cout << "--intValue4 : " << intValue4 << endl;
    cout << "" << endl;

    intValue4 -= 1;
    cout << "intValue4 -= 1 : " << intValue4 << endl;
    cout << "" << endl;

    intValue4 = intValue4 - 1;
    cout << "intValue4 = intValue4 - 1 : " << intValue4 << endl;

    /** 전치 증가 연산자와 후치 증가 연산자에 대해서 알아 봅니다. 문장을 추가해 줍니다. */
    int intValue5 = 10;
    int intValue6;
    /**
    전치 증가 연산은 ++intValue5처럼 변수 앞에 연산자를 씁니다. 
    intValue6 = ++intValue5; 라고 쓰면 intValue5가 1 증가 된 상태에서 값이 intValue6에 들어갑니다. 
    따라서 intValue5도 11이 되고, intValue6도 11이 됩니다. 
    */
    intValue6 = ++intValue5;
    cout << "전치 증가 연산자 intValue5 : " << intValue5 << endl;
    cout << "전치 증가 연산자 intValue6 : " << intValue6 << endl;
    cout << "" << endl;

    /** 테스트를 위해서 초기화를 해 줍니다. */
    intValue5 = 10;
    /**
    후치 증가 연산은 intValue5++ 처럼 변수 뒤에 연산자를 씁니다. 
    intValue6 = intValue5++; 라고 쓰면 intValue5의 값이 intValue6에 들어가고
    그런 다음에 intValue5값이 1 증가합니다. 
    따라서 intValue5의 값은 11이 되고 intValue6의 값은 10이 됩니다. 
    */
    intValue6 = intValue5++;
    cout << "후치 증가 연산자 intValue5 : " << intValue5 << endl;
    cout << "후치 증가 연산자 intValue6 : " << intValue6 << endl;
    cout << "" << endl;

    /**
    관계 연산자(Relational Operator, 비교 연산자)에 대해서 알아 봅니다. 
    C++에는 여것 가지의 관계 연산자가 있습니다. 
    관계 연산자는 boolean타입으로 true(1) 또는 false(0)으로 값을 반환합니다. 

    >   : greater than              , x > y     , x가 y보다 큰지? 
    <   : less than                 , x < y     , x가 y보다 작은지? 
    >=  : greater than or equal to  , x >= y    , x가 y보다 크거나 같은지?
    <=  : less than or equal to     , x <= y    , x가 y보다 작거나 같은지?
    ==  : equal                     , x == y    , x와 y가 같은지? 
    !=  : not equal                 , x != y    , x와 y가 다른지? 
    */

    /** 문장을 추가해 줍니다. */
    int intValue7 = 10;
    int intValue8 = 15;

    if (intValue7 > intValue8)
        cout << intValue7 << " is greater than " << intValue8 << endl;

    if (intValue7 < intValue8)
        cout << intValue7 << " is less than " << intValue8 << endl;

    if (intValue7 >= intValue8)
        cout << intValue7 << " is greater than or equal to " << intValue8 << endl;

    if (intValue7 <= intValue8)
        cout << intValue7 << " is less than or equal to " << intValue8 << endl;

    if (intValue7 == intValue8)
        cout << intValue7 << " is equal to " << intValue8 << endl;

    if (intValue7 != intValue8)
        cout << intValue7 << " is not equal to " << intValue8 << endl;

    cout << "" << endl;

    /**
    논리 연산자에 대해서 알아보도록 합니다. 

    !   : Logical Not 부정입니다. 값이 참이면 거짓이 되고, 값이 거짓이면 참이 됩니다. 
    &&  : Logical AND 양쪽이 모두 참이면 참이 됩니다. 그 외에는 거짓입니다. 
    ||  : Logical OR 한쪽이 참이면 참이 됩니다. 그 외에는 거짓입니다. 
    */

    int intValue9 = 10;
    /**
    intValue9변수의 값이 1보다 크가나 같고 intValue9변수의 값이 10보다 작거나 같다
    양쪽이 모두 참이면 참이 됩니다. 그 외에는 거짓이 됩니다. 
    */
    bool boolValue1 = intValue9 >= 1 && intValue9 <= 10;
    cout << "boolValue1 : " << boolValue1 << endl; // true
    /**
    intValue9변수의 값이 2와 같거나 intValue9변수의 값이 10과 같다
    한쪽이 참이면 참이 됩니다. 그 외에는 거짓이 됩니다. 
    */
    bool boolValue2 = intValue9 == 2 || intValue9 == 10;
    cout << "boolValue2 : " << boolValue2 << endl; // true
    /**
    boolValue2변수의 값이 참이면 거짓이고, boolValue2변수의 값이 거짓이면 참입니다. 
    부정입니다. 값이 참이면 거짓이 되고, 값이 거짓이면 참이 됩니다. 
    */
    bool boolValue3 = !boolValue2;
    cout << "boolValue3 : " << boolValue3 << endl; // false

    cout << "" << endl;

    /**
    boolean변수가 1과 0으로 표시됩니다. true와 false로 표시되도록 문장을 추가해 줍니다. 
    삼항연산자
    조건 ? A문장 : B문장   조건에 맞으면 A문장이 실행돠고, 조건에 맞지 않으면 B문장이 실행됩니다. 
    */
    cout << "boolValue1 : " << (boolValue1 ? "true" : "fasle") << endl;
    cout << "boolValue2 : " << (boolValue2 ? "true" : "fasle") << endl;
    cout << "boolValue3 : " << (boolValue3 ? "true" : "fasle") << endl;

    cout << "" << endl;

    /** 
    C언어와 C++의 관계
    C++은 거의 40년이 되었습니다. 
    C언어는 50년이 되었습니다. 
    C++언어는 별명이 있습니다. Super C, C with class

    C++언어는 거의 대부분의 C언어의 문법을 포함합니다. 
    C++언어는 객체 지향 언어입니다. 
    C언어는 절차 지향 언어입니다. 

    만일 여러분들이 정신적으로 여유가 있으시다면
    1. 네이버 카페에 Unreal C++ 문서 공부하시기를 바랍니다. 
    2. 파이썬을 공부하기를 바랍니다. 
        게임제작은 엄청 노가다입니다. 하지만 파이썬으로 게임제작의 노가다를 확실하게 줄일 수 있습니다. 
    */

    /**
    연산자 우선 순위에 대해서 알아 보도록 합니다. 
    30 + 2 * 3의 결과값은 무엇일까요? 36일까요? 96일까요?

    둘다 맞습니다. 
    */
    int intValue10 = 30 + 2 * 3;
    cout << "30 + 2 * 3 : " << intValue10 << endl;
    cout << "" << endl;

    /**
    나는 96의 값을 생각하고 코딩을 하고 있는데 36이 나입니다. 버그입니다. 어떻게 해야 할까요? 
    */
    intValue10 = (30 + 2) * 3;
    cout << "(30 + 2) * 3 : " << intValue10 << endl;
    cout << "" << endl;

    /** 36의 값이 나오도록 수정해 줍니다. */
    intValue10 = 30 + (2 * 3);
    cout << "30 + (2 * 3) : " << intValue10 << endl;
    cout << "" << endl;

    intValue10 = 30 + 2 * 3;
    cout << "30 + 2 * 3 : " << intValue10 << endl;
    cout << "" << endl;

    /**
    뭔가 상당히 복잡해 보입니다. 
    ++, --, (), *, /, +, -순입니다. 
    () : 소괄호가 연산자 우선순위가 상당히 높습니다. 
        적절하게 소괄호를 이용하면 원하는 값을 가져올 수 있습니다. 

    ()  : 소괄호
    {}  : 중괄호
    []  : 대괄호
    <>  : 꺽쇠괄호
    */


}
