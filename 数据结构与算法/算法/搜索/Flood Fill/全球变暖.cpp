//https://www.acwing.com/problem/content/1235/

//flood fill�㷨

/*
1.������ж��ٸ���ͬ����ͨ��
  ѭ���������󣬶�������û�б������Ϊ½�صĵ����bfs��dfs������
  �ҵ���õ����ڵ�����½�أ������ϱ��
2.ͳ���ж��ٸ���ͨ��ᱻ��û
  һ���ж��ٸ���Ԫ��һ���ж��ٸ����뺣���ڣ�������ֵ��ͬ������ᱻ��û
*/

#include <iostream>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n, cnt;
//g����洢��ͼ
char g[N][N];
//st����
bool st[N][N];
//q�洢����
PII q[N * N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void bfs (int a, int b, int &total, int &bound)
{
    int hh = 0, tt = 0;
    q[0] = {a, b};
    st[a][b] = true;
    
    while (hh <= tt)
    {
        //ÿ�γ���һ��Ԫ�أ���ʾ��һ����ͨ�ĵ�
        PII t = q[hh++];
        total++;
        
        bool if_bound = false;
        //������ǰ������ܸ���
        for (int i = 0; i < 4; i++)
        {
            int m = t.x + dx[i], p = t.y + dy[i];
            
            if (m < 0 || m >= n || p < 0 || p >= n) continue;
            
            if (st[m][p]) continue;
            
            if (g[m][p] == '.') 
            {
                if_bound = true;
                continue;
            }
            
            //��������ж϶������㣬��ô˵���õ㵱ǰ�����ϵĵ��Ǹ�δ��������½��
            q[++tt] = {m, p};
            st[m][p] = true;
        }
        
        //��ǰ�����ܴ��ں���˵���õ�Ϊ�߽��
        if (if_bound) bound++;
    }
}

int main ()
{
    cin >> n;
    
    for (int i = 0; i < n; i++) scanf("%s", g[i]);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!st[i][j] && g[i][j] == '#')
            {
                int total = 0, bound = 0;
                bfs(i, j, total, bound);
                //ע�⣬��������������������½��Ҳ��һ������
                //if (total == 1) continue;
                if (total == bound) cnt++;
            }
    
    cout << cnt << endl;
    
    return 0;
}