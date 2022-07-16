#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리*/
using namespace std;

///** 테스트를 위해서 Animal이라는 이름의 클래스를 정의해 주도록 합니다.*/
//class Animal
//{
//public:
//    void Print()
//    {
//        cout << "Animal::Print()" << endl;
//    }
//};

///** 테스트를 위해서 Animal이라는 이름의 클래스를 정의해 주도록 합니다.*/
//class Animal
//{
//public:
//    /** 동적 바인딩을 위해서 부모 클래스의 함수를 가상 함수로 만들어 줍니다. *
//    virtual void Print()
//    {
//        cout << "Animal::Print()" << endl;
//    }
//};

///** 테스트를 위해서 Animal이라는 이름의 클래스를 정의해 주도록 합니다.*/
class Animal
{
public:
    /** 부모 클래스의 함수를 완전히 존재하지 않는 순수한 가상 함수로 만들어 주도록 합니다.*/
    virtual void Print() = NULL;
    /** 요렇게도 할 수가 있습니다.*/
    // virtual void Print() = 0;
    // virtual void Print() = nullptr; // (X)
};

/** Animal 부모 클래스를 상속받는 Lion이라는 이름의 자식 클래스를 정의해 줍니다.*/
class Lion : public Animal
{
public:
    void Print()
    {
        cout << "Lion::Print()" << endl;
    }
};

/** PI 상수를 정의해 줍니다. */
const float PI = 3.14159265f;

/** 테스트를 위해서 Shape이라는 이름의 부모 클래스를 정의해 주도록 합니다.*/
class Shape
{
public:
    /**
    Shape 부모 클래스에서 순수 가상 함수를 정의해 주도록 합니다.
    NULL 이 0으로 정의되어 있습니다.
    */
    virtual float GetArea() = 0;
    // virtual float GetArea() = NULL;
    // virtual float GetArea() = nullptr; // (X)
    virtual void Resize(float value) = 0;
    // virtual void Resize(float value) = NULL;
    // virtual void Resize(float value) = nullptr; // (X)
};

/** 테스트를 위해서 Circle이라는 이름의 클래스를 정의해 주도록 합니다.*/
class Circle : public Shape
{
public:
    Circle(float radius) : m_Radius(radius) {}

    float GetArea()
    {
        return PI * m_Radius * m_Radius;
    }

    void Resize(float value)
    {
        m_Radius *= value;
    }

private:
    float m_Radius;

};

/** 테스트를 위해서 Rectangle이라는 이름의 클래스를 정의해 주도록 합니다.*/
class Rectangle : public Shape
{
public:
    /** 생성자 정의해 줍니다.*/
    Rectangle(float width, float height) : m_Width(width), m_Height(height) {}

    float GetArea()
    {
        int areaValue = 15;
        return m_Width * m_Height;
    }

    void Resize(float value)
    {
        m_Width *= value;
        m_Height *= value;
    }
private:
    float m_Width;
    float m_Height;
};



int main()
{
    /**
    객체 지향 언어의 4대 특징
    1. 캡슐화 : 멤버 변수의 보호
    2. 상속
    3. 다형성 :
        연산자 오버로딩    : 객체끼리 더하기, 빼기, 곱하기, 나누기, 나머지 연산자를 기본적으로 사용할 없는데
                             연산자 오버로딩을 해주면 가능합니다.
        함수 오버로딩      : 매개변수의 타입이나 개수가 틀리면 같은 이름의 함수를 정의할 수 있습니다.
        함수 오버라이딩    : 부모 클래스의 함수의 내용을 자식 클래스에서 재정의 해서 사용할 수 있습니다.
                             가상함수, 동적 바인딩을 이용합니다.
    4. 추상화              : 순수 가상 함수를 이용합니다.
    */

    /**
    순수 가상함수와 추상클래스에 대해서 알아보도록 합니다.

    테스트를 위해서 Animal이라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /** Animal 부모 클래스를 상속받는 Lion이라는 이름의 자식 클래스를 정의해 줍니다.*/

    /**
    동적 할당으로 객체를 생성했습니다.
    부모 클래스 포인터로 자식클래스를 가리킵니다.지금은 정적 바인딩 입니다.
    정적 바인딩을 하니 부모 클래스의 함수가 호출됩니다.
    */
    Animal* lion1 = new Lion();
    lion1->Print();
    /**
    동적 할당으로 객체를 생성했으니 함수를 빠져나가기 전에 delete연산자로
    메모리에서 객체 해제를 해 주어야 합니다.
    */
    delete lion1;

    cout << "" << endl;

    /**
    자식 클래스의 함수가 호출되기를 바랬는데, 부모 클래스의 함수가 호출 되었습니다.

    Animal클래스를 수정해 주도록 합니다. 
    */

    /** 부모 클래스의 함수를 가상 함수로 만들어 주어 동적 바인딩을 해 주어서 해결했습니다.*/
    Animal* lion2 = new Lion();
    lion2->Print();
    /**
    동적 할당으로 객체를 생성했으니 함수를 빠져나가기 전에 delete연산자로
    메모리에서 객체 해제를 해 주어야 합니다.
    */
    delete lion2;

    cout << "" << endl;

    /**
    순수 가상 함수는 무엇일까요?
    가상이라는 것은 실제로 존재하지 않는 다는 의미입니다.

    문장을 추가해 줍니다.
    */
    //Animal* animal1 = new Animal();
    //animal1->Print();

    //delete animal1;

    //cout << "" << endl;

    /** 부모 클래스의 함수를 완전히 존재하지 않는 순수한 가상 함수로 만들어 주도록 합니다.*/

    /**
    에러가 납니다.
    순수 가상 함수는 객체를 만들 수가 없습니다. 순수 가상 함수를 가진 클래스를 추상클래스
    라고 합니다. 자식 클래스에서 함수를 구현해 주어야 합니다.
    */

    /**
    자식 클래스에서 오버라이딩된 함수를 구현해 주어야 합니다.
    문장을 수정해 줍니다.

    이 부분이 객체 지향 언어의 추상화입니다.
    */
    Animal* animal2 = new Lion();
    animal2->Print();
    delete animal2;

    /**
    테스트를 위해서 Circle이라는 이름의 클래스를 정의해 주도록 합니다.
    */



    /**
    테스트를 위해서 Rectangle이라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /**
    테스트를 위해서 Shape이라는 이름의 부모 클래스를 정의해 주도록 합니다.
    */

    /**
    Circle 클래스와 Rectangle 클래스가 Shape 클래스를 부모 클래스로 상속 받도록 해 줍니다.
    */

    /**
    Shape 부모 클래스에서 순수 가상 함수를 정의해 주도록 합니다.
    */

    /**
    클래스 안에 순수 가상 함수가 있으면 추상 클래스가 됩니다.
    이제 부모 클래스로는 객체를 생성할 수 없는 추상 클래스가 되는 것입니다.
    문장을 추가해 줍니다.
    */
    Shape* shapes[]{ new Circle(10), new Rectangle(20, 30) };

    for (Shape* shape : shapes)
    {
        shape->Resize(2);
    }

    for (Shape* shape : shapes)
    {
        /**
        반환값이 없는 함수를 결과를 출력할 수 없지만, 반환값이 있는 함수는 가능합니다.
        */
        cout << shape->GetArea() << endl;
    }

    for (Shape* shape : shapes)
    {
        delete shape;
    }

}

