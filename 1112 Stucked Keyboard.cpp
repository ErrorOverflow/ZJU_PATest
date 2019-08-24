#include<iostream>
#include<map>
using namespace std;

int main(){
	string s;
	int i,j,k;
	int broken[512]={0};
	cin>>k>>s;
	for(i=0;i<s.length();i++){
		if(broken[s[i]]==2){
			continue;
		}
		bool isbroken=true;
		for(j=0;j<k;j++){
			if(j==s.length() || s[i+j]!=s[i]){
				isbroken=false;
				broken[s[i]]=2;
				break;
			}
		}
		if(isbroken){
			if(broken[s[i]]<2)
				broken[s[i]]=3+i;
			i+=(k-1);
		}
	}
	map<int,char> list;
	for(i=0;i<512;i++){
		if(broken[i]>2){
			list.insert(pair<int,int>(broken[i],(char)i));
		}
	}
	for(auto iter=list.begin();iter!=list.end();iter++){
		cout<<iter->second;
	}
	cout<<endl;
	for(i=0;i<s.length();i++){
		cout<<s[i];
		if(broken[s[i]]>2){
			i+=(k-1);
		}
	}
	return 0;
} 
