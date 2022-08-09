#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 스마트 포인터 관련 라이브러리*/
#include <memory>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 텍스트를 위해서 CountSharedPointer라는 이름의 함수를 정의해 주도록 합니다. */
void CountSharedPointer(shared_ptr<int> sharedPointer)
{
    cout << "sharedPointer.use_count() : " << sharedPointer.use_count() << endl;
}

/**
참조에 의한 호출을 사용하는 경우 함수에서 참조 카운터는 증가하지 않습니다.

테스트를 위해서 CountSharedReference라는 이름의 함수를 정의해 주도록 합니다.
*/
void CountSharedReference(shared_ptr<int>& sharedReference)
{
    cout << "sharedReference.use_count() : " << sharedReference.use_count() << endl;
}


int main()
{
    /**
    1. unique_ptr : 객체의 유일한 소유권을 가지는 스마트 포인터
    2. shared_ptr : 객체 간의 공유가 가능한 스마트 포인터
    3. weak_ptr   : shared_ptr의 순환참조 문제를 해결한 약한 참조의 스마트 포인터
    */

    /**
    되도록이면 new 연산자와 delete 연산자로 메모리 관리를 하지 말아야 합니다.

    unique_ptr나 shared_ptr에서도 스마트 포인터 객체 타입으로 리턴하는 것이 아니고
    포인터 타입으로만 리턴하는 경우가 있었습니다.
    요럴 때는 우리가 직접 메모리 관리를 해 주어야 합니다.

    shared_ptr는 C++ 11(2011년)이 제공하는 스마트 포인터 클래스 중에 하나입니다.
    포인터를 더 이상 사용하지 않는 경우 메모리를 자동으로 해제해 줍니다.
    */

    /**
    shared_ptr 객체 생성 시 바로 메모리를 가리키는 방법은 2가지가 있습니다.
    하지만 예외에 안정적인 make_shared() 함수 사용을 권장합니다.
    */

    /**
    shared_ptr를 위한 힙 메모리에 다음 2개의 메모리가 할당됩니다.
    1. 객체를 위한 메모리
    2. 참조 카운터(Reference Counter) 를 위한 메모리
       이 메모리는 공유하는 shared_ptr 객체의 개수를 의미합니다. 초기값은 1입니다.
       *(역참조 연산자)를 사용하여 shared_ptr가 가리키는 포인터에 저장된 값을 알 수 있습니다.
    */

    /**
    shared_ptr는 2가지 방법으로 shared_ptr 객체를 생성할 수 있습니다.

    문장을 추가해 줍니다.
    */
    shared_ptr<int> sharedPtr1(new int(10));
    shared_ptr<int> sharedPtr2 = make_shared<int>(20);

    cout << "sharedPtr1 : " << *sharedPtr1 << endl;
    cout << "sharedPtr2 : " << *sharedPtr2 << endl;
    cout << "" << endl;

    /**
    shared_ptr 객체에 포인터를 바로 대입하면 컴파일시 에러가 발생합니다.
    왜냐하면 shared_ptr 생성자의 매개 변수는 명시적이어야 하는데, 암시적이기 때문입니다.
    shared_ptr<int> sharedPtr3 = new int(); // (X)

    새로운 shared_ptr객체를 생성하는 방법은  make_shared() 함수를 사용하는 것입니다.
    make_shared() 함수는 객체와 ㅊ마조 카운터를 위한 메모리를 할당합니다.
    shared_ptr<int> sharedPtr3 = make_shared<int>();
    */
    // shared_ptr<int> sharedPtr3 = new int(); // (X)
    shared_ptr<int> sharedPtr3 = make_shared<int>();

    /**
    shared_ptr 객체의 참조 카운터
    여러 shared_ptr 객체는 동일한 포인터를 공유할 수 있습니다.

    공유하는 변수가 늘어날수록 참조 카운터는 증가합니다.
    use_count() 함수를 사용해서 shared_ptr 객체의 참조 카운터를 확인할 수 있습니다.

    참조 카운터가 0이 되면 더 이상 shared_ptr 객체가 가리키는 메모리가 없는 상태입니다.
    자동으로 메모리에서 객체 해제가 됩니다.
    */

    /** 문장을 추가해 줍니다. */
    shared_ptr<int> sharedPtr4;
    /** 변수만 선언했지 객체 생성은 하지 않았습니다. 참조 카운터는 0입니다. */
    cout << "sharedPtr4.use_count() : " << sharedPtr4.use_count() << endl;
    cout << "" << endl;

    sharedPtr4 = make_shared<int>(10);
    /** make_shared() 함수를 사용해서 shared_ptr 객체를 생성하면 참조 카운터는 1이 됩니다. */
    cout << "sharedPtr4.use_count() : " << sharedPtr4.use_count() << endl;
    cout << "" << endl;

    shared_ptr<int> sharedPtr5;
    sharedPtr5 = sharedPtr4;
    /**
    sharedPtr4를 sharedPtr5에 대입했습니다. 참조 카운터가 1 증가하여 2가 되며
    대입한 변수도 동일한 참조 카운터를 가지게 됩니다.
    */
    cout << "sharedPtr4.use_count() : " << sharedPtr4.use_count();
    cout << ", sharedPtr5.use_count() : " << sharedPtr5.use_count() << endl;
    cout << "" << endl;

    /** nullptr를 대입한 변수는 참조 카운터가 0이 되며 같은 포인터를 참조하고 있던 다른 변수는 참조 카운터가 1 감소합니다. */
    sharedPtr4 = nullptr;
    cout << "sharedPtr4.use_count() : " << sharedPtr4.use_count();
    cout << ", sharedPtr5.use_count() : " << sharedPtr5.use_count() << endl;
    cout << "" << endl;

    sharedPtr5.reset();
    /** reset() 함수를 사용하면 nullptr를 대입한 것처럼 참조 카운터는 0이 됩니다. */
    cout << "sharedPtr4.use_count() : " << sharedPtr4.use_count();
    cout << ", sharedPtr5.use_count() : " << sharedPtr5.use_count() << endl;
    cout << "" << endl;

    /**
    shared_ptr 객체가 범위(Scope)를 벗어나면 참조 카운터는 1 감소시킵니다.
    범위는 {} 중괄호를 의미합니다.

    문장을 추가해 줍니다.
    */
    shared_ptr<int> sharedPtr6 = make_shared<int>(10);
    /** make_shared() 함수로 shared_ptr 객체를 생성했으므로 참조카운터는 1이 됩니다. */
    cout << "sharedPtr6.use_count() : " << sharedPtr6.use_count() << endl;
    cout << "" << endl;
    /** 범위를 지정해 줍니다. */
    {
        shared_ptr<int> sharedPtr7 = sharedPtr6;
        /** sharedPtr6를 sharedPtr7에 대입했으므로 참조 카운터는 1 증가하여 2가 됩니다.
        대입한 객체의 참조 카운터도 2가 됩니다.
        */
        cout << "sharedPtr6.use_count() : " << sharedPtr6.use_count();
        cout << ", sharedPtr7.use_count() : " << sharedPtr7.use_count() << endl;
        cout << "" << endl;
    }
    /** sharedPtr7이 범위를 벗어나서 소멸됩니다. sharedPtr6 변수의 참조 카운터는 1 감소해서 1이 됩니다. */
    cout << ", sharedPtr6.use_count() : " << sharedPtr6.use_count() << endl;
    cout << "" << endl;

    /**
    CallByReference (참조에 의한 호출) 사용여부에 따라서 함수에서 참조 카운터의 차이를 알아 봅니다.

    참조에 의한 호출을 사용하지 않는 경우 함수에서 참조 카운터가 1 증가합니다.
    값에 의한 호출입니다. 값에 의한 호출은 배개 변수에 값을 전달할 때 값을 복사해서 전달합니다.
    따라서 참조 카운터가 1 증가합니다.
    */

    /** 텍스트를 위해서 CountSharedPointer라는 이름의 함수를 정의해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    shared_ptr<int> sharedPtr8 = make_shared<int>(10);
    /** make_shared() 함수로 shared_ptr 객체를 생성했으므로 참조 카운터는 1입니다. */
    cout << "sharedPtr8.use_count() : " << sharedPtr8.use_count() << endl;
    cout << "" << endl;
    /** 참조에 의한 호출을 사용하지 않는 경우 함수에서 참조 카운터는 1 증가해서 2가 됩니다. */
    CountSharedPointer(sharedPtr8);
    cout << "" << endl;

    /** 
    함수를 빠져 나오면 어떻게 될까요?
    
    함수를 빠져 나온다는 얘기는 범위를 빠져 나오는 것과 동일하므로 참조 카운터는 1 감소해서 1이 됩니다.
    */
    cout << "sharedPtr8.use_count() : " << sharedPtr8.use_count() << endl;
    cout << "" << endl;

    /**
    참조에 의한 호출을 사용하는 경우 함수에서 참조 카운터는 증가하지 않습니다.

    테스트를 위해서 CountSharedReference라는 이름의 함수를 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
    shared_ptr<int> sharedPtr9 = make_shared<int>(10);
    /** make_shared() 함수로 shared_ptr객체를 생성했으므로 참조 카운터는 1입니다. */
    cout << "sharedPtr9.use_count() : " << sharedPtr9.use_count() << endl;
    cout << "" << endl;

    CountSharedReference(sharedPtr9);
    cout << "" << endl;
    /** 참조에 의한 호출을 사용하는 경우 함수에서 참조 카운터는 증가하지 않습니다. */

    /** 
    함수를 빠져 나오면 어떻게 될까요?
    참조에 의한 호출은 계속 값을 유지하니 참조 카운터가 증가하지 않습니다.
    */
    cout << "sharedPtr9.use_count() : " << sharedPtr9.use_count() << endl;
    cout << "" << endl;

    /**
    move() : move() 함수를 사용해서 shared_ptr변수가 가리키는 포인터를 다른 shared_ptr로 이동할 수 있습니다.
    기본 shared_ptr의 참조 카운터는 0이 됩니다.
    */

}


