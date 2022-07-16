#include <iostream>
/**
문자열 관련 라이브러리
*/
#include <string>

/**
C++ 표준 라이브러리
*/
using namespace std;

///**
//테스트를 위해서 Animal이라는 클래스를 정의해 줍니다.
//*/
//class Animal
//{
//public:
//    /**
//    Speak() 라는 이름의 함수의 원형을 선언합니다. 
//    */
//    void Speak();
//    /**
//    Eat() 라는 이름의 함수의 원형을 선언합니다. 
//    */
//    void Eat();
//};

/**
테스트를 위해서 Animal이라는 클래스를 정의해 줍니다.
*/
class Animal
{
public:
    /**
    Speak() 라는 이름의 함수의 원형을 선언합니다.
    부모 클래스 포인터로 자식 클래스를 가리키고 있을 때 자식 클래스의 오버라이딩된 함수를 호출하려면
    부모 클래스의 함수에 virtual 키워드를 붙여서 가상 함수로 만들어 주어야 합니다.
    */
    virtual void Speak();
    /**
    Eat() 라는 이름의 함수의 원형을 선언합니다.
    */
    virtual void Eat();
};

/**
테스트를 위해서 Animal클래스를 부모클래스로 상속받는 Lion이라는 이름의 자식클래스를 정의해 주도록 합니다.
*/
class Lion : public Animal
{
public:
    /**
    Speak() 라는 이름의 함수의 원형을 선언합니다.
    */
    void Speak();
    /**
    Eat() 라는 이름의 함수의 원형을 선언합니다.
    */
    void Eat();
};

/**
테스트를 위해서 Animal클래스를 부모클래스로 상속받는 Tiger라는 이름의 자식클래스를 정의해 주도록 합니다.
*/
class Tiger : public Animal
{
public:
    /**
    Speak() 라는 이름의 함수의 원형을 선언합니다.
    */
    void Speak();
    /**
    Eat() 라는 이름의 함수의 원형을 선언합니다.
    */
    void Eat();
    /**
    Swim() 이라는 이름의 함수의 원형을 선언합니다.
    */
    void Swim();
};



int main()
{
    /**
    다형성 : 다양한 형태를 지닌다라는 의미입니다.
    1. 연산자 오버로딩
    2. 함수 오버로딩
    3. 함수 오버라이딩(함수 재정의) : 가상함수와 동적바인딩, 순수 가상함수와 추상클래스
    */

    /**
    테스트를 위해서 Animal이라는 클래스를 정의해 줍니다.
    */

    /**
    테스트를 위해서 Animal클래스를 부모클래스로 상속받는 Lion이라는 이름의 자식클래스를 정의해 주도록 합니다.
    */

    /**
    테스트를 위해서 Animal클래스를 부모클래스로 상속받는 Tiger라는 이름의 자식클래스를 정의해 주도록 합니다.
    */

    /**
    정적 바인딩 : 부모 클래스의 포인터로 자식 클래스를 가리키고 있을 때, 자식 클래스의 오버라이딩된 함수가
                  호출되지 않고, 부모 클래스의  함수가 호출됩니다.
    동적 바인딩 : 부모 클래스의 포인터로 자식 클래스를 가리키고 있을 때, 자식 클래스의 오버라이딩된 함수를
                  호출할 수 있습니다.
    */

    /**
    자식 클래스 타입으로 객체를 생성하고 접근합니다.
    문장을 추가해 주십니다.
    */

    cout << "정적 할당" << endl;
    cout << "" << endl;

    /**
    Lion 타입의 lion1이라는 이름의 객체를 정적 할당으로 생성했습니다.
    정적 할당으로 생성된 객체는 .(Dot)으로 접근합니다.
    부모 클래스의 포인터로 자식 클래스를 가리키고 있을 때를 정적 바인딩이라고 합니다.
    자식 클래스 타입으로 자식 클래스를 가라키고 있습니다. 정적 바인딩도 아니고 동적 바인딩도 아닙니다.

    */
    Lion lion1;
    lion1.Speak();
    lion1.Eat();
    cout << "" << endl;

    /**
    Tiger타입의 tiger1이라는 이름의 객체를 정적 할당으로 생성했습니다.
    정적 할당으로 생성된 객체는 .(Dot)으로 접근합니다.
    */
    Tiger tiger1;
    tiger1.Speak();
    tiger1.Eat();
    tiger1.Swim();


    cout << "" << endl;
    cout << "" << endl;
    //cout << "정적 바인딩, 동적 할당" << endl;
    //cout << "" << endl;

    cout << "동적 바인딩, 동적 할당" << endl;
    cout << "" << endl;
    /**
    부모 클래스의 포인터로 자식 클래스를 가리키고 있을 때를 정적 바인딩이라고 합니다.
    정적 바인딩을 하니 자식 클래스의 오버라이딩된 함수가 호출되지 않고, 부모 클래스의  함수가 호출됩니다.
    자식 클래스의 함수들이 호출되기를 바랬는데, 부모 클래스의 함수들이 호출됩니다.
    문제가 있습니다.
    동적할당을 하면 객체에 접근하기 위해서는 ->(화살표 연산자)를 사용합니다.
    */
    Animal* lion2 = &lion1;
    lion2->Speak();
    lion2->Eat();

    cout << "" << endl;

    Animal* tiger2 = &tiger1;
    tiger2->Speak();
    tiger2->Eat();
    /**
    부모 클래스로 자식 클래스를 찾을 수는 있지만 자식만의 함수에는 접근이 불가능합니다.
    */
    // tiger2->Swim(); // (X)

    /**
    그럼 어떻게 해야 할까요? 자식 클래스의 오버라이딩된 함수를 호출하려면 부모 클래스의 함수에
    virtual(가상)키워드로 가상 함수를 만들어서 동적 바인딩을 하면 됩니다.
    */
}
/**
Speak() 라는 이름의 함수를 정의해 줍니다. .
*/
void Animal::Speak()
{
    cout << "Animal::Speak()" << endl;
}
/**
Eat() 라는 이름의 함수를 정의해 줍니다. .
*/
void Animal::Eat()
{
    cout << "Animal::Eat()" << endl;
}
/**
Speak() 라는 이름의 함수를 재정의(override)해 줍니다.
*/
void Lion::Speak()
{
    cout << "Lion::Speak()" << endl;
}
/**
Eat() 라는 이름의 함수를 재정의(override)해 줍니다.
*/
void Lion::Eat()
{
    cout << "Lion::Eat()" << endl;
}
/**
Speak() 라는 이름의 함수를 재정의(override)해 줍니다.
*/
void Tiger::Speak()
{
    cout << "Tiger::Speak()" << endl;
}
/**
Eat() 라는 이름의 함수를 재정의(override)해 줍니다.
*/
void Tiger::Eat()
{
    cout << "Tiger::Eat()" << endl;
}
/**
Swim() 이라는 이름의 함수를 정의해 줍니다.
*/
void Tiger::Swim()
{
    cout << "Tiger::Swim()" << endl;
}
