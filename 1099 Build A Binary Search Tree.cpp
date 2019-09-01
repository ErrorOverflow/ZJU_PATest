#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,root;
vector<int> num;
int node[101][3];
int index=0;
int DFS(int p){
	if(node[p][0]!=-1){
		DFS(node[p][0]);
	}
	node[p][2]=num[index++];
	if(node[p][1]!=-1){
		DFS(node[p][1]);
	}
	return 0;
}

int main(){
	int a,b,i,j,k;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>a>>b;
		node[i][0]=a;
		node[i][1]=b;
	}
	for(i=0;i<N;i++){
		cin>>a;
		num.push_back(a);
	}
	sort(num.begin(),num.end());
	DFS(0);
	vector<int> next[2];
	int flag=0;
	next[flag].push_back(0);
	printf("%d",node[0][2]);
	while(!next[flag].empty()){
		next[1-flag].clear();
		for(i=0;i<next[flag].size();i++){
			if(next[flag][i]!=0){
				printf(" %d",node[next[flag][i]][2]);
			}
			if(node[next[flag][i]][0]!=-1){
				next[1-flag].push_back(node[next[flag][i]][0]);
			}
			if(node[next[flag][i]][1]!=-1){
				next[1-flag].push_back(node[next[flag][i]][1]);
			}
		}
		
		flag=1-flag;
	}
	return 0;
}
