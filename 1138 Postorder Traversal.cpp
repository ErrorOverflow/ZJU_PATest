#include<iostream>
#include<map>
using namespace std;

int main(){
	int N,n,i,j,root,low,high;
	cin>>N;
	int pre[N];
	int in[N];
	map<int,int> preloc,inloc;
	for(i=0;i<N;i++){
		cin>>n;
		pre[i]=n;
		preloc[n]=i;
	}
	for(i=0;i<N;i++){
		cin>>n;
		in[i]=n;
		inloc[n]=i;
	}
	low=j=0;
	high=N;
	while(true){
		root=inloc.find(pre[j++])->second;
		if(low==high-1){
			cout<<in[low];
			return 0;
		}
		if(root==low){
			low++;
		}else if(root==N-1){
			high--;
		}else{
			high=root;
		}
	}	
	return 0;
}
