//https://www.acwing.com/problem/content/description/909/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Range
{
    int l, r;
    
    bool operator< (const Range &k)const
    {
        return l < k.l;
    }
} range[N];

int main ()
{
    int s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        int a, b;
        scanf("%d%d", &a, &b);
        range[i] = {a, b};
    }
    
    sort(range, range + n);
    
    int res = 0;
    bool success = false;
    for (int i = 0; i < n; i++)
    {
        int j = i, r = -2e9;
        //��j��ö��ÿһ����˵� <= s �����䣬Ѱ�������Ҷ˵�
        while (j < n && range[j].l <= s)
        {   
            r = max(r, range[j].r);
            j++;
        }
        
        //���������������������Ҷ˵㲻�ܸ���Ŀ�����䣬˵���޽�
        if (r < s)
        {
            res = -1;
            break;
        }
        
        //����˵������ĳ��������Ը���Ŀ�����俪ͷ��һ���֣�����res
        //ע�⣬�˴����� res һ��Ҫ���ж� r >= t ��ǰ��
        res++; 
        
        //�����ʱ�Ҷ˵����Ŀ��������Ҷ˵㣬��˵��ȫ���������
        if (r >= t)
        {
            success = true;
            break;
        }
        
        //����Ŀ���������˵�
        s = r;
        //����i���ӱ������ڸ���Ŀ������������ұߵ�һ�����俪ʼ����
        i = j - 1;
    }
    
    if (!success) res = -1;
    
    cout << res << endl;
    
    return 0;
}