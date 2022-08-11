#include <iostream>
/**
문자열 관련 라이브러리를 추가해 줍니다.
*/
#include <string>
/**
배열의 사이즈를 가져오기 위한 라이브러리를 추가해 줍니다.
*/
#include <array>
/**
C++ 표준라이브러리(C++ Standard Library) 사용합니다.
*/
using namespace std;

/**
정수 타입을 매개 변수로 가지고 있는 함수를 정의해 봅니다.
*/
int AddInt(int value1, int value2)
{
    int value = value1 + value2;
    return value;
}

/**
실수 타입을 매개 변수로 가지고 있는 함수를 정의해 봅니다.
*/
float AddFloat(float value1, float value2)
{
    float value = value1 + value2;
    return value;
}

/**
더블 타입을 매개 변수로 가지고 있는 함수를 정의해 봅니다.
*/
double AddDouble(double value1, double value2)
{
    double value = value1 + value2;
    return value;
}

/**
실수 타입을 매개 변수로 가지고 있는 함수를 함수 오버로딩으로 정의해 봅니다.
*/
float Add(float value1, float value2)
{
    float value = value1 + value2;
    return value;
}

/**
더블 타입을 매개 변수로 가지고 있는 함수를 함수 오버로딩으로 정의해 봅니다.
*/
double Add(double value1, double value2)
{
    double value = value1 + value2;
    return value;
}

/**
함수 템플릿으로 더하기 함수를 정의해 주도록 합니다.
여기서 T는 자료형을 결정짓지 않겠다는 의미로 사용한 것이기에,
컴파일러가 알게 하기 위해서 상단에 template <typename T>를 붙여야 합니다.
*/
template <typename T>
T Add(T t1, T t2)
{
    return t1 + t2;
}

/**
자료형이 틀린 함수템플릿을 테스트 해 보기 위해서 함수템플릿을 정의해 주도록 합니다.
둘 이상의 형(Type)에 대해 템플릿을 정의해 줄 수 있습니다.
*/
template<typename T1, typename T2>
void ShowInfo(T1 value1, T2 value2)
{
    cout << "T1 : " << value1 << ", T2 : " << value2 << endl;
}

/**
상황에 따라 템플릿 함수의 구성 방법에 예외를 둘 필요가 있는데
이때 사용되는 것이 함수템플릿의 특수화(Specialization of Function Template)입니다.
*/
template<>
void ShowInfo<double, string>(double value1, string value2)
{
    cout << "함수 템플릿의 특수화" << endl;
    cout << "value1 : " << value1 << ", value2 : " << value2 << endl;
}

/** 테스트를 해 보기 위해서 함수 템플릿을 정의해 주도록 합니다. */
template<typename T>
T Max(T value1, T value2)
{
    // return (value1 > value2 ? value1 : value2); // 조금 아쉽습니다. 
    return ((value1 > value2) ? value1 : value2);
}

