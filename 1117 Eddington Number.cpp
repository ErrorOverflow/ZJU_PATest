#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
	int N,i,j,k,low,maxn,res;
	cin>>N;
	int num;
	multiset<int> list;
	for(i=0;i<N;i++){
		cin>>num;
		list.insert(num);
	}
	auto iter=list.begin();
	for(i=0;i<N;i++,iter++){
		if(*iter>N-i){
			cout<<N-i;
			return 0;
		}
	}
	cout<<0;
	return 0;
} 
