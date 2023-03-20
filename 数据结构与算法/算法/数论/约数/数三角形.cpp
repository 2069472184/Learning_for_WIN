//https://www.acwing.com/problem/content/description/1312/

//��Ϊ i , ��Ϊ j ��������б���ϳ��˵�ĵ�����ǣ�gcd(i, j) - 1;
/*
֤����https://www.acwing.com/solution/content/22893/
*/

#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1010;

int m, n;

int gcd (int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main ()
{
    cin >> m >> n;    
    
    m++, n++;
    //�����������ѡ��
    ll all = (ll)n * m * (n * m - 1) * (n * m - 2) / 6;
    //������ͬ�ں�����
    ll r = (ll)n * m * (m - 1) * (m - 2) / 6;
    //������ͬ��������
    ll l = (ll)m * n * (n - 1) * (n - 2) / 6;
    
    m--, n--;
    ll x = 0;
    // i �� j ��ʾö�ٵ�ֱ�������ε�����ֱ�Ǳߣ��ҽ�ֱ�Ƕ��㿴��ԭ��
    //�����Ϳ���ֱ���� gcd(i, j) ��
    //����ÿһ��ֱ�������Σ�ֱ�Ƕ����ѡȡ��ʽ�� (n - i + 1) * (m - j + 1) �� 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            ll t = gcd(i, j) - 1;
            x += (ll)t * (n - i + 1) * (m - j + 1);
        }
        
    //��Ϊ����б�����֮ö����б��Ϊ�����������б��Ϊ���������б��Ϊ������� x ��ͬ
    cout << all - l - r - 2 * x << endl;
    
    return 0;
}