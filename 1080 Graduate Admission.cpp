#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

int N,M,K;
map<int,set<int>> list;
set<int> res[101];
int choice[40010][5];

int main(){
	int i,j,tmp,Ge,Gi;
	int quota[101];
	cin>>N>>M>>K;
	for(i=0;i<M;i++){
		cin>>tmp;
		quota[i]=tmp;
	}
	for(i=0;i<N;i++){
		cin>>Ge>>Gi;
		for(j=0;j<K;j++){
			cin>>choice[i][j];
		}
		tmp=(Ge+Gi)*10000+Ge*100+Gi;
		if(list.find(-tmp)==list.end()){
			set<int> tmpset;
			tmpset.insert(i);
			list.insert(pair<int,set<int>>(-tmp,tmpset));
		}
		else{
			list.find(-tmp)->second.insert(i);
		}
	}
	for(auto iter=list.begin();iter!=list.end();iter++){
		bool isChange[101]={false};
		for(auto it=iter->second.begin();it!=iter->second.end();it++){
			i=*it;
			//cout<<i<<" ";
			for(j=0;j<K;j++){
				if(quota[choice[i][j]]>0 || isChange[choice[i][j]]){
					res[choice[i][j]].insert(i);
					quota[choice[i][j]]--;
					isChange[choice[i][j]]=true;
					break;
				}
			}			
		}
		//cout<<endl;
	}
	for(i=0;i<M;i++){
		if(res[i].size()>0){
			auto ite=res[i].begin();
			cout<<*ite;
			ite++;
			for(;ite!=res[i].end();ite++){
				cout<<" "<<*ite;
			}
		}
		cout<<endl;
	}
	return 0;
}
