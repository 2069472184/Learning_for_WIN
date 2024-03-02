// https://www.acwing.com/problem/content/description/1015/

// ��ģ����
#include <iostream>

using namespace std;

const int N = 15, M = 20;

int n, m, g[N][M];
int f[N][M], res[N], idx;

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> g[i][j];
    
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k <= j; k++)
                f[i][j] = max(f[i][j], f[i + 1][j - k] + g[i][k]);
    
    cout << f[1][m] << endl;
    
    int j = m;
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= j; k++)
            if (f[i][j] == f[i + 1][j - k] + g[i][k])
            {
                res[i] = k;
                j -= k;
                break;   // Ϊ�����ֵ�����С��Ҫ����������ڵ�һ������������������һ��ѭ��������k������
            }
            
    for (int i = 1; i <= n; i++) cout << i << ' ' << res[i] << endl;
    
    return 0;
}