#include <iostream>
// ���ڿ� ���� ���̺귯��
#include <string>

// C++ ǥ�� ���̺귯��
using namespace std;

// �׽�Ʈ�� ���ؼ� Parent1, Child1�̶�� �̸��� Ŭ������ ������ �ֵ��� �մϴ�. 
class Parent1
{
private: // ��������
    // ��ü���� ���� ��� ������ private������ �ξ ��� ������ ��ȣ�մϴ�. ĸ��ȭ
    // ��� �Լ��� ���ؼ��� ��� ������ ������ �� �ֽ��ϴ�. 
    // �ٸ� Ŭ���������� ��� ������ ���������� ������ �Ұ����ϰ� ��� ������ ��ȣ�ϴ� ���Դϴ�. 
    // ��� ������ ������ �̸��� ������ ��� ������ ���� �� �� �ֵ��� m, m_, _ �� ���� �̸��տ� �پ� �ݴϴ�. 

    // Parent1 Ŭ������ �ڽŸ��� ������ ������ ��� ���� m_IntValue1, m_IntValue2, m_IntValue3�� ������ �ֽ��ϴ�. 
    // private ���� ������ �ȿ� �ֱ� ������ �ڽ� Ŭ�������� ��� ������ ������ ���� �����ϴ�. 
    int m_IntValue1;
    int m_IntValue2;
    int m_IntValue3;
public: // ��������
    // ������ �Լ��� public ���� ������ �ȿ� �Ӵϴ�. 
    Parent1() {} // �Ű������� ���� ����Ʈ ������ �Դϴ�. 
    // �����ڷ� �ʱ�ȭ �ϴ� ����� 2������ �ֽ��ϴ�. 
    // 1. �Ϲ����� �����ڸ� ����ؼ� �ʱ�ȭ �ϴ� ����Դϴ�. 
    // �����ڸ� �̿��ؼ� ������ ���ο��� Ŭ���� ��� �������� �ʱ�ȭ �߽��ϴ�. 
    // m_IntValue1, m_IntValue2 ��� �������� �ʱ�ȭ ���� �ݴϴ�. 
    Parent1(int value1, int value2)
    {
        m_IntValue1 = value1;
        m_IntValue2 = value2;
    }

    // 2. �ʱ�ȭ ����Ʈ(Member Initialization List)�� �ʱ�ȭ �ϴ� ����Դϴ�. 
    // : (�ݷ�) �޺κ��� �ʱ�ȭ ����Ʈ�� �ʱ�ȭ�� �ϴ� �κ��Դϴ�. 
    // ������ �ʱ�ȭ��� �մϴ�. 
    Parent1(int value1, int value2, int value3) : m_IntValue1(value1), m_IntValue2(value2), m_IntValue3(value3) {}
    // ������ ���� ������(public ���� ������ �ȿ� �ֽ��ϴ�.)
    int Add()
    {
        return m_IntValue1 + m_IntValue2;
    }
protected: // ��ȣ�ϴ�
};

class Child1 : public Parent1
{
public:
    // Child1 Ŭ������ Parent1 Ŭ������ �θ� Ŭ����(Super Class)�� ����� �޽��ϴ�. 
    // �� �� �θ�Ŭ������ �ʱ�ȭ�� �ϴ� ����� : �θ�Ŭ������(�Ű�������1, �Ű�������2, ...)���� �ʱ�ȭ�� �� �� �ֽ��ϴ�.
    // Child1Ŭ������ Parent1 Ŭ������ ��� �޾ұ� ������ m_IntValue1, m_IntValue2 ��� ������ ������ ������ 
    // ������ �� �����ϴ�. 
    Child1(int value1, int value2) : Parent1(value1, value2) {}
};

// �׽�Ʈ�� ���ؼ� Parent2, Child2 ��� �̸��� Ŭ������ ������ �ֵ��� �մϴ�. 
class Parent2
{
public:
    Parent2()
    {
        cout << "Parent2 ������" << endl;
    }

