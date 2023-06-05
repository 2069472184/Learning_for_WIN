//https://www.acwing.com/problem/content/189/

//dfs + ��֦ + �½�����˫�� + ̰��

#include <iostream>
#include <cstring>

using namespace std;

const int N = 55;

int n, a[N], ans;
int up[N], down[N];

//u����������ڼ�������xu��ʾ�½������и�����su��ʾ���������и���
//����ÿһ���������������xu�к�su�еĲ�ͬ���
void dfs (int u, int xu, int su) 
{
    //������������Ҳ��������Ԫ���Գ�һ�����л����Ѿ�����n��ʱ����ʱ��Ҫ��֦
    if (xu + su >= ans) return;
    
    //���û�г���n�������е����������ǵ�����ʱ�������Ž�
    if (u == n + 1)
    {
        ans = xu + su;
        return;
    }
    
    //���1������ǰ��Ϯ�����ŵ��½���������
    int k = 1;
    while (k <= xu && down[k] <= a[u]) k++;
    int t = down[k];
    down[k] = a[u];
    if (k > xu) dfs(u + 1, xu + 1, su);
    else dfs(u + 1, xu, su);
    down[k] = t;  //�ָ��ֳ�
    
    //���2������ǰ��Ϯ�����ŵ�������������
    k = 1;
    while (k <= su && up[k] >= a[u]) k++;
    t = up[k];
    up[k] = a[u];
    if (k > su) dfs(u + 1, xu, su + 1);
    else dfs(u + 1, xu, su);
    up[k] = t;    //�ָ��ֳ�
}

int main ()
{
    while (cin >> n, n)
    {
        //�˴���ʼ��up��down����û�б�Ҫ����Ϊÿһ��up��down���鶼���ȱ�a����Ԫ�ظ�ֵ���ٱȽϵ�
        //memset(up, 0, sizeof(up));
        //memset(down, 0, sizeof(down));
        
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        //����
        ans = n;
        
        //�ӵ�һ����ʼ��������һ������Ϊ 1
        dfs(1, 0, 0);
        
        cout << ans << endl;
    }
    
    return 0;
}