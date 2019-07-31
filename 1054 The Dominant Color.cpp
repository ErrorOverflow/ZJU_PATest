#include<iostream>
#include<map>

using namespace std;

map<int,int> list;
map<int,int> order;

int main(){
	int i,j,tmp,M,N;
	cin>>M>>N;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			cin>>tmp;
			if(list.find(tmp)==list.end()){
				list.insert(pair<int,int>(tmp,1));
			}else{
				list.find(tmp)->second++;
			}
		}
	}
	auto iter=list.begin();
	while(iter!=list.end()){
		order.insert(pair<int,int>(iter->second,iter->first));
		iter++;
	}
	cout<<(--order.end())->second;
	return 0;
}

 
