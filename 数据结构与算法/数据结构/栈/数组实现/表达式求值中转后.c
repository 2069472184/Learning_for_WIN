//https://www.acwing.com/problem/content/3305/

//��׺ת��׺�ټ���
#include<stdio.h>
#include<string.h>
#define N 100010

//ex[N]Ϊ��׺���ʽ������9������δ�ϲ�������1000��ex�д洢Ϊex[1]=1,ex[2]=0,ex[3]=0,ex[4]=0��
//last[N]��ֻ�����ŵĺ�׺���ʽ��num[N]��ֻ�����ֵĺ�׺���ʽ
//last[N]��num[N]����ͬһ���±�
char ex[N], last[N];
int num[N];

//k��������ex[N]��countΪlast[N]��num[N]�Ĺ����±�
int k, count;

//ansջ��������𰸣�stkջ���������׺ת��׺ʱ���ַ���idx��Ϊ�±�
int ans[N];
char stk[N];
int idx;

//��׺ת��׺�������ִ����num������
void change ( int botton )  //botton��ʾ�ú�����������Զ��Ե�ջ���±꣬������0��Ҳ������'('���ڵ��±�
{
    while ( k+1 <= strlen(ex+1) )
    {
        k++;
        if ( ex[k] >= '0' && ex[k] <= '9' ) //�����׺���ʽ��λ�ñ�ʾ����,����������������һ������õ���׺���ʽ�е����ֲ������num������
        {
            num[++count] = ex[k++] - '0';
            while ( ex[k] >= '0' && ex[k] <= '9' ) 
                num[count] = num[count] * 10 + ( ex[k++] - '0' );
            k--;
        }
        else if ( ex[k] == '*' || ex[k] == '/' )  //�����׺���ʽ��λ����*��/����ջ��ͬ���ȼ���*��/��������׺���ʽ�У�ֱ��ջ����+��-
        {
            int j;
            for ( j = idx; j > botton; j-- )
            {
                if ( stk[j] == '*' || stk[j] == '/' ) last[++count] = stk[j];
                else break;
            }
            idx = j;
            stk[++idx] = ex[k];
        }
        else if ( ex[k] == '+' || ex[k] == '-' )  //�����׺���ʽ��λ����+��-������Ҫ��ջ�з������η����׺���ʽ�У������ջ�з����λ�õ�+��-
        {
            int j;
            for ( j = idx; j > botton; j-- )
                last[++count] = stk[j];
            idx = j;
            stk[++idx] = ex[k];
        }
        else if ( ex[k] == '(' )  //�����׺���ʽ��λ��Ϊ�����ţ���ݹ����ת���������Ѹ�λ�ÿ����µ�ת�������е�ջ���±�
        {
            stk[++idx] = '(';
            change(idx);
        }
        else if ( ex[k] == ')' )  //������������ţ���ջ����botton�����з��ŵ�������׺���ʽ�У������ų��⣬����idxΪbotton-1
        {
            int j;
            for ( j = idx; j > botton; j-- ) last[++count] = stk[j];
            idx = j-1;
            return;
        }
    }

    return;
}

//�����׺���ʽ
void calculate ()
{
    for ( int i = 1; i <= count; i++ )
    {
        if ( last[i] == 0 ) ans[++idx] = num[i]; //���last[i]Ϊ0��˵����׺���ʽ�ڴ˴������֣������num[i]��
        else if ( last[i] == '+' )
        {
            int sum = ans[idx-1] + ans[idx];
            ans[--idx] = sum;
        }
        else if ( last[i] == '-' )
        {
            int minor = ans[idx-1] - ans[idx];  //ע������ͳ�����ǰ���������
            ans[--idx] = minor;
        }
        else if ( last[i] == '*' )
        {
            int plus = ans[idx-1] * ans[idx];
            ans[--idx] = plus;
        }
        else if ( last[i] == '/' )
        {
            int divide = ans[idx-1] / ans[idx];
            ans[--idx] = divide;
        }
    }   
}

int main ( int argc, char *argv[] )
{
    gets(ex+1);
    
    change(0);

    while (idx) last[++count] = stk[idx--];  //�����꺯������Ҫ��ջ�еĲ����������η����׺���ʽ��

    calculate();

    printf( "%d\n", ans[1] );

    return 0;
}