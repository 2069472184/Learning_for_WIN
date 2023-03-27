//https://www.acwing.com/problem/content/274/

/*
״̬��ʾ��dp[i][j] ��ʾ������ a ��ǰ n ��Ԫ�غ����� b ��ǰ j ��Ԫ���еĹ������������У���������󳤶�
״̬ת�ƣ�
1.��ѡ a[i]��dp[i][j] = dp[i - 1][j]
2.ѡ a[i] �� b[j]��dp[i][j] = max(dp[i][j], ��ǰ i ѭ���� dp �����ֵ);
3.
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3010;

int n, m, a[N], b[N];
int dp[N][N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    
    for (int i = 1; i <= n; i++)
    {
        int maxn = 1;
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            
            if (a[i] == b[j]) dp[i][j] = max(dp[i][j], maxn);
            
            if (a[i] > b[j]) maxn = max(maxn, dp[i - 1][j] + 1);
        }
    }
        
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dp[n][i]);
        
    cout << res << endl;
    
    return 0;
}