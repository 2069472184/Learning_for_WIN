#include<stdio.h>
int main(){
    int a,b,c;
    int flag=1;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF){
        if(a+b>c&&a+c>b&&b+c>a){
            if(a==b&&b==c){
                printf("regular triangle\n");
                flag=0;
            }else if(a==b||a==c||b==c){
                printf("isosceles triangle\n");
                flag=0;
            }else if(a*a+b*b-c*c==0||a*a+c*c-b*b==0||b*b+c*c-a*a==0){
                printf("right triangle\n");
                flag=0;
            }else if(flag){
                printf("triangle\n");
            }        
        }else{
            printf("not a triangle\n");
        }
        flag=1;
    }
    return 0;
}
