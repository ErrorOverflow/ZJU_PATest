#include<iostream>
#include<set>
#include<map>
using namespace std;

int main(){
	int V,N,a,b,i,j,k,K,n,start,pre;
	map<int,int> link;
	cin>>V>>N;
	for(i=0;i<N;i++){
		cin>>a>>b;
		link.insert(pair<int,int>(a,b));
		link.insert(pair<int,int>(b,a));
	}
	cin>>K;
	for(i=0;i<K;i++){
		cin>>k;
		set<int> visit;
		bool isCycle=true;
		if(k!=V+1){
			isCycle=false;
		}
		for(j=0;j<k;j++){
			cin>>a;
			if(j==0){
				start=a;
				visit.insert(a);
				pre=a;
			}else if(j==k-1){
				if(a!=start){
					isCycle=false;
				}
			}else{
				if(visit.find(a)!=visit.end()){
					isCycle=false;				
				}else{
					visit.insert(a);
				}
			}
		}
		if(isCycle){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
