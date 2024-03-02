// https://www.acwing.com/problem/content/11/

// ��ά�ⷨ��ע���ʼ��
#include <iostream>

using namespace std;

const int N = 1005, mod = 1e9 + 7;
typedef long long ll;

int n, m, v, w;
int f[N][N];
ll g[N][N];

int main ()
{
    cin >> n >> m;
    
    for (int i = 0; i <= m; i++) g[0][i] = 1;  // ʲô����ȡ���Ϸ�״̬������״̬�ɴ�ת������
    for (int i = 0; i <= n; i++) g[i][0] = 1;  // ����״̬�ɴ�ת������
     
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w;
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            g[i][j] = g[i - 1][j];
            
            if (j >= v) 
                if (f[i][j] == f[i - 1][j - v] + w) g[i][j] = (g[i - 1][j] + g[i - 1][j - v]) % mod;
                else if (f[i][j] < f[i - 1][j - v] + w)
                {
                    f[i][j] = f[i - 1][j - v] + w;
                    g[i][j] = g[i - 1][j - v];
                }
        }
    }
    
    cout << g[n][m] << endl;
    
    return 0;
}

һά�Ż�
#include <iostream>

using namespace std;

const int N = 1005, mod = 1e9 + 7;
typedef long long ll;

int n, m, v, w;
int f[N];
ll g[N];

int main ()
{
    cin >> n >> m;
    
    for (int i = 0; i <= m; i++) g[i] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w;
        for (int j = m; j >= v; j--)
            if (f[j] == f[j - v] + w) g[j] = (g[j] + g[j - v]) % mod;
            else if (f[j] < f[j - v] + w)
            {
                f[j] = f[j - v] + w;
                g[j] = g[j - v];
            }
    }
    
    cout << g[m] << endl;
    
    return 0;
}