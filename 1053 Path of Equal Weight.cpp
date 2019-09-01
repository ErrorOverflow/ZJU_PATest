#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int N,M;
long long S;
vector<int> res[100];
vector<int> link[100];
int weight[100];
int solu;
long long wei;
vector<int> tmp;

int DFS(int p){
	if(wei==S && link[p].empty()){
		for(int i=0;i<tmp.size();i++){
			res[solu].push_back(tmp[i]);
		}
		solu++;
		return 0;
	}
	if(wei>=S){
		return 0;
	}
	for(int i=0;i<link[p].size();i++){
		tmp.push_back(link[p][i]);
		wei+=weight[link[p][i]];
		DFS(link[p][i]);
		wei-=weight[link[p][i]];
		tmp.pop_back();
	}
	return 0;
}

bool cmp(int a, int b){
	return weight[a]>weight[b];
}

int main(){
	int i,j,a,id,K;
	scanf("%d%d%lld",&N,&M,&S);
	for(i=0;i<N;i++){
		scanf("%d",&weight[i]);
	}
	for(i=0;i<M;i++){
		scanf("%d%d",&id,&K);
		for(j=0;j<K;j++){
			scanf("%d",&a);
			link[id].push_back(a);
		}
	}
	for(i=0;i<N;i++){
		sort(link[i].begin(),link[i].end(),cmp);
	}
	wei+=weight[0];
	tmp.push_back(0);
	DFS(0);
	for(i=0;i<solu;i++){
		for(j=0;j<res[i].size();j++){
			printf("%d%s",weight[res[i][j]],j==res[i].size()-1?"\n":" ");
		}
	}
	return 0;
}
