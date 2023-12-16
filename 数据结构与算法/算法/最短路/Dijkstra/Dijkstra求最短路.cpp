//https://www.acwing.com/problem/content/851/

//��������·�����bfs�����·�и���֮ͬ���������ȱ����ĵ���̾���϶���С
#include <iostream>
#include <cstring>

using namespace std;
const int N = 510;

int n, m;
//gΪ�ڽӾ���dist�洢ÿ���ڵ㵽1�ľ���
int g[N][N], dist[N];
//�������飬��֤ÿ����֮����һ��
bool st[N];

int dijkstra()
{
    //��ʼ������
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    //����n�Σ�ÿ�ο���ȷ��һ���㵽1�����·
    for ( int i = 0; i < n; i++ )
    {
        int t = -1;
        //�ҵ���ǰδ�������Ҿ���1��̵ĵ�
        for( int j = 1; j <= n; j++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
                
        if (t == n)  break;

        st[t] = true;

        //ͨ���ҵ��ĵ����̾���ȥ�����������ڵ�������ľ���
        for ( int j = 1; j <= n; j++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    
    //������һ����û�б��ı䣬˵�����������·
    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main ()
{
    cin >> n >> m;
    
    memset(g, 0x3f, sizeof(g));
    
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        //min������Ϊ�˱�����̵�һ���ߣ���Ϊ��Ӧ���ر�����
        g[x][y] = min(z, g[x][y]);
    }
    
    cout << dijkstra();
    
    return 0;
}

//���Ż���
//https://www.acwing.com/problem/content/851/

// #include <iostream>
// #include <cstring>
// #include <queue>

// using namespace std;
// const int N = 150010;
// typedef pair<int, int> PII;

// int n, m;
// //���ڽӱ�洢�������˴���һ��������
// int h[N], w[N], e[N], ne[N], idx;
// int dist[N];
// //�������飬��֤ÿ����֮����һ��
// bool st[N];

// void add (int a, int b, int c)
// {
//     e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
// }

// int dijkstra()
// {
//     //��ʼ������
//     memset(dist, 0x3f, sizeof(dist));
//     dist[1] = 0;
    
//     priority_queue<PII, vector<PII>, greater<PII>> heap;
//     //������Ҫ�ȴ���룬��������
//     heap.push({0, 1});
    
//     //С�����Զ��õ���ǰ����1����ĵ�
//     while (heap.size())
//     {
//         auto t = heap.top();
//         heap.pop();
                
//         int ver = t.second, distance = t.first;
//         if (st[ver]) continue;
        
//         st[ver] = true;
        
//         for ( int i = h[ver]; i != -1; i = ne[i] )
//         {
//             int j = e[i];
//             //�����б����¾���ĵ�浽С�����У��Զ�����
//             //��һ��ȡ�����ǵ�ǰ����1�����δ���������ĵ�
//             //�˴� w[i] �洢��ǰ�ڵ㵽����ͷ�ڵ�ľ���
//             if (dist[j] > distance + w[i])
//             {
//                 dist[j] = distance + w[i];
//                 heap.push({dist[j], j});
//             }
//         }
//     }
    
//     //������һ����û�б��ı䣬˵�����������·
//     if (dist[n] == 0x3f3f3f3f) return -1;
//     else return dist[n];
// }

// int main ()
// {
//     cin >> n >> m;
    
//     memset(h, -1, sizeof(h));
    
//     while (m--)
//     {
//         int x, y, z;
//         cin >> x >> y >> z;
//         //min������Ϊ�˱�����̵�һ���ߣ���Ϊ��Ӧ���ر�����
//         add(x, y, z);
//     }
    
//     cout << dijkstra();
    
//     return 0;
// }