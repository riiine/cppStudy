#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 스마트 포인터 관련 라이브러리*/
#include <memory>
/** 벡터 컨테이너 관련 라이브러리*/
#include <vector>
/** 리스트 컨테이너 관련 라이브러리*/
#include <list>
/** 배열의 사이즈를 가져오기 위한 라이브러리*/
#include <array>
/** 랜덤 관련 라이브러리*/
#include <time.h>
/** deque 컨테이너 관련 라이브러리*/
#include <deque>
/** queue 컨테이너 관련 라이브러리*/
#include <queue>

/**C++ 표준 라이브러리 사용합니다. */
using namespace std;


int main()
{
    /**
    queue 컨테이너의 특징
    queue 컨테이너는 FIFO(first in first out) 구조입니다.
    가장 먼저 들어온 원소가 가장 먼저 나가는 구조입니다.
    queue의 기본 함수에는 push(), pop(), emtpy(), front(), back() 함수들이 있습니다.
    스택과 달리 front 요소와 back 요소에 접근할 수 있다는 점이 특징입니다.
    */

    cout << "큐 생성" << endl;
    queue<int> que1;

    cout << "" << endl;
    cout << "" << endl;

    cout << "push(element) : 큐 컨테이너 맨 뒤에 요소를 추가합니다. " << endl;

    for (int i = 0; i < 10; i++)
    {
        // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        que1.push(i);
    }
    cout << "" << endl;

    /** queue 컨테이너는 for문이나 foreach문으로 요소가 출력되지 않습니다. */

    //for (int i = 0; i < que1.size(); i++)
    //{
    //    cout << que1[i] << endl;
    //}

    /**
    queue 컨테이너에 요소가 있을 때까지 반복합니다.

    queue 컨테이너에 요소값을 주었는데, 요소값을 출력해 보기 위해서는 요소를 지워야 하는
    비효율이 발생합니다.
    */
    //while (!que1.empty())
    //{
    //    /** 맨 앞에 있는 요소를 반환해서 출력합니다.*/
    //    cout << que1.front() << " ";
    //    /** 맨 앞에 있는 요소를 지웁니다. */
    //    que1.pop();
    //}
    cout << "" << endl;
    cout << "" << endl;

    cout << "pop() : 큐 컨테이너의 맨 앞에 잇는 요소를 삭제합니다. " << endl;

    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    que1.pop(); // 맨 앞의 0의 요소를 삭제합니다. 
    cout << "" << endl;

    que1.pop(); // 맨 앞의 1의 요소를 삭제합니다. 
    cout << "" << endl;

    que1.pop(); // 맨 앞에 2의 요소를 삭제합니다. 
    cout << "" << endl;

    cout << "front() : 큐의 맨 앞에 있는 요소를 반환합니다. " << endl;
    cout << "front : " << que1.front() << endl;

    cout << "" << endl;
    cout << "" << endl;

    cout << "back() : 큐의 맨 뒤에 있는 요소를 반환합니다. " << endl;
    cout << "back : " << que1.back() << endl;

    cout << "" << endl;
    cout << "" << endl;

    cout << "size() : 큐 컨테이너의 사이즈를 반환합니다. " << endl;
    cout << "size : " << que1.size() << endl;

    cout << "" << endl;
    cout << "" << endl;

    cout << "empty() : 큐 컨테이너가 비어 있다면 true 또는 1, 비어 있지 않다면 false 또는 0을 반환합니다. " << endl;
    cout << "empty? : " << (que1.empty() ? "true" : "false") << endl;
    cout << "empty? : " << que1.empty() << endl;
}