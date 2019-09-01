#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
	int N,M,Q,i,j,k,a,b;
	cin>>N>>M;
	int color[N];
	vector<int> next[N];
	for(i=0;i<M;i++){
		cin>>a>>b;
		next[a].push_back(b);
		next[b].push_back(a);
	}
	cin>>Q;
	for(i=0;i<Q;i++){
		set<int> use;
		bool isF=true;
		for(j=0;j<N;j++){
			cin>>color[j];
			if(use.find(color[j])==use.end()){
				use.insert(color[j]);
			}
		}
		for(j=0;j<N;j++){
			for(k=0;k<next[j].size();k++){
				if(color[next[j][k]]==color[j]){
					isF=false;
					break;
				}
			}
			if(!isF){
				break;
			}
		}
		if(isF){
			cout<<use.size()<<"-coloring"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
