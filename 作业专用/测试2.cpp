#include <iostream>

using namespace std;

typedef struct OLNode
{
    int i, j, e;
    struct OLNode *right, *down;
} OLNode, *OLink; 

typedef struct
{
    OLink *rhead, *chead;
    int r, c, n;
} CrossList;

// 构建十字链表
void CreateSMatrix_OL (CrossList &m)
{
    int r, c, n;
    cin >> r >> c >> n;
    m.r = r, m.c = c, m.n = n;

    m.rhead = new OLink[n + 1];
    m.chead = new OLink[n + 1];
    for (int i = 1; i <= n; i++)
    {
        m.rhead[i] = NULL;
        m.chead[i] = NULL;
    }

    int i, j, e;
    for (int s = 1; s <= n; s++)
    {
        cin >> i >> j >> e;
        OLNode *p = new OLNode;
        p -> i = i;
        p -> j = j;
        p -> e = e;

        if (m.rhead[i] == NULL || m.rhead[i] -> j > j)
        {
            p -> right = m.rhead[i];
            m.rhead[i] = p;
        }
        else
        {
            for (OLNode *q = m.rhead[i]; q && q -> j < j; q = q -> right)
            {
                p -> right = q -> right;
                q -> right = p;
            }
        }
        
        if (m.chead[j] == NULL || m.chead[j] -> i > i)
        {
            p -> down = m.chead[j];
            m.chead[j] = p;
        }
        else
        {
            for (OLNode *q = m.chead[j]; q && q -> i < i; q = q -> down)
            {
                p -> down = q -> down;
                q -> down = p;
            }
        }
    }
}

// 打印矩阵
void Show (CrossList x)
{
    for (int i = 1; i <= x.r; i++)
        for (OLNode *t = x.rhead[i]; t; t = t -> right) 
            cout << "r:" << t -> i << " c:" << t -> j << " e:" << t -> e << endl;
}

int main ()
{
    CrossList c;

    CreateSMatrix_OL(c);

    Show(c);

    return 0;
}