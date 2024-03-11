// https://www.acwing.com/problem/content/1077/

// ��һ��ֻ��һ��������Ҫ��ÿ�����ĸ��ڵ������

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 50005;

int n, h[N], e[2 * N], ne[2 * N], idx, ans;
bool st[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int get_prime (int n)
{
    int sum = 0;
    vector<int> a;
    int len = sqrt(n);
    for (int i = 1; i <= len; i++)
    {
        if (n % i == 0 && i * i == n) a.push_back(i);
        else if (n % i == 0)
        {
            a.push_back(i);
            a.push_back(n / i);
        }
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < a.size(); i++) 
        if (a[i] != n) sum += a[i];

    return sum;
}

int dfs (int u)
{
    int d1 = 0, d2 = 0;
    
    for (int i = h[u]; ~i; i = ne[i])
    {
        int son = e[i];
        
        int d = dfs(son) + 1;
    
        if (d >= d1) d2 = d1, d1 = d;
        else if (d >= d2) d2 = d;
    }
    
    ans = max(ans, d2 + d1);
    
    return d1;
}

int main ()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    for (int i = 2; i <= n; i++)  // i��2ö�٣���Ϊ1��sumΪ0�������в�����0�ŵ�
    {
        int sum = get_prime(i);
        
        if (sum < i && !st[i])
        {
            st[i] = true;  // ���st[i]Ϊtrue�����ʾi���Ǹ��ڵ�
            add(sum, i);  
            // ÿ��Լ��֮�Ͷ�Ӧ��i��һ��Ψһ����˲��ܽ��ߴ�sum����i������ᵼ��һ���ӽ���ж�����ڵ�
        } 
    }
    
    for (int i = 1; i <= n; i++)   // ����������������
        if (!st[i]) dfs(i); 
    
    cout << ans << endl;
    
    return 0;
}