#include<iostream>

using namespace std;

string res[2]="";
int result[2]={0};
int N;
int cal(int num,string s){
	int i=0,j,t=0,flag,total,tmp=0;
	while(tmp<s.length() && s[tmp]=='0') tmp++;
	if(tmp==s.length()){
		for(j=0;j<N;j++){
			res[num].push_back('0');
		}
		result[num]=0;
		return 0;		
	}
	i=tmp;
	if(s[i]=='.'){
		while(!(s[i]>='1' && s[i]<='9')){
			if(i==s.length()-1){
				for(j=0;j<N;j++){
					res[num].push_back('0');
				}
				result[num]=0;
				return 0;
			}
			i++;
		}
		result[num]=tmp+1-i;
		for(j=0;j<N;j++,i++){
			if(i>=s.length()){
				res[num].push_back('0');
			}else{
				res[num].push_back(s[i]);
			}
		}
	}else{
		t=0;
		flag=0;
		for(i=tmp,total=0;total<N;i++,t++){
			if(i==s.length()){
				for(j=total;j<N;j++){
					res[num].push_back('0');
				}
				if(flag==0){
					flag=1;
					result[num]=t;
				}
				return 0;
			}
			if(s[i]=='.'){
				result[num]=t;
				flag=1;
			}else{
				res[num].push_back(s[i]);
				total++;
			}
		}
		if(flag==0){
			while(i!=s.length() && s[i]!='.'){
				i++;
				t++;
			}
			result[num]=t;
		}
	}
	return 0;
}

int main(){
	string a,b;
	int i;
	cin>>N>>a>>b;
	cal(0,a);
	cal(1,b);
	if(res[0]==res[1] && result[0]==result[1]){
		cout<<"YES 0."<<res[0]<<"*10^"<<result[0];
	}else{
		cout<<"NO 0."<<res[0]<<"*10^"<<result[0]<<" 0."<<res[1]<<"*10^"<<result[1];
	}
	return 0;
} 
