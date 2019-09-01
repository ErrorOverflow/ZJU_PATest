#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> in;
vector<int> pre;
vector<int> post;
int N;

int dfs(int inleft,int inright,int preleft,int preright){
	if(inleft==inright){
		post.push_back(pre[preleft]);
		return 0;
	}
	int mid;
	for(mid=inleft;in[mid]!=pre[preleft];mid++);
	if(mid>inleft)
		dfs(inleft,mid-1,preleft+1,preleft+mid-inleft);
	if(mid<inright)
		dfs(mid+1,inright,preleft+mid-inleft+1,preright);
	post.push_back(in[mid]);
	return 0;
}

int main(){
	scanf("%d",&N);
	vector<int> stack;
	for(int i=0;i<2*N;i++){
		string s;
		cin>>s;
		if(s=="Push"){
			int a;
			scanf("%d",&a);
			stack.push_back(a);
			pre.push_back(a);
		}else if(s=="Pop"){
			in.push_back(*stack.rbegin());
			stack.pop_back();
		}
	}
	dfs(0,N-1,0,N-1);
	for(int i=0;i<N;i++)
		printf("%d%s",post[i],i==N-1?"":" ");
	return 0;
}
