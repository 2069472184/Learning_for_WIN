//�������1
/*��������Ĺ�����:�ֱ�ͳ���ַ����д�д��ĸ��Сд��ĸ�ĸ����� 
����,���ַ���ss����:AaaaBBb123CCccccd,��������ӦΪ:upper=5,lower=9��
ע��:����Դ����������¡�
����Ķ������е���������,���ں�������������д�����ɱ��ʽ����䡣
�������: */
#include <stdlib.h>
#include <stdio.h>
void fun(char *s,int *a,int *b)
{
	 while(*s)
	 {
		if(*s>='A' && *s<='Z')
/**********FILL**********/
		(*a)++;
		if(*s>='a' && *s<='z')
/**********FILL**********/
		(*b)++;
	 	s++;
	 }
}

int main()
{
	 char s[100];
	 int upper=0,lower=0;
	 printf("\nPlease a string: ");
	 gets(s);
	 fun(s,&upper,&lower);
/**********FILL**********/
	 printf("\n upper=%d lower=%d\n",upper,lower);
return 0;
} 

//�������2
/*�벹��main����,�ú����Ĺ�����:�Ӽ������������ַ������ֱ𱣴����ַ�����str1��str2��,
���ַ���str2�滻�ַ���str1ǰ��������ַ���ע��:str2�ĳ��Ȳ�����str1,������Ҫ�������롣
����,�������str1="abced",str2="fk",�����"fkced"�� 
ע��:����Դ����������¡� 
����Ķ�main���������������е��κ�����,����main�����ĺ�������������д�����ɱ��ʽ����䡣
�������:*/
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
int main()
{
	 char str1[81],str2[81];
	 char *p1=str1,*p2=str2;
	 do
	 {
		printf(" Input str1 \n");
		gets(str1);
		printf(" Input str2 \n");
		gets(str2);
/**********FILL**********/
	 }while(strlen(str1)<strlen(str2));
/**********FILL**********/
	 while(*p2)
		*p1++=*p2++;
	 printf(" Display str1 \n");
/**********FILL**********/
	 puts(str1);
return 0;
} 

//�������3
/*����������,����fun�Ĺ�����:���β�s��ָ�ַ����е�ÿ�������ַ�֮�����һ��*�š�
����,�β�s��ָ���ַ���Ϊ:def35adh3kjsdf7��ִ�н��Ϊ:def3*5*adh3*kjsdf7*��
ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�ĺ�������������д�����ɱ��ʽ����䡣
�������:*/
#include <stdio.h>
#include<stdlib.h>
void fun(char *s )
{
	 int i,j,n;
	 for(i=0;s[i]!='\0';i++)
/**********FILL**********/
	 if(s[i]>='0'&&s[i]<='9')
	{
		n=0;
/**********FILL**********/
		while(s[i+1+n]!='\0')
			n++;
		for(j=i+n+1;j>i;j--)
/**********FILL**********/
		s[j+1]=s[j];
		s[j+1]='*';
			i=i+1;
		}
}
int main()
{
	char s[60]="ba3a54cd23a";
	printf("\n the original string is: %s\n",s);
	fun(s);
	printf("\nthe result is: %s\n",s);
return 0;
}

//�������4
/*�벹�亯��fun,�ú����Ĺ�����:���ַ�������ǰ�˼���n��*��,�γ��´�,���Ҹ��ǡ�ע��:�ַ����ĳ��������Ϊ79��
ע��:����Դ����������¡�����Ķ�main���������������е��κ�����,���ں���fun�ĺ����������������ɱ��ʽ����䡣
�������: */
#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
void fun(char s[],int n)  
{
 char a[80],*p;
 int i;
/**********FILL**********/
 p=s;   
 for(i=0;i<n;i++)  a[i]= '*';
 do 
{
/**********FILL**********/
a[i]=*p++;
    i++;
/**********FILL**********/
 }while(*p!='\0');  //������*p!=0,*p
 a[i]=0;
 strcpy(s,a);
}
int main()
{
int n;char s[80];
printf("\nEnter a string: ");gets(s);
 printf("\nThe string:%s\n",s);
 printf("\nEnter n (number of*):");
 scanf("%d",&n);
 fun(s,n);
 printf("\nThe string after inster:%s\n",s);
 system("pause");
return 0;
}

//�������5
/*�벹��main����,�ú����Ĺ�����:�Ӽ������������ַ��ŵ�һ���ַ�������,�����س���ʱ��������,
����������ַ������е������ַ���
ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,����main�����ĺ�������������д�����ɱ��ʽ����䡣
�������:*/
#include <stdlib.h>
#include <stdio.h>
int main()
{
	 int i=0;
	 char s[81];
	 char *p=s;
	 printf(" Input a string \n");
	 for(i=0;i<80;i++)
	 {
		s[i]=getchar();
		if(s[i]=='\n')
/**********FILL**********/
		break;
	 }
/**********FILL**********/
	 s[i]='\0';
	 printf(" display the string \n");
	 while(*p!='\0')
/**********FILL**********/
		putchar(*p++);
return 0;
}

