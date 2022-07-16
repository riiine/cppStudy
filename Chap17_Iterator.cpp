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
/** 랜덤 라이브러리*/
#include <time.h>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

int main()
{
    /**
    반복자(Iterator)

    C++에서는 반복자를 제공하는데, 이를 사용하면 컨테이너에 저장된 요소를 순회하고
    접근하여 효율적으로 컨테이너에 접근할 수 있습니다. 
    반복자는 포인터는 아니지만 비숫한 개념닙니다. 
    반복자를 이용하면 특정 컨테이너에 종속적이지 않게 컨테이너에 접근할 수 있습니다. 
    */

    /** int타입을 여러개 저장할 수 있는 vector타입의 intValue1이라는 이름의 vector컨테이너 변수를 선언했습니다. */
    vector<int> intVector1;

    for (int i = 0; i < 6; i++)
    {
        // 0, 10, 20, 30, 40, 50
        intVector1.push_back(i * 10);
    }

    for (int i : intVector1)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 
    1. 반복자 선언

    vector 컨테이너의 반복자인 iter 반복자를 선언합니다. 
    */
    vector<int>::iterator iter;

    /**
    2. 반복자 초기화

    반복자의 초기화는 무척 중요합니다. 
    반복자를 초기화하지 않으면 계속 반복자가 증가해서 에러가 날 수 있습니다. 
    */
    /** iter반복자는 intVector1의 시작점을 가리킵니다. */
    iter = intVector1.begin();


    /**
    반복자는 포인터와 유사하지만 포인터는 아닙니다. 
    반복자가 가리키는 값을 가져오기 위해서는 *(역참조 연산자)를 사용합니다. 
    반복자가 가리키는 주소값을 가져오기 위해서는 &(주소 연산자)를 사용합니다. 
    */
    // cout << "iter value : " << *iter << ", iter address : " << iter << endl; // (X)
    cout << "iter value : " << *iter << ", iter address : " << &iter << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    프로그래밍의 언어의 숫자는 0부터 시작합니다. 
                 0번째 인덱스   1번째 인덱스    2번째 인덱스    3번째 인덱스    4번째 인덱스
    반복자는 인덱스가 아닙니다. 
                 1번째 반복자   2번째 반복자    3번째 반복자    4번째 반복자    5번째 반복자
    */
    int intArr1[] = {0,            1,             2,           3,            4};

    /**
    3. 반복자는 임의 접근이 가능합니다. 
    하지만 주의할 점은, 임의 접근은 인덱스를 통해 접근해서 해당 값을 반환합니다. 
    하지만 iter반복자가 가리키는 값을 변경하는 것은 아닙니다. 
    */
    cout << "iter[1] : " << iter[1] << endl;
    cout << "iter[3] : " << iter[3] << endl;

    /**
    iter반복자의 *(역참조 연산자)를 사용하면 2번째 인덱스, 3번째 반복자의 요소값이 반환됩니다. 
    intVector1.begin() : intVector1의 0번째 인덱스, 1번째 반복자를 의미합니다. 
    intVector1.begin() + 2 : intVector1의 2번째 인덱스, 3번째 반복자를 의미합니다. 
    */
    iter = intVector1.begin() + 2;
    cout << "intVector1.begin() + 2 : " << *iter << endl;

    /**
    intVector1.begin() + 4 : intVector1의 4번째 인덱스, 5번째 반복자를 의미합니다. 
    */
    iter = intVector1.begin() + 4;
    cout << "intVector1.begin() + 4 : " << *iter << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 4. += 연산자 사용이 가능합니다. */
    /** 반복자를 초기화 하지 않으면 에러가 날 수 있습니다. */
    iter = intVector1.begin(); // 초기화를 하지 않으면 7번째 인덱스, 8번째 반복자를 의미하게 됩니다. 
    iter += 3; // 3번째 인덱스, 4번째 반복자를 반환합니다. 
    cout << "iter : " << *iter << ", iter address : " << &iter << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 5. for문으로 컨테이너의 요소들을 출력해 봅니다. */
    cout << "for문 : " << endl;
    /** 1번째 반복자의 요소 위치*/
    vector<int>::iterator iter_begin = intVector1.begin();
    /** 마지막 반복자의 요소의 다음 위치*/
    vector<int>::iterator iter_end = intVector1.end();
    /**
    iter = iter_begin : 초기값입니다. 첫번째 반복자의 요소 위치
    iter != iter_end : 조건문입니다. 만일 반복자가 마지막 반복자의 요소의 다음 위치가 아닐때까지
    */
    for (iter = iter_begin; iter != iter_end; iter++)
    {
        cout << "iter : " << *iter << ", iter address : " << &*iter << endl;
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 6. while문*/
    cout << "while문 : " << endl;
    /** 반복자를 초기화 해 주지 않으면 에러가 날 수 있습니다. */
    iter = intVector1.begin(); // 초기화를 해 주지 않으면 값에 오류가 발생할 수 있습니다. 
    /** 반복자가 마지막 반복자의 다음 위치가 아닐때까지 반복합니다. */
    while (iter != intVector1.end())
    {
        cout << *iter << " ";

        /** 
        while반복문을 조건을 빠져나갈 수 있도록 해 주어야 합니다. 
        그렇지 않으면 무한 반복이 됩니다. 
        */
        /**
        ++ : 후치 증가 연산자가 아닙니다. 
        ++ : 연산자 오버로딩으로 반복자를 증가시켜 줍니다. 
        */
        iter++;
    }

    cout << "" << endl;
    cout << "" << endl;

    /** 7. foreach문 */
    cout << "foreach 문 " << endl;
    /** foreach문은 반복자 없이도 컨테이너의 값을 출력할 수 있습니다. */
    for (auto itr : intVector1)
    {
        cout << itr << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 8. foreach문의 다른 형태*/
    cout << "foreach문의 다른 형태 : " << endl;
    /** & : 주소 연산자(Address Operator)가 아니고 참조 연산자(Reference Operator)입니다. */
    for (auto& itr : intVector1)
    {
        cout << itr << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 9. 반복자를 통한 요소 값 변경*/
    cout << "반복자를 통한 요소 값 변경" << endl;
    /** 반복자를 사용할 때는 꼭 초기화를 해 주어야 합니다. */
    iter = intVector1.begin();
    /** 포인터 연산자와 거의 유사합니다. */
    *iter = 100; // 첫번째 반복자에 100의 리터럴 값을 대입합니다. 
    *(iter + 1) = 200; // 두번째 반복자에 200의 리터럴 값을 대입합니다. 
    iter[2] = 300; // 세번째 반복자에 300의 리터럴 값을 대입합니다. 

    for (iter = intVector1.begin(); iter != intVector1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 9. intVector1[2] 앞에 15의 값을 추가*/
    cout << "intVector1[2] 앞에 15의 값을 추가 : " << endl;
    intVector1.insert(intVector1.begin() + 2, 15);

    for (iter = intVector1.begin(); iter != intVector1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 10. intVector1[3] 제거*/
    cout << "intVector1[3] 제거 : " << endl;
    intVector1.erase(intVector1.begin() + 3);

    for (iter = intVector1.begin(); iter != intVector1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    ///** 11. 반복문 안에서 erase() 함수를 쓸 때는 주의해야 합니다. */
    //cout << "반복문 안에서 erase() 함수를 쓸 때는 주의해야 합니다. " << endl;
    //vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    //{
    //    /**
    //    vector컨테이너의 요소를 2로 나눈 나머지가 0이면 제거해 줍니다. 
    //    짝수 값을 제거해 줍니다. 
    //    */
    //    if (*it % 2 == 0)
    //    {
    //        it = numbers.erase(it);
    //    }
    //}

    //for (auto i : numbers)
    //{
    //    cout << i << " ";
    //}
    //cout << "" << endl;
    //cout << "" << endl;

    /** 12. 반복문 안에서 erase() 함수를 쓸 때는 조심해야 합니다. */
    cout << "반복문 안에서 erase() 함수를 쓸 때는 조심해야 합니다." << endl;
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /** 반복문안에서 erase() 함수가 호출되지 않았을 때만 it++를 해 줍니다. */
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end();)
    {
        /**
        vector컨테이너의 요소를 2로 나눈 나머지가 0이면 제거해 줍니다. 
        짝수 값을 제거해 줍니다.
        */
        if (*it % 2 == 0)
        {
            it = numbers.erase(it);
        }
        else  /** 반복문안에서 erase() 함수가 호출되지 않았을 때만 it++를 해 줍니다. */
        {
            it++;
        }
    }

    for (auto i : numbers)
    {
        cout << i << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

    /** 13. 문자열을 여러개 저장할 수 있는 벡터 컨테이너에서 특정 문자열을 제거합니다. */
    cout << "문자열을 여러개 저장할 수 있는 벡터 컨테이너에서 특정 문자열을 제거합니다. " << endl;
    vector<string> names{"John", "James", "Tom", "Smith", "Jane"};

    /** 반복문으로 이름에 "J" 문자열이 들어간 이름들을 지워 봅니다. */
    for (vector<string>::iterator name = names.begin(); name != names.end();)
    {
        /** string::find() 함수는 찾는 단어나 문자열이 없으면 string::npos를 반환합니다. */
        if ((*name).find("J") != string::npos)
        {
            name = names.erase(name);
        }
        else /** 반복문안에서 erase() 함수가 호출되지 않았을 때만 name++를 해 줍니다. */
        {
            name++;
        }
    }

    for (auto name : names)
    {
        cout << name << " ";
    }
    cout << "" << endl;
    cout << "" << endl;

}

