#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 배열의 사이즈를 가져오기 위한 라이브러리*/
#include <array>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 테스트를 위해서 EAnimal이라는 이름의 열거형을 정의해 줍니다. */
enum EAnimal
{
    /**
    열거자(Enumerator, 이뉴머레이터)
    각 열거자는 세미콜론(;)이 아니라 쉼표(,)로 구분됩니다. 
    열거자는 내부적으로 정수값입니다. 
    열거자는 초기화를 하지 않으면 0부터 시작합니다. 
    */
    Lion,       // 0
    Tiger,      // 1
    Elephant,   // 2
    Dog,        // 3
    Cat,        // 4
    Eagle,      // 5
    MaxAnimal,  // 6   열거자의 요소수를 알기 위한 
};/** enum 자체는 ;(세미콜론)으로 끝내야 합니다. */

/** 테스트를 위해 EItem이라는 이름의 열거형을 정의해 줍니다. */
enum EItem
{
    /**
    초기화를 하게 되면 다음과 같이 값을 지정해 줄 수 있습니다. 
    그 이후의 원소들은 값이 1씩 증가해서 자동적으로 설정됩니다. 
    */
    DailyItem = -3,
    WeeklyItem,  // -2
    GamemoneyItem, // -1
    GoldItem = 7,
    CashItem = 7,
    VIPItem,    // 8
    MaxItem = 6,    // 9  열거형의  요소수를 지금은 알 수 없습니다. 
}; 

class TestClass
{
public:
    //EAnimal lion = EAnimal::Lion;
    //EAnimal tiger(EAnimal::Cat);
    //EAnimal elephant{ EAnimal::Elephant };

    // TestEnum // main함수 안에 있기 때문에 외부에서 접근 불가능합니다. 
};

EAnimal lion = EAnimal::Lion;
EAnimal tiger(EAnimal::Cat);
EAnimal elephant{ EAnimal::Elephant };

void TestGlobalFunction()
{
    EAnimal lion = EAnimal::Lion;
    EAnimal tiger(EAnimal::Cat);
    EAnimal elephant{ EAnimal::Elephant };
}

/**
열거형을 문자열로도 변경할 수도 있습니다.
테스트를 위해서 EColor라는 이름의 열거형을 정의해 주도록 합니다.
*/
enum EColor
{
    Black,      // 0
    Red,        // 1
    Blue,       // 2
    Green,      // 3
    White,      // 4
    Yellow,     // 5
    Max,        // 6 열거형의 요소수를 알기 위한
}; /** enum 자체는 ;(세미콜론)으로 끝나야 합니다. */

/**
열거형의 요소를 문자열로 변경할 수 있습니다.
배열을 선언하고 값을 주어서 초기화를 해 주도록 합니다.
*/
string colors[] = {"Black", "Red", "Blue", "Green", "White", "Yellow"};

/** 테스트를 위해서 EMonth라는 이름의 열거형을 정의 해 주도록 합니다. */
enum EMonth
{
    January = 1,
    February,
    March,
    April,
    May, 
    June,
    July,
    August,
    September,
    October,
    November,
    December,
    /**
    열거형의 요소는 전역처럼 작동하기 때문에 서로 다른 enum 영역이라도 변수명이 같으면 오류가 납니다. 
    같은 영역내에서 동일한 변수ㅗ 선언 불가능합니다. 
    */
    // Max, // (X)
    MaxMonth,
};

/**
typedef : type definition, 타입을 정의해 줍니다. 별명 또는 별칭을 지어 줍니다.
typedef를 사용하여 enum 키워드를 생략할 수도 있습니다.
테스트를 위해서 ESeason이라는 이름의 열거형을 정의해 줍니다.
*/
typedef enum season // 열거형의 이름은 season입니다. 
{
    Spring, 
    Summer,
    Fall,
    Winter,
    MaxSeason,
}ESeason; // typedef를 사용하여 열거형의 별칭을 ESeason으로 정의했습니다. 

