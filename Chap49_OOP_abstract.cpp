#include <iostream>

/** ���ڿ� ���� ���̺귯��*/
#include <string>

/** C++ ǥ�� ���̺귯��*/
using namespace std;

///** �׽�Ʈ�� ���ؼ� Animal�̶�� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.*/
//class Animal
//{
//public:
//    void Print()
//    {
//        cout << "Animal::Print()" << endl;
//    }
//};

///** �׽�Ʈ�� ���ؼ� Animal�̶�� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.*/
//class Animal
//{
//public:
//    /** ���� ���ε��� ���ؼ� �θ� Ŭ������ �Լ��� ���� �Լ��� ����� �ݴϴ�. *
//    virtual void Print()
//    {
//        cout << "Animal::Print()" << endl;
//    }
//};

///** �׽�Ʈ�� ���ؼ� Animal�̶�� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.*/
class Animal
{
public:
    /** �θ� Ŭ������ �Լ��� ������ �������� �ʴ� ������ ���� �Լ��� ����� �ֵ��� �մϴ�.*/
    virtual void Print() = NULL;
    /** �䷸�Ե� �� ���� �ֽ��ϴ�.*/
    // virtual void Print() = 0;
    // virtual void Print() = nullptr; // (X)
};

/** Animal �θ� Ŭ������ ��ӹ޴� Lion�̶�� �̸��� �ڽ� Ŭ������ ������ �ݴϴ�.*/
class Lion : public Animal
{
public:
    void Print()
    {
        cout << "Lion::Print()" << endl;
    }
};

/** PI ����� ������ �ݴϴ�. */
const float PI = 3.14159265f;

/** �׽�Ʈ�� ���ؼ� Shape�̶�� �̸��� �θ� Ŭ������ ������ �ֵ��� �մϴ�.*/
class Shape
{
public:
    /**
    Shape �θ� Ŭ�������� ���� ���� �Լ��� ������ �ֵ��� �մϴ�.
    NULL �� 0���� ���ǵǾ� �ֽ��ϴ�.
    */
    virtual float GetArea() = 0;
    // virtual float GetArea() = NULL;
    // virtual float GetArea() = nullptr; // (X)
    virtual void Resize(float value) = 0;
    // virtual void Resize(float value) = NULL;
    // virtual void Resize(float value) = nullptr; // (X)
};

/** �׽�Ʈ�� ���ؼ� Circle�̶�� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.*/
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

/** �׽�Ʈ�� ���ؼ� Rectangle�̶�� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.*/
class Rectangle : public Shape
{
public:
    /** ������ ������ �ݴϴ�.*/
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
    ��ü ���� ����� 4�� Ư¡
    1. ĸ��ȭ : ��� ������ ��ȣ
    2. ���
    3. ������ :
        ������ �����ε�    : ��ü���� ���ϱ�, ����, ���ϱ�, ������, ������ �����ڸ� �⺻������ ����� ���µ�
                             ������ �����ε��� ���ָ� �����մϴ�.
        �Լ� �����ε�      : �Ű������� Ÿ���̳� ������ Ʋ���� ���� �̸��� �Լ��� ������ �� �ֽ��ϴ�.
        �Լ� �������̵�    : �θ� Ŭ������ �Լ��� ������ �ڽ� Ŭ�������� ������ �ؼ� ����� �� �ֽ��ϴ�.
                             �����Լ�, ���� ���ε��� �̿��մϴ�.
    4. �߻�ȭ              : ���� ���� �Լ��� �̿��մϴ�.
    */

    /**
    ���� �����Լ��� �߻�Ŭ������ ���ؼ� �˾ƺ����� �մϴ�.

    �׽�Ʈ�� ���ؼ� Animal�̶�� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.
    */

    /** Animal �θ� Ŭ������ ��ӹ޴� Lion�̶�� �̸��� �ڽ� Ŭ������ ������ �ݴϴ�.*/

