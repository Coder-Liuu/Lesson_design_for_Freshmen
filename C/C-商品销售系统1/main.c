#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000 // �ֿ�����Ʒ��������

// ��Ʒ�ṹ��
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
        printf("�ֿ���������,���ʧ��!");
    }else{
        goods t_goods;
        printf("������Ҫ��ӵ�������Ʒ������:");
        scanf("%s",&t_goods.name);
        printf("������Ҫ��ӵ�������Ʒ�ļ۸�:");
        scanf("%lf",&t_goods.money);
        printf("������Ҫ��ӵ�������Ʒ������:");
        scanf("%d",&t_goods.count);
        storage[storage_total] = t_goods;
        storage_total++;
    }
}

void add_sales(){
    goods t_goods;
    printf("������Ҫ��ӵ����۱���Ʒ������:");
    scanf("%s",&t_goods.name);
    printf("������Ҫ��ӵ����۱���Ʒ�ļ۸�:");
    scanf("%lf",&t_goods.money);
    printf("������Ҫ��ӵ����۱���Ʒ������:");
    scanf("%d",&t_goods.count);
    sales_table[salse_total] = t_goods;
    salse_total++;
}

void show_storage(){
    if(storage_total == 0){
        printf("���[����]�пտ���Ҳ,����[¼�����Ʒ]��!");
    }else{
        int i;
        for(i = 0; i < storage_total; i++){
            printf("\n----�����е�%d����Ʒ----\n",i+1);
            printf("��Ʒ����:%s\n",&storage[i].name);
            printf("��Ʒ�۸�:%.2f\n",storage[i].money);
            printf("��Ʒ���:%d\n",storage[i].count);
        }
    }
}

void show_sales(){
    if(salse_total == 0){
        printf("���[���۱�]�пտ���Ҳ,����[������Ʒ]����[�����Ʒ]��!");
    }else{
        int i;
        for(i = 0; i < salse_total; i++){
            printf("\n----���۱��е�%d����Ʒ----\n",i+1);
            printf("��Ʒ����:%s\n",&sales_table[i].name);
            printf("��Ʒ�۸�:%.2f\n",sales_table[i].money);
            printf("��Ʒ������:%d\n",sales_table[i].count);
        }
    }
}

void sell(){
    char * name;
    int i,j;
    if(storage_total == 0){
        printf("��Ĳֿ�տա�����¼����Ʒ������!");
        return;
    }
    printf("��������Ҫ������Ʒ������:");
    scanf("%s",name);
    for(i = 0; i < storage_total; i++){
        if(strcmp(name,(char *)(&storage[i].name)) == 0){
        	if(storage[i].count >=0 ){
        		storage[i].count--;
			}else{
				printf("����Ʒû�п���ˣ����Ƚ�����");
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
        printf("���������Ʒ�ڲֿ���û�У�����������������˶Ժ��ڳ���!");
    }
}

int main(){
    int choice = 0;
    while(1) {
        printf("\n\n\n");
        printf("****************�����̵����Ʒ����ϵͳ***************\n");
        printf("\n");
        printf("    1.��������¼��\n");
        printf("    2.���۱�����¼�� \n");
        printf("    3.������Ʒ \n");
        printf("    4.�����ѯ\n");
        printf("    5.���۱��ѯ\n");
        printf("    6.�˳�\n");
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

