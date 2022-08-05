#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 스마트 포인터 관련 라이브러리*/
#include <memory>
/** 벡터 컨테이너 관련 라이브러리*/
#include <vector>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 테스트를 위해서 Cat이라는 이름의 클래스를 정의해 주도록 합니다. */
class Cat
{
public:
    Cat()
    {
        cout << "Cat 생성자" << endl;
    }

    ~Cat()
    {
        cout << "Cat 소멸자" << endl;
    }
};

/** 테스트를 위해서 Tiger라는 이름의 클래스를 정의해 주도록 합니다. */
class Tiger
{
public:
    Tiger()
    {
        cout << "Tiger 생성자" << endl;
    }

    ~Tiger()
    {
        cout << "Tiger 소멸자" << endl;
    }
};

/**
서로 참조하는 shared_ptr에 대해서 알아봅니다.

shared_ptr는 참조 카운터가 0이 되면 가리키는 객체를 메모리에서 해제 시킵니다.
그런데, 객체들을 더 이상 참조하지 않는 상황에도 불구하고 참조 카운터가 절대로 0이 될 수 없는 상황이 있습니다.

테스트를 위해서 Lion이라는 이름의 클래스를 정의해 주도록 합니다.
*/
class Lion
{
private:
    shared_ptr<Lion> m_Lion;
public:
    Lion()
    {
        cout << "Lion 생성자" << endl;
    }

    ~Lion()
    {
        cout << "Lion 소멸자" << endl;
    }

    void Show(shared_ptr<Lion> lion)
    {
        m_Lion = lion;
    }
};

