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

bool check(char &flag){	//判断是否退出 
	while(1){
		cout<<"是否停止输入或查询？[Y/N]:";
		cin>>flag;
		if(flag == 'Y' || flag == 'y'){
			return true;
		}
		else if(flag == 'N' || flag == 'n'){
			return false;
		}
		else{
			cout << "输入错误，请重新输入";
		}
	}
} 
void input(){
	char tar[100];
	cout << "请输入你要读取学生的文件:(本系统自带data.txt)" << endl;
	cin >> tar;
	ifstream myfile( tar);
	cout << "读取成功!" << endl;
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
void min_max(){		//课程最高和最低成绩 (课程号)
	int num;
	while(1){
		cout<<"请输入要查询最高分和最低分的课程号："<<endl;
		cin >> num;
		if(num > m || num < 1){
			cout<<"输入出错,请重新输入:"<<endl;
			continue;
		}
		num--;
		double grad[N] = {0};
		for(int i = 0;i<n;i++){
			grad[i] = st[i].grade[num];
		}
		sort(grad,grad + n);
		cout<<"此课程最高分为："<<grad[n-1]<<' '<<"最低分为："<<grad[0]<<endl;
		if(check(flag)){
			break;
		}
	}
}
void avg_course(){		//m门课程的平均成绩 
	int avg[N];
	for(int i = 0;i<m;i++){
		double re = 0;
		for(int j = 0;j<m;j++){
			re += st[i].grade[i];
		}
		re /= n;
		avg[i] = re;
		cout<<"第"<<i+1<<"门课程的平均成绩为："<<re<<endl; 
	}
}
void  avg_st(){			//每个学生的平均成绩和总分
	for(int i = 0;i<n;i++){
		double re = 0;
		for(int j = 0;j< m;j++){
			re += st[i].grade[j];
		}
		cout<<"学号为："<<st[i].sno<<' '<<"姓名为："<<st[i].name<<' '<<"总分为："<<re<<' ';
		re /= m;
		cout<<"平均成绩为："<<re<<endl; 
	} 
} 

void seclect(){		//根据成绩给等级 
	while(1){
		while(1){
			cout<<"请输入要查询学生的学号和课程号："<<endl;
			cin>> stud >> course;
			double grade = -1;
			for(int i = 0;i<n;i++){
				if(st[i].sno == stud)
					grade = st[i].grade[course];
			}
			if(grade == -1)
				cout<<"查找失败"<<endl;
			if(grade <= 100 && grade >= 90){
				cout<<"该同学成绩为优秀"<<endl;
				break;
			}
			if(grade < 90 && grade >= 70){
				cout<<"该同学成绩为良好"<<endl;
				break;
			}
			if(grade < 70 && grade >= 60){
				cout<<"该同学成绩为可以"<<endl;
				break;
			}
			if(grade < 60){
				cout<<"该同学成绩为较差"<<endl;
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
	cout<<"-------------------------学生成绩管理系统--------------------------"<<endl; 
	while(1){
		input();
		cout<<"\n---------------查询课程最高分与最低分--------------------"<<endl; 
		min_max();
		cout<<"\n------------------课程平均分展示-------------------------"<<endl; 
		avg_course();
		cout<<"\n----------------学生总分和平均分展示---------------------"<<endl;
		avg_st();
		cout<<"\n------------------查询学生的成绩等级----------------------"<<endl;
		seclect();
		cout<<"\n----------------------end--------------------------------"<<endl;
		if( check(flag) ){
			break;
		}
	} 
	return 0;
}
