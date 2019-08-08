#include<iostream>
#include<set> 

using namespace std;

set<int> list;

int main(){
	int i,N,tmp,root;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>tmp;
		if(i==0){
			root=tmp;
		}
		list.insert(tmp);
		
	}
	cout<<root;
	return 0;
} 
