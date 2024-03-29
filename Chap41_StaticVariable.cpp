﻿#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 스마트 포인터 관련 라이브러리*/
#include <memory>
/** 벡터 컨테이너 관련 라이브러리*/
#include <vector>
/** 리스트 컨테이너 관련 라이브러리*/
#include <list>
/** 배열의 사이즈를 얻어오기 위한 라이브러리*/
#include <array>
/** 랜덤 라이브러리*/
#include <time.h>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 테스트를 위해서 정적변수가 없는 IncreaseValue() 라는 이름의 함수를 정의해 줍니다. */
void IncreaseValue()
{
    /** 스태틱 변수가 아니라 일반 로컬변수입니다. 자동 생명 주기(auto duration)입니다. */
    int value = 0;
    /** value변수의 값을 1 증가시킵니다. */
    value++;

    cout << "value : " << value << endl;
} /** value라는 일반 로컬변수는 블록을 벗어나면 소멸됩니다. */

/** 테스트를 위해서 정적 변수가 있는 IncreaseValueWithStatic이라는 이름의 함수를 정의해 줍니다. */
void IncreseValueWithStatic()
{
    /**
    static 키워드를 사용한 정적 생멸 주기(static duration)입니다. 한번만 실행됩니다.
    변수 이름만 보더라도 정적변수인 것을 알 수 있도록 s_접두사를 붙여 줍니다.
    */
    static int s_intValue1 = 0;

    s_intValue1++;

    cout << "s_intValue1 : " << s_intValue1 << endl;
} /** s_intValue1은 정적 생명 주기입니다. 블록을 지나도 소멸되지 않습니다.  */

/**
테스트를 위해서 g_IntValue1이라는 이름의 전역 변수를 선언해 줍니다.
전역변수가 선언된 이후에 프로그램 어디에서든지 접근이 가능합니다.

함수 외부에서 선언된 변수는 전역변수(global variable)입니다.
변수 이름만 보더라도 전역변수인 것을 알 수 있도록 g_접두사를 붙여 줍니다.
*/
int g_IntValue1;

/**
전역변수와 로컬변수의 이름이 같을 경우 무슨일이 일어날까요?
테스트를 위해서 intValue2라는 이름의 전역변수를 선언해 줍니다.
*/
int intValue2 = 10;

/** 테스트를 위해서 Something이라는 이름의 클래스를 정의해 줍니다. */
class Something
{
public:
    /**
    멤버 변수는 변수이름만 보더라도 멤버 변수인 것을 알 수 있도록
    m_, m, _ 접두사를 붙여 줍니다.
    */

    /**
    클래스 안에, 함수 밖에 static으로 선언된 변수가 정적 멤버 변수입니다.
    클래스는 멤버변수와 멤버 함수로 구성됩니다.
    정적 멤버 변수는 클래스안에서 초기화를 할 수가 없습니다.
    */

    /**
    정적 멤버 변수를 선언하고 1의 값을 주어서 초기화를 해 봅니다. 에러가 납니다.

    정적 멤버 변수를 클래스 안에서 초기화를 하면 객체를 생성할 때마다 정적 멤버 변수의 값이 계속해서
    덮어질 것입니다. 왜냐하면 모든 객체들이 이 멤버를 공유하기 때문입니다.
    정적 멤버 변수는 클래스 안에서 선언만 가능하고 정의(구현, 초기화)는 불가능합니다.
    정적 멤버 변수는 모든 객체들이 접근해야 하므로 프로그램 시작부터 끝까지 유지 되어야 하기 때문에
    전역 범위에서만 정의(초기화)할 수 있습니다.

    따라서 정적 멤버 변수는 main() 함수는 물론이고, 생성자 안에서도 초기화 할 수가 없습니다.
    생성자도 static이어야 static멤버 변수를 초기화할 수 있는데, C++에서는 static 생성자를 지원하지 않습니다.
    */
    // static int m_staticValue = 1; // (X)

