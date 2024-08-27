//https://www.acwing.com/problem/content/856/

#include <iostream>

using namespace std;
const int N = 205, M = 20010;

int n, m, k;

//��ҪҪ�㶮g[i][j]�ĺ��壬����ֵ��ʾ��i��j�����·
//g[i][j]Ҳ���Է�Ϊi��j·�����κ�һ���㵽���˵ľ���
//��g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
int g[N][N];

void floyd ()
{
    //���g��������������ʾ��g[k, i, j]��k ��ʾ i ����
    // 1~k �ڵ�ĳЩ�㵽�� j ����Ҫ�����·
    //�� d[k, i, j] = d[k-1, i, k] + d[k-1, k, j]
    //��ǰѭ�������õ���һ�ε�����
    //���Դ˴���kѭ��һ��Ҫд�����棬��Ȼ�޷�ʡ�Ե�kά
    for ( int k = 1; k <= n; k++ )
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= n; j++ )
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main ()
{
    cin >> n >> m >> k;
    
    //ע�⣬ͼ�д����Ի������Ի�����Ϊ�����ں����е��ã�
    //���Ա��뵥����ʼ���Ի�Ϊ0
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) g[i][j] = 0;
            else g[i][j] = 0x3f3f3f3f;
            
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        //��Ȼ��ʡ�Ե��ϳ���
        g[x][y] = min(g[x][y], z);
    }
    
    floyd();
    
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        
        if (g[x][y] > N*M) puts("impossible");
        else cout << g[x][y] << endl;
    }
    
    return 0;
}