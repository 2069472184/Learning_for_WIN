#include<stdio.h>
int main(){
    const int number=10;   //�����С
    int x;
    int count[number];   //��������
    int i;

    for(i=0;i<10;i++){
        count[i]=0;      //��ʼ������
    }

    do{
        scanf("%d",&x);
        if(x>=0&&x<=9){
            count[x]++;
        }
    }while(x!=-1);
    
    for(i=0;i<number;i++){
        printf("%d:%d\n",i,count[i]);
    }
    return 0;
}