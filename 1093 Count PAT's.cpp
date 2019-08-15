#include<iostream>

using namespace std;

int main(){
	int i,j,res=0;
	string s;
	cin>>s;
	long long p=0,a=0,t=0;
	for(i=1;i<=s.length();i++){
		if(s[i-1]=='P'){
			p++;
		}else if(s[i-1]=='A'){
			a+=p;
		}else if(s[i-1]=='T'){
			t+=a;
		}
	}
	printf("%d",t%1000000007);
	return 0;
}
