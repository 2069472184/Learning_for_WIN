//https://www.acwing.com/problem/content/description/1091/

//���������Ż�dp
/*
״̬��ʾ��dp[i]��ʾ������i�����̨��ǰ�����е����ķ��̨����֮��
״̬ת�ƣ�dp[i] = min{dp[i - 1], dp[i - 2], ���� , dp[i - m]} + a[i];

�������ж�ͷ�洢��ǰ��Χ��dp����Сֵ
*/

#include <iostream>
  
using namespace std;

const int N = 200010;

int n, m, a[N];
int q[N], t, h;
int f[N];

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        if (t >= h && i - m > q[h]) h++;
        
        f[i] = f[q[h]] + a[i];
        
        while (h <= t && f[q[t]] >= f[i]) t--;
        
        q[++t] = i;
    }
    
    int ans = 0x3f3f3f3f;
    //����� m �����̨��ѡ����ۺ���С���Ǹ����´�
    for (int i = n - m + 1; i <= n; i++) ans = min(ans, f[i]);
    
    cout << ans << endl;
    
    return 0;
}