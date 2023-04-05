//https://www.acwing.com/problem/content/3305/

//��׺���ʽֱ����ֵ
//����һ�Ŷ��������ڵ㶼������������Ķ��Ӷ���ֵ��
//�ҽڵ�����ȼ��ͱ��ִ�С�ɷ��ȣ������ȼ��ߵĽڵ��ȱ����㣬Ȼ�������������ڵ�
//����ж�ĳ�������Ѿ��������꣺��ǰ�ڵ���������ȼ� >= ���ڵ����ȼ�

#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

//����ջ�ֱ�洢���ֺͷ���
stack<int> num;
stack<char> op;

//��ϣ��洢���ź����ȼ��Ķ�Ӧ��ϵ��Ԫ��
unordered_map<char, int> pr = {{'+', 1},{'-', 1},{'*', 2},{'/', 2}};

string str;

//���㺯��
void eval ()
{
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top(); op.pop();
    int x;
    if ( c == '+' ) x = a + b;
    else if ( c == '-' ) x = a - b;
    else if ( c == '*' ) x = a * b;
    else x = a / b;

    num.push(x);
}

int main ()
{
    cin >> str;
    for ( int i = 0; i < str.size(); i++ ) 
    {
        auto c = str[i];
        if ( isdigit(c) ) 
        //���cΪ���֣�����������������ּ����������ѹ��numջ��
        {
            int ans = 0;
            int j;
            for ( j = i; j < str.size() && isdigit(str[j]); j++ )
                ans = ans*10 + str[j] - '0';

            i = j - 1;  //����i�±�
            num.push(ans);
        }
        else if ( c == '(' ) op.push(c);
        else if ( c == ')' )
        //����������ţ����轫������֮ǰ�����з������numջ��Ԫ�ؼ��㲢ѹ��numջ��
        {
            while ( op.top() != '(' ) eval();
            op.pop();  //����������
        }
        else 
        //�������ͨ��������������ȼ��Ĵ�С��ϵ�����Ǽ��㻹��ѹ��opջ��
        //������׺���ʽ���ȼ���Ŀ϶������ȼ���ģ�������ÿһ���������ѹ��opջǰһ��Ҫ�ж�ջ�����ȼ����������Ƿ񶼼�������
        {
            while ( op.size() && pr[op.top()] >= pr[c] ) eval();
            op.push(c);
        }
    }

    while ( op.size() ) eval();  //���opջ�л��д�������ȫ��������
    
    cout << num.top() << endl;  //���numջ��ֻ��һ��Ԫ�أ�����

    return 0;
}