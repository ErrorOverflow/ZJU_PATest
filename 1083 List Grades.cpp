#include<iostream>
#include<map>
using namespace std;

struct Stu{
	string name;
	string ID;
};

int main(){
	int N,i,score,low,high;
	string name,ID;
	map<int,Stu> list;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>name>>ID>>score;
		list.insert(pair<int,Stu>(score,Stu{name,ID}));
	}
	cin>>low>>high;
	bool isFind=false;
	auto iter=list.end();
	do{
		iter--;
		if(iter->first>=low && iter->first<=high){
			cout<<iter->second.name<<" "<<iter->second.ID<<endl;
			isFind=true;
		}
	}while(iter!=list.begin());
	if(!isFind){
		cout<<"NONE";
	}
	return 0;
} 