    ~Parent2()
    {
        cout << "Parent2 �Ҹ���" << endl;
    }
};

class Child2 : public Parent2
{
public:
    Child2()
    {
        cout << "Child2 ������" << endl;
    }

    ~Child2()
    {
        cout << "Child2 �Ҹ���" << endl;
    }
};

/**
�׽�Ʈ�� ���ؼ� Parent3, Child3��� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.

��ü ���� ���� ��� ������ ������ private ���� ������ �ȿ� �Ӵϴ�.
�׽�Ʈ�� ���ؼ� ��� �������� protected, public ���� ������ �ȿ� �ξ����ϴ�.
��� ������ private ���� ������ �ȿ� �δ� ������ ��� ������ ��ȣ�Դϴ�.
*/
class Parent3
{
private:
    /**
    private ���� ������ �ȿ� �ֱ� ������ �ڽ� Ŭ�������� �ٷ� ������ �ȵ˴ϴ�.
    �ٸ� Ŭ���������� ��� �Լ��� ���ؼ� ������ �����մϴ�.
    */
    int m_IntValue1 = 10;
protected:
    /**
    protected ���� ������ �ȿ� �ֱ� ������ �θ� Ŭ������ ��ӹ��� �ڽ� Ŭ���������� ������ �����մϴ�.
    �ٸ� Ŭ���������� ��� �Լ��� ���ؼ� ������ �����մϴ�.
    */
    int m_IntValue2 = 10;
public:
    /**
    public ���� ������ �ȿ� �ֱ� ������ �ڽ� Ŭ�������� �Ӹ��� �ƴϰ� ��� Ŭ�������� ������ �����մϴ�.
    m_IntValue3 ������ ���� �ִ�� ������ �ִ� ���� 100���� �Դϴ�.
    */
    int m_IntValue3 = 10;
    /**
    ����Ʈ ������ �̴� ����Ʈ ������ �ʱ�ȭ �� �ݴϴ�.
    */
    Parent3()
    {
        m_IntValue1 = 0;
        m_IntValue2 = 0;
        m_IntValue3 = 0;
    }

    void SetValue(int value)
    {
        if (value > 100)
        {
            value = 100;
        }

        m_IntValue3 = value;
    }

    /**
    ��� ���� ��ȣ�� ���ؼ� ��� ������ ���� �����ϴ� �Լ����� const�� �ٿ��ݴϴ�.
    ��� ������ ��ȣ�� �ʿ䰡 ������ ��� ������ ���� �����ϴ� �Լ����� ����
    const�� �ٿ����� �ʾƵ� �˴ϴ�.
    */

    /**
    const�� �Լ� �ڿ� �ٿ� �ָ� �Լ��� �����ϴ� ���ȿ��� ��� ������ ���� �ٲ� ������ �����մϴ�.
    */
    int GetValueA() const
    {
        // m_IntValue1 = 50; // (X)
        return m_IntValue1;
    }

    int GetValueB()
    {
        m_IntValue1 = 50;
        return m_IntValue1;
    }
};

class Child3 : public Parent3
{
public:
    void SetInfo()
    {
        /**
        private ���� ������ �ȿ� �ֱ� ������ �ڽ� Ŭ�������� �ٷ� ������ �ȵ˴ϴ�.
        */
        // m_IntValue1 = 10; // error

        /**
        protected ���� ������ �ȿ� �ֱ� ������ �θ� Ŭ������ ��� ���� �ڽ� Ŭ���������� ������ �����մϴ�.
        */
        m_IntValue2 = 10;
        /**
        public ���� ������ �ȿ� �ֱ� ������ �ڽ� Ŭ���� �Ӹ��� �ƴϰ� ��� Ŭ�������� ������ �����մϴ�.
        */
        m_IntValue3 = 10;
    }
};

