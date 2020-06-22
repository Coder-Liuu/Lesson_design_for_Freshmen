#include <iostream>
using namespace std;


const int N = 500;
int n,m;
string sno,name;
double g[N];
char flag;
int course;
string stud;
struct student{
	string sno;
	string name;
	double grade[N]; 
}st[N];

bool check(char &flag){	//�ж��Ƿ��˳� 
	while(1){
		cout<<"�Ƿ�ֹͣ������ѯ��[Y/N]:";
		cin>>flag;
		if(flag == 'Y' || flag == 'y'){
			return true;
		}
		else if(flag == 'N' || flag == 'n'){
			return false;
		}
		else{
			cout << "�����������������";
		}
	}
} 
void input(){
	char tar[100];
	cout << "��������Ҫ��ȡѧ�����ļ�:(��ϵͳ�Դ�data.txt)" << endl;
	cin >> tar;
	ifstream myfile( tar);
	cout << "��ȡ�ɹ�!" << endl;
	myfile>>n>>m;
	for(int i = 0;i<n;i++){
		myfile>>sno>>name;
		for(int j = 0;j<m;j++){
			myfile>> g[j] ; 
		}
		st[i].sno = sno;
		st[i].name = name;
		for(int k = 0;k<m;k++){
			st[i].grade[k] = g[k];
		}	
	}
}
void min_max(){		//�γ���ߺ���ͳɼ� (�γ̺�)
	int num;
	while(1){
		cout<<"������Ҫ��ѯ��߷ֺ���ͷֵĿγ̺ţ�"<<endl;
		cin >> num;
		if(num > m || num < 1){
			cout<<"�������,����������:"<<endl;
			continue;
		}
		num--;
		double grad[N] = {0};
		for(int i = 0;i<n;i++){
			grad[i] = st[i].grade[num];
		}
		sort(grad,grad + n);
		cout<<"�˿γ���߷�Ϊ��"<<grad[n-1]<<' '<<"��ͷ�Ϊ��"<<grad[0]<<endl;
		if(check(flag)){
			break;
		}
	}
}
void avg_course(){		//m�ſγ̵�ƽ���ɼ� 
	int avg[N];
	for(int i = 0;i<m;i++){
		double re = 0;
		for(int j = 0;j<m;j++){
			re += st[i].grade[i];
		}
		re /= n;
		avg[i] = re;
		cout<<"��"<<i+1<<"�ſγ̵�ƽ���ɼ�Ϊ��"<<re<<endl; 
	}
}
void  avg_st(){			//ÿ��ѧ����ƽ���ɼ����ܷ�
	for(int i = 0;i<n;i++){
		double re = 0;
		for(int j = 0;j< m;j++){
			re += st[i].grade[j];
		}
		cout<<"ѧ��Ϊ��"<<st[i].sno<<' '<<"����Ϊ��"<<st[i].name<<' '<<"�ܷ�Ϊ��"<<re<<' ';
		re /= m;
		cout<<"ƽ���ɼ�Ϊ��"<<re<<endl; 
	} 
} 

void seclect(){		//���ݳɼ����ȼ� 
	while(1){
		while(1){
			cout<<"������Ҫ��ѯѧ����ѧ�źͿγ̺ţ�"<<endl;
			cin>> stud >> course;
			double grade = -1;
			for(int i = 0;i<n;i++){
				if(st[i].sno == stud)
					grade = st[i].grade[course];
			}
			if(grade == -1)
				cout<<"����ʧ��"<<endl;
			if(grade <= 100 && grade >= 90){
				cout<<"��ͬѧ�ɼ�Ϊ����"<<endl;
				break;
			}
			if(grade < 90 && grade >= 70){
				cout<<"��ͬѧ�ɼ�Ϊ����"<<endl;
				break;
			}
			if(grade < 70 && grade >= 60){
				cout<<"��ͬѧ�ɼ�Ϊ����"<<endl;
				break;
			}
			if(grade < 60){
				cout<<"��ͬѧ�ɼ�Ϊ�ϲ�"<<endl;
				break;
			}
		}
		if(check(flag)){
			break;
		}
	}
}

int main(){
	// freopen("path","r",stdin);
	cout<<"-------------------------ѧ���ɼ�����ϵͳ--------------------------"<<endl; 
	while(1){
		input();
		cout<<"\n---------------��ѯ�γ���߷�����ͷ�--------------------"<<endl; 
		min_max();
		cout<<"\n------------------�γ�ƽ����չʾ-------------------------"<<endl; 
		avg_course();
		cout<<"\n----------------ѧ���ֺܷ�ƽ����չʾ---------------------"<<endl;
		avg_st();
		cout<<"\n------------------��ѯѧ���ĳɼ��ȼ�----------------------"<<endl;
		seclect();
		cout<<"\n----------------------end--------------------------------"<<endl;
		if( check(flag) ){
			break;
		}
	} 
	return 0;
}
