#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Node{
	string addr;
	int data;
	string next;
};

map<string,Node> list;

int main(){
	int i,j,data,N,R,can;
	string start,addr,next;
	cin>>start>>N>>R;
	for(i=0;i<N;i++){
		cin>>addr>>data>>next;
		list.insert(pair<string,Node>(addr,Node{addr,data,next}));
	}
	can=0;
	auto iter=list.find(start);
	vector<Node> queue;
	bool isFirst=true;
	while(true){
		if(iter->second.next=="-1"){
			//cout<<"end:"<<iter->first<<endl;
			queue.push_back(iter->second);
			can++;
			if(can!=R){
				if(!isFirst){
					cout<<queue[0].addr<<endl;
				}else{
					isFirst=false;
				}
				for(j=0;j<queue.size();j++){
					cout<<queue[j].addr<<" "<<queue[j].data<<" ";
					if(j!=queue.size()-1){
						cout<<queue[j+1].addr<<endl;
					}
				}
				break;				
			}
		}
		if(can==R){
			if(!isFirst){
				cout<<queue[R-1].addr<<endl;
			}else{
				isFirst=false;
			}
			for(j=R-1;j>=0;j--){
				cout<<queue[j].addr<<" "<<queue[j].data<<" ";
				if(j!=0){
					cout<<queue[j-1].addr<<endl;
				}
			}
			queue.clear();
			can=0;
		}
		if(iter->second.next=="-1"){
			break;
		}
		queue.push_back(iter->second);
		iter=list.find(iter->second.next);
		can++;
	}
	cout<<"-1";
	return 0;
}
