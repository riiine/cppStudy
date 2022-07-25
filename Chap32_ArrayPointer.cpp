#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 배열의 사이즈를 알아오기 위한 라이브러리*/
#include <array>

/** C++ 표준 라이브러리 사용합니다.*/
using namespace std;

int main()
{
    /**
    1. 배열과 포인터
    2. 배열포인터
    3. 포인터배열
    */

    /** 배열포인터에 대해서 알아봅니다. */
    int intArr1[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int* intPtr1 = intArr1;

    for (int i = 0; i < size(intArr1); i++)
    {
        cout << *(intPtr1 + i) << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    for (int i = 0; i < size(intArr1); i++)
    {
        cout << intPtr1[i] << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /**
    3번째 문장이 헷갈립니다. 하지만 이렇게 이해하시면 됩니다. 
    intArr1[i] => *(intArr1 + i) => *(intPtr1 + i) => *(i + intPtr1) => i[intPtr1]
    */
    for (int i = 0; i < size(intArr1); i++)
    {
        cout << i[intPtr1] << " ";
    }
    cout << "" << endl;
    cout << "" << endl;
}


