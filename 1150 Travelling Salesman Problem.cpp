#include<iostream>

using namespace std;

int main(){
	int N,M,Q,n,i,j,k,a,b,dist,pre,minl,mini;
	cin>>N>>M;
	int d[N+1][N+1];
	for(i=0;i<M;i++){
		cin>>a>>b>>dist;
		d[a][b]=dist;
		d[b][a]=dist;
	}
	cin>>Q;
	for(i=0,minl=1e9+7;i<Q;i++){
		cin>>n;
		int path[n];
		bool isall[N+1]={false};
		bool isFin=false;
		for(j=0;j<n;j++){
			cin>>path[j];
			isall[path[j]]=true;
		}
		for(j=0,dist=0;j<n;j++){
			if(j==0){
				pre=path[0];
			}else{
				if(d[pre][path[j]]==0){
					cout<<"Path "<<i+1<<": NA (Not a TS cycle)"<<endl;
					isFin=true;
					break;
				}
				dist+=d[pre][path[j]];
				pre=path[j];
			}
		}
		if(isFin){
			continue;
		}
		if(path[0]!=path[n-1]){
			cout<<"Path "<<i+1<<": "<<dist<<" (Not a TS cycle)"<<endl;
			continue;
		}
		for(j=1;j<=N;j++){
			if(!isall[j]){
				isFin=true;
				cout<<"Path "<<i+1<<": "<<dist<<" (Not a TS cycle)"<<endl;
				break;
			}
		}
		if(!isFin){
			if(dist<minl){
				mini=i+1;
				minl=dist; 
			}
			if(n==N+1)
				cout<<"Path "<<i+1<<": "<<dist<<" (TS simple cycle)"<<endl;
			else
				cout<<"Path "<<i+1<<": "<<dist<<" (TS cycle)"<<endl;
		}
	}
	cout<<"Shortest Dist("<<mini<<") = "<<minl;
	return 0;
}
