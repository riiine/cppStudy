﻿#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/**
생성자 : 객체를 생성하면서 멤버 변수의 초기화를 담당합니다.
소멸자 : 객체가 메모리에서 해제될 때 호출됩니다.
         객체가 메모리에서 해제될 때 할 일들을 정의해줍니다.

테스트를 위해서 Fruit이라는 이름의 클래스를 정의해 주도록 합니다.
*/
class Fruit
{
/** 
공개적인, 외부 클래스에서 접근이 가능합니다.
객체지향 언어에서는 클래스 간 통신을 함수로 합니다.
그렇기 때문에 public 접근 지정자 안에 두어서 외부에서 접근이 가능하도록 합니다.
*/
public:
    /** : 뒤가 초기화 리스트로 초기화를 하는 과정입니다.*/
    Fruit() : m_Seed(2), m_Count(15)
    {
        cout << "생성자 호출 " << endl;
        cout << "Seed : " << m_Seed << ", Count : " << m_Count << endl;
    }
    /**
    생성자 오버로딩입니다.
    앞에 부분은 멤버 변수로 인식하고 뒤의 부분은 매개변수로 인식합니다.
    */
    Fruit(int seed, int count) : m_Seed(seed), m_Count(count)
    {
        cout << "생성자 호출 " << endl;
        cout << "Seed : " << m_Seed << ", Count : " << m_Count << endl;
    }
    /** 클래스 이름과 동일하면 ~(틸드)가 붙습니다. */
    ~Fruit() {
        cout << "소멸자 호출" << endl;
    }

/**
개인적인, 외부클래스에서 접근이 안 됩니다.
객체지향 언어에서는 멤버 변수는 무조건 private 접근 지정자 안에 둡니다.
멤버 변수의 보호(캡슐화)입니다.
*/
private:
    int m_Seed;
    int m_Count;
};

int main()
{
    /** 이번 시간에는 객체의 생성과 소멸에 대해서 알아봅니다.*/

    /**
    생성자 : 객체를 생성하면서 멤버 변수의 초기화를 담당합니다.
    소멸자 : 객체가 메모리에서 해제될 때 호출됩니다.
             객체가 메모리에서 해제될 때 할 일들을 정의해줍니다.

    테스트를 위해서 Fruit이라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /** 
    동적 할당으로 Fruit 객체를 생성해봅니다.
    동적 할당을 하게되면 스마트 포인터를 쓰지 않는 이상 delete연산자로 메모리 해제를 해주어야 합니다.
    */

    Fruit* fruit = new Fruit();
    delete fruit;
    cout << "" << endl;
    cout << "" << endl;


}


