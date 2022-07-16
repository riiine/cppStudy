#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 스마트 포인터 관련 라이브러리*/
#include <memory>
/** 벡터 컨테이너 관련 라이브러리*/
#include <vector>
/** 리스트 컨테이너 관련 라이브러리*/
#include <list>
/** 배열의 사이즈를 얻어오기 위한 라이브러리*/
#include <array>
/** 랜덤 관련 라이브러리*/
#include <time.h>
/** deque 컨테이너 관련 라이브러리*/
#include <deque>
/** queue 컨테이너 관련 라이브러리*/
#include <queue>
/** stack 컨테이너 관련 라이브러리*/
#include <stack>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

namespace Lion
{
    class Animal
    {
    public:
        void Eat(int value) {}
        void Eat(int value1, int value2) {}
        void Eat(float value) {}
        void Eat(int value1, float value2, string value3) {}
    };
}

namespace Tiger
{
    class Animal
    {
    public:
        void Eat(int value) {}
        void Eat(int value1, int value2) {}
        void Eat(float value) {}
        void Eat(int value1, float value2, string value3) {}
    };
}

int main()
{
    /**
    같은 클래스 안에 같은 이름의 함수가 존재할 수 있을까요?
    함수 오버로딩 : 매개 변수의 개수와 타입이 틀리면 같은 이름의 함수가 존재합니다.

    프로젝트에 같은 이름의 클래스가 존재할 수 있을까요?
    이름공간(namespace)으로 클래스를 감싸주면 프로젝트에 같은 이름의 클래스가 존재합니다.
    */

    /**
    queue는 FIFO (First In Firt Out)
        먼저 저장된 요소가 먼저 나갑니다.
    stack은 FILO (Fist in List Out)
        맨 나중에 저장된 요소가 먼저 나갑니다.

    따라서 제일 마지막에 넣은 데이터가 제일 먼저 빠져나갑니다.
    스택의 멤버 함수는 push(), pop(), empty(), top() 함수 등이 있습니다.


    폰의 Escape키를 누르면 5번이 빠져나가고, 4번이 빠져나가고, 3번이 빠져나가고, 2번이 빠져나가고
    5. 지도를 찾습니다.
    4. 영화를 봅니다.
    3. 음악을 듣습니다.
    2. 문자를 보냅니다.
    1. 폰으로 인터넷을 합니다.
    */

    cout << "스택 생성" << endl;
    stack<int> s;

    cout << "" << endl;
    cout << "" << endl;

    cout << "push(element) : 맨 위(top)에 요소를 추가합니다. " << endl;
    s.push(3);
    s.push(2);
    s.push(1);
    cout << "" << endl;

    /**
    스택 컨테이너에 요소가 없을 때까지 반복합니다.
    그런데 스택에 있는 요소들을 반복문으로 출력하는 것은 에러가 날 수 있고 비효율적입니다.
    디버거로 확인하는 것이 좋습니다.
    */
    //while (!s.empty())
    //{
    //    /** 맨 위에 있는 요소를 반환하고 출력합니다. */
    //    cout << s.top() << " ";
    //    /** 다음 요소를 출력하기 위해서 맨 위의 요소를 지웁니다. */
    //    s.pop();
    //}
    cout << "" << endl;
    cout << "" << endl;

    cout << "pop() : 맨 위에 있는 요소를 삭제합니다. " << endl;
    s.pop(); // 1이 삭제 됩니다. 
    cout << "" << endl;
    s.pop(); // 2가 삭제 됩니다. 

    cout << "" << endl;
    cout << "" << endl;

    cout << "size() : 스택 컨테이너의 사이즈를 반환합니다. " << endl;
    cout << "size : " << s.size() << endl;

    cout << "" << endl;
    cout << "" << endl;

    cout << "empty() : 스택이 비어 있으면 true 또는 1, 비어 있지 않으면 false 또는 0을 반환합니다. " << endl;

    /** 맨 위에 있는 요소를 삭제합니다. */
    s.pop();

    cout << "empty? : " << (s.empty() ? "true" : "fasle") << endl;
    cout << "empty? : " << s.empty();

    cout << "" << endl;
    cout << "" << endl;

    bool bIsEmpty = s.empty();
    cout << "bIsEmpty : " << bIsEmpty << endl;

    cout << "" << endl;
    cout << "" << endl;





}