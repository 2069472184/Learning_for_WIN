//https://www.acwing.com/problem/content/481/

#include <iostream>

using namespace std;

const int N = 35;

int n, a[N];
//dp[i][j] ��ʾ�� i ~ j ������ɵ����������ӷ�ֵ��g[i][j] ��¼�����ֵ��Ӧ�������ĸ��ڵ��±�
int dp[N][N], g[N][N];

//��ǰ����������
void dfs (int l, int r)
{
    if (l > r) return;

    cout << g[l][r] << ' ';

    dfs(l, g[l][r] - 1);
    dfs(g[l][r] + 1, r);
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int len = 1; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if (len == 1) dp[i][j] = a[i], g[i][j] = i;
            else
            {
                for (int k = i; k <= j; k++) 
                {
                    int ltree = k == i ? 1 : dp[i][k - 1];
                    int rtree = k == j ? 1 : dp[k + 1][j];
                    int score = ltree * rtree + a[k];
                    if (dp[i][j] < score)
                    {
                        g[i][j] = k;
                        dp[i][j] = score;
                    }
                }
            }
        }

    cout << dp[1][n] << endl;

    dfs(1, n);

    return 0;
}