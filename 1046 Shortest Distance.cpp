#include<iostream>

using namespace std;

int N,M;
int D[100100];

int main(){
	int i,total=0,j,a,b,res;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>D[i];
		total+=D[i];
		D[i]=total-D[i];
	}
	cin>>M;
	for(i=0;i<M;i++){
		cin>>a>>b;
		res=0;
		if(a>b){
			res=D[a-1]-D[b-1];
			if(res<=total/2){
				cout<<res<<endl;
			}else{
				cout<<total-res<<endl;
			}
		}else if(a<b){
			res=D[b-1]-D[a-1];
			if(res<=total/2){
				cout<<res<<endl;
			}else{
				cout<<total-res<<endl;
			}
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}
