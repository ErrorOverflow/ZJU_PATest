#include<iostream>
#include<map>
using namespace std;

struct Node{
	string addr;
	int data;
	string next;
};

map<string,Node> list;

int main(){
	int N,K,i,j,data;
	string start,addr,next;
	cin>>start>>N>>K;
	for(i=0;i<N;i++){
		cin>>addr>>data>>next;
		list.insert(pair<string,Node>(addr,Node{addr,data,next}));
	}
	auto iter=list.find(start);
	i=0;
	for(auto ite=iter;ite!=list.end();ite=list.find(ite->second.next)){
		if(ite->second.data<0){
			if(i!=0){
				cout<<ite->first<<endl;
			}
			cout<<ite->first<<" "<<ite->second.data<<" ";
			i++;
		}
	}
	for(auto ite=iter;ite!=list.end();ite=list.find(ite->second.next)){
		if(ite->second.data>=0 && ite->second.data<=K){
			if(i!=0){
				cout<<ite->first<<endl;
			}
			cout<<ite->first<<" "<<ite->second.data<<" ";
			i++;
		}		
	}
	for(auto ite=iter;ite!=list.end();ite=list.find(ite->second.next)){
		if(ite->second.data>K){
			if(i!=0){
				cout<<ite->first<<endl;
			}
			cout<<ite->first<<" "<<ite->second.data<<" ";
			i++;
		}		
	}
	cout<<"-1";
	return 0;
}
