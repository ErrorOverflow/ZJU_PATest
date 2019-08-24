#include<iostream>
#include<map>
using namespace std;

int main(){
	int N,K,i,j,t,a,b;
	map<int,int> list;
	multimap<int,int> ranklist;
	cin>>N>>K;
	for(i=0;i<N;i++){
		cin>>t;
		if(i!=0){
			ranklist.clear();
			for(auto iter=list.begin();iter!=list.end();iter++){
				ranklist.insert(pair<int,int>(iter->second,iter->first));
			}
			j=0;
			cout<<t<<": ";
			for(auto iter=ranklist.rbegin();iter!=ranklist.rend() && j<K;iter++,j++){
				cout<<-iter->second;
				if(j!=ranklist.size()-1 && j!=K-1){
					cout<<" ";
				}
			}
			cout<<endl;
		}
		if(list.find(-t)==list.end()){
			list.insert(pair<int,int>(-t,1));
		}else{
			list[-t]++;
		}
	}
	return 0;
}
