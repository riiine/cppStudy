#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 배열의 사이즈를 알기 위한 라이브러리*/
#include <array>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

int main()
{
    /**
    1. 배열과 포인터
    2. 배열포인터
    3. 포인터배열
    */

    /** 배열과 포인터에 대해서 알아 봅니다. */
    int intValue1 = 10;
    /** 포인터 변수를 선언하고 초기화를 합니다. */
    int* intPtr1 = &intValue1;

    cout << "intPtr1 : " << *intPtr1 << ", intPtr1 address : " << intPtr1 << endl;

    *intPtr1 = 20;

    cout << "intPtr1 : " << *intPtr1 << ", intPtr1 address : " << intPtr1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    주소값을 확인해 보도록 합니다.
    int타입의 무게는 4byte입니다.
    주소값은 16진수입니다.
    포인터 변수에 1을 더한 값이 출력된 것을 볼 수 있습니다.
    이는 무엇을 의미하는 것일까요?
    intPtr1 + 1의 주소값 : intPtr1의 주소값에 4바이트가 더해진 값입니다.
    */
    cout << "intPtr1의 주소값 : " << intPtr1 << endl;
    cout << "intPtr1 + 1의 주소값 : " << intPtr1 + 1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 배열을 선언하면 배열의 시작주소(배열의 0번째 인덱스 값의 주소입니다. )가 반환됩니다. */

    /** 문장을 추가해 줍니다. */
    int intArr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    cout << "intArr1[0] value : " << *intArr1 << endl;
    cout << "intArr1[0] value : " << intArr1[0] << endl;

    cout << "intArr1[1] value : " << *(intArr1 + 1) << endl;
    cout << "intArr1[1] value : " << intArr1[1] << endl;

    cout << "intArr1[0] address : " << intArr1 << endl;
    cout << "intArr1[0] address : " << &intArr1[0] << endl;

    cout << "intArr1[1] address : " << intArr1 + 1 << endl;
    cout << "intArr1[1] address : " << &intArr1[1] << endl;

    /** 다음과 같은 표현도 가능합니다. */
    cout << "intArr1[1] address : " << &intArr1[0] + 1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    반복문으로 주소값을 출력해 봅니다.
    문장을 추가해 줍니다.
    */

    /** 확인*/
    int index = 0;

    for (int i : intArr1)
    {
        cout << "intArr1[" << index << "] address : " << &intArr1[index] << endl;

        index++;
    }

    cout << "" << endl;
    cout << "" << endl;

    for (int i = 0; i < size(intArr1); i++)
    {
        cout << "intArr1[" << i << "] address : " << &intArr1[i] << endl;
    }


    cout << "" << endl;
    cout << "" << endl;

    char charValue2 = 'L';
    int intValue2 = 1024;
    double doubleValue2 = 3.14;

    /** 포인터 변수의 사이즈는 4바이트 입니다. 확인해 봅니다. */
    cout << "charValue2 size : " << sizeof(charValue2) << endl;
    cout << "charValue2 ptr size : " << sizeof(&charValue2) << endl;

    cout << "intValue2 size : " << sizeof(intValue2) << endl;
    cout << "intValue2 ptr size : " << sizeof(&intValue2) << endl;

    cout << "doubleValue2 size : " << sizeof(doubleValue2) << endl;
    cout << "doubleValue2 ptr size : " << sizeof(&doubleValue2) << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 문장을 추가해 줍니다. */
    /** 확인*/
    int intArr2[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for (int i = 0; i < size(intArr2); i++)
    {
        cout << "address0 : " << &intArr2[i] << endl;
        cout << "address1 : " << intArr2 + (i + 1) << endl;
        cout << "" << endl;
    }

    cout << "" << endl;
    cout << "" << endl;

    /** 다음 문장을 보도록 합니다. */
    for (int i = 0; i < size(intArr2); i++)
    {
        cout << intArr2[i] << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    for (int i = 0; i < size(intArr2); i++)
    {
        cout << *(intArr2 + i) << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    for (int* ptr = intArr2; ptr < intArr2 + size(intArr2); ptr++)
    {
        cout << *ptr << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 배열의 사이즈를 알아보도록 합니다. */
    cout << "array size : " << sizeof intArr2 / sizeof intArr2[0] << endl;

    cout << "array size : " << size(intArr2) << endl;

    cout << "array size : " << sizeof(intArr2) / sizeof(intArr2[0]) << endl;


}