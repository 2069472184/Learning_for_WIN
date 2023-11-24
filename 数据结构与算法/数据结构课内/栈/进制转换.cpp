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

int Conversion (SqStack s, Elemtype a, Elemtype cet)
{   
    Elemtype ans = 0;
    while (a)
    {
        Push(s, a % cet);
        a /= cet;
    }

    while (!StackEmpty(s))
    {
        Elemtype x;
        Pop(s, x);
        ans = ans * 10 + x;
    }

    return ans;
}

int main()
{
    SqStack s;
    InitStack(s);

    int a, cet, ans, n = 25;
    while (n--)
    {
        cout << "������һ���Ǹ�ʮ��������" << endl;
        cin >> a; 
        cout << "����������ת���Ľ��ƣ�" << endl;
        cin >> cet;

        ans = Conversion(s, a, cet);

        cout << "ת�����Ϊ��" << ans << endl;
    }

    return 0;
}