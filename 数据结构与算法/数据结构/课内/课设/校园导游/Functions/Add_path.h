// ·�������
void Add(int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{
    while (true)
    {
        cout << "������������ӵ�·����Ϣ����㣬�յ㣬���ȣ����ʣ���";
        int x, y, w;
        string type;
        cin >> x >> y >> w >> type;
        if (type == "��������") 
        {
            *(g1[x] + y) = min(*(g1[x] + y), w);
            *(g1[y] + x) = min(*(g1[y] + x), w);
            break;
        }
        else if (type == "���е�")
        {
            *(g2[x] + y) = min(*(g2[x] + y), w);
            *(g2[y] + x) = min(*(g2[y] + x), w);
            break;
        }
        else cout << "��������ȷ�ĵ�·���ʣ�";
    }
}

void Add_path(int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{
    for (int i = 1; i <= 9; i++)
        Add(g1, g2);
}