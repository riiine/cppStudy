#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 배열의 사이즈를 가져오기 위한 라이브러리*/
#include <array>

/** C++ 표준 라이브러리*/
using namespace std;

class Lion
{
public:
    /**
    생성자들을 정의해 주도록 합니다.
    : 콜론 뒤는 멤버 변수의 값을 초기화 해 주는 것입니다.
    생성자라고도 하고 변환생성자라고도 합니다.
    */
    Lion(int eyeSight) : m_EyeSight(eyeSight)
    {
        cout << "Lion(int)" << endl;
    }

    Lion(string name) : m_Name(name)
    {
        cout << "Lion(string)" << endl;
    }

    Lion(int eyeSight, string name) : m_EyeSight(eyeSight), m_Name(name)
    {
        cout << "Lion(int, string)" << endl;
    }

    /** 멤버 함수를 추가해 줍니다. */
    void SetInfo()
    {
        cout << "EyeSight : " << m_EyeSight << " : " << ", Name : " << m_Name << endl;
    }

    /**
    int 타입으로의 형변환 연산자 오버로딩입니다.
    형변환 함수(type conversion)라고도 합니다.
    형변환 연산자 오버로딩은 형변환 연산자를 실행하는 동안에 객체 자체의 값을 바꾸지
    않는 다는 것을 보장하기 위해서 const 키워드를 붙여 줍니다.
    */
    operator int() const
    {
        return m_EyeSight;
    }

    /**
    문자열 타입으로의 형변환 연산자 오버로딩입니다.
    형변환 함수(type conversion function)라고도 합니다.
    형변환 연산자 오버로딩은 형변환 연산자를 실행하는 동안에 객체 자체의 값을 바꾸지
    않는다는 것을 보장하기 위해서 const 키워드를 붙여 줍니다.
    */
    operator string() const
    {
        /** to_string() : 매개 변수로 입력받은 값을 문자열로 변경해 주는 함수입니다.*/
        string info = to_string(m_EyeSight) + " : " + m_Name;
        return info;
    }

private:
    /**
    객체 지향 언어에스는 멤버 변수는 private 접근 지정자 안에 둡니다.
    private 접근 지정자 안에 두게 되면 다른 클래0스에서 멤버 변수에 접근할 수가 없습니다.
    멤버 변수에 접근하기 위해서는 멤버 함수를 통해서 접근하고
    멤버 함수는 public 접근 지정자 안에 둡니다.
    멤버 변수는 변수 이름만 보더라도 멤버 변수인것을 알 수 있도록
    변수 이름 앞에 m, m_, _ 접두사를 붙여 줍니다.
    */
    int m_EyeSight;  // 시력
    string m_Name;
};

/**
전역 범위에서 함수를 정의해 주도록 합니다.
전역 범위는 함수밖을 의미합니다.
*/
void SetMessage(string info)
{
    cout << info << endl;
}

