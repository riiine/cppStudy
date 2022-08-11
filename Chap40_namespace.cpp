#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 
테스트를 위해서 이름이 같은 함수를 정의합니다. 

같은 이름의 함수를 정의하면 에러가 나지만 이름공간으로 함수를 감싸주면 이름충돌이 없어집니다.
*/
namespace Apple
{
    void SetInfo()
    {
        cout << "Apple namespace" << endl;
    }
}

namespace Banana
{
    void SetInfo()
    {
        cout << "Banana namespace" << endl;
    }
}

/** 테스트로 변수와 함수를 네임스페이스로 감싸줍니다. */
namespace Melon
{
    int MAX_COUNT = 10;

    void Init()
    {
        cout << "Melon 이름공간의 Init() 함수" << endl;
    }

    void Print()
    {
        cout << "Melon 이름공간의 Print() 함수" << endl;
    }
}

/** 
Melon 네임스페이스의 Init() 함수만 가리킵니다.
Init() 함수는 네임스페이스 없이 사용이 가능합니다.
*/
using Melon::Init;

int main()
{
    /** 이번 시간에는 namespace(이름 공간)에 대해서 알아 봅니다. */

    /**
    같은 프로젝트에서 클래스 이름이나 함수 이름, 구조체 이름, 변수 등이 같은 이름을 쓸 수 있을까요?
    이런 경우 함수의 이름이나 구조체의 이름 그리고 변수의 이름이 같다고 하면 이름 충돌이 일어나서
    오류가 발생합니다.

    이런 이름 충돌이 발생하지 않게 하기 위해 만들어진 것이 namespace(이름 공간)의 개념입니다.
    */

    /**
    namespace는 함수나 구조체, 변수 이름 등의 소속을 정해주는 것입니다.
    소속을 정해 주어서 그 소속에 혹한 함수, 그 소속에 속한 구조체 등을 딱 지정해서
    헷갈리지 않게 하는 것입니다.
    :: (범위지정자)를 사용합니다.
    */

    /** 테스트를 위해서 이름이 같은 함수를 정의합니다. */

    /**
    이렇게 namespace Apple, namespace Banana라는 소속을 만들어서 각 함수를 감싸게 되면 이름 충돌을 방지할 수 있습니다.

    문장을 추가해 줍니다.
    */
    Apple::SetInfo();
    Banana::SetInfo();

    cout << "" << endl;
    cout << "" << endl;

    /**
    C++에서 namespace 요소 접근 방법은 5가지가 있습니다.

    1. 한정된 이름을 사용한 접근입니다.
        네임스페이스::이름

        이름 충돌을 피할 수 있으며 어디에 속해있는 함수, 변수, 클래스 인지를 명확하게 알 수 있습니다.

    2. 전역 using 선언 사용한 접근입니다.
        using 선언은 namespace 소속에 있는 변수 하나, 함수 하나 이렇게 하나씩을 지정해서
        네임스페이스::변수를 "네임스페이스" 없이 사용하게 해줍니다.

        using 네임스페이스::요소;
    */

    /** 테스트로 변수와 함수를 네임스페이스로 감싸줍니다. */

    /** 문장을 추가해 줍니다. */
    /** 네임스페이스 없이 사용이 가능합니다. */
    Init();
    /** 네임스페이스와 같이 사용이 가능합니다. */
    Melon::Init();

    Melon::Print();
    cout << "Melon::MAX_COUNT : " << Melon::MAX_COUNT << endl;
    /** 네임스페이스 없이 호출이 불가능합니다. */
    // Print(); // (X)
    // cout << "MAX_COUNT : " << MAX_COUNT << endl; // (X)

    cout << "" << endl;
    cout << "" << endl;
}
