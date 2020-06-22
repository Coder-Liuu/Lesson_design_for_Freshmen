#include <stdio.h>
#include <stdlib.h>

void Sequential_search(){
    int n,target;
    int index = -1;
    int i;
    int data[100];
    printf("���������ݵ�����:");
    scanf("%d",&n);

    printf("���������ݣ�ʹ�ÿո����!\n");
    for(i = 0; i < n; i++){
        scanf("%d",&data[i]);
    }
    printf("��������Ҫ���ҵ�Ŀ������:");
    scanf("%d",&target);
    for(i = 0; i < n; i++){
        if(target == data[i]){
            index = i+1;
            break;
        }
    }
    if(index == -1){
        printf("û�в��ҵ���Ԫ��!");
    }else{
        printf("��Ԫ��λ�����ݵĵ�%d��λ��",index);
    }
}

void Ascendind_order(){
    int n,target;
    int index = -1;
    printf("���������ݵ�����:");
    scanf("%d",&n);
    int data[100];
    printf("���������ݣ�ʹ�ÿո����!(���ݱ�������)");
    int i;
    for(i = 0; i < n; i++){
        scanf("%d",&data[i]);
    }
    printf("��������Ҫ���ҵ�Ŀ������:");
    scanf("%d",&target);

    int head,tail,mid;
    head = 0;
    tail = n-1;
    // �����ǹؼ�
    while(head <= tail){
        mid = (head+tail)/2;
        if(data[mid] == target){
            index = mid;
            break;
        }else if(data[mid] < target){
            head = mid+1;
        }else if(data[mid] > target){
            tail = mid-1;
        }
    }
    if(index == -1){
        printf("û�в��ҵ���Ԫ��!\n");
    }else{
        printf("��Ԫ��λ�����ݵĵ�%d��λ��\n",index+1);
    }
}

void Descending_order(){
    int n,target;
    int index = -1;
    int i;
    printf("���������ݵ�����:");
    scanf("%d",&n);
    int data[100];
    printf("���������ݣ�ʹ�ÿո����!(���ݱ��뽵��)");
    for(i = 0; i < n; i++){
        scanf("%d",&data[i]);
    }
    printf("��������Ҫ���ҵ�Ŀ������:");
    scanf("%d",&target);

    int head,tail,mid;
    head = 0;
    tail = n-1;
    // �����ǹؼ�
    while(head <= tail){
        mid = (head+tail)/2;
        if(data[mid] == target){
            index = mid;
            break;
        }else if(data[mid] < target){
            tail = mid-1;
        }else if(data[mid] > target){
            head = mid+1;
        }
    }
    if(index == -1){
        printf("û�в��ҵ���Ԫ��!\n");
    }else{
        printf("��Ԫ��λ�����ݵĵ�%d��λ��\n",index+1);
    }
}


int main(){
    int choice = 0;
    while(1) {
        printf("\n\n\n");
        printf("****�������㷨Ӧ��****\n");
        printf("\n");
        printf("    1.˳�����\n");
        printf("    2.��������Ķ��ֲ��� \n");
        printf("    3.��������Ķ��ֲ��� \n");
        printf("    0.�˳�\n");
        printf("\n");
        printf("***********************\n");
        printf("please choice(0-3):");
        scanf("%d",&choice);
        switch(choice){
            case 1:   Sequential_search();  break;
            case 2:   Ascendind_order();    break;
            case 3:   Descending_order();   break;
            case 0:   exit(0);
            break;
        }
    }
    return 0;
}
