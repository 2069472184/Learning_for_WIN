//https://www.acwing.com/problem/content/description/4410/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 50010, M = 999997;

int n, m;

//�����׵�����Ͱ뾶
struct circle 
{
    int x, y, r;
} cir[N];

ll h[M];  //�����ϣ��������ÿ���Ѱַ��
int id[M];  //����ÿһ������ը����Ӧ�� h �����±�
bool st[M];  //�������鱣֤ÿһ��������ը��ֻ�ᱻ����һ��

//�� x * (1e9 + 1) + y ����ʽ�õ�ÿһ������Ĺ�ϣֵ
//��Ϊ�������Ϊ 1e9�������� 1e9 ����С�������� 1e9 + 1
ll get_key (int x, int y)
{
    return (ll)x * 1000000001 + y;
}

//��ϣ���Ѱ�Ҳ���
int find (int x, int y)
{
    ll key = get_key(x, y);
    int t = (key % M + M) % M;
    
    while (h[t] != -1 && h[t] != key)
    {
        t++;
        if (t == M) t = 0;
    }
        
    return t;
}

//����ÿһ�������������ը�����ܹ�����������ը��
void dfs (int x, int y, int r)
{
    st[find(x, y)] = true;
    
    for (int i = x - r; i <= x + r; i++)
        for (int j = y - r; j <= y + r; j++)
            if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r)
            {
                int t = find(i, j);
                if (id[t] && !st[t]) dfs(i, j, cir[id[t]].r);
            }
}

int main()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    for (int i = 1; i <= n; i++)
    {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        cir[i] = {x, y, r};
        
        //�õ���ǰը����ϣֵ�� h �����е��±�
        int t = find(x, y);
        //��� h[t] ��û��Ԫ�أ������
        if (h[t] == -1) h[t] = get_key(x, y);
        //����ǵ�ǰ���껹û��ը������ǰλ���ϵ�ը���뾶�Ƚ�С�Ļ������µ�ǰλ�õ�ը��id
        if (!id[t] || cir[id[t]].r < r) id[t] = i;
    }
    
    while (m--)
    {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        
        //������ǰ���������Χ�ڵ�������������
        for (int i = x - r; i <= x + r; i++)
            for (int j = y - r; j <= y + r; j++)
                if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r)
                {
                    //�����ǰ������ը����δ�����������Ը�ը��Ϊ��������������ܱ�����������ը��
                    int t = find(i, j);
                    if (id[t] && !st[t]) dfs(i, j, cir[id[t]].r);
                }
    }
    
    //�����ж���ը��������
    //��Ϊ st ������±�Ϊ��ϣ����ÿһ��ը����ϣֵ����Ӧ���±�
    //������Ҫ���󵽵�ǰը����ϣֵ�Ķ�Ӧ�±꣺��ϣ����Ҳ���
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (st[find(cir[i].x, cir[i].y)]) res++;
        
    cout << res << endl;
    
    return 0;
}