#include <stdio.h>
#define N 10  //���ǰʮ��
int main() {
    int arr[N][N];
    for (int i = 0;i < N;i++) {    
            arr[i][0] = 1;    // ���ȸ�ÿ�е�һ�������һ����ֵ1
            arr[i][i] = 1;
    }

    // �ӵ������𣬳���ÿ�е�1���⣬������Ϊ��һ�б��е���������һ��ǰһ�е���
    // �� a[i][j] = a[i-1][j] + a[i-1][j-1];
    for (int i = 2;i < N;i++) {
        for (int j = 1;j <= i - 1;j++) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < i + 1;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
