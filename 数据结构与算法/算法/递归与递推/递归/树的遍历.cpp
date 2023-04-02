//https://www.acwing.com/problem/content/1499/

//��ϣ��--��ֱ�۵ķ���
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
 
const int N = 35;

int n, mid[N], bac[N];
// l[i] = j �� r[i] = k �ֱ��ʾ i �ڵ������� j ���Ҷ��� k
// g �洢���������ÿһ��Ԫ�ص��±�
unordered_map<int, int> l, r, g;

int build (int ml, int mr, int bl, int br)
{
    //��ǰ�����ĸ��ڵ�Ϊ�����������е����һ��Ԫ��
    int root = bac[br];
    //��ǰ�����ĸ��ڵ��Ӧ�±�
    int rg = g[root];
    
    //������ݺ���������ҵ��ĸ��ڵ�������������ҵ���ӦԪ�أ����ж������Ĵ������
    //������������ڣ��ݹ�õ����������ڵ�
    if (ml < rg) l[root] = build(ml, rg - 1, bl, bl + rg - ml - 1);
    //������������ڣ��ݹ�õ����������ڵ�
    if (mr > rg) r[root] = build(rg + 1, mr, bl + rg - ml, br - 1);
    
    return root;
}

//����Ϊʲô���԰��ղ���ÿ��������ұ�����
//���ݴ��룬�����ڱ���ʱ�����Ƚ��ò����нڵ�ĵ�һ�ӽڵ�������У�����Щ���ڶ���������˳����Ǵ������ҵ�
//���Ҹ��ڵ�ȵ�һ�ӽ��Ҫ����ӣ����Ա��Ƚ����ڵ�����������һ�ӽ��
void bfs (int root)
{
    queue<int> q;
    q.push(root);
    
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        cout << t << ' ';
        //��� t ������ӣ��ͽ��ö��ӵ��±��������
        if (l.count(t)) q.push(l[t]);
        //�������ͬ��
        if (r.count(t)) q.push(r[t]);
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> bac[i];
    for (int i = 1; i <= n; i++) 
    {
        cin >> mid[i];
        //�洢һ������������ÿ��Ԫ�ص��±�
        g[mid[i]] = i;
    }
    
    //�ؽ������������Բ���������������������Ҷ˵㣬������������Ҷ˵�
    int root = build(1, n, 1, n);    
    
    //�ÿ��Ѳ����������
    bfs(root);
    
    return 0;
}


//���ù�ϣ--ֱ�Ӳ���洢��ʡȥbfs����
#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

//g�洢���������ÿ�������±�
int n, mid[N], bac[N], g[N];
vector<int> level[N];

//��������Ϊ�����������Ҷ˵㣬����������Ҷ˵㣬���������
void build (int ml, int mr, int bl, int br, int d)
{
    int root = bac[br];
    int rg = g[root];

    //���ò�Ľڵ������
    level[d].push_back(root);
    
    //���ж����������Ƿ����
    if (rg > ml) build(ml, rg - 1, bl, bl + rg - ml - 1, d + 1);
    if (rg < mr) build(rg + 1, mr, bl + rg - ml, br - 1, d + 1);
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> bac[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> mid[i];
        g[mid[i]] = i;
    }
    
    build(1, n, 1, n, 1);
    
    //����ÿһ���Ԫ�أ�level �б�����Ǵ����������еģ�����ֱ���������
    for (int i = 1; i <= n; i++)
        for (int t : level[i])
            cout << t << ' ';
    
    return 0;
}