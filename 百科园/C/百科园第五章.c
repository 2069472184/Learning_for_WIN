//�������1
/*���дһ������void fun(char ss[]),�书����:���ַ���ss�������±�Ϊ����λ���ϵ���ĸת��Ϊ��д(����λ���ϲ�����ĸ,��ת��)��
����,������abc4EFg,��Ӧ���aBc4EFg�� ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣
�������:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void fun ( char ss[])
{
     /***************Begin************/
	int i=0;
	for(i=0;i<strlen(ss);i++){
		if(i%2&&ss[i]>='a'&&ss[i]<='z'){
			ss[i]-=32;
		}
	}
     /*************** End ************/
}

int main()
{
char tt[100];
FILE *out,*in;
printf("Please enter an character string within 50 characters:\n");
gets(tt);
printf("\n\nAfter changing,the string\n%s",tt);
fun(tt);
printf("\nbecomes\n %s",tt);
/******************************/
in=fopen("in14.dat","r");
out=fopen("out14.dat","w");
fgets(tt,16,in);
strcat(tt,"After changing the string");
fun(tt);
fprintf(out,"%s",tt);
fclose(in);
fclose(out);
/******************************/
 system("pause");
 return 0;
}

//�������2
/*��дһ������fun,���Ĺ�����:ʵ�������ַ���������(��ʹ�ÿ⺯��strcat),����p2��ָ���ַ������ӵ�p1��ָ���ַ�����
����,�ֱ��������������ַ���: 
FirstString 
SecondString 
��������:FirstStringSecondString
ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣 
�������:*/
#include<stdio.h>
#include<stdlib.h>
void fun(char p1[],char p2[])
{
     /***************Begin************/
  int i,j;
  for(i=0;p1[i];i++);
  for(j=0;p2[j];j++){
    p1[i++]=p2[j];
  }
  p1[i]='\0';
     /*************** End ************/
}
int main()
{
  FILE *wf,*in;
  char s1[80],s2[40];
  char  p1[80]="FirstString",p2[40]="SecondString";
  printf("Enter s1 and s2:\n") ;
  scanf("%s%s",s1,s2);
  printf("s1=%s\n",s1);
  printf("s2=%s\n",s2);
  printf("Invoke fun(s1,s2):\n");
  fun(s1,s2);
  printf("After invoking:\n");
  printf("%s\n",s1);
/******************************/
  in=fopen("in16.dat","r");
  wf=fopen("out16.dat","w");
  fscanf(in,"%s %s",p1,p2);
  fun(p1,p2);
  fprintf(wf,"%s",p1);
  fclose(in);
  fclose(wf);
/*****************************/
 system("pause");
  return 0;
}

//�������3
/*���дһ������fun,���Ĺ�����:��һ�������ַ���ת��Ϊһ������(���õ���C�����ṩ�Ľ��ַ���תΪ�����ĺ���)��
����,�������ַ���"-1234",��������ת��Ϊ����ֵ-1234��
ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣
�������:*/
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
long fun(char p[])
{
     /***************Begin************/
	long n=0,i=0;
	int flag=1;
	if(p[i]=='-'){
		i++;
		flag=-1;
	}else if(p[i]=='+'){
		i++;
	}
	while(p[i]){
		n=n*10+p[i]-'0';    //�˴����ַ�ת��Ϊ���ͱ���
		i++;
	}
	return n*flag;
     /*************** End ************/
}
int main()
{
  FILE *wf,*in;
  char s[10];
  long n;
  printf("Enter a string:\n");
  gets(s);
  n=fun(s);
  printf("%ld\n",n);
/******************************/
  in=fopen("in13.dat","r");
  wf=fopen("out13.dat","w");
  fscanf(in,"%s",s);
  fprintf (wf,"%ld",fun(s));
  fclose(wf);
  fclose(in);
/*****************************/
  system("pause");
return 0;
}

//�������4
/*��д����int fun(int lim, int aa[MAX]),�ú����Ĺ��������С�ڻ����lim����������������aa������,
�ú�������������������ĸ����� 
ע��:����Դ����������¡� 
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣 
�������: */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int fun(int lim, int aa[MAX])
{
/**********Begin**********/
	int i=0,j=0,count=0;
	for(i=2;i<=lim;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				break;
			}
		}
		if(j==i){
			aa[count]=i;
			count++;
		}
	}
	return count;
