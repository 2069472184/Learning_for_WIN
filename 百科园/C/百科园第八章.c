//�������1
/*����������,����fun�Ĺ�����:���β�std��ָ�ṹ����������������ߵ�������Ϊ����ֵ����,����main�����������
ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�ĺ�������������д�����ɱ��ʽ����䡣 
�������: */
#include  <stdio.h>
typedef struct
{
  char name[10];
  int age;
}STD;
STD fun(STD std[],int n)
{
  STD max;
  int i;
/**********FILL**********/
  max=std[0];
  for(i=1;i<n;i++){
/**********FILL**********/
   	if(max.age<std[i].age)
		max=std[i];}
  return max;
}
int main()
{ 
  STD std[5]={"aaa",17,"bbb",16,"ccc",18,"eee",15};
  STD max;
  max=fun(std,5);
  printf("\nThe result is: \n ");
/**********FILL**********/
  printf("\nName :%s,Age :%d\n",max.name,max.age);
return 0;
}

//�������2
/*��Ա�ļ�¼�ɱ�źͳ����ꡢ�¡������,N����Ա�����������������д���ṹ������std��,�ұ��Ψһ��
����fun�Ĺ�����:�ҳ�ָ�������Ա������,��Ϊ����ֵ����,�����������,��ָ����Ų�����,���������еı��Ϊ�մ��� 
ע��:����Դ����������¡� 
����Ķ�main���������������е��κ�����,���ں���fun�ĺ�������������д�����ɱ��ʽ����䡣 
�������: */
#include <stdio.h>
#include <string.h>
#define N 8
typedef struct
{
  	char num[10];
	int year,month,day;
}STU;
/**********FILL**********/
STU fun(STU *std,char *num)
{
	int i;
	STU a={"",9999,99,99};
	for(i=0;i<=N;i++)
/**********FILL**********/
		if(strcmp(std[i].num,num)==0)
/**********FILL**********/
			return (std[i]);
	return a;
}
int main()
{
	STU std[N]={{"11111",1984,2,15},{"22222",1983,9,21},{"33333",1984,9,1},{"44444",1983,7,15},
{"55555",1984,9,28},{"666666",1983,11,14},{"77777",1983,6,22},{"88888",1984,8,18}};
	STU p;
	char n[10]="666666";
	p=fun(std,n);
	if(p.num[0]==0)
	{
		printf("\nNot found!\n");
	}
	else
	{
		printf("\nSucceed!\n");
		printf("%s   %d-%d-%d\n",p.num,p.year,p.month,p.day);
	}
return 0;
}

//�������3
/*�벹�亯��fun,�ú����Ĺ�����:����һ����ͷ���ĵ�������������ļ�"out70.dat"����Ļ��,
������ֵΪ��Ӧ���±�,����Ľ������������ļ�����Ϊ�������롣ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�ĺ�������������д�����ɱ��ʽ����䡣
�������: */
#include <stdio.h>
#include <stdlib.h>
typedef struct ss
{
	 int data;
	 struct ss *next;
}NODE;
void fun(int n,char*filename)
{
	 NODE *h,*p,*s;
	 FILE *pf;
	 int i;
	 h=p=(NODE *)malloc(sizeof(NODE));
	 h->data=0;
	 for(i=1;i<n;i++)
	 {
		s=(NODE *)malloc (sizeof (NODE));
/**********FILL**********/
		s->data=i;
/**********FILL**********/
		p->next=s;
/**********FILL**********/
		p=p->next;
	 }
	 p->next=NULL;
	 if((pf=fopen(filename,"w"))==NULL)
	 {
		printf("Can not open out98.dat!");
		exit(0);
	 }
	 p=h;
	 fprintf(pf,"\n***THE LIST***\n");
	 printf("\n***THE LIST***\n");
	 while(p)
	 {
		fprintf(pf,"%3d",p->data);
		printf("%3d",p->data);
		if(p->next!=NULL)
		{
			fprintf(pf,"->");
			printf("->");
		}
		p=p->next;
	 }
	 fprintf(pf,"\n");
	 printf("\n");
	 fclose(pf);
	 p=h;
	 while(p)
	 {
		s=p;
		p=p->next;
		free(s);
	 }
}
int main()
{
	 char *filename="out98.dat";
	 int n;
	 printf("\nInput n:");
	 scanf("%d",&n);
	 fun(n,filename);
return 0;
}

