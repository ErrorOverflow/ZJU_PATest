#include<iostream>
#include<map>
#include<set>

using namespace std;

struct _node{
	string addr;
	char data;
	string next;
};

map<string,_node> list;
set<string> alist;

map<string,_node>::iterator iter;

int main(){
	int i,N;
	string a,b,addr,next;
	char data;
	cin>>a>>b>>N;
	for(i=0;i<N;i++){
		cin>>addr>>data>>next;
		list.insert(pair<string,_node>(addr,_node{addr,data,next}));
	}
	iter=list.find(a);
	while(true){
		alist.insert(iter->first);
		if(iter->second.next=="-1"){
			break;
		}
		iter=list.find(iter->second.next);
	}
	iter=list.find(b);
	while(true){
		if(alist.find(iter->first)!=alist.end()){
			cout<<iter->first;
			return 0;
		}
		if(iter->second.next=="-1"){
			break;
		}
		iter=list.find(iter->second.next);		
	}
	cout<<-1;
	return 0;
}
