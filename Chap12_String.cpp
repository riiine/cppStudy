#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>
/** 문자열의 대, 소문자 변환 라이브러리*/
#include <algorithm>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 정적 할당을 테스트해보기 위해서 Animal이라는 이름의 클래스를 정의해 주도록 합니다. */
class Animal
{
public:
    Animal()
    {
        cout << "정적 할당 생성자" << endl;
    }

    ~Animal()
    {
        cout << "정적 할당 소멸자" << endl;
    }
};
/** new 연산자를 이용한 동적 할당을 테스트 해 보기 위해서 Lion이라는 이름의 클래스를 정의해 줍니다. */
class Lion
{
public:
    Lion()
    {
        cout << "new 연산자를 이용한 동적 할당 생성자" << endl;
    }

    ~Lion()
    {
        cout << "new 연산자를 이용한 동적 할당 소멸자" << endl;
    }
};


/**
스마트 포인터로 동적으로 객체 생성을 해 봅니다.
테스트를 위해서 Tiger라는 이름의 클래스를 정의해 주도록 합니다.
*/
class Tiger
{
public:
    Tiger()
    {
        cout << "스마트 포인터로 동적으로 객체 생성한 생성자" << endl;
    }

    ~Tiger()
    {
        cout << "스마트 포인터로 동적으로 객체 생성한 소멸자" << endl;
    }
};

