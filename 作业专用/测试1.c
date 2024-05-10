#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
  int i=0,j=0;

  char key[50];        //key���λ��50λ�����ǻ���ֻȡ16λ

  char plaintext[100];   //����

  char pGroup[10][10]; //������
 
  char keyGroup[16][17]; //������

  void encryption(char pGroup[10][10],char keyGroup[16][17]); 

  void decryption(char pGroup[10][10],char keyGroup[16][17]);
 
  void generateKey(char  key[50],char keyGroup[16][17]);

  void makeGroup(char plaintext[100],char pGroup[10][10]);
 
  memset(plaintext,0,sizeof(plaintext)/sizeof(char));

  memset(key,0,sizeof(key)/sizeof(char));

  memset(pGroup,0,sizeof(pGroup) / sizeof(char) );

  memset(keyGroup,0,sizeof(keyGroup) / sizeof(char) );

  printf("����������\n");

  scanf("%s",plaintext);

  printf("����������\n");

  scanf(" %s",key);

  generateKey(key,keyGroup);

  makeGroup(plaintext, pGroup);

   encryption(pGroup,keyGroup);

   printf("����Ϊ��\n");

   for(i=0;i<10;i++)
   {
	   printf("%s",pGroup[i]);
   }

   printf("\n");

   decryption(pGroup,keyGroup);

	printf("����Ϊ��\n");

   for(i=0;i<10;i++)
   {
	   printf("%s",pGroup[i]);
   }

   printf("\n");

  return 0;
}

void makeGroup(char plaintext[100],char pGroup[10][10])
{
    int i=0,j=0;

	int g_num=0;   //������
    
	int b_num=0;

	int n_num=0;

	int pLength=0;

	pLength = strlen(plaintext); 
    
	b_num = pLength % 8;

	n_num = 8 - b_num;

	g_num = pLength / 8 ;

	if(b_num != 0)
	{
		g_num += 1;

		for(i=0;i<n_num;i++)
		{
			plaintext[strlen(plaintext)] = n_num + '0';
		}
	}

	plaintext[strlen(plaintext)]='\0';
   
    for(i=0;i<g_num;i++)
	{
	   for(j=0;j<8;j++)
	   {
		  pGroup[i][j] = plaintext[i*8+j];

	   }

	  pGroup[i][8]='\0';

	}

}


void generateKey(char  key[50],char keyGroup[16][17])
{
	int i=0,j=0;  

	char keyadd[50]; //��������

	memset(keyadd,0,50);

	char last;

    while(strlen(key)<16)  //16*8=128bit
	{

		strcpy(keyadd,key);

		strcat (key,keyadd);
	}

   for(i=0;i<16;i++)    //��ȡ��ͬ��key��ѭ����λһbit
   {

	 last = key[15];   //���һ��
	  
	 for(j=15;j>0;j--)     //����strlen��ȡ�����ˣ���Ϊ�ǹ̶���
	 {
		   key[j]=key[j-1];
	 }
    
	 key[0] = last;     

	 memcpy(keyGroup[i],key,16*sizeof(char)); //һά������ӳ�Ϊ��ά���� 
      
     keyGroup[i][16]='\0';     //���ľ���
	  
   }
 
}

void f(char p[10],char key[17],int flag,int time)    //��Կ�̶�16λ
{

    int i=0,j=0;

	char LE[4];  //���ø�����ռ䣬����Ĵ�С�ǹ̶���

	char RE[4];

	char LE1[4];

	char RE1[4];
	
	strncpy(LE,p,4);

	strncpy(RE,p+4,4);

	strncpy(LE1,RE,4); 
    
	for(i=0;i<4;i++)
	{
		RE1[i] = RE[i]^key[4*i]^LE[i];  //��λ���
	}
   
	if(flag==0 && time == 15 || flag == 1 && time == 0)     //���⴦�����򣩼��ܵ�16�κͽ��ܵ�16��
	{
		for(i=0;i<8;i++)
		{
		   if(i<4)
		   {
			 p[i]=RE1[i];
		   }
		   else
		   {
			 p[i]=LE1[i-4];
		   }
			
		}

	}
    else //��������
	{
		for(i=0;i<8;i++)
		{
		   if(i<4)
		   {
			 p[i]=LE1[i];
		   }
		   else
		   {

			 p[i]=RE1[i-4];

		   }
			
		}
	}
}


void loop(char pGroup[10],int flag,char keyGroup[16][17])         //flag=0Ϊ���ܣ�flag=1Ϊ����
{
	int i = 0;
	
   if(flag==0)
   {
 		 for(i=0;i<16;i++)
		 {
			f(pGroup,keyGroup[i],flag,i);  //ѭ��16�Σ����ܣ���Կ����
		 }

		 pGroup[8]='\0';
   }

  else	
  {

		for(i=15;i>-1;i--)
		{
			f(pGroup,keyGroup[i],flag,i);  //ѭ��16��,���ܣ���Կ������
		}

		pGroup[8]='\0';

  }

}


void encryption(char pGroup[10][10],char keyGroup[16][17])    //����
{   

     int i=0;

     int numP;

	numP = sizeof(pGroup[0]) / sizeof(char);  //������������

	for(i=0;i<numP;i++)
	{ 	
		loop(pGroup[i],0,keyGroup); //�������	
	} 

}

void decryption(char pGroup[10][10],char keyGroup[16][17])  //����
{
   int i=0;

   int numP = 0;

   numP = sizeof(pGroup[0]) / sizeof(char);  //һά���鳤��,�Լ�֪��������8
   
   for(i=0;i<numP;i++)
   {
	  loop(pGroup[i],1,keyGroup);
   }
}