//�������4
/*��֪ѧ���ļ�¼��ѧ�ź�ѧϰ�ɼ�����,N��ѧ���������Ѵ���a�ṹ����,��������Ĺ������ҳ��ɼ���͵�ѧ����¼,
ͨ���βη�����������ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�ĺ�������������д�����ɱ��ʽ����䡣 �������: */
#include <stdio.h>
#include <string.h>
#define N 10
typedef struct ss  /*����ṹ��*/
{ char num[10]; 
  int s;
} STU;
void fun(STU a[], STU *s)
{
/**********FILL**********/
  STU h;
   int i;
   h=a[0];
   for(i=1;i<N;i++)
	if(a[i].s<h.s)
/**********FILL**********/
		h=a[i];
/**********FILL**********/
   *s=h;
}
int main()
{ 
STU a[N]={{ "A01",81},{ "A02",89},
{ "A03",66},{ "A04",87},{ "A05",77},
{ "A06",90},{ "A07",79},{ "A08",61},
{ "A09",80},{ "A10",71}},m;
  int i;
  printf("*****The original data*****");
  for(i=0;i<N;i++) 
     printf("No=%s Mark=%d\n", a[i].num,a[i].s);
  fun(a,&m);
printf("*****THE RESULT*****\n");
  printf("The lowest :%s, %d\n",m.num,m.s);
return 0;
}

//�������1
/*��n��ѧ����ÿ��ѧ�������ݰ���ѧ�ţ�C���Գ�����ƿγ̵�ƽʱ�ɼ�����ĩ���Գɼ������������������������У�ʵ�ְ�ƽʱ�ɼ�ռ30%����ĩ�ɼ�ռ70%���������ɼ���
�������ɼ�ƽ�������ϵ�ѧ���ĵȼ�ȷ��Ϊ"��������"��ͬʱ����Щͬѧ�Ķ�Ӧ��Ϣ����ڽṹ������h�У�����ͨ����������ֵ�õ���
����Ķ�main���������������е��κ�����,���ں���fun�Ļ�������ע�����֮����������д��������䡣*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define  N 100
typedef  struct
{ char num[10];/*ѧ��*/
  int s1;/*��ĩ�ɼ�*/
  int s2;/*ƽʱ�ɼ�*/
  float sum; /*����*/
  char level[10]; /*�ȼ�*/
} STU;
int fun (STU a[],int n,STU h[])
{
/************Begin************/
	int i, j = 0;
	float sum = 0;
	for ( i=0; i<n; i++ ) {
		a[i].sum = a[i].s1*0.7 + a[i].s2*0.3;
		sum += a[i].sum;
	}
	sum /= 10;
	for ( i=0; i<n; i++ ) {
		if ( a[i].sum > sum ) {
      strcpy( a[i].level,"��������" ); 
      h[j] = a[i];
			j++;
		}
	}
	return j;
 /************End**************/
}
int main()
{
  STU s[N]={{"GA05",85,76},{"GA03",76,90},{"GA02",69,90},{"GA04",85,56},{"GA01",91,95},
				{"GA07",72,80},{"GA08",64,45},  {"GA06",87,98},{"GA015",85,86},{"GA013",91,97}},h[N];
  int i,k,n=10; 
  FILE *out,*in;
  k=fun(s,n,h);
  printf("There are :\n");
  for(i=0;i<k;i++)
    printf("%s %d %d %.2f %s\n",h[i].num,h[i].s1,h[i].s2,h[i].sum,h[i].level);
  /******************************/
  in=fopen("in70.dat","r");
  out=fopen("out70.dat","w");
  i=0;
  while(!feof(in))
  {
  	fscanf(in,"%s %d %d",s[i].num,&s[i].s1,&s[i].s2);
  	i++;
  }
  n=i;
  k=fun(s,n,h);
  for(i=0;i<k;i++)
    fprintf(out,"%s %d %d %.2f %s\n",h[i].num,h[i].s1,h[i].s2,h[i].sum,h[i].level);
  fclose(out);
  fclose(in);
  /******************************/
  system("pause");
  return 0;
}

