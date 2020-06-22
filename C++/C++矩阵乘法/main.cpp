#include <iostream>
using namespace std;

double data1[1000][1000];
double data2[1000][1000];
double data3[1000][1000];

int n1, m1;
int n2, m2;
int t;
int i ,j ,k;
void matrix_muti(){
	if(m1 != n2){
		cout << "������״��ƥ��!!!";
		return;		
	}
	for( i = 0; i < n1; i++){
		for( j = 0; j < m2; j++){
			double t = 0;
			for( k = 0; k < m1; k++){
//				cout << data1[i][k] << " " << data2[j][k] << endl;
				t += data1[i][k] * data2[k][j];
			}
			data3[i][j] = t;
		}
	}
	cout << "���ľ���˻���:" << endl;
	for( i = 0; i < n1; i++){
		for( j = 0; j < m2; j++){
			cout << data3[i][j] << " ";
		}
		cout << endl;
	}
}

void matrix_sum(){
	// ����Խ������
	cout << "����������Խ�����͵ľ���:(1��2)" << endl; 
	int choose;
	cin >> choose;
	double zhu,fu;
	zhu=fu=0;
	if(choose == 1){
		for( i = 0; i < n1;i++){
			zhu += data1[i][i];
			fu += data1[i][n1-i - 1];
		}		
	} else{
		for( i = 0; i < n1;i++){
			zhu += data2[i][i];
			fu += data2[i][n2-i-1];
		}
	}
	cout << "���Խ������Ϊ:" << zhu << endl;
	cout << "���Խ������Ϊ:" << fu << endl;  
}


void matrix_T(){
	cout << "����������ת�õľ���:(1��2)" << endl; 
	int choose;
	cin >> choose;
	if(choose == 1){
		for( i = 0; i < n1;i++){
			for( j = 0; j < m1;j++){
				data3[i][j] = data1[j][i];
			}
		}
		cout << "ת�����data1����Ϊ(�����ԭ�ظ���):" << endl;
		for( i = 0; i < n1;i++){
			for( j = 0; j < m1;j++){
				data1[i][j] = data3[i][j];
				cout << data1[i][j]  << " ";
			}
			cout << endl;
		}		
	}
	if(choose == 2){
		for( i = 0; i < n1;i++){
			for( j = 0; j < m1;j++){
				data3[i][j] = data2[i][j];
			}
		}
		cout << "ת�����data2����Ϊ(�����ԭ�ظ���):" << endl;
		for( i = 0; i < n1;i++){
			for( j = 0; j < m1;j++){
				data2[i][j] = data3[j][i];
				cout << data2[i][j]  << " ";
			}
			cout << endl;
		}			
	}
}

void matrix_add(){
	cout << "����1+����2" << endl;
	if(n1 != n2 || m1 != m2){
		cout << "������״��ƥ��!!!";
		return;
	}
	
	for( i = 0; i < n1;i++){
		for( j = 0; j < m1;j++){
			data3[i][j] = data1[i][j] +  data2[i][j];
		}
	}
	cout << "��Ӻ�Ľ����:" << endl;
	for( i = 0; i < n1;i++){
		for( j = 0; j < m1;j++){
			cout << data3[i][j] << " ";
		}
		cout << endl;
	}	 
} 

void read_matrix(){
	cout << "���������1�Ĵ�С:(�ո����)" << endl;
	cin >> n1 >> m1;
	cout << "���������1������:(�ո����)" << endl;
	for( i = 0; i < n1;i++){
		for( j = 0; j < m1;j++){
			cin >> data1[i][j];
		}
	}
	cout << "���������2�Ĵ�С:(�ո����)" << endl;
	cin >> n2 >> m2;
	cout << "���������2������:(�ո����)" << endl;
	for( i = 0; i < n2;i++){
		for( j = 0; j < m2;j++){
			cin >> data2[i][j];
		}
	}
}

void matrix_show(){
	cout << "����1Ϊ:" << endl;
	for( i = 0; i < n1; i++){
		for( j = 0; j < m1; j++){
			cout << data1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "����2Ϊ:" << endl;
	for( i = 0; i < n2; i++){
		for( j = 0; j < m2; j++){
			cout << data2[i][j] << " ";
		}
		cout << endl;
	}	
}


int main(){
    int choice = 0;
    while(1) {
        printf("\n\n\n");
        printf("****************���ƾ���ʵ����***********************\n");
        printf("\n");
        printf("    1.�������\n");
        printf("    2.չʾ���� \n");
        printf("    3.����ת�� \n");
        printf("    4.����Խ������\n");
        printf("    5.����˷�\n");
        printf("    6.����˷�\n");
        printf("    7.�˳�\n");
        printf("\n");
        printf("*****************************************************\n");
        printf("please choice(1-7):");
        scanf("%d",&choice);
        switch(choice){
            case 1:   read_matrix();  break;
            case 2:   matrix_show();    break;
            case 3:   matrix_T();         break;
            case 4:   matrix_sum(); break;
            case 5:   matrix_muti();   break;
            case 6:   matrix_add();   break;
            case 7:   exit(0);
            break;
        }
    }
    return 0;
}

// ���Ժ��� 
//int test(){
//	freopen("data.in","r",stdin);
//	read_matrix();
//	matrix_show();
//	matrix_T();
//	matrix_sum();
//	matrix_muti();
//	return 0; 
//} 
