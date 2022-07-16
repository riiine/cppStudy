#include <iostream>
// 문자열 관련 라이브러리
#include <string>

// C++ 표준 라이브러리
using namespace std;

// 테스트를 위해서 Parent1, Child1이라는 이름의 클래스를 정의해 주도록 합니다. 
class Parent1
{
private: // 개인적인
    // 객체지향 언어에서 멤버 변수는 private공간에 두어서 멤버 변수를 보호합니다. 캡슐화
    // 멤버 함수를 통해서면 멤버 변수에 접근할 수 있습니다. 
    // 다른 클래스에서는 멤버 변수에 직접적으로 접근이 불가능하게 멤버 변수를 보호하는 것입니다. 
    // 멤버 변수는 변수의 이름만 보더라도 멤버 변수인 것을 알 수 있도록 m, m_, _ 를 변수 이름앞에 붙어 줍니다. 

    // Parent1 클래스는 자신만이 접근이 가능한 멤버 변수 m_IntValue1, m_IntValue2, m_IntValue3를 가지고 있습니다. 
    // private 접근 지정자 안에 있기 때문에 자식 클래스에서 멤버 변수에 접근할 수가 없습니다. 
    int m_IntValue1;
    int m_IntValue2;
    int m_IntValue3;
public: // 공개적인
    // 생성자 함수는 public 접근 지정자 안에 둡니다. 
    Parent1() {} // 매개변수가 없는 디폴트 생성자 입니다. 
    // 생성자로 초기화 하는 방법은 2가지가 있습니다. 
    // 1. 일반적인 생성자를 사용해서 초기화 하는 방법입니다. 
    // 생성자를 이용해서 생성자 내부에서 클래스 멤버 변수들을 초기화 했습니다. 
    // m_IntValue1, m_IntValue2 멤버 변수들을 초기화 시켜 줍니다. 
    Parent1(int value1, int value2)
    {
        m_IntValue1 = value1;
        m_IntValue2 = value2;
    }

    // 2. 초기화 리스트(Member Initialization List)로 초기화 하는 방법입니다. 
    // : (콜론) 뒷부분이 초기화 리스트로 초기화를 하는 부분입니다. 
    // 생성전 초기화라고 합니다. 
    Parent1(int value1, int value2, int value3) : m_IntValue1(value1), m_IntValue2(value2), m_IntValue3(value3) {}
    // 누구나 접근 가능한(public 접근 지정자 안에 있습니다.)
    int Add()
    {
        return m_IntValue1 + m_IntValue2;
    }
protected: // 보호하는
};

class Child1 : public Parent1
{
public:
    // Child1 클래스는 Parent1 클래스를 부모 클래스(Super Class)로 상속을 받습니다. 
    // 이 때 부모클래스의 초기화를 하는 방법은 : 부모클래스명(매개변수명1, 매개변수명2, ...)으로 초기화를 할 수 있습니다.
    // Child1클래스는 Parent1 클래스를 상속 받았기 때문에 m_IntValue1, m_IntValue2 멤버 변수를 가지고 있지만 
    // 접근할 수 없습니다. 
    Child1(int value1, int value2) : Parent1(value1, value2) {}
};

// 테스트를 위해서 Parent2, Child2 라는 이름의 클래스를 정의해 주도록 합니다. 
class Parent2
{
public:
    Parent2()
    {
        cout << "Parent2 생성자" << endl;
    }

    ~Parent2()
    {
        cout << "Parent2 소멸자" << endl;
    }
};

class Child2 : public Parent2
{
public:
    Child2()
    {
        cout << "Child2 생성자" << endl;
    }

    ~Child2()
    {
        cout << "Child2 소멸자" << endl;
    }
};

