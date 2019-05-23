#include<iostream>
#include<map>
#include<set>

using namespace std;

int N;

map<int,set<string>> res;

map<string,int> local;

map<string,int> location;

map<int,set<string>> lRank;

int main(){
	string s;
	int K,total=0,i,j,k,score,finalRank,localRank;
	map<int,set<string>>::iterator iter_res;
	set<string>::iterator iter_set;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>K;
		total+=K;
		lRank.clear();
		for(j=0;j<K;j++){
			cin>>s;
			cin>>score;
			if(lRank.find(score)!=lRank.end()){
				lRank.find(score)->second.insert(s);
			}else{
				set<string> tmp;
				tmp.insert(s);
				lRank.insert(pair<int,set<string>>(score,tmp));
			}
			if(res.find(score)!=res.end()){
				res.find(score)->second.insert(s);
			}else{
				set<string> tmp;
				tmp.insert(s);
				res.insert(pair<int,set<string>>(score,tmp));
			}
			location.insert(pair<string,int>(s,i));
		}
		iter_res=lRank.end();
		localRank=1;
		while(--iter_res!=lRank.begin()){
			iter_set=iter_res->second.begin();
			while(iter_set!=iter_res->second.end()){
				int int_tmp;
				int_tmp=localRank;
				local.insert(pair<string,int>(*iter_set,int_tmp));
				iter_set++;
			}
			localRank+=iter_res->second.size();
		}
		iter_set=iter_res->second.begin();
		while(iter_set!=iter_res->second.end()){
			int int_tmp;
			int_tmp=localRank;
			local.insert(pair<string,int>(*iter_set,int_tmp));
			iter_set++;
		}
	}
	
	iter_res=res.end();
	finalRank=1;
	cout<<total<<endl;
	while(--iter_res!=res.begin()){
		iter_set=iter_res->second.begin();
		while(iter_set!=iter_res->second.end()){
			cout<<*iter_set<<" "<<finalRank<<" "<<location.find(*iter_set)->second+1<<" "<<local.find(*iter_set)->second<<endl;
			iter_set++;
		}
		finalRank+=iter_res->second.size();
	}
	iter_set=iter_res->second.begin();
	while(iter_set!=iter_res->second.end()){
		cout<<*iter_set<<" "<<finalRank<<" "<<location.find(*iter_set)->second+1<<" "<<local.find(*iter_set)->second<<endl;
		iter_set++;
	}	
}
