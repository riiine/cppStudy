#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 테스트를 위해서 Date라는 이름의 클래스를 정의합니다. */
class Date
{
    /**
    접근 지정자가 없습니다. 클래스에서 접근 지정자가 없으면 디폴트로 private입니다.
    m_Year 멤버 변수는 private 접근 지정자 안에 있기 때문에 클래스의 멤버 함수에서만
    접근이 가능하고 그 외에서는 불가능합니다.
    Date클래스를 부모 클래스로 상속받는 자식클래스에서도 접근이 불가능합니다.
    */
    int m_Year;

public:
    int m_Month;
    int m_Day;
};

/**
3. C++ 에서는 C#과는 틀리게 속성(Property)이 없습니다.
접근함수 Getter, Setter
private 멤버 변수들은 public한 접근 함수들을 만들어서 이를 통해 간접적으로 접근합니다.
테스트를 위해서 DateTime이라는 이름의 클래스를 정의해 줍니다.
*/
class DateTime
{
private:
    /** 모든 멤버 변수들은 private 접근 지정자 안에 있어야 합니다. */
    int m_Year;
    int m_Month;
    int m_Day;
protected:

public:
public:
public:
    /** 모든 멤버 함수들은 public 접근 지정자 안에 있어야 합니다. */
    void Setdate(int year, int month, int day)
    {
        m_Year = year;
        m_Month = month;
        m_Day = day;

        cout << "m_Year : " << m_Year << ", m_Month : " << m_Month << ", m_Day : " << m_Day << endl;
    }

    void SetYear(int year)
    {
        m_Year = year;

        cout << "m_Year : " << m_Year << endl;
    }
};

/**
캡슐화라는 것은 멤버 변수를 직접 변경할 수 없도록 캡슐처럼 껍데기를 둘러싸는 과정을 의미합니다.
테스트를 위해서 Parent1, Child1이라는 이름의 클래스를 정의해 줍니다.
*/
class Parent1
{
private:
    int m_A;
    int m_B;
public:
    void SetA(int a)
    {
        /**
        멤버 변수가 public 접근 지정자 안에 있으면 멤버 변수에 아무 값이나 넣을 수가 있습니다.
        하지만 멤버 변수를 private 접근 지정자 안에 두고 public 접근 지정자 안에 있는 멤버 함수로
        멤버 변수에 접근을 하면 멤버 변수의 값을 제한할 수 있습니다.
        아무리 a 매개 변수에 많은 값을 주어도 멤버 변수 m_A의 최대값은 50입니다.
        멤버 변수의 보호입니다.
        */
        if (a > 50)
        {
            a = 50;
        }

        m_A = a;
    }

    void SetB(int b)
    {
        /**
        아무리 b 매개 변수에 많은 값을 주어도 멤버 변수 m_B의 최대값은 100입니다.
        멤버 변수의 값을 제한할 수가 있습니다.
        멤버 변수의 보호입니다.
        */
        if (b > 100)
        {
            b = 100;
        }

        m_B = b;
    }

    int GetA()
    {
        return m_A;
    }

    int GetB()
    {
        return m_B;
    }
};

class Child1 : public Parent1
{
public:
    void SetAB(int a, int b)
    {
        /** 부모 클래스를 상속받는 자식클래스라면 범위지정자(::  소속을 의미합니다. ) 를 붙이지 않아도 됩니다. */
        SetA(a);
        SetB(b);
        Parent1::SetA(a);
        Parent1::SetB(b);

        /**
        부모 클래스의 private 접근 지정자 안에 있는 멤버 변수는
        상속을 받은 자식 클래스에서도 접근이 불가능합니다.
        오직 부모 클래스의 멤버 함수로만 접근이 가능합니다.
        */
        // Parent1::m_A; // (X)
        // Parent1::m_B; // (X)
    }

    void SetResult()
    {
        cout << "GetA() : " << GetA() << ", GetB() : " << GetB() << endl;
        cout << "Parent1::GetA() : " << Parent1::GetA() << ", Parent1::GetB() : " << Parent1::GetB() << endl;
    }
};

