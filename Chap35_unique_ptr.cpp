#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 스마트 포인터 관련 라이브러리*/
#include <memory>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

int main()
{
    /**
    unique_ptr : 객체의 유일한 소유권을 가지는 스마트 포인터
    shared_ptr : 객체 간의 공유가 가능한 스마트 포인터
    weak_ptr   : shared_ptr의 순환참조 문제를 해결한 약한 참조의 스마트 포인터
    */

    /** 생성자로 unique_ptr 객체를 생성합니다. */
    unique_ptr<int> uniquePtr1(new int(3));
    cout << "uniqueptr1 value : " << *uniquePtr1 << ", uniquePtr1 address : " << uniquePtr1.get() << endl;
    cout << "" << endl;

    /** 대입 연산자로 unique_ptr 객체를 생성합니다. */
    unique_ptr<int> uniquePtr2 = unique_ptr<int>(new int(10));
    cout << "uniquePtr2 value : " << *uniquePtr2 << ", uniquePtr2 address : " << uniquePtr2.get() << endl;
    cout << "" << endl;

    /** 소유권을 갖기 때문에 객체를 소유하는 unique_ptr는 2개가 되어서는 안 됩니다. */
    unique_ptr<int> uniquePtr3 = unique_ptr<int>(new int(3));
    // unique_ptr<int> uniquePtr4 = uniquePtr3; // (X)
    cout << "" << endl;

    /**
    소유권을 이전할 수가 있습니다.
    move() 함수 : unique_ptr 객체의 소유권을 이전하기 위해서는 move() 함수를 사용합니다.
    아예 이동시켜 버리는 것이기 때문에 원본 unique_ptr는 empty가 됩니다.
    */
    unique_ptr<int> uniquePtr5(new int(3));
    cout << "uniquePtr5 value : " << *uniquePtr5 << ", uniquePtr5 address : " << uniquePtr5.get() << endl;
    cout << "" << endl;

    unique_ptr<int> uniquePtr6 = move(uniquePtr5);
    cout << "uniquePtr6 value : " << *uniquePtr6 << ", uniquePtr6 address : " << uniquePtr6.get() << endl;
    cout << "" << endl;

    /** C++은 포인터가 nullptr인데 접근하면 에러가 생깁니다. */
    // cout << "uniquePtr5 value : " << *uniquePtr5 << ", uniquePtr5 address : " << uniquePtr5.get() << endl; // (X)
    cout << "" << endl;

    /** reset() 함수 : 만일 unique_ptr에 할당된 값을 지우거나 다른 값으로 변경하고 싶다면 reset() 함수를 사용합니다. */
    unique_ptr<int> uniquePtr7 = make_unique<int>(10);
    cout << "uniquePtr7 value : " << *uniquePtr7 << ", uniquePtr7 address : " << uniquePtr7.get() << endl;
    cout << "" << endl;

    /** reset() 함수로 다른 값으로 변경했습니다. */
    uniquePtr7.reset(new int(20));
    cout << "uniquePtr7 value : " << *uniquePtr7 << ", uniquePtr7 address : " << uniquePtr7.get() << endl;
    cout << "" << endl;

    /** reset() 함수로 다른 값으로 변경했습니다. */
    uniquePtr7.reset(new int(30));
    cout << "uniquePtr7 value : " << *uniquePtr7 << ", uniquePtr7 address : " << uniquePtr7.get() << endl;
    cout << "" << endl;

    /** 매개 변수 없이 reset() 함수를 쓰면 empty가 됩니다. */
    uniquePtr7.reset();
    /** 객체가 nullptr인데 접근하려고 하면 에러가 생깁니다. */
    // cout << "uniquePtr7 value : " << *uniquePtr7 << ", uniquePtr7 address : " << uniquePtr7.get() << endl; // (X)
    cout << "" << endl;

    /**
    release() 함수

    move() 함수는 unique_ptr 객체 자체를 이동시켜 버립니다.
    reset() 함수는 매개 변수가 있다면 unique_ptr 객체를 새로운 값으로 생성합니다.
        당연히 새로운 값으로 생성을 하니 주소값이 틀려집니다.
    release() 함수는 unique_ptr 객체를 반환하는 것이 아니고 포인터 주소만 반환합니다.
    동적 할당으로 생성된 객체의 포인터 주소만 반환합니다.
    따라서 delete 연산자로 객체를 직접 해재해 주어야 합니다.
    원본 unique_ptr 객체는 empty가 됩니다.
    만약 현재 unique_ptr 객체가 empty라면 반환된 객체는 nullptr가 될 것입니다.

    release() 함수는 내가 메모리 관리를 해 주어야 합니다.
    */

    /** 선언만 하고 객체 생성은 하지 않았습니다. empty입니다. */
    unique_ptr<int> uniquePtr8;
    cout << "" << endl;
    
    /** release() 함수는 unique_ptr 객체를 반환하는 것이 아니고 포인터 주소만 반환합니다. */
    /** 원본이 empty입니다. nullptr를 반환합니다. */
    int* intPtr8 = uniquePtr8.release();
    cout << "" << endl;

    /** 원본 객체는 empty가 됩니다. */
    // cout << "uniquePtr8 value : " << *uniquePtr8 << ", uniquePtr8 address : " << uniquePtr8.get() << endl; // (X)
    cout << "" << endl;

    /** reset() 함수로 새로운 값을 가집니다. */
    uniquePtr8.reset(new int(30));
    cout << "uniquePtr8 value : " << *uniquePtr8 << ", uniquePtr8 address : " << uniquePtr8.get() << endl;
    cout << "" << endl;

    /** release() 함수는 unique_ptr 객체를 반환하는 것이 아니고 포인터 주소만 반환합니다. */
    intPtr8 = uniquePtr8.release();
    /** 원본 객체는 empty가 됩니다. */
    cout << "uniquePtr8 value : " << *uniquePtr8 << ", uniquePtr8 address : " << uniquePtr8.get() << endl; // (X)
    cout << "" << endl;

    /** 더 이상 객체에 접근할 필요가 없다면 객에를 직접 메모리 해제 해 줍니다. */
    if (intPtr8)
    {
        /** delete 연산자로 메모리 해제를 해 주지 않으면 메모리 누수가 생깁니다. */
        delete intPtr8;
    }
    cout << "" << endl;

    /**
    unique_ptr는 자원(포인터)을 고유하게 관리합니다.
    하나의 자원을 하나의 unique_ptr 객체만 소유할 수 있습니다.
    자원을 소유한 객체가 소멸되면 자동적으로 메모리에서 해제가 됩니다.

    move() 함수에 대한 정리를 해봅니다.
    move를 하면 원본 unique_ptr 객체는 empty가 됩니다.
    move가 되어도 객체는 하나의 unique_ptr만 소유합니다.
    */
    unique_ptr<int> uniquePtr9 = make_unique<int>(10);

    /** 대입 연산자로 대입해 봅니다. */
    // unique_ptr<int> uniquePtr10 = uniquePtr9; // (X)

    /** 복사 생성자로 객체를 생성해 봅니다. */
    // unique_ptr<int> uniquePtr11(uniquePtr9); // (X)

    /**
    move() 함수에 대한 정리입니다.

    문장을 추가해 줍니다.
    */
    unique_ptr<int> uniquePtr12 = make_unique<int>(10);
    cout << "uniquePtr12 value : " << *uniquePtr12 << ", uniquePtr12 address : " << uniquePtr12.get() << endl;
    cout << "" << endl;

    /** uniquePtr12 객체를 이동했으므로 uniquePtr12 객체는 empty가 됩니다. */
    unique_ptr<int> uniquePtr13 = move(uniquePtr12);
    cout << "uniquePtr13 value : " << *uniquePtr13 << ", uniquePtr13 address : " << uniquePtr13.get() << endl;
    cout << "" << endl;

    /** uniquePtr12 객체가 empty인데 접근하려면 에러가 생깁니다. */
    // cout << "uniquePtr12 value : " << *uniquePtr12 << ", uniquePtr12 address : " << uniquePtr12.get() << endl; // (X)
    cout << "" << endl;

    /**
    unique_ptr 객체를 생성하는 방법은 많습니다.
    하지만 make_unique() 함수를 사용하는 것이 예외에 안전합니다.
    */

    /** int 타입의 포인터를 가지는 생성자로 unique_ptr 객체를 생성합니다. */
    unique_ptr<int> uniquePtr14(new int(10));
    cout << "uniquePtr14 value : " << *uniquePtr14 << ", uniquePtr14 address : " << uniquePtr14.get() << endl;
    cout << "" << endl;

    /**
    int 타입의 포인터를 가지는 unique_ptr 객체를 make_unique() 함수를 사용해서 객체를 생성합니다.
    예외에 안전하게 구현이 되어 있습니다.
    */
    unique_ptr<int> uniquePtr15 = make_unique<int>(10);
    cout << "uniquePtr15 value : " << *uniquePtr15 << ", uniquePtr15 address : " << uniquePtr15.get() << endl;
    cout << "" << endl;

    /**
    게임을 만들기 위해서는
    1. 유저의 정보를 저장하고 가져오는 데이터 베이스
    2. RPG의 요소인 인벤토리, 인벤토리의 기본 스탯 정보는 엑셀테이블에서 가져옵니다.
    3. 실시간 서버 연동
    */

}


