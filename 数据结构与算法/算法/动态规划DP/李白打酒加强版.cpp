//https://www.acwing.com/problem/content/description/4411/

#include <iostream>

using namespace std;

typedef long long ll;

const int N = 110, Mod = 1000000007;

int n, m;
//״̬��ʾ��
//f[i][j][k]��ʾ����i�ε꣬j�λ��Ҵ�ʱ�о�k�������з�����
//״̬ת�ƣ�
//1.��ǰ�������ǵ꣺dp[i][j][k] = dp[i - 1][j][k / 2];
//2.��ǰ�������ǻ���dp[i][j][k] = dp[i][j - 1][k + 1];
//�������������dp[i][j][k] = ap[i - 1][j][k / 2] + dp[i][j - 1][k + 1];
ll dp[N][N][N];

int main ()
{
    cin >> n >> m;
    
    //״̬����
    dp[0][0][2] = 1;
    //ע�⣬�е�ʱ��״̬���ڿ��ܻ�Ƚ϶࣬��ʱ�����ѭ�����Դ�0��ʼ��
    //����������Խ��ֻ��Ҫ��ת��֮ǰ�Ӹ��ж�
    
    //״̬ת��
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= m; k++)
            {
                if (j) dp[i][j][k] = dp[i][j - 1][k + 1];
                if (k % 2 == 0 && i) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k / 2]) % Mod;
            }
    
    //��������ĵ����ڶ���һ���� dp[n][m][1]
    cout << dp[n][m - 1][1] << endl;
    
    return 0;
}