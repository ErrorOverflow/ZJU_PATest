#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	int N,i,j,minz,first;
	cin>>N;
	string s[N],res;
	int zero[N];
	for(i=0;i<N;i++){
		cin>>s[i];
		if(stoi(s[i])==0){
			i--;
			N--;
			continue;
		}
		for(j=0;j<s[i].size() && s[i][j]=='0';j++){
		}
		zero[i]=j;
	}
	vector<int> f[2];
	int flag=0;
	vector<int> seg;
	seg.resize(N);
	for(i=0,minz=0;i<N;i++){
		if(zero[i]>minz){
			minz=zero[i];
			f[0].clear();
			f[0].push_back(i);
		}else if(zero[i]==minz){
			f[0].push_back(i);
		}
	}
	i=0;minz=1e9;
	while(f[flag].size()==1){
		f[1-flag].clear();
		bool isuse=false;
		for(j=0;j<f[flag].size();j++){
			if(zero[f[flag][j]]+i>=s[f[flag][j]].length()){
				continue;
			}
			isuse=true;
			if(s[f[flag][j]][zero[f[flag][j]]+i]<minz){
				minz=s[f[flag][j]][zero[f[flag][j]]+i];
				f[1-flag].push_back(f[flag][j]);
			}
		}
		if(!isuse){
			f[1-flag].push_back()
			break;
		}
		flag=1-flag;
		i++;
	}
	first
	for(i=0;i<f.size();i++){
		
	}
	for(i=0;i<N;i++){
		if(i!=)
	}
	return 0;
}
