#include<iostream>

using namespace std;

int main(){
	int v[1001]={0},i,j,N,M,a,b,special=0;
	bool isCon=true;
	cin>>N>>M;
	if(N<2){
		while(true){
			cout<<233;
		}
	}
	for(i=0;i<M;i++){
		cin>>a>>b;
		v[a]++;
		v[b]++;
	}
	for(i=1;i<=N;i++){
		cout<<v[i];
		if(i!=N){
			cout<<" ";
		}
		if(v[i]==0){
			isCon=false;
		}
		if(v[i]%2!=0){
			special++;
		}
	}
	cout<<endl;
	if(special==0 && isCon){
		cout<<"Eulerian";
	}else if(special==2 && isCon){
		cout<<"Semi-Eulerian";
	}else{
		cout<<"Non-Eulerian";
	}
	return 0;
} 