    static int m_value;
};

/**
전역범위는 함수 밖, 전역변수가 있는 곳입니다.
정적 멤버 변수는 모든 객체가 공유해야 하므로 프로그램 전체 영역에서 메모리 유지가 되어야 합니다.
따라서 정적 멤버 변수는 전역 범위에서 정의및 초기화를 해 주어야 합니다.
*/
int Something::m_value = 1;

/** 테스트를 위해서 SomethingOther라는 이름의 클래스를 정의해 줍니다. */
class SomethingOther
{
private:
    /**
    객체 지향 언어에서 멤버 변수는 private(개인적인) 접근지정자 안에 둡니다.
    일반 멤버 변수를 선언하고 값을 주어서 초기화를 해 줍니다.
    */
    int normal_value = 99;
    /**
    정적 멤버 변수를 선언하고 초기화를 하지 않습니다.
    정적 멤버 변수는 클래스 안에서 초기화를 할 수 없습니다.
    전역 범위에서 초기화를 해 주어야 합니다.
    */
    static int static_value;
public:
    /** 정적 멤버 함수를 정의합니다. */
    static void StaticFunction()
    {
        /** 정적 멤버 함수에서는 멤버 변수는 사용할 수 없지만 지역변수는 가능합니다. */
        int intValue1 = 1024;
        cout << "intValue1 : " << intValue1 << endl;

        cout << "" << endl;
        cout << "" << endl;

        /** 정적 멤버 함수 안에서는 일반 멤버 변수의 접근이 안됩니다. */
        // cout << "normal_value : " << normal_value << endl; // (X)
        /** 정적 멤버 함수이니 정적 멤버 변수는 접근이 가능합니다. */
        cout << "static_value : " << static_value << endl;

        cout << "" << endl;
        cout << "" << endl;
    }
};
/** 여기가 전역 범위입니다. 함수 밖입니다. 정적 멤버 변수에 값을 주어서 초기화를 할 수 있습니다. */
int SomethingOther::static_value = 2048;

/** 테스트를 위해서 Something1이라는 이름의 클래스를 정의해 줍니다. */
class Something1
{
private:
    /**
    정적 멤버 변수를 선언합니다.
    정적 멤버 변수는 클래스 안에서는 값을 주어서 초기화를 할 수 없습니다.
    전역 범위에서 값을 주어서 꼭 초기화를 해 주어야 합니다.
    초기화를 해 주지 않으면 난리가 납니다.
    */
    static int static_value;
public:
    /** 정적 멤버 변수는 정적 멤버 함수에서만 접근이 가능하니 정적 멤버 함수를 정의해 줍니다. */
    static int GetValue()
    {
        return static_value;
    }
};
/** 여기가 전역범위입니다. 전역범위에서 정적 멤버 변수에 값을 주어서 초기화를 해 줍니다. */
int Something1::static_value = 512;

/**
정적 멤버 함수는 this포인터(객체 자체)를 사용할 수 없습니다.

테스트를 위해서 Something1라는 이름의 클래스를 정의해 줍니다.
*/
class Something2
{
private:
    /** 정적 멤버 변수를 선언합니다. */
    static int static_value;
public:
    /** 정적 멤버 함수를 정의합니다. */
    static int GetValue()
    {
        /** 정적 멤버 함수에서는 this포인터를 사용할 수 없습니다. */
        // return this->static_value; // (X)
    }
    /** 일반 멤버 함수를 정의합니다. */
    int NormalGetValue()
    {
        /** 일반 멤버 변수이기 때문에 this포인터를 사용할수가 있습니다. */
        return this->static_value;
    }
};

