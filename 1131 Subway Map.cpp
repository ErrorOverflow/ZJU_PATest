#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;
const int maxv=10000;
const int INF=1e9+7;
bool link[maxv][maxv];
int tube[maxv][maxv];
set<int> node;
vector<int> pre[maxv],tmp,path,respath;
vector<int> res;
set<int> station[maxv];
bool vis[maxv];
int dd[maxv];
int N,start,des,tansfer;

int dijkstra(int s){
	fill(vis,vis+maxv,false);
	fill(dd,dd+maxv,INF);
	dd[s]=0;
	while(true){
		int mini=-1,minl=INF;
		for(auto iter=node.begin();iter!=node.end();iter++){
			if(dd[*iter]<minl && !vis[*iter]){
				minl=dd[*iter];
				mini=*iter;
			}
		}
		if(mini==-1){
			break;
		}
		vis[mini]=true;
		for(auto iter=node.begin();iter!=node.end();iter++){
			if(!vis[*iter] && link[*iter][mini]){
				if(dd[mini]+1<dd[*iter]){
					dd[*iter]=dd[mini]+1;
					pre[*iter].clear();
					pre[*iter].push_back(mini);
				}else if(dd[mini]+1==dd[*iter]){
					pre[*iter].push_back(mini);
				}
			}
		}
	}
	return 0;
} 

int dfs(int p){
	if(p==start){
		tmp.push_back(p);
		int t=0;
		for(int i=0,pre;i<path.size();i++){
			if(i!=0 && pre!=i){
				t++;
			} 
			pre=path[i];
		}
		if(t<tansfer){
			res.assign(tmp.begin(),tmp.end());
			respath.assign(path.begin(),path.end());
		}
		tmp.pop_back();
		return 0;
	}
	tmp.push_back(p);
	for(int i=0;i<pre[p].size();i++){
		path.push_back(tube[p][pre[p][i]]);
		dfs(pre[p][i]);
		path.pop_back();
	}
	tmp.pop_back();
	return 0;
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int M,s,p,pre;
		scanf("%d",&M);
		for(int j=0;j<M;j++){
			scanf("%d",&p);
			if(j==0)s=p;
			else{
				link[pre][p]=true;
				link[p][pre]=true;
				tube[p][pre]=i;
				tube[pre][p]=i;
			}
			pre=p;
			node.insert(p);
			station[p].insert(i);
		}
	}
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		tansfer=INF;
		scanf("%d%d",&start,&des);
		dijkstra(start);
		dfs(des);
		printf("%d\n",res.size()-1);
		for(int k=res.size()-1;k>=0;k--){
			if(k==res.size()-1){
				printf("Take Line#%d from %04d to ",path[respath.size()-1],res[k]);
			}else if(k==0){
				printf("%d.\n",res[0]);
			}else if(respath[k-1]!=respath[k]){
				printf("%d.\nTake Line#%d from %04d to ",res[k],respath[k-1],res[k]);
			}
		}
		tmp.clear();
		respath.clear();
		path.clear();
		res.clear();
		for(auto iter=node.begin();iter!=node.end();iter++){
			pre[*iter].clear();
		}
	}
	return 0;
}
