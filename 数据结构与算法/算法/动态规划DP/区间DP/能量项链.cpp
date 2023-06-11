//https://www.acwing.com/problem/content/322/

#include <iostream>

using namespace std;

const int N = 205;

int n, m[N];
int dp[N][N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> m[i];
        m[i + n] = m[i];
    }
    
    //���⽫��������һ��������ʼ��������󳤶�Ϊn + 1����ͱ�֤�˲����ظ������Ѿ��ϲ��ĵ�
    //�൱��һ���������ڣ������оͰѵ�n�����Ӻ͵�һ�����ӵ����кϲ�ʱ����������ȥ��
    for (int num = 3; num <= n + 1; num++) //num��ʾ������+1������ȥ��ͬ������ͷ��Ǻ�β���
        for (int i = 1; i + num - 1 <= n * 2; i++)
        {
            int j = i + num - 1;
            dp[i][j] = 0;  //����max�ĳ�ʼ��
            
            for (int k = i + 1; k < j; k++) 
                dp[i][j] = max(dp[i][j], dp[i][k] + m[k] * m[i] * m[j] + dp[k][j]);
        }   
    
    //�����д���������ȫ�����Ȣ�����ֵ
    int res = 0;
    for (int l = 1; l <= n; l++) res = max(res, dp[l][l + n]);
    
    cout << res << endl;
    
    return 0;
}