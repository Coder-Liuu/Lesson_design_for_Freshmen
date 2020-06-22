#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ������������
#define OK 1
#define NO 0 
// ����һЩ���� 
void Buy_dish();
int show_Displaytable();
int show_Warehouses();
void add_Displaytable();
void add_Warehouse();
/* ������������  */
typedef struct Food{
	char * name;
    int count;
    double cost;
}food;
// ����һ����Ҫ���������͡� 
food Warehouse[999];
food Displaytable[999];
int Total1 = 0;  // �ֿ��еķ������� 
int Total2;      // ���۹��ķ��˵����� 
int i,j;
int main(){
    int User_chose = 0;
    while(1) {
        printf("��ð������ǽ���������Ʒ����ϵͳ�Ļ����ˣ��������ҿ��԰�����ɵ�����\n");
        printf("1.��������\n");
        printf("2.�����˵���¼\n");
        printf("3.�㱨�����˵�����\n");
        printf("4.�鿴�˵�\n");
        printf("5.�������ϲ�\n");
        printf("0.�˳�\n");
        printf("\n");
        printf("�����ϰ�����Щʲô: ");
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
        printf("\n----�����е�%d������----\n",i+1);
        printf("������  ��:%s\n",&Warehouse[i].name);
        printf("���˵�  ��:%.2f\n",Warehouse[i].cost);
        printf("����ʣ����:%d\n",Warehouse[i].count);
    }
    return OK;
}

int show_Displaytable(){
    for(i = 0; i < Total2; i++){
        printf("\n----�˵��е�%d������----\n",i+1);
        printf("������  ��:%s\n",&Displaytable[i].name);
        printf("���˵�  ��:%.2f\n",Displaytable[i].cost);
        printf("����������:%d\n",Displaytable[i].count);
    }
    return OK;
}

void add_Warehouse(){
    food t_food;
    printf("<<<������ӷ���>>>\n"); 
    printf("���˵�������:");
    scanf("%s",&t_food.name);
    printf("���˵ĵ�����:");
    scanf("%lf",&t_food.cost);
    printf("��Ҫ��Ӹ÷��˵�������:");
    scanf("%d",&t_food.count);
    Warehouse[Total1] = t_food;
    Total1++;
}

void add_Displaytable(){
    printf("<<<��������˵�>>>\n");
    food t_food;
    printf("���˵�������:");
    scanf("%s",&t_food.name);
    printf("���˵ĵ�����:");
    scanf("%lf",&t_food.cost);
    printf("��Ҫ��Ӹ÷��˵�������:");
    scanf("%d",&t_food.count);
    Displaytable[Total2] = t_food;
    Total2++;
}


void Buy_dish(){
    char  name[1000];
    printf("��������Ҫ���۷��˵�����:");
    scanf("%s",&name);
    printf("%s",name);
    
    for(i = 0; i < Total1; i++){
    	printf("\n%s",&Warehouse[j].name);
    	if(strcmp((char *)(&Warehouse[j].name),name)  != 0  ) return;
        printf("���۳ɹ���"); 
        // �����1 
    	if(Warehouse[i].count >=0 ){
    		Warehouse[i].count--;
		}
        // ���۱�����1 
        for(j = 0; j < Total2; j++){
            if(strcmp(name, (char *)(&Displaytable[j].name))  == 0  ){
                Displaytable[i].count++;
                return;
            }
        }
        // ������۱���û�о;������ 
        if(j == Total2){
            Displaytable[Total2].name = Warehouse[i].name;
            Displaytable[Total2].count = 1;
            Displaytable[Total2].cost = Warehouse[i].cost;
            Total2++;
        }
    }
}
