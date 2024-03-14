// https://www.acwing.com/problem/content/169/

// ����д�����ų���Ч���ࣺ���������������
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 70;

int n, l[N], len;
vector<int> primes;
int e[N], num;

void get_primes (int a)
{
    int len = sqrt(a);
    for (int i = 1; i <= len; i++)
    {
        if (a % i == 0 && i * i == a) primes.push_back(i);
        else if (a % i == 0) 
        {
            primes.push_back(i);
            primes.push_back(a / i);
        }
    }
    
    sort(primes.begin(), primes.end());
}

bool dfs (int u)
{
    if (u == n + 1) 
    {
        for (int k = 1; k <= num; k++)
            if (e[k] != len) return false;
        
        return true;
    }
    
    // ����
    for (int k = 1; k <= num; k++)
        if (e[k] + l[u] <= len) 
        {
            e[k] += l[u];
            if (dfs(u + 1)) return true;
            e[k] -= l[u];
        }
    
    // �¿�
    e[++num] = l[u];
    if (dfs(u + 1)) return true;
    e[num--] = 0;
    
    return false;
}

int main ()
{
    while (cin >> n, n)
    {
        int sum = 0, maxl = 0;
        
        for (int i = 1; i <= n; i++) 
        {
            cin >> l[i];
            maxl = max(maxl, l[i]);
            sum += l[i];
        }
        
        // �õ����п��ܵĳ��ȣ���Щ�������㣺1.������Ķ�ľ����2.�����ж�ľ�����Ⱥ͵�Լ����
        get_primes(sum);
        
        int idx = 0;
        while (primes[idx] <= maxl) idx++;
        
        for (int i = idx; i < primes.size(); i++)
        {
            len = primes[i];
            
            memset(e, 0, sizeof e);
            num = 0;
            
            if (dfs(1)) 
            {
                cout << len << endl;
                break;
            }
        }
    }
    
    return 0;
} 

// �Ż�
/*
�Ż�����˳�򣺴Ӵ�С��������֦
�ų���Ч����2�������ǰľ��a�ӵ���ǰ����֮����ʧ���ˣ���ֱ����������������ľ��a������ȵ�ľ����
�ų���Ч����3�����ľ��a�ӵ�ĳһľ���Ŀ�ͷ֮����ʧ���ˣ�������ľ�����ȵ�ö�ٱض�ʧ�ܡ�
�ų���Ч����4�����ľ��a�ӵ�ĳһľ����ĩβ֮����ʧ���ˣ�������ľ�����ȵ�ö�ٱض�ʧ�ܡ�

����֤�����̣�
https://www.acwing.com/solution/content/36030/
Ҫץסľ��֮��ĵ�Ч�ԣ���������滻
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 70;

int n, l[N], len, sum, maxl;
vector<int> primes;
int e[N], num;
bool st[N];

void get_primes (int a)
{
    int len = sqrt(a);
    for (int i = 1; i <= len; i++)
    {
        if (a % i == 0 && i * i == a) primes.push_back(i);
        else if (a % i == 0) 
        {
            primes.push_back(i);
            primes.push_back(a / i);
        }
    }
    
    sort(primes.begin(), primes.end());
}

bool dfs (int u, int e, int start)  // u����ǰ���쵽��ľ������e����ǰľ���ѹ���ĳ��ȣ�start����ǰö�ٵ���ľ�����
{
    if (u * len == sum) return true;
    if (e == len) return dfs(u + 1, 0, 0);
    
    for (int i = start; i <= n; i++)
    {
        if (st[i]) continue;
        if (e + l[i] > len) continue;
        
        st[i] = true;
        if (dfs(u, e + l[i], i + 1)) return true;
        st[i] = false;
        
        // �ų���Ч����3��4
        if (!e || e + l[i] == len) return false;
        
        // �ų���Ч����2
        int j = i;
        while (j <= n && l[j] == l[i]) j++;
        i = j - 1;
    }
    
    return false;
}

int main ()
{
    while (cin >> n, n)
    {
        sum = 0, maxl = 0;
        
        for (int i = 1; i <= n; i++) 
        {
            cin >> l[i];
            maxl = max(maxl, l[i]);
            sum += l[i];
        }
        
        sort(l + 1, l + 1 + n);
        reverse(l + 1, l + 1 + n);
        
        primes.clear();
        get_primes(sum);
        
        int idx = 0;
        while (primes[idx] < maxl) idx++;
        
        for (int i = idx; i < primes.size(); i++)
        {
            len = primes[i];
            
            memset(st, 0, sizeof st);
            
            if (dfs(0, 0, 1)) 
            {
                cout << len << endl;
                break;
            }
        }
    }
    
    return 0;
} 
