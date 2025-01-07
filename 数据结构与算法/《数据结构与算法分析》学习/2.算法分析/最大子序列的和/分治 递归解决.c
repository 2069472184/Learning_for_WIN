//�˷���ʱ�临�Ӷ�ΪO( N*logN ) > O( N )
#include<stdio.h>

#define N 10000

int a[N];

int Max ( int a, int b, int c )
{
    int result;
    if ( a > b ) {
        result = a;
    }
    if ( result < c ) {
        result = c;
    }
    return result;
}

int MaxSubSum ( const int *a, int left, int right )
{
    int MaxLeftSum, MaxRightSum;  //���Ұ�鲻�������ı߽����������к�
    int MaxLeftBorderSum = 0, MaxRightBorderSum = 0;  //���Ұ�������а������ı߽����������к�
    int LeftBorderSum, RightBorderSum;  //�м������
    int center, i;

    if ( left == right ) {
        if ( a[left] > 0 ) {
            return a[left];
        } else {
            return 0;
        }
    }

    center = ( left + right )/2;
    MaxLeftSum = MaxSubSum( a, left, center );
    MaxRightSum = MaxSubSum( a, center + 1, right );

    for ( i = center; i>=left; i-- ) {
        LeftBorderSum += a[i];
        if ( MaxLeftBorderSum < LeftBorderSum ) {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }

    for ( i = center + 1; i<=right; i++ ) {
        RightBorderSum += a[i];
        if ( MaxRightBorderSum < RightBorderSum ) {
            MaxRightBorderSum = RightBorderSum;
        }
    }

    return Max( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int main ( int argc, char *argv[] )
{
    int result, num, leftborder, rightborder, i = 0;

    scanf( "%d %d", &leftborder, &rightborder );
    scanf( "%d", &num );
    while ( num != 0 ) {
        a[i++] = num;
        scanf( "%d", &num );
    } 

    result = MaxSubSum( a, leftborder, rightborder );
    printf( "%d\n", result );
    return 0;
}