#include <iostream>
// 문자열 관련 라이브러리
#include <string>

// C++ 표준 라이브러리
using namespace std;

// 테스트를 위해서 Date라는 이름의 클래스를 정의합니다. 
class Date
{
    // 접근 지정자가 없습니다. 클래스에서 접근 지정자가 없으면 디폴트로 private입니다. 
    int m_Year; // m_Year 멤버변수는  private 접근 지정자 안에 있기 때문에 클래스의 
                // 멤버 함수에서만 접근이 가능하고 그 외에는 불가능합니다. 

public:
    int m_Month;
    int m_Day;
};

// 테스트를 위해서 DateTime이라는 이름의 클래스를 정의해 주도록 합니다. 
class DateTime
{
private:
    // 모든 멤버 변수들은 private 접근 지정자 공간에 있습니다. 
    int m_Year;
    int m_Month;
    int m_Day;
public:
    // 모든 멤버 함수들은 public  접근 지정자 공간에 있습니다. 
    void SetDate(int year, int month, int day)
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
protected:
};

// Parent1, Child1이라는 클래스를 정의해 주도록 합니다. 
class Parent1
{
private:
    int a;
    int b;
public:
    void SetA(int _a)
    {
        if (_a > 50) // 멤버 변수가 public에 있으면 멤버 변수의 아무 값이나 넣을 수가 있습니다. 
            _a = 50; // 하지만 멤버 변수를 private공간에 두고 public 공간에 있는 멤버 함수로 멤버 변수에 접근을 하면 
                     // 멤버 변수의 값을 제한 할 수가 있습니다. 
        a = _a;      // 아무리 _a 매개변수에 많은 값을 주어도 멤버 변수 a의 최대값을 50입니다. 
    }
    void SetB(int _b)
    {
        if (_b > 100)
            _b = 100;

        b = _b;       // 아무리 _b 매개 변수에 많은 값을 주어도 멤버 변수 b의 값의 최대값은 100입니다. 
    }
    int GetA()
    {
        return a;
    }
    int GetB()
    {
        return b;
    }

protected:

};

class Child1 : Parent1
{
public:
    void SetAB(int a, int b)
    {
        // 부모클래스를 상속받은 자식클래스라면 범위지정자(:: 소속을 의미합니다. )를 붙이지 않아도 됩니다.
        // SetA(a);
        // SetB(b);
        Parent1::SetA(a);
        Parent1::SetB(b);
    }
    void SetResult()
    {
        // 부모클래스를 상속받은 자식클래스라면 범위지정자(:: 소속을 의미합니다. )를 붙이지 않아도 됩니다.
        // cout << GetA() << " + " << GetB() << " = " << GetA() + GetB() << endl;
        cout << Parent1::GetA() << " + " << Parent1::GetB() << " = " << Parent1::GetA() + Parent1::GetB() << endl;
    }
};

