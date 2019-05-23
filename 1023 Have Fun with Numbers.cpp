#include<iostream>

using namespace std;

int isUsed[32]={0};

int main(){
	int i,j,k,isYes=1;
	string s;
	int res[32];
	cin>>s;
	for(i=0;i<s.length();i++){
		isUsed[s[i]-'0']++;
	}
	for(i=s.length()-1,k=0;i>=0;i--){
		j=(2*(s[i]-'0')+k)%10;
		k=(2*(s[i]-'0')+k)/10;
		res[i]=j;
		isUsed[j]--;
		if(isUsed[j]<0){
			isYes=0;
		}
	}
	if(isYes){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	if(s[0]>='5'){
		cout<<"1";
	}
	for(i=0;i<s.length();i++){
		cout<<res[i];
	}
	return 0;
} 
