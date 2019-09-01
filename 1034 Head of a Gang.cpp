#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
const int maxv=10001;
int N,K;
int call[maxv][maxv];
bool isvisit[maxv];
map<string,int> id;
map<int,string> mean;

int main(){
	cin>>N>>K;
	int i,j,k,t,ida,idb,Q;
	string a,b;
	for(i=0,j=0;i<N;i++){
		cin>>a>>b>>t;
		if(id.find(a)==id.end()){
			id.insert(pair<string,int>(a,j));
			ida=j;
			mean.insert(pair<int,string>(j++,a));
		}else{
			ida=id.find(a)->second;
		}
		if(id.find(b)==id.end()){
			id.insert(pair<string,int>(b,j));
			idb=j;
			mean.insert(pair<int,string>(j++,b));
		}else{
			idb=id.find(b)->second;
		}
		call[ida][idb]+=t;
		call[idb][ida]+=t;	
	}
	Q=j;
	vector<int> res;
	vector<int> rest;
	for(i=0;i<Q;i++){
		if(isvisit[i]){
			continue;
		}
		vector<int> list[3];
		int flag,total;
		flag=total=0;
		list[flag].push_back(i);
		while(list[flag].size()!=0){
			list[1-flag].clear();
			for(j=0;j<list[flag].size();j++){
				if(isvisit[list[flag][j]]){
					continue;
				}
				isvisit[list[flag][j]]=true;
				list[2].push_back(list[flag][j]);
				for(k=0;k<Q;k++){
					if(isvisit[k]){
						continue;
					}
					if(call[k][list[flag][j]]){
						total+=call[k][list[flag][j]];
						list[1-flag].push_back(k);
					}
				}
			}
			flag=1-flag;
		}
		int maxt=0,maxn,time[maxv]={0};
		if(total<=K || list[2].size()<=2){
			continue;
		}
		for(j=0;j<list[2].size();j++){
			for(k=j+1;k<list[2].size();k++){
				time[j]+=call[list[2][j]][list[2][k]];
				time[k]+=call[list[2][j]][list[2][k]];
			}
			if(time[j]>maxt){
				maxt=time[j];
				maxn=list[2][j];
			}
			isvisit[list[2][j]]=true;
			//cout<<list[2][j]<<" ";
		}
		//cout<<endl;
		if(!list[2].empty()){
			res.push_back(maxn);
			rest.push_back(list[2].size()); 			
		}
	}
	printf("%d\n",res.size());
	for(i=0;i<res.size();i++){
		cout<<mean.find(res[i])->second<<" "<<rest[i]<<endl;
	}
	return 0;
} 
