#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/**
테스트를 위해서 이름이 같은 함수를 정의합니다.

같은 이름의 함수를 정의하면 에러가 나지만 이름공간으로 함수를 감쏴주면 이름충돌이 없어집니다.
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

/** 테스트로 변수와 함수를 네임스페이스로 감쏴 줍니다. */
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
Melon 네임스페이스의 Init() 함수만 가리킵니다
Init() 함수는 네임스페이스 없이 사용이 가능합니다.
*/
using Melon::Init;


/** 추가를 해 주도록 합니다. */
using namespace Melon; // Melon 이름공간  제약없이 접근이 가능합니다. 


/** 추가를 해 주도록 합니다. */
namespace Mango
{
    void Go()
    {
        cout << "Mango 이름공간의 Go() 함수" << endl;
    }

    void Back()
    {
        cout << "Mango 이름공간의 Back() 함수" << endl;
    }
}

/** 추가해 주도록 합니다. */
namespace Pitch
{
    void Name()
    {
        cout << "Pitch 이름공간의 Name() 함수" << endl;
    }

    void Eat()
    {
        cout << "Pitch 이름공간의 Eat() 함수" << endl;
    }
}

/** 추가해 주도록 합니다. */
namespace Car
{
    void Drive()
    {
        cout << "Car 이름공간 안의 Drive() 함수 호출" << endl;
    }
}

using namespace Car;

void Drive() // 전역 함수입니다. 
{
    cout << "글로벌 이름공간 Drive() 함수 호출" << endl;
}


/**
namespace를 사용하면 프로젝트에 같은 클래스가 존재할 수 있습니다.
회사대 회사로 협업을 하게 되면 같은 이름의 클래스가 존재할 수 있습니다.
충돌 방지를 위해서 프로젝트에 관련된 네임스페이스를 사용하는 것이 좋습니다.

Lion이름공간과  Tiger이름공간을 정의해 주도록 합니다.
*/
namespace Lion
{
    class Animal
    {
    public:
        void SetInfo()
        {
            cout << "Lion" << endl;
        }
    };
}

namespace Tiger
{
    class Animal
    {
    public:
        void SetInfo()
        {
            cout << "Tiger" << endl;
        }
    };
}

/**
namespace를 사용하면 프로젝트에 같은 이름의 구조체가 존재할 수 있습니다.

추가해 주도록 합니다.
*/
namespace Apple
{
    struct Color
    {
        /**
        구조체에서는 접근지정자가 없으면 public입니다.
        클래스에서는 접근지정자가 없으면 private입니다.
        */
        float red;
        float green;
        float blue;
        float alpha;

        void SetColor()
        {
            cout << "Red" << endl;
        }
    };
}

namespace Banana
{
    struct Color
    {
        /**
        구조체에서는 접근지정자가 없으면 public입니다.
        클래스에서는 접근지정자가 없으면 private입니다.
        */
        float red;
        float green;
        float blue;
        float alpha;

