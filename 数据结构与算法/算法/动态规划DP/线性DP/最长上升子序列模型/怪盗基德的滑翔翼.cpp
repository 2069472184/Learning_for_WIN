//https://www.acwing.com/problem/content/1019/

//ΪʲôҪ����������������У�
//����ÿһ�����ӣ��ֵ����¶���������������ѡ��ʽ��
//����Ҫ����ÿһ�������������˵�����������У���������Щ���ȡһ��max

#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;

int k, n, a[N], f[N], res;

int main ()
{
    cin >> k;
    
    while (k--)
    {
        memset(f, 0, sizeof(f));
        res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        for (int i = 1; i <= n; i++)
        {
            f[i] = 1;
            for (int j = 1; j < i; j++)
                if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
                
            res = max(f[i], res);
        }
    
        for (int i = n; i; i--)
        {
            f[i] = 1;
            for (int j = n; j > i; j--)
                if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
                
            res = max(res, f[i]);
        }
        
        cout << res << endl;
    }
    
    return 0;   
}