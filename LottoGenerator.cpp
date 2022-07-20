#include <iostream>

/** 문자열 관련 라이브러리 */
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
    난수테이블을 생성해줍니다.
    */
    srand((unsigned int)time(0));

    /** int타입을 여러개 저장할 수 있는 벡터 컨테이너 타입의 resultNumbers라는 이름의 변수를 선언합니다. */
    vector<int> resultNumbers;

    /** 행운 번호를 저장할 변수를 선언합니다. */
    int luckyNumber;

    /** 로또는 총 50개의 볼을 사용합니다. 요 50개의 수치를 저장할 변수를 선언합니다. */
    int totalBalls = 50;

    /**
    로또는 총 50개의 볼 중에서 7개의 볼을 랜덤으로 선택합니다.
    요 7이라는 수치를 저장해둘 변수를 선언합니다. 
    */
    int resultBalls = 7;

    /**
    1에서 50이라는 숫자를 저장할 벡터 컨테이너를 선언해주고, 반복문 이용해서
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
        /** 1에서 50까지 숫자를 저장해야하니, 최초 1+1로 해줍니다. */
        totalNumbers.push_back(i + 1);
    }

    cout << "" << endl;

    /**
    totalNumbers 컨테이너에서 7개의 숫자를 랜덤으로 골라서 
    resultNumbers 벡터 컨테이너에 추가해줍니다.
    */

    for (int i = 0; i < resultBalls; i++)
    {
        int randomIndex = rand() % totalBalls;
        cout << "randomIndex : " << randomIndex << endl;

        resultNumbers.push_back(totalNumbers.at(randomIndex));

        totalNumbers.erase(totalNumbers.begin() + randomIndex);
    }
}


