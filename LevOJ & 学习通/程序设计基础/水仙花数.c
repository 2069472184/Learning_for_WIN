#include<stdio.h>

int main()

{

    int i,m,n,p;

    for(i=100;i<1000;i++)

   {

        m=i%10; //��λ

        n=i/100%10;  //��λ

        p=i%100/10;  //ʮλ

    if(i==m*m*m+n*n*n+p*p*p)

        printf("%d\n",i);

    }

    return 0;

}