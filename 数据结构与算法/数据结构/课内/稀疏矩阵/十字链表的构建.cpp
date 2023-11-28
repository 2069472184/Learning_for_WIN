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

// ����ʮ������
void CreateSMatrix_OL (CrossList &m)
{
    // ¼��ʮ������ߴ缰����Ԫ����
    int r, c, n;
    cin >> r >> c >> n;
    m.r = r, m.c = c, m.n = n;

    // �Ѷ�����ı��������ڴ�ռ�����ָ������
    m.rhead = new OLink[n + 1];
    m.chead = new OLink[n + 1];
    
    // ����ָ��ָ��NULL
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

        // ���ȹ���������
        // �����Ԫ������û��Ԫ�ػ��߸÷���Ԫ�ڸ����еľ���Ԫ���
        // ��ֱ�Ӹ��¸�����Ԫ��λ��
        // ʮ�������У�ÿһ��ÿһ�е�ĩβԪָ�붼ָ��NULL�����Ǵ�����ж���������ȥ��
        // NULLָ�벻�ϱ����ݵ�ĩβλ�á�
        if (m.rhead[i] == NULL || m.rhead[i] -> j > j)
        {
            // ��Ԫָ�����Ԫ
            p -> right = m.rhead[i];
            // ����ָ����Ԫ��ָ��
            m.rhead[i] = p;
        }
        else // ���÷���Ԫ�ڸ����е���Ԫ�ұ�
        {
            // һֱ���ұ�����ֱ����������Ԫ�����е�������һ���ϵķ���Ԫ
            for (OLNode *q = m.rhead[i]; q && q -> j < j; q = q -> right)
            {
                // ������Ԫ
                p -> right = q -> right;
                q ->right = p;
            }
        }

        // �����������Ĺ���ͬ��
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

// ��ӡ����
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