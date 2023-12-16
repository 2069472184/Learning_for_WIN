// ������
#include <string>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <sstream>

#define SIZE 100

using namespace std;

#include "./Class/Sight.h"
#include "./Functions/Add_path.h"
#include "./Functions/Add_sight.h"
#include "./Functions/Delete_sight.h"
#include "./Functions/Update_sight.h"
#include "./Functions/Search_sight.h"
#include "./Functions/Init_path.h"
#include "./Functions/Update_path.h"
#include "./Functions/Delete_path.h"
#include "./Algorithms/Floyd.h"
#include "./Algorithms/Show_all_paths.h"
#include "./Algorithms/Multi_Floyd.h"

map<pos, Sight> Sights_pos;                 // ������;�����Ϣ֮�佨������
unordered_map<string, Sight> Sights_name;   // �����ƺ;�����Ϣ֮�佨������
int Weight_for_cars[SIZE + 1][SIZE + 1];    // �洢�ڵ� i �� j �Ļ�������·Ȩ
int Weight_for_people[SIZE + 1][SIZE + 1];  // �洢�ڵ� i �� j �����е�·Ȩ

int main ()
{   
    // ��ʼ��·Ȩ����
    Init_path(Weight_for_cars, Weight_for_people);

    // �澰��
    Add_sight(Sights_pos, Sights_name);

    // // ����Ϣ
    // Upgrade_sight(Sights_pos, Sights_name);  

    // // ���Ҿ���
    // Search_sight(Sights_name);
    
    // ��·��
    Add_path(Weight_for_cars, Weight_for_people);

    // // չʾ���������·��
    // Show_all_paths(Sights_name, Weight_for_cars, Weight_for_people);

    // ��Դ���·
    Floyd(Sights_name, Weight_for_cars, Weight_for_people);

    // // ɾ��·��
    // Delete_path(Sights_name, Weight_for_cars, Weight_for_people);

    // // ���¶�Դ���·
    // Floyd(Sights_name, Weight_for_cars, Weight_for_people);

    // // ɾ������ 
    // Delete_sight(Sights_pos, Sights_name, Weight_for_cars, Weight_for_people);  

    // // ���¶�Դ���·
    // Floyd(Sights_name, Weight_for_cars, Weight_for_people);

    // // ����·Ȩ
    // Update_path(Sights_name, Weight_for_cars, Weight_for_people);

    // // ���¶�Դ���·
    // Floyd(Sights_name, Weight_for_cars, Weight_for_people);

    // �󾭹���ڵ�����·
    Mutli_Floyd(Sights_name, Weight_for_cars, Weight_for_people);

    return 0;
}

/*
1 2 001 ʳ�� �� ��
3 4 002 �ĵ�¥ �� ��
5 6 003 ����¥ �� ��
7 8 004 ����¥ �� ��

1 2 1 ��������
1 4 4 ��������
1 3 1 ��������
2 4 2 ��������
3 4 1 ��������
1 2 2 ���е�
1 4 3 ���е�
1 3 1 ���е�
2 4 4 ���е�
*/