//�������1
/*���д����fun,�书����:��������λ����������a��b�ϲ��γ�һ����������c�С�
�ϲ��ķ�ʽ��:��a����ʮλ�͸�λ���η���c����ǧλ��ʮλ��,b����ʮλ�͸�λ���η���c���İ�λ�͸�λ�ϡ�
����,��a=45,b=12,���ø������,c=4152�� 
ע��:����Դ����������¡� 
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣
�������: */
#include <stdio.h>
#include <conio.h>
void fun(int a ,int b,long *c)
{
  /************Begin************/
	*c=0;
	*c+=b%10+10*(a%10)+100*(b/10)+1000*(a/10);
  /************End***************/
}
int main()
{
  int  a,b,i;  
  long c;
  FILE *out,*in;
  printf("Input a ,b: ");
  scanf("%d%d",&a,&b);
  fun(a,b,&c);
  printf("The result is :%ld\n",c);
  /******************************/
  in=fopen("in20.dat","r");
  out=fopen("out20.dat","w");
  for(i=10;i<20;i++)
  {
   fscanf(in,"%d %d",&a,&b);
	fun(a,b,&c);
	fprintf(out,"%d\n",c);
  }
fclose(out);
fclose(in);
/******************************/
return 0;
}

//�������2
/*���һ������fun(char *s),�ú����Ĺ����ǰ��ַ����е��������á�
����,�ַ�����ԭ�е��ַ���Ϊabcdefg,����øú�����,���е�����Ϊgfedcba��
ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣
�������:*/
#include <string.h>
#include <stdio.h>
#define N 81
void fun(char*s)
{
/************Begin*************/
	int i,j;
	char box;
	for(i=0;i<strlen(s)-1;i++){
		box=s[strlen(s)-1];
		for(j=strlen(s)-1;j>i;j--){
			s[j]=s[j-1];
		}	
		s[i]=box;
	}
/************End**************/
}
int main()
{
	 char a[N];
	 FILE *out,*in;
	 printf("Enter a string:");
	 gets(a);
	 printf("The  original string is:");
	 puts(a);
	 fun(a);
	 printf("\n");
	 printf("The string after modified:");
	 puts(a);
	 strcpy(a,"Hello World! This is a first C program!");
	 fun(a);
	 /******************************/
      in=fopen("in17.dat","r");
      fgets(a,81,in);
	 out=fopen("out17.dat","w");
        fun(a);
	 fprintf(out,"%s",a);
	 fclose(out);
       fclose(in);
	 /******************************/
      return 0;
}

//�������3
/*���д����fun,�ú����Ĺ�����:�ж��ַ����Ƿ�Ϊ����,������������1,�����������"YES",���򷵻�0,�����������"NO"��
������ָ˳���͵�����һ�����ַ���������,�ַ���LEVEL�ǻ���,���ַ���123312�Ͳ��ǻ��ġ�
ע��:����Դ����������¡�����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣
�������:*/
#include <stdio.h>
#define N 80
int fun(char str[])
{
    /***************Begin************/
	int count=0,j=0,flag=1,i;
	while(str[j]){
		count++;
		j++;
	}
	for(i=0;i<=count/2;i++){
		if(str[i]!=str[count-i-1]){
			flag=0;
			break;
		}
	}
	return flag;
    /*************** End ************/
}
int main()
{
	 char s[N];
	 FILE *out,*in;
         char test[][80]={"1234321","123421","123321","abcdCBA"};
	 int i;
	 printf("Enter a string : ");
	 gets(s);
	 printf("\n\n");
	 puts(s);
	 if(fun(s))
		printf("YES\n");
	 else
		printf("NO\n"); 
	 /************************************/
    in=fopen("in12.dat","r");
    for(i=0;i<4;i++)
    fscanf(in,"%s",test[i]);
	 out=fopen("out12.dat","w");
	 for(i=0;i<4;i++)
	 	if(fun(test[i]))
			fprintf(out,"YES\n");
		else
			fprintf(out,"NO\n");
    fclose(in);
	 fclose(out);
	 /************************************/
  return 0;
}

//�������4
/*���д����fun,�ú����Ĺ�����:ͳ��һ���ַ����е��ʵĸ���,��Ϊ����ֵ���ء�
һ���ַ�����������������,�涨���е�����Сд��ĸ���,����֮�������ɸ��ո����,һ�еĿ�ʼû�пո� 
ע��:����Դ����������¡� 
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣 
�������:*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define N 80
int fun(char *s)
{
 /************Begin*************/
	int count=1,i;
	for(i=0; i<strlen(s)-1; i++){
		if(s[i]==' '&&s[i+1]>='a'&&s[i+1]<='z'){
			count++;
		}
	}
	return count;
