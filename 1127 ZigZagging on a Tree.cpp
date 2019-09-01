#include<iostream>
#include<vector>
using namespace std;

int tree[31][2],post[31],in[31];
int N,root;

int dfs(int postleft,int postright,int inleft,int inright,int p){
	if(postleft==postright){
		tree[inleft][0]=tree[inleft][1]=-1;
		return inleft;
	}
	int i;
	for(i=inleft;in[i]!=post[postright];i++);
	if(inright-inleft==N-1){
		root=i;
	}
	int l,r;
	if(i-1>=inleft){
		l=dfs(postleft,postleft+i-1-inleft,inleft,i-1,i);
	}else{
		l=-1;
	}
	if(inright>=i+1){
		r=dfs(postleft+i-inleft,postright-1,i+1,inright,i);
	}else{
		r=-1;
	}
	tree[i][0]=l;
	tree[i][1]=r;
	//cout<<i<<" -> "<<l<<" "<<r<<endl;
	return i;
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&in[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&post[i]);
	}
	dfs(0,N-1,0,N-1,0);
	vector<int> list[2];
	int flag=0;
	list[0].push_back(root);
	printf("%d",post[N-1]);
	while(!list[flag].empty()){
		list[1-flag].clear();
		for(int i=0;i<list[flag].size();i++){
			int u=list[flag][i];
			if(u!=root && flag%2==1){
				printf(" %d",in[u]);
			}else if(u!=root){
				printf(" %d",in[list[flag][list[flag].size()-i-1]]);
			}
			if(tree[u][0]!=-1){
				list[1-flag].push_back(tree[u][0]);
			}
			if(tree[u][1]!=-1){
				list[1-flag].push_back(tree[u][1]);
			}
		}
		flag=1-flag;
	}
	return 0;
}