int main()
{
    /**
변수의 이름을 정하고, 함수의 이름을 정하고, 클래스의 이름을 정하기 위해서는 많은 고민을 합니다.
변수나, 함수, 클래스의 이름만 보더라도 어떤 의도에서 이름을 지었는지 알 수 있어야 직관적이면서
가독성 있는 코드를 작성할 수 있기 때문입니다.
*/

    cout << "정수 타입을 매개 변수로 가지고 있는 함수를 정의해 봅니다. " << endl;
    int intValue1 = AddInt(1, 2);
    cout << "AddInt : " << intValue1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    cout << "실수 타입을 매개 변수로 가지고 있는 함수를 정의해 봅니다." << endl;
    float floatValue1 = AddFloat(1.414f, 3.1415f);
    cout << "AddFloat : " << floatValue1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    cout << "더블 타입을 매개 변수로 가지고 있는 함수를 정의해 봅니다." << endl;
    double doubleValue1 = AddDouble(1.414, 3.1415);
    cout << "AddDouble : " << doubleValue1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    함수를 만들고는 있는데, 더하기 함수인데 Add라는 이름의 함수이면 충분할 듯 싶습니다.
    AddInt, AddFloat, AddString이라는 이름으로 함수를 만들고 있으니 가독성이 떨어집니다.

    함수 오버로딩을 이용하면 매개 변수의 타입과 개수가 틀리면 같은 이름의 함수를 정의할 수 있습니다.
    */

    cout << "실수 타입을 매개 변수로 가지고 있는 함수를 함수 오버로딩으로 정의해 봅니다." << endl;
    float floatValue2 = Add(1.414f, 3.1415f);
    cout << "Add : " << floatValue2 << endl;

    cout << "" << endl;
    cout << "" << endl;

    cout << "더블 타입을 매개 변수로 가지고 있는 함수를 함수 오버로딩으로 정의해 봅니다." << endl;
    double doubleValue2 = Add(1.414, 3.1415);
    cout << "Add : " << doubleValue2 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    하지만 이게 끝난 것일까요?
    char, long, double, bool 타입으로 함수 오버로딩을 하게 되면 자료형에 따라서 함수의 개수가
    늘게 됩니다. 엄청 비효율적이면서 관리가 힘들어 집니다.

    방법은 있습니다. 함수템플릿으로 함수를 정의해 주면 됩니다.
    */

    /**
    템플릿(Template) 이란.

    함수나 클래스를 개별적으로 다시 작성하지 않아도, 여러 자료 형으로 사용할 수 있도록 하게 만들어 놓은 틀입니다.
    함수 템플릿(Function Template)과 클래스 템플릿(Class Template)로 나누어집니다.
    */

    /**
    함수 템플릿(Function Template)은 함수를 만드는 도구를 의미합니다.
    함수를 만드는 도구는 무엇으로 이루어져서 만들지는 정하지 않습니다.
    따라서 함수 템플릿이 만들어 내는 함수의 자료형도 결정되어 있지 않습니다.

    함수 템플릿으로 더하기 함수를 정의해 주도록 합니다.
    이렇게 완성된 함수를 함수 템플릿(Function Template)이라고 합니다.
    */


    /**
    일반함수 호출과 같은 방식으로 수정이 가능합니다.
    이는 전달되는 인자의 자료형을 참조하여 호출 될 함수의 유형을 컴파일러가 결정하기 때문입니다.
    */
    /** 문장을 추가해 줍니다. */
    int intValue3 = 1024;
    int intValue4 = 2048;
    /**
    여기에서 <int> 가 의미하는 바는 다음과 같습니다.
    T를 int로 해서 만들어진 Add 함수를 호출한다는 의미입니다.
    */
    cout << "int : " << Add<int>(intValue3, intValue4) << endl;
    cout << "" << endl;

    float floatValue3 = 1.414f;
    float floatValue4 = 3.1415f;
    cout << "float : " << Add<float>(floatValue3, floatValue4) << endl;
    cout << "" << endl;

    double doubleValue3 = 1.414;
    double doubleValue4 = 3.1415;
    cout << "double : " << Add<double>(doubleValue3, doubleValue4) << endl;
    cout << "" << endl;

    string stringValue3 = "Tom ";
    string stringValue4 = "Jane";
    cout << "string : " << Add<string>(stringValue3, stringValue4);
    cout << "" << endl;

    /**
    자료형이 틀린 함수템플릿을 테스트 해 보기 위해서 함수템플릿을 정의해 주도록 합니다.
    둘 이상의 형(Type)에 대해 템플릿을 정의해 줄 수 있습니다.
    */

    /** 문장을 추가해 줍니다. */
    ShowInfo<int, string>(10, "John");
    ShowInfo<string, float>("Jane", 3.1415f);
    ShowInfo<string, string>("Tom", "James");
    ShowInfo<double, float>(1.414, 3.1415f);

    cout << "" << endl;
    cout << "" << endl;

    /**
    상황에 따라 템플릿 함수의 구성 방법에 예외를 둘 필요가 있는데
    이때 사용되는 것이 함수템플릿의 특수화(Specialization of Function Template)입니다.
    */

    /** 문장을 추가해 줍니다. */
    ShowInfo<double, string>(1.414, "James");
    ShowInfo<double, string>(3.1415, "Smith");

    cout << "" << endl;
    cout << "" << endl;

    /** 테스트를 해 보기 위해서 함수 템플릿을 정의해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    int intValue5 = Max(1024, 2048);
    cout << "intValue5 : " << intValue5 << endl;
    cout << "" << endl;

    float floatValue5 = Max(1.414f, 3.1415f);
    cout << "floatValue5 : " << floatValue5 << endl;
    cout << "" << endl;

    /** 문자열의 경우에는 결과에 의미가 없습니다. */
    string stringValue5 = Max("Tom", "Jane");
    cout << "stringValue5 : " << stringValue5 << endl;
    cout << "" << endl;




}
