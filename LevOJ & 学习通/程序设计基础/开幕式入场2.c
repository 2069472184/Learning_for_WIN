#include <stdio.h>
#include <string.h>
char *exchange(char *a,char *b);
int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        getchar();     //�ӻ���������������n��Ļس�
        int num[n], Temp, CHN;       //num[n]Ϊÿ�鿪ͷ����ţ�Temp��Ϊ�м������ڽ������
        char a[n][50], temp[50];     //a[n][50]�洢��������Ӻ����һ�����ţ�temp[50]��Ϊ�м����������以��˳��
        int i, j;

        //����ÿ��
        for(i=0; i<n; i++){
            scanf("%d", &num[i]);
            getchar();      //�ӻ�����������ź�Ŀո�
            gets(a[i]);     //���롰�������� �μ����� �������ޡ����ַ���
            if(a[i][0]=='C'&&a[i][1]=='h'&&a[i][2]=='i'&&a[i][3]=='n'&&a[i][4]=='a'&&a[i][5]==' '){
                CHN = i;
            }
        }

        //��Chinaһ������Ԫ�ط������
        strcpy(temp , a[CHN]);
        strcpy(a[CHN] , a[n-1]);
        strcpy(a[n-1] , temp);
        Temp = num[CHN];    
        num[CHN] = num[n-1];
        num[n-1] = Temp;

        //��ǰn-1���������
        memset(temp,0,sizeof(temp));   //��ʼ��temp[]���飬���ڿ�������
        for(i=0; i<n-2; i++){
            for(j=0; j<n-2-i; j++){
                if( strcmp(a[j] , a[j+1])>0 ){
                    strcpy(temp , a[j]);       //
                    strcpy(a[j] , a[j+1]);     //
                    strcpy(a[j+1] , temp);     //�����ַ�����
                    Temp = num[j];             //
                    num[j] = num[j+1];         //   
                    num[j+1] = Temp;           //
                }
            }
        }
        for(i=0; i<n; i++){
            printf("%d ", num[i]);    //������˳��������
            puts(a[i]);
        }
    }
    return 0;
}
