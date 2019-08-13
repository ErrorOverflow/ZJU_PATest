#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	long long i,N,p,j;
	vector<long long> list;
	cin>>N>>p;
	for(i=0;i<N;i++){
		cin>>j;
		list.push_back(j);
	}
	sort(list.begin(),list.end());
	for(i=N;i>=0;i--){
		for(j=0;j<=N-i;j++){
			if(list[j+i-1]<=list[j]*p){
				cout<<i;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
} 
