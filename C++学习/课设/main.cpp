#include <iostream>

#include "./class/gen.h"
#include "./class/book.h"
#include "./class/disc.h"
#include "./class/drawing.h"
#include "operations.h"

int main ()
{
    while (true)  
    {
        Menu();
        ifbreak = false;

        std::cout << "��ѡ���Ӧ���ܣ�"; 
        std::cin >> operation;
        std::cout << std::endl;

        switch (operation)
        {
            case 0:
                std::cout << "�����˳���...���Ժ�" << std::endl;
                ifbreak = true;
                break;
            case 1:
                Add_Media();
                break;
            case 2:
                Update_Media();
                break;
            case 3:
                Search_Media();
                break;
            case 4:
                Show_Media();
                break;
            case 5:
                Delete_Media();
                break;
            case 6:
                Count_Media();
                break;
            case 7:
               	if (ifsave)
				{
					std::cout << "[      �Ѿ������һ�Σ��ٴα���ᵼ�²��������ظ�!     ]" << std::endl << std::endl;
					break;
				}
                else
				{
					Save_Media();
					ifsave = true;
					break;
				}    
                break;
            case 8:
                Read_Media();
                break;
            default:
                std::cout << "[          ���빦�ܲ��Ϸ�, ������0-8֮�����!          ]" << std::endl << std::endl;
                break;
        }

        if (ifbreak)
            if (!ifsave)
            {
                std::cout << "�������Ĳ�����δ����, ��ȷ���Ƿ��˳�? (��: Y; ����: N)" << std::endl << std::endl;
                char a;
                bool ifexit = false;

                while(true)
                {
                    std::cin >> a;
                    if (a == 'Y')
                    {   
                        ifexit = true;
                        break;
                    }
                    else if (a == 'N')
                    {
                        std::cout << std::endl;
                        break;
                    }
                    else std::cout << std::endl << "[                    ������'Y'��'N'                    ]" << std::endl << std::endl;
                }

                if (ifexit)
                {
                    std::cout << std::endl << "[                       �˳��ɹ�!                      ]" << std::endl << std::endl;
                    break;
                }
            }
            else
            {
                std::cout << std::endl << "[                       �˳��ɹ�!                      ]" << std::endl << std::endl;
                break;
            }
    }

    return 0;
}