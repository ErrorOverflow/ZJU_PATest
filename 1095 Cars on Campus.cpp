#include<iostream>
#include<map>
#include<string>
#include<set>
#include<vector>
using namespace std;

int N,K;

struct Car{
	map<int,int> inout;
	vector<int> real;
};

int timechange(string t){
	return stoi(string(t.substr(0,2)))*3600+stoi(string(t.substr(3,2)))*60+stoi(string(t.substr(6,2)));
}

int display(int t){
	int h,m,s;
	h=t/3600;
	t%=3600;
	m=t/60;
	t%=60;
	s=t;
	if(h<10){
		cout<<"0";
	}
	cout<<h<<":";
	if(m<10){
		cout<<"0";
	}
	cout<<m<<":";
	if(s<10){
		cout<<"0";
	}
	cout<<s;
}

int main(){
	int i,j,now;
	string t,id,state;
	map<string,Car> record;
	map<int,int> maptmp;
	cin>>N>>K;
	for(i=0;i<N;i++){
		cin>>id>>t>>state;
		if(record.find(id)==record.end()){
			record.insert(pair<string,Car>(id,Car{}));
		}
		if(state=="in"){
			record.find(id)->second.inout.insert(pair<int,int>(timechange(t),0));
		}else{
			record.find(id)->second.inout.insert(pair<int,int>(timechange(t),1));
		}
	}
	for(auto iter=record.begin();iter!=record.end();iter++){
		bool isLegal=false;
		int pair;
		int flag=0;
		for(auto it=iter->second.inout.begin();it!=iter->second.inout.end();it++){
			if(flag){
				if(it->second==0){
					pair=it->first;
				}else{
					iter->second.real.push_back(pair);
					iter->second.real.push_back(it->first);
					flag=0;
				}
			}else{
				if(it->second==0){
					pair=it->first;
					flag=1;
				}
			}
		}
	}
	for(i=0;i<K;i++){
		cin>>t;
		now=timechange(t);
		int cars=0;
		for(auto iter=record.begin();iter!=record.end();iter++){
			for(auto it=iter->second.real.begin();it!=iter->second.real.end();it++){
				if(*it<=now){
					it++;
					if(*it>now){
						cars++;
						break;						
					}
				}
			}
		}
		cout<<cars<<endl;
	}
	int maxt=0;
	int stop=0;
	set<string> res;
	for(auto iter=record.begin();iter!=record.end();iter++){
		stop=0;
		for(auto it=iter->second.real.begin();it!=iter->second.real.end();it++){
			stop-=*it;
			it++;
			stop+=*it;
		}
		if(stop>=maxt){
			if(stop>maxt){
				maxt=stop;
				res.clear();
			}
			res.insert(iter->first);
		}
	}
	for(auto iter=res.begin();iter!=res.end();iter++){
		cout<<*iter<<" ";
	}
	display(maxt);
	return 0;
} 
