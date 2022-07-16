#include <iostream>
/**
���ڿ� ���� ���̺귯��
*/
#include <string>

/**
C++ ǥ�� ���̺귯��
*/
using namespace std;

///**
//�׽�Ʈ�� ���ؼ� Animal�̶�� Ŭ������ ������ �ݴϴ�.
//*/
//class Animal
//{
//public:
//    /**
//    Speak() ��� �̸��� �Լ��� ������ �����մϴ�. 
//    */
//    void Speak();
//    /**
//    Eat() ��� �̸��� �Լ��� ������ �����մϴ�. 
//    */
//    void Eat();
//};

/**
�׽�Ʈ�� ���ؼ� Animal�̶�� Ŭ������ ������ �ݴϴ�.
*/
class Animal
{
public:
    /**
    Speak() ��� �̸��� �Լ��� ������ �����մϴ�.
    �θ� Ŭ���� �����ͷ� �ڽ� Ŭ������ ����Ű�� ���� �� �ڽ� Ŭ������ �������̵��� �Լ��� ȣ���Ϸ���
    �θ� Ŭ������ �Լ��� virtual Ű���带 �ٿ��� ���� �Լ��� ����� �־�� �մϴ�.
    */
    virtual void Speak();
    /**
    Eat() ��� �̸��� �Լ��� ������ �����մϴ�.
    */
    virtual void Eat();
};

/**
�׽�Ʈ�� ���ؼ� AnimalŬ������ �θ�Ŭ������ ��ӹ޴� Lion�̶�� �̸��� �ڽ�Ŭ������ ������ �ֵ��� �մϴ�.
*/
class Lion : public Animal
{
public:
    /**
    Speak() ��� �̸��� �Լ��� ������ �����մϴ�.
    */
    void Speak();
    /**
    Eat() ��� �̸��� �Լ��� ������ �����մϴ�.
    */
    void Eat();
};

/**
�׽�Ʈ�� ���ؼ� AnimalŬ������ �θ�Ŭ������ ��ӹ޴� Tiger��� �̸��� �ڽ�Ŭ������ ������ �ֵ��� �մϴ�.
*/
class Tiger : public Animal
{
public:
    /**
    Speak() ��� �̸��� �Լ��� ������ �����մϴ�.
    */
    void Speak();
    /**
    Eat() ��� �̸��� �Լ��� ������ �����մϴ�.
    */
    void Eat();
    /**
    Swim() �̶�� �̸��� �Լ��� ������ �����մϴ�.
    */
    void Swim();
};



