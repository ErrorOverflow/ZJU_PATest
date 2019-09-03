#include<iostream>
#include<string>
using namespace std;

int add(string &a,string &b,string &c){
	string mid;
	int plus=0,i,j;
	for(i=a.length()-1,j=b.length()-1;j>=0;i--,j--){
		int u=a[i]-'0'+b[j]-'0'+plus;
		plus=u>9?1:0;
		mid.push_back((char)(u>9?u-10+'0':u+'0'));
	}
	if(plus) mid.push_back('1');
	c.assign(mid.rbegin(),mid.rend());
	return 0;
}

int main(){
	int n;
	string a,b,c;
	cin>>a;
	for(n=0;n<a.length()-1 && a[n]=='0';n++);
	a=a.substr(n,a.length());
	bool isFind=true;
	for(int j=0;j<a.size();j++){
		if(a[j]!=a[a.length()-j-1]){
			isFind=false;
			break;
		}
	}
	if(isFind){
		cout<<a;
		printf(" is a palindromic number.\n");
		return 0;
	}
	b.assign(a.rbegin(),a.rend());
	for(int i=0;i<10;i++){
		add(a,b,c);
		cout<<a<<" + "<<b<<" = "<<c<<endl;
		for(n=0;n<c.length()-1 && c[n]=='0';n++);
		c=c.substr(n,c.length());
		bool isFind=true;
		for(int j=0;j<c.size();j++){
			if(c[j]!=c[c.length()-j-1]){
				isFind=false;
				break;
			}
		}
		if(isFind){
			cout<<c;
			printf(" is a palindromic number.\n");
			return 0;
		}
		a.assign(c.begin(),c.end());
		b.assign(c.rbegin(),c.rend());
	}
	printf("Not found in 10 iterations.\n");
	return 0;
}
