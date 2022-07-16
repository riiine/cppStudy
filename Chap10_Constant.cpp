#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/**
const 변수는 반드시 선언시 초기화를 해야 하며 초기화가 되지 않으면 컴파일 에러가 발생합니다.
그래서 const의 멤버 변수를 const로 선언시에는 반드시 초기화 리스트로 초기화 해야 합니다.

테스트를 위해서 Lion이라는 이름의 클래스와 Tiger라는 이름의 클래스를 정의해 주도록 합니다.
*/

/**
Lion클래스의 num 멤버 변수는 생성자에서 초기화 리스트로 1로 초기화를 하고 있는데
이는 const int num = 1; 과 동일한 의미입니다. 
*/
class Lion
{
    const int num;
    /**
    클래스 이름과 동일한 함수가 생성자 함수입니다. 
    생성자 함수는 객체를 생성하면서 멤버 변수의 초기화를 담당합니다. 
    : (콜론) 뒤가 초기화 리스트로 멤버 변수를 초기화 하고 있습니다. 
    */
    Lion() : num(1)  // const int num = 1;
    {

    }
};

/**
그런데 Tiger클래스의 num 멤버 변수는 생성자에서 초기화 리스트를 사용하지 않고 함수 내부에서 초기화를 시도하고 있습니다. 
이것은 초기화가 아니라 const int num; 으로 const변수를 선언한 다음에 num = 1;을 시도하는 것입니다. 
따라서 const 변수를 1로 수정한다는 의미이므로 컴파일 에러가 발생합니다. 

따라서 주석처리 해 주도록 합니다. 
*/
class Tiger
{
    const int num;

    //Tiger()
    //{
    //    // num = 1; //  컴파일 에러가 납니다. 초기화 리스트로 초기화를 해 주지 않아서 에러가 납니다. 
    //    // const int num;
    //    // num = 1;
    //}
};

/**
전처리 지시자는 #define, #include, #endif, #pragma등과 같이 #으로 시작하는 문구를 말하는데
여기서 #define은 매크로라고 하면 이를 이용해서 상수를 정의할 수 있습니다.
매크로를 이용해서 상수를 정의해 주도록 합니다.
*/
#define WIDTH 3
#define HEIGHT 4

/**
enum상수에 대해서 알아 봅니다.
enum상수를 정의해 주도록 합니다.
*/
enum EWidthHeight
{
    Width = 3,
    Height = 5,

    /**
    enum타입은 단점이 있습니다. 
    정수형만 가능하기 때문에 PI = 3.14, 와 같은 상수의 선언은 불가능합니다. 
    */
    // PI = 3.14, // (X)
};

/**
상수는 함수의 매개 변수와 함께 사용하는 경우가 많습니다.

매개변수 : Parameter, 인수(Argument)

테스트를 위해서 ConstParameter라는 이름의 함수를 정의해 주도록 합니다.
*/

/**
함수를 호출하는 사람에게 intValue변수의 값을 변경하지 말라고 하는 것입니다. 
intValue변수의 값을 변경하지 못합니다. 
*/
void ConstParameter(const int intValue)
{
    cout << "intValue : " << intValue << endl;

     // intValue = 10; // (X)
}

/**
반환형이 있는 함수에 const키워드가 붙으면 어떻게 될까요?
테스트를 위해서 Animal이라는 이름의 클래스를 정의해 주도록 합니다.
*/
class Animal
{
private:
    int m_EyeSight = 100;
public:
    /** 반환형이 있는 함수에 const키워드를 붙이면 멤버 변수의 값을 변경하지 못한다는 것을 보장합니다.*/
    int GetEyeSight() const;
};

