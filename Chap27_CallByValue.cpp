#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 값에 의한 호출을 테스트 해 보기 위해서 CallByValue라는 이름의 함수를 정의해 줍니다. */
void CallByValue(int value)
{
    /** 함수 내부에서 값을 변경합니다. */
    value = 20;
    cout << "value : " << value << ", address : " << &value << endl;
}

/** 주소에 의한 호출을 테스트해 보기 위해서 CallByAddress 라는 이름의 함수를 정의해 줍니다. */
void CallByAddress(int* address)
{
    *address = 20;
    cout << "address : " << *address << ", address address : " << address << endl;
}

/** 참조에 의한 호출을 테스트해 보기 위해서 CallByReference라는 이름의 함수를 정의해 주도록 합니다. */
void CallByReference(int& reference)
{
    reference = 20;
    cout << "reference : " << reference << ", reference address " << &reference << endl;
}

/** 값에 의한 호출을 테스트 하기 위해서 SwapByValue라는 이름의 함수를 정의합니다. */
void SwapByValue(int value1, int value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;

    cout << "value1 : " << value1 << ", value2 : " << value2 << endl;
}

/**
CallByAddress는 주소에 의한 호출로, 주소 값을 매개 변수로 전달하는 함수 호출을 의미합니다.
주소에 의한 호출을 테스트 하기 위해서 SwapByAddress라는 이름의 함수를 정의합니다.
*/
void SwapByAddress(int* value1, int* value2)
{
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;

    cout << "value1 : " << *value1 << ", value2 : " << *value2 << endl;
}

/**
참조에 의한 호출에 대해서 알아 봅니다.
참조에 의한 호출을 테스트하기 위해서 SwapByReference라는 이름의 함수를 정의합니다.
*/
void SwapByReference(int& value1, int& value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;

    cout << "value1 : " << value1 << ", value2 : " << value2 << endl;
}

