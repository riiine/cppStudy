/** cout을 사용하기 위한*/
#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>


/** C++ 표준 라이브러리*/
using namespace std;

/** 정적변수가 없는 함수를 정의합니다. */
void IncreaseValue()
{
    /** 
    기본적으로 '자동 생명 주기(auto duration)' 입니다. 
    함수를 빠져 나가면 멤버 변수 value는 소멸 됩니다. 
    */
    int value = 0; 
    /** value 변수의 값을 1 증가시킵니다. */
    value++; 
    
    cout << "value : " << value << endl;
} /** value는 여기서 소멸됩니다.*/

/** 정적변수가 있는 함수를 정의 합니다. */
void IncreaseValueWithStatic()
{
    /** 
    'static' 키워드를 사용한 '정적 생명 주기(static duration)', 이 줄은 한번만 실행됩니다.
    함수를 빠져 나가도 정적 멤버 변수인 s_intValue1는 소멸되지 않습니다. 
    */
    static int s_intValue1 = 0;  

    s_intValue1++;

    cout << "s_intValue1 : " << s_intValue1 << endl;

} /** staticValue는 여기서 소멸되지 않지만, 함수 안에 있기 때문에 접근할 수 없게됩니다.*/

/** 함수 외부에서 정의된 변수는 전역 변수(global variable)입니다.*/
int g_IntValue1;

/** 함수 외부에서 정의된 변수는 전역 변수(global variable)입니다.*/
int intValue2 = 10;

/** 테스트를 위해서 StaticMemberVariable이라는 이름의 클래스를 정의해 주도록 합니다. */
class StaticMemberVariable
{
public:
    /**
    정적 멤버 변수 선언

    static 멤버 변수를 클래스 내에서 초기화 하면 객체를 생성할 때마다 static멤버 변수 값이 계속 해서 
    덮어 씌워질 것입니다. 왜냐하면 모든 객체들이 이 멤버를 공유하기 때문입니다.
    static멤버 변수는 클래스 내에서 선언만 가능하고 정의는 불가능합니다. 
    static멤버 변수는 모든 객체들이 접근해야 하므로 프로그램 시작부터 끝까지 유지되어야 하기 때문에 
    전역 범위 에서만 정의(초기화)할 수 있습니다.

    따라서 static 멤버 변수는 main 함수는 물론이고 생성자 안에서도 초기화 할 수 없습니다.
    생성자도 static여야 static 멤버 변수를 초기화시킬 수 있는데 C++에서는 static 생성자를 지원하지 않습니다.
    */
    static int m_value; 
    // static int m_value = 1; // (X)
};
 
/**
전역 범위에서 초기화
static 멤버 변수는 모든 객체가 공유해야 하므로 프로그램 전체 영역에서 메모리 유지가 되어야 합니다. 
따라서 반드시 전역 범위에서 정의 및 초기화를 해주어야 합니다.
*/
int StaticMemberVariable::m_value = 1;

/** 테스트를 위해서 StaticMemberFunction라는 이름의 클래스를 정의해 주도록 합니다.  */
class StaticMemberFunction
{
private:
    /** 일반 멤버 변수*/
    int noramal_value = 99;  
    /** static 멤버 변수*/
    static int static_value; 

public:
    /** static 멤버 함수*/
    static void StaticFunction()     
    {
        /** StaticFunction() 함수내의 일반 지역 변수 */
        int intValue1 = 1024;      
        cout << "intValue1 : " << intValue1 << endl;
        
        cout << "" << endl;
        cout << "" << endl;
        /** 일반 멤버 변수는 사용할 수 없습니다.*/
        // cout << "noramal_value: " << noramal_value << endl; 
        /** static 멤버 변수는 사용 가능합니다.*/
        cout << "static_value : " << static_value << endl; 

        cout << "" << endl;
        cout << "" << endl;
    }
};

