#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 테스트를 위해서 Parent1, Child1이라는 이름의 클래스를 정의해줍니다. */
class Parent1
{
private: // 개인적인
    /**
    객체 지향 언어에서 멤버 변수는 private 접근 지정자 안에 두어서 멤버 변수를 보호합니다. 캡슐화
    멤버 함수를 통해서만 멤버 변수에 접근할 수 있습니다.
    자식 클래스에서 조차도 부모 클래스의 private 접근 지정자 안에 있는 멤버 변수에 접근이 안 됩니다.
    다른 클래스에서는 멤버 변수에 직접적으로 접근이 불가능하게 해서 멤버 변수를 보호하는 것입니다.
    멤버 변수는 변수의 이름만 보더라도 멤버 변수인 것을 알 수 있도록 m, m_, _를 변수 이름 앞에 붙여줍니다.
    */

    /**
    Parent1클래스는 자식도 아닌 자신만이 접근이 가능한 멤버 변수
    m_IntValue1, m_IntValue2, m_IntValue3을 가지고 있습니다.
    private 접근 지정자 안에 있기 때문에 자식 클래스에서도 멤버 변수에 접근할 수가 없습니다.
    */
    int m_IntValue1;
    int m_IntValue2;
    int m_IntValue3;
public: // 공개적인
    /**
    Parent1이라는 이름의 생성자 함수를 정의합니다.
    Parent1이라는 이름의 생성자 함수의 원형을 선언합니다. // (X) 이미 함수의 본체가 있기 때문입니다.
    매개 변수가 없는 디폴트 생성자입니다.
    */
    Parent1() {}

    /**
    생성자로 초기화를 하는 방법은 2가지가 있습니다.
    1. 일반적인 생성자를 사용해서 초기화를 하는 방법입니다.
    생성자를 사용해서 생성자 내부에서 클래스 멤버 변수들을 초기화 합니다.
    m_IntValue1, m_IntValue2 멤버 변수들을 초기화 합니다.
    */
    Parent1(int value1, int value2)
    {
        m_IntValue1 = value1;
        m_IntValue2 = value2;
    }

    /**
    2. 초기화 리스트(Member Initialization List)로 초기화하는 방법입니다.
    : (콜론) 뒷부분이 초기화 리스트로 초기화를 하는 부분입니다.
    생성자 초기화라고 합니다.
    */
    Parent1(int value1, int value2, int value3) : m_IntValue1(value1), m_IntValue2(value2), m_IntValue3(value3) {}

    int Add()
    {
        return m_IntValue1 + m_IntValue2;
    }
};

class Child1 : public Parent1
{
public:
    /**
    Child1클래스는 Parent1 클래스를 부모 클래스(Parent class, Super class)로 상속을 받습니다. 
    이 때 부모 클래스의 초기화 방법은 부모클래스명(매개변수명1, 매개변수명2, ...)으로 초기화가 가능합니다.
    Child1클래스는 Parent1클래스를 상속받았기 때문에 부모 클래스의 private 접근지정자 안에 있는
    m_IntValue1, m_IntValue2, m_IntValue3 멤버 변수를 가질 수는 있지만 접근할 수 없습니다.
    */
    Child1(int value1, int value2) : Parent1(value1, value2) {}
};

/** 테스트를 위해서 Parent2, Child2라는 이름의 클래스를 정의해 주도록 합니다. */
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
protected(보호된) : 부모 클래스를 상속받는 자식 클래스에서만 접근이 가능한 접근 지정자입니다.
테스트를 위해서 Parent3, Child3라는 이름의 클래스를 정의해줍니다.

