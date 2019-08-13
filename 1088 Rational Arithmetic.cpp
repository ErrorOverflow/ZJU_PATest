#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int num[2][2];
int res[2];
int simplify(int* a,int* b){
	int i,j;
	if(*a%*b==0){
		*a/=*b;
		*b=1;
		return 0;
	}
	if(*b%*a==0){
		*b/=*a;
		*a=1;
		return 0;		
	}
	while(*a%2==0 && *b%2==0){
		*a/=2;
		*b/=2;
	}
	for(i=3;i<*a && i<*b;i+=2){
		if(*a%i==0 && *b%i==0){
			*a/=i;
			*b/=i;
			i-=2;
		}
	}
	return 0; 
}

void display(char c){
	if(num[0][0]==0){
		cout<<"0 ";
	}else{
		if(num[0][0]/num[0][1]!=0){
			if(num[0][0]/num[0][1]<0){
				cout<<"(";
			}
			if(num[0][0]%num[0][1]!=0)
				cout<<num[0][0]/num[0][1]<<" "<<abs(num[0][0]%num[0][1])<<"/"<<num[0][1]<<" ";
			else
				cout<<num[0][0]/num[0][1];
			if(num[0][0]/num[0][1]<0){
				cout<<")";
			}
		}else{
			cout<<num[0][0]<<"/"<<num[0][1]<<" ";
		}
	}
	cout<<c<<" ";
	if(num[1][0]==0){
		cout<<"0 ";
	}else{
		if(num[1][0]/num[1][1]!=0){
			if(num[1][0]/num[1][1]<0){
				cout<<"(";
			}
			if(num[1][1]%num[1][1]!=0)
				cout<<num[1][0]/num[1][1]<<" "<<abs(num[1][0]%num[1][1])<<"/"<<num[1][1]<<" ";
			else
				cout<<num[1][0]/num[1][1];
			if(num[1][0]/num[1][1]<0){
				cout<<")";
			}
		}else{
			cout<<num[1][0]<<"/"<<num[1][1]<<" ";
		}
	}
	cout<<" = ";
}

int result(){
	if(res[0]==0){
		cout<<"0";
		return 0;
	}
	if(res[0]%res[1]==0){
		if(res[0]/res[1]<0){
			cout<<"(";
		}
		cout<<res[0]/res[1];
		if(res[0]/res[1]<0){
			cout<<")";
		}
		return 0;
	}
	bool isMinus=false;
	if((res[0]<0 && res[1]>0) ||(res[0]>0 && res[1]<0)){
		isMinus=true;
	}
	if(isMinus){
		cout<<"(";
		cout<<"-";
	}
	if(res[0]/res[1]!=0){
		cout<<(abs)(res[0]/res[1])<<" ";
	}
	cout<<abs(res[0]%res[1])<<"/"<<abs(res[1]);
	if(isMinus){
		cout<<")";
	}
	return 0;
}

int main(){
	string a;
	int i,j;
	for(j=0;j<2;j++){
		cin>>a;
		for(i=0;i<a.length();i++){
			if(a[i]=='/'){
				num[j][0]=stoi(string(a.substr(0,i)));
				num[j][1]=stoi(string(a.substr(i+1,a.length()-i)));
				simplify(&num[j][0],&num[j][1]);
			}
		}	
	}
//	cout<<num[0][0]<<" "<<num[0][1]<<endl;
//	cout<<num[1][0]<<" "<<num[1][1]<<endl;
	display('+');
	res[0]=num[0][0]*num[1][1]+num[0][1]*num[1][0];
	res[1]=num[0][1]*num[1][1];
	simplify(&res[0],&res[1]);
	result();
	cout<<endl;
	display('-');
	res[0]=num[0][0]*num[1][1]-num[0][1]*num[1][0];
	res[1]=num[0][1]*num[1][1];
	simplify(&res[0],&res[1]);
	result();
	cout<<endl;
	display('*');
	res[0]=num[0][0]*num[1][0];
	res[1]=num[0][1]*num[1][1];
	simplify(&res[0],&res[1]);
	result();
	cout<<endl;
	display('/');
	res[0]=num[0][0]*num[1][1];
	res[1]=num[0][1]*num[1][0];
	if(res[1]==0){
		cout<<"Inf";
		return 0;
	}
	simplify(&res[0],&res[1]);
	result();	
	return 0;
}