/**********End**********/  
}
int main()
{
  FILE *wf,*in;
  int limit,i,k,sum;
  int aa[MAX];
  printf("����һ������");
  scanf("%d",&limit);
  sum=fun(limit,aa);        
  for(i=0;i<sum;i++)
     {
      if(i%10==0&&i!=0)    /*ÿ�����10����*/
         printf("\n ");
      printf("%5d ",aa[i]);
    }
/******************************/
  wf=fopen("2.out","w");
  in=fopen("2.dat","r");
  fscanf(in,"%d",&k);
  sum=fun(k,aa);        
  for(i=0;i<sum;i++)
      fprintf(wf,"%d\n",aa[i]);
  fclose(wf);
  fclose(in);
/*****************************/
system("pause");
return 0;
}

//�������5
/*���д����fun,�����Ĺ�����:�����ά�����ܱ�Ԫ��֮��,��Ϊ����ֵ���ء���ά�����е�ֵ���������и��衣 
����,����ά�����е�ֵΪ 
    1  3  5  7  9 
    2  9  9  9  4 
    6  9  9  9  8 
    1  3  5  7  0 
����ֵΪ61�� 
ע��:����Դ����������¡� 
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣 
    �������:*/
#include<stdio.h>
#include<stdlib.h>
#define  M  4
#define  N  5
int fun( int a [M][N])
{
     /***************Begin************/
	int sum=0;
	int i=0,j=0;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(i==0||j==0||i==M-1||j==N-1){
				sum+=a[i][j];
			}
		}
	}
	return sum;
     /*************** End ************/
}
void main()
{
  FILE *wf,*in;
  int aa[M][N]={{1,3,5,7,9},{2,9,9,9,4},{6,9,9,9,8},{1,3,5,7,10}};
  int i, j, y;
  printf ("The original data is :\n ");
  for(i=0; i<M;i++)
     {for (j=0; j<N;j++) 
          printf("%6d ",aa[i][j]);
      printf("\n ");
     }
  y=fun(aa);
  printf("\nThe sun: %d\n ",y);
  printf("\n ");
/******************************/
 in=fopen("in10.dat","r");
  wf=fopen("out10.dat","w");
  for(i=0;i<M;i++)
    for(j=0;j<N;j++)
      fscanf(in,"%d",&aa[i][j]);
  y=fun(aa);
  fprintf (wf,"%d",y);
  fclose(wf);
  fclose(in);
/*****************************/
system("pause");
} 

//�������6
/*���д����fun,�书����:�����д���1С�ڵ�������m�ķ���������xx��ָ������,�������ĸ���ͨ��k���ء�
����,����17,��Ӧ���4 6 8 9 10 12 14 15 16��
ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣
�������:*/ 
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int fun(int m, int xx[])
{
/**********Begin*******/
	int i=0,count=0,j=0;
	for(i=2;i<=m;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				xx[count]=i;
				count++;
				break;
			}
		}
	}
	return count;
/*********End*********/  
}
int main()
{
  FILE *wf,*in;
  int m, n, zz[100];
  printf("\nPlease enter an integer number between 10 and 100: ");
  scanf("%d",&n);
  m=fun(n,zz);
  printf("\n\nThere are %d non-prime numbers less than %d: ",m,n);
  for(n=0;n<m;n++)
    printf("\n %4d",zz[n]);
/******************************/
  wf=fopen("1.out","w");
  in=fopen("1.in","r");
  fscanf(in,"%d",&n);
  m=fun(n,zz);
  for(n=0;n<m;n++)
    fprintf(wf,"%d\n",zz[n]);
  fclose(wf);
 fclose(in);
/*****************************/
system("pause");
return 0;
}

//�������7
/*    ��д����ʵ�־���3��3�У���ת�ã������л�������
���磬��������ľ���  
         100  200  300
         400  500  600
         700  800  900
���������  
         100  400  700
         200  500  800
         300  600  900
    ע�⣺ ����Դ��������ļ�program.c�С�
    ����Ķ�������main�����������е��κ����ݣ����ں���fun�Ļ��������������д��������䡣*/
