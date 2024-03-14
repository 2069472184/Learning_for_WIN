// https://www.acwing.com/problem/content/168/

//�����ⷨ
#include <iostream>

using namespace std;

const int N = 10;

string str;
int g[N][N];

bool check (int a, int x, int y)
{
    for (int i = 1; i <= 9; i++)
        if ((g[x][i] == a && i != y) || (g[i][y] == a && i != x)) return false;
    
    for (int i = (x - 1) / 3 * 3 + 1; i <= (x - 1) / 3 * 3 + 3; i++)
        for (int j = (y - 1) / 3 * 3 + 1; j <= (y - 1) / 3 * 3 + 3; j++)
            if (g[i][j] == a && i != x && j != y) return false;
    
    return true;
}

bool dfs (int x, int y)
{
    if (x == 10)
    {
        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++) 
                cout << g[i][j];
        cout << endl;
        
        return true; 
    }

    if (g[x][y]) 
    {
        if (dfs(y == 9 ? x + 1 : x, y == 9 ? 1 : y + 1)) return true;
    }
    else
    {
        for (int a = 1; a <= 9; a++)
            if (check(a, x, y))
            {   
                g[x][y] = a;
                if (dfs(y == 9 ? x + 1 : x, y == 9 ? 1 : y + 1)) return true;
                else g[x][y] = 0;
            }
    }
    
    return false;
}

int main ()
{
    while (cin >> str, str != "end")
    {
        int idx = 0;
        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++)
            {
                g[i][j] = str[idx] == '.' ? 0 : int(str[idx] - '0');
                idx++;
            }
             
        dfs(1, 1);
    }
    
    return 0;
}

// �Ż�
/*
�Ż�����˳������ѡ���ȡ��ֵ�ٵĸ�������
λ�����Ż���
1. ʹ��9λ01����ʾһ�У�һ�к�һ���Ź����п�ȡ����ֵ������Ҫ���һ�����ӺϷ�������ȡֵʱ��
ֻҪ������01�����������ɣ����յõ���01����1�ı���������Ǹø����ϵ����кϷ�ȡֵ��
2. �ڵõ�ĳ�������ϵĺϷ�ȡֵ01���󣬿���ʹlowbit�㷨������������9����Ϊ�Ϸ�ȡֵ����Ŀ����ֻ�������еĺϷ�ȡֵ��
*/

// ע�⣺���ڱ���ʹ��λ���㣬���Ը����±��(0, 0)��ʼ
/* 01����010010110��1��ʾ��ȡ��0��ʾ����ȡ
   ��ֵ��123456789����ȡ��ֵΪ2��3��5��8  */

#include <iostream>
#include <algorithm>

using namespace std;

// ------------------------------------------------------ //

const int N = 9, M = 1 << N;

// ones[i]��i�Ķ����Ʊ�ʾ��01�������ж��ٸ�1
// map[i]�����󾭹�lowbit�����Ķ����ƽ����1��λ�ã��������Ҵ�0��ʼ��������map[000001000] = 3
int ones[M], map[M];

// rows[i]��ʾ��i���е�ǰ��ȡ����ֵ������
// cols[i]��ʾ��i���е�ǰ��ȡ����ֵ������
// cell[i]��ʾ��(i, j)Ϊ���ϽǵĹ��е�ǰ��ȡ����ֵ������
int rows[N], cols[N], cell[3][3];

// s����洢����ԭʼ����
string s;

// ------------------------------------------------------ //

int lowbit (int a)
{
    return a & (-a);  
    // lowbit(x)����һ��01�����ô���ֻ��һ��λ��Ϊ1����x�����λ1��λ��
    // ����lowbit(010100100) = 000000100
}

void init ()
{
    // ��ʼ����ÿ��ÿ��ÿ���Ź���������������ѡ
    for (int i = 0; i < N; i++) rows[i] = cols[i] = (1 << N) - 1;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cell[i][j] = (1 << N) - 1;
}

void update (int x, int y, int a, int mode) // modeΪ1��ʾ���룬modeΪ0��ʾɾ��
{
    int v = 1 << a;  // ��ô�������ֵa + 1��Ӧ�Ķ�������λ������������ֵΪ5����a = 4, v = 000010000
    
    if (mode)  // ����
    {
        rows[x] -= v;
        cols[y] -= v;
        cell[x / 3][y / 3] -= v;
        s[x * N + y] = '1' + a;
    }
    else  // ɾ��
    {
        rows[x] += v;
        cols[y] += v;
        cell[x / 3][y / 3] += v; 
        s[x * N + y] = '.';
    }
}

int get (int x, int y)
{
    return rows[x] & cols[y] & cell[x / 3][y / 3];   
}

bool dfs (int cnt)
{
    if (!cnt) return true; // û�пո���ʱ���õ����մ𰸡�
    
    // �����������ǰ���пո���������ֵ�������ٵ��Ǹ�����(x, y)�����Ż�����˳��
    int x, y;
    int minv = 10; // ����Ѱ����Сonesֵ�������ٵĿ�ѡ��ֵ����
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (s[i * N + j] == '.')
            {
                int state = get(i, j);
                if (ones[state] < minv)
                {
                    minv = ones[state];
                    x = i, y = j;
                }
            }

    int state = get(x, y); // �������(x, y)�Ŀ�ȡֵ���
    for (int k = state; k; k -= lowbit(k))  // ���α���(x, y)��ÿһ����ȡ��ֵ
    {
        int tem = map[lowbit(k)]; // �õ�������ֵ��-1ֵ

        update(x, y, tem, 1);
        if (dfs(cnt - 1)) return true;
        update(x, y, tem, 0);  // �ָ��ֳ�
    }
    
    return false;
}

// ------------------------------------------------------ //

int main ()
{
    // ��ʼ��map����
    for (int i = 0; i < N; i++) map[1 << i] = i; 
    
    // ��ʼ��ones����
    for (int i = 0; i < M; i++)  // �� 000000000(2) ö�ٵ� 111111111(2)����Ӧ���е�ȡֵ���
        for (int j = i; j; j -= lowbit(j))  // ɾȥj�����λ��1
            ones[i] += 1;    // ��ÿһ��ȡֵ�����Ӧ��01����1����������ones��
    
    // ��ʼ��������
    while (cin >> s, s != "end")
    {
        init();  // ��ʼ��rows��cols��cell
        
        int cnt = 0; // ��¼��������ֵ�ĸ�������
        
        // ������ʼ�������ݣ����Ѹ�������ֵ�����rows��cols��cell��
        for (int i = 0, k = 0; i < N; i++)
            for (int j = 0; j < N; j++, k++)
                if (s[k] != '.')
                {
                    int tem = s[k] - '1';
                    update(i, j, tem, 1);
                }
                else cnt++;
         
        // ��ʼ����ɺ󣬿�ʼdfs
        dfs(cnt);
        
        cout << s << endl;
    }
    
    return 0;
}