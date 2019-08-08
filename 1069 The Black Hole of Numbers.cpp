#include<iostream>
#include<algorithm>

using namespace std;

void add(string a,string b,string &c){
	c.clear();
	int res[4];
	for(int i=3,bias=0,g=0;i>=0;i--){
		if(a[i]>=b[i]+bias){
			res[i]=a[i]-b[i]-bias;
			bias=0;
		}else{
			res[i]=a[i]-b[i]-bias+10;
			bias=1;
		}
	}
	for(int i=0;i<4;i++){
		c.push_back('0'+res[i]);
	}
	cout<<a<<" - "<<b<<" = "<<c<<endl;
}

int main(){
	string s,a,b;
	cin>>s;
	while(s!="6174"){
		a = string(s);
		b = string(s);
		sort(a.begin(),a.end(),greater<char>());
		sort(b.begin(),b.end());
		if(a==b){
			cout<<a<<" - "<<b<<" = 0000";
			return 0;
		}
		add(a,b,s);
	}
	return 0;
}
