#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** StudentScore라는 이름의 구조체를 정의해 보도록 합니다. */
struct StudentScore
{
    /**
    멤버 변수는 변수 이름만 보더라도 멤버 변수인 것을 알 수 있도록 
    변수 이름 앞에 m, m_, _를 붙여줍니다. 
    */
    string mName;
    int m_Math;
    int _Korean;
    int m_English;
    int m_History;
};

/**
클래스에서 자주 사용하게 되는 생성자(Constructor)를 사용하는 방법도 있습니다.
StudentScoreOther라는 이름의 구조체를 정의해 주도록 합니다.
*/
struct StudentScoreOther
{
    string m_Name;
    int m_Math;
    int m_Korean;
    int m_English;
    int m_History;

    /** 생성자 함수를 정의합니다. */
    StudentScoreOther() {}
    /** 
    매개 변수의 개수나 타입이 틀리면 같은 이름의 함수 이름을 쓸 수 있습니다. 
    함수 오버로딩이라고 합니다. 
    : (콜론) 뒤는 초기화 리스트로 초기화를 하는 부분입니다. 
    */
    StudentScoreOther(string name, int math, int korean, int english, int history) 
        : m_Name(name), m_Math(math), m_Korean(korean), m_English(english), m_History(history) {}
};

/**
구조체는 구조체 멤버와 함께 함수에 전달할 수 있으며 반환값으로도 사용 가능합니다.
SetStudentInfo라는 이름의 함수를 정의해 주도록 합니다.
*/
void SetStudentInfo(StudentScoreOther stu)
{
    cout << "name : " << stu.m_Name << ", math : " << stu.m_Math << ", korean : " << stu.m_Korean;
    cout << ", english : " << stu.m_English << ", history : " << stu.m_History << endl;
}

/**
구조체의 중첩

구조체는 다른 구조체를 멤버 변수로 사용 가능합니다.
Student와 School이라는 이름의 구조체를 정의해 주도록 합니다.
*/
struct Student
{
    int m_Number;
    string m_Name;
};

struct School
{
    string m_Location;
    Student m_Student;
};

/** Car라는 이름의 구조체를 정의해 줍니다. */
struct Car
{
    int m_Num;
    double m_Gas;
};

/**
구조체의 포인터를 매개 변수로 받는 Show라는 이름의 함수의 원형을 선언합니다.
C++에서는 함수의 원형을 우선 선언하고 함수를 몸체를 정의합니다.
마우스 더블클릭으로 함수의 이름을 선택하고 Alt + Enter 함수를 정의해 줍니다. 
*/
void Show(Car* car);

/**
구조체의 포인터를 매개 변수로 받는 Show라는 이름의 함수를 정의합니다.
C언어 스타일입니다.
*/
void Show(Car& car)
{
    /**
    이 함수에는 참조자(별칭, 별명)가 전달됩니다. 
    함수 안에서 멤버에 접근할 때, 화살표 연산자(->)가 아닌 닷 연산자(.)를 사용한다는 점이 다릅니다. 
    */
    cout << "차량 변호는 : " << car.m_Num << ", 연료량은 : " << car.m_Gas << endl;
}

/**
구조체 선언에 대해서 정리를 합니다.

서로 다른 자료형들을 한번에 담을 수 있는 것이 바로 구조체(struct)입니다.
Fruit이라는 이름의 구조체를 정의해 주도록 합니다.
*/
struct Fruit
{
    string m_Name;
    int m_Price;
};

