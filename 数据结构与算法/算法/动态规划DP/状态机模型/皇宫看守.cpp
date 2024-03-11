// https://www.acwing.com/problem/content/1079/

// �����������ڵ�
/*
ע��״̬���֣����ز�©
f[i][3]:
j=0�����ڵ㲻�����������ұ����ڵ㿴����
j=1�����ڵ㲻�����������ұ��ӽڵ㿴����
j=2�����ڵ����������

�롰ս����Ϸ���ı����������ڴ��������ڵ㣬��ս����Ϸ�������ڱߡ�

��ս����Ϸ���У����ڵ���ÿ���ӽڵ�֮��ı�ֻ��ͨ�������˵�ʵ�֡�����������Ŀ�꣬����ڵ�ĸ��ڵ��޹ء�
ֻҪ���ڵ�����������������ֽڵ㶼�ɷſɲ���������������ڵ㲻�����������������ӽڵ㶼��Ҫ��ֹ������״̬ת�ƹ�����ͳһ�ġ�

�ڱ����У������ǹ涨ÿ���ڵ㶼�����������ڵ�ȿ���ͨ���丸�ڵ㿴��Ҳ����ͨ�����ӽڵ㿴�������롰ս����Ϸ����ȫ��ͬ����ȻҲ��������״̬��ʾ���Ѷ�
�����ڵ��������ʱ�����ӽڵ��״̬����Ҫ�������Գ��֡�
    f[u][2] += min(f[son][0], min(f[son][1], f[son][2]));
�����ڵ㲻�����������ұ��ӽڵ㿴��ʱ��ֻ��Ҫ��ĳһ���ӽڵ�������������������⣬����ӽڵ�������ĸ���Ҫ���ۣ������ӽڵ���˲��ܱ����������ڵ㿴���⣬����״̬�����ܳ��֡�
    f[u][1] = min(f[u][1], f[son][2] + sum(min(f[other_son][1], f[other_son][2])));
�����ڵ㲻�����������ұ����ڵ㿴��ʱ�����ڵ���ӽڵ���˲��ܱ����ڵ㿴���⣬����״̬�����ܳ��֡�
    f[u][0] += min(f[son][1], f[son][2]);
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1505;

int n, h[N], e[N], w[N], ne[N], idx, root;
int f[N][3];
bool has_father[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs (int u)
{
    f[u][2] = w[u];
    
    int sum = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int son = e[i];
        dfs(son);
        
        f[u][0] += min(f[son][2], f[son][1]);
        f[u][2] += min(min(f[son][0], f[son][1]), f[son][2]);
        sum += min(f[son][1], f[son][2]);
    }
    
    f[u][1] = 0x3f3f3f3f;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int son = e[i];
        f[u][1] = min(f[u][1], sum - min(f[son][2], f[son][1]) + f[son][2]);
    }
}

int main ()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, num;
        cin >> a >> c >> num;
        w[a] = c;
        
        for (int j = 1; j <= num; j++)
        {
            cin >> b;
            has_father[b] = true;
            add(a, b);
        }
    }
    
    for (int i = 1; i <= n; i++) 
        if (!has_father[i]) root = i;
    
    dfs(root);
    
    cout << min(f[root][1], f[root][2]) << endl;
    
    return 0;
}