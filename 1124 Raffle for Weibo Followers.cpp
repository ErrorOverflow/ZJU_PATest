#include<iostream>
#include<set>
using namespace std;

int main(){
	int N,M,K,i,j;
	cin>>N>>M>>K;
	string s;
	set<string> list;
	for(i=1,j=1;i<=N;i++,j++){
		cin>>s;
		if(i==K){
			cout<<s<<endl;
			list.insert(s);
		}
		else if(j>K && (j-K)%M==0){
			if(list.find(s)==list.end()){
				cout<<s<<endl;
				list.insert(s);
			}else{
				j--;
			}
		}
	}
	if(K>N){
		cout<<"Keep going...";
	}
	return 0;
}