int main()
{
    /**
    게임을 만들기 위해서는 C++ 문법의 전체적인 부분에 익숙해져 있어야 합니다. 
    디테일한 부분은 구글검색하면 다 나옵니다. 

    하지만 디테일하면서 자연스럽게 써야 하는 문법적 요소가 있습니다. 
    1. 포인터 (Pointer)
    2. 참조자 (Reference)
    3. 상수   (Constant)
    4. 동적할당 (Dynamic Memory Allocation)
    5. 스마트 포인터 
        . unique_ptr  : 객체의 고유한 소유권을 가지는 스마트 포인터
        . shared_ptr  : 객체간의 공유가 가능한 스마트 포인터
        . weak_ptr    : shared_ptr의 고질적인 문제인 순환참조 문제를 해결한
                 약한 참조의 스마트 포인터
    */

    /** 
    C++ 대규모 업데이트
    C++ 11 (2011년) 스마트 포인터를 지원합니다. 
    C++ 14 (2014년)
    C++ 17 (2017년)
    C++ 20 (2020년)
    */

    /** 
    int타입의 intValue1이라는 이름의 변수를 선언했습니다. 
    3의 값을 intValue1 변수에 대입해서 초기화 햇습니다. 
    */
    int intValue1 = 3;

    /**
    * : 포인터 연산자 (Pointer Operator)
    & : 키보드로는 앰퍼센드, 주소 연산자 (Address Operator)
    int포인터 타입의 intPtr1이라는 이름의 포인터 변수를 선언했습니다. 
    intValue1의 주소값을 intPtr1포인터 변수에 대입함으로써 초기화했습니다. 
    */
    int* intPtr1 = &intValue1;

    /**
    & : 참조자(Reference) 연산자
    int레퍼런스(참조자)타입의 intRef1이라는 참조자 변수를 선언했습니다. 
    intRef1 참조자 변수는 intValue1변수의 별명(별칭)으로 선언했습니다. 
    */
    int& intRef1 = intValue1;

    /**
    * : 역참조 연산자, 포인터 변수가 가리키는 실제 값을 의미합니다. 
    int타입의 intValue2라는 이름의 변수를 선언했습니다. 
    intPtr1포인터 변수가 가리키는 값을 intValue2 변수에 대입함으로써 초기화했습니다. 
    */
    int intValue2 = *intPtr1;

    /**
    학생들의 점수를 저장하기 위한 변수들을 선언해 봅니다. 
    문장을 추가해 줍니다. 
    */
    string name;
    int math;
    int korean;
    int english;
    int history;

    /**
    그룹화 되지 않은 5개의 독립변수가 있습니다. 
    점수에 대한 정보를 함수에 전달하려면 각 변수를 개별적으로 전달해야 합니다. 
    또한, 다른 사람에 대한 정보를 전달하려면 추가된 사람마다 5개의 변수를 추가로 선언해야 합니다. 
    엄청 비효율적입니다. 
    */

    /** 구조체(Struct)는 하나 이상의 변수를 그룹 지어서 새로운 자료형을 정의하는 것입니다. */

    /** StudentScore라는 이름의 구조체를 정의해 보도록 합니다. */

    /** 문장을 추가해 줍니다. */

    /**
    구조체는 사용자가 새롭게 정의하는 자료형이기 때문에 컴파일러에게 알려주지 않고 사용하게 되면 인식을 못합니다. 
    따라서 사용하기 전에 미리 선언해야 합니다. 
    선언만 하면 메모리에 따로 할당이 되지 않습니다. 
    구조체 또한 자료형이기 때문에 선언만 하면 따로 메모리에 할당되지 않습니다. 
    */
    StudentScore studentScore;
    /**
    구조체의 멤버에 접근하기 위해서는 멤버 참조 연산자(. Dot)을 이용합니다. 
    */
    StudentScore stu1;
    stu1.mName = "John";
    stu1.m_Math = 90;
    stu1._Korean = 95;
    stu1.m_English = 85;
    stu1.m_History = 90;

    /** 
    구조체 멤버 변수들도 일반 변수처럼 초기화를 하지 않으면 쓰레기값이 들어가기 때문에 꼭 초기화를 해야 합니다. 
    일일히 진행할 경우 상당히 번거롭기 때문에 초기화 리스트를 통한 초기화 방법이 존재합니다. 
    {} (중괄호)를 사용한 초기화 리스트를 통해 구조체를 초기화 할 수 있습니다. 

    문장을 추가해 줍니다.
    */
    StudentScore stu2 = {"Tom", 90, 80, 95, 75};
    StudentScore stu3 = {"Jane", 95, 80, 90, 90};

    cout << "name : " << stu2.mName << ", math : " << stu2.m_Math << ", korean : " << stu2._Korean;
    cout << ", english : " << stu2.m_English << ", history : " << stu2.m_History << endl;

    cout << "name : " << stu3.mName << ", math : " << stu3.m_Math << ", korean : " << stu3._Korean;
    cout << ", english : " << stu3.m_English << ", history : " << stu3.m_History << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    클래스에서 자주 사용하게 되는 생성자(Constructor)를 사용하는 방법도 있습니다. 
    StudentScoreOther라는 이름의 구조체를 정의해 주도록 합니다. 
    */

    /** 문장을 추가해 줍니다. */
    StudentScoreOther stu4 = StudentScoreOther("John", 90, 80, 95, 75);
    StudentScoreOther stu5 = StudentScoreOther("Smith", 95, 80, 90, 90);

    cout << "name : " << stu4.m_Name << ", math : " << stu4.m_Math << ", korean : " << stu4.m_Korean;
    cout << ", english : " << stu4.m_English << ", history : " << stu4.m_History << endl;

    cout << "name : " << stu5.m_Name << ", math : " << stu5.m_Math << ", korean : " << stu5.m_Korean;
    cout << ", english : " << stu5.m_English << ", history : " << stu5.m_History << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    구조체는 구조체 멤버와 함께 함수에 전달할 수 있으며 반환값으로도 사용 가능합니다. 
    SetStudentInfo라는 이름의 함수를 정의해 주도록 합니다. 
    */

    /** 문장을 추가해 줍니다. */
    SetStudentInfo(stu4);
    SetStudentInfo(stu5);

    cout << "" << endl;
    cout << "" << endl;

    /**
    구조체의 중첩

    구조체는 다른 구조체를 멤버 변수로 사용 가능합니다. 
    Student와 School이라는 이름의 구조체를 정의해 주도록 합니다. 
    */

    /** 문장을 추가해 줍니다. */

    /**
    구조체 안의 구조체를 초기화 리스트를 통해 초기화를 하는 경우 {}를 2번 사용하면 되고
    멤버 변수에 접근할 경우 (. Dot)를 2번 사용하면 됩니다. 
    */
    School school = { "Seoul", {00001, "John"} };
    cout << "location : " << school.m_Location;
    cout << ", student number : " << school.m_Student.m_Number << ", student name : " << school.m_Student.m_Name << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 
    구조체의 크기

    구조체의 크기는 멤버 변수들의 크기를 합친 것으로 결정되지만 항상 그렇지는 않습니다. 
    문장을 추가해 줍니다. 
    sizeof 연산자로 자료형의 무게를 달 수 있습니다. 
    */
    StudentScore stu6;
    cout << "멤버 변수의 크기 : " << sizeof(stu6.mName) << ", " << sizeof(stu6.m_Math) << ", " << sizeof(stu6._Korean);
    cout << ", " << sizeof(stu6.m_English) << ", " << sizeof(stu6.m_History) << endl;
    cout << "" << endl;

    cout << "구조체의 크기 : " << sizeof(stu6) << endl;
    cout << "" << endl;

    /**
    구조체의 초기화 방법은 2가지가 있습니다. 
    1. 선언시 바로 초기화
    2. 선언후 .(Dot)으로 접근해서 초기화
    */
    
    /** 문장을 추가해 줍니다. */

    /**
    1. 선언시 바로 초기화 합니다. 
    */
    StudentScore stu7 = {"Tom", 90, 80, 95, 75};

    cout << "name : " << stu7.mName << ", math : " << stu7.m_Math << ", korean : " << stu7._Korean;
    cout << ", english : " << stu7.m_English << ", history : " << stu7.m_History << endl;
    cout << "" << endl;

    /** 2. 선언후 .(Dot)으로 접근해서 초기화 합니다. */
    StudentScore stu8;
    stu8.mName = "John";
    stu8.m_Math = 90;
    stu8._Korean = 95;
    stu8.m_English = 100;
    stu8.m_History = 95;

    cout << "name : " << stu8.mName << ", math : " << stu8.m_Math << ", korean : " << stu8._Korean;
    cout << ", english : " << stu8.m_English << ", history : " << stu8.m_History << endl;
    cout << "" << endl;

    /**
    구조체 포인터를 매개 변수로 사용하기

    구조체를 매개 변수로 사용하면, 그 구조체의 각 멤버의 값이 복사되어 함수로 넘어갑니다. 
    Call By Value (값에 의한 호출)이라고 합니다. 
    그러나 멤버를 다수 포함하는 구조체를 매개변수로 사용할 경우에는 주의가 필요합니다. 
    함수를 호출할 때마다 많은 수의 멤버가 복사되어야 하므로 함수 호출이 지연될 수 있기 때문입니다. 
    
    따라서 많은 수의 멤버를 포함하는 구조체를 매개 변수로 넘겨야 할 경우
    구조체 포인터를 매개 변수로 넘기는 방법을 고려해야 합니다. 
    Call By Address(주소에 의한 호출)이라고 합니다. 

    구조체 변수의 주소만 함수에 넘기는 것입니다. 
    구조체를 가리키는 포인터를 함수의 매개변수로 사용하면 함수를 호출할 때 포인터만 넘기면 됩니다. 
    이러한 방법을 사용하면 큰 구조체를 매개변수로 사용할 경우에 속도 향상을 볼 수 있습니다. 
    또한 주소가 넘어가므로 함수 안에서 원래 구조체 변수의 멤버 값을 변경할 수 있습니다. 
    이렇게 사용하려면 구조체를 가리키는 포인터를 통해서 각 멤버에 접근하는 방법을 찾아야 합니다. 
    ->(화살표 연산자, Arrow Operator)로 접근합니다. 

    하지만 지금은 참조자를 이용합니다. 
    Call By Reference (참조에 의한 호출)
    */

    /** Car라는 이름의 구조체를 정의해 줍니다. */

    /** 
    구조체의 포인터를 매개 변수로 받는 Show라는 이름의 함수의 원형을 선언합니다. 
    C++에서는 함수의 원형을 우선 선언하고 함수를 몸체를 정의합니다. 
    */

    /** 
    구조체의 포인터를 매개 변수로 받는 Show라는 이름의 함수를 정의합니다. 
    C언어 스타일입니다. 
    */

    /** 문장을 추가해 줍니다. */
    /** 차량 번호와 연료량을 표시합니다. */
    Car car1 = {1234, 5500.142};

    /** 구조체 포인터를 매개변수로 사용하기 */
    Show(&car1);

    /** 구조체 레퍼런스(참조자)를 매개변수로 사용하기*/
    Show(car1);

    /**
    구조체 선언에 대해서 정리를 합니다. 

    서로 다른 자료형들을 한번에 담을 수 있는 것이 바로 구조체(struct)입니다. 
    Fruit이라는 이름의 구조체를 정의해 주도록 합니다. 
    */

    /** 문장을 추가해 줍니다. */
    Fruit fruit1;
    cout << "" << endl;

    Fruit fruit2 = {"apple", 100};
    cout << "" << endl;

    Fruit fruit3 = {"banana"}; // 가격은 0이 됩니다. 
    cout << "" << endl;

    Fruit fruitArray[] = { {"apple", 100}, {"banana", 200} };
    cout << "" << endl;

    /**
    자료형은 값타입과 참조타입이 있습니다. 
    값타입은 변수를 선언하고 값을 주지 않으면 기본값이 들어갑니다. 
    int타입의 기본값은 0입니다. 
    float타입의 기본값은 0.0입니다. 
    bool타입의 기본값은 false(0입니다.)

    string타입의 기본값은 없습니다. string타입은 참조 타입입니다. 
    string타입의 변수를 선언하고 값을 주지 않으면 nullptr입니다. 
    */

}

/** 구조체의 포인터를 매개 변수로 받는 Show라는 이름의 함수를 정의합니다.*/
void Show(Car* car)
{
    /**
    이 함수에는 포인터가 전달됩니다. 
    따라서 멤버에 접근할 때 닷 연산자(.) 대신 화살표 연산자(->)를 사용하고 있습니다. 
    ->(화살표 연산자) 대신에 * (역참조 연산자)와 닷 연산자(.)를 이용해서 접근해도 좋습니다. 
    다만 꼭 포인터에 괄호를 붙여 주어야 합니다. 
    연산자 우선 순위 때문에 괄호를 붙여주지 않을 경우 실행이 되지 않습니다. 
    */
    cout << "차량 번호는 : " << car->m_Num << ", 연료량은 : " << car->m_Gas << endl;
    cout << "차량 변호는 : " << (*car).m_Num << ", 연료량은 : " << (*car).m_Gas << endl;
    // cout << "차량 변호는 : " << *car->m_Num << ", 연료량은 : " << *car->m_Gas << endl; // (X)
}
