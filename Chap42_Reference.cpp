#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

int main()
{
    /**
    참조자(Reference)는 C++을 사용한다면 반드시 익혀야하는 매우 중요한 개념입니다.
    하지만 구조적으로 포인터와 유사하여 혼돈이 생길 수 있습니다.
    C언어 때는 참조자가 없었습니다.
    C++에서 참조자가 생겨서 가독성(보기좋고, 읽기 쉬운 코드)이 좋은 코드를 작성할 수 있습니다.
    */

    /**
    참조자는 2가지 종류가 있습니다.
    1. 비-상수 참조 : 보통 참조자라고 하면 이것을 의미합니다.
    2. 상수 참조 : 상수를 참조하기 위한 것이지만 비-상수 참조도 가능합니다.
    */

    /**
    참조자란 대상에게 또 다른 이름을 붙여주는 것을 의미합니다.
    별명 또는 별칭을 지어준다고 할 수 있습니다.

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
}


