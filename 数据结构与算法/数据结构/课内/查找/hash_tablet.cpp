#include <iostream>

using namespace std;

typedef struct Elem
{
    int key;
    int compareTimes;
    int flag;
} Elem;

typedef struct HashList
{
    Elem *base;
    int length;
} HashList;

void CreateHashList (HashList &HL)
{
    int num[] = {23, 5, 17, 12, 26, 31, 13, 4, 6};

    HL.base = new Elem[13];
    HL.length = 9;

    for (int i = 0; i < 13; i++) 
    {
        HL.base[i].flag = 0;
        HL.base[i].compareTimes = 0;
    }

    for (int i = 0; i < 9; i++)
    {
        int cnt = 1;
        int key = num[i] % 13;
        while (HL.base[key].flag) 
        {
            key = (key + 1) % 13;
            cnt ++;
        }

        HL.base[key].key = num[i];
        HL.base[key].flag = 1;
        HL.base[key].compareTimes = cnt;
    }
}

void PrintHashList (HashList HL)
{
    for (int i = 0; i < 13; i++)
        if (HL.base[i].flag) cout << "HL.base[" << i << "].key: " << HL.base[i].key << endl;
}

void IndexHashList (HashList HL, int x)
{
    int key = x % 13;
    while (HL.base[key].flag && HL.base[key].key != x) key = (key + 1) % 13;

    if (HL.base[key].key == x) cout << "�ҵ��ˣ�" << "Ԫ��" << x << "�ڹ�ϣ���е�" << key + 1 << "��λ��(HL.base[" << key << "])��" << endl;
    else cout << "û�ҵ���" << endl;
}

void DeleteIndex (HashList &HL, int idx)
{
    if (HL.base[idx - 1].flag) 
    {
        cout << "�ɹ�ɾ����ϣ���е�" << idx << "��λ���ϵ�Ԫ��(HL.base[" << idx - 1 << "].key): " << HL.base[idx - 1].key << endl;
        HL.base[idx - 1].flag = 0;
        HL.base[idx - 1].key = 0;
        HL.base[idx - 1].compareTimes = 0;
    }
    else cout << "��λ���ϻ�û��Ԫ�أ�" << endl;
}

void CalcuASL (HashList HL)
{
    double sum = 0;
    int count = 0;
    for (int i = 0; i < 13; i++)
        if (HL.base[i].flag) 
        {
            sum += HL.base[i].compareTimes;
            count ++;
        }

    cout << "��ϣ���ƽ�����ҳ���Ϊ��" << sum / count << endl;
}

void Menu ()
{
    cout << "===================================" << endl;
    cout << "           1.��ʾ��ϣ��             " << endl;
    cout << "            2.����Ԫ��              " << endl;
    cout << "            3.ɾ��Ԫ��              " << endl;
    cout << "            4.����ASL               " << endl;
    cout << "             5.�˳�                 " << endl;
    cout << "===================================" << endl;
}

int op, x, idx;

int main ()
{
    HashList HL;
    CreateHashList(HL);

    Menu();

    while (true)
    {
        cout << "������������еĲ�����";
        cin >> op;
        cout << endl;

        if (op == 5) break;
        else if (op == 1) 
        {
            cout << "�����ǹ�ϣ�������Ԫ��:" << endl;
            PrintHashList(HL);
        }
        else if (op == 2)
        {
            cout << "������������ҵ�Ԫ�أ�" << endl;
            cin >> x;
            IndexHashList(HL, x);
        }
        else if (op == 3)
        {
            cout << "����ɾ����ϣ�����ĸ�λ�õ�Ԫ�أ�(��1��ʼ)";
            cin >> idx;
            DeleteIndex(HL, idx);
        }
        else if (op == 4) CalcuASL(HL);
        else cout << "������[1, 5]�ڵ�������" << endl;

        cout << endl;
    }

    return 0;
}