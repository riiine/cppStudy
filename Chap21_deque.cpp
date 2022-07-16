#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 스마트 포인터 관련 라이브러리*/
#include <memory>
/** 벡터 컨테이너 관련 라이브러리*/
#include <vector>
/** 리스트 컨테이너 관련 라이브러리*/
#include <list>
/** 배열의 사이즈를 알아오기 위한 라이브러리*/
#include <array>
/** 랜덤 관련 라이브러리*/
#include <time.h>
/** deque 컨테이너 관련 라이브러리*/
#include <deque>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;


int main()
{
    /**
    STL : Standard Template Library
    Templete : <> 꺽쇠괄호
    <> 에 모든 타입을 넣을 수가 있습니다. 
    STL의 종류 : array(X), vector, list, map, set, deque, queue, stack, pair, tuple
    */

    /**
    deque 컨테이너의 특징
    1. deque는 vector의 단점을 보완하기 위해서 만들어진 컨테이너입니다. 
    2. deque는 vector와 마찬가지로 배열 기반의 구조입니다. 
    3. vector는 새로운 요소를 추가할 때 메모리 재할당 후 이전 요소를 복사하는 비효율적인 방식으로 인해서
        삽입시에 성능이 저하되는 단점이 있습니다. 
    4. deque는 이러한 vector의 단점을 보완하기 위해서 여러개의 메모리 블록을 할당하고 하나의
        블록처럼 여기는 기능을 제공합니다. 
    5. deque는 메모리가 부족할 때마다 일정한 크기의 새로운 블럭을 할당합니다. 
        vector의 단점으로 볼 수 있는 이전 요소를 복사하지 않습니다. 
    6. deque는 중간에 요소를 삽입하거나 삭제할 수 있습니다. 
    */

    /** deque 컨테이너 생성*/

    cout << "0번째, 비어 있는 deque 컨테이너를 생성합니다. " << endl;
    deque<int> dq0;

    cout << "" << endl;

    cout << "1번째. 1, 2, 3, 4, 5의 초기값을 가지고 초기화해서 deque 컨테이너를 생성합니다. " << endl;
    deque<int> dq1 = {1, 2, 3, 4, 5};

    for (int i : dq1)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "2번째. default값인 0으로 초기화 된 10개의 요소를 가진 deque 컨테이너를 생성합니다. " << endl;
    deque<int> dq2(10);

    for (int i : dq2)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "3번째. 4의 값으로 초기화 된 10개의 요소를 가진 deque 컨테이너를 생성합니다.  " << endl;
    deque<int> dq3(10, 4);

    for (int i : dq3)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "4번째. deque 컨테이너의 요소들을 복사해서 deque 컨테이너를 생성합니다. " << endl;
    deque<int> dq4(dq3);

    for (int i : dq4)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** deque 컨테이너에서 제공하는 멤버 함수들에 대해서 알아 봅니다. */

    deque<int> dq5;

    for (int i = 0; i < 5; i++)
    {
        /** 맨 끝에 요소를 추가합니다. */
        // 10, 20, 30, 40, 50
        dq5.push_back((i + 1) * 10);
    }

    for (int i : dq5)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "컨테이너와 반복자 선언입니다. " << endl;
    deque<int>::iterator iter;

    for (iter = dq5.begin(); iter != dq5.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "deque 컨테이너 앞과 뒤에 요소를 추가합니다. " << endl;

    dq5.push_front(1); // 맨 앞에 요소를 추가합니다. 
    dq5.push_front(2); // 맨 앞에 요소를 추가합니다. 
    dq5.push_back(100);// 맨 뒤에 요소를 추가합니다. 
    dq5.push_back(200);// 맨 뒤에 요소를 추가합니다. 

    for (iter = dq5.begin(); iter != dq5.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "역으로 deque 컨테이너의 요소들의 값을 출력해 봅니다. " << endl;

    /**
    rbegin() : reverse begin, 맨 끝의 반복자를 반환합니다. 
    rend() : reverse end, 맨 앞의 반복자의 앞을 반환합니다. 
    */
    /** 역순환을 위해서 아예 역 반복자를 제공합니다. */
    deque<int>::reverse_iterator reverseIter;
    // deque<int>::iterator reverseIter; // (X)

    for (reverseIter = dq5.rbegin(); reverseIter != dq5.rend(); reverseIter++)
    {
        cout << *reverseIter << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "문자열로 테스트를 해 봅니다. " << endl;
    deque<string> dq6;

    dq6.push_front("Jane"); // 컨테이너의 맨 앞에 요소를 추가합니다. 
    dq6.push_back("John");  // 컨테이너의 맨 뒤에 요소를 추가합니다. 
    dq6.push_front("Tom");  // 컨테이너의 맨 앞에 요소를 추가합니다. 
    dq6.push_back("Smith"); // 컨테이너의 맨 뒤에 요소를 추가합니다. 
    dq6.push_front("James");// 컨테이너의 맨 앞에 요소를 추가합니다. 
    /** 반복자를 정의해 줍니다. */
    deque<string>::iterator iter1;

    for (iter1 = dq6.begin(); iter1 != dq6.end(); iter1++)
    {
        cout << *iter1 << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "insert() : 정해진 반복자 앞에 요소를 삽입합니다. " << endl;
    /**
    반복자를 다시 사용하기 위해서는 꼭 초기화를 해 주어야 합니다. 
    초기화를 해 주지 않으면 에러가 날 수 있습니다. 
    */
    deque<string>::iterator iter3 = dq6.begin();
    /** 반복자를 2번째 인덱스, 3번째 반복자 위치로 옮겼습니다. */
    iter3 += 2;
    /** 2번째 인덱스, 3번째 반복자의 위치 앞에 "Emma"라는 문자열을 2번 삽입했습니다. */
    dq6.insert(iter3, 2, "Emna");

    for (iter1 = dq6.begin(); iter1 != dq6.end(); iter1++)
    {
        cout << *iter1 << " ";
    }
    cout << "" << endl;
    cout << "" << endl;


    cout << "요소를 지워봅니다. " << endl;
    /** end() 는 맨 마지막 반복자의 다음을 가리킵니다. */
    iter3 = dq6.end();
    /** 맨 마지막 반복자를 가리켜 줍니다. */
    iter3--;
    cout << "iter3 : " << *iter3 << endl;
    /** 맨 마지막 반복자의 바로 앞에 반복자를 가리켜 줍니다. */
    iter3--;
    cout << "iter3 : " << *iter3 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 반복자가 가리키는 요소를 지워줍니다. */
    dq6.erase(iter3);

    for (iter1 = dq6.begin(); iter1 != dq6.end(); iter1++)
    {
        cout << *iter1 << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "at() : 인덱스로 요소에 접근합니다. " << endl;

    for (int i = 0; i < dq6.size(); i++)
    {
        cout << dq6.at(i) << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "인덱스로 접근해 봅니다. " << endl;

    for (int i = 0; i < dq6.size(); i++)
    {
        cout << dq6[i] << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "deque 컨테이너의 맨 뒤와 맨 앞의 요소를 삭제할 수 있습니다. " << endl;
    /** 맨 뒤의 요소 삭제*/
    dq6.pop_back();
    /** 맨 앞의 요소 삭제*/
    dq6.pop_front();

    for (iter1 = dq6.begin(); iter1 != dq6.end(); iter1++)
    {
        cout << *iter1 << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "첫번째 요소, 마지막 번째 요소에 접근할 수가 있습니다. " << endl;
    cout << "front() : 맨 앞의 요소에 접근합니다. " << endl;
    cout << "front : " << dq6.front() << endl;
    cout << "" << endl;

    cout << "back() : 맨 뒤의 요소에 접근합니다. " << endl;
    cout << "back : " << dq6.back() << endl;
    cout << "" << endl;
}