/**
테스트를 위해서 Parent3, Child3라는 이름의 클래스를 정의해 주도록 합니다.

객체 지향 언어에서 멤버 변수는 무조건 private 접근 지정자 안에 둡니다.
테스트를 위해서 멤버 변수들을 protected, public 접근 지정자 안에 두었습니다.
멤버 변수를 private 접근 지정자 안에 두는 이유는 멤버 변수의 보호입니다.
*/
class Parent3
{
private:
    /**
    private 접근 지정자 안에 있기 때문에 자식 클래스에서 바로 접근이 안됩니다.
    다른 클래스에서는 멤버 함수를 통해서 접근이 가능합니다.
    */
    int m_IntValue1 = 10;
protected:
    /**
    protected 접근 지정자 안에 있기 때문에 부모 클래스를 상속받은 자식 클래스에서만 접근이 가능합니다.
    다른 클래스에서는 멤버 함수를 통해서 접근이 가능합니다.
    */
    int m_IntValue2 = 10;
public:
    /**
    public 접근 지정자 안에 있기 때문에 자식 클래스에서 뿐만이 아니고 모든 클래스에서 접근이 가능합니다.
    m_IntValue3 변수의 값은 최대로 가질수 있는 값이 100까지 입니다.
    */
    int m_IntValue3 = 10;
    /**
    디폴트 생성자 이니 디폴트 값으로 초기화 해 줍니다.
    */
    Parent3()
    {
        m_IntValue1 = 0;
        m_IntValue2 = 0;
        m_IntValue3 = 0;
    }

    void SetValue(int value)
    {
        if (value > 100)
        {
            value = 100;
        }

        m_IntValue3 = value;
    }

    /**
    멤버 변수 보호를 위해서 멤버 변수의 값을 리턴하는 함수에는 const를 붙여줍니다.
    멤버 변수를 보호할 필요가 없으면 멤버 변수의 값을 리턴하는 함수에는 굳이
    const를 붙여주지 않아도 됩니다.
    */

    /**
    const를 함수 뒤에 붙여 주면 함수를 실행하는 동안에는 멤버 변수의 값을 바꿀 없도록 보장합니다.
    */
    int GetValueA() const
    {
        // m_IntValue1 = 50; // (X)
        return m_IntValue1;
    }

    int GetValueB()
    {
        m_IntValue1 = 50;
        return m_IntValue1;
    }
};

class Child3 : public Parent3
{
public:
    void SetInfo()
    {
        /**
        private 접근 지정자 안에 있기 때문에 자식 클래스에서 바로 접근이 안됩니다.
        */
        // m_IntValue1 = 10; // error

        /**
        protected 접근 지정자 안에 있기 때문에 부모 클래스를 상속 받은 자식 클래스에서만 접근이 가능합니다.
        */
        m_IntValue2 = 10;
        /**
        public 접근 지정자 안에 있기 때문에 자식 클래스 뿐만이 아니고 모든 클래스에서 접근이 가능합니다.
        */
        m_IntValue3 = 10;
    }
};

/**
테스트를 위해서 Parent4, Child4 라는 이름의 클래스를 정의해 주도록 합니다.
*/
class Parent4
{
    /**
    접근 지정자가 없습니다.
    1. 클래스에서 접근 지정자가 없으면 디폴트로 private 접근 지정자로 설정됩니다.
    2. 구조체에서는 접근 지정자가 없으면 디폴트로 public  접근 지정자로 설정됩니다.
    */
    string m_Name;
    int m_Age;

    int GetAge() const
    {
        /**
        값을 반환하는 함수에 const 키워드를 붙여주면 함수가 실행되는 동안에는 멤버 변수의 값을 변경하지
        못한다는 것을 보장합니다. 일반적으로 멤버 변수를 반환하는 함수는 const 키워드를 붙여줍니다.
        */
        // m_Age = 29; // (X)
        /**
        멤버 변수의 값을 변경하지 못하지, 로컬 변수의 수정은 상관 없습니다.
        */
        string name = "Smith";
        return m_Age;
    }
};

