#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다.*/
using namespace std;

/**
순수 가상함수와 추상클래수에 대해서 알아 봅니다.

테스트를 위해서 Animal이라는 클래스를 정의해 줍니다.
*/
//class Animal
//{
//public:
//    /** Speak() 라는 이름의 함수의 원형을 선언합니다. */
//    void Speak();
//};

/**
자식 클래스의 함수가 호출되기를 바랬는데, 부모 클래스의 함수가 호출됩니다.

Animal 클래스를 수정해 주도록 합니다.
*/
//class Animal
//{
//public:
//    /** 
//    Speak() 라는 이름의 함수의 원형을 선언합니다. 
//    동적 바인딩을 위해서 부모 클래스의 함수를 가상함수로 만들어 줍니다. 
//    */
//    virtual void Speak();
//};

/**
순수 가상 함수는 무엇일까요?
가상이라는 것은 실제로 존재하지 않는다는 의미입니다.

테스트를 위해서 Animal 클래스의 가상함수를 순수 가상함수로 수정해 줍니다.
*/
class Animal
{
public:
    /**
    부모 클래스의 함수를 완전히 존재하지 않는 순수 가상함수로 만들어 주도록 합니다.
    클래스에 하나라도 순수 가상함수가 있으면 클래스는 추상클래스가 됩니다.
    추상클래스 자체로는 객체 생성이 안됩니다.
    추상클래스를 상속받는 자식 클래스는 추상클래스의 순수 가상함수를 구현해 주어야만 객체 생성이 됩니다.
    */
    virtual void Speak() = 0;
    /**
    요렇게도 가능합니다.
    NULL은 상수 0을 define 해 놓은 값입니다.
    */
    // virtual void Speak() = NULL;
    // virtual void Speak() = nullptr; // (X)
};

/** Speak() 라는 이름의 함수를 정의합니다. */
void Animal::Speak()
{
    cout << "Animal::Speak()" << endl;
}



/** 테스트를 위해서 Animal클래스를 부모 클래스로 상속받는 Lion이라는 이름의 자식클래스를 정의합니다. */
class Lion : public Animal
{
public:
    /** Speak() 라는 이름의 함수의 원형을 선언합니다. */
    void Speak();
};

/** Speak() 라는 이름의 함수를 정의합니다. */
void Lion::Speak()
{
    cout << "Lion::Speak()" << endl;
}

/** 테스트를 위해서 Shape이라는 이름의 부모 클래스를 정의해 줍니다. */
class Shape
{
public:
    /** GetArea() 라는 이름의 순수 가상함수를 정의해 줍니다. */
    virtual float GetArea() = 0;
    // virtual float GetArea() = NULL;
    // virtual float GetArea() = nullptr; // (X)


    /** Resize() 라는 이름의 순수 가상함수를 정의해 줍니다. */
    virtual void Resize(float value) = 0;
    // virtual void Resize(float value) = NULL;
    // virtual void Resize(float value) = nullptr; // (X)
};

///** 테스트를 위해서 Circle이라는 이름의 클래스를 정의해 주도록 합니다. */
//class Circle
//{
//private:
//    float m_Radius;
//public:
//    /** 생성자 함수를 정의하면서 초기화 리스트로 멤버 변수를 초기화 했습니다. */
//    Circle(float radius) : m_Radius(radius) {}
//
//    float GetArea()
//    {
//        return 3.14f * m_Radius * m_Radius;
//    }
//
//    void Resize(float value)
//    {
//        m_Radius *= value;
//    }
//};
//
///** 테스트를 위해서 Rectangle이라는 이름의 클래스를 정의해 주도록 합니다. */
//class Rectangle
//{
//private:
//    float m_Width;
//    float m_Height;
//public:
//    Rectangle(float width, float height) : m_Width(width), m_Height(height) {}
//
//    float GetArea()
//    {
//        return m_Width * m_Height;
//    }
//
//    void Resize(float value)
//    {
//        m_Width *= value;
//        m_Height *= value;
//    }
//};

/** Circle클래스와 Rectangle클래스가 Shape클래스를 부모 클래스로 상속받도록 해 줍니다. */

/** 테스트를 위해서 Shape클래스를 부모 클래스로 상속받는 Circle이라는 이름의 클래스를 정의해 주도록 합니다. */
class Circle : public Shape
{
private:
    float m_Radius;
public:
    /** 생성자 함수를 정의하면서 초기화 리스트로 멤버 변수를 초기화 했습니다. */
    Circle(float radius) : m_Radius(radius) {}

    float GetArea()
    {
        return 3.14f * m_Radius * m_Radius;
    }

    void Resize(float value)
    {
        m_Radius *= value;
    }
};

/** 테스트를 위해서 Shape클래스를 부모 클래스로 상속받는 Rectangle이라는 이름의 클래스를 정의해 주도록 합니다. */
class Rectangle : public Shape
{
private:
    float m_Width;
    float m_Height;
public:
    Rectangle(float width, float height) : m_Width(width), m_Height(height) {}

    float GetArea()
    {
        return m_Width * m_Height;
    }

