//�������1
/*
����fun()�Ǹ���������n�����������еĺ� s=1+1/22+1/333+......+1/nn...nn
������n=5��s=1.04870057 ,ע��:����Դ����������¡� 
����Ķ�main���������������е��κ�����,���ں���fun��ע�����֮����������д��������䡣
*/ 
#include<stdio.h>
#include<stdlib.h>
double fun(int n)
{
	/*********Begin*********/
	int i=0,j=0,box=0;
	double s=0.0,num=0.0;
	for(i=1;i<n+1;i++){
		box=i;
		num=0;
		for(j=1;j<i+1;j++){
			num+=box;
			box*=10;
		}
		s+=1.0/num;
	}
	return s;
	/*********End*********/
}
int main()
{
	FILE *in,*out;
	int n,i;
	double s;
	scanf("%d",&n);
	s=fun(n);
	printf("%.8lf\n",s);
	/**************/
	in=fopen("in96.dat","r");
	out=fopen("out96.dat","w");
	while(!feof(in))
	{
		fscanf(in,"%d",&n);
		fprintf(out,"%.8lf\n",fun(n));
	}
	fclose(in);
	fclose(out);
       system("pause");
	return 0;
}

//�������2
/*
����fun�Ǹ�������n���������ĸΪn����(����n)���������ɵ����еĺ� ������10�������-0.138095��
Ҫ����fun������ע�����֮���д�����������ֲ�����ɾ��䡣
*/
#include<stdio.h>
#include<stdlib.h>
double fun(int n)
{
/*************************Begin*********************/
	int i=0,j=0,count=1;
	double s=0.0;
	for(i=1;i<n+1;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				break;
			}
		}
		if(j==i){
			s+=((count%2==0)?-1:1)*((double)count/(double)i);
			count++;
		}
	}
	return s;
/**************************End**********************/
}
int main()
{
	int n;
	double s,x;
	FILE *in,*out;
	printf("����n:");
	scanf("%d",&n);
	s=fun(n);
	printf("%lf\n",s);
	/*****************/
	in=fopen("in2019-2-1-2.dat","r");
	out=fopen("out2019-2-1-2.dat","w");
	while(!feof(in))
	{
		fscanf(in,"%d",&n);
		fprintf(out,"%lf\n",fun(n));
	}
            fclose(in);
            fclose(out);
	system("pause");
	return 0;	
}

//�������3
   /*���д����fun,�书����:�����д���1С������m�ķ���������xx��ָ������,�������ĸ���ͨ��k���ء� 
    ����,����17,��Ӧ���4 6 8 9 10 12 14 15 16�� 
ע��:����Դ����������¡� 
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣 
    �������: */
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int fun(int m, int xx[])
{
    /***************Begin************/
	int k=0,i=0,j=0;
	for(i=1;i<m+1;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				xx[k]=i;
				k++;
				break;
			}
		}
	}
	return k;
    /*************** End ************/
}
int main()
{
  FILE *wf,*in;
  int m, n,k, zz[100];
  printf("\nPlease enter an integer number between 10 and 100: ");
  scanf("%d",&n);
  m=fun(n,zz);
  printf("\n\nThere are %d non-prime numbers less than %d: ",m,n);
  for(n=0;n<m;n++)
    printf("%4d\n",zz[n]);
  in=fopen("in01.dat","r");
  wf=fopen("out01.dat","w");
  fscanf(in,"%d",&k);
  m=fun(k,zz);
  for(n=0;n<m;n++)
    fprintf(wf,"%d\n",zz[n]);
  fclose(in);
  fclose(wf);
  return 0;
}

//�������4
#include<stdio.h>
#include<stdlib.h>
double fun(int n)
{
/**********************Begin*********************/
	int i=0;
	double s=0.5,num=0.5;
	for(i=2;i<n+1;i++){
		num*=(2.0*i-1)/(2.0*i);
		s+=((i%2==0)?-1:1)*num;
	}
	return s;
/**********************End*********************/
}
int main()
{
	int n;
	double s;
	FILE *in,*out;
	printf("����n:");
	scanf("%d",&n);
	s=fun(n);
	printf("%lf\n",s);
	/***********************/
	in=fopen("in2019-2-3-2.dat","r");
	out=fopen("out2019-2-3-2.dat","w");
	while(!feof(in))
	{
		fscanf(in,"%d",&n);
		fprintf(out,"%lf\n",fun(n));
	}
            fclose(in);
            fclose(out);
	system("pause");
	return 0;
}
