// ɾ��·��
void Delete_path (unordered_map<string, Sight> m, int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{
    string na, nb, type;
    cout << "����ɾ������������֮��������ʵ�·����";
    cin >> na >> nb >> type;

    int a = stoi(m[na].getID());
    int b = stoi(m[nb].getID());

    if (type == "��������") 
    {
        *(g1[a] + b) = 0x3f3f3f3f;
        *(g1[b] + a) = 0x3f3f3f3f;
    }
    else if (type == "���е�")
    {
        *(g2[a] + b) = 0x3f3f3f3f;
        *(g2[b] + a) = 0x3f3f3f3f;      
    }
}