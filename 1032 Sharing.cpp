#include<iostream>
#include<map>
#include<vector>

using namespace std;

struct Node{
	string n;
	char c;
	string next;
};

map<string,Node> list;
vector<>
int aused[1000000]={0};
int bused[1000000]={0};

map<string,Node>::iterator iter;
map<string,Node>::iterator it;
map<string,Node>::iterator record;

int main(){
	string a,b,n_input,next_input,p;
	int i,N,isSame=0;
	char c_input;
	cin>>a>>b>>N;
	for(i=0;i<N;i++){
		cin>>n_input>>c_input>>next_input;
		list.insert(pair<string,Node>(n_input,Node{n_input,c_input,next_input}));
	}
	iter=list.find(a);
	while(true){
		it=list.find(b);
		isSame=0;
		//cout<<iter->second.n<<endl;
		record=iter;
		while(true){
			//cout<<"    "<<it->second.n<<" "<<iter->second.n<<endl;
			if(it->second.n==iter->second.n){
				
			}
			if(it->second.n==iter->second.n && isSame==0){
				isSame=1;
				p=it->second.n;
			}
			if(isSame==1 && it->second.n!=iter->second.n){
				isSame=0;
				break;
			}
			if(it->second.next=="-1"){
				break;
			}
			it=list.find(it->second.next);
			iter=list.find(iter->second.next);
		}
		if(isSame>0 && iter->second.next=="-1"){
			cout<<p;
			return 0;
		}
		if(iter->second.next=="-1"){
			break;
		}
		iter=list.find(record->second.next);
	}
	cout<<-1;
	return 0;
} 
