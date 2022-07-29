#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 테스트를 위해서 Point1이라는 이름의 클래스를 정의해 줍니다. */
class Point1
{
private:
    int m_xPosition;
    int m_yPosition;
public:
    /**
    생성자의 목적은 객체를 생성하면서 멤버 변수의 초기화를 담당합니다.
    : 콜론뒤의 내용이 초기화 리스트로 멤버 변수를 초기화 하는 과정입니다.
    */
    Point1(int x, int y) : m_xPosition(x), m_yPosition(y) {}
    /** ShowPosition라는 이름의 함수의 원형을 선언합니다. */
    void ShowPosition();
};

/** ShowPosition라는 이름의 함수를 정의합니다. */
void Point1::ShowPosition()
{
    cout << "m_xPosition : " << m_xPosition << ", m_yPosition : " << m_yPosition << endl;
}

/**
연산자 오버로딩을 사용해 봅니다.

테스트를 위해서 Point2라는 이름의 클래스를 정의해 주도록 합니다.
*/
class Point2
{
private:
    int m_xPosition;
    int m_yPosition;
public:
    /**
    생성자 함수를 정의합니다.
    : 콜론 뒤의 초기화 리스트로 객체를 생성하면서 멤버 변수의 값을 초기화 합니다.
    */
    Point2(int x, int y) : m_xPosition(x), m_yPosition(y) {}
    /** ShowPosition이라는 이름의 함수의 원형을 선언합니다. */
    void ShowPosition();
    /** Add라는 이름의 함수의 원형을 선언합니다. */
    Point2 Add(Point2& position);
    /** 덧셈 연산자 오버로딩 함수의 원형을 선언합니다. */
    Point2 operator+(Point2& position);
};

/** ShowPosition이라는 이름의 함수를 정의합니다. */
void Point2::ShowPosition()
{
    cout << "m_xPosition : " << m_xPosition << ", m_yPosition : " << m_yPosition << endl;
}

/** Add라는 이름의 함수를 정의합니다. */
Point2 Point2::Add(Point2& position)
{
    Point2 pt(m_xPosition + position.m_xPosition, m_yPosition + position.m_yPosition);
    return pt;
}

/** 덧셈 연산자 오버로딩 함수를 정의합니다. */
Point2 Point2::operator+(Point2& position)
{
    Point2 pt(m_xPosition + position.m_xPosition, m_yPosition + position.m_yPosition);
    return pt;
}

/** 2. 비교 연산자 오버로딩 (==, !=)

테스트를 위해서 Point3라는 이름의 클래스를 정의해 주도록 합니다.
*/
class Point3
{
private:
    int m_xPosition;
    int m_yPosition;
public:
    Point3(int x, int y) : m_xPosition(x), m_yPosition(y) {}
    /** ShowPosition이라는 이름의 함수의 원형을 선언합니다. */
    void ShowPosition();

    /** 더하기 함수의 원형을 선언합니다. */
    Point3 Add(Point3& position);
    /** 같은지 함수의 원형을 선언합니다. */
    bool EqualTo(Point3& positon);
    /** 다른지 함수의 원형을 선언합니다.*/
    bool NotEqualTo(Point3& position);
    /** 더하기 연산자 오버로딩 함수의 원형을 선언합니다. */
    Point3 operator+(Point3& position);
    /** 같은지 연산자 오버로딩 함수의 원형을 선언합니다. */
    bool operator==(Point3& position);
    /** 다른지 연산자 오버로딩 함수의 원형을 선언합니다. */
    bool operator!=(Point3& position);
};

/** ShowPosition이라는 이름의 함수를 정의합니다. */
void Point3::ShowPosition()
{
    cout << "m_xPosition : " << m_xPosition << ", m_yPosition : " << m_yPosition << endl;
}

/** 더하기 함수를 정의합니다. */
Point3 Point3::Add(Point3& position)
{
    Point3 pt(m_xPosition + position.m_xPosition, m_yPosition + position.m_yPosition);
    return pt;
}

