#include<iostream>

using namespace std;

int flag=0;
int order[55];
int now[55][2];

int change(){
	int i,j;
	for(i=1;i<=54;i++){
		now[order[i]][1-flag]=now[i][flag];
	}
}

int output(int N){
	if(N<=13){
		cout<<"S"<<N;
	}else if(N<=26){
		cout<<"H"<<N-13;
	}else if(N<=39){
		cout<<"C"<<N-26;
	}else if(N<=52){
		cout<<"D"<<N-39;
	}else{
		cout<<"J"<<N-52;
	}
	return 0;
}

int main(){
	int i,j,time;
	cin>>time;
	for(i=1;i<=54;i++){
		cin>>order[i];
	}
	for(i=1;i<=54;i++){
		now[i][0]=i;
		now[i][1]=i;
	}	
	for(i=0;i<time;i++){
		change();
		flag=1-flag;
	}
	for(i=1;i<=54;i++){
		output(now[i][flag]);
		if(i!=54){
			cout<<" ";
		}
	}
	return 0;
} 