//�������2
/*ѧ���ļ�¼��ѧ�źͳɼ���ɣ�N��ѧ�������������������з���ṹ������s��,���д����fun�����Ĺ����ǣ�
�ѷ�����ߵ�ѧ�����ݷ���b��ָ��������,ע�⣺������ߵ�ѧ�����ܲ�ֹһ�����������ط�����ߵ�ѧ���������� 
ע��: ����Դ���������¡� 
����Ķ�������main�����������е��κ����ݣ����ں���fun�Ļ����������� 
���д��������䡣 
����Դ���� */
#include <stdio.h> 
#define N 16 
typedef struct 
{	 char num[10]; 
int s; 
} STREC; 
int fun( STREC *a, STREC *b ) 
{
   /**************Begin*************/
	int i, j = 0;
	STREC max={0,0};
	for ( i=0; i<N; i++ ) {
		if ( a[i].s > max.s ) {
			max = a[i];
		}
	}
	for ( i=0; i<N; i++ ) {
		if ( a[i].s == max.s ) {
			b[j++] = a[i];
		}
	}
	return j;
   /*************End***************/
    
} 
int main() 
{ STREC s[N]={{"GA05",85},{"GA03",76},{"GA02",69},{"GA04",85}, 
  {"GA01",91},{"GA07",72},{"GA08",64},{"GA06",87}, 
  {"GA015",85},{"GA013",91},{"GA012",64},{"GA014",91}, 
  {"GA011",77},{"GA017",64},{"GA018",64},{"GA016",72}}; 
STREC h[N]; 
   int i,n;
   FILE *out,*in;
   n=fun(s,h);
   printf("The %d highest score :\n",n);
   for(i=0;i<n; i++)
     printf("%s  %4d\n",h[i].num,h[i].s);
   printf("\n");
   out = fopen("out03.dat","w");
   in=fopen("in03.dat","r");
   i=0;
   while(!feof(in))
   {
      fscanf(in,"%s %d\n",h[i].num,&h[i].s);
      i++;
   }
   n=fun(s,h);
   for(i=0;i<n; i++)
   {
     fprintf(out, "%s %d\n",h[i].num,h[i].s);
   }
   fclose(in);
   fclose(out);
return 0;
} 

//�������3
/*��n��ѧ����ÿ��ѧ�������ݰ���ѧ�ţ�C���Գ�����ƿγ̵�ƽʱ�ɼ�����ĩ���Գɼ����������������������У�Ҫ��ƽʱ�ɼ�ռ30%����ĩ�ɼ�ռ70%���������ɼ���
���������ɼ�����90�֣��Ҹ��ڵ���80�ֵ�ͬѧ�ĵȼ�ȷ��Ϊ"����"��������Щͬѧ�Ķ�Ӧ��Ϣ����ڽṹ������h�У�����ͨ����������ֵ�õ��������Ӧ����Ϣ��
����Ķ�main���������������е��κ�����,���ں���fun�Ļ�������ע�����֮����������д��������䡣*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define  N 100
typedef  struct
{ char num[10];/*ѧ��*/
  int s1;/*��ĩ�ɼ�*/
  int s2;/*ƽʱ�ɼ�*/
  float sum; /*����*/
  char level[10]; /*�ȼ�*/
} STU;
int fun (STU a[],int n,STU h[])
{
/************Begin************/
  int i, j = 0;
  for ( i=0; i<n; i++ ) {
	a[i].sum = a[i].s1*0.7 + a[i].s2*0.3;
	if ( a[i].sum >= 80.0 && a[i].sum < 90.0 ) {
		strcpy( a[i].level, "����" );
		h[j++] = a[i];
	}
  }
  return j;
 /************End**************/
}
int main()
{
  STU s[N]={{"GA05",85,76},{"GA03",76,90},{"GA02",69,90},{"GA04",85,56},{"GA01",91,95},
				{"GA07",72,80},{"GA08",64,45},  {"GA06",87,98},{"GA015",85,86},{"GA013",91,97}},h[N];
  int i,k,n=10; 
  FILE *out,*in;
  k=fun(s,n,h);
  printf("There are :\n");
  for(i=0;i<k;i++)
    printf("%s %d %d %.2f %s\n",h[i].num,h[i].s1,h[i].s2,h[i].sum,h[i].level);
  /******************************/
  in=fopen("in68.dat","r");
  out=fopen("out68.dat","w");
  i=0;
  while(!feof(in))
  {
  	fscanf(in,"%s %d %d",s[i].num,&s[i].s1,&s[i].s2);
  	i++;
  }
  n=i;
  k=fun(s,n,h);
  for(i=0;i<k;i++)
    fprintf(out,"%s %d %d %.2f %s\n",h[i].num,h[i].s1,h[i].s2,h[i].sum,h[i].level);
  fclose(out);
  fclose(in);
  /******************************/
  system("pause");
  return 0;
}

