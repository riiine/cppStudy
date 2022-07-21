#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/**
로또는 50개의 공 중에서 7개의 공을 랜덤으로 선택합니다.
랜덤 관련 라이브러리
*/
#include <time.h>
/** 로또 번호 7개를 저장할 컨테이너가 필요합니다. */
#include <vector>
/**
선택된 로또 번호 7개는 오름차순으로 정렬이 되어야 합니다.
정렬을 위한 라이브러리
*/
#include <algorithm>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;


int main()
{
    /**
    50개의 공 중에서 7개의 공을 랜덤으로 선택합니다.
    난수테이블을 생성해 줍니다.
    */
    srand((unsigned int)time(0));

    /** int타입을 여러개 저장할 수 있는 벡터 컨테이너 타입의 resultNumbers라는 이름의 변수를 선언합니다. */
    vector<int> resultNumbers;

    /** 행운 번호를 저장할 변수를 선언합니다. */
    int luckyNumber;

    /**  로또는 총 50개의 볼을 사용합니다. 요 50개의 수치를 저장할 변수를 선언합니다. */
    int totalBalls = 50;

    /**
    로또는 총 50개의 볼 중에서 7개의 볼을 랜덤으로 선택합니다.
    요 7이라는 수치를 저장해 둘 변수를 선언합니다.
    */
    int resultBalls = 7;

    /**
    1에서 50이라는 숫자를 저장할 벡터 컨테이너를 선언해 주고, 반복문 이용해서
    1에서 50까지 숫자를 넣어줍니다.
    프로그래밍 언어의 숫자는 0부터 시작합니다.
    */
    vector<int> totalNumbers;

    //for (int i = 1; i <= totalBalls; i++)
    //{
    //    totalNumbers.push_back(i);
    //}

    for (int i = 0; i < totalBalls; i++)
    {
        /** 1에서 50까지 숫자를 저장해야 하니, 최초 i + 1 로 해 줍니다. */
        totalNumbers.push_back(i + 1);
    }

    cout << "" << endl;

    /**
    totolNumbers 컨테이너에서 7개의 숫자를 랜덤으로 골라서
    resultNumbers 벡터 컨테이너에 추가해 줍니다.
    */

    /**
    resultBalls 변수의 값은 7입니다. 반복문으로 7번 반복합니다.
    for문을 이용해서 50개의 숫자중에서 랜덤으로 7개의 숫자를 골라서
    resultNumbers 벡터 컨테이너에 저장해 줍니다.
    */

    for (int i = 0; i < resultBalls; i++)
    {
        /**
        (int)rand() % totalBalls 0에서 49의 숫자중에서 랜덤으로 하나를 골라줍니다.
        totalBalls의 값은 50입니다.
        */
        /** 0에서 49사이에서 값을 가져오니 , 값을 오버할 수 있어서 에러가 나게 됩니다. */
        totalBalls--;

        int randomIndex = (int)rand() % totalBalls;
        cout << "randomIndex : " << randomIndex << endl;
        /** resultNumbers 벡터 컨테이너에 랜덤으로 고른 숫자를 저장해 줍니다. */
        resultNumbers.push_back(totalNumbers.at(randomIndex));
        /** 같은 번호가 나오면 안되니 선택한 번호를 totalNumbers 벡터 컨테이너에서 지워줍니다. */

        /**
        totalNumbers 사이즈는 50인데, 계속 1씩 감소합니다. 그런데 randomIndex가 0에서 49 사이에서
        값을 가져오니, 값을 오버할 수 있어서 에러가 납니다.
        */
        totalNumbers.erase(totalNumbers.begin() + randomIndex);
    }

    cout << "" << endl;

    cout << "resultNumbers : " << endl;

    /** 7개의 랜덤으로 고른 숫자를 오름차순으로 정렬해 줍니다. */

    /**
    로또 번호는 정렬이 되어 있어야 합니다.
    정렬은 하기 위해서는 라이브러리를 추가해 줍니다.
    #include <algorithm>
    */
    sort(resultNumbers.begin(), resultNumbers.end());

    for (int i = 0; i < resultNumbers.size(); i++)
    {
        cout << resultNumbers[i] << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 7개의 번호 중에서 행운 번호를 랜덤으로 골라서 luckyNumber 변수에 넣어줍니다. */
    /**
    로또 번호는 6개의 번호와 1개의 행운번호로 구성되므로, 7개의 숫자중에서
    행운번호를 고르기 위해서 번호 하나를 랜덤으로 골라줍니다.
    resultNumbers.size()는 7입니다.
    rand() % resultNumbers.size()는 0에서 6사이의 값을 랜덤으로 반환합니다.
    */
    int luckyNumberIndex = rand() % resultNumbers.size();
    /** 선택한 번호를 luckyNumber변수에 저장합니다. */
    luckyNumber = resultNumbers.at(luckyNumberIndex);
    /** resultNumbers 벡터 컨테이너에서 이제 행운 번호는 필요가 없으므로 행운 번호를 지워줍니다. */
    resultNumbers.erase(resultNumbers.begin() + luckyNumberIndex);

    cout << "lotto number : ";

    for (int i = 0; i < resultNumbers.size(); i++)
    {
        cout << resultNumbers[i] << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    cout << "luckyNumber : " << luckyNumber << endl;

}