#include<iostream>

using namespace std;

int n[61][2387][129];
int M,N,L,T;

int main(){
	int i,j,k,volume=0,slice;
	cin>>M>>N>>L>>T;
	for(i=0;i<L;i++){
		for(j=0,slice=0;j<M;j++){
			for(k=0;k<N;k++){
				cin>>n[i][j][k];
				slice+=n[i][j][k];
			}
		}
		if(slice>=T){
			volume+=slice;
		}
		for(j=0,slice=0;j<M;j++){
			for(k=0;k<N;k++){
				if(j!=M)
			}
		}
	}
	cout<<volume;
}
