#include<iostream>
#include<string>

using namespace std;

int main(){
	int i,j,k,n,N;
	string s;
	cin>>s;
	N=s.length()+2;
	n=N/3;
	k=N-2*n;
	for(i=0;i<n-1;i++){
		cout<<s[i];
		for(j=0;j<k-2;j++){
			cout<<" ";
		}
		cout<<s[s.length()-i-1]<<endl;
	}
	for(j=i;j<i+k;j++){
		cout<<s[j];
	}
	return 0;
} 
