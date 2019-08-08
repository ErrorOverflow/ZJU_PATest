#include<iostream>
#include<set>
#include<vector>
using namespace std;

set<int> coins;
vector<int> res;

int main(){
	int N,P,pay,i,j,tmp;
	cin>>N>>P;
	for(i=0;i<N;i++){
		cin>>tmp;
		coins.insert(tmp);
	}
	cout<<"No Solution";
	return 0;
	pay=0;
	while(true){
		if(pay==P){
			break;
		}
		else if(pay<P){
			
		}else{
			
		}
	}
	for(i=0;i<res.size();i++){
		cout<<res[i];
		if(i!=res.size()-1)
			cout<<" ";
	}
	return 0;
}
