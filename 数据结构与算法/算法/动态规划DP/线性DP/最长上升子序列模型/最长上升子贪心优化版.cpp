//https://www.acwing.com/problem/content/898/

//̰���Ż�
//����dp[j],�洢jǰ��ÿ�ֳ��ȵ�����������е�ĩβ��С��ֵ��
//������Щֵ���������г�����С�������ڵ�������ջ��
//��Ϊ��βԽС���������Ԫ��ʱ�ķ�Χ�͸���
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <bitset>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;

const int N = 100010;
typedef long long ll;

int le[N];
int n, x[N], len;

int main ()
{
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> x[i];

    for ( int i = 1; i <= n; i++ )
    {
        int l = 0, r = len;
        while ( l < r )
        {
            int mid = ( l + r + 1 ) / 2;
            if ( le[mid] < x[i] ) l = mid;
            else r = mid - 1;
        }

        len = max( len, r+1 );
        le[r+1] = x[i];
    } 

    cout << len;

    return 0;
}