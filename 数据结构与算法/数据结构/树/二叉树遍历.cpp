//https://www.acwing.com/problem/content/description/3387/

//����һ��ǰ����������У����ҽ���������������������ʶ��ʱ�����ϻ���
//���ʾһ���ӽ����������Ӷ�Ϊ�գ�Ҳ����������ӽڵ�
#include <iostream>

using namespace std;

void dfs ()
{
    char h;
    cin >> h;
    
    if (h == '#') return;
    
    dfs();
    cout << h << ' ';
    dfs();
}

int main ()
{
    dfs();
    
    return 0;
}