/**
열거형을 정의하는 동시에 변수를 선언할 수도 있습니다.
테스트를 위해서 EWeek라는 이름의 열거형을 정의해 줍니다.
*/
enum EWeek
{
    Sunday = 0,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    MaxWeek,
} week; /** 열거형을 정의하는 동시에 변수 week를 사용합니다. */

/**
enum 클래스 사용법
테스트를 위해서 ERainbowColor라는 이름의 열거형을 정의 해 줍니다.
*/
enum class ERainbowColor
{
    Red,
    Orange,
    Yellow,
    Green,
    Blue,
    Indigo,
    Violet,
    MaxRainbowColor,
};

/** 
배열을 선언하고 값을 주어서 초기화를 해 주도록 합니다. 
enum class의 요소도 문자열로 변경해 보기 위해서 배열을 선언하고 초기값을 주었습니다. 
*/
string rainbowColors[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};


int main()
{
    enum TestEnum
    {
        One,
        Two,
        Three,
    };

    /**
    무언가 구분할 일이 있다면 열거형을 정의해서 사용합니다. 
    열거형은 내부적으로는 정수값이지만 외부로 보이기에는 문자열이라서 가독성이 좋습니다. 
    또한 내부적으로 정수값이라서 값을 비교할 때 빠릅니다. 
    게임에서 아이템구분, 몬스터 구분, 플레이어 직업 구분, 스테이지 구분등
    구분할 필요가 있는 것들은 모두 열거형을 사용합니다. 
    */

    /** 테스트를 위해서 EAnimal이라는 이름의 열거형을 정의해 줍니다. */

    /** 문장을 추가해 줍니다. */
    EAnimal lion = EAnimal::Lion;
    EAnimal tiger(EAnimal::Tiger);
    EAnimal elephant{EAnimal::Elephant};

    cout << "lion : " << lion << endl;
    cout << "tiger : " << tiger << endl;
    cout << "elephant : " << elephant << endl;

    cout << "" << endl;

    /**
    열거형의 값을 명시적으로 정의할 수 있습니다. 
    이러한 정수 값은 양 또는 음의 값일 수 있으며 다른 열거형과 같은 값을 공유할 수 있습니다. 
    정의되지 않는 모든 열거형은 이전 열거형보다 1 더 큰 값이 부여 됩니다. 
    */

    /** 테스트를 위해 EItem이라는 이름의 열거형을 정의해 줍니다. */

    /** 
    열거형 변수는 정수 변수에 할당할 수 있습니다. 
    문장을 추가해 줍니다. 
    */
    int dailyItem = EItem::DailyItem;
    int weeklyItem = EItem::WeeklyItem;
    int gameMoneyItem = EItem::GamemoneyItem;
    int goldItem = EItem::GoldItem;
    int cashItem = EItem::CashItem;
    int vipItem = EItem::VIPItem;

    cout << "dailyItem : " << dailyItem << endl;
    cout << "weeklyItem : " << weeklyItem << endl;
    cout << "gameMoneyItem : " << gameMoneyItem << endl;
    cout << "goldItem : " << goldItem << endl;
    cout << "cashItem : " << cashItem << endl;
    cout << "vipItem : " << vipItem << endl;

    cout << "" << endl;

    /** 열거형 요소의 소속을 표시하지 않아도 됩니다. */

    cout << "EItem::DailyItem : " << EItem::DailyItem << endl;
    cout << "EItem::WeeklyItem : " << EItem::WeeklyItem << endl;
    cout << "EItem::GamemoneyItem : " << EItem::GamemoneyItem << endl;
    cout << "EItem::GoldItem : " << EItem::GoldItem << endl;
    cout << "EItem::CashItem : " << EItem::CashItem << endl;
    cout << "EItem::VIPItem : " << EItem::VIPItem << endl;

    cout << "" << endl;

    cout << "DailyItem : " << DailyItem << endl;
    cout << "WeeklyItem : " << WeeklyItem << endl;
    cout << "GamemoneyItem : " << GamemoneyItem << endl;
    cout << "GoldItem : " << GoldItem << endl;
    cout << "CashItem : " << CashItem << endl;
    cout << "VIPItem : " << VIPItem << endl;

    cout << "" << endl;

    /**
    컴파일러는 정수를 열거형 값으로 암시적으로 변환하지 않습니다. 
    다음과 같은 경우 컴파일 오류가 발생합니다. 
    */
    // VIPItem = 3; // (X)

    /** static_cast를 통해 강제로 변환이 가능합니다. 문장을 추가해 줍니다. */
    EItem item = static_cast<EItem>(5);
    cout << "item : " << item << endl;
    cout << "" << endl;
    cout << "" << endl;

    /**
    정수값을 열거형으로 변경해 봅니다. 
    열거형 요소의 내부 정수값을 초기화 해 줍니다. 
    */
    dailyItem = static_cast<EItem>(0);
    weeklyItem = static_cast<EItem>(1);
    gameMoneyItem = static_cast<EItem>(2);
    goldItem = static_cast<EItem>(3);
    cashItem = static_cast<EItem>(4);
    vipItem = static_cast<EItem>(5);

    cout << "dailyItem : " << dailyItem << endl;
    cout << "weeklyItem : " << weeklyItem << endl;
    cout << "gameMoneyItem : " << gameMoneyItem << endl;
    cout << "goldItem : " << goldItem << endl;
    cout << "cashItem : " << cashItem << endl;
    cout << "vipItem : " << vipItem << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    열거형을 문자열로도 변경할 수도 있습니다. 
    테스트를 위해서 EColor라는 이름의 열거형을 정의해 주도록 합니다. 
    */

    /** 
    C++ 11 (2011년)
    C++ 14 (2014년)
    C++ 17 (2017년)
    C++ 20 (2020년)
    */

    /**
    열거형의 요소를 문자열로 변경할 수 있습니다. 
    배열을 선언하고 값을 주어서 초기화를 해 주도록 합니다. 
    */

    /** 
    문장을 추가해 줍니다. 
    배열은 인덱스로 접근해서 값을 가져옵니다. 
    열거형은 내부 값이 정수값이니 인덱스로 사용할 수가 있습니다. 
    */
    string black = colors[EColor::Black];
    string red = colors[EColor::Red];
    string blue = colors[EColor::Blue];
    string green = colors[EColor::Green];
    string white = colors[EColor::White];
    string yellow = colors[EColor::Yellow];

    cout << "black : " << black << endl;
    cout << "red : " << red << endl;
    cout << "blue : " << blue << endl;
    cout << "green : " << green << endl;
    cout << "white : " << white << endl;
    cout << "yellow : " << yellow << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 반복문으로 확인해 봅니다. */
    for (int i = 0; i < EColor::Max; i++)
    {
        EColor color = static_cast<EColor>(i);
        string name = colors[i];

        cout << "color : " << color << ", name : " << name << endl;
    }

    cout << "" << endl;
    cout << "" << endl;

    int indexArray = 0;

    for (auto color : colors)
    {
        EColor color = static_cast<EColor>(indexArray);
        string name = colors[indexArray];
        indexArray++;

        cout << "color : " << color << ", name : " << name << endl;
    }

    cout << "" << endl;
    cout << "" << endl;

    /** 테스트를 위해서 EMonth라는 이름의 열거형을 정의 해 주도록 합니다. */

    /** switch문으로 테스트를 해 봅니다. */
    EMonth month = EMonth::July;

    switch (month)
    {
    case EMonth::December:
    case EMonth::January:
    case EMonth::February:
        cout << "Winter" << endl;
        break;
    case EMonth::March:
    case EMonth::April:
    case EMonth::May:
        cout << "Spring" << endl;
        break;
    case EMonth::June:
    case EMonth::July:
    case EMonth::August:
        cout << "Summer" << endl;
        break;
    case EMonth::September:
    case EMonth::October:
    case EMonth::November:
        cout << "Fall" << endl;
        break;
    default:
        break;   
    }

    cout << "" << endl;

    /**
    typedef : type definition, 타입을 정의해 줍니다. 별명 또는 별칭을 지어 줍니다. 
    typedef를 사용하여 enum 키워드를 생략할 수도 있습니다. 
    테스트를 위해서 ESeason이라는 이름의 열거형을 정의해 줍니다. 
    */

    /** 문장을 추가해 줍니다. */
    ESeason season1 = ESeason::Fall;
    ESeason season2 = Fall;

    cout << "" << endl;
    cout << "" << endl;

    /** 
    열거형을 정의하는 동시에 변수를 선언할 수도 있습니다. 
    테스트를 위해서 EWeek라는 이름의 열거형을 정의해 줍니다. 
    */

    /** 문장을 추가해 줍니다. */
    week = EWeek::Saturday;
    
    cout << "" << endl;
    cout << "" << endl;

    /**
    enum 클래스 사용법
    테스트를 위해서 ERainbowColor라는 이름의 열거형을 정의 해 줍니다. 
    */

    /**
    1. enum class는 enum과 달리 enum에[ 범위지정 연산자(::)로 이름공간을 지어줍니다. 
    코드를 작성할 때 좀더 직관적이고 정확하게 enum을 정의합니다. 
    */
    // ERainbowColor rainbowColor = Red; // 이름 공간이 없으니 에러가 생깁니다. 
    ERainbowColor rainbowColor = ERainbowColor::Red;

    /** 
    2. 타입 변환에 좀 더 까다롭게 변했습니다. 
        기본의 enum은 암시적으로 int타입으로 형변환이 되었습니다. 
        하지만 enum class를 도입함으로써 더이상 int타입으로 암시적 형변환이 되는게 불가능해졌습니다. 

        static_cast를 사용하면 int타입으로 형변환 가능합니다. 
    */

    /** string rainbowColors[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};*/
    int redColor = static_cast<int>(ERainbowColor::Red);
    int orangeColor = static_cast<int>(ERainbowColor::Orange);
    int yellowColor = static_cast<int>(ERainbowColor::Yellow);
    int greenColor = static_cast<int>(ERainbowColor::Green);
    int blueColor = static_cast<int>(ERainbowColor::Blue);
    int indigoColor = static_cast<int>(ERainbowColor::Indigo);
    int violetColor = static_cast<int>(ERainbowColor::Violet);

    cout << "redColor : " << redColor << endl;
    cout << "orangeColor : " << orangeColor << endl;
    cout << "yellowColor : " << yellowColor << endl;
    cout << "greenColor : " << greenColor << endl;
    cout << "blueColor : " << blueColor << endl;
    cout << "indigoColor : " << indigoColor << endl;
    cout << "violetColor : " << violetColor << endl;

    cout << "" << endl;

    /** 기존의 열거형을 반복문 처리합니다. */
    for (int i = 0; i < EColor::Max; i++)
    {
        EColor color = static_cast<EColor>(i);
        string name = colors[i];

        cout << "color : " << color << ", name : " << name << endl;
    }

    cout << "" << endl;
    cout << "" << endl;

    /** enum class를 반복문으로 처리합니다. */
    for (int i = 0; i < static_cast<int>(ERainbowColor::MaxRainbowColor); i++)
    {
        ERainbowColor color = static_cast<ERainbowColor>(i);
        int value = static_cast<int>(color);
        string name = rainbowColors[i];

        cout << "value : " << value << ", name : " << name << endl;
    }

    cout << "" << endl;
    cout << "" << endl;
}
