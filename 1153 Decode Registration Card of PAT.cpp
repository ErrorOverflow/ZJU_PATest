#include<iostream>
#include<map>
#include<string>
#include<unordered_map> 
using namespace std;

int main(){
	int N,M,score,i,j,k,step;
	map<string,int> list;
	string name;
	cin>>N>>M;
	for(i=0;i<N;i++){
		cin>>name>>score;
		list.insert(pair<string,int>(name,score));
	}
	for(i=0;i<M;i++){
		cin>>step>>name;
		cout<<"Case "<<i+1<<": "<<step<<" "<<name<<endl;
		if(step==1){
			multimap<int,string> ranklist;
			for(auto iter=list.begin();iter!=list.end();iter++){
				if(iter->first.substr(0,1)==name){
					ranklist.insert(pair<int,string>(-iter->second,iter->first));
				}
			}
			if(ranklist.empty()){
				cout<<"NA"<<endl;
			}
			for(auto iter=ranklist.begin();iter!=ranklist.end();iter++){
				cout<<iter->second<<" "<<-iter->first<<endl;
			}
		}else if(step==2){
			int num=0,total=0;
			for(auto iter=list.begin();iter!=list.end();iter++){
				if(iter->first.substr(1,3)==name){
					num++;
					total+=iter->second;
				}
			}
			if(num==0){
				cout<<"NA"<<endl;
			}else{
				cout<<num<<" "<<total<<endl;
			}
		}else{
			unordered_map<string,int> count;
			for(auto iter=list.begin();iter!=list.end();iter++){
				if(iter->first.substr(4,6)==name) count[iter->first.substr(1,3)]++;
			}
			multimap<int,string> res;
			for(auto iter=count.begin();iter!=count.end();iter++){
				res.insert(pair<int,string>(-iter->second,iter->first));
			}
			if(res.empty()){
				cout<<"NA"<<endl;
			}
			for(auto iter=res.begin();iter!=res.end();iter++){
				cout<<iter->second<<" "<<-iter->first<<endl;
			}
		}
	}
	return 0;
}
