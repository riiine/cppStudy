#include <iostream>

/** ���ڿ� ���� ���̺귯��*/
#include <string>
/** �迭�� ����� �������� ���� ���̺귯��*/
#include <array>

/** C++ ǥ�� ���̺귯��*/
using namespace std;

class Lion
{
public:
    /**
    �����ڵ��� ������ �ֵ��� �մϴ�.
    : �ݷ� �ڴ� ��� ������ ���� �ʱ�ȭ �� �ִ� ���Դϴ�.
    �����ڶ�� �ϰ� ��ȯ�����ڶ�� �մϴ�.
    */
    Lion(int eyeSight) : m_EyeSight(eyeSight)
    {
        cout << "Lion(int)" << endl;
    }

    Lion(string name) : m_Name(name)
    {
        cout << "Lion(string)" << endl;
    }

    Lion(int eyeSight, string name) : m_EyeSight(eyeSight), m_Name(name)
    {
        cout << "Lion(int, string)" << endl;
    }

    /** ��� �Լ��� �߰��� �ݴϴ�. */
    void SetInfo()
    {
        cout << "EyeSight : " << m_EyeSight << " : " << ", Name : " << m_Name << endl;
    }

    /**
    int Ÿ�������� ����ȯ ������ �����ε��Դϴ�.
    ����ȯ �Լ�(type conversion)��� �մϴ�.
    ����ȯ ������ �����ε��� ����ȯ �����ڸ� �����ϴ� ���ȿ� ��ü ��ü�� ���� �ٲ���
    �ʴ� �ٴ� ���� �����ϱ� ���ؼ� const Ű���带 �ٿ� �ݴϴ�.
    */
    operator int() const
    {
        return m_EyeSight;
    }

    /**
    ���ڿ� Ÿ�������� ����ȯ ������ �����ε��Դϴ�.
    ����ȯ �Լ�(type conversion function)��� �մϴ�.
    ����ȯ ������ �����ε��� ����ȯ �����ڸ� �����ϴ� ���ȿ� ��ü ��ü�� ���� �ٲ���
    �ʴ´ٴ� ���� �����ϱ� ���ؼ� const Ű���带 �ٿ� �ݴϴ�.
    */
    operator string() const
    {
        /** to_string() : �Ű� ������ �Է¹��� ���� ���ڿ��� ������ �ִ� �Լ��Դϴ�.*/
        string info = to_string(m_EyeSight) + " : " + m_Name;
        return info;
    }

private:
    /**
    ��ü ���� ������ ��� ������ private ���� ������ �ȿ� �Ӵϴ�.
    private ���� ������ �ȿ� �ΰ� �Ǹ� �ٸ� Ŭ��0������ ��� ������ ������ ���� �����ϴ�.
    ��� ������ �����ϱ� ���ؼ��� ��� �Լ��� ���ؼ� �����ϰ�
    ��� �Լ��� public ���� ������ �ȿ� �Ӵϴ�.
    ��� ������ ���� �̸��� ������ ��� �����ΰ��� �� �� �ֵ���
    ���� �̸� �տ� m, m_, _ ���λ縦 �ٿ� �ݴϴ�.
    */
    int m_EyeSight;  // �÷�
    string m_Name;
};

/**
���� �������� �Լ��� ������ �ֵ��� �մϴ�.
���� ������ �Լ����� �ǹ��մϴ�.
*/
void SetMessage(string info)
{
    cout << info << endl;
}

