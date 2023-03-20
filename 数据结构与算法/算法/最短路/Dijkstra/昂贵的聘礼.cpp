//https://www.acwing.com/problem/content/905/

//���ذ�
#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
int g[N][N], level[N];
int dist[N];
bool st[N];

int dijsktra (int a, int b)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(st, 0, sizeof(st));
    dist[0] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        int t = -1;
        
        for (int j = 0; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
            
        st[t] = true;
        
        for (int j = 1; j <= n; j++)
            //�Ը��������������
            if (level[j] >= a && level[j] <= b) 
                dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    return dist[1];
}

int main ()
{
    cin >> m >> n;
    
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= n; i++) g[i][i] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        int cnt, price;
        scanf("%d%d%d", &price, &level[i], &cnt);
        
        //������Դ��0����Ʒ����һ����
        g[0][i] = min(price, g[0][i]);
        
        while (cnt--)
        {
            int id, discount;
            scanf("%d%d", &id, &discount);
            
            g[id][i] = min(g[id][i], discount);
        }
    }
    
    int res = 0x3f3f3f3f;
    //�׵������ĵȼ���һ����ߣ����Ա�������Ӧ������ ��level[1] - m, level[1] + m) �����ڣ�����Ϊ m
    for (int i = level[1] - m; i <= level[1]; i++) res = min(res, dijsktra(i, i + m));
    
    cout << res << endl;
    
    return 0;
}

