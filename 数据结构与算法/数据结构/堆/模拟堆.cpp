//https://www.acwing.com/problem/content/841/

#include <iostream>
using namespace std;

const int N = 100010;

int n, h[N], Count;

//ph����洢��k�����뵽�����ĸ��ڵ��ϣ����±�
//hp����洢ph������±꣬��ʾ��k�����������������ph�ж�Ӧ���±�
//�� ph[k] = j �� hp[j] = k;
//ph -> position in tree; hp -> tree's elements' position in ph
int ph[N], hp[N], num;

string a;
int x, k;

void heap_swap ( int a, int b )
{
    //����Ľڵ��ph����Ԫ����˫��ָ��Ĺ�ϵ������ph[k]ָ���k��������������еĽڵ�(������j)����ph[k] = j��
    //������е�j�ڵ�Ҳָ��ph[k]��ph�����е�λ�ã���ÿ�����ڵ㶼���и�ָ��
    //�������ǽ�ÿ�����ڵ��ph����Ԫ�ص�ָ���ϵ����һ��hp����洢����hp[j] = k��������˫����Ľṹ
    
    //�Ƚ�ph�����ָ�뻥��
    swap(ph[hp[a]], ph[hp[b]]);
    //phָ�뻥����hp�����ָ��û�иı䣬����Ҳ��Ҫ����һ��hp�����ָ��
    swap(hp[a], hp[b]);
    //��󽻻�����Ԫ��ֵ
    swap(h[a], h[b]);

    //�������ֲ������Ի���λ�ã�����Ϊ�˷�����⣬����ֱ��д��������ʽ���Ȼ�ָ�룬�ٻ�Ԫ��ֵ
}

void down ( int u )
{
    int t = u;
    if ( u*2 <= Count && h[u*2] < h[u] ) t = u*2;
    if ( u*2 + 1 <= Count && h[u*2+1] < h[t] ) t = u*2 + 1;
    if ( t != u )
    {
        heap_swap(t, u);
        down(t);
    }
}

void up ( int u )
{
    while ( u > 1 && h[u/2] > h[u] )
    {
        heap_swap(u/2, u);
        u /= 2;
    }
}

int main ()
{
    cin >> n;

    while ( n-- )
    {
        cin >> a;
        if ( a[0] == 'I' )
        {
            cin >> x;
            h[++Count] = x;
            ph[++num] = Count, hp[Count] = num;
            up(Count);
        }
        else if ( a[0] == 'P' )
        {
            cout << h[1] << endl;
        }
        else if ( a == "DM" )
        {
            heap_swap(1, Count);
            Count--;
            down(1);
        }
        else if ( a[0] == 'D' )
        {
            cin >> k;
            //�˴���Ҫ�洢һ��ph[k]ԭ����ֵ����Ϊ�ھ���heap_swap������ph[k]��
            //�±껹��k��������ֵ��ı�
            k = ph[k];
            heap_swap(k, Count);
            Count--;
            up(k);
            down(k);
        }
        else
        {   
            cin >> k >> x;
            //�˴�ͬ��
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}