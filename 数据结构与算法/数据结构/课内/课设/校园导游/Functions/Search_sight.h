// ������Ϣ�Ĳ�ѯ
void Search_sight (unordered_map<string,Sight> m)
{
    string name;
    cout << "������һ���������ƣ�";
    cin >> name;

    if (m.find(name) != m.end()) m[name].Show();
    else cout << "���㲻���ڣ�" << endl;
}