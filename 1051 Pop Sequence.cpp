#include<iostream>

using namespace std;

int num[1010];
int M,N,K;
bool isNo=false;

int judge(int low,int high){
	int i,tmp,lowest,min=9999;
	for(i=low;i<=high;i++){
		if(num[i]<min){
			lowest=i;
			min=num[i];
		}
	}
	if(lowest!=low){
		if(lowest-high+1>M){
			isNo=true;
			return 0;
		}
		for(i=lowest-1,tmp=num[lowest];i>=low;i--){
			if(num[i]!=--tmp){
				isNo=true;
				return 0;
			}
		}
		judge(low,lowest);
	}
	if(lowest!=high){
		/*
		if(high-lowest>M){
			cout<<"NO";
			exit(0);
		}
		for(i=high-1,tmp=num[high];i>lowest;i--){
			if(num[i]!=--tmp){
				cout<<"NO";
				exit(0);
			}
		}
		*/
		judge(lowest+1,high);
	}
}

int main(){
	int i,j;
	cin>>M>>N>>K;
	for(i=0;i<K;i++){
		for(j=0;j<N;j++){
			cin>>num[j];
		}
		judge(0,N-1);
		if(isNo)
			cout<<"NO";
		else
			cout<<"YES";
		isNo=false;
	}
	return 0;
} 
