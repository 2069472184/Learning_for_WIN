#include <iostream>
#include <cmath>

using namespace std;
const int N = 1000010;

int cnt, primes[N];
bool st[N];

void get_prime (int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) primes[cnt++] = i;
	    //ȷ��primes[j]��i��˲��ᱬn
        for (int j = 0; primes[j] <= n / i; j++) 
        {
	        //����st����ΪʲôҪ��ǰ�棬��ʵ�����ǻ�����һ��
	        //���жϣ��� if (i % primes[j] == 0) break; 
	        //��仰��ֻ֤Ҫ���µ�ѭ�� primes[j] �ͻ��� 
	        //primes[j] * i ����С������
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }  
    }
}

int main ()
{
    int n;
    cin >> n;
    
    get_prime(n);
    
    cout << cnt;
    
    return 0;
}