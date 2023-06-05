//https://www.acwing.com/problem/content/1024/

/*
������Ҫע��һ�㣬���ǵڶ�ά�ķ��á����˺����ܺͲ��ܴ��ڵ���Ƥ�����������
��˵ڶ�ά�����ֵ���� m - 1
*/

#include <iostream>

using namespace std;

const int N = 1010;

int n, m, k;
int c, h;
int f[N][N];

int main ()
{
    cin >> n >> m >> k;
    
    for (int i = 1; i <= k; i++)
    {
        cin >> c >> h;
        
        for (int j = n; j >= c; j--)
            for (int k = m - 1; k >= h; k--)
                f[j][k] = max(f[j][k], f[j - c][k - h] + 1);
    }
    
    cout << f[n][m - 1] << ' ';
    
    /*
    ���ڵڶ��ʣ��շ����С����ʱʣ����������ֵΪ���٣�

    */
    int cnt = m - 1;  //��ʼ��ֵ������ m = 1 ���������
    for (int i = m - 2; i >= 0; i--)  //ע�⣬�ڶ�ά������0�������շ��κξ�������
        if (f[n][i] == f[n][m - 1]) cnt = i;
    
    cout << m - cnt << endl;
    
    return 0;
}