/** 같은지 함수를 정의합니다. */
bool Point3::EqualTo(Point3& positon)
{
    return ((m_xPosition == positon.m_xPosition) && (m_yPosition == positon.m_yPosition));
}

/** 다른지 함수를 정의합니다. */
bool Point3::NotEqualTo(Point3& position)
{
    /** this포인터 변수가 가리키는 값은 Point3객체의 멤버 변수와 멤버 함수입니다. */
    return !(*this == position);
}

/** 더하기 연산자 오버로딩 함수를 정의합니다. */
Point3 Point3::operator+(Point3& position)
{
    Point3 pt(m_xPosition + position.m_xPosition, m_yPosition + position.m_yPosition);
    return pt;
}

/** 같은지 연산자 오버로딩 함수를 정의합니다. */
bool Point3::operator==(Point3& position)
{
    return ((m_xPosition == position.m_xPosition) && (m_yPosition == position.m_yPosition));
}

bool Point3::operator!=(Point3& position)
{
    /** this포인터 변수가 가리키는 값은 Point3객체의 멤버 변수와 멤버 함수입니다. */
    return !(*this == position);
}

/**
3. 증감 연산자 오버로딩

테스트를 위해서 Point4라는 이름의 클래스를 정의해 주도록 합니다.
*/
class Point4
{
private:
    int m_xPosition;
    int m_yPosition;
public:
    Point4(int x, int y) : m_xPosition(x), m_yPosition(y) {}
    void ShowPosition();

    Point4 Add(Point4& position);
    Point4 Subtract(Point4& position);
    Point4 Multiply(Point4& position);
    Point4 Divide(Point4& position);
    Point4 Remainder(Point4& position);
    bool EqualTo(Point4& position);
    bool NotEqualTo(Point4& position);
    Point4 IncreaseFront();  // ++Point4
    Point4 IncreaseBack(int);// Point4++
    Point4 DecreaseFront();  // --Point4
    Point4 DecreaseBack(int);// Point4--

    Point4 operator+(Point4& position);
    Point4 operator-(Point4& position);
    Point4 operator*(Point4& position);
    Point4 operator/(Point4& position);
    Point4 operator%(Point4& position);
    bool operator==(Point4& position);
    bool operator!=(Point4& position);
    Point4 operator++();    // ++Point4
    Point4 operator++(int); // Point4++
    Point4 operator--();    // --Point4
    Point4 operator--(int); // Point--
};


void Point4::ShowPosition()
{
    cout << "m_xPosition : " << m_xPosition << ", m_yPosition : " << m_yPosition << endl;
}

Point4 Point4::Add(Point4& position)
{
    Point4 pt(m_xPosition + position.m_xPosition, m_yPosition + position.m_yPosition);
    return pt;
}

Point4 Point4::Subtract(Point4& position)
{
    Point4 pt(m_xPosition - position.m_xPosition, m_yPosition - position.m_yPosition);
    return pt;
}

Point4 Point4::Multiply(Point4& position)
{
    Point4 pt(m_xPosition * position.m_xPosition, m_yPosition * position.m_yPosition);
    return pt;
}

Point4 Point4::Divide(Point4& position)
{
    Point4 pt(m_xPosition / position.m_xPosition, m_yPosition / position.m_yPosition);
    return pt;
}

Point4 Point4::Remainder(Point4& position)
{
    Point4 pt(m_xPosition % position.m_xPosition, m_yPosition % position.m_yPosition);
    return pt;
}

bool Point4::EqualTo(Point4& position)
{
    return false;
}

bool Point4::NotEqualTo(Point4& position)
{
    return false;
}

Point4 Point4::IncreaseFront()
{
    ++m_xPosition;
    ++m_yPosition;
    return *this;
}

Point4 Point4::IncreaseBack(int)
{
    Point4 pt = *this;
    m_xPosition++;
    m_yPosition++;
    return pt;
}

Point4 Point4::DecreaseFront()
{
    --m_xPosition;
    --m_yPosition;
    return *this;
}

