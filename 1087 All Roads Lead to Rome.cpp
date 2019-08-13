#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct City{
	int num;
	int happy;
	vector<string> next;
	vector<int> cost;
};

string start;
int N,K,solution=0,max_h=0,max_a=0,min_len=1e9+7,happiness=0,leng=0;
map<string,City> list;
vector<string> res;
vector<string> routine;

int DFS(string now,bool* isVisit){
	int i,tnum;
	string t;
	if(now=="ROM"){
		solution++;
		if(leng<=min_len){
			if(happiness>=max_h){
				if(happiness/routine.size()>max_a){
					max_h=happiness;
					max_a=happiness/routine.size();
					min_len=leng;
					res.assign(routine.begin(),routine.end());					
				}
			}
		}
		return 0;
	}
	auto iter=list.find(now);
	for(i=0;i<iter->second.next.size();i++){
		t=iter->second.next[i];
		tnum=list.find(t)->second.num;
		if(!isVisit[tnum]){
			isVisit[tnum]=true;
			routine.push_back(t);
			leng+=iter->second.cost[i];
			happiness+=list.find(iter->second.next[i])->second.happy;
			//cout<<now<<"->"<<t<<" "<<leng<<" "<<happiness<<endl;
			DFS(t,isVisit);
			happiness-=list.find(iter->second.next[i])->second.happy;
			leng-=iter->second.cost[i];
			routine.pop_back();
			isVisit[tnum]=false;
		}
	}
	return 0;
}

int main(){
	int i,j,c,h;
	string a,b;
	cin>>N>>K>>start;
	list.insert(pair<string,City>(start,City{0}));
	for(i=0;i<N-1;i++){
		cin>>a>>h;
		list.insert(pair<string,City>(a,City{i+1,h}));
	}
	for(i=0;i<K;i++){
		cin>>a>>b>>c;
		list.find(a)->second.next.push_back(b);
		list.find(a)->second.cost.push_back(c);
		list.find(b)->second.next.push_back(a);
		list.find(b)->second.cost.push_back(c);
	}
	bool isVisit[201]={false};
	isVisit[0]=true;
	DFS(start,isVisit);
	cout<<solution<<" "<<min_len<<" "<<max_h<<" "<<max_a<<endl;
	cout<<start<<"->";
	for(i=0;i<res.size();i++){
		cout<<res[i];
		if(i!=res.size()-1){
			cout<<"->";
		}
	}
	return 0;
}
