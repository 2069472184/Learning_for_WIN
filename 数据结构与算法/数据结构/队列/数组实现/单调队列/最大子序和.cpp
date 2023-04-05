//https://www.acwing.com/problem/content/137/

#include <iostream>

using namespace std;

const int N = 300010;

int n, m, a[N], ans = -0x3f3f3f3f;
int q[N], h, t = -1;

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    
    q[++t] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        //��Ϊ�����Ǵ洢��ǰ׺�ͣ�����ǰ׺�͵ļ��㹫ʽ��������Ҫ�洢�� i - m ��ǰһ���±�
        if (h <= t && i - m > q[h]) h++;
        //����ÿһ������Ե����У���Ҫ����ǰ׺�Ͳ�
        ans = max(ans, a[i] - a[q[h]]);
        //��֤�����������Զ��С������ a[i] - a[q[h]] ����ʱȡ��������ֵ
        //��Ϊ��ǰ������˵������������������ǰ׺�͵���Сֵ���������迼�ǳ���С�� i - q[h] ������ 
        while (h <= t && a[q[t]] >= a[i]) t--;
        
        q[++t] = i;
    }
    
    cout << ans << endl;
    
    return 0;
}