객체 지향 언어에서 멤버 변수는 무조건 private 접근 지정자 안에 둡니다.
테스트를 위해서 멤버 변수들을 protected, public 접근 지정자 안에 둡니다.
멤버 변수를 private 접근 지정자 안에 두는 이유는 멤버 변수의 보호입니다.
*/
class Parent3
{
private:
    /**
    private 접근 지정자 안에 있기 때문에 자식 클래스에서 바로 접근이 안됩니다.
    자식클래스를 포함한 다른 클래스에서는 멤버 함수를 통해서 접근이 가능합니다.
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
    public 접근 지정자 안에 있기 때문에 자식 클래스를 포함한 모든 클래스에서 접근이 가능합니다.
    직접적으로 변수에 접근할 때는 어떤 값도 넣을 수 있습니다.
    함수를 통해서 m_IntValue3변수의 값이 최대로 가질 수 있는 값을 100으로 할 예정입니다.
    */
    int m_IntValue3 = 10;

    /** 디폴트 생성자이니 디폴트 값으로 초기화를 해줍니다. */
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

    /** const를 함수 끝에 붙여주면 함수를 실행하는 동안에는 멤버 변수의 값을 바꿀 수 없도록 보장합니다. */
    int GetValueA() const
    {
        //m_IntValue1 = 50; // (X)
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
        /** private 접근 지정자 안에 있기 때문에 자식 클래스에서 바로 접근이 안 됩니다. */
        //m_IntValue1 = 10; // (X)

        /** protected 접근 지정자 안에 있기 때문에 부모 클래스를 상속받은 자식 클래스에서만 접근이 가능합니다. */
        m_IntValue2 = 10;

        /** public 접근 지정자 안에 있기 때문에 자식 클래스를 포함한 모든 클래스에서 접근이 가능합니다. */
        m_IntValue3 = 10;
    }
};

/** 테스트를 위해서 Parent4, Child4 클래스를 정의해 주도록 합니다. */
class Parent4
{
    /**
    접근 지정자가 없습니다.
    1. 클래스에서 접근 지정자가 없으면 디폴트로 private 로 설정됩니다.
    2. 구조체에서는 접근 지정자가 없으면 디폴트로 public으로 설정됩니다.
    */
    string m_Name;
    string m_Age;

    int GetAge() const
    {
        /**
        값을 반환하는 함수에 const키워드를 붙여주면 함수가 실행되는 동안에는 멤버 변수의 값을 변경하지
        못한다는 것을 보장합니다. 일반적으로 멤버 변수를 반환하는 함수는 const키워드를 붙여 줍니다.
        */
        // m_Age = 29; // (X)
        /** 멤버 변수의 값을 변경하지 못하지, 로컬 변수의 수정은 상관이 없습니다. */
        string name = "Smith";
    }
};

class Child4 : public Parent4
{
    int m_ID;

public:
    void Print()
    {
        /**
        Parent4 클래스에 접근 지정자를 넣지 않아서 모든 변수 및 함수가
        private 접근 지정자로 설정되었습니다.
        */
        //GetAge(); // (X)
    
        /**
        부모 클래스에서 멤버 변수를 접근 지정자 없이 선언했습니다.
        멤버 변수들은 디폴트로 private 접근 지정자로 설정됩니다.
        */
        //cout << "m_Name : " << m_Name << endl; // (X)
        //cout << "m_Age : " << m_Age << endl; // (X)
        cout << "m_ID : " << m_ID << endl;
    }
};

/** 테스트를 위해서 Parent5, Child5 클래스를 정의해 주도록 합니다. */
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

    /** 디폴트 생성자는 굳이 정의해 주지 않아도 자동으로 생성됩니다. */
    Parent5()
    {

    }
    /** : (콜론) 뒤는 초기화 리스트로 초기화를 하는 부분입니다. */
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
        protected 접근 지정자 안에 있으면 자식 클래스에서 직접 접근이 가능합니다.
        하지만 안정성 측면에서는 좋지 않은 방법입니다.
        */
        cout << "m_Name : " << m_Name << endl;
        cout << "m_Age : " << m_Age << endl;
        cout << "m_ID : " << m_ID << endl;
    }
};

