#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N;
int tree[21][2];

int main(){
	int i,j,root;
	bool isRoot[21]={false};
	char t;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>t;
		if(t=='-'){
			tree[i][0]=-1;
		}else{
			tree[i][0]=t-'0';
			isRoot[tree[i][0]]=true;
		}
		cin>>t;
		if(t=='-'){
			tree[i][1]=-1;
		}else{
			tree[i][1]=t-'0';
			isRoot[tree[i][1]]=true;
		}
	}
	for(i=0;i<N;i++){
		if(!isRoot[i]){
			root=i;
			break;
		}
	}
	//cout<<root<<endl;
	vector<int> list[2];
	int flag=0,level=0,res;
	bool isComplete=true;
	bool isVisit[21]={false};
	list[flag].push_back(root);
	while(!list[flag].empty()){
		level++;
		list[1-flag].clear();
		for(i=0;i<list[flag].size();i++){
			auto iter=list[flag].begin();
			cout<<flag<<" "<<i<<" "<<*iter<endl;
			cout<<list[flag][i]<<endl;
			if((list[flag][i]>=0 && tree[list[flag][i]][0]>=0 && isVisit[tree[list[flag][i]][0]]) || (list[flag][i]>=0 && tree[list[flag][i]][1]>=0 && isVisit[tree[list[flag][i]][1]])){
				cout<<"NO "<<root;
				return 0;
			}
			if(list[flag][i]>=0){
				isVisit[tree[list[flag][i]][0]]=true;
				isVisit[tree[list[flag][i]][1]]=true;				
			}
			if(tree[list[flag][i]][0]!=-1){
				list[1-flag].push_back(tree[list[flag][i]][0]);
			}
			if(tree[list[flag][i]][1]!=-1){
				list[1-flag].push_back(tree[list[flag][i]][1]);
			}
		}
		if(list[flag].size()!=pow(2,level-1) && list[1-flag].size()!=0){
			isComplete=false;
			break; 
		}
		flag=1-flag;
	}
	res=list[1-flag][list[1-flag].size()-1];
	if(isComplete){
		cout<<"YES "<<res;
	}else{
		cout<<"NO "<<root;
	}
	return 0;
}
