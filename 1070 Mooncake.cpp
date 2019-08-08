#include<iostream>
#include<map>
using namespace std;

map<double,int> list;

int main(){
	int N,demand;
	double cake[1010][2],amount,res;
	cin>>N>>demand;
	for(int i=0;i<N;i++){
		cin>>cake[i][0];
	}
	for(int i=0;i<N;i++){
		cin>>cake[i][1];
		if(list.find(-cake[i][1]/cake[i][0])!=list.end()){
			cake[list.find(-cake[i][1]/cake[i][0])->second][1]+=cake[i][1];
		}else{
			list.insert(pair<double,int>(-cake[i][1]/cake[i][0],i));
		}
	}
	amount=0;
	res=0;
	auto iter=list.begin();
	while(true){
		if(iter==list.end()){
			break;
		}
		if(amount+cake[iter->second][0]>=demand){
			res+=(demand-amount)*cake[iter->second][1]/cake[iter->second][0];
			break;
		}else{
			res+=cake[iter->second][1];
			amount+=cake[iter->second][0];
			iter++;
		}
	}
	printf("%.2f",res);
	return 0;
} 
