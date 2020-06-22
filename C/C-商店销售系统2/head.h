#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct T{
    int id;
    char name[100]; // ��Ʒ����
    int money;      // ��Ʒ�۸�
    int have_number;      // ��Ʒ������
    int sale_number;      // ��Ʒʣ������
}commodity;

commodity commodity_list[100];
int head=1;
int i,j;

// չʾ�ֿ����Ʒ
void display_have();
// չʾ���۵���Ʒ
void display_sale();
// ��Ӳֿ����Ʒ
void add_have();
// ������۵���Ʒ
void add_sale();
// ������Ʒ
void buyed();

void add_have(){
    commodity t;
    printf("������ӵ���Ʒ��������:");
    scanf("%s",t.name);
    printf("������ӵ���Ʒ�ļ۸���:");
    scanf("%d",&t.money);
    printf("������ӵ���Ʒ��������:");
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
    printf("������ӵ���Ʒ�Ƿ��ڿ�������?");
    scanf("%c",&c);
    scanf("%c",&c);
    if(c == 'y'){
        printf("��Ҫ¼�����Ʒ����Ϊ?");
        scanf("%s",t);
        for(i=0;i<head-1;i++){
            for(j=0;j<strlen(t);j++){
                if(t[j] != commodity_list[i].name[j]) return;
            }
            printf("��Ҫ������Ʒ����������Ϊ?");
            scanf("%d",&data);
            commodity_list[i].sale_number = data;
        }
    }else{
        commodity tdata;
        printf("������ӵ���Ʒ��������:");
        scanf("%s",tdata.name);
        printf("������ӵ���Ʒ�ļ۸���:");
        scanf("%d",&tdata.money);
        printf("������ӵ���Ʒ��������Ϊ:");
        scanf("%d",&tdata.sale_number);
        tdata.have_number = 0;
        tdata.id = head;
        commodity_list[head-1] = tdata;
        head++;
    }
}

// չʾ�ֿ����Ʒ
void display_have(){
    printf("�������Ʒ����:\n");
    for(i=0;i<head-1;i++){
        printf("---------------%d----------------\n",(i+1));
        printf("��Ʒ��ID��:%d\n",commodity_list[i].id);
        printf("��Ʒ��������:%s\n",commodity_list[i].name);
        printf("��Ʒ�ļ۸���:%d\n",commodity_list[i].money);
        printf("��Ʒ�Ŀ������:%d\n",commodity_list[i].have_number);
    }
}

// չʾ���۱����Ʒ
void display_sale(){
    printf("���۱����Ʒ����:\n");
    for(i=0;i<head-1;i++){
        printf("---------------%d----------------\n",(i+1));
        printf("��Ʒ��ID��:%d\n",commodity_list[i].id);
        printf("��Ʒ��������:%s\n",commodity_list[i].name);
        printf("��Ʒ�ļ۸���:%d\n",commodity_list[i].money);
        printf("��Ʒ����������:%d\n",commodity_list[i].sale_number);
    }
}

// ������Ʒ
void buyed(){
    int id;
    printf("���۵���Ʒ��ID��:");
    scanf("%d",&id);
    if( commodity_list[id-1].have_number > 0 ){
        commodity_list[id-1].have_number -= 1;
        commodity_list[id-1].sale_number += 1;
        printf("���۳ɹ�!\n");
        return;
    }
    printf("����ʧ��!\n");
}