class Child4 : public Parent4
{
    int m_ID;
public:
    void Print()
    {
        /**
        Parent4 클래스가 있고, Child4 클래스는 Parent4 클래스를 상속받았습니다.
        Child4 클래스에서 Print() 함수로 멤버 변수들을 호출하려면 에러가 발생합니다.
        왜냐하면 Parent4 클래스에 접근 지정자를 넣지 않아서 모든 변수가 private
        접근 지정자로 설정되기 때문입니다.

        GetAge() 함수도 접근 지정자 없이 함수가 정의 되었기 때문에 private 접근 지정자로 설정됩니다.
        */
        // GetAge(); // (X)
        /**
        부모 클래스에서 멤버변수를 접근 지정자 없이 선언했습니다.
        멤버 변수들은 디폴트로 private 접근 지정자로 설정됩니다.
        */
        // cout << m_Name << endl; // (X)
        // cout << m_Age << endl;  // (X)
        cout << m_ID << endl;
    }
};

/**
테스트를 위해서 Parent5, Child5 라는 이름의 클래스를 정의해 주도록 합니다.

우리가 추구해야 하는 프로그래밍의 패러다임은 가독성과 유지보수입니다.
가독성은 보기 좋은 코드이구요, 유지보수는 쉬운 수정입니다. 경험이 필요한 부분입니다.
경험 : experence  전문가 : expert  경험이 많은 사람을 전문가라고 합니다.
*/
class Parent5
{
protected:
    string m_Name;
    int m_Age;
public:
    int GetAge() const
    {
        return m_Age;
    }

    /**
    디폴트 생성자와 오버로딩된 생성자를 정의해 줍니다.
    디폴트 생성자는 굳이 정해주지 않아도 알아서 생성됩니다.
    */
    Parent5() {}
    /**
    : (콜론) 뒤는 초기화 리스트로 초기화를 하는 부분입니다.
    */
    Parent5(string name, int age) : m_Name(name), m_Age(age) {}
};

class Child5 : public Parent5
{
    int m_ID;
public:
    Child5()
    {
        m_Name = "";
        m_Age = 0;
        m_ID = 0;
    }

    Child5(string name, int age, int id) : Parent5(name, age), m_ID(id) {}

    void Print()
    {
        /**
        m_Name, m_Age 멤버 변수는 부모 클래스에서 protected 접근 지정자 안에 있기 때문에
        자식 클래스에서 접근이 가능합니다.
        부모클래스에서는 멤버 변수에 접근하기 위해서 public 지정자 안에 있는 GetAge() 라는 함수로 멤버 변수에 접근합니다.
        권장하는 방법입니다.

        protected 접근 지정자 안에 안에 있으면 자식 클래스에서 직접 접근이 가능합니다. 안정성 측면에서는 좋지 않은 방법입니다.
        */
        cout << "m_Name : " << m_Name << " ";
        cout << "m_Age : " << m_Age << " ";
        cout << "m_ID : " << m_ID << " ";
        cout << "" << endl;
    }
};

