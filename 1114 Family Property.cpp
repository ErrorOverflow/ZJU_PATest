#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Person{
	string father;
	string mother;
	vector<string> child;
	int mestate;
	int area;
	bool isvisit;
};

struct Result{
	string name;
	int n;
	float sets;
	float area;
};

map<string,Person> list;
int N,f=0;
Result res[1000];

int DFS(string name){
	cout<<name<<endl;
	int i;
	auto iter=list.find(name);
	iter->second.isvisit=true;
	res[f].n++;
	res[f].area+=iter->second.area;
	res[f].sets+=iter->second.mestate;
	for(i=0;i<iter->second.child.size();i++){
		auto it=list.find(iter->second.child[i]);
		if(it==list.end()){
			continue;
		}
		if(!it->second.isvisit){
			//cout<<name<<" "<<it->first<<endl; 
			DFS(it->first);
		}
	}
	if(iter->second.father!="-1" && list.find(iter->second.father)!=list.end() && !list.find(iter->second.father)->second.isvisit){
		//cout<<name<<" "<<iter->second.father<<endl; 
		DFS(iter->second.father);
	}
	if(iter->second.mother!="-1" && list.find(iter->second.mother)!=list.end() && !list.find(iter->second.mother)->second.isvisit){
		//cout<<name<<" "<<iter->second.mother<<endl;
		DFS(iter->second.mother);
	}
	cout<<"END "<<name<<endl;
	return 0;
}

int main(){
	int i,j,k,mes,are;
	string id,fa,mo,ch;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>id>>fa>>mo>>k;
		Person p={fa,mo};
		for(j=0;j<k;j++){
			cin>>ch;
			p.child.push_back(ch);
		}
		cin>>mes>>are;
		p.mestate=mes;
		p.area=are;
		p.isvisit=false;
		list.insert(pair<string,Person>(id,p));
	}
	for(auto iter=list.begin();iter!=list.end();iter++){
		if(!iter->second.isvisit){
			DFS(iter->first);
			res[f].name.assign(iter->first.begin(),iter->first.end());
			f++;
		}
	}
	multimap<float,int> ranklist;
	for(i=0;i<f;i++){
		ranklist.insert(pair<float,int>(res[i].area/res[i].n,i));
	}
	for(auto iter=ranklist.rbegin();iter!=ranklist.rend();iter++){
		cout<<res[iter->second].name<<" "<<res[iter->second].n<<" "<<res[iter->second].sets/res[iter->second].n<<" "<<res[iter->second].area/res[iter->second].n<<endl;
	}
	return 0;
} 
