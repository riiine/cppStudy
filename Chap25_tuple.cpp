#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 배열의 사이즈를 가져오기 위한 라이브러리*/
#include <array>
/** pair 컨테이너 관련 라이브러리*/
#include <utility>
/** tuple 컨테이너 관련 라이브러리*/
#include <tuple>

/** vector 컨테이너 관련 라이브러리*/
#include <vector>

/** queue 컨테이너 관련 라이브러리*/
#include <queue>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

int main()
{
    /** 
    tuple 컨테이너의 특징
    
    일반적으로 함수에서 반환을 할 때는 하나만 반환됩니다. 
    만일 2개가 반환되어야 하는 경우는 pair 컨테이너를 씁니다. 
    만일 2개 이상이 반환되어야 하는 경우는 tuple 컨테이너를 씁니다.
    */

    /**
    서로 연관이 있는 데이터끼리 값을 묶고 싶을 때가 있습니다. 
    이러할 경우 직접 클래스나 구조체를 만들어서 묶을 수도 있지만
    복잡한 반복적인 동작이 필요한 경우가 아닌 경우 pair와 tuple을 사용하는 것이 좋습니다. 

    2쌍의 값을 묶고 싶다면 pair 컨테이너를 사용합니다. 
    2쌍 이상의 값을 묶고 싶다면 tuple 컨테이너를 사용합니다. 
    */

    vector<pair<int, int>> vector1;
    vector1.push_back(make_pair(5, 6));
    vector1.push_back(make_pair(3, 2));
    vector1.push_back(make_pair(1, 8));
    vector1.push_back(make_pair(4, 3));

    for (int i = 0; i < vector1.size(); i++)
    {
        cout << vector1[i].first << " : " << vector1[i].second << endl;
    }
    cout << "" << endl;
    cout << "" << endl;

    vector<tuple<int, string, int>> vector2;
    vector2.push_back(make_tuple(1, "John", 3));
    vector2.push_back(make_tuple(2, "Jane", 7));
    vector2.push_back(make_tuple(3, "Smith", 5));
    vector2.push_back(make_tuple(4, "Emma", 9));
    /**
    pair와 tuple은 make_pair() 함수와 make_tuple() 함수로 간단하게 생성할 수 있습니다. 
    tuple은 값을 읽을 시 get을 사용하는데 get<튜플에서 읽어올 값 인덱스>(튜플)의 형식입니다. 
    */
    for (int i = 0; i < vector2.size(); i++)
    {
        cout << get<0>(vector2[i]) << " : " << get<1>(vector2[i]) << " : " << get<2>(vector2[i]) << endl;
    }

    cout << "" << endl;
    cout << "" << endl;

    /** 알고리즘 문제를 풀 때 큐(queue)나 스택(stack)에 push할 때 파라미터를 보통 1개나 2개를 넣는 경우가 있습니다. */
    int intValue1;
    int intValue2;
    int intValue3;

    queue<pair<int, int>> queue1;

    intValue1 = 3;
    intValue2 = 5;

    queue1.push(make_pair(intValue1, intValue2));

    cout << "queue1.front().first : " << queue1.front().first << ", queue1.front().second : " << queue1.front().second << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** pair는 매개 변수를 최대 2개까지 밖에 할 수 없지만 매개 변수가 2개 이상일 때는 tuple을 사용할 수 있습니다. */
    intValue1 = 3;
    intValue2 = 5;
    intValue3 = 7;

    queue<tuple<int, int, int>> queue2;

    queue2.push(make_tuple(intValue1, intValue2, intValue3));

    cout << "queue2 : " << " ";

    cout << "get<0>(queue2.front()) : " << get<0>(queue2.front()) << " ";
    cout << "get<1>(queue2.front()) : " << get<1>(queue2.front()) << " ";
    cout << "get<2>(queue2.front()) : " << get<2>(queue2.front()) << " ";

    cout << "" << endl;
    cout << "" << endl;

    /** 두 가지 방법으로 튜플을 초기화할 수 있습니다. */
    tuple<int, string, bool> tuple1(1, "Robert", true);
    tuple<int, string, bool> tuple2 = make_tuple(2, "Anna", false);

    /** tuple1 요소를 출력합니다. */
    cout << "tuple1 : " << " ";
    cout << get<0>(tuple1) << " ";
    cout << get<1>(tuple1) << " ";
    cout << get<2>(tuple1) << " ";

    cout << "" << endl;
    cout << "" << endl;

    /** tuple2 요소를 출력합니다.  */
    cout << "tuple1 : " << " ";
    cout << get<0>(tuple2) << " ";
    cout << get<1>(tuple2) << " ";
    cout << get<2>(tuple2) << " ";

    cout << "" << endl;
    cout << "" << endl;

    /**
    튜플은 함께 사용되는 변수들을 하나로 묶어서 사용할 때 유용합니다. 
    특히 함수의 반환값으로 2개 이상의 값을 반환할 때 자주 사용됩니다. 
    보통 변수들을 묶을 때 구조체를 사용하지만 tuple을 사용하면 편리한 점이 많습니다. 
    2개의 데이터를 묶을 때는 pair를 사용하고, 2개 이상의 데이터를 묶을 때는 tuple을 사용합니다. 
    */
    int intValue4 = 10;
    char charValue4 = 'A';
    string stringValue4 = "Jane";
    /** 
    tuple 에 int, char, string 3가지 타입을 tuple로 묶었습니다. 
    tuple은 값을 참조할 때 get을 사용합니다. 
    get은 해당 값을 얻어올 수도 있고, 저장된 값을 변경할 수도 있습니다. 
    값을 얻어올 때 : get<0>(tuple3)
    값을 변경할 때 : get<0>(tuple3) = 10
    */
    tuple<int, char, string> tuple3 = tuple<int, char, string>(intValue4, charValue4, stringValue4);

    cout << get<0>(tuple3) << " ";
    cout << get<1>(tuple3) << " ";
    cout << get<2>(tuple3) << " ";
    cout << "" << endl;
    cout << "" << endl;

    get<0>(tuple3) = 20;
    get<1>(tuple3) = 'B';
    get<2>(tuple3) = "Smith";

    cout << get<0>(tuple3) << " ";
    cout << get<1>(tuple3) << " ";
    cout << get<2>(tuple3) << " ";
    cout << "" << endl;
    cout << "" << endl;

    /** tuple_size() : tuple에 저장된 데이터의 개수를 반환합니다. */
    tuple<int, int, int, char, string> tuple5 = make_tuple(10, 20, 30, 'C', "Tom");
    uint32_t tupleCount = tuple_size<decltype(tuple5)>::value;

    cout << "tuple5 size : " << tupleCount << endl;
    cout << "" << endl;
    cout << "" << endl;

    /** tuple_cat() : tuple과 tuple을 합칠 수 있습니다. */
    tuple<int, char, string> tuple6 = make_tuple(10, 'A', "Emma");
    tuple<int, char, string> tuple7 = make_tuple(20, 'B', "James");
    auto tupleCat = tuple_cat(tuple6, tuple7);

    cout << get<0>(tupleCat) << " ";
    cout << get<1>(tupleCat) << " ";
    cout << get<2>(tupleCat) << " ";
    cout << get<3>(tupleCat) << " ";
    cout << get<4>(tupleCat) << " ";
    cout << get<5>(tupleCat) << " ";

    cout << "" << endl;
    cout << "" << endl;



}