int main()
{
    // 캡슐화(Encapusulation)
    // 객체 지향의 기초 : 캡슐화, 접근 지정자, 접근 함수
    // 왜 멤버변수를 비공개(private)로 할까요?
    // 객체 지향 언어(C#, Java, C++)에서 멤버 변수는 private 접근 지정자 안에 
    // 두어서 외부 객체가 접근 불가능 하게 합니다. 멤버 변수의 보호 때문입니다. 
    // C++ 에서는 접근 지정자를 통해서 캡슐화를 구현합니다. 
    // 일반적으로 클래스의 멤버 변수는 private로 설정하고, 멤버 함수는 public으로 설정합니다. 
    // 캡슐화는 외부에 데이터를 은닉하는데 많이 사용이 되는데, 멤버의 접근 지정어로
    // public(공개적인), protected(보호된), private(개인적인)로 선언을 해 줍니다. 

    // 1. 캡슐화
    // 외부로부터 중요한 데이터(멤버 변수)와 기능(멤버 함수)을 보호하고 은닉하는 것입니다. 
    // 클래스의 구성 요소 : 멤버 변수와 멤버 함수입니다. 
    // 우리는 연관 있고 공통적인 데이터(멤버 변수)와 기능(멤버 함수)들을 묶어서 
    // 추상화 하였습니다. 
    // 데이터와 기능들 중에서 접근할 수 있는 영역을 제한하고(접근 지정자의 역활) 외부로부터
    // 은닉하는 것을 캡슐화라고 합니다. 
    // 이 때  캡슐화란 알약의 내용물이 캡슐로부터 보호받는 것처럼 객체를 외부로부터 
    // 보호하는 것을 의미합니다. 
    // 보통 캡슐화를 설명할 때 콘택600을 예로 듭니다. 
    // 콘택600의 알약들은 내가 모르는  private에 있는 멤버 변수들입니다. 
    // 콘택600의 캡슐은 멤버 함수들입니다. 콘택600을 먹으면 감기가 낫습니다. 

    // 2. 접근 지정자
    // 클래스에서 접근지정자를 지정해 주지 않으면 디폴트로 private로 인식합니다. 
    // 구조체가 발전된 형태가 클래스입니다. 
    // 구조체에서 접근지정자를 지정해 주지 않으면 디폴트로 public으로 인식합니다. 
    // 접근 지정자는 객체지향의 중요한 특징인 캡슐화를 지원하는 역활을 합니다. 
    // public(공개적인) :  외부의 모든 곳에서 접근이 허용됩니다. 
    // protected(보호적인) : 이 클래스를 상속받는 자식 클래스에서만 접근이 가능합니다. 
    //                       그 외에는 접근이 불가능합니다. 
    // private(개인적인) : 클래스 내의 멤버 함수에서만 접근이 가능합니다. 

    // 테스트를 위해서 Date라는 이름의 클래스를 정의합니다. 
    // Date 타입의 today라는 이름의 객체를 정적할당으로 생성했습니다. 
    // 정적할당으로 생성된 객체에 접근하기 위해서는 .(Dot)로 접근합니다. 
    // C++ 에서 동적할당은 2가지가 있습니다. 
    // 1. new 연산자로 객체 생성을 합니다. 
    // 2. 스마트 포인터(unique_ptr, shared_ptr, weak_ptr)로 객체 생성을 합니다. 
    // 동적할당으로 생성된 객체에 접근하기 위해서는 ->(화살표 연산자)로 접근합니다. 
    Date today;
    today.m_Month = 8;
    today.m_Day = 28;
    // today.m_Year = 2021; // m_Year 멤버 변수는 private 접근지정자 안에 있기 때문에 접근이 
                         // 불가능합니다. 

    // 3. 접근 함수 Getter, Setter
    // private 멤버 변수들은 public한 접근 함수들을 만들어서 이를 통해 간접적으로 접근합니다. 
    // 테스트를 위해서 DateTime이라는 이름의 클래스를 정의해 주도록 합니다. 
    DateTime dateTime;
    // private 접근 지정자 공간에 있는 멤버 변수들에게 값을 주었습니다. 
    // 멤버 변수들은 private 공간에 두고 멤버 함수들은 public공간에 두어서 private 공간에 있는 
    // 멤버 변수들의 초기화 하거나 바꿔 줄 수가 있습니다. 
    dateTime.SetDate(2021, 8, 4);
    cout << "" << endl;
    // private  접근 지정자 공간에 있는 멤버 변수에게 값을 주었습니다. 
    dateTime.SetYear(2021);
    cout << "" << endl;

    // 캡슐화라는 것은 멤버 변수를 직접 변경할 수 없도록 캡슐처럼 껍데기를 둘러싸는 과정을 의미합니다. 
    // Parent1, Child1이라는 클래스를 정의해 주도록 합니다. 

    // Child1은 Parent1을 부모클래스로 상속받습니다. 이 때 멤버변수 a와 b는 직업 설정할 수 없게 private로 접근을 제한했습니다. 

    Child1 child1;
    // 메인 함수에서는 SetAB() 함수를 호출해서 a의 값을 100, b의 값을 200으로 바꾸려고 합니다. 
    // 그런데  Parent1클래스는 그것을 용납하지 않습니다. a의 최대값은 50으로, b의 최대값은 100으로 제한을 하였습니다. 
    // 요렇게 멤버의 값을 함부로 변경할 수 없도록 멤버 함수로 멤버 변수들에 껍질을 입히는 작업을 캡슐화 라고 합니다. 
    child1.SetAB(100, 200);
    child1.SetResult();
}
