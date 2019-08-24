#include<iostream>
#include<set>
using namespace std;

int main(){
	int N,i,j,k;
	set<int> res;
	cin>>N;
	string s[N];
	for(i=0;i<N;i++){
		cin>>s[i];
	}
	for(i=0;i<N;i++){
		for(j=0,k=0;j<s[i].length();j++){
			k+=s[i][j]-'0';
		}
		res.insert(k);
	}
	cout<<res.size()<<endl;
	i=0;
	for(auto iter=res.begin();iter!=res.end();iter++,i++){
		cout<<*iter;
		if(i!=res.size()-1){
			cout<<" ";
		}
	}
	return 0;
} 
