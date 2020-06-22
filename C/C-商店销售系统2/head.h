#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct T{
    int id;
    char name[100]; // 商品名称
    int money;      // 商品价格
    int have_number;      // 商品有数量
    int sale_number;      // 商品剩余数量
}commodity;

commodity commodity_list[100];
int head=1;
int i,j;

// 展示仓库的商品
void display_have();
// 展示销售的商品
void display_sale();
// 添加仓库的商品
void add_have();
// 添加销售的商品
void add_sale();
// 出售商品
void buyed();

void add_have(){
    commodity t;
    printf("你想添加的商品的名称是:");
    scanf("%s",t.name);
    printf("你想添加的商品的价格是:");
    scanf("%d",&t.money);
    printf("你想添加的商品的数量是:");
    scanf("%d",&t.have_number);
    t.sale_number = 0;
    t.id = head;
    commodity_list[head-1] = t;
    head++;
}

void add_sale(){
    char c;
    char t[100];
    int data;
    printf("你想添加的商品是否在库存表中有?");
    scanf("%c",&c);
    scanf("%c",&c);
    if(c == 'y'){
        printf("你要录入的商品名称为?");
        scanf("%s",t);
        for(i=0;i<head-1;i++){
            for(j=0;j<strlen(t);j++){
                if(t[j] != commodity_list[i].name[j]) return;
            }
            printf("你要将该商品的销售量改为?");
            scanf("%d",&data);
            commodity_list[i].sale_number = data;
        }
    }else{
        commodity tdata;
        printf("你想添加的商品的名称是:");
        scanf("%s",tdata.name);
        printf("你想添加的商品的价格是:");
        scanf("%d",&tdata.money);
        printf("你想添加的商品的销售量为:");
        scanf("%d",&tdata.sale_number);
        tdata.have_number = 0;
        tdata.id = head;
        commodity_list[head-1] = tdata;
        head++;
    }
}

// 展示仓库的商品
void display_have(){
    printf("库存表的商品如下:\n");
    for(i=0;i<head-1;i++){
        printf("---------------%d----------------\n",(i+1));
        printf("商品的ID是:%d\n",commodity_list[i].id);
        printf("商品的名称是:%s\n",commodity_list[i].name);
        printf("商品的价格是:%d\n",commodity_list[i].money);
        printf("商品的库存量是:%d\n",commodity_list[i].have_number);
    }
}

// 展示销售表的商品
void display_sale(){
    printf("销售表的商品如下:\n");
    for(i=0;i<head-1;i++){
        printf("---------------%d----------------\n",(i+1));
        printf("商品的ID是:%d\n",commodity_list[i].id);
        printf("商品的名称是:%s\n",commodity_list[i].name);
        printf("商品的价格是:%d\n",commodity_list[i].money);
        printf("商品的销售量是:%d\n",commodity_list[i].sale_number);
    }
}

// 出售商品
void buyed(){
    int id;
    printf("出售的商品的ID是:");
    scanf("%d",&id);
    if( commodity_list[id-1].have_number > 0 ){
        commodity_list[id-1].have_number -= 1;
        commodity_list[id-1].sale_number += 1;
        printf("出售成功!\n");
        return;
    }
    printf("出售失败!\n");
}
