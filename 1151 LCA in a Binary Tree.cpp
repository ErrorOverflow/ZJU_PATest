#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

struct Node{
	int right;
	int left;
	int fa;
};

int M,N;
int pre[1001],in[1001];
map<int,int> inlist,prelist;

int main(){
	int i,j,a,b,p,index,low,high,mini;
	set<int> use;
	cin>>M>>N;
	for(i=0;i<N;i++){
		cin>>a;
		in[i]=a;
		use.insert(a);
		inlist.insert(pair<int,int>(a,i));
	}
	for(i=0;i<N;i++){
		cin>>a;
		pre[i]=a;
		prelist.insert(pair<int,int>(a,i));
	}
	for(i=0;i<M;i++){
		cin>>a>>b;
		if(use.find(a)==use.end()){
			if(use.find(b)==use.end()){
				cout<<"ERROR: "<<a<<" and "<<b<<" are not found."<<endl;
			}else{
				cout<<"ERROR: "<<a<<" is not found."<<endl;
			}
			continue;
		}else if(use.find(b)==use.end()){
			cout<<"ERROR: "<<b<<" is not found."<<endl;
			continue;
		}
		vector<int> list;
		low=min(inlist.find(a)->second,inlist.find(b)->second);
		high=max(inlist.find(a)->second,inlist.find(b)->second);
		for(j=low;j<=high;j++){
			list.push_back(in[j]);
		}
		int res;
		for(j=0,mini=N;j<list.size();j++){
			if(prelist.find(list[j])->second<mini){
				res=list[j];
				mini=prelist.find(list[j])->second;
			}
		}
		if(res==a){
			cout<<a<<" is an ancestor of "<<b<<"."<<endl;
		}else if(res==b){
			cout<<b<<" is an ancestor of "<<a<<"."<<endl;
		}else{
			cout<<"LCA of "<<a<<" and "<<b<<" is "<<res<<"."<<endl;
		}
	}
	return 0;
}
