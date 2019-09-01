#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string &a,string &b){
	return a+b<b+a;
}

int main(){
	int N,i,j,minz,first;
	cin>>N;
	string s[N],res;
	for(i=0;i<N;i++){
		cin>>s[i];
	}
	sort(s,s+N,cmp);
	for(i=0;i<N;i++){
		res.append(s[i]);
	}
	for(i=0;i<res.size() && res[i]=='0';i++);
	cout<<res.substr(i,res.size());
	if(i==res.size()){
		printf("0");
	}
	return 0;
}
