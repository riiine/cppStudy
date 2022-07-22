#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

int main()
{
    /**
    C++ 문법에서 자연스럽게 써야하는 문법적 요소
    1. 포인터          Pointer
    2. 참조자          Reference
    3. 상수            Constant
    4. 동적할당        Dynamic Memory Allocation
    5. 스마트 포인터   Smart Pointer
                unique_ptr : 객체의 유일한 소유권을 가지는 스마트 포인터
                shared_ptr : 객체 간의 공유가 가능한 스마트 포인터
                weak_ptr   : shared_ptr의 순환참조 문제를 해결한 약한 참조의 스마트 포인터
    */

    /**
    Memory 영역은 다음과 같이 나뉘게 됩니다.

    Code : 실행한 프로그램의 코드가 저장됩니다.
    Data : 전역변수(Global Variable), 정적변수(Static Variable)가 저장되면
            프로그램 종료 시까지 사라지지 않고 남아있습니다.
    Stack : 지역변수와 매개변수가 할당되고 함수를 빠져나가면 자동 소멸됩니다.
    Heap : 동적으로 할당된 메모리 영역이며 프로그래머에 의해 할당 및 해제됩니다.
    */

    /**
    함수에 매개변수로 값을 전달합니다.
    매개변수 : Parameter, 인수(Argument)
    */

    /**
    정적 메모리 할당과 동적 메모리 할당에 대해서 알아봅니다.

    정적으로 메모리를 할당하면 컴파일 시 stack영역에 할당되며, 함수를 빠져나갈 때 소멸됩니다.
    프로그램 컴파일 시 stack에 얼마만큼의 크기로 할당을 해야하는지 결정되기 때문에
    컴파일 이후 크기를 변경할 수 없습니다.

    따라서 정적 배열 선언시 크기를 가변적으로 명시하면 문제가 될 수 있기 때문에
    반드시 상수로 명시해야 합니다.
    */

    /** 문장을 추가해줍니다. */
    int intValue1 = 10;
    const int intValue2 = 10;
    
    /**
    따라서 정적 배열 선언시 크기를 가변적으로 명시하면 문제가 될 수 있기 때문에
    반드시 상수로 명시해야 합니다.
    */
    // int intArray1[intValue1]; // (X)

    int intArray2[intValue2];
    int intArray3[10];

    cout << "" << endl;
    cout << "" << endl;

    /**
    배열의 종류
    int intArray1[] = {1, 2, 3, 4, 5};              C언어의 배열
    array<int, 5> intArray2 = {1, 2, 3, 4, 5};      C++ 언어의 배열
    */

    /**
    동적으로 메모리를 할당하는 경우 데이터가 heap영역에 할당됩니다.
    heap 메모리 영역은 프로그래머에 의해 할당(new 연산자)되거나 소멸(delete 연산자)됩니다.
    동적할당은 프로그래머가 원할 때 원하는 크기로 할당할 수 있습니다.
    포인터 변수는 stack에 할당됩니다.
    */

    /** 문장을 추가해줍니다. */
    int intValue4 = 10;
    /** intArray4 포인터 변수는 stack에 할당되며, intArray1 배열은 heap에 할당됩니다. */
    int* intArray4 = new int[intValue4];

    cout << "" << endl;
    cout << "" << endl;

    /**
    native C++ 의 문자열 클래스는 string입니다. #include <string>
    unreal C++ 의 문자열 클래스는 FString입니다.

    native C++ 의 스마트 포인터는 unique_ptr, shared_ptr, weak_ptr 입니다.     #include <memory>
    unreal C++ 의 스마트 포인터는 TUniquePtr, TSharedPtr, TWeakPtr 입니다.
    */
}
