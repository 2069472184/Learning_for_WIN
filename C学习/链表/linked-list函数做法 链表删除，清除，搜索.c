#include<stdio.h>
#include"node.h"
#include<stdlib.h>

/* typedef struct _node {
    int value;
    struct _node *next;
} Node; */

typedef struct _list
{
    Node * head;    //�˴�headΪָ��ָ���ָ��
} List;

void *add(List* pList, int number)   
{
    //add to the linked-list
    Node *p=(Node*)malloc(sizeof(Node));    //�����µ�����飬���Ǵ�ʱ��δ��ʹ�ã�ֻ�������������嵥�����ڵģ���Ҫ���õ�ʱ��ͱ�����
    p->value = number;
    p->next = NULL;

    //find the last
    Node *last = pList->head;
    if ( last ) {     //NULL��->����Ч�ģ���last->head��head=NULLʱ����Ч�ģ�����Ҫ���������Ƿ�Ϊ������
        while( last->next ) {    //����n������鸳ֵ��n>1��
            last = last->next;     //����һ�������ΪNULLʱ��last����ͣ����һ����number���������
        }
        //attach
        last->next = p;
    } else {
        pList->head = p;   //��p��ֵ��head��ͬʱ����һ������飨����ʱlast��ָ�Ľṹ�壩��ֵ���������֮��last->next����ΪNULL
    }    
}

void print(List *pList)
{
    Node *p;
    //����ı���
    for( p=pList->head; p; p=p->next){  
        printf("%d\t",p->value);
    }
    printf("\n");
}

int main ( int argc, char const *argv[] ) 
{
    //����һ������ͷ
    List list;           
    list.head = NULL;
    int number;
    do {
        scanf("%d", &number);
        if(number!=-1){
            add(&list, number);
        }
    } while ( number!=-1 );

    //��������
    print( &list );

    //����Ĳ���
    scanf("%d",&number);
    Node* p;
    int isfound=0;
    for( p=list.head; p; p=p->next){
        if(p->value == number){
            printf("�ҵ���\n");
            isfound = 1;
            break;
        }
    }
    if(!isfound){
        printf("û�ҵ�\n");
    }
    
    //�����ɾ��
    Node *q;
    for( q = NULL, p=list.head; p; q=p, p=p->next){
        if(p->value == number){
            if( q ){
                q->next = p->next;
            } else {
                list.head = list.head->next;  //  list.head = p->next
            }
            free(p);
            break;
        }
    }

    print( &list );

    //��������
    for( p=list.head; p; p=q){
        q = p->next;
        free(p);
    }

    return 0;
}