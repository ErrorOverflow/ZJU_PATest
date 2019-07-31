#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>

using namespace std;

struct PERSON{
	string name;
	int age;
	int worth;
};

int N,K;

map<string,PERSON> namelist;
map<int,set<string>> agelist;

int main(){
	string name;
	int i,j,age,worth,amin,amax,num;
	cin>>N>>K;
	for(i=0;i<N;i++){
		cin>>name>>age>>worth;
		namelist.insert(pair<string,PERSON>(name,PERSON{name,age,worth}));
		if(agelist.find(age)==agelist.end()){
			set<string> tmpage;
			tmpage.insert(name);
			agelist.insert(pair<int,set<string>>(age,tmpage));
		}else{
			agelist.find(age)->second.insert(name);
		}
	}
	for(i=0;i<K;i++){
		cin>>num>>amin>>amax;
		map<int,vector<string>> worthlist;
		for(j=amin;j<=amax;j++){
			auto tmpiter = agelist.find(j);
			if(tmpiter!=agelist.end()){
				set<string>::iterator iter = tmpiter->second.begin();
				while(iter!=tmpiter->second.end()){
					if(worthlist.find(namelist.find(*iter)->second.worth)!=worthlist.end()){
						worthlist.find(namelist.find(*iter)->second.worth)->second.push_back(*iter);
					}else{
						vector<string> tmpworth;
						tmpworth.push_back(*iter);
						worthlist.insert(pair<int,vector<string>>(namelist.find(*iter)->second.worth,tmpworth));
					}
					iter++;
				}
			}
		}
		cout<<"Case #"<<i+1<<":"<<endl;
		if(worthlist.empty()){
			cout<<"None"<<endl;
			continue;
		}
		auto iter_worth = worthlist.end();
		iter_worth--;
		int round = num;
		while(iter_worth!=worthlist.begin()){
			auto iter_tmp = iter_worth->second.begin();
			while(iter_tmp!=iter_worth->second.end()){
				if(round==0){
					break;
				}
				cout<<*iter_tmp<<" "<<namelist.find(*iter_tmp)->second.age<<" "<<namelist.find(*iter_tmp)->second.worth<<endl;
				round--;
				iter_tmp++;
			}
			iter_worth--;
		}
		if(round!=0){
			auto iter_tmp = iter_worth->second.begin();
			while(iter_tmp!=iter_worth->second.end()){
				if(round==0){
					break;
				}
				cout<<*iter_tmp<<" "<<namelist.find(*iter_tmp)->second.age<<" "<<namelist.find(*iter_tmp)->second.worth<<endl;
				round--;
				iter_tmp++;
			}	
		}
	}
	return 0;
}
