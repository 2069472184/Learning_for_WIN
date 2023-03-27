//https://www.acwing.com/problem/content/6/

//���������Ż�
/*
���������д洢��ֵ����ʵ�ʱ�ʾ��ֵ�����������±������Ԫ�صĹ�ϵ��
Ҳ������һ��x��y�ĺ�����ϵ��������ر������⡣
��Ȼ������Ҫ�ҵ�ÿ����ӵ�ֵa����ʵ�ʱ�ʾ��ֵf(a)֮��ĺ����������ϵ��
���Ҹ������ֹ�ϵ�õ�f(a)������f(q[t])�Ƚϣ������֮ǰ�ó��ĵ������Ƽ����жϡ�
*/
/*
1.���ȣ���Ҫ����άת��Ϊһά���⣺
dp[i][j] = max( dp[i-1][j], dp[i-1][j-v] + w, �������� , dp[i-1][j-k*v] + k*w );
��Ϊ��dp[j] = max( dp[j], dp[j-v] + w, �������� , dp[j-k*v] + k*w );

2.�õ�dp�����ȡmax����
��ʱ��j����������������ÿһ����Ʒ�����㣺j = k*v + n. 
v���������k�����ֻȡ����Ʒ��ô����Ʒ�ܹ�ȡ�õ����������n��ȥ��֮��ʣ�µ����
���ԣ��У�dp[k*v + n] = max( dp[k*v + n], dp[(k-1)*v + n] + w, �������� , dp[v + n] + (k-1)*w, dp[n] + k*w ); 
��ʱ 0 <= n < v������������ʽ�Ľ����ԭһ�飺
dp[n] = dp[n];                                          
dp[n+v] = max( dp[n] + w, dp[n+v] );                     //dp[n] �� dp[n+v] ��� 1 �� w
dp[n+2*v] = max( dp[n] + 2*w, dp[n+v] + w, dp[n+2*v] );  //dp[n] �� dp[n+2*v] ��� 2 �� w
������������
��������֪��������ÿ����Ʒ�����������޵�(�����������Ϊs)��Ҳ����˵ k = s����n���ϼ��ϵ�����Ʒ���������ܳ��� n + s*v
��������ǿ����˻������ڵ�Ӱ�ӣ�ά��һ������Ϊs�ĵ����ݼ����У�����q�洢��������� n + m*v. ( 0 <= m < s )
q[h]������С�� n + m*v ������һ��ֵ��dp[q[h]]��dp[k]��� k - q[h] �� w.

3.�õ�f(a)����������ж�
Ϊ�˵õ�����ÿһ���ƶ��³��ֵ�������������д��
dp[n] = dp[n];
dp[n+v] = max( dp[n], dp[n+v] - w ) + w;
dp[n+2*v] = max( dp[n], dp[n+v] - w, dp[n+2*v] - 2*w ) + 2*w;  
dp[n+3*v] = max( dp[n], dp[n+v] - w, dp[n+2*v] - 2*w, dp[n+3*v] - 3*w ) + 3*w;
������������
ÿ���³��ֵ�ֵ����dp[n+m*v] - m*w�����ں� dp[q[t]] - (q[t] - j)/v * w �Ƚϣ�
����ÿ��ֵҲ�ͱ�ʾ dp[q[n + m*v]] - (q[n + m*v] - n)/v * w. 
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 20010;

//tem������һ����Ʒ������������dpֵ
int q[N], dp[N], tem[N];   
int n, m, v, w, s;

int main ()
{
    cin >> n >> m;

    for ( int i = 0; i < n; i++ )
    {
        memcpy(tem, dp, sizeof(dp));
        cin >> v >> w >> s;
        for ( int j = 0; j < v; j++ )
        {
            int h = 0, t = -1;
            for ( int k = j; k <= m; k += v )
            {
                if ( h <= t && k - s*v > q[h] ) h++;

                while ( h <= t && tem[q[t]] + (q[t])/v * w <= tem[k] - (k - j)/v * w ) t--;

                if ( h <= t ) dp[k] = max( tem[k], tem[q[h]] + (k - q[h])/v * w );

                q[++t] = k;
            }
        }
    }

    cout << dp[m] << endl;

    return 0;
}