int main()
{
    /**
    ����ȯ�� C��� ��Ÿ���� ����ȯ�� C++ ��Ÿ���� ����ȯ�� �ֽ��ϴ�.
    C��� ��Ÿ���� ����ȯ�� 2���� ������ �ֽ��ϴ�.
    1. ������ ����ȯ(Implicit Cast) : �����Ϸ��� �ڵ������� ����ȯ�� ��Ű�� ���� �ǹ��մϴ�.
    �ַ� ���Կ����ڿ��� �߻��մϴ�.
    2. ����� ����ȯ(Explicit Cast) : ��������� �ڷ����� ���� ������ �ִ� ���� �ǹ��մϴ�.
    ���� �տ� �Ұ�ȣ() �� ���ؼ� ������ �� �ֽ��ϴ�.
    ����ȯ�� 3������ ����� ������ �ֽ��ϴ�.
    */

    /** �Ǽ� Ÿ���� ���� Ÿ������ ����ȯ �մϴ�. */
    float floatValue1 = 3.14159265f;
    int intValue1 = floatValue1;        // ������ ����ȯ
    int intValue2 = (int)floatValue1;   // ����� ����ȯ
    int intValue3 = int(floatValue1);   // ����� ����ȯ

    cout << "floatValue1 : " << floatValue1 << endl;
    cout << "float to int -> intValue1 : " << intValue1 << endl;
    cout << "float to int -> intValue2 : " << intValue2 << endl;
    cout << "float to int -> intValue3 : " << intValue3 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** �Ǽ� Ÿ���� ���� Ÿ������ ����ȯ �ϸ� �Ǽ� Ÿ���� �Ҽ��� �Ʒ� ������ ��� �������ϴ�. */
    int intValue4 = 3.14159265f;
    float floatValue4 = 1024;

    cout << "intValue4 : " << intValue4 << ", floatValue4 : " << floatValue4 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** ����� ���� ���ϴ�.*/
    int math = 90;
    int korean = 85;
    int english = 95;
    int history = 97;
    /** �հ踦 ���� ���ϴ�. */
    int sum = math + korean + english + history;
    /** ����� ���� ���ϴ�. */
    int average = sum / 4;

    cout << "sum : " << sum << ", average : " << average << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    ����� 91.75�� ���;� �ϴµ�, 91�� ���ɴϴ�.
    ���� / ���� = ����
    �Ǽ� / ���� = �Ǽ�
    ���� / �Ǽ� = �Ǽ�
    �Ǽ� / �Ǽ� = �Ǽ�
    */

    /** ������ ������ �ֵ��� �մϴ�. */
    // int averageScore = (float)sum / 4;  // ����� ����ȯ
    float averageScore = (float)sum / 4;  // ����� ����ȯ

    cout << "sum : " << sum << ", averageScore : " << averageScore << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** �׽�Ʈ�� ���ؼ� Lion�̶�� �̸��� Ŭ������ ������ �ֵ��� �մϴ�. */

    /**
    ������ ȣ��� ��ü ������ �� �ֵ��� �մϴ�.
    ��ü ������ �پ��� ǥ�� ����� �ֽ��ϴ�.
    */
    Lion lion1 = Lion(10);
    Lion lion2(2);
    Lion lion3 = 25;
    lion3 = 30;   // ��ȯ �����ڿ� ���� ������ ����ȭ
    Lion lion4 = (Lion)30; // ����� ����ȯ

    cout << "" << endl;
    cout << "" << endl;

    /**
    ���ڿ��� �Ű������� ������ �ִ� �����ڸ� ȣ���� ���ϴ�.
    C++ �� C����� ����  ��� ������ �����ϴµ�, C���� ���ڿ� Ÿ���� �������ϴ�.
    C���� booleanŸ�Ե� �������ϴ�.
    ���ڿ��� �⺻ �ڷ����� �ƴմϴ�.
    �⺻ �ڷ��� : char, int, long, float, double, bool
    ���ڿ� Ÿ���� �ܺζ��̺귯�� �Դϴ� #include <string>
    ������ ����� ���ڿ� Ÿ������ ����� ����ȯ�� �� �ֵ��� �մϴ�.
    */
    // Lion lion5 = "Simba"; // (X)
    Lion lion5 = (string)"Simba";  // ��ȯ �����ڿ� ���� ����� ����ȯ
    Lion lion6 = string("KingLion");
    lion6 = (string)"White";       // ��ȯ �����ڿ� ���� ����� ����ȯ
    lion6 = string("Black");

    cout << "" << endl;
    cout << "" << endl;

    /** ����Ÿ�԰� ���ڿ� Ÿ���� ��� �Ű������� ������ �ִ� ������ ȣ���� ���ϴ�. */
    Lion lion7(30, "Simba");
    Lion lion8 = { 25, "KingLion" };
    lion8 = { 30, "White" };
    Lion lion9{ 20, "Black" };

    cout << "" << endl;
    cout << "" << endl;

    cout << "����Ÿ���� �Ű������� ���� �����ڷ� ��ü ����" << endl;
    /** ���ڿ� Ÿ���� �����ϰ� ���� ���� ������? nullptr�Դϴ�. �� ���ڿ��� �ƴմϴ�. */
    lion1.SetInfo();
    lion2.SetInfo();
    lion3.SetInfo();
    lion4.SetInfo();
    cout << "" << endl;

    cout << "���ڿ� Ÿ���� �Ű������� ���� �����ڷ� ��ü ����" << endl;
    /** ���� Ÿ�Կ� ������ ���� ���ϴ�. */
    lion5.SetInfo();
    lion6.SetInfo();
    cout << "" << endl;

    cout << "����Ÿ�԰� ���ڿ� Ÿ���� �Ű������� ���� �����ڷ� ��ü ����" << endl;
    lion7.SetInfo();
    lion8.SetInfo();
    lion9.SetInfo();
    cout << "" << endl;

    /**
    ��ȯ �����ڷ� �������� LionŸ������ ����ȯ �� ���ҽ��ϴ�.
    �ݴ�� LionŸ���� ���������� ��ȯ�� �� ���� ���?
    ������ ���鼭 ��ȯ�� ���� �ʽ��ϴ�.
    */
    // int intValue5 = lion9;       // (X)
    // int intValue6 = (int)lion9;  // (X) ����� ����ȯ

    /**
    ����ȯ ��ü�� �������Դϴ�. ����ȯ �����ڶ�� �մϴ�.
    ������ �����ε����� �ذ��� �� �ֽ��ϴ�.
    int Ÿ�������� ����ȯ ������ �����ε��� �� �ֵ��� �մϴ�.
    ����ȯ �Լ�(type conversion) �̶�� �մϴ�.
    */
    int intValue5 = lion9;      // ������ ����ȯ   
    int intValue6 = (int)lion9; // ����� ����ȯ

    cout << "intValue5 : " << intValue5 << endl;
    cout << "intValue6 : " << intValue6 << endl;

    cout << "" << endl;
    cout << "" << endl;


    /**
    ���ڿ� Ÿ���� LionŸ������ ����ȯ �� ���ҽ��ϴ�.
    �ݴ�� LionŸ���� ���ڿ� Ÿ������ ��ȯ�� �� �ִ��� �˾� ���ϴ�.
    ��ȯ�� ���� �ʽ��ϴ�.
    */
    // string strLion8 = lion8; // (X)
    // string strLion9 = (string)lion9; // (X)

    /**
    ������ �����ε����� �ذ� �� �� �ֽ��ϴ�.
    ���ڿ� Ÿ�������� ����ȯ ������ �����ε��� ���ֵ��� �մϴ�.
    ����ȯ ������ �����ε��� ����ȯ �Լ�(type conversion function)��� �մϴ�.
    */

    /**
    �پ��� ������� Lion��ü�� ���ڿ��� ������ ���ϴ�.
    Lion��ü�� ������ ���� �ϳ��� ���ڿ��� �Ű������� ������ ��ü�� �����ϱ� �����Դϴ�.
    �ݴ�� ��ü�� ������ �ִ� ���ڿ��� ���ڿ� ������ �־��ִ� ���Դϴ�.
    */

    string strLion = lion8;
    /**
    SetMessage() �Լ��� �Ű������� ���ڿ� Ÿ���Դϴ�.
    ���� lion9 ��ü�� ���ڿ��� ������ ����ȯ�� �ȴٰ� �� �� �ֽ��ϴ�.
    */
    SetMessage((string)lion8);      // ����� ����ȯ

    SetMessage(lion8);              // ������ ����ȯ
    cout << (string)lion8 << endl;  // ����� ����ȯ

    cout << lion8 << endl;          // lion8 ��ü�� �׳� ��� �߽��ϴ�. 
    string strLion8 = lion8;        // ������ ����ȯ
    cout << strLion8 << endl;

    /**
    �⺻���� �ຯȯ ������ �߽��ϴ�.
    C++ ���� ����ȯ�� ���� �ֽ��ϴ�.
    */
}
