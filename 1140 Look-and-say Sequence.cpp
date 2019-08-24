#include<iostream>
#include<string>

using namespace std;

int main(){
	int i,j,k,t=0,D,N;
	cin>>D>>N;
	string s[2];
	s[t].push_back(D+'0');
	for(k=0;k<N-1;k++,t=1-t){
		for(i=0;i<s[t].length();i++){
			s[1-t].push_back(s[t][i]);
			for(j=i;j<s[t].length() && s[t][j]==s[t][i];j++){}
			s[1-t].push_back(j-i+'0');
			i=j-1;
		}
		//cout<<s[1-t]<<endl;
		s[t].clear();
	}
	cout<<s[t];
	return 0;
}
