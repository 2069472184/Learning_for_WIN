// �����ⷨ
#include <iostream>

using namespace std;

const int N = 105;

int n, m, g[N][N], ans;
bool st[N][N];

int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

void dfs (int x, int y, int len)
{
    for (int k = 0; k < 4; k++)
    {
        int a = x + dx[k], b = y + dy[k];

        if (a < 1 || a > n || b < 1 || b > m) continue;

        if (!st[a][b] && g[a][b] <= g[x][y])
        {
            st[a][b] = true;

            dfs(a, b, len + 1);

            st[a][b] = false;
        } 
    }

    if (ans < len) 
    {
        ans = len;
        return;
    }
}   

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> g[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dfs(i, j, 1);

    cout << ans << endl;

    return 0;
}

// ���仯����
#include <iostream>

using namespace std;

const int N = 105;

int r, c, h[N][N], ans;
int dp[N][N];

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };  //�������ҷֱ������ϣ����ң����£�����

int DP ( int x, int y )
{
    //��ֹ�ظ�������ͬλ�õ�·�����ֵ�����͸��Ӷ�
    if ( dp[x][y] ) return dp[x][y];  //���dp[x][y]��Ϊ0��˵���Ѿ����������

    //��ʼ��Ҫ�����λ�õ�ֵ��һ��ʼ����һ����λ����
    dp[x][y] = 1;
    for ( int i = 0; i <= 3; i++ )
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if ( a >= 1 && a <= r && b >= 1 && b <= c && h[x][y] > h[a][b] )
            dp[x][y] = max( dp[x][y], DP(a, b) + 1 );
    }

    return dp[x][y];
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &r, &c );
    for ( int i = 1; i <= r; i++ )
        for ( int j = 1; j <= c; j++ )  
            scanf( "%d", &h[i][j] );

    for ( int i = 1; i <= r; i++ )
        for ( int j = 1; j <= c; j++ )
            ans = max( ans, DP(i, j) );

    printf( "%d\n", ans );

    return 0;
}