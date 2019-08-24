#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int P,M,N,i,j,t;
	double td; 
	string s;
	map<string,int> program;
	map<string,int> mid;
	map<string,int> final;
	map<int,vector<string>> list;
	cin>>P>>M>>N;
	for(i=0;i<P;i++){
		cin>>s>>t;
		program.insert(pair<string,int>(s,t));
	}
	for(i=0;i<M;i++){
		cin>>s>>t;
		mid.insert(pair<string,int>(s,t));		
	}
	for(i=0;i<N;i++){
		cin>>s>>t;
		final.insert(pair<string,int>(s,t));		
	}
	for(auto iter=program.begin();iter!=program.end();iter++){
		if(iter->second<200){
			continue;
		}
		if(mid.find(iter->first)!=mid.end() && final.find(iter->first)!=final.end() && mid.find(iter->first)->second>final.find(iter->first)->second){
			td=((double)mid.find(iter->first)->second*0.4+(double)final.find(iter->first)->second*0.6);
			t=(int)td;
			if(td>=(double)t+0.5){
				t++;
			}
			if(t<60){
				continue;
			}
			if(list.find(t)==list.end()){
				vector<string> tmp;
				tmp.push_back(iter->first);
				list.insert(pair<int,vector<string>>(t,tmp));				
			}else{
				list.find(t)->second.push_back(iter->first);
			}
		}else if(final.find(iter->first)!=final.end()){
			if(final.find(iter->first)->second<60){
				continue;
			}
			if(list.find(final.find(iter->first)->second)==list.end()){
				vector<string> tmp;
				tmp.push_back(iter->first);
				list.insert(pair<int,vector<string>>(final.find(iter->first)->second,tmp));
			}else{
				list.find(final.find(iter->first)->second)->second.push_back(iter->first);
			}
		}
	}
	for(auto iter=list.rbegin();iter!=list.rend();iter++){
		sort(iter->second.begin(),iter->second.end());
		for(i=0;i<iter->second.size();i++){
			cout<<iter->second[i]<<" "<<program.find(iter->second[i])->second<<" ";
			if(mid.find(iter->second[i])==mid.end()){
				cout<<"-1 ";
			}else{
				cout<<mid.find(iter->second[i])->second<<" ";
			}
			if(final.find(iter->second[i])==final.end()){
				cout<<"-1 ";
			}else{
				cout<<final.find(iter->second[i])->second<<" ";
			}
			cout<<iter->first<<endl;
		}
	}
	return 0;
}