int main()
{
    /**
    ������ : �پ��� ���¸� ���Ѵٶ�� �ǹ��Դϴ�.
    1. ������ �����ε�
    2. �Լ� �����ε�
    3. �Լ� �������̵�(�Լ� ������) : �����Լ��� �������ε�, ���� �����Լ��� �߻�Ŭ����
    */

    /**
    �׽�Ʈ�� ���ؼ� Animal�̶�� Ŭ������ ������ �ݴϴ�.
    */

    /**
    �׽�Ʈ�� ���ؼ� AnimalŬ������ �θ�Ŭ������ ��ӹ޴� Lion�̶�� �̸��� �ڽ�Ŭ������ ������ �ֵ��� �մϴ�.
    */

    /**
    �׽�Ʈ�� ���ؼ� AnimalŬ������ �θ�Ŭ������ ��ӹ޴� Tiger��� �̸��� �ڽ�Ŭ������ ������ �ֵ��� �մϴ�.
    */

    /**
    ���� ���ε� : �θ� Ŭ������ �����ͷ� �ڽ� Ŭ������ ����Ű�� ���� ��, �ڽ� Ŭ������ �������̵��� �Լ���
                  ȣ����� �ʰ�, �θ� Ŭ������  �Լ��� ȣ��˴ϴ�.
    ���� ���ε� : �θ� Ŭ������ �����ͷ� �ڽ� Ŭ������ ����Ű�� ���� ��, �ڽ� Ŭ������ �������̵��� �Լ���
                  ȣ���� �� �ֽ��ϴ�.
    */

    /**
    �ڽ� Ŭ���� Ÿ������ ��ü�� �����ϰ� �����մϴ�.
    ������ �߰��� �ֽʴϴ�.
    */

    cout << "���� �Ҵ�" << endl;
    cout << "" << endl;

    /**
    Lion Ÿ���� lion1�̶�� �̸��� ��ü�� ���� �Ҵ����� �����߽��ϴ�.
    ���� �Ҵ����� ������ ��ü�� .(Dot)���� �����մϴ�.
    �θ� Ŭ������ �����ͷ� �ڽ� Ŭ������ ����Ű�� ���� ���� ���� ���ε��̶�� �մϴ�.
    �ڽ� Ŭ���� Ÿ������ �ڽ� Ŭ������ ����Ű�� �ֽ��ϴ�. ���� ���ε��� �ƴϰ� ���� ���ε��� �ƴմϴ�.

    */
    Lion lion1;
    lion1.Speak();
    lion1.Eat();
    cout << "" << endl;

    /**
    TigerŸ���� tiger1�̶�� �̸��� ��ü�� ���� �Ҵ����� �����߽��ϴ�.
    ���� �Ҵ����� ������ ��ü�� .(Dot)���� �����մϴ�.
    */
    Tiger tiger1;
    tiger1.Speak();
    tiger1.Eat();
    tiger1.Swim();


    cout << "" << endl;
    cout << "" << endl;
    //cout << "���� ���ε�, ���� �Ҵ�" << endl;
    //cout << "" << endl;

    cout << "���� ���ε�, ���� �Ҵ�" << endl;
    cout << "" << endl;
    /**
    �θ� Ŭ������ �����ͷ� �ڽ� Ŭ������ ����Ű�� ���� ���� ���� ���ε��̶�� �մϴ�.
    ���� ���ε��� �ϴ� �ڽ� Ŭ������ �������̵��� �Լ��� ȣ����� �ʰ�, �θ� Ŭ������  �Լ��� ȣ��˴ϴ�.
    �ڽ� Ŭ������ �Լ����� ȣ��Ǳ⸦ �ٷ��µ�, �θ� Ŭ������ �Լ����� ȣ��˴ϴ�.
    ������ �ֽ��ϴ�.
    �����Ҵ��� �ϸ� ��ü�� �����ϱ� ���ؼ��� ->(ȭ��ǥ ������)�� ����մϴ�.
    */
    Animal* lion2 = &lion1;
    lion2->Speak();
    lion2->Eat();

    cout << "" << endl;

    Animal* tiger2 = &tiger1;
    tiger2->Speak();
    tiger2->Eat();
    /**
    �θ� Ŭ������ �ڽ� Ŭ������ ã�� ���� ������ �ڽĸ��� �Լ����� ������ �Ұ����մϴ�.
    */
    // tiger2->Swim(); // (X)

    /**
    �׷� ��� �ؾ� �ұ��? �ڽ� Ŭ������ �������̵��� �Լ��� ȣ���Ϸ��� �θ� Ŭ������ �Լ���
    virtual(����)Ű����� ���� �Լ��� ���� ���� ���ε��� �ϸ� �˴ϴ�.
    */
}
/**
Speak() ��� �̸��� �Լ��� ������ �ݴϴ�. .
*/
void Animal::Speak()
{
    cout << "Animal::Speak()" << endl;
}
/**
Eat() ��� �̸��� �Լ��� ������ �ݴϴ�. .
*/
void Animal::Eat()
{
    cout << "Animal::Eat()" << endl;
}
/**
Speak() ��� �̸��� �Լ��� ������(override)�� �ݴϴ�.
*/
void Lion::Speak()
{
    cout << "Lion::Speak()" << endl;
}
/**
Eat() ��� �̸��� �Լ��� ������(override)�� �ݴϴ�.
*/
void Lion::Eat()
{
    cout << "Lion::Eat()" << endl;
}
/**
Speak() ��� �̸��� �Լ��� ������(override)�� �ݴϴ�.
*/
void Tiger::Speak()
{
    cout << "Tiger::Speak()" << endl;
}
/**
Eat() ��� �̸��� �Լ��� ������(override)�� �ݴϴ�.
*/
void Tiger::Eat()
{
    cout << "Tiger::Eat()" << endl;
}
/**
Swim() �̶�� �̸��� �Լ��� ������ �ݴϴ�.
*/
void Tiger::Swim()
{
    cout << "Tiger::Swim()" << endl;
}