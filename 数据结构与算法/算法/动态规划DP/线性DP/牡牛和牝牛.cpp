//https://www.acwing.com/problem/content/1309/

/*
״̬��ʾ��dp[i] ��ʾ�� i ��λ������ţ�����з���
״̬���㣺��ֻ��ţ֮�����ٴ��� k ֻĵţ��
    dp[i] = dp[i - 1] + dp[i - 2] + �� + dp[i - k - 1]
*/

#include <iostream>

using namespace std;

const int N = 100010, Mod = 5000011;

int n, k;
int f[N], s[N];

int main ()
{
    cin >> n >> k;
    
    //��״̬��һֻ��ţ������Ҳ��һ�ַ���
    f[0] = 1, s[0] = 1;
    for (int i = 1; i <= n; i++) 
    {
        //i- k - 1 �����Ǹ���������һֻţ���� i ֻţ֮��ţ��������δ�� k ֻ����ʱҲ��һ�ַ���
        f[i] = s[max(i - k - 1, 0)];
        s[i] = (f[i] + s[i- 1]) % Mod;
    }
    
    cout << s[n] << endl;
    
    return 0;
}