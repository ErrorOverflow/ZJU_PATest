#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N,L;
int vis[1001];
vector<int> user[1001];

int main(){
	scanf("%d%d",&N,&L);
	for(int i=0;i<N;i++){
		int K;
		scanf("%d",&K);
		for(int j=0;j<K;j++){
			int fans;
			scanf("%d",&fans);
			user[fans].push_back(i+1);
		}
	}
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		int q,num=0,level=0,flag=0;
		scanf("%d",&q);
		vector<int> list[2];
		list[0].push_back(q);
		fill(vis,vis+1001,0);
		vis[q]=1;
		while(!list[flag].empty()){
			list[1-flag].clear();
			for(int j=0;j<list[flag].size();j++){
				if(vis[list[flag][j]]>L){
					continue;
				}
				for(int k=0;k<user[list[flag][j]].size();k++){
					int u=user[list[flag][j]][k];
					if(vis[u]==0){
						list[1-flag].push_back(u);
						vis[u]=vis[list[flag][j]]+1;
						num++;			
					}else if(vis[list[flag][j]]+1<vis[u]){
						list[1-flag].push_back(u);
						vis[u]=vis[list[flag][j]]+1;
					}
				}
			}
			flag=1-flag;
		}
		printf("%d\n",num);
	}
	return 0;
} 