int main()
{
    /**
    형변환은 C언어 스타일의 형변환과 C++ 스타일의 형변환이 있습니다.
    C언어 스타일의 형변환은 2가지 종류가 있습니다.
    1. 묵시적 형변환(Implicit Cast) : 컴파일러가 자동적으로 형변환을 시키는 것을 의미합니다.
    주로 대입연산자에서 발생합니다.
    2. 명시적 형변환(Explicit Cast) : 명시적으로 자료형을 직접 변경해 주는 것을 의미합니다.
    변수 앞에 소괄호() 를 통해서 변경할 수 있습니다.
    형변환은 3가지의 모습을 가지고 있습니다.
    */

    /** 실수 타입을 정수 타입으로 형변환 합니다. */
    float floatValue1 = 3.14159265f;
    int intValue1 = floatValue1;        // 묵시적 형변환
    int intValue2 = (int)floatValue1;   // 명시적 형변환
    int intValue3 = int(floatValue1);   // 명시적 형변환

    cout << "floatValue1 : " << floatValue1 << endl;
    cout << "float to int -> intValue1 : " << intValue1 << endl;
    cout << "float to int -> intValue2 : " << intValue2 << endl;
    cout << "float to int -> intValue3 : " << intValue3 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 실수 타입을 정수 타입으로 형변환 하면 실수 타입의 소수점 아래 값들이 모두 없어집니다. */
    int intValue4 = 3.14159265f;
    float floatValue4 = 1024;

    cout << "intValue4 : " << intValue4 << ", floatValue4 : " << floatValue4 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 평균을 구해 봅니다.*/
    int math = 90;
    int korean = 85;
    int english = 95;
    int history = 97;
    /** 합계를 구해 봅니다. */
    int sum = math + korean + english + history;
    /** 평균을 구해 봅니다. */
    int average = sum / 4;

    cout << "sum : " << sum << ", average : " << average << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    평균이 91.75가 나와야 하는데, 91이 나옵니다.
    정수 / 정수 = 정수
    실수 / 정수 = 실수
    정수 / 실수 = 실수
    실수 / 실수 = 실수
    */

    /** 문장을 수정해 주도록 합니다. */
    // int averageScore = (float)sum / 4;  // 명시적 형변환
    float averageScore = (float)sum / 4;  // 명시적 형변환

    cout << "sum : " << sum << ", averageScore : " << averageScore << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 테스트를 위해서 Lion이라는 이름의 클래스를 정의해 주도록 합니다. */

    /**
    생성자 호출로 객체 생성을 해 주도록 합니다.
    객체 생성은 다양한 표현 방식이 있습니다.
    */
    Lion lion1 = Lion(10);
    Lion lion2(2);
    Lion lion3 = 25;
    lion3 = 30;   // 변환 생성자에 의한 묵시적 형변화
    Lion lion4 = (Lion)30; // 명시적 형변환

    cout << "" << endl;
    cout << "" << endl;

    /**
    문자열을 매개변수로 가지고 있는 생성자를 호출해 봅니다.
    C++ 은 C언어의 거의  모든 문법을 포함하는데, C언어때는 문자열 타입이 없었습니다.
    C언어때는 boolean타입도 없었습니다.
    문자열을 기본 자료형이 아닙니다.
    기본 자료형 : char, int, long, float, double, bool
    문자열 타입은 외부라이브러리 입니다 #include <string>
    에러가 생기니 문자열 타입으로 명시적 형변환을 해 주도록 합니다.
    */
    // Lion lion5 = "Simba"; // (X)
    Lion lion5 = (string)"Simba";  // 변환 생성자에 의한 명시적 형변환
    Lion lion6 = string("KingLion");
    lion6 = (string)"White";       // 변환 생성자에 의한 명시적 형변환
    lion6 = string("Black");

    cout << "" << endl;
    cout << "" << endl;

    /** 정수타입과 문자열 타입을 모두 매개변수로 가지고 있는 생성자 호출해 봅니다. */
    Lion lion7(30, "Simba");
    Lion lion8 = { 25, "KingLion" };
    lion8 = { 30, "White" };
    Lion lion9{ 20, "Black" };

    cout << "" << endl;
    cout << "" << endl;

    cout << "정수타입을 매개변수로 가진 생성자로 객체 생성" << endl;
    /** 문자열 타입을 선언하고 값을 주지 않으면? nullptr입니다. 빈 문자열이 아닙니다. */
    lion1.SetInfo();
    lion2.SetInfo();
    lion3.SetInfo();
    lion4.SetInfo();
    cout << "" << endl;

    cout << "문자열 타입을 매개변수로 가진 생성자로 객체 생성" << endl;
    /** 정수 타입에 쓰레기 값이 들어갑니다. */
    lion5.SetInfo();
    lion6.SetInfo();
    cout << "" << endl;

    cout << "정수타입과 문자열 타입을 매개변수로 가진 생성자로 객체 생성" << endl;
    lion7.SetInfo();
    lion8.SetInfo();
    lion9.SetInfo();
    cout << "" << endl;

    /**
    변환 생성자로 정수값을 Lion타입으로 형변환 해 보았습니다.
    반대로 Lion타입을 정수값으로 변환할 수 있을 까요?
    에러가 나면서 변환이 되지 않습니다.
    */
    // int intValue5 = lion9;       // (X)
    // int intValue6 = (int)lion9;  // (X) 명시적 형변환

    /**
    형변환 자체도 연산자입니다. 형변환 연산자라고 합니다.
    연산자 오버로딩으로 해결할 수 있습니다.
    int 타입으로의 형변환 연산자 오버로딩을 해 주도록 합니다.
    형변환 함수(type conversion) 이라고도 합니다.
    */
    int intValue5 = lion9;      // 묵시적 형변환   
    int intValue6 = (int)lion9; // 명시적 형변환

    cout << "intValue5 : " << intValue5 << endl;
    cout << "intValue6 : " << intValue6 << endl;

    cout << "" << endl;
    cout << "" << endl;


    /**
    문자열 타입을 Lion타입으로 형변환 해 보았습니다.
    반대로 Lion타입을 문자열 타입으로 변환할 수 있는지 알아 봅니다.
    변환이 되지 않습니다.
    */
    // string strLion8 = lion8; // (X)
    // string strLion9 = (string)lion9; // (X)

    /**
    연산자 오버로딩으로 해결 할 수 있습니다.
    문자열 타입으로의 형변환 연산자 오버로딩을 해주도록 합니다.
    현변환 연산자 오버로딩은 형변환 함수(type conversion function)라고도 합니다.
    */

    /**
    다양한 방법으로 Lion객체를 문자열로 변경해 봅니다.
    Lion객체의 생성자 중의 하나가 문자열을 매개변수로 가지고 객체를 생성하기 때문입니다.
    반대로 객체가 가지고 있는 문자열을 문자열 변수에 넣어주는 것입니다.
    */

    string strLion = lion8;
    /**
    SetMessage() 함수는 매개변수로 문자열 타입입니다.
    따라서 lion9 객체가 문자열로 묵시적 형변환이 된다고 볼 수 있습니다.
    */
    SetMessage((string)lion8);      // 명시적 형변환

    SetMessage(lion8);              // 묵시적 형변환
    cout << (string)lion8 << endl;  // 명시적 형변환

    cout << lion8 << endl;          // lion8 객체를 그냥 출력 했습니다. 
    string strLion8 = lion8;        // 묵시적 형변환
    cout << strLion8 << endl;

    /**
    기본적인 행변환 정리를 했습니다.
    C++ 만의 형변환이 남아 있습니다.
    */
}
