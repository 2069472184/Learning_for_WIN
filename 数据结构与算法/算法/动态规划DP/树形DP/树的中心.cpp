// https://www.acwing.com/problem/content/1075/

// ע�����⣬����Ҫ�����ĳ���㵽�����������·���е���Сֵ��

// ����д����ֱ�ӱ�������ÿһ���㣬�������ǰ�������е�����룬��������ans�Ƚϡ�6/11
#include <iostream>
#include <cstring>

using namespace std;

const int N = 10005;

int n, h[N], e[2 * N], ne[2 * N], w[2 * N], idx;
int dist;

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs (int u, int father)
{
    int dist = 0;
    
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        
        if (j == father) continue;
        
        int d = dfs(j, u) + w[i];
        
        dist = max(dist, d);
    }
    
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
    
    int ans = 0x3f3f3f3f; 
    for (int i = 1; i <= n; i++) ans = min(ans, dfs(i, -1));  // �����dfs�������ѭ���ڣ�ÿ�����һ���ڵ������롣
    // ����Ϊʲô�����������·����һ��ֻ����һ�Σ�����Ϊÿ�����Ѷ��Ὣ��ʼ������Ǹ��ڵ�涨Ϊ���ĸ��ڵ㣬����֮����ֻ����ȫ����õ��һ������롣
    // ��������ڵ㣬������dfs�����й涨�������ϱ������ڵ㣬ֻ�������Щ�ڵ�������Ϊ���ڵ�������е�һ������룬����Ȼ������Ϊ���յĴ𰸡�

    cout << ans << endl;
    
    return 0;
}

// �Ż�д����
/*
Ϊ���ֲ�����д���ж���ѭ�����µĳ�ʱ���⣬�������һ�ֻ���DP��˼�룺
���ؽⷨ�е�dfs���ܱ������ڵ㣬Ϊ�˽��������⣬��������һ�����µ�dfs������һ�����ϱ������ڵ��dfs
���µ�dfs����������нڵ���������Ϊ���ڵ�������е������d
���ϵ�dfs����������н��ĸ��ڵ�������Ϊ���ڵ�������е������u����b���֣�
Ϊ�˷�ֹd��u�غϵ��������Ҫ������dfsʱά���������飺��ǰ���i���µ������ʹγ����룬�Լ����������Ӧ������ţ�i��ĳ���ӽڵ㣩
������dfsʱ��ֻ��Ҫ�ж�i�ĸ��ڵ�j������Ϊ���ڵ�������е�������Ƿ���iΪ���
����ǣ�ֻ�ܽ�j�Ĵγ�������Ϊi���ϵ�����룻��֮��ֱ�ӽ�j������븳��i���ϵ�����롣
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005;

int n, h[N], e[2 * N], ne[2 * N], w[2 * N], idx;
int d1[N], d2[N], p1[N], up[N];
bool is_leaf[N];

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs_down (int u, int father)
{
    d1[u] = d2[u] = -0x3f3f3f3f;   
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == father) continue;
        
        int d = dfs_down(j, u) + w[i];
        
        if (d >= d1[u])
        {
            d2[u] = d1[u], d1[u] = d;
            p1[u] = j;
        }
        else if (d > d2[u]) d2[u] = d;
    }
        
    if (d1[u] == -0x3f3f3f3f)
    {
        d1[u] = d2[u] = 0;
        is_leaf[u] = true;
    }
    
    return d1[u];
}

void dfs_up (int u, int father)
{
    for (int i = h[u]; i != -1; i = ne[i])   // ����ڵ�u��ÿһ���ӽڵ�j���up���롣
    {
        int j = e[i];
        if (j == father) continue;
        
        if (p1[u] == j) up[j] = max(up[u], d2[u]) + w[i];
        else up[j] = max(up[u], d1[u]) + w[i];
        
        dfs_up(j, u);
    }
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
    
    // �����ĳ�ڵ������ߵ������ʹγ�����
    dfs_down(1, -1);
    
    // �����ĳ�ڵ������ߵ������
    dfs_up(1, -1);
    
    int ans = d1[1];
    for (int i = 2; i <= n; i++) 
    {
        if (is_leaf[i]) ans = min(ans, up[i]);
        else ans = min(ans, max(d1[i], up[i]));
    }
    
    cout << ans << endl;
    
    return 0;
}