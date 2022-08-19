#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/**
그렇다면 왜 굳이 참조자까지 사용하면서 상수를 참조하는 것일까요?
테스트를 위해서 AddConst() 라는 이름의 함수를 정의해 줍니다.
*/
int AddConst(const int& num1, const int& num2)
{
    // num1 = 10; // const 지정어가 붙어있는 변수이니 값 변경의 불가능합니다. 
    // num2 = 20; // const 지정어가 붙어있는 변수이니 값 변경의 불가능합니다. 
    return num1 + num2;
}

/**
만일 const 참조자가 없다면?
테스트를 위해서 AddNonConst()라는 이름의 함수를 추가해 줍니다.
비-상수 매개 변수입니다.
*/
int AddNonConst(int& num1, int& num2)
{
    return num1 + num2;
}

/**
CallByValue를 테스트 해 보기 위해서 SwapByValue라는 이름의 함수를 정의해 주도록 합니다.
값을 변경하는 함수입니다. 매개 변수로 arg1 = 1, arg2 = 2를 넣어면 arg1 = 2, arg2 = 1
*/
void SwapByValue(int arg1, int arg2)
{
    int temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}


/** CallByAddress를 테스트 해 보기 위해서 SawpByAddress라는 이름의 함수를 정의해 주도록 합니다.*/
void SwapByAddress(int* arg1, int* arg2)
{
    int temp = *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}

/** CallByReference를 테스트 해 보기 위해서 SwapByReference라는 이름의 함수를 정의해 주도록 합니다.*/
void SwapByReference(int& arg1, int& arg2)
{
    int temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}

/**
참조자를 이용한 함수 호출의 장점은 무엇일까요?
테스트를 위해서 PrintNumConst라는 이름의 함수를 정의해 줍니다.
*/
void PrintNumConst(const int arg)
{
    /** 매개 변수에 const 지정어를 붙여서 의도치 않는 변형을 방지합니다. */
    // arg = 30; // (X)
    cout << "arg : " << arg << endl;
}

/** 테스트를 위해서 PrintNumConstReference라는 이름의 함수를 정의해 주도록 합니다. */
void PrintNumConstReference(const int& arg)
{
    /** 매개 변수에 const지정어를 붙여서 의도치 않는 변형을 방지합니다. */
    // arg = 30; // (X)
    cout << "arg : " << arg << endl;
}

/**
반환 타입이 값이 함수가 있습니다.
테스트를 위해서 AddNumReturnValue라는 이름의 함수를 정의해 주도록 합니다.
*/
int AddNumReturnValue(int& arg)
{
    arg++;
    return arg;
}

/**
반환타입이 참조자인 함수입니다.
테스트를 위해서 AddNumReturnReference라는 이름의 함수를 정의해 주도록 합니다.
*/
int& AddNumReturnReference(int& arg)
{
    arg++;
    return arg;
}

