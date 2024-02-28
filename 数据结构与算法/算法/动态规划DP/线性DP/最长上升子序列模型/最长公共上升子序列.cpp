//https://www.acwing.com/problem/content/description/274/

//ע��״̬��ʾ��f[i][j] ��ʾ�ɵ�һ�����е�ǰ i ����ĸ�͵ڶ������е�ǰ j ����ĸ���� b[j] ��β������ LICS �ĳ������ֵ

//���ذ棬����ѭ��---TLE
#include <iostream>

using namespace std;

const int N = 3010;

int n, a[N], b[N];
int f[N][N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            //��ѡ a[i] �����
            f[i][j] = f[i - 1][j];
            
            //ѡ a[i] �����
            if (a[i] == b[j])
            {
                for (int k = 1; k < j; k++)
                    if (b[j] > b[k])
                        f[i][j] = max(f[i][j], f[i - 1][k] + 1);
                        //��������Ϊʲô�� f[i - 1][k]����Ϊ��ʱ a[i] �Ѿ��� b[j] ƥ�䣬
                        //���������� b[j] ǰ��һ��ƥ��� b[k] ʱ����Ȼ���ܽ� a[i] ������ȥ��������ִ���
            }
        }
        
    //�ҵ�����ĩβ���ֲ�ͬ��LICS֮�����ĳ���
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    
    cout << ans << endl;
    
    return 0;
}

//�Ż�����
/*
���Ƿ��֣��� a[i] = b[j] ʱ��b[j] > b[k] <=> a[i] > b[k]
��ʱ k ѭ������ j �޹��ˣ����ǿ��԰���һ������ᵽ j ѭ������ȥ 
��������һ����һ�����ı��ʣ����������� a[i] > b[j] ������ f[i][j] + 1 �����ֵ
����ÿһ�� j ѭ���õ��Ķ�����һ�ֵĽ��

�������ǿ�������һ������ g[i][j] ������ô����Ľ�����൱��һ����������
g[i][j] ��ʾ���� a[i] > b[j] ������ f[i][j] + 1 �����ֵ
��һ�ֵĽ������ g[i][j - 1]

����������θ��� g[i][j]:
1.g[i][j] ���� g[i][j - 1] ���ݶ���
2.���ҵ����� g[i][j] ��������
  �������ذ�Ľⷨ��a[i] = b[j] ʱ�������� g[i][j] ��� f[i][j] 
  �� a[i] != b[j] ʱ�������������a[i] > b[j] �� a[i] < b[j]
  ��������������������ذ�����У���Ȼ��ǰѭ�� b[j] ���ᱻ�õ������ǵ�ǰ�� b[j] һ�����Ϊ���� k ѭ���е�ĳ�� b[k]������δ����ĳ�� a[i] ƥ�䡣
  (��Ϊ״̬��ʾ�涨ÿһ�� f[i][j] ������ b[j] ��ֵ��β)
  ���Ե����Ǹ��� g[i][j] ʱ��һ��ʱ��Ϊ��ǰ�Ż������е� b[j](����A) ��������δ��ĳʱ�����ذ���� k ѭ���е� b[j](�µ�) > b[k](Ҳ����A)��
  ��Ϊ��������������ذ��е�δ��ĳʱ�̳��ֵģ����ֵĴ�ǰ��(Ҳ����kѭ�����ֵ�ǰ��)����a[i] = b[j]��
  �������ǿ����ڸ��� g[i][j] ʱ�õ����������Ҳ���ǵ� a[i] > b[k](���Ż���������ǰ���ֲ�������b[j]����A)��
  ��a[i] = b[j](��������δ��ĳʱ�̵�b[k]) ʱ�Ÿ��� g[i][j]��
  
  �������������֮��������������θ��£�
  ��ʵ�ܺ�����ˣ���Ϊ������²�������δ���� k ѭ���н��еģ��ο����ذ���룺
  maxv = max(maxv, f[i - 1][k] + 1);
  �ڽ� f[i - 1][k] �еڶ�ά���ɵ�ǰ�Ż������е� j ����(b[j](����) <=> b[k](δ��))
  
  ���ϣ����� a[i] > b[j] ʱ��g[i][j] = max(g[i][j], f[i - 1][j] + 1);
*/

//���������Ż������ڴ�
#include <iostream>

using namespace std;

const int N = 3010;

int n, a[N], b[N];
int f[N][N], g[N][N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++)
    {
        //��ʼ����Ϊ 0 + 1 = 1
        g[i][0] = 1;
        for (int j = 1; j <= n; j++)
        {
            //��ѡa[i]�����
            f[i][j] = f[i - 1][j];
            
            //ѡa[i]�����
            if (a[i] == b[j]) f[i][j] = max(f[i][j], g[i][j - 1]);
            
            //����g[i][j]ֵ
            g[i][j] = g[i][j - 1];
            if (a[i] > b[j]) g[i][j] = max(g[i][j], f[i - 1][j] + 1);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    
    cout << ans << endl;
    
    return 0;
}

//��һ���������� g ����
/*
���ǲ��ѷ��֣��������õ� g[i][j] ʱ���Ǹ��� g[i][j] ʱ
��ֻ���õ���һ�� j ѭ���Ľ��������Ȼ�Ϳ���ֻ��һ���������档
���²�������Ӱ��
*/
#include <iostream>

using namespace std;

const int N = 3010;

int n, a[N], b[N];
int f[N][N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++)
    {
        int maxv = 1;
        for (int j = 1; j <= n; j++)
        {
            //��ѡa[i]�����
            f[i][j] = f[i - 1][j];
            
            //ѡa[i]�����
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
            
            //����maxvֵ
            if (a[i] > b[j]) maxv = max(maxv, f[i - 1][j] + 1);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    
    cout << ans << endl;
    
    return 0;
}

//���п��޵Ŀռ��Ż����Ż��� i ά����
#include <iostream>

using namespace std;

const int N = 3010;

int n, a[N], b[N];
int f[N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++)
    {
        int maxv = 1;
        for (int j = 1; j <= n; j++)
        {
            //ѡa[i]�����
            if (a[i] == b[j]) f[j] = max([j], maxv);
            
            //����maxvֵ
            if (a[i] > b[j]) maxv = max(maxv, f[j] + 1);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    
    cout << ans << endl;
    
    return 0;
}