#include<iostream>
#include<set>
using namespace std;

set<string> list[2501];

int main(){
	int i,j,N,K,num,tmp;
	string name;
	cin>>N>>K;
	for(i=0;i<N;i++){
		cin>>name;
		cin>>num;
		for(j=0;j<num;j++){
			cin>>tmp;
			list[tmp].insert(name);
		}
	}
	for(i=1;i<=K;i++){
		cout<<i<<" "<<list[i].size()<<endl;
		auto iter=list[i].begin();
		while(iter!=list[i].end()){
			cout<<*iter<<endl;
			iter++;
		}
	}
	return 0;
}