int main()
{
    std::cout << "" << std::endl; // (X)
    cout << "" << endl;

    /**
    캡슐화(Encapsulation)

    객체 지향 프로그래밍 (OOP : Object Oriented Programming)
        : 캡슐화, 접근 지정자, 접근 함수

    왜 멤버 변수를 비공개(private)로 할까요?
    객체 지향 언어(C#, Java, C++)에서 멤버 변수는 private 접근 지정자 안에 두어서 외부 객체가
    접근 불가능하게 합니다. 멤버 변수의 보호 때문입니다.

    C++ 에서는 접근 지정자를 두어서 캡슐화를 구현합니다.
    일반적으로 클래스의 멤버 변수는 private으로 설정하고, 멤버 함수는 public으로 설정합니다.
    캡슐화는 외부에 데이터를 은닉하는데 많이 사용이 되는데,
    멤버의 접근 지정어로 3가지가 있습니다.
    public(공개적인)  : 외부 클래스에서 무조건 접근이 가능합니다.
    protected(보호된) : 부모 클래스를 상속받은 자식클래스에서는 public입니다. 외부 클래스에서는 private입니다.
    private(개인적인) : 외부 클래스에서 접근이 불가능합니다, 외부 클래스에서 멤버 함수로 접근이 가능하도록 해 줍니다.
    */

    /**
    1. 캡슐화
    외부로부터 중요한 데이터(멤버 변수)와 기능(멤버 함수)을 보호하고 은닉하는 것입니다.
    C++에서 클래스의 구성요소는 멤버 변수와 멤버 함수입니다.

    C#에서 클래스의 구성요소는 멤버 변수와 멤버 함수, 속성(Property)입니다.

    우리는 연관있고 공통적인 데이터(멤버 변수)와 기능(멤버 함수)들을 묶어서 객체 지향(추상화)하였습니다.

    데이터와 기능들 중에서 접근할 수 있는 영역을 제한하고(접근 지정자의 역활) 외부로부터
    은닉하는 것을 캡슐화라고 합니다.

    보통 캡슐화를 설명할 때 콘택600을 예로 듭니다.
    콘택600의 알약들은 내가 모르는 private에 있는 멤버 변수들입니다.
    콘택600의 캡슐은 멤버 함수들입니다. 콘택600을 먹으면 감기가 낮습니다.
    */

    /**
    2. 접근 지정자

    클래스에서 접근지정자를 지정해 주지 않으면 디폴트로 private으로 인식합니다.
    구조체가 발전된 형태가 클래스입니다.
    구조체에서 접근지정자를 지정해 주지 않으면 디폴트로 public으로 인식합니다.
    접근 지정자는 객체지향의 중요한 특징인 캡슐화를 지원하는 역활을 합니다.

    puclic(공개적인) : 외부의 모든 곳에서 접근이 허용됩니다.
    pretected(보호적인) : 이 클래스를 상속받는 자식 클래스에서만 접근이 가능합니다.
                    그 외에는 접근이 불가능합니다.
    private(개인적인) : 클래스 내의 멤버 함수에서만 접근이 가능합니다.
                    이 클래스를 상속받는 자식 클래스에서도 접근이 불가능합니다.
    */

    /** 테스트를 위해서 Date라는 이름의 클래스를 정의합니다. */

    /** 문장을 추가해 줍니다. */

    Date today;
    today.m_Month = 8;
    today.m_Day = 28;
    /** m_Year 멤버 변수는 private 접근 지정자 안에 있기 때문에 접근이 불가능합니다. */
    // today.m_Year = 2021; // (X)

    /**
    3. C++ 에서는 C#과는 틀리게 속성(Property)이 없습니다.
    접근함수 Getter, Setter
    private 멤버 변수들은 public한 접근 함수들을 만들어서 이를 통해 간접적으로 접근합니다.
    테스트를 위해서 DateTime이라는 이름의 클래스를 정의해 줍니다.
    */

    /** 문장을 추가해 줍니다. */
    DateTime dateTime;
    /**
    private 접근 지정자 안에 있는 멤버 변수들에게 값을 주었습니다.
    멤버 변수들은 private 접근 지정자 안에 두고, 멤버 함수들은 public 접근 지정자 안에 두어서
    private 접근 지정자 안에 있는 멤버 변수들을 초기화 하거나 값을 변경할 수 있습니다.
    */
    dateTime.Setdate(2022, 8, 26);
    cout << "" << endl;
    /** private 접근 지정자 안에 있는 멤버 변수에 값을 주었습니다. */
    dateTime.SetYear(2022);
    cout << "" << endl;

    /**
    캡슐화라는 것은 멤버 변수를 직접 변경할 수 없도록 캡슐처럼 껍데기를 둘러싸는 과정을 의미합니다.
    테스트를 위해서 Parent1, Child1이라는 이름의 클래스를 정의해 줍니다.
    */

    /** 문장을 추가해 줍니다. */

    /**
    Child1 클래스는 Parent1클래스를 부모 클래스로 상속받습니다.
    이 때 멤버 변수 m_A, m_B는 직접 설정할 수 없도록 private 접근 지정자로 접근을 제한했습니다.
    */
    Child1 child1;
    /**
    SetAB() 함수를 호출해서 m_A의 값을 100, m_B의 값을 200으로 변경하려고 합니다.
    하지만 Parent1클래스에서는 이것을 용납하지 않습니다.
    m_A의 최대값을 50으로, m_B의 최대값을 100으로 제한을 하였습니다.
    이렇게 멤버 변수의 값을 함부로 변경할 수 없도록 멤버 변수들에 껍질(캡슐)을 입히는 과정을 캡슐화라고 합니다.
    */
    child1.SetAB(100, 200);
    child1.SetResult();


}

