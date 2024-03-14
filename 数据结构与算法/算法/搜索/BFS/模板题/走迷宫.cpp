//https://www.acwing.com/problem/content/846/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

int n, m;
//a�洢��ͼ��d�洢��ǰλ�õ����(1, 1)�ľ���
int a[N][N], d[N][N];
//ƫ����
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

queue<pair<int, int>> k;

int bfs ()
{
    //��ʼ������
    memset(d, -1, sizeof(d));
    d[1][1] = 0;
    
    k.push({1, 1});
    
    while (k.size())
    {
        auto t = k.front();
        k.pop();
        
        //��ÿ��λ�ã�������ȫ���п��е���һ��λ�ã�Ҳ����˵��ÿһ������п���λ�ö���һ����õ�
        for ( int i = 0; i < 4; i++ )
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            
            //����d[x][y]�������ǹؼ�������ֹ���漸��ľ��븲�ǵ�ԭ�Ƚ϶̵ľ��룬��֤�����������̾���
            if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                k.push({x, y});
            }
        }
    }
    
    return d[n][m];
}

int main ()
{
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ ) cin >> a[i][j];
    
    cout << bfs();
    
    return 0;
}