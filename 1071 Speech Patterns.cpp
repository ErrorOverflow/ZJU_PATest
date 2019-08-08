#include<iostream>
#include<map>

using namespace std;

map<string,int> list;

int main(){
	int i,j;
	bool isSplit=true;
	string word = string();
	char input[1048577];
	cin.getline(input,1048577);
	string s=string(input);
	for(i=0;i<s.length();i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
			word.push_back(s[i]);
		}else if(s[i]>='A' && s[i]<='Z'){
			word.push_back(char(s[i]-'A'+'a'));
		}else{
			if(word.length()>0){
				if(list.find(word)==list.end()){
					list.insert(pair<string,int>(word,1));
				}else{
					list.find(word)->second++;
				}
			}
			word=string();
		}
	}
	if(word.length()>0){
		if(list.find(word)==list.end()){
			list.insert(pair<string,int>(word,1));
		}else{
			list.find(word)->second++;
		}		
	}
	auto iter=list.begin();
	int max=0;
	string res;
	while(iter!=list.end()){
		if(iter->second>max){
			res=iter->first;
			max=iter->second;
		}
		iter++;
	}
	cout<<res<<" "<<max;
	return 0;
} 
