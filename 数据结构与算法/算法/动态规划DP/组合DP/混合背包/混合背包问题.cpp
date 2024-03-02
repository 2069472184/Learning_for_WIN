// https://www.acwing.com/problem/content/7/

// ���ؽⷨ����ʱ
#include <iostream>

using namespace std;

const int N = 1005, M = 1005;

int n, V, v, w, s;
int f[N][M];

int main ()
{
    cin >> n >> V;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w >> s;
        for (int j = 1; j <= V; j++)
        {
            f[i][j] = f[i - 1][j];
            
            if (s == 0) 
                for (int k = 1; k * v <= j; k++)
                    f[i][j] = max(f[i][j], f[i - 1][j - k * v] + k * w);
            else if (s)
                for (int k = 1; k * v <= j && k <= s; k++)
                    f[i][j] = max(f[i][j], f[i - 1][j - k * v] + k * w);
        }
    }
    
    cout << f[n][V] << endl;
    
    return 0;
}

// ���ر����������Ż�
// f�����һά����˼·����ر����С�������ά����Ķ������Ż���һ��
#include <iostream>

using namespace std;

const int N = 1005, M = 10005;

int n, V, v, w, s, c = 1;
int f[M][N], vv[N], ww[N];

int main ()
{
    cin >> n >> V;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w >> s;
        
        if (s == 0)  // ��ȫ����
        {
            for (int j = 1; j <= V; j++) 
            {
                f[c][j] = f[c - 1][j];
                
                if (j >= v) f[c][j] = max(f[c][j], f[c][j - v] + w);
            }
            c++;
        }
                
        if (s == -1) // 0-1����
        {
            for (int j = 1; j <= V; j++)
            {
                f[c][j] = f[c - 1][j];
                
                if (j >= v) f[c][j] = max(f[c][j], f[i - 1][j - v] + w);
            }
            c++;
        }
                
        if (s > 0)   // ���ر���
        {
            int k = 1, idx = 0;
            
            while (k <= s)
            {
                idx++;
                vv[idx] = k * v;
                ww[idx] = k * w;
                s -= k;
                k *= 2;
            }
            
            if (s)
            {
                idx++;
                vv[idx] = s * v;
                ww[idx] = s * w;
            }

            for (int p = 1; p <= idx; p++)
            {
                for (int j = 1; j <= V; j++)
                {
                    f[c][j] = f[c - 1][j];
                    
                    if (j >= vv[p]) f[c][j] = max(f[c][j], f[c - 1][j - vv[p]] + ww[p]);
                }
                c++;
            }
        }
    }
    
    cout << f[c - 1][V] << endl;
    
    return 0;
}

// ���ر������д����ʡȥvv��ww���飬���Ż�һά
#include <iostream>

using namespace std;

const int N = 1005;

int n, V, v, w, s;
int f[N], vv[N], ww[N];

int main ()
{
    cin >> n >> V;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w >> s;
        
        if (s == 0)  // ��ȫ����
            for (int j = v; j <= V; j++) 
                f[j] = max(f[j], f[j - v] + w);
                
        if (s == -1) // 0-1����
            for (int j = V; j >= v; j--)
                f[j] = max(f[j], f[j - v] + w);
                
        if (s > 0)   // ���ر���
        {
            int k = 1, idx = 0;

            for (int k = 1; k <= s; k *= 2)
            {
                for (int j = V; j >= v * k; j--)
                    f[j] = max(f[j], f[j - v * k] + w * k);
                s -= k;    
            }
            
            if (s)
                for (int j = V; j >= v * s; j--)
                    f[j] = max(f[j], f[j - v * s] + w * s);
        }
    }
    
    cout << f[V] << endl;
    
    return 0;
}

// ��Ȼ��0-1��������Ҳ���Կ�������Ķ��ر������⣬��ˣ�
#include <iostream>

using namespace std;

const int N = 1005;

int n, V, v, w, s;
int f[N], vv[N], ww[N];

int main ()
{
    cin >> n >> V;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w >> s;
        
        if (s == 0)  // ��ȫ����
            for (int j = v; j <= V; j++) 
                f[j] = max(f[j], f[j - v] + w);
                
        if (s == -1) // 0-1����
            s = 1;   // ������Ʒ��Ϊ1�����
                
        if (s > 0)   // ���ر���
        {
            int k = 1, idx = 0;

            for (int k = 1; k <= s; k *= 2)
            {
                for (int j = V; j >= v * k; j--)
                    f[j] = max(f[j], f[j - v * k] + w * k);
                s -= k;    
            }
            
            if (s)
                for (int j = V; j >= v * s; j--)
                    f[j] = max(f[j], f[j - v * s] + w * s);
        }
    }
    
    cout << f[V] << endl;
    
    return 0;
}