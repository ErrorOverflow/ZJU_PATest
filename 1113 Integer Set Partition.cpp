#include<iostream>
#include<set>

using namespace std;

int main(){
	int i,j=0,N,t;
	multiset<int> list;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>t;
		list.insert(t);
	}
	auto iter=list.begin();
	for(i=0;i<N/2;i++,iter++){
		j-=*iter;
	}
	for(;iter!=list.end();iter++){
		j+=*iter;
	}
	cout<<N%2<<" "<<j;
	return 0;
}