int main()
{
    /**
    참조자(Reference)는 C++을 사용한다면 반드시 익혀야 하는 매우 중요한 개념입니다.
    하지만 구조적으로 포인터와 유사하여 혼돈이 생길수 있습니다.
    C언어 때는 참조자가 없었습니다.
    C++에서 참조자가 생겨서 가독성(보기 좋고, 읽기 쉬운 코드)이 좋은 코드를 작성할 수 있습니다.
    */

    /**
    참조자는 2가지 종류가 있습니다.
    1. 비-상수 참조 : 보통 참조자라고 하면 이것을 의미합니다.
    2. 상수 참조 : 상수를 참조하기 위한 것이지만 비-상수 참조도 가능합니다.
    */

    /**
    참조자란 대상에게 또 다른 이름을 붙여주는 것을 의미합니다.
    별명 또는 별칭을 지어 준다고 할 있습니다.

    문장을 추가해 줍니다.
    */

    int intValue1 = 1;
    /**
    int참조자 타입의 intRef1이라는 이름의 참조자 변수를 선언했습니다.
    intValue1 변수의 별명으로 선언했습니다.
    */
    int& intRef1 = intValue1;


    /**
    int intValue1 = 1;
    는 스택 메모리의 특정 영역에 int만큼의 크기를 할당하고 1이라는 데이터를 복사하는 것입니다.
    그리고 할당된 메모리의 이름은 intValue1이라고 하고 이것을 변수라고 합니다.

    int& intRef1 = intValue1;
    는 intValue1을 참조하는 참조자 intRef1을 선언하는 것입니다.
    그럼 이 변수의 이름은 intValue1뿐만이 아니고 intRef1도 되는 것입니다.
    하나의 메모리 공간에 이름이 2개가 생기고 이 둘의 주소값이 동일합니다.
    하나의 대상을 두고 2개가 아니라 그 이상도 참조자를 선언할 수 있습니다.
    intRef1 = 2;
    는 값과 주소를 모두 출력해 보면 intValue1과 intRef1 모두 값이 2로 변경되고
    주소 또한 동일한 것을 확인할 수 있습니다.
    */
    cout << "intValue1 : " << intValue1 << ", intValue1 address : " << &intValue1 << endl;
    cout << "intRef1 : " << intRef1 << ", intRef1 address : " << &intRef1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    intRef1 = 2;
    cout << "intValue1 : " << intValue1 << ", intValue1 address : " << &intValue1 << endl;
    cout << "intRef1 : " << intRef1 << ", intRef1 address : " << &intRef1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 참조자의 선언방법에 대해서 알아 봅니다. */
    int intValue2 = 1;
    int& intRef2 = intValue2;

    /**
    참조자를 선언하는 방법은 선언시 &(앰퍼샌드)를 붙여야 하며
    선언과 동시에 참조할 대상을 지정하여 초기화를 해야만 합니다.
    */
    // int& intRef3; // 컴파일 에러, 참조자는 선언과 동시에 초기화를 해야만 합니다. 

    /** 참조할 대상의 변경은 불가능합니다. */
    int intValue4 = 1;
    int intValue5 = 2;

    /**
    int참조자 타입의 intRef5라는 이름의 참조자 변수를 선언했습니다.
    intValue4 변수의 별칭으로 선언했습니다.
    */
    int& intRef5 = intValue4;
    /**
    intRef5 참조자 변수는 intValue5변수의 별칭으로 선언했다고 오해를 할 수가 있습니다.
    참조자는 한번 대상을 정하면 대상을 변경하지 못합니다.
    */
    intRef5 = intValue5;
    /**
    한번 누구가를 참조했으면 참조의 대상을 변경할 수 없습니다.
    intRef5가 intValue4를 참조한 상태에서 intRef5 = intValue5; 를 해도
    intRef5가 intValue5를 참조하는 것이 아니고
    intValue4 = intValue5; 를 하는 것입니다.
    intValue4변수에 intValue5변수의 값을 대입하는 것입니다.
    당연히 intValue4와 intValue5의 주소값은 틀리게 됩니다.

    intRef5와 intValue4의 주소값은 같습니다.
    */
    cout << "intRef5 value : " << intRef5 << ", intRef5 address : " << &intRef5 << endl;
    cout << "intValue4 value : " << intValue4 << ", intValue4 address : " << &intValue4 << endl;
    cout << "intValue5 value : " << intValue5 << ", intValue5 address : " << &intValue5 << endl;

    cout << "" << endl;
    cout << "" << endl;


    /** 상수 참조에 대해서 정리를 해 봅니다. */

    /**
    비-상수 참조자로 상수를 참조할 수는 없지만 const를 사용하면 가능합니다.
    또한 const int& intRef7 = 100; 처럼 리터럴 상수도 참조가 가능합니다.
    여기에서 100이라는 리터럴 상수는 임시적인 값으로써 메모리에 이름도 없이 존재했다가 사라집니다.
    때문에 비-상수 참조자는 상수를 참조할 수가 없습니다.
    하지만 상수를 const 참조자로 참조하면 임시 변수라는 것이 생기면서 참조가 가능합니다.
    */
    const int intValue6 = 10; // 상수
    // int& intRef6 = intValue6; // 컴파일 에러, 비-상수 참조자로 상수 참조는 불가능합니다. 
    const int& intRef6 = intValue6; // 상수 참조자로 상수 참조는 가능합니다. 
    const int& intRef7 = 100; // 100은 리터럴(값 그 자체) 상수입니다. 


    /**
    그렇다면 왜 굳이 참조자까지 사용하면서 상수를 참조하는 것일까요?
    테스트를 위해서 AddConst() 라는 이름의 함수를 정의해 줍니다.
    */

    /**
    문장을 추가해 줍니다.
    매개 변수에 상수로 값을 전달합니다.
    */
    cout << "AddConst(1, 2) : " << AddConst(1, 2) << endl;
    cout << "" << endl;

    /**
    만일 const 참조자가 없다면?
    테스트를 위해서 AddNonConst()라는 이름의 함수를 추가해 줍니다.
    */

    /** 문장을 추가해 줍니다. */
    int intValue8 = 1;
    int intValue9 = 2;

    cout << "AddNonConst(intValue8, intValue9) : " << AddNonConst(intValue8, intValue9) << endl;
    // cout << "AddNonConst(1, 2) : " << AddNonConst(1, 2) << endl; // (X)
    cout << "" << endl;

    /**
    1. 매개 변수로 상수 값을 전달하려면 상수 참조 매개변수를 적용합니다.
    2. 매개 변수로 변수 값을 전달하려면 비-상수 참조 매개변수를 적용합니다.
    */

    /** 그러면 참조자는 NULL을 참조할 수 있을 까요? */

    /**
    기본적으로 NULL 참조는 불가능합니다.

    NULL은 상수 값 0을 define해 놓은 것이므로 NULL과 0은 같습니다.
    따라서 일반 참조자는 NULL참조가 불가능합니다.
    */
    // int& intRef10 = NULL; // 컴파일 에러, 비-상수 참조자로 상수 참조 불가능합니다. 
    const int& intRef10 = NULL; // 가능은 하지만 의미는 없습니다. 
    // const int& intRef11 = nullptr; // nullptr는 상수 0이 아니고 포인터입니다. 


    /**
    매개 변수에 값을 전달하는 방법은 3가지가 있습니다.
    1. CallByValue : 값에 의한 전달
    2. CallByAddress : 주소에 의한 전달
    3. CallByReference : 참조에 의한 전달

    CallByValue, CallByAddress 는 C언어와 C++ 언어에 모두 존재합니다.
    하지만 CallByReference는 C++ 문법에만 있습니다. 발전된 형태입니다.

    좋은 습관
    1. 모든 if문을 switch문으로 변경할 수 없지만 가능하다면 switch문을 사용합니다. 가독성
    2. 모든 for문을 foreach문으로 변경할 수 없지만 가능하다면 foreach문을 사용합니다. 가독성
    3. 매개 변수에 참조자 매개 변수를 사용할 수 있다면 포인터 매개 변수보다는 참조자 매개 변수를 사용합니다. 가독성
    */

    /**
    CallByValue를 테스트 해 보기 위해서 SwapByValue라는 이름의 함수를 정의해 주도록 합니다.
    CallByAddress를 테스트 해 보기 위해서 SawpByAddress라는 이름의 함수를 정의해 주도록 합니다.
    CallByReference를 테스트 해 보기 위해서 SwapByReference라는 이름의 함수를 정의해 주도록 합니다.
    */


    /** 문장을 추가해 줍니다. */
    int intValue11 = 1;
    int intValue12 = 2;
    int intValue13 = 1;
    int intValue14 = 2;
    int intValue15 = 1;
    int intValue16 = 2;

    cout << "CallByValue" << endl;
    /**
    CallByValue는 매개 변수에 값을 복사해서 전달해 줍니다.
    원본 변수의 값이 변경되지 않습니다.
    */
    cout << "intValue11 : " << intValue11 << ", intValue12 : " << intValue12 << endl;
    SwapByValue(intValue11, intValue12);
    cout << "intValue11 : " << intValue11 << ", intValue12 : " << intValue12 << endl;
    cout << "" << endl;

    cout << "CallByAddress" << endl;
    /**
    CallByAddress는 매개변수에 주소값을 전달해 줍니다.
    원본 변수의 값이 변경됩니다.
    */
    cout << "intValue13 : " << intValue13 << ", intValue14 : " << intValue14 << endl;
    SwapByAddress(&intValue13, &intValue14);
    cout << "intValue13 : " << intValue13 << ", intValue14 : " << intValue14 << endl;
    cout << "" << endl;

    cout << "CallByReference" << endl;
    /**
    CallByRefernce는 매개변수에 참조를 전달해 줍니다.
    원본 변수의 값이 변경됩니다.
    함수 내용을 보니 CallByAddress보다 복잡하지 않습니다. 가독성 있습니다.
    CallByAddress와 CallByReference는 결과 값은 똑같습니다.
    하지만 가독성이 좋은, 복잡하게 보이지 않는 CallByReference를 쓰는 이유입니다.
    */
    cout << "intValue15 : " << intValue15 << ", intValue16 : " << intValue16 << endl;
    SwapByReference(intValue15, intValue16);
    cout << "intValue15 : " << intValue15 << ", intValue16 : " << intValue16 << endl;
    cout << "" << endl;

    /**
    매개 변수로 준 값을 변경하지 않고 싶을 때에는 CallByValue를 씁니다.
    매개 변수로 준 값을 변경하고 싶을 때에는 CallByReference를 씁니다.
    되도록이면 CallByAddress는 쓰지 않습니다.
    */

    /**
    참조자를 이용한 함수 호출의 장점은 무엇일까요?
    테스트를 위해서 PrintNumConst라는 이름의 함수를 정의해 줍니다.
    */

    /** 문장을 추가해 줍니다. */
    int intValue17 = 1;

    PrintNumConst(intValue17); // const int arg = intValue17;
    cout << "" << endl;

    /**
    그런데 만일 전달하는 데이터가 int타입이 아니고 엄청나게 큰 용량의 객체라면?
    그만큼 거대한 용량의 메모리를 복사해서 재할당해야 하기 때문에 메모리 낭비가 됩니다.
    CallByValue 방식의 큰 단점입니다.

    하지만 참조자로 매개 변수에 값을 전달하게 되면 값을 복사해서 전달해 주지 않기 때문에
    메모리 낭비가 없게 됩니다.
    */

    /** 테스트를 위해서 PrintNumConstReference라는 이름의 함수를 정의해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    int intValue18 = 1;

    /**
    PrintNumConstReference() 함수는 매개 변수를 값이 아니라 참조자로 받고 있습니다.
    메모리 재할당이 없어집니다.
    이렇게 메모리 재할당을 방지하는 것은 포인터로도 할 수 있습니다.
    하지만 참조자는 포인터와 달리 주소값 연산을 이용해서 해당 메모리가 아닌 다른 메모리에 아예 접근할 수 없기 때문에
    한 번 누군가를 참조했으면 참조의 대상을 변경할 수 없기 때문에
    안전하다는 큰 장점이 있습니다.
    포인터 매개 변수(CallByAddress)를 쓰지 않고 참조자 매개 변수(CallByReference)를 써야 하는 이유입니다.
    */
    PrintNumConstReference(intValue18); // const int& arg = insValue18;
    cout << "" << endl;


    /**
    반환 타입이 값이 함수가 있습니다.
    테스트를 위해서 AddNumReturnValue라는 이름의 함수를 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
    int intValue19 = 1;
    int intValue20 = AddNumReturnValue(intValue19); // intValue19와 intValue20은 별개의 변수입니다. 

    /**
    AddNumReturnValue() 함수는 매개 변수를 참조자로 받고, int타입으로 값을 반환하고 있습니다.
    int intValue20 = AddNumReturnValue(intValue19); 는 intValue20 = 2; 와 마찬가지입니다.
    intValue19는 CallByReference로 함수에 매개 변수로 전달되었기 때문에
    AddNumReturnValue(intValue19) 함수에서 2가 됩니다.
    intValue19와 intValue20은 완전히 별개의 변수입니다.
    */
    cout << "intValue19 value : " << intValue19 << ", intValue19 address : " << &intValue19 << endl;
    cout << "intValue20 value : " << intValue20 << ", intValue20 address : " << &intValue20 << endl;
    cout << "" << endl;

    intValue19++;

    cout << "intValue19 value : " << intValue19 << ", intValue19 address : " << &intValue19 << endl;
    cout << "intValue20 value : " << intValue20 << ", intValue20 address : " << &intValue20 << endl;
    cout << "" << endl;


    /**
    반환타입이 참조자인 함수입니다.
    테스트를 위해서 AddNumReturnReference라는 이름의 함수를 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
    int intValue21 = 1;
    int intValue22 = AddNumReturnReference(intValue21);

    cout << "intValue21 value : " << intValue21 << ", intValue21 address : " << &intValue21 << endl;
    cout << "intValue22 value : " << intValue22 << ", intValue22 address : " << &intValue22 << endl;
    cout << "" << endl;

    intValue21++;

    cout << "intValue21 value : " << intValue21 << ", intValue21 address : " << &intValue21 << endl;
    cout << "intValue22 value : " << intValue22 << ", intValue22 address : " << &intValue22 << endl;
    cout << "" << endl;

    /**
    반환 타입이 참조자이니 intValue21과 intValue22 변수는 같은 변수라고 오해할 수가 있습니다.
    하지만 다른 변수입니다.

    같은 변수가 되려면 어떻게 해야 할까요?
    반환 타입이 참조자라고 하면 받는 변수도 참조자 변수로 해야 합니다.

    문장을 추가해 줍니다.
    */

    intValue21 = 1;
    int& intRef21 = AddNumReturnReference(intValue21); // 참조자로 받았기 때문에 intValue21과 intRef21은 같습니다. 

    cout << "intValue21 value : " << intValue21 << ", intValue21 address : " << &intValue21 << endl;
    cout << "intRef21 value : " << intRef21 << ", intRef21 address : " << &intRef21 << endl;
    cout << "" << endl;

    intRef21++;

    cout << "intValue21 value : " << intValue21 << ", intValue21 address : " << &intValue21 << endl;
    cout << "intRef21 value : " << intRef21 << ", intRef21 address : " << &intRef21 << endl;
    cout << "" << endl;

    intValue21++;

    cout << "intValue21 value : " << intValue21 << ", intValue21 address : " << &intValue21 << endl;
    cout << "intRef21 value : " << intRef21 << ", intRef21 address : " << &intRef21 << endl;
    cout << "" << endl;




}

