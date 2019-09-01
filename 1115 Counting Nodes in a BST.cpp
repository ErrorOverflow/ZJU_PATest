#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct Node{
	int num;
	int left;
	int right;
};
map<int,Node> tree;
int N;

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int n;
		scanf("%d",&n);
		if(i==0){
			tree.insert(pair<int,Node>(i,Node{n,-1,-1}));
		}else{
			auto iter=tree.find(0);
			tree.insert(pair<int,Node>(i,Node{n,-1,-1}));
			while(true){
				if(n<=iter->second.num){
					if(iter->second.left!=-1){
						iter=tree.find(iter->second.left);
					}else{
						iter->second.left=i;
						break;
					}
				}else{
					if(iter->second.right!=-1){
						iter=tree.find(iter->second.right);
					}else{
						iter->second.right=i;
						break;
					}					
				}
			}
		}
	}
	vector<int> list[2];
	int flag=0,n1,n2;
	list[0].push_back(0);
	while(!list[flag].empty()){
		n1=list[1-flag].size();
		n2=list[flag].size();
		list[1-flag].clear();
		for(int i=0;i<list[flag].size();i++){
			//cout<<list[flag][i]<<" ";
			int l=tree.find(list[flag][i])->second.left;
			int r=tree.find(list[flag][i])->second.right;
			if(l!=-1){
				list[1-flag].push_back(l);
			}
			if(r!=-1){
				list[1-flag].push_back(r);
			}
		}
		//cout<<endl;
		flag=1-flag;
	}
	printf("%d + %d = %d",n2,n1,n1+n2);
	return 0;
} 