/** static 멤버 변수인 static_value의 초기화는 전역 공간에서 해 줍니다. */
int StaticMemberFunction::static_value = 2048;

/** 테스트를 위해서 StaticClass1이라는 이름의 클래스를 정의해 주도록 합니다. */
class StaticClass1
{
private:
    /** private한 static 멤버 변수*/
    static int static_value;

public:
    /** 
    static 멤버 함수입니다. 
    다른 클래스에서 private인 static 멤버 변수에 접근이 안되니 함수를 통해서 접근합니다.
    */
    static int GetValue() 
    {
        /** static 멤버 변수인 static_value의 값을 반환하고 함수를 빠져나갑니다. */
        return static_value;
    }
};

/** static 멤버 변수인 static_value의 초기화는 전역 공간에서 해 줍니다. */
int StaticClass1::static_value = 512;

/** 테스트를 위해서 StaticClass2이라는 이름의 클래스를 정의해 주도록 합니다. */
class StaticClass2
{
private:
    /** static 멤버 변수*/
    static int static_value; 

public:
    /** static 멤버 함수*/
    static int GetValue()     
    {
        /** static 멤버 함수인 GetValue()에선 this를 사용할 수 없습니다.*/
        // return this->static_value;   
    }
    /** 일반 멤버 함수*/
    int NormalGetValue() 
    {
        /** 일반 멤버 함수인 NormalGetValue()에선 this를 사용할 수 있습니다.*/
        return this->static_value; 
    }
};

