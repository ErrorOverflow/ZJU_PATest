#include<iostream>
#include<string>
using namespace std;

int main(){
	string s[2],tmp;
	int i,j;
	bool isFin;
	long int a,b,c;
	cin>>s[0];
	for(i=0;i<10;i++){
		isFin=true;
		s[1].assign(s[0].rbegin(),s[0].rend());
		a=stol(s[0]);
		b=stol(s[1]);
		c=a+b;
		tmp.assign(s[0].begin(),s[0].end());
		s[0]=to_string(c);
		for(j=0;j<=s[0].length()/2;j++){
			if(s[0][j]!=s[0][s[0].length()-1-j]){
				isFin=false;
			}
		}
		cout<<tmp<<" + "<<s[1]<<" = "<<s[0]<<endl;
		if(isFin){
			cout<<s[0]<<" is a palindromic number.";
			return 0;
		}
	}
	cout<<"Not found in 10 iterations.";
	return 0;
} 
