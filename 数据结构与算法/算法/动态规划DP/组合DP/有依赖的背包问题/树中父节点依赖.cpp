// https://www.acwing.com/problem/content/10/

// ����DP+���鱳��DP

// ��ά�ⷨ
#include <iostream>
#include <vector>

using namespace std;

const int N = 105;

int n, m, v[N], w[N], p, root;
vector<int> son[N];
int f[N][N][N];   // ��iΪ���ڵ㣬�Ӹ��ڵ��ǰj��������ѡ����������Ϊk�ļ���

void dfs (int u)
{
    // ��������пɷ�����������ڸ��ڵ�u��������򽫸��ڵ���������ȥ
    // ��ΪҪ����������е������ڵ㣬�ͱ�����丸�ڵ㡣
    for (int j = v[u]; j <= m; j++) f[u][0][j] = w[u];   // ע�⣬�ڶ�άԪ������ȫ����ʼ����ֻ��Ҫ��ʼ�����0����
    
    // �������ڵ�u�������ӽڵ㣬iΪ�Ѿ��������ӽڵ����
    for (int i = 1; i < son[u].size(); i++)
    {
        int s = son[u][i];              // ��ǰ�ӽڵ�ı��
        int s_num = son[s].size() - 1;  // ��ǰ�ӽڵ�������Ϊ���ڵ�������е��ӽڵ����
        dfs(s);                         // ������Ե�ǰ�ӽڵ�Ϊ���ڵ�������е����м�ֵѡ��״̬
        
        // ���鱳��ģ�壺��u��ǰi��������ǰi����Ʒ�飩��ѡ���������������j�����з���
        for (int j = v[u]; j <= m; j++)
            for (int k = 0; k <= j - v[u]; k++) // �ڵ�i����ѡ������Ϊk������Ϊ j - v[u]����Ϊ���ڵ��ѡ
                f[u][i][j] = max(f[u][i][j], f[u][i - 1][j - k] + f[s][s_num][k]);
    }
}

int main ()
{
    cin >> n >> m;
    
    // Ҫ��son������±�1��ʼ��¼�ӽڵ㣬��Ҳ���Ϸ��鱳���������ĺ���
    for (int i = 1; i <= n; i++) son[i].push_back(0);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> p;
        
        if (p == -1) root = i;
        else son[p].push_back(i);
    }
    
    dfs(root);
    
    cout << f[root][son[root].size() - 1][m] << endl;
    
    return 0;
}

// ��ά�Ż��ⷨ������鱳���Ķ�ά�Ż���ȫһ��
#include <iostream>
#include <vector>

using namespace std;

const int N = 105;

int n, m, v[N], w[N], p, root;
vector<int> son[N];
int f[N][N];   // ��iΪ���ڵ㣬�Ӹ��ڵ��ǰj��������ѡ����������Ϊk�ļ���

void dfs (int u)
{
    // ��������пɷ�����������ڸ��ڵ�u��������򽫸��ڵ���������ȥ
    // ��ΪҪ����������е������ڵ㣬�ͱ�����丸�ڵ㡣
    for (int j = v[u]; j <= m; j++) f[u][j] = w[u];   // ע�⣬�ڶ�άԪ������ȫ����ʼ����ֻ��Ҫ��ʼ�����0����
    
    // �������ڵ�u�������ӽڵ㣬iΪ�Ѿ��������ӽڵ����
    for (int i = 1; i < son[u].size(); i++)
    {
        int s = son[u][i];              // ��ǰ�ӽڵ�ı��
        dfs(s);                         // ������Ե�ǰ�ӽڵ�Ϊ���ڵ�������е����м�ֵѡ��״̬
        
        // ���鱳��ģ�壺��u��ǰi��������ǰi����Ʒ�飩��ѡ���������������j�����з���
        for (int j = m; j >= v[u]; j--)
            for (int k = 0; k <= j - v[u]; k++) // �ڵ�i����ѡ������Ϊk������Ϊ j - v[u]����Ϊ���ڵ��ѡ
                f[u][j] = max(f[u][j], f[u][j - k] + f[s][k]);
    }
}

int main ()
{
    cin >> n >> m;
    
    // Ҫ��son������±�1��ʼ��¼�ӽڵ㣬��Ҳ���Ϸ��鱳���������ĺ���
    for (int i = 1; i <= n; i++) son[i].push_back(0);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> p;
        
        if (p == -1) root = i;
        else son[p].push_back(i);
    }
    
    dfs(root);
    
    cout << f[root][m] << endl;
    
    return 0;
}

// �����ӱ�洢��
#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;

int n, m, v[N], w[N], p, root;
int h[N], e[N], ne[N], idx;
int f[N][N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs (int u)
{
    for (int j = v[u]; j <= m; j++) f[u][j] = w[u];
    
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int son = e[i];
        dfs(son);
        
        for (int j = m; j >= v[u]; j--)
            for (int k = 0; k <= j - v[u]; k++)
                f[u][j] = max(f[u][j], f[son][k] + f[u][j - k]);
    }
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> p;
        
        if (p == -1) root = i;
        else add(p, i);
    }
    
    dfs(root);
    
    cout << f[root][m] << endl;
    
    return 0;
}