/**
�׽�Ʈ�� ���ؼ� Parent4, Child4 ��� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.
*/
class Parent4
{
    /**
    ���� �����ڰ� �����ϴ�.
    1. Ŭ�������� ���� �����ڰ� ������ ����Ʈ�� private ���� �����ڷ� �����˴ϴ�.
    2. ����ü������ ���� �����ڰ� ������ ����Ʈ�� public  ���� �����ڷ� �����˴ϴ�.
    */
    string m_Name;
    int m_Age;

    int GetAge() const
    {
        /**
        ���� ��ȯ�ϴ� �Լ��� const Ű���带 �ٿ��ָ� �Լ��� ����Ǵ� ���ȿ��� ��� ������ ���� ��������
        ���Ѵٴ� ���� �����մϴ�. �Ϲ������� ��� ������ ��ȯ�ϴ� �Լ��� const Ű���带 �ٿ��ݴϴ�.
        */
        // m_Age = 29; // (X)
        /**
        ��� ������ ���� �������� ������, ���� ������ ������ ��� �����ϴ�.
        */
        string name = "Smith";
        return m_Age;
    }
};

class Child4 : public Parent4
{
    int m_ID;
public:
    void Print()
    {
        /**
        Parent4 Ŭ������ �ְ�, Child4 Ŭ������ Parent4 Ŭ������ ��ӹ޾ҽ��ϴ�.
        Child4 Ŭ�������� Print() �Լ��� ��� �������� ȣ���Ϸ��� ������ �߻��մϴ�.
        �ֳ��ϸ� Parent4 Ŭ������ ���� �����ڸ� ���� �ʾƼ� ��� ������ private
        ���� �����ڷ� �����Ǳ� �����Դϴ�.

        GetAge() �Լ��� ���� ������ ���� �Լ��� ���� �Ǿ��� ������ private ���� �����ڷ� �����˴ϴ�.
        */
        // GetAge(); // (X)
        /**
        �θ� Ŭ�������� ��������� ���� ������ ���� �����߽��ϴ�.
        ��� �������� ����Ʈ�� private ���� �����ڷ� �����˴ϴ�.
        */
        // cout << m_Name << endl; // (X)
        // cout << m_Age << endl;  // (X)
        cout << m_ID << endl;
    }
};

/**
�׽�Ʈ�� ���ؼ� Parent5, Child5 ��� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.

�츮�� �߱��ؾ� �ϴ� ���α׷����� �з������� �������� ���������Դϴ�.
�������� ���� ���� �ڵ��̱���, ���������� ���� �����Դϴ�. ������ �ʿ��� �κ��Դϴ�.
���� : experence  ������ : expert  ������ ���� ����� ��������� �մϴ�.
*/
class Parent5
{
protected:
    string m_Name;
    int m_Age;
public:
    int GetAge() const
    {
        return m_Age;
    }

    /**
    ����Ʈ �����ڿ� �����ε��� �����ڸ� ������ �ݴϴ�.
    ����Ʈ �����ڴ� ���� �������� �ʾƵ� �˾Ƽ� �����˴ϴ�.
    */
    Parent5() {}
    /**
    : (�ݷ�) �ڴ� �ʱ�ȭ ����Ʈ�� �ʱ�ȭ�� �ϴ� �κ��Դϴ�.
    */
    Parent5(string name, int age) : m_Name(name), m_Age(age) {}
};

class Child5 : public Parent5
{
    int m_ID;
public:
    Child5()
    {
        m_Name = "";
        m_Age = 0;
        m_ID = 0;
    }

    Child5(string name, int age, int id) : Parent5(name, age), m_ID(id) {}

    void Print()
    {
        /**
        m_Name, m_Age ��� ������ �θ� Ŭ�������� protected ���� ������ �ȿ� �ֱ� ������
        �ڽ� Ŭ�������� ������ �����մϴ�.
        �θ�Ŭ���������� ��� ������ �����ϱ� ���ؼ� public ������ �ȿ� �ִ� GetAge() ��� �Լ��� ��� ������ �����մϴ�.
        �����ϴ� ����Դϴ�.

        protected ���� ������ �ȿ� �ȿ� ������ �ڽ� Ŭ�������� ���� ������ �����մϴ�. ������ ���鿡���� ���� ���� ����Դϴ�.
        */
        cout << "m_Name : " << m_Name << " ";
        cout << "m_Age : " << m_Age << " ";
        cout << "m_ID : " << m_ID << " ";
        cout << "" << endl;
    }
};

