#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    int choose = 0;
    while(choose !=6){
        printf("--------------------��Ʒ����ϵͳ--------------------\n");
        printf("(1) ��Ӳֿ����Ʒ\n");
        printf("(2) ������۵���Ʒ\n");
        printf("(3) չʾ�ֿ����Ʒ\n");
        printf("(4) չʾ���۵���Ʒ\n");
        printf("(5) ������Ʒ\n");
        printf("(0) �˳�ϵͳ\n");
        printf("���������ѡ��:\n");
        scanf("%d",&choose);
        switch(choose){
            case 1:add_have(); break;
            case 2:add_sale(); break;
            case 3:display_have(); break;
            case 4:display_sale(); break;
            case 5:buyed(); break;
            case 6:exit(0);
        }
    }
    return 0;
}

void display(){

}


