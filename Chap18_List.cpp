#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** List 컨테이너에 접근하기 위한 라이브러리*/
#include <list>
/** 스마트 포인터를 쓰기 위한 라이브러리*/
#include <memory>
/** 배열의 사이즈를 알기 위한 라이브러리*/
#include <array>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

int main()
{
    /**
    vector 컨테이너나 list 컨테이너는 상당히 비숫합니다. 
    차이점이라면
    vector 컨테이너는 미리 일정 크기의 메모리를 할당해 놓고 그 이상의 값이 추가되면
    새로운 더 큰 메모리를 할당합니다. 최적화 이슈입니다. 
    문자열의 경우도 미리 메모리 할당을 했었습니다. capacity(용량)이었습니다. 

    하지만 list컨테이너는 값을 넣을 때마다 메모리를 할당하게 됩니다. 
    */

    /**
    맨 뒤에서만 추가, 삭제가 일어나는 경우는 vector 컨테이너가 빠르며 메모리도 적게 먹습니다. 
    순서와 상관없이 또는 순차적으로 추가, 삭제가 일어난다면 vector 컨테이너가 유리합니다. 
    반대로 순서가 중요하여 중간위치에 값이 추가, 삭제가 되는 경우
    리스트 컨테이너를 사용하는 것이 좋습니다. 

    vector 컨테이너는 중간에 추가, 삭제가 되면 뒤에 것들을 밀거나 당겨오는 작업이 필요합니다. 
    */

    /** 
    list 컨테이너는 모든 위치에서 접근이 가능한 컨테이너 입니다. 
    양방향으로 빠른 삽입및 삭제가 가능합니다. 
    하지만 컨테이너의 요소에 임의로 접근할 수가 없습니다. 
    인덱스로 접근이 불가능합니다. 반복자(iterator)로 접근해야만 합니다. 
    */

    /** 
    원소를 탐색할 때는 임의 접근 반복자(at(), [])
    리스트 컨테이너는 양방향 반복자(++, --)를 이용해서 탐색을 합니다. 
    리스터 컨테이너를 이중 연결 리스트(doubly linked list)라고 합니다. 
    */

    /** list 생성자*/

    /** 1. 비어 있는 리스트 컨테이너를 생성합니다. */
    list<int> lt1;

    /** 2. default 값인 0으로 초기화 된 요소 10개를 가진 리스트 컨테이너를 생성합니다. */
    list<int> lt2(10);

    for (int val : lt2)
    {
        cout << val << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 3. "Jane"의 값으로 초기화 된 요소 3개를 가진 리스트 컨테이너를 생성합니다. */
    list<string> lt3(3, "Jane");

    for (string val : lt3)
    {
        cout << val << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 4. 리스트 컨테이너인 lt3를 lt4로 복사합니다. */
    list<string> lt4(lt3);

    for (string val : lt4)
    {
        cout << val << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 리스트 컨테이너에서 제공하는 유용한 멤버 함수들에 대해서 알아 봅니다. */

    /** int타입을 여러개 저장할 수 있는 list타입의 intList1이라는 이름의 list를 선언합니다. */
    list<int> intList1;

    /** push_back(element) : 리스트 맨 뒤에 요소를 추가합니다. */
    intList1.push_back(22);
    intList1.push_back(33);
    intList1.push_back(44);
    intList1.push_back(55);

    /** 
    값을 확인하기 위해서는 반복자를 사용합니다. 
    begin() : 시작 반복자를 반환합니다. 
    end() : 끝 반복자의 다음 반복자를 반환합니다. 
    */

    /** 시작 반복자를 반환합니다. */
    list<int>::iterator iter = intList1.begin();

    /** 
    iter = intList1.begin()  초기값입니다. 시작 반복자입니다. 
    iter != intList1.end()  조건문입니다. 반복자가 끝 반복자의 다음 반복자가 아닐때까지
    iter++   증감문입니다. 
    */
    for (iter = intList1.begin(); iter != intList1.end(); iter++)
    {
        /** 반복자가 가리키는 실제 값을 출력하기 위해서 *(역참조 연산자)를 사용합니다. */
        cout << *iter << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 
    리스트 컨테이너는 인덱스로 접근이 안됩니다. 반복자로 접근합니다. 
    리스트 컨테이너의 특징은 foreach문이나 반복자를 이용해서 처음부터 끝까지 값을 출력합니다. 

    for (int i = 0; i < intList1.size(); i++)
    이와 같은 전형적이 for문으로 값을 확인할 수가 없습니다. 
    */
    for (int i = 0; i < intList1.size(); i++)
    {
        /** 인덱스로 접근이 안됩니다. */
        // cout << "intList1 : " << intList1[i] << endl; // (X)
    }

    /** push_front(element) : 리스트 컨테이너 맨 앞에 요소를 추가합니다. */
    intList1.push_front(11);
    intList1.push_front(77);

    for (iter = intList1.begin(); iter != intList1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** pop_front() : 리스트 컨테이너의 맨 앞의 요소를 삭제합니다. */
    intList1.pop_front();
    /** pop_back() : 리스트 컨테이너의 맨 뒤의 요소를 삭제합니다. */
    intList1.pop_back();

    for (iter = intList1.begin(); iter != intList1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** size() : 리스트 컨테이너의 사이즈를 반환합니다. */
    cout << "size : " << intList1.size() << endl;
    cout << "" << endl;
    cout << "" << endl;

    /** empty() : 리스트 컨테이너가 비어 있는 지 확인합니다. */
    cout << "empty : " << intList1.empty() << endl;
    cout << "" << endl;
    cout << "" << endl;

    /** 
    empty() 함수는 boolean타입으로 반환값을 갖습니다. 
    비어 있으면 true나 1의 값을 반환합니다. 
    비어 있지 않으면 false나 0의 값을 반환합니다. 
    */

    /** 만일 리스트 컨테이너에 요소가 하나도 없다면? */

    /** 비교 연산자 관련 추가*/
    if (intList1.empty())
    {
        cout << "리스트는 비어 있습니다. " << endl;
    }
    /** 그렇지 않고 만일 리스트에 요소들이 있다면? */
    else
    {
        cout << "리스트는 비어 있지 않습니다. " << endl;
        cout << "size : " << intList1.size() << endl;
    }

    /** 비교 연산자 관련 추가*/
    if (intList1.empty() == true)
    {
        cout << "리스트는 비어 있습니다. " << endl;
    }
    /** 그렇지 않고 만일 리스트에 요소들이 있다면? */
    else
    {
        cout << "리스트는 비어 있지 않습니다. " << endl;
        cout << "size : " << intList1.size() << endl;
    }

    /** 비교 연산자 관련 추가*/
    if (intList1.empty() == 1)
    {
        cout << "리스트는 비어 있습니다. " << endl;
    }
    /** 그렇지 않고 만일 리스트에 요소들이 있다면? */
    else
    {
        cout << "리스트는 비어 있지 않습니다. " << endl;
        cout << "size : " << intList1.size() << endl;
    }

    /** 인덱스와 반복자에 대해서 정리를 합니다. */

    /**
    프로그래밍 언어의 숫자는 0부터 시작합니다. 
    하지만 모든 언어의 숫자가 0부터 시작하지는 않습니다. 
    maxscript는 1부터 시작합니다. 

            0번째 인덱스  1번째 인덱스  2번째 인덱스  3번째 인덱스  4번째 인덱스  5번째 인덱스
    반복자는 인덱스가 아닙니다. 
            1번째 반복자  2번째 반복자  3번째 반복자  4번째 반복자  5번째 반복자  6번째 반복자
    */
    int intArr1[]{0,        1,          2,          3,          4,          5};

    /** front() : 첫번째 요소를 반환합니다. */
    cout << "front : " << intList1.front() << endl;
    cout << "" << endl;
    cout << "" << endl;

    /** back() : 마지막 요소를 반환합니다. */
    cout << "back : " << intList1.back() << endl;
    cout << "" << endl;
    cout << "" << endl;

    /** begin() : 시작 반복자(첫번째 반복자)를 반환합니다. */
    iter = intList1.begin();
    /**
    반복자를 2번째 위치로 이동합니다. 
    ++ 은 후치 증가 연산자가 아닙니다. 
    ++ 은 연산자 오버로딩이 되어 있는 다음 반복자를 가리킵니다. 
    */
    iter++;
    /** 반복자를 3번째 위치로 이동합니다. */
    iter++;

    /** insert(iterator, element) : 반복자가 가리키는 앞에 요소를 추가합니다. */
    /** 3번째 반복자 위치 앞에 100의 값을 삽입합니다. */
    intList1.insert(iter, 100);
    /** 자기를 증가시키는 증가 연산자는 후치 증가연산자이건 전치 증가연산자이건 상관이 없습니다. */
    // for (iter = intList1.begin(); iter != intList1.end(); ++iter)
    for (iter = intList1.begin(); iter != intList1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 
    begin() : 시작 반복자를 반환 합니다. 
    반복자를 초기화 하지 않으면 계속 반복자의 위치가 증가합니다. 
    따라서 반복자를 새로 사용할 때는 꼭 초기화를 해 주는 것이 안전합니다. 
    */
    iter = intList1.begin();
    /** 반복자 2번째 위치로 이동합니다. */
    iter++;
    /** 반복자 3번째 위치로 이동합니다. */
    iter++;
    /** 반복자 4번째 위치로 이동합니다. */
    iter++;

    /** erase(iterator) : 반복자가 가리키는 위치의 요소를 삭제합니다. */
    intList1.erase(iter);

    for (iter = intList1.begin(); iter != intList1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** clear() : 리스트 컨테이너의 요소를 모두 삭제합니다. */
    // intList1.clear();

    /** switch문 안에서 리스트 컨테이너가 비어 있는지 확인합니다. */
    switch (intList1.empty())
    {
    case 0:
        cout << "리스트 컨테이너는 비어 있지 않습니다. " << endl;
        cout << "size : " << intList1.size() << endl;
        break;
    case 1: 
        cout << "리스트 컨테이너는 비어 있습니다. " << endl;
        cout << "size : " << intList1.size() << endl;
        break;
    default:
        break;
    }

    /** a부터 z까지 출력해 봅니다. */
    list<char> charList;
    /** 리스트 컨테이너에 a부터 z까지 추가해 줍니다. */
    for (char c = 'a'; c <= 'z'; c++)
    {
        charList.push_back(c);
    }

    /** while문으로 조건 검사 해 봅니다. */
    /** 리스트 컨테이너의 사이즈가 empty가 아닐때까지 반복합니다. */
    while (!charList.empty())
    {
        /** 첫번째 요소를 반환해서 출력합니다. */
        cout << charList.front() << " ";
        /** 리스트 맨 앞에 요소를 삭제합니다. */
        charList.pop_front();
    }
    cout << "" << endl;
    cout << "" << endl;



}

