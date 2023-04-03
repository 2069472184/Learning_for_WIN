//https://www.acwing.com/problem/content/4407/

//����x����������nλ���ֵ�Ȩ����x^(n-1)
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 100010, Mod = 1000000007;

int maxj, la, lb;
ll a[N], b[N], w[N], mul[N];
//w����洢ÿ����λ�����Ϸ�����
ll ansa, ansb;

int main ()
{
    cin >> maxj;
    cin >> la;
    for (int i = la; i; i--) cin >> a[i];
    cin >> lb;
    for (int i = lb; i; i--) cin >> b[i];
    
    //������ͬ��λ�����Ϸ�����
    int len = max(la, lb);
    for (int i = 1; i <= len; i++)
    {
        int tem = max(a[i], b[i]);
        w[i] = max(tem + 1, 2);
        //if (w[i] > maxj) w[i] = maxj;
    }
    
    //����x������ÿλ����Ȩ��
    mul[0] = 1;
    for (int i = 1; i <= len; i++)
        mul[i] = mul[i - 1] * w[i] % Mod;
    
    //����a��x�����µ�ʮ���Ʊ�ʾ
    for (int i = 1; i <= len; i++)
        ansa = (ansa + a[i] * mul[i - 1]) % Mod;
        
    //����b��x�����µ�ʮ���Ʊ�ʾ
    for (int i = 1; i <= len; i++)
        ansb = (ansb + b[i] * mul[i - 1]) % Mod;
        
    cout << (ansa - ansb + Mod) % Mod << endl;
     
    return 0;
}