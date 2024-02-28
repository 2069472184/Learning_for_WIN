//https://www.acwing.com/problem/content/1029/
// ���ؽⷨ
#include <iostream>

using namespace std;

int n, r, c, x, g[15][15], dp[15][15][15][15]; 
// dp[x1][y1][x2][y2] ��ʾ��(0, 0)��(x1, y1)��(x2, y2)������·���У����ֺ���������

int main()
{
    cin >> n;
    
    while (cin >> r >> c >> x, r || c || x) g[r][c] = x;
    
    for (int i1 = 1; i1 <= n; i1++)
        for (int j1 = 1; j1 <= n; j1++)
            for (int i2 = 1; i2 <= n; i2++)
                for (int j2 = 1; j2 <= n; j2++)
                {
                    dp[i1][j1][i2][j2] = max(max(dp[i1 - 1][j1][i2 - 1][j2], dp[i1 - 1][j1][i2][j2 - 1]), 
                                             max(dp[i1][j1 - 1][i2 - 1][j2], dp[i1][j1 - 1][i2][j2 - 1]));
                                             
                    if (i1 == i2 && j1 == j2) dp[i1][j1][i2][j2] += g[i1][j1];
                    else dp[i1][j1][i2][j2] += g[i2][j2] + g[i1][j1];
                }
                
    cout << dp[n][n][n][n] << endl;
    
    return 0;
}

//������Կ���������·ͬʱ���У���Ϊȡ���Ϊ0���൱�ڲ��پ�����һ��λ��
#include <iostream>

using namespace std;

//ע�⣺���ｲ���鳤�ȿ���һ������Ϊ f ����ĵ�һά����������
const int N = 25;

int n, x, y, c, g[N][N];
int f[N][N][N];
//״̬��ʾ��f[k][i][j]��ʾ����k����a�ߵ�(i, k - i)����b�ߵ�(j, k - j)��
//״̬ת�ƣ�����±겻Խ�磬��ôֱ�Ӵ�i - 1�� i�� j - 1, j�ĸ�������ȡ���ֵ

int get (int k, int i, int j)
{
    int ans = max(max(f[k - 1][i - 1][j], f[k - 1][i - 1][j - 1]), max(f[k - 1][i][j], f[k - 1][i][j - 1]));
    return ans;
}

int main ()
{
    cin >> n;
    
    while (cin >> x >> y >> c, x || y || c) g[x][y] = c;
    
    for (int k = 2; k <= n * 2; k++)
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= k; j++)
            {  
                f[k][i][j] = get(k, i, j) + g[i][k - i];
                if (i != j) f[k][i][j] += g[j][k - j];
            }
            
    cout << f[n * 2][n][n] << endl;
            
    return 0;
}