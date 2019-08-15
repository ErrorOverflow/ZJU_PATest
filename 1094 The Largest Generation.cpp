#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N,M;

vector<int> child[101];

int main(){
	string ID,id;
	int i,j,k;
	cin>>N>>M;
	for(i=0;i<M;i++){
		cin>>ID>>k;
		for(j=0;j<k;j++){
			cin>>id;
			child[stoi(ID)].push_back(stoi(id));
		}
	}
	vector<int> list;
	vector<int> tmp;
	int max=1;
	int max_gen=1;
	int level=1;
	list.push_back(1);
	while(list.size()!=0){
		tmp.clear();
		for(i=0;i<list.size();i++){
			for(j=0;j<child[list[i]].size();j++){
				tmp.push_back(child[list[i]][j]);
			}
		}
		list.assign(tmp.begin(),tmp.end());
		level++;
		//cout<<list.size()<<" "<<level<<endl;
		if(list.size()>max){
			max=list.size();
			max_gen=level;
		}
	}
	cout<<max<<" "<<max_gen;
	return 0;
} 
