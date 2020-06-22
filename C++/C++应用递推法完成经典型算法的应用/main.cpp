#include <iostream>
using namespace std;
int Joseph(int m,int k)
{
    if(m<=0||k<=0)
    {
        cout<<"error!"<<endl;
        return -1;
    }else
    {
        if(m==1)
        {
            return 0;
        }else
        {
            return ((Joseph(m-1,k)+k)%m);
        }
    }
}
void slove_Joseph(){
	int m,k;
	cout<<"请输入总人数和淘汰数字："<<endl;
	cin>>m>>k;
	cout<<"胜利者为："<<Joseph(m,k) + 1<<endl; 
}
int fish(int i){
	if(i == 0) 	
		return  1;
	else{
		i--;
		return 5*fish(i) + 1;
	}
}
int monkey(int i){
	if(i == 1) 	
		return  1;
	else{
		i--;
		return 2*(monkey(i)+1);
	}
}
bool check(char &flag){	//判断是否退出 
	while(1){
		cout<<"是否结束该程序？[Y/N]:";
		cin>>flag;
		if(flag == 'Y' || flag == 'y'){
			return true;
		}
		else if(flag == 'N' || flag == 'n'){
			return false;
		}
		else{
			cout<<"输入错误，请重新输入"; 
		}
	}
} 
int main(){
	char flag; 
	int flag2;
	cout<<"---------------问题列表--------------"<<endl;
	cout<<"*-----------------------------------*"<<endl;
	cout<<"*------------1.约瑟夫问题-----------*"<<endl;  
	cout<<"*------------2.捕鱼问题-------------*"<<endl;
	cout<<"*------------3.猴子吃桃问题---------*"<<endl;
	while(1){
		cout<<"请选择问题序号："<<endl;
		cin>>flag2;
		if(flag2 == 1)
			slove_Joseph();
		else if(flag2 == 2)
			cout<<fish(5)<<endl;
		else if(flag2 == 3)
			cout<<monkey(10)<<endl; 
		else
			cout<<"序号错误"<<endl;
		if(check(flag)){
			break;
		}
	} 
	return 0;
}