/*************End*************/
}
int main()
{ 
  FILE *wf,*in;
  char line[N]; 
  int num=0;
  printf("Enter a string:\n "); 
  gets(line);
  num=fun(line);
  printf("The number of word is:%d\n\n ",num);
/******************************/
 in=fopen("in19.dat","r");
  wf=fopen("out19.dat","w");
  fgets(line,81,in);
  fprintf(wf,"%d",fun(line));
  fclose(wf);
  fclose(in);
  system("pause");
/*****************************/
  return 0;
}

//�������5
/*�ٶ�������ַ�����ֻ������ĸ��*�š����д����fun,���Ĺ�����:���ַ����е�ǰ��*��ȫ��ɾ��,�м�ͺ����*�Ų�ɾ����
����,���ַ����е�����Ϊ****A*BC*DEF*G*******,ɾ����,�ַ����е�������Ӧ����A*BC*DEF*G*******��
ע��:����Դ����������¡� 
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣 
�������: */
#include <stdio.h>
#include<stdlib.h>
void  fun  (char *a)
{
/************Begin**************/
	int j=0,k,i=0;
	while(a[j]=='*'){
		j++;
	}
	k=j;
	while(a[k]!='\0'){
		a[i]=a[k];
		k++;
		i++;
	}
	a[i]='\0';
/************End*************/
}
int main()
{
  FILE *wf,*in;
  int i;
  char s[81],t[81]="****A*BC*DEF*G*******";
  printf("Enter a string :\n");
  gets(s);
  fun(s);
  printf("The string after deleted:\n");puts(s);
/******************************/
  in=fopen("in18.dat","r");
  wf=fopen("out18.dat","w");
  for(i=0;i<8;i++)
  {
	  fscanf(in,"%s",t);
	  fun(t);
      fprintf(wf,"%s\n",t);
  }
  fclose(in);
  fclose(wf);
  system("pause");
/*****************************/
 return 0;
}

//�������6
/*�ٶ�������ַ�����ֻ������ĸ��*�š����д����fun,���Ĺ�����:�����ַ���ǰ����*��֮��,����������*��ȫ��ɾ����
�ڱ�д����ʱ,����ʹ��C�����ṩ���ַ��������� 
����,���ַ����е�����Ϊ****A*BC*DEF*G*******,ɾ����,�ַ����е�������Ӧ����****ABCDEFG�� 
ע��:����Դ����������¡� 
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣 
�������: */
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
void  fun  (char *a)
{
/************Begin*************/
	int i=0,k;
	while(a[i]=='*'){
		i++;
	}
	k=i;
	while(a[i]!='\0'){
		if(a[i]!='*'){
			a[k++]=a[i];
		}
		i++;
	}
	a[k]='\0';
/************End**************/
}
int main()
{
  char s[81];
  FILE *in,*out;
  int i;
  printf("Enter a string :\n");
  gets(s);
  fun(s);
  printf("The string after deleted:\n");
  puts(s);
  /******************************/
  in=fopen("in21.dat","r");
  out=fopen("out21.dat","w");
  for(i=0;i<8;i++)
  {
	  fscanf(in,"%s",s);
	  fun(s);
      fprintf(out,"%s\n",s);
  }
  fclose(in);
  fclose(out);
  system("pause");
  /******************************/
  return 0;
}

//����Ĵ�1
/*�ٶ�������ַ�����ֻ������ĸ��*�š�����fun�Ĺ�����:���ַ����е�ǰ��*��ȫ��ɾ��,�м�ͺ����*�Ų�ɾ����
����,���ַ����е�����Ϊ****A*BC*DEF*G*******,ɾ����,�ַ����е�������Ӧ����A*BC*DEF*G*******��
ע��:�������л�ɾ��,Ҳ���ø��ĳ���Ľṹ��
�������:
*/
#include <stdio.h>
/**********ERROR**********/
void  fun(char *a)
{
    char *p=a;
/**********ERROR**********/
     while(*p=='*')
        p++; 
/**********ERROR**********/
    for(;*p!='\0';p++,a++)
        *a=*p;
/**********ERROR**********/
    *a='\0'; 
}
int main()
{
	char s[81];
	printf("Enter a string :\n");
	gets(s);
/**********ERROR**********/
	fun(s);
	printf("The string after deleted:\n");
	puts(s);
	return 0;
}

