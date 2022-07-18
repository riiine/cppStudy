using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Conditional : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        int a= 3;
        int b= 2;

        // a와 b가 같다면
        if (a == b)
        {
            print("같음");
        }
        // a와 b가 다르다면
        else
        {
            print("다름");
        }

        // 만약 a의 값이 짝수라면
        if (a % 2 == 0)
        {
            // a의 값 출력
            print("a의 값은 " + a);
        }

        // 현재 시간 중 '시' 부분을 24시간제로 가져옴
        int hour = int.Parse(System.DateTime.Now.ToString("HH"));

        // 현재 시간이 12시 전이라면 = 오전
        if(hour < 12)
        {
            print("현재는 오전입니다.");
        }
        // 현재 시간이 12시 이후라면 + 12시라면 = 오후
        else
        {
            print("현재는 오후입니다.");

            // 12시에서 16시 사이라면
            if(hour < 16)
            {
                print("12시에서 16시 사이");
            }
            // 16시 이후
            else
            {
                print("16시 이후");
            }
        }

        // 현재 시간이 12시 전이라면 = 오전
        if (hour < 12)
        {
            print("현재는 오전입니다.");
        }
        // 현재 시간이 12시 이후라면 + 12시라면 = 오후
        else if (hour < 16)
        {
            print("12시에서 16시 사이");
        }
        // 16시 이후
        else
        {
            print("16시 이후");
        }

        // if 와 else if 차이점
        // 1. else if는 단독적으로 사용X (위에 조건문 필요)
        // 2. if문이 각각 = 둘 다 걸림
        //    if문과 else if문이라면 = 위에 조건에 걸리면 아래에 안 걸림

        int score = 48;

        if(score >= 100)
        {
            print("잘하셨습니다");
        }
        else if(score >= 80)
        {
            print("좀 더 노력하세요");
        }
        else if(score >= 0)
        {
            print("다시 하세요");
        }
        else
        {
            print("올바른 값이 아닙니다");
        }

        switch (score)
        {
            case 100: 
                print("잘하셨습니다"); 
                break;
            case 80: 
                print("좀 더 노력하세요"); 
                break;
            case 0: 
                print("다시 하세요"); 
                break;
            default: 
                print("올바른 값이 아닙니다"); 
                break;
        }

        // 1. 조건문에 기준이 될 변수 필요 
        // 2. 기준이 되는 값과 동등조건 (범위x)

        // 현재 월 저장
        int month = int.Parse(System.DateTime.Now.ToString("MM"));

        switch (month)
        {
            case 12: 
            case 1: 
            case 2: print("겨울"); break;
            case 3:
            case 4:
            case 5: print("봄"); break;
            case 6: 
            case 7: 
            case 8: print("여름"); break;
            case 9: 
            case 10:
            case 11: print("가을"); break;
            default: print("없는 달입니다."); break;
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