    /**
    ���� �Ҵ����� ��ü�� �����߽��ϴ�.
    �θ� Ŭ���� �����ͷ� �ڽ�Ŭ������ ����ŵ�ϴ�.������ ���� ���ε� �Դϴ�.
    ���� ���ε��� �ϴ� �θ� Ŭ������ �Լ��� ȣ��˴ϴ�.
    */
    Animal* lion1 = new Lion();
    lion1->Print();
    /**
    ���� �Ҵ����� ��ü�� ���������� �Լ��� ���������� ���� delete�����ڷ�
    �޸𸮿��� ��ü ������ �� �־�� �մϴ�.
    */
    delete lion1;

    cout << "" << endl;

    /**
    �ڽ� Ŭ������ �Լ��� ȣ��Ǳ⸦ �ٷ��µ�, �θ� Ŭ������ �Լ��� ȣ�� �Ǿ����ϴ�.

    AnimalŬ������ ������ �ֵ��� �մϴ�. 
    */

    /** �θ� Ŭ������ �Լ��� ���� �Լ��� ����� �־� ���� ���ε��� �� �־ �ذ��߽��ϴ�.*/
    Animal* lion2 = new Lion();
    lion2->Print();
    /**
    ���� �Ҵ����� ��ü�� ���������� �Լ��� ���������� ���� delete�����ڷ�
    �޸𸮿��� ��ü ������ �� �־�� �մϴ�.
    */
    delete lion2;

    cout << "" << endl;

    /**
    ���� ���� �Լ��� �����ϱ��?
    �����̶�� ���� ������ �������� �ʴ� �ٴ� �ǹ��Դϴ�.

    ������ �߰��� �ݴϴ�.
    */
    //Animal* animal1 = new Animal();
    //animal1->Print();

    //delete animal1;

    //cout << "" << endl;

    /** �θ� Ŭ������ �Լ��� ������ �������� �ʴ� ������ ���� �Լ��� ����� �ֵ��� �մϴ�.*/

    /**
    ������ ���ϴ�.
    ���� ���� �Լ��� ��ü�� ���� ���� �����ϴ�. ���� ���� �Լ��� ���� Ŭ������ �߻�Ŭ����
    ��� �մϴ�. �ڽ� Ŭ�������� �Լ��� ������ �־�� �մϴ�.
    */

    /**
    �ڽ� Ŭ�������� �������̵��� �Լ��� ������ �־�� �մϴ�.
    ������ ������ �ݴϴ�.

    �� �κ��� ��ü ���� ����� �߻�ȭ�Դϴ�.
    */
    Animal* animal2 = new Lion();
    animal2->Print();
    delete animal2;

    /**
    �׽�Ʈ�� ���ؼ� Circle�̶�� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.
    */



    /**
    �׽�Ʈ�� ���ؼ� Rectangle�̶�� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.
    */

    /**
    �׽�Ʈ�� ���ؼ� Shape�̶�� �̸��� �θ� Ŭ������ ������ �ֵ��� �մϴ�.
    */

    /**
    Circle Ŭ������ Rectangle Ŭ������ Shape Ŭ������ �θ� Ŭ������ ��� �޵��� �� �ݴϴ�.
    */

    /**
    Shape �θ� Ŭ�������� ���� ���� �Լ��� ������ �ֵ��� �մϴ�.
    */

    /**
    Ŭ���� �ȿ� ���� ���� �Լ��� ������ �߻� Ŭ������ �˴ϴ�.
    ���� �θ� Ŭ�����δ� ��ü�� ������ �� ���� �߻� Ŭ������ �Ǵ� ���Դϴ�.
    ������ �߰��� �ݴϴ�.
    */
    Shape* shapes[]{ new Circle(10), new Rectangle(20, 30) };

    for (Shape* shape : shapes)
    {
        shape->Resize(2);
    }

    for (Shape* shape : shapes)
    {
        /**
        ��ȯ���� ���� �Լ��� ����� ����� �� ������, ��ȯ���� �ִ� �Լ��� �����մϴ�.
        */
        cout << shape->GetArea() << endl;
    }

    for (Shape* shape : shapes)
    {
        delete shape;
    }

}

