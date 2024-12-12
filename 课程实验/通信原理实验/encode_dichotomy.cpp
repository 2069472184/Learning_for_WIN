#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int parCode[7] = {16, 32, 64, 128, 256, 512, 1024};
int parInsideCode[8] = {1, 1, 2, 4, 8, 16, 32, 64};
int parInsideSart[8] = {0, 16, 32, 64, 128, 256, 512, 1024};
int flag, testNum;

void parGenerate (string &result, int testNum)
{
    int low = 0, high = 7;
    for (int i = 0; i < 3; i ++)
    {
        int mid = (low + high) / 2;
        if (testNum >= parCode[mid])
        {
            result = result + '1';
            low = mid + 1;
            flag = mid;
        }
        else 
        {
            result = result + '0';
            high = mid - 1;
            flag = mid - 1;
        }
    }
}

void parInsideGenerate (string &result, int testNum, int parStart,  int parSpace)
{
    int low = 0, high = 17, mid = 8;
    for (int i = 0; i < 4; i++)
    {
        int cost = parStart + parSpace * mid;
        if (cost > testNum) 
        {
            result = result + '0';
            high = mid;
            mid = (low + high) / 2;
        }
        else 
        {
            result = result + '1';
            low = mid;
            mid = (low + high) / 2;
        }
    }
}

int main () 
{
    while (1)
    {
        cout << "����������ֵ��";
        cin >> testNum;
        
        string result; //�ֽ������洢���������pcm��

        //�жϼ�����
        if (testNum < 0) result = result + '0';
        else result = result + '1';
        
        //ȥ����
        testNum = fabs(testNum);    

        //ȷ��������
        parGenerate(result, testNum);               

        //�����������
        int parSeq = flag + 1;                   

        int parStart = parInsideSart[parSeq];    //������ʼ��ƽ
        int parSpace = parInsideCode[parSeq];    //�������

        // ȷ��������
        parInsideGenerate(result, testNum, parStart, parSpace);

        cout << "���������pcm����: " << result << endl;
    }

    return 0;
}