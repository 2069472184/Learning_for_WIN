// https://www.acwing.com/problem/content/1114/

// ����д����2/10
#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;

int t, n, ax, ay, bx, by;
char g[N][N];
int dx[] = {0, 1, 0, -1, 0}, dy[] = {0, 0, 1, 0, -1};
bool flag, st[N][N];

void dfs (int x, int y)
{
    if (flag) return;
    
    if (x == bx && y == by && !flag) 
    {
        cout << "YES" << endl;
        flag = true;
        return;
    }
    
    for (int k = 1; k <= 4; k++)
    {
        int xn = x + dx[k], yn = y + dy[k];
        
        if (xn >= 1 && xn <= n && yn >= 1 && yn <= n && g[xn][yn] == '.' && !st[xn][yn])
        {
            st[xn][yn] = true;
            dfs(xn, yn);
            st[xn][yn] = false;
        }
    }
}

int main ()
{
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        
        flag = false;
        memset(st, 0, sizeof st);
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> g[i][j];
        
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ax = a + 1, ay = b + 1, bx = c + 1, by = d + 1;
        
        if (g[ax][ay] == '#' || g[bx][by] == '#') cout << "NO" << endl;
        else if (ax == bx && ay == by) cout << "YES" << endl;
        else 
        {
            dfs(ax, ay);
            
            if (!flag) cout << "NO" << endl;
        }
    }
    
    return 0;
}

// �Ż������ڱ����Ҫ��ó�������ܷ��ߵ��յ㣬��·������û��Ҫ��
// �������ֻ��Ҫ�����һ������������·�����ɣ�֮������Ѳ���������ʡ�ԣ���ͼ��ÿ����ֻ�ᱻ����һ�Ρ�
// ����ͨ��Ĵ�С������Ҫ����
#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;

int t, n, ax, ay, bx, by;
char g[N][N];
int dx[] = {0, 1, 0, -1, 0}, dy[] = {0, 0, 1, 0, -1};
bool st[N][N];

bool dfs (int x, int y)
{
    if (x == bx && y == by) return true;
    
    for (int k = 1; k <= 4; k++)
    {
        int xn = x + dx[k], yn = y + dy[k];
        
        if (xn <= 0 || xn > n || yn <= 0 || yn > n || st[xn][yn] || g[xn][yn] == '#') continue;
        
        st[xn][yn] = true;    // һ���õ�������������ȷ���������߸õ㣬����ÿ����ֻ�ᱻ����һ�Σ��������ָ��ֳ���
        if (dfs(xn, yn)) return true;   // ֻҪ��ǰ·������ͨ��ֱ��һ·���ݡ�
    }
    
    return false;
}

int main ()
{
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        
        memset(st, 0, sizeof st);
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> g[i][j];
        
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ax = a + 1, ay = b + 1, bx = c + 1, by = d + 1;
        
        if (g[ax][ay] == '#' || g[bx][by] == '#') cout << "NO" << endl;
        else if (ax == bx && ay == by) cout << "YES" << endl;
        else if (dfs(ax, ay)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}