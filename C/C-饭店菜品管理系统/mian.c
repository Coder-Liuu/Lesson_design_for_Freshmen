#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 饭菜最多的种类
#define OK 1
#define NO 0 
// 声明一些函数 
void Buy_dish();
int show_Displaytable();
int show_Warehouses();
void add_Displaytable();
void add_Warehouse();
/* 饭菜数据类型  */
typedef struct Food{
	char * name;
    int count;
    double cost;
}food;
// 定义一下重要的数据类型。 
food Warehouse[999];
food Displaytable[999];
int Total1 = 0;  // 仓库中的饭菜种类 
int Total2;      // 销售过的饭菜的种类 
int i,j;
int main(){
    int User_chose = 0;
    while(1) {
        printf("你好啊！我是金必来饭店菜品管理系统的机器人！下面是我可以帮你完成的任务。\n");
        printf("1.厨房进货\n");
        printf("2.增加账单记录\n");
        printf("3.汇报厨房菜的数量\n");
        printf("4.查看账单\n");
        printf("5.给客人上菜\n");
        printf("0.退出\n");
        printf("\n");
        printf("请问老板想做些什么: ");
        scanf("%d",&User_chose);
        switch(User_chose){
            case 1:   add_Warehouse();  break;
            case 2:   add_Displaytable();    break;
            case 3:   show_Warehouses(); break;
            case 4:   show_Displaytable();   break;
            case 5:   Buy_dish();         break;
            case 0:   exit(0);
            break;
        }
        printf("\n\n\n");
    }
    return 0;
}
int show_Warehouses(){
    for(i = 0; i < Total1; i++){
        printf("\n----厨房中第%d件饭菜----\n",i+1);
        printf("饭菜名  称:%s\n",&Warehouse[i].name);
        printf("饭菜单  价:%.2f\n",Warehouse[i].cost);
        printf("饭菜剩余量:%d\n",Warehouse[i].count);
    }
    return OK;
}

int show_Displaytable(){
    for(i = 0; i < Total2; i++){
        printf("\n----账单中第%d件饭菜----\n",i+1);
        printf("饭菜名  称:%s\n",&Displaytable[i].name);
        printf("饭菜单  价:%.2f\n",Displaytable[i].cost);
        printf("饭菜销售量:%d\n",Displaytable[i].count);
    }
    return OK;
}

void add_Warehouse(){
    food t_food;
    printf("<<<进行添加饭菜>>>\n"); 
    printf("饭菜的名称是:");
    scanf("%s",&t_food.name);
    printf("饭菜的单价是:");
    scanf("%lf",&t_food.cost);
    printf("你要添加该饭菜的数量是:");
    scanf("%d",&t_food.count);
    Warehouse[Total1] = t_food;
    Total1++;
}

void add_Displaytable(){
    printf("<<<进行添加账单>>>\n");
    food t_food;
    printf("饭菜的名称是:");
    scanf("%s",&t_food.name);
    printf("饭菜的单价是:");
    scanf("%lf",&t_food.cost);
    printf("你要添加该饭菜的数量是:");
    scanf("%d",&t_food.count);
    Displaytable[Total2] = t_food;
    Total2++;
}


void Buy_dish(){
    char  name[1000];
    printf("请输入你要出售饭菜的名字:");
    scanf("%s",&name);
    printf("%s",name);
    
    for(i = 0; i < Total1; i++){
    	printf("\n%s",&Warehouse[j].name);
    	if(strcmp((char *)(&Warehouse[j].name),name)  != 0  ) return;
        printf("出售成功！"); 
        // 库存表减1 
    	if(Warehouse[i].count >=0 ){
    		Warehouse[i].count--;
		}
        // 销售表增加1 
        for(j = 0; j < Total2; j++){
            if(strcmp(name, (char *)(&Displaytable[j].name))  == 0  ){
                Displaytable[i].count++;
                return;
            }
        }
        // 如果销售表中没有就就行添加 
        if(j == Total2){
            Displaytable[Total2].name = Warehouse[i].name;
            Displaytable[Total2].count = 1;
            Displaytable[Total2].cost = Warehouse[i].cost;
            Total2++;
        }
    }
}
