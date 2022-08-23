#include <iostream>

/** 문자열 관련 라이브러리 */
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** LinQ 관련 라이브러리*/
#include "cpplinq.hpp"

/** LinQ 라이브러리를 사용합니다. */
using namespace cpplinq;

int main()
{
    /**
    이번 시간에는 C++에서 LinQ라이브러리 사용하는 방법에 대해서 알아봅니다.

    라이브러리를 가져옵니다.
    https://github.com/mrange/cpplinq
    */

    /** 배열을 선언하고 초기화를 합니다. */
    int numbers1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    /** 배열에서 값을 2로 나누었을 때 0이 되는 요소들만을 모읍니다. */
    auto total = from_array(numbers1) 
        >> where([](int i) {return i % 2 == 0;  }) // where : 조건입니다. 값을 2로 나누었을 때 나머지가 0인 값을
        >> sum(); /** 모든 요소들의 값을 합쳐줍니다. */

    cout << "sum : " << total << endl;
    cout << "" << endl;
    cout << "" << endl;

    int numbers2[] = { 3, 1, 4, 1, 5, 9, 2, 6 };

    auto result2 = from_array(numbers2)
        >> distinct() // 값이 중복되면 지워줍니다.
        >> orderby_descending([](int i) {return i; }) // 내림차순으로 정렬합니다.
        >> select([](int i) {return i; }) // 값을 선택합니다.
        >> to_vector(); // 벡터 타입으로 변경해줍니다.

    for (int i : result2)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 문장을 추가해줍니다. */
    int numbers3[] = { 3, 1, 4, 1, 5, 9, 2, 6 };

    auto result3 = from_array(numbers3)
        >> distinct() // 값이 중복되면 지워줍니다.
        >> orderby([](int i) {return i; }) // 오름차순으로 정렬합니다.
        >> select([](int i) {return i;  }) // 선택합니다.
        >> to_vector(); //벡터 타입으로 변경합니다.

    for (int i : result3)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 합집합을 구해봅니다. */
    int intArr4[] = { 1, 3, 5, 7, 9, 7, 5, 3, 1 };

    vector<int> vector4;
    vector4.push_back(1);
    vector4.push_back(2);
    vector4.push_back(3);
    vector4.push_back(4);

    auto union1 = from_array(intArr4)
        >> union_with(from(vector4)) // intArr4와 vector4의 합집합을 구해봅니다.
        >> orderby([](int i) {return i; }) // 오름차순으로 정렬합니다.
        >> to_vector(); // 벡터 타입으로 변경합니다.

    for (int i : union1)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 교집합을 구해봅니다. */
    int intArr5[] = { 1, 3, 5, 7, 9, 7, 5, 3, 1 };

    vector<int> vector5;
    vector5.push_back(1);
    vector5.push_back(2);
    vector5.push_back(3);
    vector5.push_back(4);

    auto intersect1 = from_array(intArr5)
        >> intersect_with(from(vector5)) // 교집합을 구해봅니다.
        >> orderby([](int i) {return i; }) // 오름차순으로 정렬합니다.
        >> to_vector(); // 벡터 타입으로 변환합니다.

    for (int i : intersect1)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 차집합을 구해봅니다. */
    int intArr6[] = { 1, 3, 5, 7, 9, 7, 5, 3, 1 };

    vector<int> vector6;
    vector6.push_back(1);
    vector6.push_back(2);
    vector6.push_back(3);
    vector6.push_back(4);

    auto except1 = from_array(intArr6)
        >> except(from(vector6)) // 차집합을 구해봅니다.
        >> orderby([](int i) {return i; }) // 오름차순으로 정렬합니다.
        >> to_vector(); // 벡터 타입으로 변경합니다.

    for (int i : except1)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /**
    반복자에 대해서 알아봅니다.

    문장을 추가해줍니다.
    */
    vector<int> vector7 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto result7 = from_iterators(vector7.begin(), vector7.end());
    result7 >> for_each([](int i) {cout << "iterator : " << i << endl; });

    cout << "" << endl;
    cout << "" << endl;

    /**
    범위값으로 반복자를 만들어주도록 합니다.

    문장을 추가해줍니다.
    */
    vector<int> vector8 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto result8 = from(vector8);
    result8 >> for_each([](int i) {cout << "from : " << i << endl; });

    cout << "" << endl;
    cout << "" << endl;

    /**
    배열에서 반복하도록 해줍니다.

    문장을 추가해줍니다.
    */
    int intArr9[] = { 1, 2, 3, 4, 5 };
    auto result9 = from_array(intArr9);
    result9 >> for_each([](int i) {cout << "array : " << i << endl; });

    cout << "" << endl;
    cout << "" << endl;

    /**
    범위값으로 반복자를 만들어주도록 합니다.

    문장을 추가해줍니다.
    */
    /**
    10부터 시작해서 89개를 만들어 줍니다.
    그러므로 결과는 10에서 99까지가 표시됩니다.
    */
    auto result10 = range(10, 90);
    result10 >> for_each([](int i) {cout << "range : " << i << endl; });

    cout << "" << endl;
    cout << "" << endl;
}