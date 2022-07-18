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

        // a�� b�� ���ٸ�
        if (a == b)
        {
            print("����");
        }
        // a�� b�� �ٸ��ٸ�
        else
        {
            print("�ٸ�");
        }

        // ���� a�� ���� ¦�����
        if (a % 2 == 0)
        {
            // a�� �� ���
            print("a�� ���� " + a);
        }

        // ���� �ð� �� '��' �κ��� 24�ð����� ������
        int hour = int.Parse(System.DateTime.Now.ToString("HH"));

        // ���� �ð��� 12�� ���̶�� = ����
        if(hour < 12)
        {
            print("����� �����Դϴ�.");
        }
        // ���� �ð��� 12�� ���Ķ�� + 12�ö�� = ����
        else
        {
            print("����� �����Դϴ�.");

            // 12�ÿ��� 16�� ���̶��
            if(hour < 16)
            {
                print("12�ÿ��� 16�� ����");
            }
            // 16�� ����
            else
            {
                print("16�� ����");
            }
        }

        // ���� �ð��� 12�� ���̶�� = ����
        if (hour < 12)
        {
            print("����� �����Դϴ�.");
        }
        // ���� �ð��� 12�� ���Ķ�� + 12�ö�� = ����
        else if (hour < 16)
        {
            print("12�ÿ��� 16�� ����");
        }
        // 16�� ����
        else
        {
            print("16�� ����");
        }

        // if �� else if ������
        // 1. else if�� �ܵ������� ���X (���� ���ǹ� �ʿ�)
        // 2. if���� ���� = �� �� �ɸ�
        //    if���� else if���̶�� = ���� ���ǿ� �ɸ��� �Ʒ��� �� �ɸ�

        int score = 48;

        if(score >= 100)
        {
            print("���ϼ̽��ϴ�");
        }
        else if(score >= 80)
        {
            print("�� �� ����ϼ���");
        }
        else if(score >= 0)
        {
            print("�ٽ� �ϼ���");
        }
        else
        {
            print("�ùٸ� ���� �ƴմϴ�");
        }

        switch (score)
        {
            case 100: 
                print("���ϼ̽��ϴ�"); 
                break;
            case 80: 
                print("�� �� ����ϼ���"); 
                break;
            case 0: 
                print("�ٽ� �ϼ���"); 
                break;
            default: 
                print("�ùٸ� ���� �ƴմϴ�"); 
                break;
        }

        // 1. ���ǹ��� ������ �� ���� �ʿ� 
        // 2. ������ �Ǵ� ���� �������� (����x)

        // ���� �� ����
        int month = int.Parse(System.DateTime.Now.ToString("MM"));

        switch (month)
        {
            case 12: 
            case 1: 
            case 2: print("�ܿ�"); break;
            case 3:
            case 4:
            case 5: print("��"); break;
            case 6: 
            case 7: 
            case 8: print("����"); break;
            case 9: 
            case 10:
            case 11: print("����"); break;
            default: print("���� ���Դϴ�."); break;
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
