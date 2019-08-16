#include<iostream>
#include<map>
#include<vector>
#include<cmath>

using namespace std;

struct Node{
	string id;
	int value;
	string next;
};

map<string,Node> list;
vector<string> res;
vector<string> res2;

int main(){
	string start,id,next;
	int i,j,N,v;
	bool values[10001]={false};
	cin>>start>>N;
	for(i=0;i<N;i++){
		cin>>id>>v>>next;
		list.insert(pair<string,Node>(id,Node{id,v,next}));
	}
	for(auto iter=list.find(start);iter!=list.end();iter=list.find(iter->second.next)){
		if(!values[abs(iter->second.value)]){
			res.push_back(iter->first);
			values[abs(iter->second.value)]=true;
		}else{
			res2.push_back(iter->first);
		}
		if(iter->second.next=="-1"){
			break;
		}
	}
	for(i=0;i<res.size();i++){
		auto iter=list.find(res[i]);
		if(i!=res.size()-1)
			cout<<iter->second.id<<" "<<iter->second.value<<" "<<list.find(res[i+1])->second.id<<endl;
		else
			cout<<iter->second.id<<" "<<iter->second.value<<" -1"<<endl;
	}
	for(i=0;i<res2.size();i++){
		auto iter=list.find(res2[i]);
		if(i!=res2.size()-1){
			cout<<iter->second.id<<" "<<iter->second.value<<" "<<list.find(res2[i+1])->second.id<<endl;
		}
		else{
			cout<<iter->second.id<<" "<<iter->second.value<<" -1"<<endl;
		}
	}
}
