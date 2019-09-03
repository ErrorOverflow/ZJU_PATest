#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=1e9+7;
const int maxv=1001;
int N,L;
bool vis[maxv];
vector<int> user[maxv];
int dd[maxv];

int dijkstra(int s){
	fill(dd,dd+max,INF);
	dd[s]=0;
	find min;
	vis[u]=true;	
}

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
		
		printf("%d\n",num);
	}
	return 0;
}
