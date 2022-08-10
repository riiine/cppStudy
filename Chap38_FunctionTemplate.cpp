#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 배열의 사이즈를 가져오기 위한 라이브러리*/
#include <array>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 정수 타입을 매개 변수로 가지고 있는 함수를 정의합니다. */
int AddInt(int value1, int value2)
{
    int value = value1 + value2;
    return value;
}

/** 실수 타입을 매개 변수로 가지고 있는 함수를 정의합니다. */
float AddFloat(float value1, float value2)
{
    float value = value1 + value2;
    return value;
}

/** 더블 타입을 매개 변수로 가지고 있는 함수를 정의합니다. */
double AddDouble(double value1, double value2)
{
    double value = value1 + value2;
    return value;
}

/** 실수 타입을 매개 변수로 가지고 있는 함수를 함수 오버로딩으로 정의해 줍니다. */
float Add(float value1, float value2)
{
    float value = value1 + value2;
    return value;
}

/** 더블 타입을 매개 변수로 가지고 있는 함수를 함수 오버로딩으로 정의해 줍니다. */
double Add(double value1, double value2)
{
    double value = value1 + value2;
    return value;
}

/** 
테스트를 위해서 Add라는 이름의 함수 템플릿을 정의해 줍니다.
여기에서 T는 자료형을 결정짓지 않겠다는 의미로 사용하는 것이기에
컴파일러가 알게 하기 위해서 상단에 template <typename T> 를 붙여야 합니다.
*/
template <typename T>
T Add(T t1, T t2)
{
    return t1 + t2;
}

int main()
{
    /**
    변수의 이름을 정하고, 함수의 이름을 정하고, 클래스의 이름을 정하기 위해서는 많은 고민을 합니다.
    변수나 함수, 클래스의 이름만 보더라도 어떤 의도에서 이름을 지었는지 알 수 있어야 직관적이면서
    가독성 있는 코드를 작성할 수 있기 때문입니다.
    */

    /** 정수 타입을 매개 변수로 가지고 있는 함수를 정의합니다. */

    /** 문장을 추가해 줍니다. */
    int intValue1 = AddInt(1, 2);
    cout << "AddInt : " << intValue1 << endl;
    cout << "" << endl;

    /** 실수 타입을 매개 변수로 가지고 있는 함수를 정의합니다. */

    /** 문장을 추가해 줍니다. */
    float floatValue1 = AddFloat(1.414f, 3.1415f);
    cout << "floatValue1 : " << floatValue1 << endl;
    cout << "" << endl;

    /** 더블 타입을 매개 변수로 가지고 있는 함수를 정의합니다. */

    /** 문장을 추가해 줍니다. */
    double doubleValue1 = AddDouble(1.414, 3.1515);
    cout << "doubleValue1 : " << doubleValue1 << endl;
    cout << "" << endl;

    /**
    함수를 정의하고 있는데, 더하기 함수라면 Add라는 이름의 함수이면 충분할 듯 싶습니다.
    AddInt, AddFloat, AddDouble 가독성이 떨어집니다.

    함수 오버로딩을 이용하면 매개 변수의 타입과 개수가 틀리면 같은 이름의 함수를 정의할 수 있습니다.
    */

    /** 실수 타입을 매개 변수로 가지고 있는 함수를 함수 오버로딩으로 정의해 줍니다. */

    /** 문장을 추가해 줍니다. */
    float floatValue2 = Add(1.414f, 3.1415f);
    cout << "floatValue2 : " << floatValue2 << endl;
    cout << "" << endl;

    /** 더블 타입을 매개 변수로 가지고 있는 함수를 함수 오버로딩으로 정의해 줍니다. */

    /** 문장을 추가해 줍니다. */
    double doubleValue2 = Add(1.414, 3.1415);
    cout << "doubleValue2 : " << doubleValue2 << endl;
    cout << "" << endl;

    /**
    하지만 이게 끝난 것일까요?

    char, long, double, bool 타입으로 함수 오버로딩을 하게 되면 자료형에 따라서
    함수의 개수가 늘게 됩니다.
    엄청 비효율적이면서 관리가 힘들어 집니다.

    방법은 있습니다. 함수템플릿으로 함수를 정의해 주면 됩니다.
    */

    /**
    템플릿(Template)이란?

    함수나 클래스를 개별적으로 다시 작성하지 않아도, 여러 자료형으로 사용할 수 있도록
    만들어 놓은 틀입니다.
    함수 템플릿(Function Template)와 클래스 템플릿(Class Template) 로 나누어 집니다.
    */

    /**
    함수 템플릿은 함수를 만드는 도구를 의미합니다.
    함수를 만드는 도구는 무엇으로 이루어져서 만들지는 정하지 않습니다.
    따라서 함수 템플릿이 만들어 내는 함수의 자료형도 결정되어 있지 않습니다.
    */

    /** 테스트를 위해서 Add라는 이름의 함수 템플릿을 정의해 줍니다. */

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

}