#include <stdio.h>
#include<stdlib.h>
void fun(int array[3][3])
{
    /**********  Begin  **********/
	int i=0,j=0,box;
	for(i=0;i<3;i++){
		for(j=i;j<3;j++){
			box=array[i][j];
			array[i][j]=array[j][i];
			array[j][i]=box;
		}
	}
    /**********   End  ***********/
}

void NONO( )
{/* ���ڴ˺����ڴ��ļ�������������ݣ����� fun ������
    ������ݣ��ر��ļ��� */
    int i,j;
    FILE  *wf ,*in;
    int array[3][3]={{100,200,300},
                     {400,500,600},
                     {700,800,900}};
    in=fopen("a11.in","r");
    for(i=0;i<3;i++)
    {   for(j=0;j<3;j++)
	fscanf(in,"%d",&array[i][j]);
     }
    wf = fopen("a11.out", "w") ;
    fun(array);
    for(i=0;i<3;i++)
    {   for(j=0;j<3;j++)
	fprintf(wf,"%7d\n",array[i][j]);
     }

    fclose(wf) ;
    fclose(in);
}

int main()
{
    int i,j;
    int array[3][3]={{100,200,300},
                     {400,500,600},
                     {700,800,900}};
     for (i=0;i<3;i++)
    {    for (j=0;j<3;j++)
         printf("%7d",array[i][j]);
         printf("\n");
    }
    fun(array);
    printf("Converted array:\n");
    for(i=0;i<3;i++)
    {   for(j=0;j<3;j++)
        printf("%7d",array[i][j]);
        printf("\n");
    }
 NONO( );
 system("pause");
 return 0;
}

//�������8
/*���д����fun,�书����:���㲢�����������(����Ϊn)��,ÿ��������Ԫ�ص�ƽ��ֵ��ƽ����֮�͡� 
����,�����������е�9��Ԫ������Ϊ12.0��34.0��4.0��23.0��34.0��45.0��18.0��3.0��11.0,�����ӦΪs=35.951014�� 
ע��:����Դ����������¡� ����Ķ�main���������������е��κ�����,���ں���fun�Ļ����ŵ�ע�����֮������������д��������䡣 �������:*/ 
#include  <stdio.h>
#include  <math.h>
#include<stdlib.h>
double fun(double x[],int n)
{
/************Begin**************/	
	int i=0;
	double average=0.0,sum=0.0;
	for(i=0;i<n-1;i++){
		average=(x[i]+x[i+1])/2;
		sum+=sqrt(average);
	}
	return sum;
/************End**************/
}
int main()
{double s,a[100]={12.0,34.0,4.0,23.0,34.0,45.0,18.0,3.0,11.0};
 int i,n;
 FILE *out,*in;
 printf("\nThe original data is : ");
 for(i=0;i<9;i++)
	printf("%6.1f",a[i]);
 printf("\n\n"); 
 s=fun(a,9);
 printf("s=%lf\n\n",s);
 /******************************/
 in=fopen("in48.dat","r");
 out=fopen("out48.dat","w");
 fscanf(in,"%d",&n);
 for(i=0;i<n;i++)
	 fscanf(in,"%lf",&a[i]);
 s=fun(a,n);
 fprintf(out,"%lf",s);
 fclose(out);
 fclose(in);
 /******************************/
 system("pause");
 return 0;
}

//�������1
/*�벹�亯��fun(char s[]),�ú����Ĺ�����:���ַ����е��������á�
����,�ַ�����ԭ�е��ַ���Ϊabcde,����øú�����,���е�����Ϊedcba��
ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�ĺ�������������д�����ɱ��ʽ����䡣
�������: */
#include <string.h>
#include <stdio.h>
#define N 81
void fun(char s[])
{
	 int i,n=strlen(s)-1;
	 char t;
/**********FILL**********/
	 for(i=0;i<n;i++,n--)  //��ͷһ�����м���£
	 {
    	t=s[i];
/**********FILL**********/
	  	s[i]=s[n]; 
/**********FILL**********/
	  	s[n]=t;  
	 }
}