        void SetColor()
        {
            cout << "Green" << endl;
        }
    };
}

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
    이렇게 namespace Apple, namespace Banana라는 소속을 만들어서 각 함수를 감쏴게 되면 이름 충돌을 방지할 수 있습니다.

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
        네임스페이스::변수를 "네임스페이스" 없이 사용하게 해 줍니다.

        using 네임스페이스::요소;
    */

    /** 테스트로 변수와 함수를 네임스페이스로 감쏴 줍니다. */

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

    /**
    using Melon::init을 이름공간 Melon 안에 있는 Init 함수를 전역 using 선언을 해 주었습니다.
    이렇게 되면 해당 파일 어디에서든 Melon::Init() 함수를 Melon:: 을 떼고 Init() 라는 이름으로 호출할 수 있습니다.
    Init(); 으로 호출이 가능하며, Melon::Init() 함수로 호출도 가능합니다.
    */

    cout << "" << endl;
    cout << "" << endl;

    /**
    3. 전역 using  지시어 사용한 접근입니다.
    특정 요소만 접근을 풀어주었던 using 선언과 달리
    using 지시어는 해당 이름공간 내부에 있는 모든 요소의 접근을 풀어 줍니다.

    using namespace 네이스페이스이름
    ex) using namespace std;
    */

    /** 추가를 해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */

    /**
    using namespace Melon을 선언했기 때문에 main() 함수 내부에서 처럼 Melon 이름공간 안의 모든 요소에
    "이름공간::" 없이 접근이 가능합니다.
    */
    Init();
    Print();
    cout << "MAX_COUNT : " << MAX_COUNT << endl;


    /**
    4. 함수 내부 using 선언 사용한 접근입니다.

    전역 using 선언과 기능은 같지만, 함수 내부에서 using을 선언하였기 때문에,
    적용되는 범위가 해당 함수 스코프(범위) 내부에서만 접근이 가능합니다.

    함수()
    {
        using 네임스페이스이름::요소
        // 이 아래부터 해당 요소는 네임스페이스 이름 생략이 가능합니다.
    }

    main() 함수에서만 using을 적용하고 싶고, 다른 함수에서는 using을 적용하고 싶지 않을 때 사용합니다.

    */

    /** 추가를 해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    Mango::Go();
    // Go();   // (X)

    using Mango::Go; // 여기 아래부터는 main() 함수 내부에서는 이름공간 없이 사용이 가능합니다. 
    Go();



    /**
    5. 함수 내부 using 지시어 사용한 접근입니다.

    "전역 using 지시어" 와 기능은 같습니다.
    하지만 그 적용 범위를 하나의 함수 내부로 범위를 좁히는 것입니다.

    함수()
    {
        using namespace 네임스페이스이름;
        // 이 아래부터 해당 네임스페이스의 모든 요소는 네임스페이스이름 생략이 가능합니다.
        // 해당 함수 내부로 한정됩니다.
    }
    */

    /** 추가해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    Pitch::Name();
    Pitch::Eat();

    // Name(); // (X)
    // Eat(); // (X)

    using namespace Pitch; // 여기 아래부터는 Pitch 이름공간 없이 접근이 가능합니다. 

    Name();
    Eat();

    cout << "" << endl;
    cout << "" << endl;


    /**
    6. 전역 네임스페이스 접근 방법입니다.

    네임스페이스에 속해 있는 요소에는 한정된 이름 접근 방법에 따라서 "네임스페이스::요소" 를 이용해서
    딱 그 요소에 접근이 가능합니다.
    그럼 전역에 있는 요소를 가리키는 방법은 없을까요?

    "::요소" 를 사용하면 무조건 글로벌 네임스페이스에 접근하게 됩니다.
    */

    /** 추가해 주도록 합니다. */


    /** 문장을 추가해 줍니다. */
    /** 이름공간 안의 함수와 전역 함수의 이름이 같습니다. */
    // Drive(); // (X) // 이름공간이 없으면 함수 이름 충돌로 사용이 불가능합니다. 
    ::Drive();   // 글로벌
    Car::Drive(); // Cat 이름공간 


    /**
    namespace를 사용하면 프로젝트에 같은 클래스가 존재할 수 있습니다.
    회사대 회사로 협업을 하게 되면 같은 이름의 클래스가 존재할 수 있습니다.
    충돌 방지를 위해서 프로젝트에 관련된 네임스페이스를 사용하는 것이 좋습니다.

    Lion이름공간과  Tiger이름공간을 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
    Lion::Animal lion;
    lion.SetInfo();

    Tiger::Animal tiger;
    tiger.SetInfo();

    cout << "" << endl;
    cout << "" << endl;

    /**
    namespace를 사용하면 프로젝트에 같은 이름의 구조체가 존재할 수 있습니다.

    추가해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
    Apple::Color redColor;
    redColor.SetColor();

    Banana::Color greenColor;
    greenColor.SetColor();

    cout << "" << endl;
    cout << "" << endl;

    /** 헷갈릴수 있는 연산자에 대해서 정리합니다. */
    int intValue1 = 10;
    int intValue2 = 20;

    int total = intValue1 * intValue2;  // * : 곱하기 연산자
    int* intPtr1 = &intValue1;          // * : 포인터 연산자
    int intValue3 = *intPtr1;           // * : 역참조 연산자
    /**
    int참조자 타입의 intRef1이라는 이름의 참조자를 선언했습니다.
    intValue1의 별칭으로 선언했습니다.
    */
    int& intRef1 = intValue1;           // & : 참조 연산자
    int* intPtr2 = &intValue2;          // & : 주소 연산자

}
