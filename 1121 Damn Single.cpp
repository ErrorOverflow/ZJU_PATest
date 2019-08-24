#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
	int N,i,j,k,Q;
	string a,b;
	map<string,string> couple;
	set<string> res;
	set<string> wait;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>a>>b;
		couple.insert(pair<string,string>(a,b));
		couple.insert(pair<string,string>(b,a));
	}
	cin>>Q;
	for(i=0;i<Q;i++){
		cin>>a;
		auto iter=couple.find(a);
		if(iter==couple.end()){
			res.insert(a);
		}else{
			auto it=wait.find(iter->second);
			if(it!=wait.end()){
				wait.erase(it);
			}else{
				wait.insert(a);
			}
		}
	}
	for(auto iter=wait.begin();iter!=wait.end();iter++){
		res.insert(*iter);
	}
	cout<<res.size()<<endl;
	i=0;
	for(auto iter=res.begin();iter!=res.end();iter++,i++){
		cout<<*iter;
		if(i!=res.size()-1){
			cout<<" ";
		}
	}
	return 0;
} 