//�������4
/*ѧ���ļ�¼��ѧ�źͳɼ����,N��ѧ�������������������з���ṹ������s��,���д����fun,
���Ĺ�����:��ָ��������Χ�ڵ�ѧ�����ݷ���b��ָ��������,������Χ�ڵ�ѧ�������ɺ���ֵ���ء�
����,����ķ�����60��69,��Ӧ���ѷ�����60��69��ѧ�����ݽ������,����60�ֺ�69�ֵ�ѧ�����ݡ�
�������а�60����low��,��69����heigh�С�ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣
�������: */
#include <stdio.h>
#define  N  16
typedef  struct
{ char num[10];
  int  s ;
}STREC;
int  fun (STREC *a, STREC *b, int l, int h )
{
/************Begin*************/
	int i, j = 0;
	for ( i=0; i<N; i++ ) {
		if ( a[i].s >= l && a[i].s <= h ) {
			b[j++] = a[i];
		}
	}
	return j;
/************End************/
}

int main ()
{
  FILE *wf,*in;
  STREC  s[N]={{ "GA005",85},{"GA003",76},{"GA002",69},{"GA004",85},
  {"GA001",96},{"GA007",72},{"GA008",64},{"GA006",87},
  {"GA015",85},{"GA013",94},{"GA012",64},{"GA014",91},
  {"GA011",90},{"GA017",64},{"GA018",64},{"GA016",72}};
  STREC h[N],tt; 
  int i, j,n, low, heigh, t;
  printf("Enter 2 integer number low & heigh: ");
  scanf("%d%d",&low,&heigh);
  if(heigh<low) 
    {t=heigh;heigh=low; low=t;}
  n=fun(s,h,low, heigh);
  printf("The student 's data between %d--%d:\n ",low, heigh);
  for(i=0;i<n;i++)
     printf("%s %4d\n ",h[i].num, h[i].s);    /*���ָ��������Χ�ڵ�ѧ����¼*/
  printf("\n ");
/******************************/
 in=fopen("in26.dat","r");
 i=0;
 while(!feof(in))
 {
     fscanf(in,"%s %d\n",s[i].num,&s[i].s);
     i++;
  }
  n=fun(s,h,80,98);
  for(i=0;i<n-1;i++)          /*������80��98֮���ѧ����¼�������ӵ͵�������*/
     for(j=i+1;j<n;j++)
        if(h[i].s>h[j].s) 
          {tt=h[i];h[i]=h[j];h[j]=tt;}
  wf=fopen("out26.dat","w");
  for(i=0;i<n;i++)
     fprintf(wf, "%s %4d\n",h[i].num, h[i].s);
  fclose(in);
  fclose(wf);
/*****************************/
return 0;
}

//�������5
/*��n��ѧ����ÿ��ѧ�������ݰ���ѧ�ţ�C���Գ�����ƿγ̵�ƽʱ�ɼ�����ĩ���Գɼ����������������������У�Ҫ��ƽʱ�ɼ�ռ30%����ĩ�ɼ�ռ70%���������ɼ���
���������ɼ�����60�ֵ�ͬѧ�ĵȼ�ȷ��Ϊ"������"������ͬѧΪ"����"���������Ӧ����Ϣ��
����Ķ�main���������������е��κ�����,���ں���fun�Ļ�������ע�����֮����������д��������䡣*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define  N 100
typedef  struct
{ char num[10];/*ѧ��*/
  int s1;/*��ĩ�ɼ�*/
  int s2;/*ƽʱ�ɼ�*/
  float sum; /*����*/
  char level[10]; /*�ȼ�*/
} STU;
void fun (STU a[],int n)
{
/************Begin************/
	int i, j;
	for ( i=0; i<n; i++ ) {
		a[i].sum = a[i].s1*0.7 + a[i].s2*0.3;
		if ( a[i].sum < 60 ) {
			strcpy( a[i].level, "������" );
		} else {
			strcpy( a[i].level, "����" );
		}
	} 
 /************End**************/
}
int main()
{
  STU s[N]={{"GA05",85,76},{"GA03",76,90},{"GA02",69,90},{"GA04",85,56},{"GA01",91,95},
				{"GA07",72,80},{"GA08",64,45},  {"GA06",87,98},{"GA015",85,86},{"GA013",91,97}};
  int i,n=10; 
  FILE *out,*in;
  fun(s,n);
  printf("There are :\n");
  for(i=0;i<n;i++)
    printf("%s %d %d %.2f %s\n",s[i].num,s[i].s1,s[i].s2,s[i].sum,s[i].level);
  /******************************/
  in=fopen("in67.dat","r");
  out=fopen("out67.dat","w");
  i=0;
  while(!feof(in))
  {
  	fscanf(in,"%s %d %d",s[i].num,&s[i].s1,&s[i].s2);
  	i++;
  }
  n=i;
  fun(s,n);
  for(i=0;i<n;i++)
    fprintf(out,"%s %d %d %.2f %s\n",s[i].num,s[i].s1,s[i].s2,s[i].sum,s[i].level);
  fclose(out);
  fclose(in);
  /******************************/
  system("pause");
  return 0;
}