int main()
{
    /**
    완성도 있는 게임의 조건은 유저에게 정확안 정보를 알려야 합니다. 
    문자열로 알려야 합니다. 

    게임 엔진 내부는 수학과 물리덩어리입니다. 문자열이 아닙니다. 

    올바른 정보를 효율적으로 유저에게 전달하려면 문자열 클래스에서 제공하는
    멤버 함수들을 자유롭게 쓸 수 있어야 합니다. 
    */

    /** 문자열을 3가지 방법으로 선언할 수 있습니다. */

    cout << "1. 생성과 동시에 초기화 할 수 있습니다. " << endl;
    string stringValue1("C 공부하고 있어요. !!");
    cout << "stringValue1 : " << stringValue1 << endl;
    cout << "" << endl;

    cout << "2. 생성한 후에 초기화 할 수 있습니다. " << endl;
    string stringValue2;
    stringValue2 = "C++ 공부하고 있어요. !!";
    cout << "stringValue2 : " << stringValue2 << endl;
    cout << "" << endl;

    cout << "3. 문자열을 복사해서 선언할 수 있습니다. " << endl;
    cout << "문자열 stringValue3를 선언과 동시에 stringValue2의 값을 복사해서 대입합니다. " << endl;
    string stringValue3(stringValue2);
    cout << "stringValue3 : " << stringValue3 << endl;
    cout << "" << endl;

    /** 문자열 값 반환에 대해서 알아봅니다. */
    string stringValue4 = "Hello World";

    cout << "at(index) : 문자열 index위치의 문자를 반환합니다. " << endl;
    cout << "stringValue4.at(4) : " << stringValue4.at(4) << endl;
    cout << "" << endl;

    cout << "문자열[index] : 배열처럼 index의 위치의 문자를 반환합니다. " << endl;
    cout << "stringValue4[4] : " << stringValue4[4] << endl;
    cout << "" << endl;

    cout << "front() : 문자열 맨 앞에 문자를 반환합니다. " << endl;
    cout << "stringValue4.front() : " << stringValue4.front() << endl;
    cout << "" << endl;

    cout << "back() : 문자열의 맨 끝의 문자를 반환합니다. " << endl;
    cout << "stringValue4.back() : " << stringValue4.back() << endl;
    cout << "" << endl;

    /** 
    문자열 크기 반환에 대해서 알아 봅니다. 
    최적화 이슈입니다. 문자열은 크기가 증가할 가능성이 있기 때문에 실제로 가지고 있는
    문자열의 길이보다 더 큰 크기를 메모리에 할당하는데, 이 크기를 Capacity(용량)라고 하며
    capacity() 함수로 이 크기를 반환할 수 있습니다. 
    */

    string stringValue5 = "C와 C++ 공부합니다. !!";
    cout << "length() : 문자열의 길이를 반환합니다. " << endl;
    cout << "stringValue5.length() : " << stringValue5.length() << endl;
    cout << "" << endl;

    cout << "size() : 문자열이 사용하고 있는 사이즈를 반환합니다. " << endl;
    cout << "stringValue5.size() : " << stringValue5.size() << endl;
    cout << "" << endl;

    cout << "capacity() : 문자열에 할당된 메모리 크기를 반환합니다. " << endl;
    cout << "stringValue5.capacity() : " << stringValue5.capacity() << endl;
    cout << "" << endl;

    /**
    C++ 에서 객체 생성 방법
    A. 정적 할당 : 미리 할당해 놓습니다. 비효율적인 부분이 발생할 수 있습니다. 
            내가 메모리 할당을 할 필요가 없습니다.
    B. 동적 할당 : 런타임에서 메모리 할당을 합니다. 효율적으로 필요한 부분에서 메모리 할당을 합니다. 
            까다로운 부분이 있습니다. 하지만 동적으로 객체 생성을 해야만 합니다. 
        1. new 연산자로 객체 생성을 합니다. delete 연산자로 객체 해제를 해야 합니다. 
            만일 delete 연산자로 객체 해제를 해 주지 않으면 메모리 누수가 발생합니다. 
            메모리 누수 : 내가 접근할 수 없는, 지울 수 없는 찌꺼기들이 메모리에 계속 쌓입니다. 
            나중에는 앱이나 게임이 강제로 종료될 수가 있습니다. 
        2. 현재는 스마트 포인터로 메모리 관리를 할 수도 있습니다. 내가 객체 해제를 해줄 필요가 없습니다. 
            메모리 누수 발생을 예방할 수 있습니다. 
    */

    /** 정적 할당을 테스트해보기 위해서 Animal이라는 이름의 클래스를 정의해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    Animal animal1;
    cout << "" << endl;

    /** new 연산자를 이용한 동적 할당을 테스트 해 보기 위해서 Lion이라는 이름의 클래스를 정의해 줍니다. */

    /** 문장을 추가해 줍니다. */
    Lion* lion1 = new Lion();
    cout << "" << endl;

    /**
    new 연산자로 객체 생성을 하면 delete 연산자로 객체 해제를 해 주어야만 합니다. 해 주지 않으면
    메모리 누수가 발생합니다. 복잡한 코드에서는 어느 위치에서 delete 연산자로 메모리 해제를 해 주어야 하는지
    상당히 복잡합니다. 
    */
    delete lion1;
    cout << "" << endl;

    /** 
    delete 연산자 사용의 복잡성과 메모리 누수 예방을 위해서 스마트 포인터가 생겼습니다. 
    1. unique_ptr   : C++11(2011년)에서 생성되었습니다. 
    2. shared_ptr   : C++11(2011년)에서 생성되었습니다. 
    3. weak_ptr     : C++11(2011년)에서 생성되었습니다. 
    4. auto_ptr     : C++17(2017년)에서 없어졌습니다. 

    C언어 때는 malloc(말록, Memory Allocation), free() 함수로 메모리 관리를 했습니다. 
    C++ 에서 new연산자, delete 연산자로 메모리 관리를 하면 어렵습니다. 테스트를 많이 해야만 합니다. 

    2011년에 스마트 포인터를 지원하면서 메모리 관리가 쉬워졌습니다. 
    */

    /**
    스마트 포인터로 동적으로 객체 생성을 해 봅니다. 
    테스트를 위해서 Tiger라는 이름의 클래스를 정의해 주도록 합니다. 
    */

    /** 문장을 추가해 줍니다. */
    unique_ptr<Tiger> uniquePtr0 = make_unique<Tiger>();
    cout << "" << endl;

    /** 문자열 클래스에서 제공하는 다양한 문자열 함수들로 문자열을 쉽게 가공할 수 있는 함수들을 제공합니다. */
    string stringValue6 = "Red";
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "append() : 문자열 뒤에 문자열을 추가합니다. " << endl;
    stringValue6.append("Orange"); // Orange
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "append(\"문자열\"), n, m : 문자열 뒤에 문자열을 인덱스 n부터 m까지 문자를 추가합니다. " << endl;
    stringValue6.append("Yellow", 2, 3); // llo
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "append(n, '문자') : 문자열 뒤에 문자를 n개 만큼 추가합니다. " << endl;
    stringValue6.append(2, 'A'); // 'A' 문자를 끝에 2개 추가
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    /** 원활한 테스트를 위해서 초기화 해 줍니다. */
    stringValue6 = "Red";
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "intert(n, \"문자열\") : 문자열 index n 뒤에 문자열을 삽입합니다. " << endl;
    stringValue6.insert(2, "Green"); // ReGreend
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "replace(n, m, \"문자열\") : 문자열 index n부터 m 까지 문자를 대체 합니다. " << endl;
    stringValue6.replace(2, 3, "Blue"); // ReBlueend
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    /** 원활한 테스트를 위해서 초기화를 해 줍니다. */
    stringValue6 = "Red";
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "push_back() : 문자열 뒤에 '문자'를 추가 합니다. " << endl;
    stringValue6.push_back('B'); // RedB
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "pop_back() : 문자열 맨 끝의 문자를 제거합니다. " << endl;
    stringValue6.pop_back();  //Red
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "assign(\"문자을\") 문자열 전체를 재할당 합니다. " << endl;
    stringValue6.assign("Blue"); // Blue
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "erase(n) : 문자열 n부터 지워줍니다. " << endl;
    stringValue6.erase(3); // Blu
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "clear() : 문자열을 초기화 해 줍니다. " << endl;
    stringValue6.clear(); // 
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;


    /** 원할한 테스트를 위해서 초기화 해 줍니다. */
    stringValue6 = "Red";
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "erase() : erase() 함수를 매개변수 없이 사용하면 문자열 전체를 지웁니다. " << endl;
    stringValue6.erase();
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    /** 원할한 테스트를 위해서 초기화 해 줍니다. */
    stringValue6 = "Red";
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "empty() : 문자열이 비어 있는지 확인합니다. 비어 있으면 true, 아니면 false값을 반환합니다. " << endl;
    bool isEmpty = stringValue6.empty() ? true : false;
    cout << "isEmpty : " << isEmpty << endl;

    string strEmpty = stringValue6.empty() ? "true" : "false";
    cout << "strEmpty : " << strEmpty << endl;
    cout << "" << endl;

    cout << "erase() : 문자열 전체를 지워줍니다. " << endl;
    stringValue6.erase();

    cout << "empty() : 문자열이 비어 있는지 확인합니다. 비어 있으면 true, 아니면 false값을 반환합니다. " << endl;
    isEmpty = stringValue6.empty() ? true : false;
    cout << "isEmpty : " << isEmpty << endl;

    strEmpty = stringValue6.empty() ? "true" : "false";
    cout << "strEmpty : " << strEmpty << endl;
    cout << "" << endl;

    /** 원할한 테스트를 위해서 초기화 해 줍니다. */
    stringValue6 = "We learn C++";
    cout << "stringValue6 : " << stringValue6 << endl;
    cout << "" << endl;

    cout << "find() : 문자열에서 찾을 문자열을 찾은 뒤에 인덱스를 반환합니다. 찾지 못하면 -1을 반환합니다. " << endl;
    /** 현재는 가독성을 위해서 변수에 담아서 매개 변수에 전달합니다. */
    string stringForFind = "learn";
    int index1 = stringValue6.find(stringForFind);
    /** 예전에는 코드를 한줄이라도 줄이려고 했습니다. 가독성이 떨어집니다. */
    /**
    "learn"이라는 문자열을 왜 쓰는지 헷갈립니다. 변수에 담아서 넣어주면 "아 찾을 문자열이구나. " 알 수가 있습니다. 
    지금은 시스템이 좋아져서 굳이 한 줄 없애지 말고, 의미 있는 변수에 담아서 하는 것이 좋습니다. 
    */
    // int index1 = stringValue6.find("learn"); // 안좋은 습관
    if (index1 > 0)
    {
        cout << stringForFind << "를 찾았습니다. " << index1 << " index입니다. " << endl;
    }
    else
    {
        cout << stringForFind << "이 없습니다. " << endl;
    }
    cout << "" << endl;

    /** if else문은 삼항 연산자로 변경해 줄 수 있습니다. */
    string strResult = (index1 > 0) ? stringForFind + " 찾았습니다. " : stringForFind + " 찾지 못했습니다. ";
    cout << "strResult : " << strResult << endl;
    cout << "" << endl;


    cout << "substr() : 문자열 전체를 반환합니다. " << endl;
    string stringValue7 = stringValue6.substr();
    cout << "stringValue7 : " << stringValue7 << endl;
    cout << "" << endl;

    cout << "substr(n) : n번째 index부터 문자열 끝까지 반환합니다. " << endl;
    stringValue7 = stringValue6.substr(3);
    cout << "stringValue7 : " << stringValue7 << endl;
    cout << "" << endl;

    cout << "substr(n, k) : n번째 index부터 k까지 문자열을 반환합니다. " << endl;
    stringValue7 = stringValue6.substr(3, 7);
    cout << "stringValue7 : " << stringValue7 << endl;
    cout << "" << endl;

    cout << "resize(n) : 문자열을 n의 크기로 만들어 줍니다. " << endl;
    stringValue7.resize(15);
    cout << "stringValue7 : " << stringValue7 << endl;
    cout << "" << endl;

    cout << "resize(n, '문자') : 문자열을 n의 크기로 만들고, 넘치면 '문자'로 채웁니다. " << endl;
    stringValue7.resize(20, 'a');
    cout << "stringValue7 : " << stringValue7 << endl;
    cout << "" << endl;

    cout << "reserve(n) : n만큼 메모리를 미리 할당합니다. " << endl;
    stringValue7.reserve(30);
    cout << "stringValue7 : " << stringValue7 << endl;
    cout << "" << endl;

    cout << "compare() : 문자열을 비교합니다. 문자열이 서로 같으면 0을 반환하고, 다르면 -1을 반환합니다. " << endl;
    string stringValue8 = "korean";
    string stringValue9 = "koreaN"; // 문자열은 오타가 날 수 있습니다. 

    if (stringValue8.compare(stringValue9) == 0)
    {
        cout << stringValue8 + "과 " << stringValue9 << "는 같은 문자열입니다. " << endl;
    }
    else
    {
        cout << stringValue8 + "과 " << stringValue9 << "는 다른 문자열입니다. " << endl;
    }
    cout << "" << endl;

    /** 문자열은 오타가 날 수 있기 때문에 korean과 koreaN은 같은 문자열로 해 주어야 합니다. */

    cout << "toupper(), tolower() : 문자열을 대문자 또는 소문자로 바꿉니다. " << endl;
    string stringValue10 = "we study cpp language. !!";
    string stringValue11 = "THAT'S REALLY AMAZING. !!";

    /** 대문자는 소문자로, 소문자는 대문자로 변경해 줍니다. */
    transform(stringValue10.begin(), stringValue10.end(), stringValue10.begin(), toupper);
    cout << "stringValue10 : " << stringValue10 << endl;

    transform(stringValue11.begin(), stringValue11.end(), stringValue11.begin(), tolower);
    cout << "stringValue11 : " << stringValue11 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 개발중에 오타가 날 수 있습니다. 이후에 오타는 수정해 줍니다. */
    string stringValue12 = "woRld";
    string stringValue13 = "WoRlD";

    transform(stringValue12.begin(), stringValue12.end(), stringValue12.begin(), toupper);
    cout << "stringValue12 : " << stringValue12 << endl;

    transform(stringValue13.begin(), stringValue13.end(), stringValue13.begin(), toupper);
    cout << "stringValue13 : " << stringValue13 << endl;

    if (stringValue12.compare(stringValue13) == 0)
    {
        cout << stringValue12 + "과 " << stringValue13 << "는 같은 문자열입니다. " << endl;
    }
    else
    {
        cout << stringValue12 + "과 " << stringValue13 << "는 다른 문자열입니다. " << endl;
    }

    cout << "" << endl;
    
    cout << "+=, append() : 문자열을 합쳐 봅니다. " << endl;
    string stringValue14 = "";
    stringValue14 += "We ";
    stringValue14 += "study ";
    stringValue14.append("C++ ");
    stringValue14.append("programming language. !!");

    cout << "stringValue14 : " << stringValue14 << endl;
    cout << "" << endl;

    cout << "move() : 문자열을 이동할 수 있습니다. " << endl;
    string stringValue15 = "We study C++ programming language. !!";
    cout << "" << endl;
    string stringValue16 = move(stringValue15);
    cout << "" << endl;

    cout << "stringValue15 : " << stringValue15 << endl;
    cout << "stringValue16 : " << stringValue16 << endl;
    cout << "" << endl;


    cout << "erase(), remove() : 문자열에서 특정 문자만 제거할 수가 있습니다. " << endl;
    string stringValue17 = "We study C++ programming language. !!";
    cout << "문자열에서 공배과 m을 없애 봅니다. " << endl;

    stringValue17.erase(remove(stringValue17.begin(), stringValue17.end(), ' '), stringValue17.end());
    stringValue17.erase(remove(stringValue17.begin(), stringValue17.end(), 'm'), stringValue17.end());

    cout << "stringValue17 : " << stringValue17 << endl;
    cout << "" << endl;

    cout << "replace() : 문자열을 일부 교체할 수 있습니다. " << endl;
    string stringValue18 = "We study C++ programming language. !!";
    string findString("study");
    string replaceString("learn");

    stringValue18.replace(stringValue18.find(findString), findString.length(), replaceString);

    cout << "stringValue18 : " << stringValue18 << endl;
    cout << "" << endl;

    cout << "stoi() : string to integer 문자열을 정수로 변경해 봅니다. " << endl;
    string stringValue19 = "1024";
    string stringValue20 = "3.14159265";
    string stringValue21 = "123 korea";
    /** 문자열 "1024"를 stoi() 함수로 정수값 1024로 변환합니다. */
    int intValue1 = stoi(stringValue19);
    /** 문자열 "3.14159265"를 stoi() 함수로 소수점 이하는 버려진채로 정수값 3으로 변환합니다. */
    int intValue2 = stoi(stringValue20);
    /** 문자열 "123 korea"를 stoi() 함수로 문자열이 제거된 채 정수값 123만을 변환합니다. */
    int intValue3 = stoi(stringValue21);

    cout << "intValue1 : " << intValue1 << ", intValue2 : " << intValue2 << ", intValue3 : " << intValue3 << endl;
    cout << "" << endl;

    cout << "to_string() : 숫자를 문자열로 변경할 수 있습니다. " << endl;
    int intValue4 = 10;
    string stringValue22 = 10 + "번 반복이 필요합니다. "; // (X)
    cout << "stringValue22 : " << stringValue22 << endl;
    cout << "" << endl;

    string stringValue23 = to_string(intValue4) + "번 반복이 필요합니다. ";
    cout << "stringValue23 : " << stringValue23 << endl;
    cout << "" << endl;


     
}