int main()
{
    /**
    객체 지향 언어의 4가지 특징
    1. 캡슐화 : 접근 지정자(private, protected, public)
    2. 상속
    3. 다형성 : 연산자 오버로딩, 함수 오버로딩, 함수 오버라이딩(함수 재정의)
                                                함수 오버라이딩 : 가상 함수와 동적 바인딩
    4. 추상화 : 순수 가상함수와 추상클래스
    */

    /**
    구조체
    주로 데이터(멤버 변수)만 넣습니다.
    C++에서는 구조체에 함수를 넣을 수 있지만 C에서는 안 됩니다.
    C++에서 구조체는 클래스와 기능적으로 동일합니다.
    멤버 변수 뿐만 아니라 생성자와 소멸자를 비롯한 멤버 함수를 가질 수 있으며
    다른 구조체나 클래스를 상속 가능하고, 다른 클래스나 구조체를 상속받을 수 있습니다.
    멤버들은 접근 지정자로 지정되며 멤버 활용 방법 또한 클래스와 동일합니다.
    하나 틀린 점은 접근 지정자를 지정하지 않으면 디폴트로 public입니다.
    
    C언어와의 호환성을 위해서, 모든 멤버들이 공개적인 C언어의 구조체를 C++에서 수용하기 위함입니다.
    */

    /**
    클래스
    접근 지정자 private, protected, public으로 멤버 변수와 멤버 함수의 접근 가능 정도를
    설정할 수 있습니다.
    데이터(멤버 변수), 기능(멤버 함수를 가집니다. )
    하나 틀린 점은 접근 지정자를 지정하지 않으면 디폴트로 private입니다.
    */

    /**
    상속(Inheritance)
    객체 지향 언어에서는 부모 클래스의 멤버 변수와 멤버 함수를 자식 클래스에서
    재사용이 가능합니다.
    멤버 변수나 멤버 함수를 접근 제한자를 두어서 아무나 접근할 수 없도록 할 수 있습니다.
    상속하는 방법은 : (콜론)을 사용합니다.

    다른 클래스의 데이터(멤버 변수), 기능(멤버 함수)을 인계해서 새로운 클래스를 정의하는 것입니다.
    자식 클래스에서는 부모 클래스로부터 상속받은 멤버 이외에 자신만의 새로운 멤버들을 추가해서 사용이 가능합니다.

    한가지 단점은 상속을 많이 하게 되면 코드 분석이 어렵게 됩니다.
    */

    /**
    생성자(Constructor)
    클래스가 객체를 생성할 때 호출되는 멤버 함수입니다.
    클래스가 메모리에 생성되면 객체(인스턴스, instance)가 됩니다.
    객체를 생성할 때 다양하게 멤버 변수들의 초기화를 해 줍니다.
    자신의 클래스 이름과 동일하지만 반환이 없는 함수입니다.
    생성자를 사용하려면 반드시 public으로 해야 합니다.
    public으로 하는 이유는 모든 곳에서 접근이 가능해야 초기화를 하고 객체를 생성할 수 있기 때문입니다.
    */

    /**
    소멸자(Destructor)
    소멸자는 객체가 메모리에서 해제될 때 할 일들을 기록하는 멤버 함수입니다.
    당연히 반환값, 전달받는 매개 변수 없습니다. ~클래스이름() 의 형태이어야 합니다.
    ~ : 틸드
    delete 연산자로 객체를 메모리에서 해제시켜 주어야 하는데, 소멸자에서 이런 작업들을 하게 됩니다.
    */

    /** 테스트를 위해서 Parent1, Child1이라는 이름의 클래스를 정의해줍니다. */

    /** 문장을 추가해줍니다. */
    
    /**
    정적 할당으로 객체를 생성했습니다.
    정적 할당으로 생성된 객체에 접근하기 위해서는 .(Dot)으로 접근합니다.
    */
    Child1 child1(1, 2);
    /**
    Add() 함수는 자식 클래스에서 정의가 되어있지 않지만 부모 클래스에서 정의되어 있기 때문에
    자식 클래스에서 사용이 가능합니다.
    */
    child1.Add();

    cout << "child1.Add() : " << child1.Add() << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    C++에서 동적 할당으로 객체 생성을 하는 방법은 2가지가 있습니다.
    1. new 연산자를 이용해서 객체를 생성합니다.
    2. unique_ptr, shared_ptr로 객체 생성을 합니다.
    동적 할당으로 생성된 객체에 접근하기 위해서는 ->(화살표 연산자)를 사용합니다.
    */
    Child1* child1a = new Child1(1, 2);
    child1a->Add();

    cout << "child1a->Add() : " << child1a->Add() << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    상속의 특징
    1. 자식 클래스의 생성자는 부모 클래스의 멤버 변수들까지 초기화를 해주어야 합니다.
    항상 부모 클래스의 생성자가 먼저 호출되고, 그 다음에 자식 클래스의 생성자가 호출됩니다.
    2. 자식 클래스를 생성할 경우 부모 클래스의 생성자는 반드시 호출됩니다.
    3. 소멸자의 호출 순서는 역순입니다.
    자식이 먼저 소멸되고, 그 후에 부모가 소멸됩니다.
    */

    /** 테스트를 위해서 Parent2, Child2라는 이름의 클래스를 정의해 주도록 합니다. */

    /** 문장을 추가해줍니다. */
    Child2 child2;

    cout << "" << endl;
    cout << "" << endl;

    Child2* child2a = new Child2();

    cout << "" << endl;
    cout << "" << endl;

    delete child2a;

    cout << "" << endl;
    cout << "" << endl;

    /**
    protected(보호된) : 부모 클래스를 상속받는 자식 클래스에서만 접근이 가능한 접근 지정자입니다.
    테스트를 위해서 Parent3, Child3라는 이름의 클래스를 정의해줍니다.
    */

    /** 문장을 추가해줍니다. */

    /** 함수를 통해서 m_IntValue3 멤버 변수의 값은 최대로 가질 수 있는 값은 100까지 입니다. */
    Parent3 parent3;
    /**
    변수가 가질 수 있는 최대값은 10인데, 그 이상의 값도 가질 수 있습니다.
    int 타입은 -2147483648 ~ 2147483647 범위입니다.
    parent3.m_IntValue3 = 1000000000000;    값을 오버하니 쓰레기 값으로 채워집니다.
    */
    parent3.m_IntValue3 = 1000000000000;
    cout << "parent3.m_IntValue3 : " << parent3.m_IntValue3 << endl;

    cout << "" << endl;
    cout << "" << endl;

    parent3.m_IntValue3 = 2048;
    cout << "parent3.m_IntValue3 : " << parent3.m_IntValue3 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    멤버 변수의 값 보호를 위해서 멤버 변수는 private 접근 지정자 안에 두고
    멤버 함수를 통해서 멤버 변수에 접근합니다.
    */

    cout << "캡슐화, 변수의 값을 제한하기 위해서 SetValue() 함수를 호출합니다. " << endl;
    parent3.SetValue(parent3.m_IntValue3);
    cout << "parent3.SetValue(parent3.m_IntValue3); : " << parent3.m_IntValue3 << endl;

    cout << "" << endl;
    cout << "" << endl;

    Child3 child3;
    //child3.m_IntValue1 = 10; // (X)
    /** Child3 클래스 안에서는 접근이 가능하지만 밖에서는 접근이 불가능합니다. */
    //child3.m_IntValue2 = 20; // (X)
    child3.m_IntValue3 = 30;

    /** 테스트를 위해서 Parent4, Child4 클래스를 정의해주도록 합니다. */

    /** 테스트를 위해서 Parent5, Child5 클래스를 정의해주도록 합니다. */
}

