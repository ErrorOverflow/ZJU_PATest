#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N;

int tree[16][2];
vector<int> res;

int levelTra(int p){
	int i,j,flag=0;
	vector<int> list[2];
	list[0].push_back(p);
	while(!list[flag].empty()){
		for(i=0;i<list[flag].size();i++){
			res.push_back(list[flag][i]);
			if(tree[list[flag][i]][1]!=-1){
				list[1-flag].push_back(tree[list[flag][i]][1]);
			}
			if(tree[list[flag][i]][0]!=-1){
				list[1-flag].push_back(tree[list[flag][i]][0]);
			}
		}
		list[flag].clear();
		flag=1-flag;
	}
	return 0;
}

int inTra(int p){
	if(tree[p][1]!=-1){
		inTra(tree[p][1]);
	}
	res.push_back(p);
	if(tree[p][0]!=-1){
		inTra(tree[p][0]);
	}
	return 0;
}

int main(){
	int i,j,root;
	string a,b;
	bool isRoot[16]={false};
	cin>>N;
	for(i=0;i<N;i++){
		cin>>a>>b;
		if(a=="-"){
			tree[i][0]=-1;
		}else{
			tree[i][0]=stoi(a);
			isRoot[stoi(a)]=true;
		}
		if(b=="-"){
			tree[i][1]=-1;
		}else{
			tree[i][1]=stoi(b);
			isRoot[stoi(b)]=true;
		}
	}
	for(i=0;i<N;i++){
		if(!isRoot[i]){
			root=i;
			break;
		}
	}
	levelTra(root);
	for(i=0;i<res.size();i++){
		cout<<res[i];
		if(i!=res.size()-1){
			cout<<" ";
		}
	}
	cout<<endl;
	res.clear();
	inTra(root);
	for(i=0;i<res.size();i++){
		cout<<res[i];
		if(i!=res.size()-1){
			cout<<" ";
		}
	}	
	return 0;
}
