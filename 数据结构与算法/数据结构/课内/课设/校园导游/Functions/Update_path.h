// ����·����Ϣ
void Update (unordered_map<string, Sight> m, int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{
    string na, nb, type;
    cout << "�����������޸ĵ�·�����˵ľ������Ƽ�·�����ʣ�";
    cin >> na >> nb >> type;

    int a = stoi(m[na].getID());
    int b = stoi(m[nb].getID());

    int len;
    cout << "�����������޸ĵ�·�����ȣ�";
    cin >> len;

    if (type == "��������") 
    {
        g1[a][b] = len;
        g1[b][a] = len;
    }
    else if (type == "���е�")
    {
        g2[a][b] = len;
        g2[b][a] = len;        
    }
}

void Update_path (unordered_map<string, Sight> m, int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{   
    Update(m, g1, g2);
}   