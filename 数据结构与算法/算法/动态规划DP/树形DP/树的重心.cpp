// https://www.acwing.com/problem/content/848/

// ���ؽⷨ�����ÿһ���ڵ���һ��dfs��8/14
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005;

int n, ans = 0x3f3f3f3f;
int h[N], e[2 * N], ne[2 * N], idx;

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// ������uΪ���ڵ�������е�ĸ���
int dfs (int u, int father)
{
    int count = 0;
    int res = 0;     // �洢��ǰ������ȥ�����ڵ�u��������ͨ���нڵ������������
    
    // �����ڵ�u�������ӽڵ�
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        
        if (j == father) continue;  // �����ϱ���
        
        int d = dfs(j, u);  // �õ���jΪ���ڵ�������нڵ����
        count += d;
        
        res = max(res, d);   // ���ϸ�����ͨ���нڵ���������ֵ
    }
    
    if (father == -1) ans = min(ans, res);   
    
    return count + 1;
}

int main ()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        
        add(a, b);
        add(b, a);
    }

    for (int i = 1; i <= n; i++) dfs(i, -1);
    
    cout << ans << endl;
    
    return 0;
}

// ��һ��dfs��������մ�
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005;

int n, ans = 0x3f3f3f3f;
int h[N], e[2 * N], ne[2 * N], idx;
bool st[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// ������uΪ���ڵ�������е�ĸ���
int dfs (int u)
{
    st[u] = true;  // ÿ����ֻ����һ��
    
    int count = 0;
    int res = 0;     // �洢��ǰ������ȥ�����ڵ�u��������ͨ���нڵ������������
    
    // �����ڵ�u�������ӽڵ�
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        
        if (st[j]) continue;
        
        int d = dfs(j);  // �õ���jΪ���ڵ�������нڵ����
        count += d;
        
        res = max(res, d);   // ���ϸ�����ͨ���нڵ���������ֵ
    }
    
    res = max(res, n - count - 1);   
    // resΪ��u�ڵ����µ���ͨ���нڵ������n - count - 1Ϊ��u�ڵ����ϵ���ͨ����еĽڵ����
    ans = min(ans, res);   
    
    return count + 1;
}

int main ()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        
        add(a, b);
        add(b, a);
    }

    dfs(1);
    
    cout << ans << endl;
    
    return 0;
}