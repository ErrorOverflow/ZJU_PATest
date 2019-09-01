#include<iostream>

using namespace std;

int main(){
	int Nv,Ne,M,K,i,j,k,a,b;
	bool isClique,isMax,isCon;
	int q[201];
	cin>>Nv>>Ne;
	bool graph[Nv+1][Nv+1]={false};
	for(i=0;i<Ne;i++){
		cin>>a>>b;
		graph[a][b]=true;
		graph[b][a]=true;
	}
	cin>>M;
	for(i=0;i<M;i++){
		isMax=true;
		isClique=true;
		bool isin[201]={false};
		cin>>K;
		for(j=0;j<K;j++){
			cin>>a;
			q[j]=a;
			isin[a]=true;
		}
		for(j=0;j<K-1;j++){
			for(k=j+1;k<K;k++){
				if(!graph[q[j]][q[k]]){
					isClique=false;
					cout<<"Not a Clique"<<endl;
					break;
				}
			}
			if(!isClique){
				break;
			}
		}
		if(isClique){
			for(j=1;j<=Nv;j++){
				if(isin[j]){
					continue;
				}
				isCon=true;
				for(k=0;k<K;k++){
					//cout<<j<<" "<<q[k]<<endl;
					if(!graph[q[k]][j]){
						isCon=false;
						break;
					}
				}
				if(isCon){
					isMax=false;
					cout<<"Not Maximal"<<endl;
					break;
				}
			}
			if(isMax){
				cout<<"Yes"<<endl;
			}
		} 
	}
	return 0;
}
