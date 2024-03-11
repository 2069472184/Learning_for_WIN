// https://www.acwing.com/problem/content/1074/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 10005;

int n, h[N], e[2 * N], w[2 * N], ne[2 * N], idx, ans;

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs (int u, int father)
{
    int dist = 0;        // �ӵ�ǰ�㿪ʼ���±����������
    int d1 = 0, d2 = 0;  // �ӵ�ǰ�㿪ʼ���±����������ʹγ�����
    
    for (int i = h[u]; i != -1; i = ne[i])  // ����������ڵ�u�����Ľڵ�
    {
        int j = e[i];
        if (j == father) continue;          // ������������ڵ�������
        
        int d = dfs(j, u) + w[i];           // ������ӽڵ�j��ʼ���±����������
        
        dist = max(dist, d);                
        
        if (d > d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
    }
    
    ans = max(ans, d1 + d2);                // �������ʹγ�������Ӽ��ɵõ������ڵ�i�������
    
    return dist;
}

int main ()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        add(a, b, c);
        add(b, a, c);
    }

    dfs(1, -1);  // ������һ���ڵ㿪ʼ�������ڶ���������ʾ���ڵ��ţ����ڷ�ֹ���ϱ��������
    
    cout << ans << endl;
    
    return 0;
}