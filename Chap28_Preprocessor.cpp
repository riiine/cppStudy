#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** #define 매크로로 상수를 정의해 주도록 합니다. */
#define PI 3.14159265
#define MY_NAME "James"
#define YEAR 2021
#define MONTH "Apr"
#define DAY 2

/**
#define 매크로를 이용하면 상수뿐만이 아니고 함수로 정의할 수가 있습니다.
정의해 주도록 합니다.
*/
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a > b)  a : b)

/**
#undef

#undef는 #define과 반대입니다.
#define으로 정의한 내용을 #undef로 정의를 없앨 수 있습니다.

정의해 주도록 합니다.
*/
#define WIDTH 80
#define ADD(X, Y) ((X) + (Y))

/** 정의된 매크로 상수의 정의를 풀어줍니다. */
#undef WIDTH
/** 정의된 매크로 함수의 정의를 풀어줍니다. */
#undef ADD

/**
#if defined(KOREAN)는 #ifdef KOREAN와 같습니다.
테스트를 위해서 KOREAN이라는 매크로 상수가 정의되어 있는지 확인을 해 봅니다.
정의해 주도록 합니다.
*/
#define KOREAN

/**
#if, #ifdef, #ifndef, #else, #elif, #endif는 다양한 방면에서 사용됩니다.

1. 헤더 파일이 중복되지 않도록 할 수 있습니다.
2. 운형체제를 구분하여 부분적으로 소스코드를 추가하거나 제거할 수 있습니다.

정의해 주도록 합니다.
*/
#ifdef _WIN32
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#endif

#ifdef linux
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#endif


int main()
{
    /**
    C++ 에서 컴파일 되는 과정입니다.

    1. 프로그래머가 작성한 소스코드는 가장 먼저 소스파일에 대한 처리를 하는 선행 처리기를 거치고
    2. 컴파일 되어 오브젝트 파일이 생성되고
    3. 다시 링커에 의해 실행파일이 됩니다.

    전처리이자 선행 처리(Preprocess)란
    실행 파일을 생성하는 과정에서
    컴파일 하기전 소스 파일 내에 존재하는 선행 처리 지시문을 처리하는 작업을 의미합니다.

    선행처리를 하는 명령어에는 #define, #include, #undef, #if, #elif, #else
    */

    /**
    #define

    상수를 이름으로 정의하거나 매크로 함수를 정의할 때 사용하는 전처리문입니다.
    #define을 잘 활용하면 가독성을 높일 수 있습니다.
    #define으로 상수를 선언하는 것을 특별히 매크로라고 합니다.

    다음과 같이 상수를 정의할 수 있습니다.
    보통 상수를 정의할 때는 일반 변수와 비교될 수 있도록 대문자로 정의합니다.
    #define PI 3.14159265

    상수를 정의하고 실제로 사용할 때는 PI라는 이름으로 사용하면 됩니다.
    선행 처리기가 #define문을 인식하고 PI부분을 3.14159265라는 상수값으로 치환합니다.
    */

    /** PI라는 상수를 정의해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    cout << "PI : " << PI << endl;
    cout << "MY_NAME : " << MY_NAME << endl;
    cout << "YEAR : " << YEAR << endl;
    cout << "MONTH : " << MONTH << endl;
    cout << "DAY : " << DAY << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    #define 매크로를 이용하면 상수뿐만이 아니고 함수로 정의할 수가 있습니다.
    정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
    cout << "SQUARE(9) : " << SQUARE(9) << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    그렇다면 매크로 함수와 멤버 함수의 차이점은 무엇일까요?

    1. 함수는 실행파일의 크기를 줄여주고 코드이 재사용성을 높여주지만 실행 속도가 늦어지는 단점이 있습니다
    2. 매크로 함수는 실행파일의 크기는 커지지만 실행 속도가 증가하는 장점이 있습니다.
    */

    /**
    #undef

    #undef는 #define과 반대입니다.
    #define으로 정의한 내용을 #undef로 정의를 없앨 수 있습니다.

    정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
    // cout << "WIDTH : " << WIDTH << endl;        // (X)
    // cout << "ADD(2, 3) : " << ADD(2, 3) << endl;// (X)

    cout << "" << endl;
    cout << "" << endl;

    /**
    #if, #elif, #else, #endif, #ifdef, #ifndef

    조건부 컴파일을 위한 전처리기 연산자입니다.
    조건부 컴파일 전처리기 연산자는 조건문인 if, else와 비숫합니다.

    #if 조건1
        코드1
    #elif 조건2
          코드2
    #else
          코드3
    #endif
    와 같은 형태로 사용됩니다.

    조건문과 비교를 해 보면

    if 대신에 #if, #ifdef (if defined), #ifndef (if not defined)
    else if 대신에 #elif
    else 대신에 #else
    조건부 컴파일 구분이 끝나는 곳에선 #endif를 붙입니다.

    #if defined(KOREAN)는 #ifdef KOREAN와 같습니다.
    테스트를 위해서 KOREAN이라는 매크로 상수가 정의되어 있는지 확인을 해 봅니다.
    정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
#if defined(KOREAN)
    cout << "KOREAN은 정의되어 있습니다. " << endl;
#else 
    cout << "KOREAN은 정의되어 있지 않습니다. " << endl;
#endif

    /**
    #if, #ifdef, #ifndef, #else, #elif, #endif는 다양한 방면에서 사용됩니다.

    1. 헤더 파일이 중복되지 않도록 할 수 있습니다.
    2. 운형체제를 구분하여 부분적으로 소스코드를 추가하거나 제거할 수 있습니다.

    정의해 주도록 합니다.
    */

    /**
    문자열 관련 라이브러리를 추가합니다.
    #include <string>       // C++ 라이브러리
    #include <string.h>     // C 라이브러리

    랜덤 관련 라이브러리
    #include <time.h>       // C 라이브러리
    */
}