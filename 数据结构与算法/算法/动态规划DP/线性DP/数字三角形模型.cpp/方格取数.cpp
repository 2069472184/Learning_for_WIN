//https://www.acwing.com/problem/content/1029/

//������Կ���������·ͬʱ���У���Ϊȡ���Ϊ0���൱�ڲ��پ�����һ��λ��
#include <iostream>

using namespace std;

//ע�⣺���ｲ���鳤�ȿ���һ������Ϊ f ����ĵ�һά����������
const int N = 25;

int n, x, y, c, g[N][N];
int f[N][N][N];
//״̬��ʾ��f[k][i][j]��ʾ����k����a�ߵ�(i, n - i)����b�ߵ�(j, n - j)��
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
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (k - i <= 0 || k - j <= 0 || k - i > n || k - j > n) continue;
                
                f[k][i][j] = get(k, i, j) + g[i][k - i];
                if (i != j) f[k][i][j] += g[j][k - j];
            }
            
    cout << f[n * 2][n][n] << endl;
            
    return 0;
}