int main()
{
    /**
    클래스가 메모리에 올라가면 객체(인스턴스, Instance)가 됩니다.

    Variable(변수), Field(필드)
    Function(함수), Method(메쏘드)

    매개변수(파라미터, Parameter), 인수(Argument)
    */

    /**
    대부분의 경우 하나의 자원은 한 개의 스마트 포인터에 의해 소유되는 것이 바람직하고
    나머지 접근은 그냥 일반 포인터로 처리하면 됩니다.

    때에 따라서는 여러 개의 스마트 포인터가 하나의 객체를 같이 소유해야 하는 경우가 발생합니다.
    대 부분의 경우입니다. 여러개의 객체에서 하나의 자원을 공유해서 사용할 때입니다.
    후에 자원을 해제하기 위해서는 이 자원을 사용하는 모든 객체들이 소멸되야 하는데
    이 자원 역시 어느 시간에 객체 해제를 해야 하는지 분명하지 않습니다.

    우리가 필요한 것은 특정 자원을 몇 개의 객체에서 가리키는 지를 추적한 다음에 그 수가 0이
    되어야만 비로소 해제를 시켜주는 포인터가 필요합니다.

    shared_ptr입니다. 객체간의 공유가 가능한 스마트 포인터

    스마트 포인터가 100퍼센트 메모리 관리를 해 주지는 않습니다.
    특정 함수에서 내가 직접 메모리 관리를 해 주어야 하는 경우도 있습니다.
    */

    /**
    shared_ptr

    객체의 유일한 소유권을 가지는 unique_ptr와는 다른게
    shared_ptr로 객체를 가리킬 경우, 다른 shared_ptr 역시 그 객체를 가리킬 수가 있습니다.
    */

    /** 테스트를 위해서 Cat이라는 이름의 클래스를 정의해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    shared_ptr<Cat> sharedPtr1(new Cat());

    /** 생성된 sharedPtr2 객체 연시 생성된 객체 Cat을 가리킵니다. */
    shared_ptr<Cat> sharedPtr2(sharedPtr1);
    cout << "" << endl;

    /** 반면에 unique_ptr의 경우에는 */
    unique_ptr<Cat> uniquePtr1(new Cat());

    /**
    unique_ptr는 shared_ptr처럼 객체 간의 공유가 안되는 유일한 소유권을 가지는
    스마트 포인터이기 때문에 에러가 생깁니다.
    uniquePtr1과 uniquePtr2의 경우 같이 동일한 객체인 Cat을 가리키지만
    uniquePtr1의 경우 유일한 소유권만 인정되므로 컴파일 에러가 생깁니다.
    */
    // unique_ptr<Cat> uniquePtr2(uniquePtr1); //(X)

    /**
    shared_ptr들은 같은 객체를 가리킬 수가 있습니다.
    이를 위해서는 몇 개의 shared_ptr들이 원래 객체를 가리키고 있는지 알아야 합니다.
    참조 카운터(Reference Counter)라고 합니다.
    참조 카운터가 0이 되어야 가리키고 있는 객체를 해제할 수가 있습니다.
    */

    /** 테스트를 위해서 Tiger라는 이름의 클래스를 정의해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    vector<shared_ptr<Tiger>> vector1;

    /**
    각기 다른 Tiger 객체를 생성해서 vector 컨테이너에 넣어 주었습니다.
    shared_ptr 테스트가 되지 않습니다. 주석처리 해 주세요.
    */
    //vector1.push_back(shared_ptr<Tiger>(new Tiger()));
    //cout << "vector1[0].use_count() : " << vector1[0].use_count() << endl;
    //vector1.push_back(shared_ptr<Tiger>(new Tiger()));
    //cout << "vector1[0].use_count() : " << vector1[0].use_count() << endl;
    //vector1.push_back(shared_ptr<Tiger>(new Tiger()));
    //cout << "vector1[0].use_count() : " << vector1[0].use_count() << endl;
    cout << "" << endl;

    /**
    같은 객체를 가리키려면 어떻게 해야 할까요?

    문장을 추가해 줍니다.
    */

    /**
    shared_ptr를 요소를 가지는 벡터 컨테이너인 vector1을 정의한 후에
    vector1[0], vector1[1], vector1[2] 가 모두 같은 Tiger 객체를
    가리키도록 shared_ptr 객체를 생성했습니다.
    */
    vector1.push_back(shared_ptr<Tiger>(new Tiger())); // vector1[0]
    cout << "vector1[0].use_count() : " << vector1[0].use_count() << endl;

    vector1.push_back(shared_ptr<Tiger>(vector1[0])); // vector1[1]
    cout << "vector1[0].use_count() : " << vector1[0].use_count() << endl;

    vector1.push_back(shared_ptr<Tiger>(vector1[1])); // vector1[2]
    cout << "vector1[0].use_count() : " << vector1[0].use_count() << endl;

    cout << "" << endl;
    cout << "" << endl;

    cout << "단계로 확인해 봅니다. " << endl;
    cout << "vector1[0].use_count() : " << vector1[0].use_count() << endl; // 참조 카운터 3
    cout << "" << endl;

    cout << "벡터 컨테이너의 0번째 요소를 소멸 시킵니다. " << endl;
    vector1.erase(vector1.begin());
    cout << "vector1[0].use_count() : " << vector1[0].use_count() << endl; // 참조 카운터 2
    cout << "" << endl;

    cout << "벡터 컨테이너의 다음 요소를 소멸 시킵니다. " << endl;
    vector1.erase(vector1.begin());
    cout << "vector1[0].use_count() : " << vector1[0].use_count() << endl; // 참조 카운터 1

    cout << "벡터 컨테이너의 마지막 요소를 소멸 시킵니다. " << endl;
    vector1.erase(vector1.begin());
    cout << "" << endl;

    cout << "참조 카운터가 0이 되었으므로 객체 해제 됩니다. " << endl;
    // cout << "vector1[0].use_count() : " << vector1[0].use_count() << endl; // (X) 

    cout << "" << endl;

    /**
    shared_ptr의 참조 카운터는 use_count() 함수로 알 수 있습니다.

    문장을 추가해 줍니다.
    */

    /** 객체를 생성하면 참조 카운터는 1입니다. */
    shared_ptr<Tiger> sharedPtr3(new Tiger());
    cout << "sharedPtr3.use_count() : " << sharedPtr3.use_count() << endl;
    cout << "" << endl;

    /**
    shared_ptr 역시 생성된 객체 Tiger를 가리킵니다.

    shared_ptr 객체를 다른 shared_ptr 객체에 대입했습니다. 참조 카운터는 1 증가해서 2가 됩니다.
    */
    shared_ptr<Tiger> sharedPtr4(sharedPtr3);

    cout << "sharedPtr3.use_count() : " << sharedPtr3.use_count();
    cout << ", sharedPtr4.use_count() : " << sharedPtr4.use_count() << endl;
    cout << "" << endl;

    /**
    몇가지 방법으로 shared_ptr객체를 생성할 수 있습니다.

    종전에는 다음과 같은 방법으로 shared_ptr객체를 생성했습니다.
    shared_ptr<Tiger> sharedPtr3(new Tiger());
    */

    /**
    하지만 좋은 shared_ptr 객체 생성 방법이 아닙니다.
    왜냐 하면 Tiger객체를 생성하기 위해서 동적 할당이 한번 일어나야 하고
    그 다음 shared_ptr 의 제어 블록 역시 동적으로 할당 해야 하기 때문입니다.
    두 번의 동적 할당이 발생해야 합니다. 비효율적입니다.

    동적 할당은 상당히 비싼 연산입니다. 어차피 동적 할당을 두 번 할 것이라는 것을 알고 있다면
    아예 두 개 합친 크기로 한 번 할당 하는 것이 빠릅니다.
    make_shared() 함수로 객체를 생성해야 하는 이유입니다.
    */

    /** 문장을 추가해 줍니다. */

    /**
    make_shared() 함수는 Tiger의 생성자의 매개 변수를 받아서
    1.객체 Tiger와
    2.shared_ptr의 제어블록 까지
    한번에 동적할당을 한 후에 생성된 shared_ptr 객체를 반환합니다.
    */
    shared_ptr<Tiger> sharedPtr5 = make_shared<Tiger>();
    cout << "" << endl;

    /**
    shared_ptr 객체 생성시 주의할 점입니다.

    문장을 추가해 줍니다.
    */
    Tiger* tiger1 = new Tiger();
    shared_ptr<Tiger> sharedPtr6(tiger1);
    cout << "sharedPtr6.use_count() : " << sharedPtr6.use_count() << endl;
    cout << "" << endl;

    /**
    컴파일 에러는 없지만 런타임 에러는 생깁니다.
    왜 생길까요?
    shared_ptr로 메모리 관리를 하기 위해서는 shared_ptr로 객체를 가리켜야만 합니다.

    new 연산자로 객체를 동적 생성했다가 shared_ptr로 가리키고 있습니다.
    잘못된 방식입니다.

    다음과 같이 하셔야 합니다.
    shared_ptr<Tiger> sharedPtr3(new Tiger());
    shared_ptr<Tiger> sharedPtr4(sharedPtr3);
    */
    //shared_ptr<Tiger> sharedPtr7(tiger1);
    //cout << "sharedPtr7.use_count() : " << sharedPtr7.use_count() << endl;
    cout << "" << endl;

    /**
    서로 참조하는 shared_ptr에 대해서 알아봅니다.

    shared_ptr는 참조 카운터가 0이 되면 가리키는 객체를 메모리에서 해제 시킵니다.
    그런데, 객체들을 더 이상 참조하지 않는 상황에도 불구하고 참조 카운터가 절대로 0이 될 수 없는 상황이 있습니다.

    테스트를 위해서 Lion이라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
    shared_ptr<Lion> sharedPtr8 = make_shared<Lion>();
    shared_ptr<Lion> sharedPtr9 = make_shared<Lion>();

    /** 상대방을 참조합니다. */
    sharedPtr8->Show(sharedPtr9);
    sharedPtr9->Show(sharedPtr8);

    /**
    소멸자가 호출이 안됩니다.

    순환참조의 문제입니다.

    이 문제는 shared_ptr 자체가 가지고 잇는 문제입니다. 따라서 shared_ptr로는 해결할 수가 없습니다.
    이러한 순환참조 문제를 해결한 것이 weak_ptr입니다.
    */
    cout << "" << endl;
}