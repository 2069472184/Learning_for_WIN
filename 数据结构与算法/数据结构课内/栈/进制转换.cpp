#include <iostream>
#define INITSIZE 10

using namespace std;

typedef int Elemtype;

typedef struct
{
    Elemtype data[INITSIZE];
    int top;
    int StackSize;
} SqStack;

void InitStack (SqStack &s)
{
    s.top = 0;
    s.StackSize = INITSIZE;
}

void Push (SqStack &s, Elemtype x)
{
    s.data[s.top++] = x;
}

void Pop (SqStack &s, Elemtype &x)
{
    x = s.data[--s.top];
}

bool StackEmpty (SqStack s)
{
    return s.top == 0;
}

string Conversion (SqStack s, int a, int cet)
{   
    string ans, tem;

    if (!a) 
    {
        ans = '0';
        return ans;
    }

    while (a)
    {
        Push(s, a % cet);
        a /= cet;
    }

    while (!StackEmpty(s))
    {
        Elemtype x;
        Pop(s, x);

        if (x < 10) ans = ans + char(x + '0');
        else ans = ans + char(x + 'A' - 10);
    }

    return ans;
}

int main()
{
    SqStack s;
    InitStack(s);

    int a, n = 5, cet[3] = {2, 8, 16};
    string ans;

    for (int i = 1; i <= 5; i++)
    {
        cout << "�������" << i << "���Ǹ�ʮ������������";
        cin >> a; 

        for (int j = 0; j <= 2; j++)
        {
            ans = Conversion(s, a, cet[j]); 
            cout << "ת��Ϊ" << cet[j] << "���ƺ�Ľ��Ϊ��" << ans << endl;
        }

        cout << endl;
    }

    return 0;
}

/*
                     2      8     16
����: 12     ���:  1100    14     C
���룺26     ����� 11010    32    1A
���룺100    �����1100100  144    64
���룺0      �����   0      0      0
���룺77     �����1001101  115    4D
*/