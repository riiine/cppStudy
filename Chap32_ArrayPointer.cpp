#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 배열의 사이즈를 알아오기 위한 라이브러리*/
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

    /** 배열포인터에 대해서 알아 봅니다. */
    int intArr1[9] = { 1, 2,3, 4, 5, 6, 7, 8, 9 };
    int* intPtr1 = intArr1;

    for (int i = 0; i < size(intArr1); i++)
    {
        cout << *(intPtr1 + i) << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    for (int i = 0; i < size(intArr1); i++)
    {
        cout << intPtr1[i] << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /**
    3번째 문장이 헷갈립니다. 하지만 이렇게 이해 하시면 됩니다.
    intArr1[i] => *(intArr1 + i) => *(intPtr1 + i) => *(i + intPtr1) => i[intPtr1]
    */
    for (int i = 0; i < size(intArr1); i++)
    {
        cout << i[intPtr1] << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /**
    포인터와 배열의 관계에 대해서 정리를 해 봅니다.

    문장을 추가해 줍니다.
    */
    intPtr1 = &intArr1[0];
    cout << "intPtr1 : " << &intArr1[0] << endl;

    intPtr1 = &intPtr1[0];
    cout << "intPtr1 : " << &intPtr1[0] << endl;

    *intPtr1 = intArr1[0];
    cout << "*intPtr1 : " << intArr1[0] << endl;

    *intPtr1 = intPtr1[0];
    cout << "*intPtr1 : " << intPtr1[0] << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    그러면 intPtr1 + 1의 값은 무엇일까요?

    문장을 추가해 줍니다.
    */
    cout << "intPtr1 : " << intPtr1 << endl;
    /** intPtr1 포인터 변수에 sizeof(*intPtr1)을 더한 주소값입니다. */
    cout << "intPtr1 + 1" << intPtr1 + 1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 반복문으로 주소값을 출력해 봅니다. */
    for (int i = 0; i < size(intArr1); i++)
    {
        cout << "address : " << &intArr1[i] << endl;
    }

    cout << "" << endl;
    cout << "" << endl;

    /** 배열이 아닌 포인터 주소로 알아보니 에러가 납니다. 주석 처리해 줍니다. */
    //for (int i = 0; i < size(intPtr1); i++)
    //{

    //}

    /**
    double 타입으로 테스트를 해 봅니다.

    문장을 추가해 줍니다.
    */
    double doubleValue1[5] = { 3.14, 3.14, 3.14, 3.14, 3.14 };

    for (int i = 0; i < size(doubleValue1); i++)
    {
        cout << "double address : " << &doubleValue1[i] << endl;
    }

    cout << "" << endl;
    std::cout << "" << std::endl;

    cout << "size of double : " << sizeof(doubleValue1[0]) << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    string 타입으로 테스트를 해 보도록 합니다.

    문장을 추가해 줍니다.
    */
    string stringValue1[] = { "Jane", "Tom", "James", "Emma", "Smith" };

    for (int i = 0; i < size(stringValue1); i++)
    {
        cout << "string address : " << &stringValue1[i] << endl;
    }

    cout << "" << endl;
    cout << "" << endl;

    cout << "size of string : " << sizeof(stringValue1[0]) << endl;

    cout << "size of string address : " << sizeof(&stringValue1[0]) << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    다음을 테스트해 보기 위해서 문장을 추가해 줍니다.
    확인
    */
    int intArr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    cout << "intArr1 : " << intArr2 << endl;
    cout << "intArr2 + 1 : " << intArr2 + 1 << endl;
    cout << "&intArr2 : " << &intArr2 << endl;
    cout << "&intArr2 + 1 : " << &intArr2 + 1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    배열 포인터에 대해서 알아 봅니다.

    배열포인터는 배열 자체를 가리키는 포인터 입니다.
    */
    int intArr3[3] = { 1, 2, 3 };
    /** 사이즈가 3인 int타입의 배열을 가리키는 포인터를 선언합니다. */
    int(*arrPtr3)[3];

    arrPtr3 = &intArr3;

    /** 반복문으로 값을 확인해 봅니다. */
    for (int i = 0; i < size(intArr3); i++)
    {
        /**
        배열 포인터가 가리키는 값은 배열입니다.
        (arrPtr3) : 배열 포인터입니다.
        *(arrPtr3) : 배열 포인터가 가리키는 값은 배열입니다.
        (*arrPtr3)[i] : 배열에 인덱스로 접근합니다.
        */
        cout << "*(arrPtr3)[" << i << "] : " << (*arrPtr3)[i] << endl;
    }

    cout << "" << endl;
    cout << "" << endl;

    /**
    조금 더 테스트를 해 보도록 합니다.

    문장을 추가해 줍니다.
    */
    int intArr4[5] = { 1, 2, 3, 4, 5 };
    /** int타입의 요소를 5개 가지고 있는 배열을 가리키는 배열 포인터를 선언합니다. */
    int(*arrPtr4)[5];

    arrPtr4 = &intArr4;

    /**
    배열의 주소를 가진 포인터는 +1 / -1 연산으로 어느 요소든 쉽게 접근이 가능합니다.
    포인터에 1을 더하면 주소는 int타입의 무게인 4byte 만큼 더해 집니다.

    확인
    */
    cout << "intArr4[0] 주소값 : " << *arrPtr4 << endl;
    cout << "intArr4[1] 주소값 : " << *(arrPtr4 + 1) << endl;
    cout << "intArr4[2] 주소값 : " << *(arrPtr4 + 2) << endl;
    cout << "intArr4[3] 주소값 : " << *(arrPtr4 + 3) << endl;
    cout << "intArr4[4] 주소값 : " << *(arrPtr4 + 4) << endl;

    cout << "" << endl;
    cout << "" << endl;

    for (int i = 0; i < size(intArr4); i++)
    {
        cout << "intArr4[" << i << "] 주소값 : " << arrPtr4[i] << endl;
    }

    cout << "" << endl;
    cout << "" << endl;

    for (int i = 0; i < size(intArr4); i++)
    {
        cout << "intArr4[" << i << "] 값 : " << (*arrPtr4)[i] << endl;
    }

    cout << "" << endl;
    cout << "" << endl;


}