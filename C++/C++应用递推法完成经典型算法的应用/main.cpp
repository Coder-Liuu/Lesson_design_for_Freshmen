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
	cout<<"����������������̭���֣�"<<endl;
	cin>>m>>k;
	cout<<"ʤ����Ϊ��"<<Joseph(m,k) + 1<<endl; 
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
bool check(char &flag){	//�ж��Ƿ��˳� 
	while(1){
		cout<<"�Ƿ�����ó���[Y/N]:";
		cin>>flag;
		if(flag == 'Y' || flag == 'y'){
			return true;
		}
		else if(flag == 'N' || flag == 'n'){
			return false;
		}
		else{
			cout<<"�����������������"; 
		}
	}
} 
int main(){
	char flag; 
	int flag2;
	cout<<"---------------�����б�--------------"<<endl;
	cout<<"*-----------------------------------*"<<endl;
	cout<<"*------------1.Լɪ������-----------*"<<endl;  
	cout<<"*------------2.��������-------------*"<<endl;
	cout<<"*------------3.���ӳ�������---------*"<<endl;
	while(1){
		cout<<"��ѡ��������ţ�"<<endl;
		cin>>flag2;
		if(flag2 == 1)
			slove_Joseph();
		else if(flag2 == 2)
			cout<<fish(5)<<endl;
		else if(flag2 == 3)
			cout<<monkey(10)<<endl; 
		else
			cout<<"��Ŵ���"<<endl;
		if(check(flag)){
			break;
		}
	} 
	return 0;
}
