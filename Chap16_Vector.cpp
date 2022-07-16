#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 벡터 컨테이너 관련 라이브러리*/
#include <vector>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

int main()
{
    /**
    자료구조와 알고리즘은 C언어 문법입니다. 
    C++에서는 STL(Standard Template Libarary)을 사용합니다. 

    STL의 종류
    vector, list, map, set, deque, queue, stack, pair, tuple
    */

    /**
    vector컨테이너는 자동으로 메모리가 할당되는 배열입니다. 
    자동으로 메모리를 할당해 주고, 알아서 끝에 들어가 주고, 알아서 삭제도 해 줍니다. 
    Teplate를 사용하기 때문에 데이터 타입은 어느 타입이던지 넣을 수 있습니다. 
    맨 뒤에서 삽입과 삭제가 가능합니다. 
    중간에 값을 삽입하거나 삭제할 수도 있습니다. 
    하지만 배열기반이므로 삽입, 삭제가 빈번하게 일어난다면 효율적이 아닙니다. 
    #include <vector> 해야만 합니다. 
    */

    /**
    Unity C#     array     List     Dictionary   HashSet
    native C++   array     vector   map          set
    Unreal C++             FArray   TMap         TSet
    */

    /** vector 컨테이너 생성 방법입니다. */

    /** 1. 비어 있는 vector1 컨테이너를 생성합니다. */
    vector<int> vector1;

    /** 2. 기본값 0으로 초기화 된 5개의 요소를 가지는 vector2 컨테이너를 생성합니다. */
    vector<int> vector2(5);

    for (int i : vector2)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 3. 2로 초기화 된 5개의 요소를 가지는 vector3 컨테이너를 생성합니다. */
    vector<int> vector3(5, 2);

    for (int i : vector3)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 4. vector4 컨테이너는 vector3 컨테이너를 복사해서 생성합니다. */
    vector<int> vector4(vector3);

    for (int i : vector4)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 
    vector 컨테이너의 멤버 함수들에 대해서 알아 봅니다. 
    문장을 추가해 줍니다. 
    */

    /** push_back() : vector 컨테이너 맨 뒤에 요소를 추가합니다. */
    vector<int> vector5;

    vector5.push_back(1);
    vector5.push_back(2);
    vector5.push_back(3);
    vector5.push_back(4);
    vector5.push_back(5);

    for (int i : vector5)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 
    at(index) : 인덱스로 요소를 참조합니다. 
    vector5[index] 보다 속도는 느리지만, 범위를 점검하므로 안전합니다. 
    */
    int index1 = vector5.at(1);

    cout << "vector5.at(1) : " << index1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    [index] : 배열의 인덱스처럼 요소를 참조합니다. 
    범위를 점검하지 않으므로 속도가 vector5.at(1) 보다 빠릅니다. 
    */
    int index2 = vector5[2];

    cout << "vector5[2] : " << index2 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** front() : 첫 번째 요소를 참조합니다. */
    int index3 = vector5.front();

    cout << "vector5.front() : " << index3 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** back() : 마지막 요소를 참조합니다. */
    int index4 = vector5.back();

    cout << "vector5.back() : " << index4 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 
    clear() : 모든 요소를 제거합니다. 
    요소만 제거하고 메모리에는 남아있습니다. 
    size(길이)만 줄어들고, capacity(용량)은 그대로 있습니다.  
    */
    vector5.clear();

    cout << "vector5.size() : " << vector5.size() << endl;
    cout << "vector5.capacity() : " << vector5.capacity() << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 테스트를 위해서 값을 추가해 주도록 합니다. */
    for (int i = 1; i <= 5; i++)
    {
        vector5.push_back(i);
    }

    for (int i : vector5)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** push_back(7) : 마지막 요소 뒤에 요소 7을 추가해 줍니다. */
    vector5.push_back(7);

    for (int i : vector5)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** pop_back() : 마지막 요소를 제거합니다. */
    vector5.pop_back();

    for (int i : vector5)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** reserve(n) : n개의 요소를 저장할 위치를 예약합니다. 미리 동적 할당을 해 놓습니다. */
    vector5.reserve(15);

    cout << "vector5.capacity() : " << vector5.capacity() << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    resize(n) : 크기를 n개로 변경해 줍니다. 
    만일 더 커졌을 경우 defalut값인 0으로 초기화를 해 줍니다. 
    */
    vector5.resize(10);

    cout << "vector5.size() : " << vector5.size() << endl;
    cout << "vector5.capacity() : " << vector5.capacity() << endl;

    for (int i : vector5)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /**
    resize(n, m) : 크기를 n개로 변경해 줍니다. 
    더 커졌을 경우 m값으로 초기화를 해 줍니다. 
    */
    vector5.resize(15, 3);

    cout << "vector5.size() : " << vector5.size() << endl;
    cout << "vector5.capacity() : " << vector5.capacity() << endl;

    for (int i : vector5)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 
    begin() : 첫번째 요소를 반환합니다. 반복자(Iterator)와 함께 사용합니다. 
    프로그래밍 언어에서 숫자는 0부터 시작합니다. 
    배열에서도 0번째 인덱스부터 시작합니다. 
    반복자는 인덱스가 아닙니다. 첫번째 부터 시작합니다. 
    */
    vector5.begin();

    cout << "" << endl;
    cout << "" << endl;

    /** end() : 마지막 요소의 다음을 반환합니다. 반복자(Iterator)와 함께 사용합니다. */
    vector5.end();

    cout << "" << endl;
    cout << "" << endl;

    /**
    rbegin() : 거꾸로 해서 첫번째 요소를 반환합니다. 반복자(Iterator)와 함께 사용합니다. 
    reverse begin
    */
    vector5.rbegin();

    cout << "" << endl;
    cout << "" << endl;

    /**
    rend() : 거꾸로 해서 마지막의 다음을 반환합니다. 반복자(Iterator)와 함께 사용합니다. 
    reverse end
    */
    vector5.rend();

    cout << "" << endl;
    cout << "" << endl;

    /**
    size는 데이터가 채워진 요소의 개수이고, capacity는 할당된 메모리 공간입니다. 
    문장을 추가해 줍니다. 
    */
    vector<string> names;

    names.push_back("Tom");
    names.push_back("Jane");
    names.push_back("John");
    names.push_back("Smith");
    names.push_back("Emma");
    names.push_back("James");
    names.push_back("Olive");
    names.push_back("Harry");
    names.push_back("Lucas");
    names.push_back("Owen");

    for (string name : names)
    {
        cout << name << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /**
    이런식으로 메모리 할당을 하는 이유는 push_back이 일어날 때마다 동적 할당을 하면
    비효율적이므로 미리 정해둔 만큼 동적 할당을 한번에 하는 것입니다. 
    */
    cout << "size : " << names.size() << endl;
    cout << "capacity : " << names.capacity() << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    vector 컨테이너의 size, capacity에 대한 테스트를 해 보도록 합니다. 
    문장을 추가해 줍니다. 
    */
    vector<int> vector6;

    for (int i = 0; i < 100; i++)
    {
        vector6.push_back(i + 1);

        cout << vector6[i] << ", size : " << vector6.size() << ", capacity : " << vector6.capacity() << endl;
    }

    cout << "" << endl;
    cout << "" << endl;



}