int main()
{
    /**
    1. 정적변수 : static variable
    2. 전역변수 : global variable
    3. 정적 멤버 변수 : static member variable
    4. 정적 멤버 함수 : static member method
    */

    /**
    정적 변수

    static키워드는 블롤(함수안)내에서 선언된 지역 변수에서도 사용이 가능합니다.
    지역변수는 함수호출이 끝나면 메모리에서 사라집니다. 자동주기(auto duration)입니다.
    정의되는 시점에서 생성되고, 초기화되며, 정의된 블록이 끝나는 시점에서 소멸합니다.
    블록은 {} 중괄호 안입니다.

    그런데 static 키워드를 사용한 지역변수는 완전히 다른 의미가 있습니다.
    static 키워드를 사용한 지역변수는 자동주기가 아닙니다.
    정적 주기(static duration)라고 합니다.

    이것을 정적변수라고 합니다. 생성된 범위가 종료한 후에도 정적주기이기 때문에
    해당값을 유지하는 변수입니다.
    정적 변수는 한번만 초기화되며 프로그램 수명 내내 지속됩니다.
    */

    /** 테스트를 위해서 정적변수가 없는 IncreaseValue() 라는 이름의 함수를 정의해 줍니다. */

    /** 문장을 추가해 줍니다. */

    /**
    함수가 호출되면 값이 계속 초기화되어서 결과값이 동일합니다.
    IncreaseValue() 함수가 호출될 때마다 value변수가 생성되고 0의 값으로 초기화 됩니다.
    그 다음에 IncreaseValue() 함수의 값을 1로 증가시킨 value 변수의 값 1을 출력합니다.
    자동주기입니다.
    함수의 블록을 벗어나면 value변수는 범위를 벗어나 소멸됩니다.
    */
    IncreaseValue();
    IncreaseValue();
    IncreaseValue();
    IncreaseValue();
    IncreaseValue();

    cout << "" << endl;
    cout << "" << endl;

    /** 테스트를 위해서 정적 변수가 있는 IncreaseValueWithStatic이라는 이름의 함수를 정의해 줍니다. */

    /** 문장을 추가해 줍니다. */

    /**
    s_intValue은 static으로 선언되었기 때문에 한번만 생성되고 0으로 초기화 됩니다.
    그 다음 부터는 초기화가 되지 않습니다.
    스코프(범위)를 벗어나도 소멸되지 않습니다.
    IncreaseValueWithStatic() 함수가 호출될 때마다 s_intValue1의 값은 이전에 남겨둔 값입니다.
    */
    IncreseValueWithStatic();
    IncreseValueWithStatic();
    IncreseValueWithStatic();
    IncreseValueWithStatic();
    IncreseValueWithStatic();

    cout << "" << endl;
    cout << "" << endl;

    /**
    테스트를 위해서 g_IntValue1이라는 이름의 전역변수를 선언해 줍니다.
    전역변수가 선언된 이후에 프로그램 어디에서든지 접근이 가능합니다.
    */

    /** 문장을 추가해 줍니다. */
    g_IntValue1 = 5;
    cout << "g_IntValue1 : " << g_IntValue1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    전역변수와 로컬변수의 이름이 같을 경우 무슨일이 일어날까요?
    테스트를 위해서 intValue2라는 이름의 전역변수를 선언해 줍니다.
    */


    /** 문장을 추가해 줍니다. */

    /**
    전역변수는 변수 이름만 보더라도 전역변수인 것을 알 수 있도록 g_를 붙여주지만 테스트를 위해서 붙여주지 않습니다.
    전역변수와 같은 이름을 가진 지역변수는 전역변수를 숨깁니다.
    그러나 전역변수에 접근하기 위해서 ::(범위지정자)를 사용하면 컴파일러는 지역변수 대신 전역변수를 사용합니다.

    이렇게 전역변수와 로컬변수의 이름이 같게 되면 혼돈이 올 수 있습니다.
    따라서 전역변수를 선언할 때는 g_를 붙여주게 됩니다.
    */

    /**
    전역변수와 같은 이름의 로컬변수를 선언하고 값을 주어서 초기화 해 줍니다.
    전역변수를 숨깁니다.
    */
    int intValue2 = 5;

    /** 지역변수의 값을 1 증가시킵니다. 지역변수 intValue2변수의 값은 6이 됩니다. */
    intValue2++;
    /**
    전역변수에 접근하기 위해서 ::(범위 지정자)를 사용합니다.
    전역변수 intValue2 변수의 값이 1 감소해서 9가 됩니다.
    */
    ::intValue2--;

    cout << "global intValue2 : " << ::intValue2 << endl;
    cout << "local intValue2 : " << intValue2 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    1. 정적변수 : static이 키워드가 들어간 변수입니다.
    2. 전역변수 : 함수 밖에서 선언된 변수입니다.


    3. 정적 멤버 변수 : 멤버는 클래스의 멤버입니다. 클래스 안, 함수 밖에서 정의된 변수입니다.

    모든 객체가 하나의 메모리를 공유하는 멤버 변수입니다.
    객체들이 메모리에 생성이 됩니다. 하지만 객체별로 각각 할당되는 멤버가 아니라
    모든 객체가 공유하는 멤버 변수입니다.

    일반적으로 객체에 접근하기 위해서는 객체 생성을 먼저 해 주어야 합니다.
    하지만 정적 멤버 변수는 객체 생성 전에도 메모리에 존재합니다.
    객체 생성전에 메모리에 존재하니, 객체 생성 전에 반드시 초기화를 해 주어야 합니다.
    객체와는 독립적으로 존재합니다.

    1. 객체 이름으로 접근이 가능합니다.
    2. 클래스 이름으로도 접근이 가능합니다.
    */

    /** 테스트를 위해서 Something이라는 이름의 클래스를 정의해 줍니다. */

    /** 문장을 추가해 줍니다. */

    /**
    정적 멤버 변수의 초기화는 전역범위에서만 가능합니다. 모든 객체들이 공유해야 하기 때문입니다.
    지역범위에서 변수를 선언하려고 하면 에러가 납니다.
    */
    // int Something::m_value = 1; // (X)

    /**
    정적 멤버 변수는 객체 생성 전에도 이미 메모리에 존재합니다.
    1. 객체 생성 전에도 사용이 가능하고, 클래스 이름으로 접근이 가능합니다.
    */
    cout << "Something::m_value value : " << Something::m_value;
    cout << ", Something::m_value address : " << &Something::m_value << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 2. 객체 생성으로도 접근이 가능합니다. */
    Something st1;
    Something st2;

    st1.m_value = 512;
    /** 정적 멤버 변수는 객체들간의 값과 주소값을 공유합니다. */
    cout << "st1 value : " << st1.m_value << ", st1 address : " << &st1.m_value << endl;
    cout << "st2 value : " << st2.m_value << ", st2 address : " << &st2.m_value << endl;

    cout << "Something::m_value value : " << Something::m_value;
    cout << ", Something::m_value address : " << &Something::m_value << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 값을 수정해 줍니다. */
    st1.m_value = 1024;


    /**
    정적 멤버 변수는 객체들간의 값과 주소값을 공유합니다.
    &st1.m_value, &st2.m_value, &Something::m_value 전부 주소가 동일합니다.
    따라서 st1.m_value 정적 멤버 변수의 값을 변경하면
    st2.m_value, Something::m_value 값들도 변경이 됩니다.
    모든 객체는 정적멤버 변수의 메모리를 공유하기 때문입니다.
    */
    cout << "st1 value : " << st1.m_value << ", st1 address : " << &st1.m_value << endl;
    cout << "st2 value : " << st2.m_value << ", st2 address : " << &st2.m_value << endl;

    cout << "Something::m_value value : " << Something::m_value;
    cout << ", Something::m_value address : " << &Something::m_value << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    우리는 지금까지
    1. 정적 변수
    2. 전역 변수
    3. 정적 멤버 변수에 대해서 알아보았습니다.

    이제 정적멤버 함수에 대해서 알아 봅니다.
    */

    /**
    정적 멤버 함수

    정적 멤버 함수는 정적 멤버 변수처럼
    1. 객체 이름은 물론이고
    2. 클래스 이름만으로 접근이 가능합니다.

    객체와 독립적입니다.  객체 생성과 상관이 없습니다.

    일반적으로 멤버 변수는 객체가 생성되어야 메모리를 할당받기 때문에
    정적 멤버 함수 안에서는 정적이 아닌 멤버 변수는 사용할 수 없습니다.
    그러나 미리 전역 범위에서 메모리가 할당되는 정적 멤버 변수는 사용이 가능합니다.
    */

    /** 테스트를 위해서 SomethingOther라는 이름의 클래스를 정의해 줍니다. */


    /** 문장을 추가해 줍니다. */

    /**
    정적 멤버 변수나 정적 멤버 함수에 접근하기 위해서는

    1. 객체 생성 없이 클래스 이름으로 접근이 가능합니다.
    */
    SomethingOther::StaticFunction();
    /**
    2. 객체를 생성하고 객체 이름으로 접근이 가능합니다.
    */
    SomethingOther somethingOther1;
    somethingOther1.StaticFunction();


    /**
    정적 멤버 변수를 사용하는 이유에 대해서 알아 봅니다.

    객체 생성 여부와 상관없이 바로 클래스 이름으로 접근하고 싶을 때 사용하지만
    주로 정적 멤버 변수에 접근하려고 할 때 사용합니다.
    정적 멤버 변수는 모든 객체들이 사용하고 공유해야 하는데, 일반 멤버 변수들은 private 접근 지정자 안에 있어서
    외부에서 접근이 불가능 합니다.

    하지만 멤버 변수들은 멤버 함수들을 통해서 접근이 가능합니다.
    정적 멤버 함수는 정적 멤버 변수에 접근이 가능하도록 구현이 되어야 합니다.
    */

    /** 테스트를 위해서 Something1이라는 이름의 클래스를 정의해 줍니다. */

    /** 문장을 추가해 줍니다. */

    /** 정적 멤버 변수는 클래스의 private 접근 지정자 안에 있어서 변수에 직접 접근이 안됩니다. */
    // cout << "Something1::static_value : " << Something1::static_value << endl; // (X)
    /**
    객체 지향 언어의 캡슐화입니다. 멤버 변수의 보호입니다/
    정적 멤버 함수인 GetValue() 함수를 통해서 정적 멤버 변수에 접근합니다.

    1. 정적 멤버 변수와 정적 멤버 함수는 객체 생성 없이 클래스 이름으로 접근이 가능합니다.
    */
    cout << "Something1::GetValue() : " << Something1::GetValue() << endl;

    /** 2. 정적 멤버 변수와 정적 멤버 함수는 객체를 생성한 후 객체 이름으로 접근이 가능합니다. */
    Something1 something1;
    cout << "something1.GetValue() : " << something1.GetValue() << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    정적 멤버 함수는 this포인터(객체 자체)를 사용할 수 없습니다.

    테스트를 위해서 Something1라는 이름의 클래스를 정의해 줍니다.
    */

    /** 문장을 추가해 줍니다. */

    /**
    this 포인터는 객체인 자기 자신의 주소, 즉 객체의 주소를 담고 있기 때문에
    객체가 생성되어야만 사용할 수가 있습니다.

    정적 멤버 함수나 정적 멤버 변수는 객체 생성 전에 이미 메모리에 있습니다.
    따라서 정적 멤버 함수에서는 this포인터를 사용할 수가 없는 것입니다.

    정적 멤버 함수에서는 일반 멤버 변수를 사용할 수가 없습니다.
    일반 멤버 변수는 객체가 생성되어야지 사용할 수가 있기 때문입니다.
    */

}
