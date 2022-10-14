#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

int main()
{
    /**
    C++ 문법에서 자연스럽게 써야 하는 문법적 요소
    1. 포인터      Pointer
    2. 참조자      Reference
    3. 상수       Constant
    4. 동적할당     Dynamic Memory Allocation
    5. 스마트 포인터 Smart Pointer
            unique_ptr : 객체의 유일한 소유권을 가지는 스마트 포인트
            shared_ptr : 객체간의 공유가 가능한 스마트 포인터
            weak_ptr   : shared_ptr의 순환참조 문제를 해결한 약한 참조의 스마트 포인터
    */

    /**
    Memory 영역은 다음과 같이 나뉘게 됩니다.

    Code : 실행한 프로그램의 코드가 저장됩니다.
    Data : 전역변수(Global Variable), 정적변수(Static Variable)가 저장되면
            프로그램 종료 시까지 사라지지 않고 남아있습니다.
    Stack : 지역변수와 매개변수가 할당되고 함수를 빠져나가면 자동 소멸됩니다.
    Heap : 동적으로 할당된 메모리 영역이며 프로그래머에 의해 할당 및 해제 됩니다.
    */

    /**
    함수에 매개 변수로 값을 전달합니다.
    매개 변수 : Parameter, 인수(Argument)
    */

    /**
    정적 메모리 할당과 동적 메모리 할당에 대해서 알아 봅니다.

    정적으로 메모리를 할당하면 컴파일시 stack영역에 할당되며, 함수를 빠져 나갈 때 소멸됩니다.
    프로그램 컴파일시 stack에 얼마만큼의 크기로 할당을 해야 하는지 결정되기 때문에
    컴파일 이후 크기를 변경할 수 없습니다.

    따라서 정적 배열 선언시 크기를 가변적으로 명시하면 문제가 될 수 있기 때문에;
    반드시 상수로 명시해야 합니다.
    */

    /** 문장을 추가해 줍니다. */
    int intValue1 = 10;
    const int intValue2 = 10;

    /**
    따라서 정적 배열 선언시 크기를 가변적으로 명시하면 문제가 될 수 있기 때문에;
    반드시 상수로 명시해야 합니다.
    */
    // int intArray1[intValue1]; // (X)

    int intArray2[intValue2];
    int intArray3[10];

    cout << "" << endl;
    cout << "" << endl;

    /**
    배열의 종류
    int intArray1[] = {1, 2, 3, 4, 5};          C언어의 배열
    arry<int, 5> intArray2 = {1, 2, 3, 4, 5};   C++ 언어의 배열
    */

    /**
    동적으로 메모리를 할당하는 경우 데이터가 heap영역에 할당됩니다.
    heap 메모리 영역은 프로그래머에 의해 할당(new 연산자)되거나 소멸(delete 연산자)됩니다.
    동적할당은 프로그래머가 원할 땨ㅐ 원하는 크기로 할당할 수 있습니다.
    포인터 변수는 stack에 할당됩니다.
    */

    /** 문장을 추가해 줍니다. */
    int intValue4 = 10;
    /** intArray4 포인터 변수는 stack에 할당되며, intArray1 배열은 heap에 할당됩니다. */
    int* intArray4 = new int[intValue4];

    cout << "" << endl;
    cout << "" << endl;

    /**
    native C++ 의 문자열 클래스는 string입니다. #include <string>
    unreal C++ 의 문자열 클래스는 FString입니다.

    native C++의 스마트 포인터는 unique_ptr, shared_ptr, weak_ptr입니다.  #include <memory>
    unreal C++의 스마트 포인터는 TUniquePtr, TSharedPtr, TWeakPtr입니다.
    */

    /**
    C : malloc(말록, Memory Allocation) 함수와 free() 함수

    C++ : new 연산자와 delete 연산자

    정적 메모리는 컴파일시에 Stack 영역에 할당되고, 함수를 빠져나올 대 소멸됩니다.
    반면 동적 메모리는 런타임시에 프로그래머에 의해서 Heap 영역에 할당되고 소멸됩니다.
    할당시에는 new 연산자를 사용하며 소멸시에는 delete 연산자를 사용합니다.

    heap 영역에 동적 할당되는 메모리의 경우 사용이 끝난다면 반드시 delete를 해 주어야 합니다.
    참고로 동적 배열을 delete 하는 경우 배열이라는 것을 명시하기 위해 delete[] 연산자를 사용합니다.
    */

    /** 문장을 추가해 줍니다. */

    /** 동적 할당*/
    int* intPtr1 = new int;
    int* intPtr2 = new int(3);
    int* intPtr3 = new int{ 5 };
    int* intPtr4 = new int();

    /** 배열의 동적 할당*/
    int* array1 = new int[5];

    /** 소멸 */
    delete intPtr1;
    delete intPtr2;
    delete intPtr3;
    delete intPtr4;

    /** 배열의 소멸 */
    delete[] array1;

    cout << "" << endl;
    cout << "" << endl;

    /**
    배열의 동적 할당에 대해서 알아 봅니다.

    정적 할당으로 배열을 선언하게 되면 사이즈가 정해져 버립니다.
    안 쓸 수도 있는데, 사이즈가 정해져 버립니다. 메모리 공간의 낭비가 심해집니다.
    */

    /** 문장을 추가해 줍니다. */

    /**
    사이즈가 1000개인 배열변수를 선언했습니다.
    만일 선언만 하고 안쓴다면 int타입은 4byte입니다. 4 * 1000 = 4000 byte의 비효율이 발생합니다.
    */
    int intArray5[1000];

    /**
    메모리 최적화를 위해서 동적 할당을 할 수 있습니다.
    배열에서는 사이즈도 원하는 사이즈로 동적 할당을 할 수 있습니다.
    */

    /** 문장을 추가해 줍니다. */
    int* intPtr8;
    int arrayLength = 10;

    intPtr8 = new int[arrayLength];

    for (int i = 0; i < arrayLength; i++)
    {
        intPtr8[i] = i;
    }

    for (int i = 0; i < arrayLength; i++)
    {
        cout << "intPtr8[" << i << "] : " << intPtr8[i] << endl;
    }

    /** 꼭 delete 연산자로 메모리에서 객체 해제를 해 주어야 합니다. */
    delete[] intPtr8;

}
