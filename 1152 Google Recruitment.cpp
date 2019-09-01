#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
	string s;
	int i,j,k,n,N;
	bool isPrime;
	cin>>k>>N;
	cin>>s;
	for(i=0;i<=k-N;i++){
		isPrime=true;
		n=stoi(s.substr(i,N));
		if(n==2){
			cout<<s.substr(i,N);
			return 0;
		}
		if(n%2==0 || n<2){
			continue;
		}
		for(j=3;j*j<=n;j+=2){
			if(n%j==0){
				isPrime=false;
				break;
			}
		}
		if(isPrime){
			cout<<s.substr(i,N);
			return 0;
		}
	}
	cout<<404;
	return 0;
}