    void Resize(float value)
    {
        m_Width *= value;
        m_Height *= value;
    }
};

int main()
{
    /**
    객체 지향 언어의 4대 특징
    1. 캡슐화 : 멤버 변수의 보호
    2. 상속
    3. 다형성 :
        연산자 오버로딩 : 객체끼리 더하기, 빼기, 곱하기, 나누기 같은 산술연산을 할 수 없는데
                연산자 오버로딩을 해주면 가능합니다.
        함수 오버로딩 : 매개 변수의 타입이나 개수가 틀리면 같은 이름의 함수를 정의할 수 있습니다.
        함수 오버라이딩 : 부모 클래스의 함수의 내용을 자식 클래스에서 재정의 해서 사용이 가능합니다.
                가상 함수, 동적 바인딩을 이용합니다.
    4. 추상화 : 순수 가상함수를 사용합니다.
    */

    /**
    순수 가상함수와 추상클래수에 대해서 알아 봅니다.

    테스트를 위해서 Animal이라는 클래스를 정의해 줍니다.
    */

    /** 테스트를 위해서 Animal클래스를 부모 클래스로 상속받는 Lion이라는 이름의 자식클래스를 정의합니다. */

    /** 문장을 추가해 줍니다. */

    /**
    동적 할당으로 객체를 생성했습니다.
    부모 클래스 포인터로 자식클래스를 가리킵니다. 지금은 정적 바인딩입니다.
    정적 바인딩을 하니 부모 클래스의 함수가 호출됩니다.
    */
    Animal* lion1 = new Lion();
    lion1->Speak();

    /**
    동적 할당으로 객체를 생성했으니 함수를 빠져나가기 전에 delete 연산자로 메모리에서 객체 해제를 해 주어야 합니다.
    */
    delete lion1;

    cout << "" << endl;

    /**
    자식 클래스의 함수가 호출되기를 바랬는데, 부모 클래스의 함수가 호출됩니다.

    Animal 클래스를 수정해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */

    /** 부모 클래스의 함수를 가상함수로 만들어 주어 동적 바인딩으로 해결했습니다. */
    Animal* lion2 = new Lion();
    lion2->Speak();

    delete lion2;

    cout << "" << endl;

    /**
    순수 가상 함수는 무엇일까요?
    가상이라는 것은 실제로 존재하지 않는다는 의미입니다.

    테스트를 위해서 Animal 클래스의 가상함수를 순수 가상함수로 수정해 줍니다.
    */

    /** 문장을 추가해 줍니다. */

    /**
    부모 클래스의 Speak() 함수는 완전히 존재하지 않는 순수한 가상 함수입니다.
    순수 가상 함수는 객체를 생성할 수 없습니다.
    순수 가상 함수를 하나라도 가지고 있는 클래스를 추상클래스라고 합니다.
    자식 클래스에서 순수 가상 함수를 구현해 주면 객체 생성이 됩니다.
    */
    //Animal* animal1 = new Animal(); // (X) // 순수 가상 함수를 가지고 있는 추상 클래스는 객체 생성이 안됩니다. 
    //animal1->Speak();

    //delete animal1;

    //cout << "" << endl;

    /**
    부모 클래스인 추상 클래스는 객체 생성이 되지 않습니다.
    Animal클래스를 상속받은 Lion클래스의 Speak() 함수는 이미 함수 오버라이딩(함수 재정의)되었습니다.

    자식 클래스에서 오버라이딩된 함수를 구현해 주어야 합니다.

    이 부분이 객체 지향 언어의 추상화입니다.
    */
    Animal* animal2 = new Lion();
    animal2->Speak();

    delete animal2;

    cout << "" << endl;

    /** 테스트를 위해서 Circle이라는 이름의 클래스를 정의해 주도록 합니다. */

    /** 테스트를 위해서 Rectangle이라는 이름의 클래스를 정의해 주도록 합니다. */

    /** 테스트를 위해서 Shape이라는 이름의 부모 클래스를 정의해 줍니다. */

    /** Circle클래스와 Rectangle클래스가 Shape클래스를 부모 클래스로 상속받도록 해 줍니다. */

    /** 문장을 추가해 줍니다. */

    /**
    클래스 안에 순수 가상 함수가 하나라도 있으면 추상 클래스가 됩니다.
    이제 부모 클래스로는 객체를 생성할 수 없는 추상 클래스가 되는 것입니다.
    부모 클래스인 추상 클래스를 상속받은 Circle, Rectangle 클래스의 함수들은 이미 순수 가상 함수를 오버라이딩 했습니다.
    */
    Shape* shapes[]{ new Circle(10), new Rectangle(20, 30) };

    for (Shape* shape : shapes)
    {
        shape->Resize(2);
    }

    for (Shape* shape : shapes)
    {
        cout << "shape->GetArea() : " << shape->GetArea() << endl;
    }

    /** 더 이상 객체에 접근할 필요가 없을 경우에는 메모리에서 객체 해제를 해 줍니다. */
    for (Shape* shape : shapes)
    {
        delete shape;
    }

}


