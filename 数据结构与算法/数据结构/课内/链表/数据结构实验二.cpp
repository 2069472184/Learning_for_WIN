# include <iostream>
# define ElemType int 

using namespace std;

typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode, *linkList;

// ʹ��β�巨����������
void CreateList_L (linkList &L, int num)
{
    L = new LNode;
    L -> next = NULL;
    linkList pl = L;

    int data;
    for (int i = 1; i <= num; i++)
    {
        cin >> data;
        linkList p = new LNode;
        p -> data = data;
        p -> next = NULL;
        pl -> next = p;
        pl = p;
    }
}

// �ϲ������ǵݼ�����
void MergeList_L (linkList &La, linkList &Lb, linkList &Lc)
{
    linkList pa = La -> next;
    linkList pb = Lb -> next;
    Lc = La;
    linkList pc = Lc;

    while (pa && pb)
        if (pa -> data <= pb -> data)
        {
            pc -> next = pa;
            pc = pa;
            pa = pa -> next;
        }
        else
        {
            pc -> next = pb;
            pc = pb; 
            pb = pb -> next;
        }
    
    pc -> next = pa ? pa : pb;
}

// ɾ���������ظ�Ԫ��: 2�ַ�ʽ
void PurgeList_L (linkList &Lc)
{
    linkList pc = Lc -> next;

    while (pc)
    {
        linkList q = pc -> next;

        while (q && q -> data == pc -> data)
        {
            linkList r = q;
            q = r -> next;
            delete r;
            pc -> next = q;
        }

        pc = pc -> next;
    }

    // while (pc && pc -> next)
    //     if (pc -> data == pc -> next -> data)
    //     {
    //         linkList r = pc -> next;
    //         pc -> next = r -> next;
    //         delete r;
    //     }
    //     else pc = pc -> next;
}

// �������Ԫ��
void ShowList_L (linkList &L)
{
    linkList pL = L -> next;

    while (pL)
    {
        cout << pL -> data << ' ';
        pL = pL -> next;
    }

    cout << endl;
}

int main ()
{
    linkList La, Lb, Lc;    

    CreateList_L(La, 5);
    CreateList_L(Lb, 6);

    

    MergeList_L(La, Lb, Lc);

    cout << "�ϲ��������Ԫ��Ϊ��" << endl; 
    ShowList_L(Lc);

    PurgeList_L(Lc);

    cout << "ȥ�غ������Ԫ��Ϊ��" << endl;
    ShowList_L(Lc);

    return 0;
}
