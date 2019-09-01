#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct Node{
	int right;
	int left;
};

map<int,Node> tree;
int root,state=0;
bool isHeap=true;
vector<int> res;

int DFS(int p){
	res.push_back(p);
	if(tree.find(p)->second.right!=-1){
		DFS(tree.find(p)->second.right);
	}
	if(tree.find(p)->second.left!=-1){
		DFS(tree.find(p)->second.left);
	}
	if(tree.find(p)->second.right==-1 && tree.find(p)->second.left==-1){
		for(int i=0,pre=-1;i<res.size();i++){
			cout<<res[i];
			if(pre==-1){
			}else if(res[i]>=pre){
				if(state==0){
					state=1;
				}else if(state==2){
					isHeap=false;
				}
			}else{
				if(state==0){
					state=2;
				}else if(state==1){
					isHeap=false;
				}
			}
			if(i!=res.size()-1){
				cout<<" ";
			}
			pre=res[i];
		}
		cout<<endl;		
	}
	res.pop_back();
	return 0;
}

int main(){
	int N,i,j,k,low,high;
	cin>>N;
	int num[N];
	for(i=0;i<N;i++){
		cin>>num[i];
		tree.insert(pair<int,Node>(num[i],Node{-1,-1}));
	}
	root=num[0];
	low=0;
	high=1;
	while(true){
		k=high-low;
		if(high>=N){
			break;
		}
		for(i=low,j=high;i<high && j<N;i++){
			tree.find(num[i])->second.left=num[j++];
			if(j<N)
				tree.find(num[i])->second.right=num[j++];
			//cout<<num[i]<<"->"<<tree.find(num[i])->second.left<<" "<<tree.find(num[i])->second.right<<endl;
		}
		low=high;
		high+=2*k;
	}
	DFS(root);
	if(isHeap){
		if(state==1){
			cout<<"Min Heap";
		}else{
			cout<<"Max Heap";
		}
	}else{
		cout<<"Not Heap";
	}
	return 0;
} 