int main()
{
	 char a[N];
	 printf("Enter a string:");
	 gets(a);
	 printf("The  original string is:");
	 puts(a);
	 fun(a);
	 printf("\n");
	 printf("The string after modified:");
	 puts(a);
return 0;
}

//�������2
/*
�������Ĺ����ǽ�һ�����������д洢��N������ѭ�����ƻ�ѭ������m�Ρ������и�Ԫ�صĳ�ʼֵΪ1��2��3��4��5��6��7��8��
����fun�Ĺ����ǽ��β�������ǰnԪ��ֵ��ѭ����λm�Σ��β�k��ʾ��λ����k=0��ʾѭ�����ƣ�k=1��ʾѭ�����ơ�
m=3��k=0ʱ�����6��7��8��1��2��3��4��5
m=3��k=1ʱ�����4��5��6��7��8��1��2��3
ע�⣺����ע�����������������д�����ɱ��ʽ�����,�������ֲ�Ҫ�Ķ���
*/
#include<stdio.h>
#define N 8
void fun(int a[],int n,int m,int k)
{
	int i,temp;
	if (m<0)return;
/**********FILL**********/
	while(m>0)
	{
		if(!k)
		{
			temp=a[n-1];
			for(i=n-1;i>0;i--)
			{
             /**********FILL**********/
			  a[i]=a[i-1];
			} 
			a[0]=temp;
		}
		else
		{
			temp=a[0];
			for(i=1;i<n;i++)
			  a[i-1]=a[i];			
      /**********FILL**********/ 
			  a[i-1]=temp;
		}
		m--;
	}
}
int main()
{
	int a[N]={1,2,3,4,5,6,7,8},m,i,k;
	printf("Input m:\n");
	scanf("%d",&m);
	printf("Input k:\n");
	scanf("%d",&k);	
    /**********FILL**********/ 
	fun(a,N,m,k);
	printf("Result:\n");
	for(i=0;i<N;i++)
	  printf("%4d",a[i]);
	return 0;
}

//�������6
/*�벹�亯��fun,�ú����Ĺ�����:��һ������ת�����ַ���,�����򱣴����ַ�����str�С�
����,��n=13572468ʱ,str="86427531"��
ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�ĺ�������������д�����ɱ��ʽ����䡣
�������:*/
#include <stdlib.h>
#include <stdio.h>
#define N 80
char str[N];
void fun(long int n)
{
	 int i=0;
/**********FILL**********/
	 while(n)
	 {
/**********FILL**********/
		str[i]=n%10+'0';   //������ת��Ϊ�ַ�
		n/=10;
		i++;
	 }
/**********FILL**********/
	  str[i]='\0';
}
int main()
{
	 long int n=13572468;
	 printf("*** the origial data ***\n");
	 printf("n=%ld",n);
	 fun(n);
	 printf("\n%s",str);
return 0;
}

//����Ĵ�3
/*���и���������,����fun�Ĺ�����:���������������ʹ������,�����������a[0]�е����Ե������������ a[1] �е����Ե��� 
����������еĴ���,ʹ���ܵó���ȷ�Ľ���� 
ע��:��Ҫ�Ķ�main����,�������л�ɾ��,Ҳ���ø��ĳ���Ľṹ�� 
    �������:*/
#include<stdio.h>
#define  N   20
/**********ERROR**********/
void fun(int a[],int n)
{
 int  i,  m, t, k;
 for(i=0; i<n;i++)
   {
/**********ERROR**********/
    m=i;
    for(k=i+1; k<n; k++)
      if(a[k]>a[m])
         m=k;
    t=a[i];
    a[i]=a[m];
    a[m]=t;
   }
}
int main()
{ 
  int b[N]={11,5,12,0,3,6,9,7,10,8},n=10,i;
  for(i=0; i<n; i++)  
    printf("%d ",b[i]);
  printf("\n");
  fun(b,n);
  for(i=0; i<n; i++)  
    printf("%d ", b[i]);
  printf("\n");

return 0;
}
