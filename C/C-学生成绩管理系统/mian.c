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

	// 1. չʾѧ������Ϣ 

	for(i = 0; i < N; i++){
		printf("ѧ��:%d\t",data[i].node);
		printf("����:%s\t\n",&data[i].name);
		for(j = 0; j < M; j++){
			printf("��%d�ųɼ���:%.2lf\n",j+1,data[i].score[j]);
		}
		printf("\n--------------------\n");
	}	
}


void calc_mm(){
	// 2.n��ѧ������߷ֺ���ͷ�
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
		printf("                  ��%d�ſγ� \n��߳ɼ���:%.2lf      ",j+1,max_score[j]);
		printf("��ͳɼ���:%.2lf\n",min_score[j]);
	}
}

void calc_avg(){
	// 3.n��ѧ����ƽ���ɼ� 
	double avg_score[M];
	
	for(j = 0; j < M; j++){
		avg_score[j] = 0;
		for(i = 0; i < N;i++){
			avg_score[j] += data[i].score[j];
		}
		avg_score[j] /= N;
	}
	for(j = 0; j < M; j++){
		printf("��%d�ųɼ�ƽ���ɼ���:%.2lf\n",j+1,avg_score[j]);
	}
	printf("\n"); 
} 

void calc_sum(){
	// 4.��ѧ�����ֺܷ�ƽ���� 
	double sum_score[N];
	
	for(i = 0; i < N; i++){
		sum_score[j] = 0;
		for(j = 0; j < M;j++){
			sum_score[i] += data[i].score[j];
		}
	}
	for(j = 0; j < N; j++){
		printf("��%d��ͬѧ�ܳɼ���:%.2lf\t",j+1,sum_score[j]);
		printf("ƽ������:%.2lf\n",sum_score[j]/M); 
	}
	printf("\n");
} 

void show(){
		// չʾѧ��ѧϰ�ĳ̶� 
		for(i = 0; i < N; i++){
		printf("ѧ��:%d\t",data[i].node);
		printf("����:%s\t\n",&data[i].name);
		for(j = 0; j < M; j++){
			printf("��%d�ųɼ��̶�:",j+1);
			if(data[i].score[j] >= 90)
				printf("[����]");
			else if(data[i].score[j] >= 80)
				printf("[����]");
			else if(data[i].score[j] >= 60)
				printf("[����]");
			else if(data[i].score[j] >= 0)
				printf("[��]");
			printf("\n");
		}
		printf("\n--------------------\n");
	}	
}
int main(){
	// ��ȡѧ����Ϣ 
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
        printf("****************ѧ���ɼ�����ϵͳ***************\n");
        printf("\n");
        printf("    1.չʾѧ����Ϣ[�Զ���ȡ]\n");
        printf("    2.����ѧ������߷ֺ���ͷ� \n");
        printf("    3.����γ̵�ƽ���ɼ� \n");
        printf("    4.����ÿ��ѧ����ƽ���ֺ��ܷ�\n");
        printf("    5.����ѧ���ɼ��ȼ�\n");
        printf("    6.�˳�\n");
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
