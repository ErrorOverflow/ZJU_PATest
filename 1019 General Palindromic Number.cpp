#include<iostream>
#include<math.h>

using namespace std;

int main(){
	int i,j,N,b,num,store[100],leave,isYes;
	cin>>N>>b;
	int maxBit=0;
	while(pow(b,maxBit)<=N){
		maxBit++;
	}
	leave=N;
	for(i=maxBit-1;i>=0;i--){
		store[i]=leave/pow(b,i);
		leave=leave%(int)pow(b,i);
	}
	isYes=1;
	for(i=0;i<=maxBit/2;i++){
		if(store[i]!=store[maxBit-i-1]){
			isYes=0;
			break;
		}
	}
	if(isYes){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	for(i=0;i<maxBit;i++){
		cout<<store[maxBit-1-i];
		if(i!=maxBit-1){
			cout<<" ";
		}
	}
}