//�������6
/*ѧ���ļ�¼��ѧ��������ѧ�š����ġ���ѧ��Ӣ�����ųɼ����,N��ѧ�������������������з���ṹ������s��,
���д����fun,�书����:�������ܷ���͵�ѧ�����ݷ���h��ָ�������С�ע��:������͵�ѧ�����ܲ�ֹһ��,
�������ط�����͵�ѧ���������� ע��:����Դ����������¡�
����Ķ�main���������������е��κ�����,���ں���fun�Ļ���������������д��������䡣�������:*/
#include <stdio.h>
# define  N 6
typedef  struct
{ 
	char name[10];
	long num;
	int s1;
	int s2;
	int s3;
	int s;
} STREC;
int fun (STREC *a,STREC *b,int m)
{
  /***********Begin*************/
	int i, j = 0, min = 300;
	for ( i=0; i<N; i++ ) {
		a[i].s = a[i].s1 + a[i].s2 + a[i].s3;
		if ( min > a[i].s ) {
			min = a[i].s;
		}
	}
	for ( i=0; i<N; i++ ) {
		if ( a[i].s == min ) {
			b[j++] = a[i];
		}
	}
	return j;
  /**********End***************/
}
int main()
{
  STREC s[100]={{"GA01",1,80,56,87},{"GA03",3,76,56,54},{"GA02",2,69,63,54},{"GA04",4,85,98,90},{"GA05",5,91,94,95},{"GA06",6,72,80,87}};
  STREC h[100]; 
  int i,n,m;  
  FILE *out,*in;
  n=fun(s,h,N);
  printf("The %d lowest score:\n",n);
  for(i=0;i<n;i++)
    printf("%s %4d\n",h[i].name,h[i].s);
  printf("\n");
  /******************************/
  in=fopen("in53.dat","r");
  out=fopen("out53.dat","w");
  fscanf(in,"%d\n",&m);
  for(i=0;i<m;i++)
    fscanf(in,"%s %ld %d %d %d\n",s[i].name,&s[i].num,&s[i].s1,&s[i].s2,&s[i].s3);
  n=fun(s,h,m);
  fprintf(out,"%d\n",n);
  for(i=0;i<n;i++)
  	fprintf(out,"%s %d\n",h[i].name,h[i].s);
  fclose(in);
  fclose(out);
  /******************************/
  return 0;
}

//����Ĵ�1
/*���и��������еĺ���Creatlink�Ĺ�����:������ͷ�ڵ�ĵ�������,��Ϊ���ڵ�������0��m-1��ֵ�� 
���������Creatlink�еĴ���,ʹ���ܵó���ȷ�Ľ���� 
ע��:��Ҫ�Ķ�main����,�������л�ɾ��,Ҳ���ø��ĳ���Ľṹ�� 
�������: */
#include <stdio.h>
#include <stdlib.h>
typedef struct aa
{ int data;
  struct aa *next;
} NODE;

NODE *Creatlink(int n, int m)
{ NODE *h=NULL,*p,*s;
  int i;
  s=(NODE *)malloc(sizeof(NODE));
  h=s;
/**********ERROR**********/
  p=s;
  for(i=1;i<n;i++)
    { s=(NODE *) malloc(sizeof(NODE));
/**********ERROR**********/
      s->data=rand()%m; 
      s->next=p->next;p->next=s;  p=p->next;
    }
  s->next=NULL;
/**********ERROR**********/
  return h;
}
void outlink(NODE *h)
{ NODE  *p;
  p=h->next;
  printf("\n The LIST :\n\n HEAD");
  while(p)
    { printf("->%d",p->data); 
      p=p->next;}
  printf("\n");
}
int main()
{ NODE *head;
  head=Creatlink(8,22);
  outlink(head);
return 0;
}

