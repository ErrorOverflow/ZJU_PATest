#include<iostream>

using namespace std;

int main(){
	int N,i,a;
	cin>>N;
	bool isR[N+1]={false};
	for(i=0;i<N;i++){
		cin>>a;
		if(a>0 && a<=N){
			isR[a]=true;
		}
	}
	for(i=1;i<=N;i++){
		if(!isR[i]){
			cout<<i;
			return 0;
		}
	}
	cout<<N+1;
	return 0;
}
