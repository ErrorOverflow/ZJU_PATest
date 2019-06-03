#include<iostream>
#include<map>

using namespace std;

map<int,int> list;

int main(){
	int N,i,num;
	int n[100010];
	bool is[100010];
	cin>>N;
	for(i=0;i<N;i++){
		cin>>num;
		n[i]=num;
		is[i]=true;
		if(list.find(num)==list.end()){
			list.insert(pair<int,int>(num,i));
		}else{
			is[list.find(num)->second]=false;
			is[i]=false;
		}
	}
	for(i=0;i<N;i++){
		if(is[i]){
			cout<<n[i];
			return 0;	
		}
	}
	cout<<"None";
	return 0;
} 
