#include<iostream>
#include<map>
#include<set>

using namespace std;

struct NODE{
	string addr;
	int key;
	string next;
};

map<int,NODE> list;
set<int> order;

int main(){
	int i,key_tmp,N;
	string H,next_tmp,addr_tmp;
	cin>>N>>H;
	for(i=0;i<N;i++){
		cin>>addr_tmp>>key_tmp>>next_tmp;
		list.insert(pair<int,NODE>(key_tmp,NODE{addr_tmp,key_tmp,next_tmp}));
		order.insert(key_tmp);
	}
	cout<<N<<" "<<list.find(*order.begin())->second.addr<<endl;
	auto iter=order.begin();
	i=0;
	while(iter!=order.end()){
		cout<<list.find(*iter)->second.addr<<" "<<*iter<<" ";
		if(i!=N-1){
			iter++;
			cout<<list.find(*iter)->second.addr;
			iter--;
		}else{
			cout<<"-1";
		}
		cout<<endl;
		iter++;
		i++;
	}
	return 0;
} 
