#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 함수 오버로딩을 테스트 해 보기 위해서 Sum이라는 이름의 함수를 추가해 주도록 합니다. */ // (X)
/** 함수 오버로딩을 테스트 해 보기 위해서 Sum이라는 이름의 함수의 원형을 선언합니다. */
int Sum(int value1, int value2);
/** 함수 오버로딩을 테스트 해 보기 위해서 Sum이라는 이름의 함수의 원형을 선언합니다. */
double Sum(double value1, double value2);

/** 함수 오버로딩을 테스트 해 보기 위해서 Sum이라는 이름를 정의합니다. */
int Sum(int value1, int value2)
{
    return value1 + value2;
}

/** 함수 오버로딩을 테스트 해 보기 위해서 Sum이라는 이름의 함수를 정의합니다. */
double Sum(double value1, double value2)
{
    return value1 + value2;
}

/**
생성자 오버로딩에 대해서 알아봅니다.
겍체를 생성할 때 호출되는 생성자 함수를 중복 선언합니다.

테스트를 위해서 Calculator 클래스를 정의해 주도록 합니다.
*/
class Calculator
{
private:
    int m_Value1;
    int m_Value2;
public:
    /** 매개 변수가 없는 디폴트 생성자 함수의 원형을 선언합니다. */
    Calculator();
    /** 함수 오버로딩으로 생성자 함수의 원형을 선언합니다. */
    Calculator(int value1, int value2);
};

/**
매개 변수가 없는 디폴트 생성자 함수를 정의합니다.
생성자의 목적은 객체가 생성되면서 멤버 변수의 초기화를 담당합니다.
: 콜론 뒤의 초기화 리스트로 초기화를 담당합니다.
*/
Calculator::Calculator() : m_Value1(10), m_Value2(20) {}

/**
함수 오버로딩으로 생성자 함수를 정의합니다.
생성자 함수의 목적은 객체를 생성하면서 멤버 변수의 초기화를 담당합니다.
: 콜론 뒤의 초기화 리스트로 멤버 변수를 초기화 합니다.
*/
Calculator::Calculator(int value1, int value2) : m_Value1(value1), m_Value2(value2) {}

int main()
{
    /**
    함수 오버로딩에 대해서 알아 봅니다.
    오버로딩이란 함수를 중복으로 정의가 가능하다는 뜻입니다.
    오버로딩된 함수의 구분은 매개 변수를 기준으로 합니다.
    함수의 이름이 같지만 매개 변수가 고유하다면 컴파일러가 중복된 함수를 구별할 수 있습니다.
    */

    /**
    함수 오버로딩의 조건입니다.
    1. 함수 이름이 같아야 합니다.
    2. 리턴타입이 같아도 되고 달라도 됩니다.
    3. 매개 변수의 개수가 달라야 합니다.
    4. 매개 변수의 개수가 같다면, 자료형이 달라야 합니다.
    */

    /**
    오버로딩의 종류
    1. 함수 오버로딩
    2. 생성자 오버로딩
    */

    /** 함수 오버로딩을 테스트 해 보기 위해서 Sum이라는 이름의 함수를 추가해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    int intValue6 = Sum(10, 20);
    cout << "intValue6 : " << intValue6 << endl;
    cout << "" << endl;


    double doubleValue6 = Sum(30.2f, 25.3f);
    cout << "doubleValue6 : " << doubleValue6 << endl;
    cout << "" << endl;

    /**
    생성자 오버로딩에 대해서 알아봅니다.
    겍체를 생성할 때 호출되는 생성자 함수를 중복 선언합니다.

    테스트를 위해서 Calculator 클래스를 정의해 주도록 합니다.
    */
}


