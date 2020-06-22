#include <stdio.h>
#include <stdlib.h>

void Sequential_search(){
    int n,target;
    int index = -1;
    int i;
    int data[100];
    printf("请输入数据的数量:");
    scanf("%d",&n);

    printf("请输入数据，使用空格隔开!\n");
    for(i = 0; i < n; i++){
        scanf("%d",&data[i]);
    }
    printf("请输入你要查找的目标数据:");
    scanf("%d",&target);
    for(i = 0; i < n; i++){
        if(target == data[i]){
            index = i+1;
            break;
        }
    }
    if(index == -1){
        printf("没有查找到该元素!");
    }else{
        printf("该元素位于数据的第%d个位置",index);
    }
}

void Ascendind_order(){
    int n,target;
    int index = -1;
    printf("请输入数据的数量:");
    scanf("%d",&n);
    int data[100];
    printf("请输入数据，使用空格隔开!(数据必须升序)");
    int i;
    for(i = 0; i < n; i++){
        scanf("%d",&data[i]);
    }
    printf("请输入你要查找的目标数据:");
    scanf("%d",&target);

    int head,tail,mid;
    head = 0;
    tail = n-1;
    // 这里是关键
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
        printf("没有查找到该元素!\n");
    }else{
        printf("该元素位于数据的第%d个位置\n",index+1);
    }
}

void Descending_order(){
    int n,target;
    int index = -1;
    int i;
    printf("请输入数据的数量:");
    scanf("%d",&n);
    int data[100];
    printf("请输入数据，使用空格隔开!(数据必须降序)");
    for(i = 0; i < n; i++){
        scanf("%d",&data[i]);
    }
    printf("请输入你要查找的目标数据:");
    scanf("%d",&target);

    int head,tail,mid;
    head = 0;
    tail = n-1;
    // 这里是关键
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
        printf("没有查找到该元素!\n");
    }else{
        printf("该元素位于数据的第%d个位置\n",index+1);
    }
}


int main(){
    int choice = 0;
    while(1) {
        printf("\n\n\n");
        printf("****查找类算法应用****\n");
        printf("\n");
        printf("    1.顺序查找\n");
        printf("    2.升序排序的二分查找 \n");
        printf("    3.降序排序的二分查找 \n");
        printf("    0.退出\n");
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
