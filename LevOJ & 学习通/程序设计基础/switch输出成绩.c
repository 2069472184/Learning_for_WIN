#include<stdio.h>
int main(){
    int a;
    while(scanf("%d",&a)!=EOF){
        if(a<0||a>100){
            printf("����ɼ�����\n");
        }else{
            switch(a/10){
                case 10:
                case 9:printf("�ɼ�Ϊ��%d���ɼ��ȼ�����\n",a);break;
                case 8:printf("�ɼ�Ϊ��%d���ɼ��ȼ�����\n",a);break;
                case 7:printf("�ɼ�Ϊ��%d���ɼ��ȼ�����\n",a);break;
                case 6:printf("�ɼ�Ϊ��%d���ɼ��ȼ����ϸ�\n",a);break;
                case 5:
                case 4:
                case 3:
                case 2:
                case 1:
                case 0:printf("�ɼ�Ϊ��%d���ɼ��ȼ���������\n",a);break;
            }
        }
    }
    return 0;
}
