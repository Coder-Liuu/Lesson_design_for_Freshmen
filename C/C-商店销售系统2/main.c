#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    int choose = 0;
    while(choose !=6){
        printf("--------------------商品销售系统--------------------\n");
        printf("(1) 添加仓库的商品\n");
        printf("(2) 添加销售的商品\n");
        printf("(3) 展示仓库的商品\n");
        printf("(4) 展示销售的商品\n");
        printf("(5) 出售商品\n");
        printf("(0) 退出系统\n");
        printf("请输入你的选择:\n");
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


