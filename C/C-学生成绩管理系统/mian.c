#include <stdio.h>
#include <stdlib.h>
#define N 4
#define M 3

typedef struct S{
	int node;
	char name[100];
	double score[M];
}student;

int i,j;
student data[N];

void show_info(){

	// 1. 展示学生的信息 

	for(i = 0; i < N; i++){
		printf("学号:%d\t",data[i].node);
		printf("姓名:%s\t\n",&data[i].name);
		for(j = 0; j < M; j++){
			printf("第%d门成绩是:%.2lf\n",j+1,data[i].score[j]);
		}
		printf("\n--------------------\n");
	}	
}


void calc_mm(){
	// 2.n个学生的最高分和最低分
	double max_score[M];
	double min_score[M];
	
	for(j = 0; j < M; j++){
		max_score[j] = 0;
		min_score[j] = 100;
		for(i = 0; i < N;i++){
			if(data[i].score[j] > max_score[i] ){
				max_score[j] = data[i].score[j];
			}
			if(data[i].score[j] < min_score[i] ){
				min_score[j] = data[i].score[j];
			}			
		}
	}
	for(j = 0; j < M; j++){
		printf("                  第%d门课程 \n最高成绩是:%.2lf      ",j+1,max_score[j]);
		printf("最低成绩是:%.2lf\n",min_score[j]);
	}
}

void calc_avg(){
	// 3.n个学生的平均成绩 
	double avg_score[M];
	
	for(j = 0; j < M; j++){
		avg_score[j] = 0;
		for(i = 0; i < N;i++){
			avg_score[j] += data[i].score[j];
		}
		avg_score[j] /= N;
	}
	for(j = 0; j < M; j++){
		printf("第%d门成绩平均成绩是:%.2lf\n",j+1,avg_score[j]);
	}
	printf("\n"); 
} 

void calc_sum(){
	// 4.求学生的总分和平均分 
	double sum_score[N];
	
	for(i = 0; i < N; i++){
		sum_score[j] = 0;
		for(j = 0; j < M;j++){
			sum_score[i] += data[i].score[j];
		}
	}
	for(j = 0; j < N; j++){
		printf("第%d个同学总成绩是:%.2lf\t",j+1,sum_score[j]);
		printf("平均分是:%.2lf\n",sum_score[j]/M); 
	}
	printf("\n");
} 

void show(){
		// 展示学生学习的程度 
		for(i = 0; i < N; i++){
		printf("学号:%d\t",data[i].node);
		printf("姓名:%s\t\n",&data[i].name);
		for(j = 0; j < M; j++){
			printf("第%d门成绩程度:",j+1);
			if(data[i].score[j] >= 90)
				printf("[优秀]");
			else if(data[i].score[j] >= 80)
				printf("[良好]");
			else if(data[i].score[j] >= 60)
				printf("[可以]");
			else if(data[i].score[j] >= 0)
				printf("[差]");
			printf("\n");
		}
		printf("\n--------------------\n");
	}	
}
int main(){
	// 读取学生信息 
	FILE *fp;
	fp = fopen("data.txt","r");
	for(i = 0; i < N; i++){
		fscanf(fp,"%d",&data[i].node);
		fscanf(fp,"%s",&data[i].name);
		for(j = 0; j < M; j++){
			fscanf(fp,"%lf",&data[i].score[j]);
		}
	}
	fclose(fp);
	
	int choice = 0;
    while(1) {
        printf("\n\n\n");
        printf("****************学生成绩管理系统***************\n");
        printf("\n");
        printf("    1.展示学生信息[自动读取]\n");
        printf("    2.计算学生的最高分和最低分 \n");
        printf("    3.计算课程的平均成绩 \n");
        printf("    4.计算每个学生的平均分和总分\n");
        printf("    5.给出学生成绩等级\n");
        printf("    6.退出\n");
        printf("\n");
        printf("************************************************\n");
        printf("please choice(1-6):");
        scanf("%d",&choice);
        switch(choice){
            case 1:   show_info();  break;
            case 2:   calc_mm();    break;
            case 3:   calc_avg();         break;
            case 4:   calc_sum(); break;
            case 5:   show();   break;
            case 6:   exit(0);
            break;
        }
    }
	return 0;
}