int main()
{
    /**
    함수에 매개 변수에 값을 전달하는 방식입니다.

    CallByValue : 값에 의한 호출
    CallByAddress : 주소에 의한 호출
    CallByReference : 참조에 의한 호출
    */

    /**
    CallByValue는 값에 의한 호출로, 함수의 매개 변수로 넘기는 값을 복사해서
    넘겨주는 방식입니다.
    */

    /**
    CallByValue (값에 의한 호출)

    함수가 호출될 때 메모리 공간 안에서는 함수를 위한 별도의 임시 공간이 생성됩니다.
    함수가 종료되면 해당 공간은 사라집니다.
    메모리 공간은 스택(stack)과 힙(Heal)이 있습니다.
    스택 프레임 : 함수 호출시 할당되는 메모리 블록입니다. 지역 변수의 선언으로 할당되는 메모리 블록입니다.
    값에 의한 호출 방식은 전달되는 변수의 값을 복사하여 함수의 매개변수로 전달합니다.
    복사된 변수의 값은 함수 안에서 지역적으로 사용되는 local value의 특성의 가집니다.
    따라서 함수 안에서 매개변수의 값이 변경되어도, 외부의 변수의 값은 변경되지 않습니다.
    */

    /**
    CallByReference (참조에 의한 호출)

    함수를 호출할 때, 메모리 공간 안에서는 함수를 위한 별도의 공간이 생성됩니다.
    함수가 종료되면 해당 공간은 사라집니다.
    참조에 의한 호출은 매개 변수로 전달되는 변수의 레퍼런스(참조)를 전달합니다.
    해당 변수를 계속 가리키게 됩니다.
    따라서 함수 안에서 매개 변수의 값이 변경되면, 매개 변수로 전달된 값도 변경됩니다.
    */

    /** 값에 의한 호출을 테스트 해 보기 위해서 CallByValue라는 이름의 함수를 정의해 줍니다. */

    /** 문장을 추가해 줍니다. */

    /**
    함수가 호출되면 int value = intValue3 형태로 값의 복사가 이루어집니다.
    실제로 intValue3를 대입시키는 것이 아니라 intValue3 변수가 가지는 값을 복사하고 임시로 메모리에
    저장한 후에 그 값을 value에 넣습니다. value와 intValue3는 지역변수로써 각각 다른 주소값을 가지게 됩니다.
    때문에 value의 값을 변경해도 intValue3 변수의 값은 변경되지 않습니다.
    */
    int intValue3 = 10;
    CallByValue(intValue3);

    cout << "intValue3 : " << intValue3 << ", intValue3 address : " << &intValue3 << endl;
    cout << "" << endl;

    /** 주소에 의한 호출을 테스트해 보기 위해서 CallByAddress 라는 이름의 함수를 정의해 줍니다. */

    /** 문장을 추가해 줍니다. */

    /**
    함수가 호출되면 int* address = &intValue4 의 형태로 address가 intValue4의 주소를 가리키고 있기 때문에
    역참조 연산자로 intValue4의 주소에 접근을 하고 값을 변경하면 intValue4의 값이 변경되게 됩니다.
    */
    int intValue4 = 10;
    CallByAddress(&intValue4);

    cout << "intValue4 : " << intValue4 << ", intValue4 address : " << &intValue4 << endl;

    cout << "" << endl;

    /** 참조에 의한 호출을 테스트해 보기 위해서 CallByReference라는 이름의 함수를 정의해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */

    int intValue5 = 10;
    CallByReference(intValue5);

    cout << "intValue5 : " << intValue5 << ", intValue5 address : " << &intValue5 << endl;

    cout << "" << endl;

    /**
    매개 변수에 값을 전달하더라도 원본 변수의 값을 변경하지 않으려면 CallByValue를 씁니다.
    매개 변수에 값을 전달하면서 원본 변수의 값을 변경하려 한다면 CallByReference를 씁니다.
    하지만 문법적으로 CallByAddress를 알아야 합니다.
    */

    /** 값에 의한 호출을 테스트 하기 위해서 SwapByValue라는 이름의 함수를 정의합니다. */

    /** 문장을 추가해 줍니다. */

    /**
    intValue6의 값은 value1에 복사되고, intValue7의 값은 value2에 복사되어 전달되기 때문에
    intValue6와 intValue7의 값이 바뀐것이 아니라 value1과 value2의 값만 변경되었습니다.
    CallByValue는 값을 복사해서 전달되기 때문에 함수 외부에 선언된 변수가 변경될 가능성이 없지만
    값을 넘겨줄 때마다 데이터 복사에 의한 비용 손실 문제가 발생하는 단점이 존재합니다.
    */
    int intValue6 = 1;
    int intValue7 = 2;

    SwapByValue(intValue6, intValue7);

    cout << "intValue6 : " << intValue6 << ", intValue7 : " << intValue7 << endl;
    cout << "" << endl;

    /**
    CallByAddress는 주소에 의한 호출로, 주소 값을 매개 변수로 전달하는 함수 호출을 의미합니다.
    주소에 의한 호출을 테스트 하기 위해서 SwapByAddress라는 이름의 함수를 정의합니다.
    */

    /** 문장을 추가해 줍니다. */

    /**
    값이 변경된 것을 확인할 수 있습니다. CallByAddress는 비용 손실 문제는 해결했지만
    외부 변수의 값이 변경되는 부분이 있습니다.
    외부 변수의 값 변경이 필요한 경우도 있지만, 필요하지 않은 경우에는 언제 에러가 발생할지도 모르고
    어디서 일어났는지 모르는 상황이 발생할 수도 있습니다.
    */
    int intValue8 = 1;
    int intValue9 = 2;

    SwapByAddress(&intValue8, &intValue9);

    cout << "intValue8 : " << intValue8 << ", intValue9 : " << intValue9 << endl;
    cout << "" << endl;

    /**
    참조에 의한 호출에 대해서 알아 봅니다.
    참조에 의한 호출을 테스트하기 위해서 SwapByReference라는 이름의 함수를 정의합니다.
    */

    /** 문장을 추가해 줍니다. */

    /**
    SwapByReference의 value1은 intValue10을 가리키는 참조자이고
    value2는 intValue11을 가리키는 참조자입니다.
    참조자는 같은 데이터 공간을 가리키는 변수지만, 이름만 다른 뿐입니다.
    참조자는 대상에 별명을 지어주는 것입니다.
    */
    int intValue10 = 1;
    int intValue11 = 2;

    SwapByReference(intValue10, intValue11);

    cout << "intValue10 : " << intValue10 << ", intValue11 : " << intValue11 << endl;
    cout << "" << endl;
}