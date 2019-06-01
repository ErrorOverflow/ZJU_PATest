#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<vector>

using namespace std;

map<char,set<int>> list;

int mark[256];

int len=0;

char input[1010];

int Sym(int low,int high){
	while(low<high){
		if(input[low++]!=input[high--]){
			return 0;
		}
	}
	return 1;
}

int find(int loc){
	if(list[input[loc]].size()<=1){
		return 0;
	}
	set<int>::iterator i,j,k;
	for(i=list[input[loc]].begin();i!=list[input[loc]].end();i++){
		j=list[input[loc]].end();
		j--;
		for(;j!=i;j--){
			if(Sym(*i,*j)){
				if(*j-*i+1>len){
					len=*j-*i+1;
				}
				return 0;
			}
		}
	}
}

int main(){
	int i;
	cin.getline(input,1010);
	for(i=0;i<256;i++){
		mark[i]=1010;
	}
	for(i=0;i<strlen(input);i++){
		list[input[i]].insert(i);
	}
	for(i=0;i<strlen(input);i++){
		find(i);
	}
	if(len==0){
		cout<<1;
		return 0;
	}
	cout<<len;
	return 0;
}