Point4 Point4::DecreaseBack(int)
{
    Point4 pt = *this;
    m_xPosition--;
    m_yPosition--;
    return pt;
}

Point4 Point4::operator+(Point4& position)
{
    Point4 pt(m_xPosition + position.m_xPosition, m_yPosition + position.m_yPosition);
    return pt;
}

Point4 Point4::operator-(Point4& position)
{
    Point4 pt(m_xPosition - position.m_xPosition, m_yPosition - position.m_yPosition);
    return pt;
}

Point4 Point4::operator*(Point4& position)
{
    Point4 pt(m_xPosition * position.m_xPosition, m_yPosition * position.m_yPosition);
    return pt;
}

Point4 Point4::operator/(Point4& position)
{
    Point4 pt(m_xPosition / position.m_xPosition, m_yPosition / position.m_yPosition);
    return pt;
}

Point4 Point4::operator%(Point4& position)
{
    Point4 pt(m_xPosition % position.m_xPosition, m_yPosition % position.m_yPosition);
    return pt;
}

bool Point4::operator==(Point4& position)
{
    return false;
}

bool Point4::operator!=(Point4& position)
{
    return false;
}

Point4 Point4::operator++()
{
    ++m_xPosition;
    ++m_yPosition;
    return *this;
}

Point4 Point4::operator++(int)
{
    Point4 pt = *this;
    m_xPosition++;
    m_yPosition++;
    return pt;
}

Point4 Point4::operator--()
{
    --m_xPosition;
    --m_yPosition;
    return *this;
}

Point4 Point4::operator--(int)
{
    Point4 pt = *this;
    m_xPosition--;
    m_yPosition--;
    return pt;
}

/**
멤버 함수에 의한 오버로딩을 알아보도록 합니다.

테스트를 위해서 Point5라는 이름의 클래스를 정의해 주도록 합니다.
*/
class Point5
{
private:
    int m_xPosition;
    int m_yPosition;
public:
    /**
    생성자 함수를 정의합니다.
    (int x = 0, int y = 0) : 디폴트 매개 변수입니다.
    만일 매개 변수에 값을 주지 않을 경우 기본값으로 적용됩니다.
    */
    Point5(int x = 0, int y = 0) : m_xPosition(x), m_yPosition(y) {}
    /** ShowPosition 함수의 원형을 선언합니다. */
    void ShowPosition();

    /** 더하기 연산자 오버로딩 멤버 함수의 원형을 선언합니다. */
    Point5 operator+(const Point5& position);
};

/** ShowPosition 함수를 정의합니다. */
void Point5::ShowPosition()
{
    cout << "m_xPosition : " << m_xPosition << ", m_yPosition : " << m_yPosition << endl;
}

/** 더하기 연산자 오버로딩 멤버 함수를 정의합니다. */
Point5 Point5::operator+(const Point5& position)
{
    Point5 pt(m_xPosition + position.m_xPosition, m_yPosition + position.m_yPosition);
    return pt;
}

/**
전역 함수에 의한 오버로딩에 대해서 알아 봅니다.

테스트를 위해서 Point6라는 이름의 클래스를 정의해 주도록 합니다.
*/
class Point6
{
private:
    // int m_xPosition, m_yPosition; // 같은 타입이라면 ,(쉼표)를 이용해서 변수를 나열할 수 있습니다. 안좋은 습관입니다. 
    int m_xPosition;
    int m_yPosition;
public:
    Point6(int x = 0, int y = 0) : m_xPosition(x), m_yPosition(y) {}
    void ShowPosition();

    /**
    전역함수를 friend 선언을 해 주고 있습니다.
    friend 선언을 해줌으로써 operator+ 함수를 Point6 객체의 private 멤버에 직접 접근이 가능합니다.
    friend 선언은 연산자 오버로딩에 주로 사용합니다.
    */
    friend Point6 operator+(const Point6& p1, const Point6& p2);
};

