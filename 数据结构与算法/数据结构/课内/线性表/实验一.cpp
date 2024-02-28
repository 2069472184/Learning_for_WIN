# include <iostream>

# define LIST_INIT_SIZE 100
# define ElemType int

using namespace std;

typedef struct
{
    ElemType * elem;
    int length;
    int listsize;
} SqList;

// key Ϊֵ��cin Ϊ��, pos Ϊ�����±�, e Ϊ����Ԫ�أ�h Ϊ������ʽ, flag ��ʾ�Ƿ�����
ElemType key;
int num, pos, e;
string h;
bool flag = true;

void InitList_Sq (SqList &L) 
{
    L.elem = new ElemType[LIST_INIT_SIZE];
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
}

void ListInsert_Sq (SqList &L, int var, int a)
{
    L.length ++;
    for (int i = L.length - 1; i > var; i--)
        L.elem[i] = L.elem[i - 1];
    
    L.elem[var] = a;
}

void ListDelet_Sq (SqList &L, int i, ElemType &e)
{
    e = L.elem[i];
    for (int j = i + 1; j < L.length; j++)
        L.elem[j - 1] = L.elem[j];
    
    L.length --;
}

int ListLocate_Sq (SqList L, ElemType e)
{
    int pos = -1;
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e) pos = i;
    return pos;
}

void Mergelist_Sq (SqList &L1, SqList &L2, bool flag)
{
    int i = 0, j = 0;
    if (flag)
    {
        while (i < L1.length && j < L2.length)
            if (L1.elem[i] < L2.elem[j]) i++;
            else 
            {
                ListInsert_Sq(L1, i, L2.elem[j]);
                j++;
            }

        while (j < L2.length)
        {
            ListInsert_Sq(L1, i, L2.elem[j]);
            j++, i++;
        }
    }
    else
    {
        for (int j = 0; j < L2.length; j++)
            if (ListLocate_Sq(L1, L2.elem[j]) == -1) ListInsert_Sq(L1, L1.length, L2.elem[j]);
    }
}

void Show_Sq (SqList &L)
{
    for (int i = 0; i < L.length; i++) cout << L.elem[i] << ' ';
    cout << endl;
}

int main ()
{
    SqList L1, L2;
    InitList_Sq(L1);
    InitList_Sq(L2);

    // �������
    cout << "���������봴����˳����ȣ�";
    cin >> num;
    
    for (int i = 0; i < num; i++)
    {
        cout << "�������" << i + 1 << "��Ԫ��ֵ��";
        cin >> key;
        if (i > 0 && key < L1.elem[i - 1]) flag = false;
        ListInsert_Sq(L1, i, key);
    }

    //��ȡ������ʽ
    cout << "�����������ʽ: ";
    cin >> h;
    while (h != "E")
    {
        if (h == "D") 
        {
            cout << "����������ɾ����Ԫ��λ��: ";
            cin >> pos;
            ListDelet_Sq(L1, pos - 1, e);
            cout << "��ɾ����Ԫ��Ϊ: " << e << endl;
            cout << "˳������Ϊ��";
            Show_Sq(L1);
        }
        else if (h == "S")
        {
            cout << "������������ҵ�Ԫ��: ";
            cin >> key;
            int var = ListLocate_Sq(L1, key) + 1;
            if (var) cout << "��Ԫ����˳����е�λ��Ϊ��" << var << endl;
            else cout << "˳�����û��ָ��Ԫ��" << endl;
        }

        cout << "�����������ʽ: ";
        cin >> h;
    }

    // �ϲ�����˳���
    cout << "���������봴���ĵڶ���˳����ȣ�";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "�������" << i + 1 << "��Ԫ��ֵ��";
        cin >> key;
        ListInsert_Sq(L2, i, key);
    }
    
    Mergelist_Sq(L1, L2, flag);
    
    cout << "�ϲ����Ϊ��";
    Show_Sq(L1);

    return 0;
}

/*
����1��
S1��1 3 5 7 9����ɾ����2��Ԫ��
S2��2 4 5 6 8
����ϲ������1 2 4 5 5 6 7 8 9

����2��
S1��1 2 45 6 889����ɾ����1��Ԫ��
S2��3 2 4 6 77
����ϲ������2 45 6 889 3 4 77
*/