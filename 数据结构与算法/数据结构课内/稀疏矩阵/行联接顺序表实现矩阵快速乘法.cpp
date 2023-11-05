#include <iostream>
#define MAXSIZE 100
#define MAXROW 10
#define Elemtype int

using namespace std;

typedef struct 
{
    int i, j;

    Elemtype e;
} Triple;

typedef struct 
{
    Triple data[MAXSIZE + 1];

    int rpos[MAXROW + 1]; // ���е�һ������Ԫ��λ�ñ�

    int r, c, n;
} RLSMatrix;

int r, c, n, x, y, data, acc[MAXROW + 1];

// ����������˳���
void InitSMatrix (RLSMatrix &a)
{
    cin >> r >> c >> n;
    a.r = r, a.c = c, a.n = n;

    for (int i = 1; i <= a.n; i++)
    {
        cin >> x >> y >> data;
        a.data[i] = {x, y, data};
    }

    int num[r + 1] = {0};
    for (int p = 1; p <= a.n; p++) num[a.data[p].i]++;

    a.rpos[1] = 1;
    for (int row = 2; row <= a.r; row++)
        a.rpos[row] = a.rpos[row - 1] + num[row - 1];
}

// ���ٳ˷����������ߴ�����˷�����
void MultSMatrix (RLSMatrix a, RLSMatrix b, RLSMatrix &q)
{
    q.r = a.r, q.c = b.c, q.n = 0;

    // ��������a��ÿһ��
    for (int arow = 1; arow <= a.r; arow++)
    {
        // q��arow�и�λ�õĵ��ۼ���
        int acc[q.c + 1] = {0};

        // �ṹ�����������a��ͬ������arow������
        // ���ͬʱ��ÿ����һ�ξͼ��㵱ǰ�з�����Ԫ��q.data�е�����
        q.rpos[arow] = q.n + 1;

        // ���㵱ǰ�з���Ԫ����a.data�е�������β
        int tp = 0; 
        if (arow < a.r) tp = a.rpos[arow + 1];
        else tp = a.n + 1;

        // �������ұ���a.data����arow���ڵ�����Ԫ��
        for (int p = a.rpos[arow]; p < tp; p++)
        {
            // ����a��ÿһ������Ԫ��������
            int brow = a.data[p].j;

            // a�е�����b�е�����ˣ���brow���൱��b�е���
            // ���㵱ǰ����b.data�е�������β
            int t = 0;
            if (brow < b.r) t = b.rpos[brow + 1]; 
            else t = b.n + 1;

            // �������ұ���b.data����brow���ڵ�����Ԫ��
            for (int s = b.rpos[brow]; s < t; s++)
            {
                // ��õ�ǰԪ�������У�b������q������ͬ
                int col = b.data[s].j;
                // �ۼ���q[arow][col]�ϵĳ˻�
                acc[col] += a.data[p].e * b.data[s].e;
            }
        }

        // ���ۼ�������q����Ӧλ��
        // q.data[]�±�Ϊq.n����Ϊq.n�Ƕ�̬���µģ�ÿ����һ��Ԫ�ؾͼ�1
        for (int col = 1; col <= q.c; col++)
            if (acc[col]) q.data[++q.n] = {arow, col, acc[col]};
    }
}

// ��ӡϡ�����
void Show (RLSMatrix m)
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
    RLSMatrix a, b, q;
    InitSMatrix(a);
    InitSMatrix(b);
    
    MultSMatrix(a, b, q);

    Show(q);

    return 0;
}