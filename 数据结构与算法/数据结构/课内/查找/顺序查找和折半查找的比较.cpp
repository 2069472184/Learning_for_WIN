#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

const int N = 1005;

using namespace std;

int num[N], a, b, x;

void Search (int *num, int target)
{
    for (int i = 1; i <= 1000; i++)
        if (*(num + i) == target) 
        {
            cout << "�ҵ��ˣ�˳����ұȽϴ���Ϊ��" << i << endl;
            return;
        }

    cout << "û���ҵ���" << endl;
}

void BinarySearch (int *num, int target)
{
    int cnt = 0;
    int l = 1, r = 1000, mid;

    while (l < r)
    {
        mid = (l + r) / 2;
        if (num[mid] >= target) r = mid;
        else l = mid + 1;  
        cnt ++;
    } 

    if (num[l] == target) cout << "�ҵ��ˣ��۰���ұȽϴ���Ϊ��" << cnt << endl;
    else cout << "û���ҵ���" << endl;
}

int main ()
{
    for (int i = 1; i <= 5; i++)
    {
        cout << "�����������������ҽ磺";
        cin >> a >> b;

        default_random_engine e;
        uniform_int_distribution<int> u(a, b);  // ����[a, b]�ڵ�����
        e.seed(time(0));

        for (int i = 1; i <= 1000; i++) num[i] = u(e);
        sort(num + 1, num + 1001);

        cout << "������������ҵ�����";
        cin >> x;

        // ֻ��¼�ҵ��ĵ�һ��λ�ã�
        Search(num, x);
        BinarySearch(num, x);
    }

    return 0;
}

/* 
����1��[1, 1000] 334
����2��[-1000, -1] -87
����3��[-33, 100] -33
����4��[100000, 1000000] 999999
����5��[1, 3] 2
*/