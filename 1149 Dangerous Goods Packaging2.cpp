#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
	int i,j,t,N,M,K;
	int a,b;
	map<int,set<int>> list;
	cin>>N>>M;
	for(i=0;i<N;i++){
		cin>>a>>b;
		if(list.find(a)==list.end()){
			set<int> settmp;
			settmp.insert(b);
			list.insert(pair<int,set<int>>(a,settmp));
		}else{
			list.find(a)->second.insert(b);
		}
		if(list.find(b)==list.end()){
			set<int> settmp;
			settmp.insert(a);
			list.insert(pair<int,set<int>>(b,settmp));
		}else{
			list.find(b)->second.insert(b);
		}
	}
	for(i=0;i<M;i++){
		cin>>K;
		int s[K];
		bool isSafe=true;
		for(j=0;j<K;j++){
			cin>>s[j];
		}
		for(j=0;j<K-1;j++){
			auto iter=list.find(s[j]);
			if(iter==list.end()){
				continue;
			}
			for(t=j+1;t<K;t++){
				if(iter->second.find(s[t])!=iter->second.end()){
					isSafe=false;
					cout<<"No"<<endl;
					break;
				}
			}
			if(!isSafe){
				break;
			}
		}
		if(isSafe){
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
