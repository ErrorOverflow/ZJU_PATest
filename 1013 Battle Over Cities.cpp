#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

struct City{
	vector<int> next;
}city[1010];

int DFS(int begin, int des, int occupy, int *tmp){
	int i;
	if(begin==des){
		return 0;
	}
	tmp[begin]=1;
	//cout<<begin<<"#"<<des<<endl;
	for(i=0;i<city[begin].next.size();i++){
		//cout<<begin<<"#"<<des<<"#"<<city[begin].next[i]<<endl;
		if(city[begin].next[i]==occupy || tmp[city[begin].next[i]]==1){
			continue;
		}
		if(city[begin].next[i]==des){
			return 0;
		}
		if(!DFS(city[begin].next[i],des,occupy,tmp)){
			return 0;
		}
	}
	return 1;
}

int check(int occupy){
	int i,road=0;
	for(i=1;i<city[occupy].next.size();i++){
		int tmp[1010]={0};
		if(DFS(city[occupy].next[i-1],city[occupy].next[i],occupy,tmp)){
			//cout<<city[occupy].next[i-1]<<"*"<<city[occupy].next[i]<<endl;
			city[city[occupy].next[i-1]].next.push_back(city[occupy].next[i]);
			city[city[occupy].next[i]].next.push_back(city[occupy].next[i-1]);
			road++;
		}
	}
	return road;
}

int main(){
	int i,N,M,K,input1,input2;
	int con[1010];
	cin>>N>>M>>K;
	for(i=0;i<M;i++){
		cin>>input1>>input2;
		city[input1].next.push_back(input2);
		city[input2].next.push_back(input1);
	}
	for(i=0;i<K;i++){
		cin>>input1;
		con[i]=input1;
	}
	for(i=0;i<K;i++){
		cout<<check(con[i])<<endl;
	}
	return 0;
} 
