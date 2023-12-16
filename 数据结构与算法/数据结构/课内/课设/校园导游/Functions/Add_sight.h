// ��������
struct pos
{
    int x = 0, y = 0;
    bool operator< (const pos &p) const
    {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

void Add (map<pos, Sight> &S1, unordered_map<string, Sight> &S2)
{
    int x, y;
    string id, name, intro, comment;
    cout << "����������������ӵľ������꣬��ţ����ƣ���鼰ѧ�����ۣ�";
    cin >> x >> y >> id >> name >> intro >> comment;

    // ���������뾰��֮�������
    pos p = {x, y};
    S1[p] = Sight(x, y, id, name, intro, comment);

    // ���������뾰��֮�������
    S2[name] = Sight(x, y, id, name, intro, comment);
}

void Add_sight (map<pos, Sight> &S1, unordered_map<string, Sight> &S2)
{
    for (int i = 1; i <= 4; i++) Add(S1, S2);
}