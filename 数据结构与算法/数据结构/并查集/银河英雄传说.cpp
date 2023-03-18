//https://www.acwing.com/problem/content/description/240/

#include <iostream>
#include <cmath>

using namespace std;

const int N = 30010;

int t, i, j;
char k[2];
int p[N], d[N], s[N];

int find (int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    
    return p[x];
}

int main ()
{
    cin >> t;
    
    for (int i = 1; i <= 30000; i++)
    {
        p[i] = i;
        s[i] = 1;
    }
    
    while (t--)
    {
        scanf("%s", k);
        
        if (k[0] == 'M')
        {
            scanf("%d%d", &i, &j);
            
            int pi = find(i), pj = find(j);
            if (pi != pj) 
            {
                //��Ŀ�н�i�н���j�����һ��ս���������˼��
                //����Ҫ�����Ǹ���pj��pj�ľ��룬Ȼ���ٸ�������pj��size
                //��Ҫȥ�롰��νӵ����һ�ҡ���һ���������鼯����һ��������Ϊ���¾���
                d[pi] = s[pj];
                s[pj] += s[pi];
                p[pi] = pj;
            }
        }
        else
        {
            scanf("%d%d", &i, &j);
            
            if (find(i) == find(j)) printf("%d\n", max(0, abs(d[i] - d[j]) - 1));
            else puts("-1");
        }
    }
    
    return 0;
}