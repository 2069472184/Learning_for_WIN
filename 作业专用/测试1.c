#include <stdio.h>

int main ()
{
    int flag = 1;
    while (flag)
    {
        char tem[25];  // ������ַ����洢��tem��
        int idx = 0;

        gets(tem);

        while (tem[idx]) idx++;
        if (tem[idx - 1] == 'E') flag = 0;

        /*
        ��������
        */
    }

    return 0;
}