int main()
{
    // ��ü ���� ����� 4���� Ư¡
    // 1. ĸ��ȭ (���� ������ : private, protected, public)
    // 2. ���
    // 3. ������ (�Լ� �����ε�, �Լ� �������̵�(�Լ� ������))
    //    �Լ� �������̵� : �����Լ�, �������ε�,    ���� �����Լ�, �߻� Ŭ����
    // 4. �߻�ȭ

    // ���α׷��� ����� ������ �Ϻθ� �������ϰ� ������ �ʿ䰡 �����ϴ�. 
    // ��ü������(�߿��մϴ�.) ������� �ͼ��� ���ž� �մϴ�. 
    // �������� �κ��� ���۰˻��ϸ� �� ���ɴϴ�. 
    // �˻��� �ϱ� ���ؼ��� ��ü������ ������� �ͼ��� ���°��� �߿��մϴ�. 


    // Ŭ������ ����ü�� ������
    // ����ü�� ������ ���°� Ŭ�����Դϴ�. ���� ����մϴ�. 
    // �� �� �����, ������ �͵��� ���� ���� Ʋ�̶�� �������� ���������

    // ����ü : 
    // �ַ� ������(��� ����)�� �ֽ��ϴ�. 
    // C++ ������ ����ü���� �Լ��� ������ ������ C������ �ȵ˴ϴ�. 
    // C++ ���� ����ü�� Ŭ������ ��������� �����մϴ�. 
    // ��� ������ �ƴ϶� �����ڿ� �Ҹ��ڸ� ����� ��� �Լ��� ���� �� ������
    // �ٸ� ����ü�� Ŭ������ ��� �����ϰ�, �ٸ� ����ü�� Ŭ������ ��� ���� �� �ֽ��ϴ�. 
    // ������� ���� �����ڷ� �����Ǹ� ��� Ȱ�� ��� ���� Ŭ������ ������ �����մϴ�. 
    // C++ ������ �ϳ� Ʋ�� ���� �ִµ�, ���� �����ڸ� �������� ������ ����Ʈ�� public�Դϴ�. 

    // Ŭ���� : 
    // ���� ������ private, protected, public���� ��� ������ ��� �Լ��� ���� ���������� ������ �� �ֽ��ϴ�. 
    // ������(��� ����), ���(��� �Լ�)�� �����ϴ�.
    // C++ ������ �ϳ� �ٸ� ���� �ִµ�, ���� �����ڸ� �������� ������ ����Ʈ�� private�Դϴ�. 
    // C������ ȣ�ϼ��� ���ؼ� , ��� ������� �������� C ����ü�� C++���� �����ϱ� ���ؼ��Դϴ�. 


    // ���(Inheritance)
    // ��ü���� ���(C#, Java, C++, Smalltalk)������ �θ� Ŭ������ ��� ������ ��� �Լ��� 
    // �ڽ� Ŭ�������� ������ ���� �ֽ��ϴ�.
    // �� ��� ������ ��� �Լ��� ���� �����ڸ� �ξ �ƹ��� ������ �� ������ �� �� �ֽ��ϴ�. (private, protected, public)
    // ����ϴ� ����� : (�ݷ�)�� ����ϼ� ����� ���� �� �ֽ��ϴ�. 

    // �ٸ� Ŭ������ ���(������: ��� ����, ���: ��� �Լ�)�� �ΰ��ؼ� ���ο� Ŭ������ �����ϴ� ���Դϴ�. 
    // ���� Ư¡�ִ� Ŭ������ �״�� �����޾� ���� �����ϱ� ������ ȿ������ ���� �� �ֽ��ϴ�. 
    // �ڽ� Ŭ���������� �θ� Ŭ�����κ��� ��ӹ��� ��� �̿ܿ� �ڽŸ��� ���ο� ������� �߰��ؼ� ����� ���� �ֽ��ϴ�. 
    // ����� ���� ū ������ �θ� Ŭ������ ������� �ڽ� Ŭ�������� ���� �� �� �ֽ��ϴ�. 


    // ������(Constructor) :
    // Ŭ������ ��ü�� ������ �� �׻� ȣ��Ǵ� ��� �Լ��Դϴ�. 
    // Ŭ������ �޸𸮿� �����Ǹ� ��ü(�ν��Ͻ�, Instance)�� �˴ϴ�. 
    // ��ü�� ������ �� �پ��ϰ� ��� �������� �ʱ�ȭ�� �� �ݴϴ�. 
    // �ڽ��� Ŭ���� �̸��� ���������� ��ȯ�� ���� �Լ��� �������Դϴ�. 
    // �����ڸ� ����Ϸ��� �ݵ�� public���� �ؾ� �մϴ�. 
    // public���� �ؾ� �ϴ� ������ ��� ������ ������ �����ؾ� �ʱ�ȭ�� �ϰ� ��ü������ �� �� �ֱ� �����Դϴ�. 

    // �Ҹ���(Destructor) : 
    // �Ҹ��ڴ� ��ü�� �޸𸮿��� �Ҹ�(����)�� �� �����۾��� ����ϴ� ��� �Լ��Դϴ�. 
    // �Ҹ��ڴ� ��ȯ��, ���޹޴� �Ű������� ����,   ~Ŭ�����̸�() �����̾�� �մϴ�. 
    // ~ : ƿ��
    // �ַ� delete�����ڷ� ��ü�� �޸𸮿��� �������� �ִµ�, �Ҹ��ڿ��� �̷� �۾����� �� �ݴϴ�. 

    // �׽�Ʈ�� ���ؼ� Parent1, Child1�̶�� �̸��� Ŭ������ ������ �ֵ��� �մϴ�. 

    // ������ �����մϴ�. 
    // ������ �����ϰ�, ���� �����ؼ� �ʱ�ȭ �� �ݴϴ�. 
    // �Լ��� �Լ��� ������ �����մϴ�. 
    // �Լ��� �Լ��� ������ ����(����)�� �ݴϴ�. 
    // Ŭ������ ������ �ݴϴ�. 

    // �����Ҵ����� ��ü�� �����߽��ϴ�. 
    // �����Ҵ����� ������ ��ü�� �����ϱ� ���ؽ� .(dot)���� �����մϴ�. 
    Child1 child1(1, 2);
    // Add() �Լ��� �ڽ�Ŭ�������� ���ǰ� �ȵǾ� ������ �θ�Ŭ�������� ���� �Ǿ� �ֱ� ������ 
    // �ڽ�Ŭ�������� ����� �����մϴ�. 
    child1.Add();

    cout << "child1.Add() : " << child1.Add() << endl;

    cout << "" << endl;
    cout << "" << endl;

    // C++ ���� �����Ҵ����� ��ü�� �����ϴ� ����� 2������ �ֽ��ϴ�. 
    // 1. new �����ڸ� �̿��ؼ� ��ü�� �����մϴ�. 
    // 2. unique_ptr, shared_ptr�� ��ü�� �����մϴ�. 
    // �����Ҵ����� ������ ��ü�� �����ϱ� ���ؼ��� ->(ȭ��ǥ ������)�� ����մϴ�. 
    Child1* child1a = new Child1(1, 2);
    child1a->Add();

    cout << "child1a->Add() : " << child1a->Add() << endl;

    cout << "" << endl;
    cout << "" << endl;

    // ����� Ư¡
    // 1. �ڽ� Ŭ������ �����ڴ� �θ� Ŭ������ ��� ��������� �ʱ�ȭ�� �� �־�� �մϴ�. 
    // �׻� �θ� Ŭ������ �����ڰ� ���� ȣ��ǰ�, �� ������ �ڽ� Ŭ������ �����ڰ� ȣ��˴ϴ�. 
    // 2. �ڽ� Ŭ������ ������ ��� �θ� Ŭ������ �����ڴ� �ݵ�� ȣ��˴ϴ�. 
    // 3. �Ҹ����� ȣ�� ������ �����Դϴ�. 
    // �ڽ��� ���� �Ҹ�ǰ� �� �Ŀ� �θ� �Ҹ�˴ϴ�. 

    // �׽�Ʈ�� ���ؼ� Parent2, Child2 ��� �̸��� Ŭ������ ������ �ֵ��� �մϴ�. 

    Child2 child2;

    cout << "" << endl;
    cout << "" << endl;

    // new �����ڷ� ��ü ������ �ϸ� delete �����ڷ� �޸𸮿��� ��ü�� �� �־�߸� �մϴ�. 
    // delete �����ڷ� �޸� ������ ������ ������ �޸� ������ �߻��մϴ�. 
    Child2* child2a = new Child2();

    cout << "" << endl;
    cout << "" << endl;

    delete child2a;

    cout << "" << endl;
    cout << "" << endl;

    /**
    protected(��ȣ��) : �θ�Ŭ������ ��ӹ޴� �ڽ�Ŭ���������� ������ ������ ���� �������Դϴ�.
    */

    /**
    �׽�Ʈ�� ���ؼ� Parent3, Child3��� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.
    */

    /**
    m_IntValue3 ��� ������ ���� �ִ�� ������ �ִ� ���� 100���� �Դϴ�.
    */
    Parent3 parent3;
    // ������ ���� �� �ִ� �ִ밪�� 100�ε�, �� �̻��� ���� �������� �ֽ��ϴ�. 
    // ������ �����ϰ� �ʱ�ȭ�� ���� �־��� ������ ������ ���� ���ϴ�. 
    // int Ÿ���� -2147483648 ~ 2147483747
    // parent3.m_IntValue3 = 1000000000000000000; // ���� �����ϴ� ������ ������ ä�����ϴ�. 
    parent3.m_IntValue3 = 2048;
    /**
    ��� ������ �� ��ȣ�� ���ؼ� ��� ������ private ���� ������ �ȿ� �ΰ�
    ��� �Լ��� ���ؼ� ������ �մϴ�. �Լ��� ������ �ֵ��� �մϴ�.
    */
    cout << "parent3.m_IntValue3 : " << parent3.m_IntValue3 << endl;

    cout << "ĸ��ȭ, ������ ���� �����ϱ� ���ؼ� SetValue() �Լ��� ȣ���մϴ�. " << endl;
    parent3.SetValue(parent3.m_IntValue3);
    cout << "parent3.m_IntValue3 : " << parent3.m_IntValue3 << endl;

    cout << "" << endl;

    Child3 child3;
    // hild3.m_IntValue1 = 10; // Error
    // child3.m_IntValue2 = 10; // Error
    child3.m_IntValue3 = 10;

    cout << "" << endl;
    cout << "" << endl;

    /**
    �׽�Ʈ�� ���ؼ� Parent4, Child4 ��� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.
    */

    /**
    �׽�Ʈ�� ���ؼ� Parent5, Child5 ��� �̸��� Ŭ������ ������ �ֵ��� �մϴ�.
    */

    /**
    ���� �Ҵ����� ��ü�� �����߽��ϴ�.
    */
    Child5 child5;
    child5.Print();

    cout << "" << endl;
    cout << "" << endl;

    /**
    �����ڷ� ��ü�� ���� �߽��ϴ�.
    */
    Child5 child6("John", 22, 99);
    child6.Print();

    cout << "GetAge() : " << child6.GetAge() << endl;

    cout << "" << endl;
    cout << "" << endl;





} // main() �Լ��� ���Դϴ�. �Լ��� ����Ƿ� �����Ǿ��� ��ü���� �Ҹ��մϴ�. 
