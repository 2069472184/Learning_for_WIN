#include <iostream>
#define MAXSIZE 100
#define ElemType int

using namespace std;

typedef struct 
{
    int i, j;
    ElemType e;
} Triple;

typedef struct 
{
    Triple data[MAXSIZE + 1];

    int r, c, n; // �У��У�����Ԫ����
} TSMatrix;

int mr, mc, mn, data, x, y;
int num[10], cpot[10];

// ����ת��
void traditional_trans (TSMatrix m, TSMatrix &t)
{
    t.c = m.r, t.r = m.c, t.n = m.n;

    int k = 1;
    // ����ԭ�����е�ÿһ�У�Ҳ���Ǵ� t �ĵ�һ�п�ʼ�������Ԫ
    for (int col = 1; col <= m.c; col++)
        for (int p = 1; p <= m.n; p++)  // �ҳ� m ��ÿһ���ϵķ���Ԫ
            if (m.data[p].j == col)
            {
                t.data[k].i = m.data[p].j;
                t.data[k].j = m.data[p].i;
                t.data[k].e = m.data[p].e;
                k++;
            }
}

// ����ת��
void super_trans (TSMatrix m, TSMatrix &t)
{
    t.r = m.c, t.c = m.r, t.n = m.n;

    for (int p = 1; p <= m.n; p++) num[m.data[p].j]++;

    cpot[1] = 1;
    for (int col = 2; col <= m.c; col++) cpot[col] = cpot[col - 1] + num[col - 1];

    for (int p = 1; p <= m.n; p++)
    {
        int col = m.data[p].j;
        int q = cpot[col];
        t.data[q].i = m.data[p].j;
        t.data[q].j = m.data[p].i;
        t.data[q].e = m.data[p].e;
        cpot[col] ++;
    }
}

// �������
void show (TSMatrix m)
{
    int k = 1, row = 1;
    for (int col = 1; col <= m.c; col = (col % m.c) + 1)
    {
        if (m.data[k].j == col && m.data[k].i == row) cout << m.data[k++].e << ' ';
        else cout << 0 << ' ';

        if (col == m.c)
        {
            cout << endl;
            if (++row > m.r) break;
        } 
    }   
}

int main ()
{
    TSMatrix m, t;
    cin >> mr >> mc >> mn;
    m.r = mr, m.c = mc, m.n = mn;

    for (int i = 1; i <= m.n; i++)
    {
        cin >> x >> y >> data;
        m.data[i] = {x, y, data};
    }

    traditional_trans(m, t);

    super_trans(m, t);

    show(t);

    return 0;
}