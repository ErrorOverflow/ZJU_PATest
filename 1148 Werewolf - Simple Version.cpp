#include<iostream>

using namespace std;

int main(){
	int N,i,j,k,n[101],liar,a,b;
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>n[i];
	}
	for(i=1;i<N;i++){
		for(j=i+1;j<=N;j++){
			liar=a=b=0;
			if((n[i]>0 && n[i]!=i && n[i]!=j) || (n[i]<0 && (n[i]==-i || n[i]==-j))){
				a=1;
			}
			if((n[j]>0 && n[j]!=i && n[j]!=j) || (n[j]<0 && (n[j]==-i || n[j]==-j))){
				b=1;
			}
			if(a+b!=1){
				continue;
			}
			for(k=1;k<=N;k++){
				if((n[k]>0 && (n[k]==i || n[k]==j)) || (n[k]<0 && n[k]!=-i && n[k]!=-j)){
					liar++;
				}
			}
			if(liar!=2){
				continue;
			}else{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	cout<<"No Solution";
	return 0;
} 