int main()
{
    /**
    const는 constant의 약자로 사전적 의미로 "상수"를 의미합니다. 
    말 그대로 const는 그 대상을 변경하지 않는 "상수"를 의미합니다. 
    const 위치에 따라 의미하는 바는 완전히 달라집니다. 
    */

    /**
    C++ 문법중에서 자연스럽게, 디테일하게 알아야 하는 문법적 요소
    1. 포인터  Pointer
    2. 참조자  Reference
    3. 상수   Const
    4. 동적할당 Dynamic Memory Allocation
    5. 스마트 포인터
        . unique_ptr : 객체의 유일한 소유권을 가지는 스마트 포인터
        . shared_ptr : 객체간의 공유가 가능한 스마트 포인터
        . weak_ptr   : shared_ptr의 고질적인 문제인 순환참조 문제를 해결한
                    약한 참조의 스마트 포인터
    */

    /**
    보통 const 위치가 맨 앞인 첫 번째 형식을 많이 사용합니다. 
    다름과 같이 선언하면 intValue1과 intValue2는 변할 수 없는 상수가 됩니다. 
    또한 함수의 반환형이나 매개변수가 const 변수형일 때도 동일한 의미입니다. 
    */
    /** 자료형 앞에 const 키워드를 붙입니다. */
    const int intValue1 = 1;
    // intValue1 = 2; // (X)

    /** 자료형과 변수 이름 사이에 const 키워드를 붙입니다. */
    int const intvalue2 = 1;
    // intValue2 = 2; // (X)

    /**
    const 변수는 반드시 선언시 초기화를 해야 하며 초기화가 되지 않으면 컴파일 에러가 발생합니다. 
    그래서 const의 멤버 변수를 const로 선언시에는 반드시 초기화 리스트로 초기화 해야 합니다. 

    테스트를 위해서 Lion이라는 이름의 클래스와 Tiger라는 이름의 클래스를 정의해 주도록 합니다. 
    */

    /**
    포인터와 const를 사용할 때는 세가지 경우가 있습니다. 
    첫번째, const위치가 맨 앞에 있으면서 포인터 변수가 가리키는 값에 대해서 상수화 시키는 경우입니다. 
    */
    int intValue3 = 1;

    /**
    int포인터 타입의 intPtr1이라는 이름의 포인터 변수를 선언했습니다. 
    intValue3변수의 주소값을 intPtr1 포인터 변수에 대입함으로써 초기화했습니다. 
    그리고 *intPtr1(intPtr1포인터 변수가 가리키는 값)을 상수화 했습니다. 
    */
    const int* intPtr1 = &intValue3;

    /**
    intPtr1 포인터 변수가 가리키는 값을 상수화 했습니다. 

    *intPtr1 = 2;는 intPtr1이 const 변수이기 때문에 컴파일 에러가 발생하지만
    intValue3 = 2; 는 intValue3가 non-const(비-상수)변수이기 때문에 정상입니다. 
    즉, 포인터 변수가 가리키는 intValue3 자체가 상수화가 되는 것이 아닙니다. 
    */
    // *intPtr1 = 2; // (X) 컴파일 에러
    intValue3 = 2;

    /** 두번째는 const 위치가 자료형과 변수 이름 사이에 있으면서 포인터 변수 자체를 상수화 시키는 경우입니다. */
    int intValue4 = 1;
    int intValue5 = 2;

    /**
    int포인터 타입의 intPtr2라는 이름의 포인터 변수를 선언했습니다. 
    intValue4변수의 주소값을 intPtr2포인터 변수에 대입함으로써 초기화 했습니다. 
    그리고 intPtr2포인터 변수의 주소값 자체를 상수화 했습니다. 
    */
    int* const intPtr2 = &intValue4;

    /**
    포인터 변수란 대상의 주소값을 저장하는 변수입니다. 
    즉 위의 자기 자신의 주소를 상수화 시키는 것이기 때문에 intValue5의 주소값으로 변경하려고 하면
    컴파일 에러가 발생합니다. 
    */
    // intPtr2 = &intValue5; // (X) 컴파일 에러가 납니다. 

    /**
    세번째는 자료형 앞에 const키워가 있고, 자료형과 변수 이름 사이에도 const키워드가 있습니다. 
    */
    int intValue6 = 1;
    int intValue7 = 2;

    /**
    int포인터 타입의 intPtr3라는 이름의 포인터 변수를 선언했습니다. 
    intValue6의 주소값을 intPtr3 포인터 변수에 대입함으로써 초기화 했습니다. 
    자료형 앞에 const키워드를 두어서 포인터 변수가 가리키는 값을 상수화했습니다. 
    자료형과 변수 이름 사이에 const키워드를 두어서 포인터 주소값 자체를 상수화 했습니다. 
    */
    const int* const intPtr3 = &intValue6;

    // *intPtr3 = 2; // (X) 컴파일 에러
    // intPtr3 = &intValue7; // (X) 컴파일 에러

    /**
    C언어 때는 일반변수와 포인터 변수가 있습니다. 
    C++ 언어에서는 참조자를 지원합니다. 
    */

    /**
    C++에서는 참조자(Reference)가 있기 때문에 포인터를 사용할 일이 그리 많지 않습니다. 
    일반 변수
    포인터 변수
    참조자 변수보다는 그냥 참조자라고 합니다. 
    
    만약 포인터를 상수화 시키려면 const int* const ptr = &num; 와 같이 다소 번거롭고
    가독성이 떨어지는 코드가 되겠지만 , 
    참조자는 애초에 참조하는 대상을 변경할 수 없는 특징이 있기 때문에
    const int& ref = num; 의 형태가 됩니다. 
    */

    /**
    C/C++을 공부하다 보면 다양한 방식의 상수 선언 법을 알게 됩니다. 
    #define, const, enum 세가지 상수 선언 방식에 대해서 알아 봅니다. 
    */

    /**
    #define 상수 (매크로)에 대해서 알아 봅니다. 

    소스코드를 빌드한다는 것은
    1. 전처리(Preprocess)
    2. 컴파일(Compile)
    3. 어셈블(Assemble)
    4. 링크(Link)
    라는 과정을 거쳐서 실행파일(.exe)를 만들게 됩니다. 

    첫 과정인 전처리기(Preprocessor)가 소스코드를 쪽 읽어서 전처리 지시자(Preprocess Directive)로 
    처리된 부분을 해석하여 소스코드를 변형시켜주는 것을 의미합니다. 
    */

    /**
    전처리 지시자는 #define, #include, #endif, #pragma등과 같이 #으로 시작하는 문구를 말하는데
    여기서 #define은 매크로라고 하면 이를 이용해서 상수를 정의할 수 있습니다.
    매크로를 이용해서 상수를 정의해 주도록 합니다. 
    */

    /** 문장을 추가해 줍니다. */
    int intArr1[WIDTH][HEIGHT];

    /** const 상수에 대해서 알아 봅니다. */
    const int width = 3;
    const int height = 5;
    int intarr2[width][height];

    /**
    enum상수에 대해서 알아 봅니다. 
    enum상수를 정의해 주도록 합니다. 
    */

    /** 문장을 추가해 줍니다. */
    int intArr3[EWidthHeight::Width][EWidthHeight::Height];

    /**
    상수는 함수의 매개 변수와 함께 사용하는 경우가 많습니다. 

    매개변수 : Parameter, 인수(Argument)

    테스트를 위해서 ConstParameter라는 이름의 함수를 정의해 주도록 합니다. 
    */

    /** 
    1. 자료형 앞에 const키워드가 붙어서 포인터 변수가 가리키는 값을 상수화 합니다. 
    2. 자료형과 변수 이름 사이에 const키워드가 붙어서 포인터 변수의 주소 자체를 상수화 합니다. 
    3. 자료형 앞에, 그리고 자료형과 변수이름 사이에 const키워드가 붙어서 포인터 변수가 가리키는 값을
        상수화 하고, 포인터 변수의 주소 자체를 상수화 합니다. 
    4. 함수의 매개 변수에 const키워드를 붙여서 매개 변수의 값이 변경되지 않는다는 것을 보장합니다. 
        협업하는 프로그래머의 있을 수 있는 실수를 방지합니다. 
    5. 반환형이 있는 함수에 const키워드를 붙여서 멤버 변수의 값이 변경되지 않는다는 것을 보장합니다. 
        협업하는 프로그래머의 있을 수 있는 실수를 방지합니다. 
    */

    /** 
    상수에는 2가지 상수가 존재합니다. 

    1. 컴파일 시간에 알 수 있는 살수를 컴파일 시간 상수(Compile time constant)
    2. 실행시간에 알 수 있는 상수를 런타임 상수(Runtime constant)

    constexpr, const는 둘다 상수를 만들어주는 키워드 이지만

    const는 컴파일 시간, 런타임 시간 상수 모두 만들 수 있고,
    constexpr은 컴파일 시간 상수만 만들수 있습니다. 
    */
    int intValue8 = 10;
    
    const int intValue9 = 20;       // 컴파일 시간 상수
    const int intValue10 = intValue8; // 런타임 상수

    constexpr int intValue11 = 20;  // 컴파일 시간 상수
    // constexpr int intValue12 = intValue8; // (X) 런타임 상수

    /** 지금까지 보았던 모든 포인터는 상수(const)가 아닌 값을 가리키는 비-상수(non-const) 포인터입니다. */
    int intValue12 = 5;
    int* intPtr12 = &intValue12;
    *intPtr12 = 6;

    /**
    값이 상수인 경우는 어떻게 될까요? 
    컴파일이 되지 않습니다. 상수 변수는 값을 변경할 수 없습니다. 
    만일 상수가 아닌 포인터가 상수 변수를 가리킨 다음에 역참조 연산자로 값을 변경할 수 있다면
    const 의 의도를 위반하게 되므로 상수가 아닌 포인터는 상수 변수를 가리킬 수 없습니다. 
    */
    const int intValue13 = 5;
    // int* intPtr13 = &intValue13; // (X)
    // *intPtr13 = 6;          // (X)

    /** 
    int* intPtr13 = &intValue13; 
    상수를 가리키는 포인터는 상수 변수의 주소를 가리키는 비-상수 포인터입니다. 
    상수 변수에 대한 포인터를 선언하려면 자료형 앞에 const키워드를 붙이면 됩니다. 
    */
    const int intValue14 = 5;
    const int* intPtr14 = &intValue14;
    // *intPtr14 = 6; // (X)

    /**
    상수 변수에 대한 포인터는 상수가 아닌 변수를 가리킬 수 있습니다. 
    상수 변수에 대한 포인터는 변수가 초기에 const로 정의되어 있는지에 관계 없이 포인터를 통해
    접근할 때 변수를 상수로 취급합니다.
    */
    int intValue15 = 5;
    const int* intPtr15 = &intValue15;
    intValue15 = 6;
    // *intPtr15 = 10; // (X)

    /** 상수를 가리키는 포인터는 상수를 가리킬 뿐, 상수 자체가 아니므로 다른 값을 가리킬 수 있습니다. */
    int intValue17 = 5;
    const int* intPtr17 = &intValue17;
    int intValue18 = 6;
    intPtr17 = &intValue18;

    /**
    포인터 자체를 상수로 만들 수 있습니다. 상수 포인터는 초기화 후에 가리키는 주소를 변경할 수 없는 포인터입니다. 
    포인터 자체를 상수화하려면 자료형 뒤에 const 키워드를 붙이면 됩니다. 
    */
    int intValue19 = 5;
    int* const intPtr19 = &intValue19;
    // intPtr19 = &intValue18; // (X)

    /**
    일반 상수 변수와 마찬가지로 상수 포인터는 선언시 초기화해야 합니다. 
    즉, 상수 포인터는 항상 같은 주소를 가리킵니다. 
    */
    int intValue20 = 5;
    int intValue21 = 6;
    int* const intPtr20 = &intValue20;
    // intPtr20 = &intValue21; // (X)

    /** 포인터가 상수일뿐, 가리키는 변수는 상수가 아니므로 포인터를 역참조하여 값을 변경하는 것은 가능합니다. */
    int intValue22 = 5;
    int* const intPtr22 = &intValue22;
    *intPtr22 = 6;

    /**
    자료형 앞뒤에 const키워드를 사용해서 상수를 가리키는 상수  포인터를 선언할 수 있습니다. 
    상수를 가리키는 상수 포인터는 다른 주소를 가리키도록 수정할 수 없으며, 역참조 연산자를 통해 값을 
    수정할 수도 없습니다. 
    */
    int intValue23 = 5;
    const int* const intPtr23 = &intValue23;
    // *intPtr23 = 6; // (X)

    /**
    반환형이 있는 함수에 const키워드가 붙으면 어떻게 될까요? 
    테스트를 위해서 Animal이라는 이름의 클래스를 정의해 주도록 합니다. 
    */
}

int Animal::GetEyeSight() const
{
    /** 
    반환형이 있는 함수에 const키워드를 붙이면 멤버 변수의 값을 변경하지 못한다는 것을 보장합니다. 
    협업하는 프로그래머의 있을 수 있는 실수를 원천봉쇄합니다. 
    */
    // m_EyeSight = 200; // (X)
    return m_EyeSight;
}
