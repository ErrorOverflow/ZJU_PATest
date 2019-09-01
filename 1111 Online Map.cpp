#include<iostream>
#include<vector>

using namespace std;
const int maxv=500;
const int INF=1e9+7;
int N,M;
int flag;
int cost[2][maxv][maxv];
int d[2][maxv];
int start,des,c[2],minc[2];
bool vis[2][maxv];
vector<int> pre[2][maxv];
vector<int> tmp, path[2];

int dijkstra(int s){
	fill(d[flag], d[flag] + 500, INF);
	d[flag][s]=0;
	while(true){
		int minl=INF,mini=-1;
		for(int i=0;i<N;i++){
			if(!vis[flag][i] && d[flag][i]<minl){
				minl=d[flag][i];
				mini=i;
			}
		}
		if(mini==-1){
			return 0;
		}
		vis[flag][mini]=true;
		for(int i=0;i<N;i++){
			if(!vis[flag][i] && cost[flag][mini][i]){
				if(d[flag][mini]+cost[flag][mini][i]<d[flag][i]){
					d[flag][i]=d[flag][mini]+cost[flag][mini][i];
					pre[flag][i].clear();
					pre[flag][i].push_back(mini);
				}else if(d[flag][mini]+cost[flag][mini][i]==d[flag][i]){
					pre[flag][i].push_back(mini);
				}
			}
		}
	}
}

int dfs(int p){
	tmp.push_back(p);
	if(p==start){
		if(!flag){
			if(c[0]<minc[0]){
				path[0].assign(tmp.begin(),tmp.end());
				minc[0]=c[0];
			}
		}else{
			if(tmp.size()<minc[1]){
				path[1].assign(tmp.begin(),tmp.end());
				minc[1]=tmp.size();
			}
		}
		tmp.pop_back();
		return 0;
	}
	for(int i=0;i<pre[flag][p].size();i++){
		c[flag]+=cost[1-flag][p][pre[flag][p][i]];
		dfs(pre[flag][p][i]);
	}
	tmp.pop_back();
	return 0;
}

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int v1,v2,one,length,time;
		cin>>v1>>v2>>one>>length>>time;
		cost[0][v1][v2]=length;
		cost[1][v1][v2]=time;
		if(!one){
			cost[0][v2][v1]=length;
			cost[1][v2][v1]=time;			
		}
	}
	fill(minc,minc+2,INF);
	cin>>start>>des;
	flag=0;
	dijkstra(start);
	dfs(des);
	flag=1;
	dijkstra(start);
	dfs(des);
	bool isSame=true;
	if(path[0]!=path[1]){
		isSame=false;
	}
	if(isSame){
		printf("Distance = %d; Time = %d: ",d[0][des],d[1][des]);
		for(int i=path[0].size()-1;i>=0;i--){
			printf("%d%s",path[0][i],i==0?"":" -> ");
		}
	}else{
		printf("Distance = %d: ",d[0][des]);
		for(int i=path[0].size()-1;i>=0;i--){
			printf("%d%s",path[0][i],i==0?"\n":" -> ");
		}
		printf("Time = %d: ",d[1][des]);
		for(int i=path[1].size()-1;i>=0;i--){
			printf("%d%s",path[1][i],i==0?"\n":" -> ");
		}
	}
	return 0;
} 
