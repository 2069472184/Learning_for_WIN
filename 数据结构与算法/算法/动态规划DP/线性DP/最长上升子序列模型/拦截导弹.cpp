//https://www.acwing.com/problem/content/1012/

//̰��˼·�������������ٵĵ���
//���ڷ��������е������߶ȵ͵ĵ������ڸ߶Ƚϸߵĵ������棬
//����޷��ӣ���ô���¿�һ���½�������

#include <iostream>
#include <sstream>

using namespace std;

const int N = 1010;

int a[N], f[N], g[N], ans, cnt, n = 1;
//g����洢ÿһ�����е�ĩβֵ

int main ()
{
    while (cin >> a[n]) n++;
    
    for (int i = n - 1; i; i--)
    {
        f[i] = 1;
        
        for (int j = n - 1; j > i; j--)
            if (a[i] >= a[j]) f[i] = max(f[i], f[j] + 1);
            
        ans = max(f[i], ans);
    }

    //̰��    
    for (int i = 1; i < n; i++)
    {
        int k = 0;
        while (k < cnt && g[k] < a[i]) k++;
        g[k] = a[i];
        if (k == cnt) cnt++;
    }
    
    cout << ans << endl << cnt << endl;
    
    return 0;
}