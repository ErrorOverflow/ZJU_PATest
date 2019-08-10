#include<iostream>
#include<vector>
#include<set>
using namespace std;

int N,L,K,id;
int follow;
vector<int> follower[1010];
set<int> visit;

int DFS(int id, int *depth,int level){
	int i,num=0;
	if(level>3){
		return 0;
	}
	for(i=0;i<follower[id].size();i++){
		if(visit.find(follower[id][i])==visit.end()){
			visit.insert(follower[id][i]);
			//cout<<id<<"#"<<follower[id][i]<<endl;
			num++;
		}
		if(level+1<depth[follower[id][i]] || depth[follower[id][i]]==0){
			//cout<<id<<"->"<<follower[id][i]<<endl;
			depth[follower[id][i]]=level+1;
			num+=DFS(follower[id][i],depth,level+1);
		}
	}
	return num;
}

int main(){
	int i,j,f;
	cin>>N>>L;
	for(i=1;i<=N;i++){
		cin>>f;
		for(j=0;j<f;j++){
			cin>>follow;
			follower[follow].push_back(i);
		}
	}
	cin>>K;
	for(i=0;i<K;i++){
		cin>>id;
		int depth[1010]={0};
		depth[id]=1;
		visit.clear();
		cout<<DFS(id,depth,1)<<endl;
	}
	return 0;
}
