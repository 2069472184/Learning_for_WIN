// ���м�ڵ����ƵĶ�Դ���·
// ��Ҫ�ظ�����ĳ����
// ��ǰ·������
int Get_dist (int (*g)[SIZE + 1], int st, int en, int k, int must[SIZE + 1])
{
    int distance = g[st][must[1]];
    if (distance == 0x3f3f3f3f) return 0x3f3f3f3f;

    for (int i = 1; i < k; i++)
        if (g[must[i]][must[i + 1]] == 0x3f3f3f3f) return 0x3f3f3f3f;
        else distance += g[must[i]][must[i + 1]];

    if (g[must[k]][en] == 0x3f3f3f3f) return 0x3f3f3f3f;
    else return distance += g[must[k]][en];
}

// �õ�·��
void Get_path(int a, int b, int (*path)[SIZE + 1], int &idx, int anspath[SIZE])
{
    if (*(path[a] + b) == -1) return;
    else 
    {
        int k = *(path[a] + b);
        Get_path(a, k, path, idx, anspath);
        anspath[idx++] = k;
        Get_path(k, b, path, idx, anspath);
    }
}

// �������·��
void Save_path (int anspath[SIZE + 1], int (*path)[SIZE + 1], int st, int en, int k, int &idx, int must[SIZE])
{
    anspath[idx++] = 1;
    Get_path(st, must[1], path, idx, anspath);

    for (int i = 1; i < k; i++)
    {
        anspath[idx++] = must[i];
        Get_path(must[i], must[i + 1], path, idx, anspath);
    }

    anspath[idx++] = must[k];
    Get_path(must[k], en, path, idx, anspath);
    anspath[idx++] = en;
}

void Mutli_Floyd (unordered_map<string, Sight> m, int (*G1)[SIZE + 1], int (*G2)[SIZE + 1])
{
    int g[SIZE + 1][SIZE + 1];       // ��¼��������֮������·��
    int path[SIZE + 1][SIZE + 1];    // ��¼��������֮�����·���ĵ�һ���ؾ���
    memset(path, -1, sizeof(path));  
    int must[SIZE + 1], k = 0;       // ��¼;����
    int anspath[SIZE + 1], idx = 1;  // ��¼����·��

    // ���������
    string na, nb, sight, type;
    stringstream sights;
    cout << "�����������������ĺ������ʵ����·����";
    cin >> na >> nb >> type;
    getchar();
    cout << "�㻹�뾭���ļ������㣺";
    getline(cin, sight);
    sights << sight;

    // ��¼��β����
    int a = stoi(m[na].getID());
    int b = stoi(m[nb].getID());
    // ��¼;����
    while (sights >> sight) must[++k] = stoi(m[sight].getID());

    // ��ʼ��
    if (type == "��������") 
    {
        for (int i = 1; i <= SIZE; i++) 
            for (int j = 1; j <= SIZE; j++) 
                g[i][j] = *(G2[i] + j);
    }
    else if (type == "���е�")
    {
        for (int i = 1; i <= SIZE; i++) 
            for (int j = 1; j <= SIZE; j++) 
                g[i][j] = *(G2[i] + j);   
    }

    // Floyd
    for (int k = 1; k <= SIZE; k++)
        for (int i = 1; i <= SIZE; i++)
            for (int j = 1; j <= SIZE; j++)
                if (g[i][j] > g[i][k] + g[k][j]) 
                {
                    g[i][j] = g[i][k] + g[k][j];
                    path[i][j] = k;
                }

    // �����β�ڵ�֮�䲻����·�������˳�
    if (g[a][b] == 0x3f3f3f3f) 
    {
        cout << "������������·����" << endl; 
        return;
    }

    // �����򣬱�ʾ����;����ĵ�һ�����з�ʽ
    sort(must + 1, must + 1 + k);
    int min_dist = 0x3f3f3f3f;

    // ����;������������з�ʽ
    do 
    {
        int d = Get_dist(g, a, b, k, must);
        if (min_dist > d) 
        {
            min_dist = d;
            Save_path(anspath, path, a, b, k, idx, must);
        }
    } while (next_permutation(must + 1, must + 1 + k));

    // ������
    cout << "�ӡ�" << na << "������" << nb << "��������";
    while (sights >> sight) cout << "��" << sight << "��";
    cout << "��" << type << "���·����Ϊ��" << min_dist << endl;

    cout << "����·��Ϊ��";
    for (int i = 1; i < idx - 1; i++) cout << anspath[i] << "->";
    cout << anspath[idx - 1] << endl;
}   

