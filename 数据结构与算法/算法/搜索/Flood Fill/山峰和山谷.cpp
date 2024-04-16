// https://www.acwing.com/problem/content/1108/

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1005;

int n, g[N][N], up, down;
int dx[] = {0, -1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
bool st[N][N];

void bfs (int x, int y, bool &is_up, bool &is_down)
{
    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;
    
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        int a = p.first, b = p.second;
        
        for (int k = 1; k <= 8; k++)
        {
            int nx = a + dx[k], ny = b + dy[k];
            
            if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
            //if (st[nx][ny]) continue;  �����жϲ���д������������ܶ�߽��жϣ�����ĳ�������Ҹ���ɽ���ɽ�ȣ�������ɽ���ɽ�ȱ�����õ�Ͳ��ᱻ�����ˣ�
            
            if (g[a][b] != g[nx][ny])   // ���ж��Ƿ�Ϊ�߽磬�߽���㱻������ҲҪ����
            { 
                if (g[a][b] > g[nx][ny]) is_up = true;  // ���������ɽ�壬����֮�����б߽��ж϶���ɽ�壬��ôis_down��Ϊfalse�����������ͨ���ʲô������
                else is_down = true;
            }
            else if (!st[nx][ny])
            {
                st[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!st[i][j])
            {
                bool is_up = false, is_down = false;
                bfs(i, j, is_up, is_down);
                
                if (is_up && !is_down) up ++;
                if (is_down && !is_up) down ++;
                if (!is_up && !is_down) up++, down++;
            }
            
    cout << up << ' ' << down << endl;
    
    return 0;
}