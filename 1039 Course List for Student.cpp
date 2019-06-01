#include<iostream>
#include<map>
#include<set>

using namespace std;

map<string,set<int>> list;

int N,K;

int main(){
	int i,j,course,num;
	string name;
	set<int>::iterator iter;
	cin>>N>>K;
	for(i=0;i<K;i++){
		cin>>course>>num;
		for(j=0;j<num;j++){
			cin>>name;
			list[name].insert(course);
		}
	}
	for(i=0;i<N;i++){
		cin>>name;
		cout<<name<<" "<<list[name].size();
		for(iter=list[name].begin();iter!=list[name].end();iter++){
			cout<<" "<<*iter;
		}
		cout<<endl;
	}
	return 0;
} 