/** 전역 공간, main() 함수 밖입니다. 클래스 밖입니다. */
/** 소속이 정해져 있는 멤버 함수입니다. */
void Point6::ShowPosition()
{
    cout << "m_xPosition : " << m_xPosition << ", m_yPosition : " << m_yPosition << endl;
}
/** 따로 소속이 정해져 있지 않은 전역 함수입니다. */
Point6 operator+(const Point6& p1, const Point6& p2)
{
    /**
    멤버 함수에서는 private 접근 지정자 안에 멤버 변수에 접근이 가능합니다.
    전역 함수에서는 private 접근 지정자 안에 멤버 변수에 접근이 불가능 합니다. 하지만 friend 선언을 해주면
    전역 함수에서도 private 접근 지정자 안에 멤버 변수에 직접 접근이 가능합니다.
    */
    Point6 pt(p1.m_xPosition + p2.m_xPosition, p1.m_yPosition + p2.m_yPosition);
    return pt;
}

int main()
{
    /**
    연산자 오버로딩(Operator Overloading)이란?

    1. 함수의 오버로딩 : 동일한 이름의 함수에 매개변수의 개수, 타입등을 다르게 하여
        여러개를 정의할 수 있습니다.
    2. 연산자의 오버로딩 : 하나의 연산자를 다른 기능도 사용할 수 있도록 사용자 정의
        클래스를 사용합니다.
    3. 함수템플릿

    다름과 같은 연산자 이외에 모든 연산자는 재정의가 가능합니다.

    :: 범위 지정 연산자
    . 멤버 참조 연산자
    * 멤버 포인터 연산자
    ? 삼항 연산자
    # 전처리기 변환
    ## 전처리기 연결

    멤버 함수로만 오버로딩 가능한 연산자로 존재합니다.

    = 대입 연산자
    () 함수 호출
    -> 포인터 멤버 접근 연산자
    [] 배열 인덱스 연산자
    */

    /**
    연산자 오버로딩 규칙

    1. 기본 데이터 타입만을 다루는 연산자 오버로딩은 할 수 없습니다.
        피 연산자 중 하나는 반드시 사용자 정의 타입이어야 합니다.
        int + int는 오버 로딩을 통해서 다른 결과를 낼 수가 없습니다.
    2.  비정적 클래스 멤버 함수 또는 전역 함수이어야 연산자 오버로딩이 가능합니다.
    3. 단항 연산자 또는 이항 연산자로 오버로딩 할 수 있습니다.
    4. 오버 로딩된 연산자는 디폴트 매개변수는 사용 불가능합니다.

    반환타입 operator오버로딩할 연산자(매개변수1, 매개변수2, ...) { 연산자 기능}
    */

    /** 연산자는 산술 연산자(+, -, *, / , %), 비교 연산자(==, !=), 증감 연산자(++, --)*/

    /** 1 산술 연산자(+, -, *, /, %) 오버로딩에 대해서 알아 봅니다. */

    /** 테스트를 위해서 Point1이라는 이름의 클래스를 정의해 줍니다. */

    /** 문장을 추가해 줍니다. */
    Point1 a1(10, 20);
    Point1 b1(20, 20);
    a1.ShowPosition();
    b1.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    /**
    오류가 나는 것을 볼 수 있습니다.

    직교좌표계의 x, y값의 점을 가지는 객체를 생성한다고 가정합니다.
    이때 두 좌표의 값은 (x1, y1) + (x2, y2) = (x1 + x2, y1 + y2)가 되어야 합니다.
    객체간의 덧셈이 정의되어 있지 않으므로 에러가 발생합니다.
    연산자 오버로딩을 통해 Point1객체에 대해 좌표끼리 덧셈을 x좌표는 x좌표끼리, y좌표는 y좌표끼리 더해서
    Point1 객체를 반환하도록 해 주면 됩니다.
    따라서 a1 + b1은 a1.operator+(b1)와 같은 함수 호출이 되어서 객체간에 덧셈의 결과가 됩니다.
    */
    // Point1 c1 = a1 + b1; // (X)
    // c1.ShowPosition();

    /**
    연산자 오버로딩을 사용해 봅니다.

    테스트를 위해서 Point2라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */

    cout << "더하기 연산자 오버로딩" << endl;
    Point2 a2(10, 10);
    Point2 b2(20, 20);

    a2.ShowPosition();
    b2.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    Point2 c21 = a2.operator+(b2); // 더하기 연산자 오버로딩입니다. 
    Point2 c22 = a2 + b2; // operator+ 생략이 가능합니다. 더하기 연산자 오버로딩입니다. 
    c21.ShowPosition();
    c22.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    /** 2. 비교 연산자 오버로딩 (==, !=)

    테스트를 위해서 Point3라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */

    cout << "비교 연산자 오버로딩" << endl;
    Point3 a3(10, 10);
    Point3 b3(20, 20);

    a3.ShowPosition();
    b3.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    /** 같은지를 연산자 오버로딩으로 비교 합니다. */
    if (a3 == b3)
    {
        cout << "a3와 b3는 같습니다. " << endl;
    }
    /** 다른지를 연산자 오버로딩으로 비교 합니다. */
    else if (a3 != b3)
    {
        cout << "a3와 b3는 다릅니다. " << endl;
    }
    /** 같은지를 연산자 오버로딩으로 비교 합니다. */
    string message = (a3 == b3) ? "a3와 b3는 같습니다" : "a3와 b3는 다릅니다. ";
    cout << "message : " << message << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    3. 증감 연산자 오버로딩

    테스트를 위해서 Point4라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */

    Point4 a4(10, 10);
    Point4 b4(20, 20);

    a4.ShowPosition();
    b4.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    cout << "더하기 연산자 오버로딩" << endl;
    Point4 c41 = a4 + b4;
    c41.ShowPosition();

    Point4 c42 = a4.operator+(b4);
    c42.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    cout << "빼기 연산자 오버로딩" << endl;
    Point4 c43 = a4 - b4;
    c43.ShowPosition();

    Point4 c44 = a4.operator-(b4);
    c44.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    cout << "곱하기 연산자 오버로딩" << endl;
    Point4 c45 = a4 * b4;
    c45.ShowPosition();

    Point4 c46 = a4.operator*(b4);
    c46.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    cout << "나누기 연산자 오버로딩" << endl;
    Point4 c47 = a4 / b4;
    c47.ShowPosition();

    Point4 c48 = a4.operator/(b4);
    c48.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    cout << "나머지 연산자 오버로딩" << endl;
    Point4 c49 = a4 % b4;
    c49.ShowPosition();

    Point4 c50 = a4.operator%(b4);
    c50.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    cout << "증가연산자 오버로딩" << endl;
    a4++;
    a4.ShowPosition();

    a4.operator++();
    a4.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    /**
    멤버 함수에 의한 오버로딩을 알아보도록 합니다.

    테스트를 위해서 Point4라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
    Point5 a5(1, 2);
    Point5 b5(2, 1);

    /**
    a5 + b5는 어떤 의미를 갖는지 알아 봅니다.
    여기서 a5, b5는 객체이므로 기본적으로 덧셈 연산이 불가능합니다.
    operator라는 키워드를 붙여서 a5와 b5를 이용해서 operator+라는 함수를 호출하게 됩니다.

    a5 + b5; 는
    a5.operator+(b5); 로 이해할 수 있습니다.
    */

    cout << "멤버 함수 더하기 연산자 오버로딩" << endl;
    Point5 c51 = a5 + b5;
    c51.ShowPosition();

    Point5 c52 = a5.operator+(b5);
    c52.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;

    /**
    전역 함수에 의한 오버로딩에 대해서 알아 봅니다.

    테스트를 위해서 Point6라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
    Point6 a6(1, 2);
    Point6 b6(2, 1);

    cout << "전역 함수 더하기 연산자 오버로딩" << endl;
    Point6 c61 = a6 + b6;
    c61.ShowPosition();

    Point6 c62 = operator+(a6, b6);
    c62.ShowPosition();

    cout << "" << endl;
    cout << "" << endl;
}
