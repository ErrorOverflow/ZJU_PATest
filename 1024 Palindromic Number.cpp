#include<iostream>

using namespace std;

int main(){
	char N[200];
	string s,pre;
	int i,j,k,l,p,K,length;
	cin>>s>>K;
	for(i=0;i<K;i++){
		for(j=0;j<s.length()/2+1;j++){
			if(s[j]!=s[s.length()-1-j]){
				break;
			}
		}
		if(j>=s.length()/2+1){
			break;
		}
		pre=string(s);
		l=0;
		p=0;
		if(s[0]+s[s.length()-1]-'0'-'0'>9){
			N[0]=1+'0';
			p=1;
		}
		for(j=s.length()-1;j>=0;j--){
			k=(s[j]+pre[s.length()-j-1]-'0'-'0'+l)%10;
			l=(s[j]+pre[s.length()-j-1]-'0'-'0'+l)/10;
			N[j+p]=k+'0';
		}
		s=string(N,s.length()+p);
	}
	cout<<s<<endl;
	cout<<i;
	return 0;
}
