#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000 // 仓库中商品最多的种类

// 商品结构体
typedef struct goods_t{
    int count;
    double money;
    char * name;
}goods;

goods storage[N];
goods sales_table[N];
int storage_total = 0;
int salse_total;

void add_storage(){
    if(storage_total == N){
        printf("仓库种类已满,添加失败!");
    }else{
        goods t_goods;
        printf("请输入要添加到库存表商品的名称:");
        scanf("%s",&t_goods.name);
        printf("请输入要添加到库存表商品的价格:");
        scanf("%lf",&t_goods.money);
        printf("请输入要添加到库存表商品的数量:");
        scanf("%d",&t_goods.count);
        storage[storage_total] = t_goods;
        storage_total++;
    }
}

void add_sales(){
    goods t_goods;
    printf("请输入要添加到销售表商品的名称:");
    scanf("%s",&t_goods.name);
    printf("请输入要添加到销售表商品的价格:");
    scanf("%lf",&t_goods.money);
    printf("请输入要添加到销售表商品的数量:");
    scanf("%d",&t_goods.count);
    sales_table[salse_total] = t_goods;
    salse_total++;
}

void show_storage(){
    if(storage_total == 0){
        printf("你的[库存表]中空空如也,请先[录入点商品]吧!");
    }else{
        int i;
        for(i = 0; i < storage_total; i++){
            printf("\n----库存表中第%d件商品----\n",i+1);
            printf("商品名称:%s\n",&storage[i].name);
            printf("商品价格:%.2f\n",storage[i].money);
            printf("商品库存:%d\n",storage[i].count);
        }
    }
}

void show_sales(){
    if(salse_total == 0){
        printf("你的[销售表]中空空如也,请先[出售商品]或者[添加商品]吧!");
    }else{
        int i;
        for(i = 0; i < salse_total; i++){
            printf("\n----销售表中第%d件商品----\n",i+1);
            printf("商品名称:%s\n",&sales_table[i].name);
            printf("商品价格:%.2f\n",sales_table[i].money);
            printf("商品销售量:%d\n",sales_table[i].count);
        }
    }
}

void sell(){
    char * name;
    int i,j;
    if(storage_total == 0){
        printf("你的仓库空空。。请录入商品后在来!");
        return;
    }
    printf("请输入你要出售商品的名字:");
    scanf("%s",name);
    for(i = 0; i < storage_total; i++){
        if(strcmp(name,(char *)(&storage[i].name)) == 0){
        	if(storage[i].count >=0 ){
        		storage[i].count--;
			}else{
				printf("该商品没有库存了，请先进货！");
				return;
			}
            for(j = 0; j < salse_total; j++){
                if(strcmp(name, (char *)(&sales_table[j].name))  == 0  ){
                    sales_table[i].count++;
                    break;
                }
            }
            if(j == salse_total){
                sales_table[salse_total].name = storage[i].name;
                sales_table[salse_total].count = 1;
                sales_table[salse_total].money = storage[i].money;
                salse_total++;
            }
            break;
        }
    }
    if(i == storage_total){
        printf("你输入的商品在仓库中没有，可能是名字有误，请核对后在尝试!");
    }
}

int main(){
    int choice = 0;
    while(1) {
        printf("\n\n\n");
        printf("****************天天商店的商品销售系统***************\n");
        printf("\n");
        printf("    1.库存表数据录入\n");
        printf("    2.销售表数据录入 \n");
        printf("    3.出售商品 \n");
        printf("    4.库存表查询\n");
        printf("    5.销售表查询\n");
        printf("    6.退出\n");
        printf("\n");
        printf("*****************************************************\n");
        printf("please choice(1-6):");
        scanf("%d",&choice);
        switch(choice){
            case 1:   add_storage();  break;
            case 2:   add_sales();    break;
            case 3:   sell();         break;
            case 4:   show_storage(); break;
            case 5:   show_sales();   break;
            case 6:   exit(0);
            break;
        }
    }
    return 0;
}

