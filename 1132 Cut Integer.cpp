#include<iostream>
#include<string>
using namespace std;

int main(){
	int N,i;
	cin>>N;
	string s;
	for(i=0;i<N;i++){
		cin>>s;
		long int a=stol(s.substr(0,s.length()/2));
		long int b=stol(s.substr(s.length()/2,s.length()/2));
		long int c=stol(s);
		if(b==0 || c==0){
			cout<<"No"<<endl;
			continue;
		}
		if(c%(a*b)==0){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