int main()
{
    // 객체 지향 언어의 4가지 특징
    // 1. 캡슐화 (접근 지정자 : private, protected, public)
    // 2. 상속
    // 3. 다형성 (함수 오버로딩, 함수 오버라이딩(함수 재정의))
    //    함수 오버라이딩 : 가상함수, 동적바인딩,    순수 가상함수, 추상 클래스
    // 4. 추상화

    // 프로그래밍 언어의 문법은 일부를 디테일하게 익히실 필요가 없습니다. 
    // 전체적으로(중요합니다.) 어느정도 익숙해 지셔야 합니다. 
    // 디테일한 부분은 구글검색하면 다 나옵니다. 
    // 검색을 하기 위해서넌 전체적으로 어느정도 익숙해 지는것이 중요합니다. 


    // 클래스와 구조체의 차이점
    // 구조체의 발전된 형태가 클래스입니다. 거의 비숫합니다. 
    // 둘 다 공통된, 연관된 것들을 묶어 놓은 틀이라는 점에서는 비숫하지만

    // 구조체 : 
    // 주로 데이터(멤버 변수)만 넣습니다. 
    // C++ 에서는 구조체에도 함수를 넣을수 있지만 C에서는 안됩니다. 
    // C++ 에서 구조체는 클래스와 기능적으로 동일합니다. 
    // 멤버 변수뿐 아니라 생성자와 소멸자를 비롯한 멤버 함수를 가질 수 있으며
    // 다른 구조체나 클래스를 상속 가능하고, 다른 구조체나 클래스를 상속 받을 수 있습니다. 
    // 멤버들은 접근 지정자로 지정되면 멤버 활용 방법 또한 클래스와 완전히 동일합니다. 
    // C++ 에서는 하나 틀린 점이 있는데, 접근 지정자를 지정하지 않으면 디폴트로 public입니다. 

    // 클래스 : 
    // 접근 지정자 private, protected, public으로 멤버 변수와 멤버 함수의 접근 가능정도를 설정할 수 있습니다. 
    // 데이터(멤버 변수), 기능(멤버 함수)를 가집니다.
    // C++ 에서는 하나 다른 점이 있는데, 접근 지정자를 지정하지 않으면 디폴트로 private입니다. 
    // C언어와의 호완성을 위해서 , 모든 멤버들이 공개절인 C 구조체를 C++에서 수용하기 위해서입니다. 


    // 상속(Inheritance)
    // 객체지향 언어(C#, Java, C++, Smalltalk)에서는 부모 클래스의 멤버 변수와 멤버 함수를 
    // 자식 클래스에서 재사용할 수가 있습니다.
    // 이 멤버 변수나 멤버 함수를 접근 제한자를 두어서 아무나 접근할 수 없도록 할 수 있습니다. (private, protected, public)
    // 상속하는 방법은 : (콜론)을 사용하셔 상속을 받을 수 있습니다. 

    // 다른 클래스의 멤버(데이터: 멤버 변수, 기능: 멤버 함수)를 인계해서 새로운 클래스를 정의하는 것입니다. 
    // 같은 특징있는 클래스를 그대로 물려받아 재사용 가능하기 때문에 효율성을 높일 수 있습니다. 
    // 자식 클래스에서는 부모 클래스로부터 상속받은 멤버 이외에 자신만의 새로운 멤버들을 추가해서 사용할 수가 있습니다. 
    // 상속의 가장 큰 장점은 부모 클래스의 멤버들을 자식 클래스에서 재사용 할 수 있습니다. 


    // 생성자(Constructor) :
    // 클래스가 객체를 생성할 때 항상 호출되는 멤버 함수입니다. 
    // 클래스가 메모리에 생성되면 객체(인스턴스, Instance)가 됩니다. 
    // 겍체를 생성할 때 다양하게 멤버 변수들의 초기화를 해 줍니다. 
    // 자신의 클래스 이름과 동일하지만 반환이 없는 함수가 생성자입니다. 
    // 생성자를 사용하려면 반드시 public으로 해야 합니다. 
    // public으로 해야 하는 이유는 모든 곳에서 접근이 가능해야 초기화를 하고 객체생성을 할 수 있기 때문입니다. 

    // 소멸자(Destructor) : 
    // 소멸자는 객체가 메모리에서 소멸(해제)할 때 최종작업을 기록하는 멤버 함수입니다. 
    // 소멸자는 반환값, 전달받는 매개변수가 없고,   ~클래스이름() 형태이어야 합니다. 
    // ~ : 틸드
    // 주로 delete연산자로 객체를 메모리에서 해제시켜 주는데, 소멸자에서 이런 작업들을 해 줍니다. 

    // 테스트를 위해서 Parent1, Child1이라는 이름의 클래스를 정의해 주도록 합니다. 

    // 변수는 선언합니다. 
    // 변수는 선언하고, 값을 대입해서 초기화 해 줍니다. 
    // 함수는 함수의 원형을 선언합니다. 
    // 함수는 함수의 원형을 구현(정의)해 줍니다. 
    // 클래스를 정의해 줍니다. 

    // 정적할당으로 객체를 생성했습니다. 
    // 정적할당으로 생성된 객체에 접근하기 위해슨 .(dot)으로 접근합니다. 
    Child1 child1(1, 2);
    // Add() 함수는 자식클래스에서 정의가 안되어 있지만 부모클래스에서 정의 되어 있기 때문에 
    // 자식클래스에서 사용이 가능합니다. 
    child1.Add();

    cout << "child1.Add() : " << child1.Add() << endl;

    cout << "" << endl;
    cout << "" << endl;

    // C++ 에서 동적할당으로 객체를 생성하는 방법은 2가지가 있습니다. 
    // 1. new 연산자를 이용해서 객체를 생성합니다. 
    // 2. unique_ptr, shared_ptr로 객체를 생성합니다. 
    // 동적할당으로 생성된 객체에 접근하기 위해서는 ->(화살표 연산자)를 사용합니다. 
    Child1* child1a = new Child1(1, 2);
    child1a->Add();

    cout << "child1a->Add() : " << child1a->Add() << endl;

    cout << "" << endl;
    cout << "" << endl;

    // 상속의 특징
    // 1. 자식 클래스의 생성자는 부모 클래스의 멤버 변수들까지 초기화를 해 주어야 합니다. 
    // 항상 부모 클래스의 생성자가 먼저 호출되고, 그 다음에 자식 클래스의 생성자가 호출됩니다. 
    // 2. 자식 클래스를 생성할 경우 부모 클래스의 생성자는 반드시 호출됩니다. 
    // 3. 소멸자의 호출 순서는 역순입니다. 
    // 자식이 먼저 소멸되고 그 후에 부모가 소멸됩니다. 

    // 테스트를 위해서 Parent2, Child2 라는 이름의 클래스를 정의해 주도록 합니다. 

    Child2 child2;

    cout << "" << endl;
    cout << "" << endl;

    // new 연산자로 객체 생성을 하면 delete 연산자로 메모리에서 객체을 해 주어야만 합니다. 
    // delete 연산자로 메모리 해제를 해주지 않으면 메모리 누수가 발생합니다. 
    Child2* child2a = new Child2();

    cout << "" << endl;
    cout << "" << endl;

    delete child2a;

    cout << "" << endl;
    cout << "" << endl;

    /**
    protected(보호된) : 부모클래스를 상속받는 자식클래스에서만 접근이 가능한 접근 지정자입니다.
    */

    /**
    테스트를 위해서 Parent3, Child3라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /**
    m_IntValue3 멤버 변수의 값은 최대로 가질수 있는 값이 100까지 입니다.
    */
    Parent3 parent3;
    // 변수가 가질 수 있는 최대값은 100인데, 그 이상의 값도 가질수가 있습니다. 
    // 변수만 선언하고 초기화를 안해 주었기 때문에 쓰레기 값이 들어갑니다. 
    // int 타입은 -2147483648 ~ 2147483747
    // parent3.m_IntValue3 = 1000000000000000000; // 값이 오버하니 쓰레기 값으로 채워집니다. 
    parent3.m_IntValue3 = 2048;
    /**
    멤버 변수의 값 보호를 위해서 멤버 변수는 private 접근 지정자 안에 두고
    멤버 함수를 통해서 관리를 합니다. 함수를 정의해 주도록 합니다.
    */
    cout << "parent3.m_IntValue3 : " << parent3.m_IntValue3 << endl;

    cout << "캡슐화, 변수을 값을 제한하기 위해서 SetValue() 함수를 호출합니다. " << endl;
    parent3.SetValue(parent3.m_IntValue3);
    cout << "parent3.m_IntValue3 : " << parent3.m_IntValue3 << endl;

    cout << "" << endl;

    Child3 child3;
    // hild3.m_IntValue1 = 10; // Error
    // child3.m_IntValue2 = 10; // Error
    child3.m_IntValue3 = 10;

    cout << "" << endl;
    cout << "" << endl;

    /**
    테스트를 위해서 Parent4, Child4 라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /**
    테스트를 위해서 Parent5, Child5 라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /**
    정적 할당으로 객체를 생성했습니다.
    */
    Child5 child5;
    child5.Print();

    cout << "" << endl;
    cout << "" << endl;

    /**
    생성자로 객체를 생성 했습니다.
    */
    Child5 child6("John", 22, 99);
    child6.Print();

    cout << "GetAge() : " << child6.GetAge() << endl;

    cout << "" << endl;
    cout << "" << endl;





} // main() 함수의 끝입니다. 함수를 벗어나므로 생성되었던 객체들은 소멸합니다. 