//����Ĵ�2
/*���и���������,����fun�Ĺ�����:����s��ָ�ַ����к���t��ָ�ַ�������Ŀ,����Ϊ����ֵ���ء� 
���������fun�еĴ�����ں��ߴ������ʵ������ݲ��Ѻ���ɾ��,ʹ���ܵó���ȷ�Ľ����
ע��:��Ҫ�Ķ�main����,�������л�ɾ��,Ҳ���ø��ĳ���Ľṹ��
�������:*/
#include  <stdlib.h>
#include  <string.h>
#include  <stdio.h>
#define N 80
int fun(char *s,char *t)
{ int n;
  char *p, *r;
  n=0;
  p=&s[0];
/**********ERROR**********/
  r=t;
  while(*p)
  { 
	if(*r==*p)
	{
		r++;
		if(*r=='\0')
		{	
			n++;
/**********ERROR**********/
			r=t;
		}
	}
  	p++;
  }
  return n;
}
int main()
{char a[N],b[N]; int m;
printf("\nPlease enter string a: ");
gets(a);
 printf("\nPlease enter substring b: ");
gets(b);
/**********ERROR**********/
 m=fun(a,b);
 m=printf("\nThe result is :m=%d\n",m);
return 0;
}

//����Ĵ�3
/*���и��������к���fun�Ĺ�����:�Ƚ����ַ���s�е��ַ��������ŵ�t����,Ȼ���s�е��ַ����������ӵ�t���ĺ��档
����,��s�е��ַ���ΪABCDEʱ,��t�е��ַ���ӦΪEDCBAABCDE��
����������еĴ���,ʹ���ܵó���ȷ�Ľ����
ע��:��Ҫ�Ķ�main����,�������л�ɾ��,Ҳ���ø��ĳ���Ľṹ��
�������: */
#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
void fun (char *s, char *t )
{
  int i,s1;
  s1=strlen(s);    
  for (i=0;i<s1;i++)
/**********ERROR**********/
      t[i]=s[s1-i-1];    
  for (i=0;i<s1;i++)
      t[s1+i]=s[i];
/**********ERROR**********/
  t[2*s1]='\0';
}
int main()
{char s[100], t[100];
  printf("\nPlease enter string s: "); 
  scanf("%s",s);
/**********ERROR**********/
  fun(s,t);
  printf ("The result is: %s\n",t);
return 0;
}

//����Ĵ�4
/*���и��������к���fun�Ĺ�����:������������ÿһλ��Ϊ������������ȡ��,����һ����������t�С���λ���ڸ�λ,��λ���ڵ�λ��
���統s�е���Ϊ87653142ʱ,t�е���Ϊ7531�� ���������fun�еĴ���,ʹ���ܵó���ȷ�Ľ���� 
ע��:��Ҫ�Ķ�main����,�������л�ɾ��,Ҳ���ø��ĳ���Ľṹ��  �������:*/
#include  <stdlib.h>
#include  <stdio.h>
void fun(long s,long *t)
{int d;
 long s1=1;
/**********ERROR**********/
 *t=0;
 while(s>0)
    { d=s%10;
/**********ERROR**********/
      if(d%2)
        {*t=d*s1+*t;
         s1*=10;
        }
    s/=10;
    }
}  
int main()
{
long s, t;
printf("\nPlease enter s: "); scanf("%ld",&s);
/**********ERROR**********/
 fun(s,&t);
 printf("The result is :%ld\n",t);
return 0;
}

//����Ĵ�5
/*���и���������,����fun�Ĺ�����:���ַ���str���ҳ�ASCII��ֵ�����ַ�,������ڵ�һ��λ����,
�������ַ�ǰ��ԭ�ַ����˳���ƶ�������,����fun����֮ǰ���ַ�������ABCDeFGH,���ú��ַ����е�����ΪeABCDFGH��
����������еĴ���,ʹ���ܵó���ȷ�Ľ����
ע��:��Ҫ�Ķ�main����,�������л�ɾ��,Ҳ���ø��ĳ���Ľṹ��
�������: */
#include <stdio.h>
/**********ERROR**********/
void fun(char *p)
{ char max, *q;int i=0;
  max=p[i];
  while (p[i]!=0)
       {if (max<=p[i])
          { 
/**********ERROR**********/
           q = p +i;max=p[i]; //�˴�qָ��������ǵõ����ASCII��ֵԪ�غ�һ��Ԫ�صĵ�ַ������֮��Ԫ�صĺ��ơ�
          }
        i++;
       }
/**********ERROR**********/
  while(q>p)
      {*q=*(q-1);
        q--;
       }
  p[0]=max;
}
int main()
{char str[80];
  printf("Enter a string: "); gets(str);
  printf("\nThe original string: "); 
puts(str);
  fun(str);
  printf("\nThe string after moving: ");
puts(str); printf("\n\n");
return 0;
}