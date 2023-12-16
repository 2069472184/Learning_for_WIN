#include <iostream>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

// ������Ľ�㶨��
struct ArcNode 
{     
  int adjvex;                // �û���ָ��Ķ����λ��
  struct ArcNode *nextarc;   // ָ����һ������ָ��
};

// ���㶨��
struct VNode 
{ 
    int data;      // ������Ϣ
    ArcNode *firstarc;    // ָ���һ�������ö���Ľ��
};

// ͼ�Ķ���
struct ALGraph
{  
	VNode vertices[100];   //����һά����
    int v, e;           // ͼ�ĵ�������
};

bool st[100];

void addEdge (ALGraph &G, int v, int w) 
{
    ArcNode *p = new ArcNode;  // �½�һ���ڵ�
    p->adjvex = w;

    G.vertices[v].data = v;

    // ͷ�巨
    p->nextarc = G.vertices[v].firstarc;
    G.vertices[v].firstarc = p;
}

void DFS (ALGraph G, int v) 
{
    memset(st, 0, sizeof(st));

    stack<int> s;
    st[v] = true;
    cout << v << ' ';
    s.push(v);

    while(!s.empty()) 
    {
        auto i = G.vertices[s.top()].firstarc;
        while (i)
            if (!st[i->adjvex])
            {
                st[i->adjvex] = true;
                cout << i->adjvex << " ";
                s.push(i->adjvex);
                break;
            }
            else i = i->nextarc;
        
        if (!i) s.pop();
    }
}

void BFS (ALGraph G, int v)
{
    memset(st, 0, sizeof(st));

    queue<int> q;
    st[v] = true;
    cout << v << " ";
    q.push(v);

    while (!q.empty())
    {
        auto i = G.vertices[q.front()].firstarc;
        q.pop();
        for (; i; i = i->nextarc)
            if (!st[i->adjvex])
            {
                st[i->adjvex] = true;
                cout << i->adjvex << ' ';
                q.push(i->adjvex);
            }
    }
}

int main () 
{
    ALGraph g;
    cout << "������ͼ�ĵ����ͱ�����";
    cin >> g.v >> g.e;

    for(int i = 1; i <= g.v; i++)
        g.vertices[i].firstarc = NULL;

    int a, b;
    cout << "�������������бߣ�" << endl;
    for (int i = 1; i <= g.e; i++)
    {
        cin >> a >> b;
        addEdge(g, a, b);
    }

    int st = 0;
    cout << "���������������ţ�";
    cin >> st;
    cout << "������ȱ���(�Ӷ���" << st << "��ʼ):";
    DFS(g, st);
    cout << endl;
    cout << "������ȱ���(�Ӷ���" << st << "��ʼ):";
    BFS(g, st);

    return 0;
}


/*
����1��   
6 8
1 2
1 4
2 5
3 1
3 6
4 6
4 2
6 5
�����
dfs��1 4 2 5 6
bfs��1 4 2 6 5

����2��
6 8
1 3
1 2
2 3
2 6
3 4
5 2
5 4
6 4
�����
dfs��1 2 6 4 3
bfs��1 2 3 6 4

����3��
5 6
1 2
1 5
1 4
2 3
4 5
5 3
�����
dfs��1 4 5 3 2
bfs��1 4 5 2 3
*/