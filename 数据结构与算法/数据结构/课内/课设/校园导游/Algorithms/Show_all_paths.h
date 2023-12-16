// չʾ���������·��
void DFS_for_Show_all_paths (int st, int (*g)[SIZE + 1], int en, int cnt, int mark[SIZE + 1], int used[SIZE + 1])
{
    if (st == en)
    {
        for (int i = 1; i < cnt - 1; i++) cout << mark[i] << "->";
        cout << en << endl;
        return;
    }

    for (int i = 1; i <= SIZE; i++)
        if (*(g[st] + i) != 0 && *(g[st] + i) != 0x3f3f3f3f && !used[i])
        {
            used[i] = true;
            mark[cnt] = i;
            DFS_for_Show_all_paths(i, g, en, cnt + 1, mark, used);
            used[i] = false;
        }
}

void Show_all_paths (unordered_map<string, Sight> m, int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{
    string na, nb, type;
    cout << "�����ѯ����������֮��������ʵ�·����";
    cin >> na >> nb >> type;

    int a = stoi(m[na].getID());
    int b = stoi(m[nb].getID());

    int k = 1;
    int mark[SIZE + 1], used[SIZE + 1];
    memset(used, 0, sizeof(used));
    memset(mark, 0, sizeof(mark));

    cout << "��" << na << "���͡�" << nb << "��֮���" << type << "·���У�" << endl;

    used[a] = true;
    mark[k] = a;
    if (type == "��������") DFS_for_Show_all_paths(a, g1, b, k + 1, mark, used);
    if (type == "���е�") DFS_for_Show_all_paths(a, g2, b, k + 1, mark, used);
}