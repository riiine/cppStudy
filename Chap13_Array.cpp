#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 배열의 사이즈를 가져오기 위한 라이브러리*/
#include <array>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/**
모든 자료형을 배열로 만들 수 있습니다. 구조체를 배열로 만들어 봅니다.
Rectangle이라는 이름의 구조체를 정의해 주도록 합니다.
*/
struct Rectangle
{
    int width;
    int height;
};

/**
상수(constant)란?

상수는 값이 변하지 않는 것을 의미합니다.
상수에 넣는 데이터로는 숫자만 오는 것이 아니라 클래스나 구조체 같은 객체도 올 수 있습니다.
테스트를 위해서 Fruit이라는 이름의 구조체를 정의해 주도록 합니다.
*/
struct Fruit
{
    string name;
    int count;
};


int main()
{
    /**
    배열(array)은 같은 자료형을 여러개 저장할 수 있는 타입입니다.
    다음과 같은 변수가 있다고 가정합니다.
    */
    int score0;
    int score1;
    int score2;
    //   ~
    int score498;
    int score499;
    int score500;

    /**
    무척 비효율적입니다. 다음과 같이 배열을 선언해 줍니다.
    배열을 사용하면 위의 작업을 훨씬 쉽고, 효율적으로 실행할 수 있습니다.
    */

    /**
    int타입을 여러개 저장할 수 있는 배열타입으로 score라는 이름의 배열 변수를 선언했습니다.
    요소의 개수를 30개로 초기화 해 주었습니다.
    대괄호 []를 사용해서 배열 변수에 할당할 배열 길이를 지정합니다.

    자료형 배열이름[배열길이];
    */
    int score[30];

    /**
    배열에 있는 각 변수를 요소(element)라고 합니다.
    요소에는 고유한 이름이 없습니다.
    대신 배열의 개별 요소에 접근하려면 배열 이름을 하위 연산자([])와 함께 사용하며
    원하는 요소를 알려주는 인덱스(index)라는 매개 변수를 사용합니다.

    배열이름[인덱스]

    프로그래밍 언어에서 숫자는 0부터 시작합니다.

    score[0]    : score배열의 0번째 인덱스, score배열의 첫 번째 요소입니다.
    score[1]    : score배열의 1번째 인덱스, score배열의 두 번째 요소입니다.
    score[2]    : score배열의 2번째 인덱스, score배열의 세 번째 요소입니다.
    score[9]    : score배열의 9번째 인덱스, score배열의 열 번째 요소입니다.
    score[29]   : score배열의 29번째 인덱스, score배열의 마지막 요소입니다.

    배열의 인덱스는 0부터 시작합니다.
    */

    /** 문장을 추가해 줍니다. */
    /**
    string타입을 여러개 저장할 수 있는 names라는 이름의 배열 변수를 선언했습니다.
    사이즈를 5로 지정해서 초기화를 했습니다.
    */
    string names[5];
    names[0] = "John";
    names[1] = "Jane";
    names[2] = "Tom";
    names[3] = "Smith";
    names[4] = "James";

    cout << "for문 : " << endl;

    for (int i = 0; i < size(names); i++)
    {
        cout << names[i] << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "foreach문 : " << endl;

    for (string name : names)
    {
        cout << name << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /**
    모든 자료형을 배열로 만들 수 있습니다. 구조체를 배열로 만들어 봅니다. 
    Rectangle이라는 이름의 구조체를 정의해 주도록 합니다. 
    */

    /** 문장을 추가해 줍니다. */
    Rectangle rectangles[5];
    rectangles[0].width = 20;
    rectangles[0].height = 10;
    rectangles[1].width = 22;
    rectangles[1].height = 30;
    rectangles[2].width = 55;
    rectangles[2].height = 60;

    /**
    배열은 사이즈를 다시 정해주기 전까지는 사이즈를 줄이거나 늘릴 수가 없습니다. 
    문장을 추가해 줍니다. 
    */
    // rectangles[10].width = 25; // (X)
    // rectangles[10].height = 100; // (X)

    cout << "for문 : " << endl;

    for (int i = 0; i < size(rectangles); i++)
    {
        cout << "width : " << rectangles[i].width << ", height : " << rectangles[i].height << endl;
    }
    cout << "" << endl;

    cout << "foreach문 : " << endl;

    for (Rectangle rec : rectangles)
    {
        cout << "width : " << rec.width << ", height : " << rec.height << endl;
    }
    cout << "" << endl;

    /**
    고정 배열(fixed array)을 선언할 때 배열의 길이(대괄호 사이)는 컴파일 타임 상수여야 합니다. 
    컴파일 타임에 고정 배열의 길이를 알아야 하기 때문입니다. 
    */

    /**
    상수(constant)란? 

    상수는 값이 변하지 않는 것을 의미합니다. 
    상수에 넣는 데이터로는 숫자만 오는 것이 아니라 클래스나 구조체 같은 객체도 올 수 있습니다. 
    테스트를 위해서 Fruit이라는 이름의 구조체를 정의해 주도록 합니다. 
    */

    /** 문장을 추가해 줍니다. */
    const Fruit fruit = {"Apple", 10};
    // fruit.name = "Banama"; // (X)
    // fruit.count = 30; // (X)

    /**
    리터럴(Literal)이란? 
    리터럴은 데이터(값) 그 자체를 의미합니다. 즉 변수에 넣는 변하지 않는  데이터를 의미합니다. 
    */
    /** intValue1은 상수변수이고, 1은 리터럴 값입니다. */
    const int intValue1 = 1;
    /** stringValue1은 상수변수이고, "Jane"은 리터럴 값입니다. */
    const string stringValue1 = "Jane";

    /** 고정배열을 선언하는 4가지 방법입니다. */

    /** 첫 번째는 리터럴 상수를 사용합니다. */
    int intArr1[5];

    /** 두 번째는 매크로 기호 상수를 사용합니다. */
#define ARRAY_LENGTH 5
    int intArr2[ARRAY_LENGTH];

    /** 세 번째는 상수변수 사용입니다. */
    const int arrayLength = 5;
    int intArr3[arrayLength];

    /** 네번째는 열거형 사용입니다. */
    enum EArrayLength {MaxArrayLength = 10};
    int intArr4[EArrayLength::MaxArrayLength];

    /** 
    다음은 좋지 않은 예입니다. 
    문장을 추가해 줍니다. 
    */
    /** 비-상수 변수 사용*/
    int arrayLength1 = 10;
    // int intArr5[arrayLength1]; // (X)

    /** 런타임 상수 변수 사용*/
    int arrayLength2 = 5;
    /** arrayLength3값은 컴파일 타임에서는 알 수 없으므로 런타임 상수입니다. */
    const int arrayLength3 = arrayLength2;
    // int intArray5[arrayLength3]; // (X)

    /**     
    배열은 선언과 동시에 초기값을 줄 수 있습니다. 
    문장을 추가해 줍니다.     
    */
    string friends1[5] = {"John", "Tom", "Jane", "Smith", "James"};

    /** 요소의 개수로 사이즈를 알 수 있기 때문에 사이즈를 명시하지 않아도 됩니다. */
    string friends2[] = { "John", "Tom", "Jane", "Smith", "James" };

    cout << "foreach문 : " << endl;

    for (auto name : friends1)
    {
        cout << name << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /**
    배열의 초기화에 대한 정리를 해 봅니다. 
    문장을 추가해 줍니다. 
    */

    /** 일반적인 배열 선언입니다. */
    int intArr5[3];
    intArr5[0] = 1;
    intArr5[1] = 2;
    intArr5[2] = 3;

    cout << "intArr5 : ";

    for (int i : intArr5)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 배열을 선언하고 초기화를 해 줍니다. */
    int intArr6[4] = {10, 20, 30, 40};

    cout << "intArr6 : ";

    for (int i : intArr6)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 배열을 선언하고 전부 초기화 하지 않아도 됩니다. 나머지는 기본값으로 채워집니다. */
    int intArr7[10] = {10, 20};

    cout << "intArr7 : ";

    for (int i : intArr7)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 대입 연산자가 없어도 됩니다. */
    int intArr8[3]{10, 20, 30};

    cout << "intArr8 : ";

    for (int i : intArr8)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 배열의 요소를 전부 0으로 설정합니다. */
    int intArr9[10] = {0};

    cout << "intArr9 : ";

    for (int i : intArr9)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    int intArr10[20] = {};

    cout << "intArr10 : ";

    for (int i : intArr10)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;


    int intArr11[30]{};

    cout << "intArr11 : ";

    for (int i : intArr11)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 요소의 개수로 사이즈를 알 수 있기 때문에 사이즈를 명시하지 않아도 됩니다. */
    int intArr12[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "intArr12 : ";

    for (int i : intArr12)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 대입연산자가 없어도 되며, 사이즈를 명시하지 않아도 됩니다. */
    int intArr13[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "intArr13 : ";

    for (int i : intArr13)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** C++ 스타일로 할 수도 있습니다. */
    array<int, 5> intArr14 = {1, 2, 3, 4, 5};

    cout << "intArr14 : ";

    for (int i : intArr14)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;



}
