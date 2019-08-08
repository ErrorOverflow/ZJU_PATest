#include<iostream>

using namespace std;

int res[200][2]={0};

int main(){
	long p=0,n,i=3;
	long num;
	cin>>num;
	n=num;
	if(n==1){
		cout<<"1=1";
		return 0;
	}
	if(n%2==0){
		res[0][0]=2;
		res[0][1]=1;
		n/=2;
		while(n%2==0){
			n/=2;
			res[0][1]++;
		}
		p=1;
	}
	while(n!=1){
		if(n%i==0){
			res[p][0]=i;
			res[p][1]=1;
			n/=i;
			while(n%i==0){
				n/=i;
				res[p][1]++;
			}
			p++;
		}
		i+=2;
	}
	cout<<num<<"=";
	for(i=0;i<p;i++){
		cout<<res[i][0];
		if(res[i][1]!=1){
			cout<<"^"<<res[i][1];
		}
		if(i!=p-1){
			cout<<"*";
		}
	}
	return 0;
}