int main()
{
    /**
    변수의 종류
    1. 정적 변수
    2. 전역 변수
    3. 정적 멤머 변수
    4. 멤버 변수
    5. 로컬 변수
    6. 매개 변수
    */

    /**
    정적변수 : static
        static 키워드는 블록 내에서 선언된 지역 변수에서도 사용할 수 있습니다. 
        지역 변수는 '자동 주기(auto duration)'를 가지며, 정의되는 시점에서 생성되고 
        초기화되며, 정의된 블록이 끝나는 지점에서 소멸한다. 
        하지만 static 키워드를 사용한 지역 변수는 완전히 다른 의미가 있습니다. 
        static 키워드를 사용한 지역 변수는 '자동 주기(auto duration)'에서 
        '정적 주기(static duration)'로 바뀝니다. 
        이것을 정적 변수(static variable)라고도 부르는데, 생성된 스코프(범위)가 종료한 이후에도 
        해당 값을 유지하는 변수입니다. 
        또한, 정적 변수는 한 번만 초기화되며 프로그램 수명 내내 지속됩니다.
    */

    /** IncreaseValue라는 이름의 정적변수가 없는 함수를 정의해 줍니다. */

    /**
    함수가 호출되면 값이 계속 초기화 되어서 결과값이 동일합니다. 
    IncreaseValue() 함수를 호출할 때마다 value 변수가 생성되고 값 0이 할당됩니다. 
    그 다음 IncreaseValue() 함수는 값을 1로 증가시킨 value 변수값 1을 출력합니다. 
    IncreaseValue() 함수의 실행이 완료되면 value 변수는 스코프(범위)를 벗어나 소멸합니다.
    */
    IncreaseValue();
    IncreaseValue();
    IncreaseValue();
    IncreaseValue();
    IncreaseValue();

    cout << "" << endl;

    /** IncreaseValueWithStatic이라는 이름의 정적변수가 있는 함수를 정의해 줍니다.  */

    /**
    staticValue는 static으로 선언되었기 때문에 staticValue는 한 번만 생성되고 0으로 초기화됩니다. 
    스코프(범위)를 벗어나면 소멸하지 않습니다. 
    IncreaseValueWithStatic() 함수가 호출될 때마다 staticValue 값은 이전에 남겨둔 값입니다.
    하지만 함수 안에서 선언되었기 때문에 접근이 불가능 합니다. 
    */
    IncreaseValueWithStatic();
    IncreaseValueWithStatic();
    IncreaseValueWithStatic();
    IncreaseValueWithStatic();
    IncreaseValueWithStatic();

    /** g_IntValue1라는 이름의 전역변수를 선언해 줍니다. */
    
    /** 전역 변수가 정의된 이후, 프로그램 어디에서든지 접근 가능합니다. */
    cout << "" << endl;

    g_IntValue1 = 5;
    cout << "g_IntValue1 : " << g_IntValue1 << endl;
    cout << "" << endl;

    /**
    전역 변수와 같은 이름을 가진 지역 변수는 전역 변수를 숨깁니다. 
    그러나 전역 범위 연산자(::)를 사용하면 컴파일러는 지역 변수 대신 전역 변수를 사용합니다.
    전역변수를 선언해 주고 테스트를 해 줍니다. 
    그러나 전역 변수와 같은 이름의 지역 변수를 선언하는 것은 피해야 합니다.
    관습에 따라 일반적으로 전역 변수를 정의할 때는 g_ 접두사를 붙입니다. 
    이 방법은 전역 변수를 식별하는데 편리할 뿐만 아니라 지역 변수와 충돌을 방지하는 데 도움이 됩니다.
    */

    /** intValue2라는 이름의 전역변수를 선언해 줍니다. */

    /** 전역 변수를 숨깁니다.*/
    int intValue2 = 5; 
    /** 지역 변수의 값을 증가시킵니다. */
    intValue2++; 
    /** 전역 변수의 값을 감소시킵니다. */
    ::intValue2--; 

    cout << "global intValue2: " << ::intValue2 << endl;
    cout << "local intValue2: " << intValue2 << endl;
    cout << "" << endl;

    /**
    static 멤버 변수

    모든 객체가 한 메모리를 공유하는 멤버 변수입니다. 
    객체 별로 각각 할당되는 멤버가 아니라 모든 객체가 공유하는 멤버 변수입니다.
    메모리는 프로그램 시작때부터 차지하고 있으며 메모리에 내내 값이 유지됩니다.
    객체 생성 전에도 메모리 존재합니다. 따라서 객체 생성 전에 반드시 미리 초기화를 해주어야 합니다.
    객체와는 독립적으로 존재합니다.
    객체 이름으로도 접근이 가능하지만 클래스 이름으로도 접근이 가능합니다. 
    int Something::s_value = 1;
    s_value가 static멤버 변수라면 객체1의 s_value 와 객체2의 &s_value 는 주소가 동일합니다.
    어떤 특정 타입의 모든 객체들의 수 라던지 모든 객체들이 알고 있고 공유할 수 있어야 하는 멤버 변수를 static으로 씁니다.    
    */

    /** 테스트를 위해서 StaticMemberVariable이라는 이름의 클래스를 정의해 주도록 합니다. */


    /** 에러!!! 전역 범위에서만 가능. 지역범위에서 변수를 선언하려고 하니 에러가 납니다. */
    // int StaticMemberVariable::m_value = 1; 

    /** 객체 생성 전에도 사용 가능*/
    cout << "value : " << StaticMemberVariable::m_value << ", address : " << &StaticMemberVariable::m_value << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 객체 생성을 해 줍니다.*/
    StaticMemberVariable st1;
    StaticMemberVariable st2;

    st1.m_value = 512;

    cout << "st1 value : " << st1.m_value << ", st1 address : " << &st1.m_value << endl;
    cout << "st2 value : " << st2.m_value << ", st2 address : " << &st2.m_value << endl;

    cout << "" << endl;
    cout << "" << endl;

    st2.m_value = 1024;

    /**
    &st1.m_value, &st2.m_value, &StaticMemberVariable::m_value 전부 주소가 동일합니다. 
    따라서 st1.m_value 값을 바꾸면 st2.m_value, StaticMemberVariable::m_value 값들도 동시에 똑같이 바뀝니다. 
    모든 객체는 static변수의 메모리를 공유하기 때문입니다. 
    */
    cout << "st1 value : " << st1.m_value << ", st1 address : " << &st1.m_value << endl;
    cout << "st2 value : " << st2.m_value << ", st2 address : " << &st2.m_value << endl;
    cout << "m_value : " << StaticMemberVariable::m_value << ", m_value address : " << &StaticMemberVariable::m_value << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    static 멤버 함수란?

    staitc 멤버 변수처럼 객체 이름은 물론이고 클래스 이름만으로도 접근이 가능합니다.
    객체와 독립적입니다. 따라서 객체 생성과 상관 없습니다.
    일반적으로 멤버 변수는 객체가 생성되야 메모리를 할당받기 때문에 
    static 멤버 함수 내에서는 멤버 변수를 사용할 수 없습니다.
    그러나 미리 전역에서 메모리가 할당되는 static 멤버 변수는 사용이 가능합니다.
    */

    /** 테스트를 위해서 StaticMemberFunction라는 이름의 클래스를 정의해 주도록 합니다.  */

    /** 객체 생성 없이 바로 클래스 이름으로 호출 가능*/
    StaticMemberFunction::StaticFunction(); 

    /**
    static 멤버 함수를 사용하는 이유

    객체 생성 여부와 상관없이 바로 클래스 이름으로 접근하고 싶을 때 사용하지만 
    주로 private인 static 멤버 변수에 접근하려 할 때 많이 쓰입니다.

    staitc 멤버 변수는 모든 객체들이 사용하고 공유해야하는데 
    private이라면 외부에서 직접 접근하고 사용할 수가 없습니다.
    private인 멤버 변수들은 멤버 함수들에서만 접근이 가능하다는 특징이 있습니다.
    static 멤버 함수 를 통해서 private한 staitc 멤버 변수 에 간접 접근할 수 있도록 구현할 수 있습니다.
    */

    /** 테스트를 위해서 StaticClass1이라는 이름의 클래스를 정의해 주도록 합니다. */

    /** private이므로 직접 접근 불가능*/
    // cout << "StaticClass1::static_value : " << StaticClass1::static_value << endl; 

    /**
    이처럼 private한 staitc 멤버 변수를 직접 접근할 수는 없지만 
    static 멤버 함수 GetValue()를 통하여 간접적으로 staitc 멤버 변수를 리턴받을 수 있습니다.
    */

    /** 클래스 이름으로 GetValue() 함수를 호출할 수 있습니다.  */
    cout << "StaticClass1::getValue() : " << StaticClass1::GetValue() << endl;   
    cout << "" << endl;

    StaticClass1 staticClass1;
    /** 객체 이름으로 GetValue() 함수를 호출할 수 있습니다. */
    cout << "StaticClass1.getValue() : " << staticClass1.GetValue() << endl;  
    cout << "" << endl;

    /**
    static 멤버 함수는 this 포인터를 사용할 수 없습니다.

    this 포인터는 객체인 자기 자신의 주소, 
    즉 객체의 주소를 담고 있기 때문에 객체가 생성되야지만 사용할 수 있습니다.

    static 멤버 함수는 객체들의 생성과 무관하며 언제 어디서든 클래스 이름으로도 접근이 가능해야 하기 때문에
    static 멤버 함수 내부에서는 this 포인터를 사용할 수 없습니다.
    static 멤버 함수 내부에서 일반 멤버 변수를 사용할 수 없었듯이 this포인터로 
        접근할 수 있는 모든 것을 하지 못 합니다.

    같은 객체 내의 멤버 변수나 멤버 함수는 접근하지 못합니다. 
    눈에 보이지 않아도 이들을 접근할 땐 this->가 숨어있는 것이나 마찬가지기 때문입니다
    */

    /** 테스트를 위해서 StaticClass2이라는 이름의 클래스를 정의해 주도록 합니다. */
}