//����Ĵ�2
/*���и���������,����fun�Ĺ�����:��N��ѧ����ѧϰ�ɼ�,���Ӹߵ��͵�˳���ҳ�ǰm(m<=10)��ѧ��,
������Щѧ�����ݴ����һ����̬����������洢����,�˴洢�����׵�ַ��Ϊ����ֵ���ء� 
����������еĴ���,ʹ���ܵó���ȷ�Ľ���� 
ע��:��Ҫ�Ķ�main����,�������л�ɾ��,Ҳ���ø��ĳ���Ľṹ�� 
�������:*/ 
#include <stdlib.h>
#include  <string.h>
#include  <stdio.h>
#include  <malloc.h>
#define N 10
typedef struct ss
   { char num[10];
     int s;
   } STU;
STU *fun(STU a[], int m)
{ STU b[N],*t;
  int i, j,k;
/**********ERROR**********/
  t=(STU *)calloc(m,sizeof(STU));
  for(i=0;i<N;i++) b[i]=a[i];
  for(k=0;k<m;k++)
     { for (i=j=0;i<N;i++)
          if(b[i].s>b[j].s) j=i;
/**********ERROR**********/
      strcpy(t[k].num,b[j].num);
      t[k].s=b[j].s;
      b[j].s=0;
     }
return t;
}
void outresult(STU a[],FILE *pf)
{ int i;
  for(i=0;i<N;i++)
  fprintf(pf, "No=%s Mark=%d\n ",
a[i].num, a[i].s);
  fprintf(pf, "\n\n ");
}
int main()
{ STU a[N]={{ "A01 ",81},{ "A02 ",89},{ "A03 ",66},{ "A04 ",87},{ "A05 ",77},
			{ "A06 ",90},{ "A07 ",79},{ "A08 ",61},{ "A09 ",80},{ "A10 ",71}};
  STU *pOrder;
  int i, m;
  printf("*****THE RESULT*****\n");
  outresult(a,stdout);
  printf("\nGive the number of the students who have better score: ");
  scanf("%d",&m);
  while(m>10)
       { printf("\nGive the number of the students who have better score: ");
  scanf("%d",&m);
}
  pOrder=fun(a,m);
  printf("***** THE RESULT*****\n");
  printf("The top :\n");
  for(i=0;i<m;i++)
     printf("%s  %d\n",pOrder[i].num, pOrder[i].s);
  free(pOrder);
return 0;
}  

//����Ĵ�3
/*���и�������Ĺ�����:����һ����ͷ�ڵ�ĵ�������,�����������Ϊ���ڵ�������ֵ��
����fun�������������������ڵ�(������ͷ�ڵ�)�������е����ֵ,������Ϊ����ֵ���ء�
���������fun�еĴ���,ʹ���ܵó���ȷ�Ľ����
ע��:��Ҫ�Ķ�main����,�������л�ɾ��,Ҳ���ø��ĳ���Ľṹ��
�������: */
#include <stdio.h>
#include <stdlib.h>
typedef struct aa
{ int data;
  struct aa *next;
} NODE;
int fun (NODE *h)
{ int max=-1;
  NODE *p;
/**********ERROR**********/
  p=h->next;
  while(p)
       { if(p->data>max)
             max=p->data;
/**********ERROR**********/
      p=p->next;
       }
  return max;
}
void outresult(int s, FILE *pf)
{ fprintf(pf, "\nThe max in link :%d\n",s);
}
NODE *creatlink(int n, int m)
{ NODE *h,*p,*s;
  int i;
  h=p=(NODE *)malloc(sizeof(NODE));
  h->data=9999;
  for(i=1;i<=n;i++)
    { s=(NODE *) malloc(sizeof(NODE));
      s->data=rand()%m; s->next=p->next;
      p->next=s;  p=p->next;
    }
  p->next=NULL;
  return h;
}
void outlink(NODE *h,FILE *pf)
{ NODE  *p;
  p=h->next;
  fprintf(pf, "\n The LIST :\n\n HEAD");
  while(p)
    { 
fprintf(pf, "->%d",p->data); 
  p=p->next;}
  fprintf(pf, "\n");
}
int main()
{ NODE *head; int m;
  head=creatlink(12,100);
  outlink(head,stdout);
  m=fun(head);
  printf("\nThe RESULT :\n"); 
  outresult(m,stdout);
return 0;
}

