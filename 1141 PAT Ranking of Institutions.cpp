#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct College{
	float score;
	int num;
};

float add(char c,int score){
	if(c=='A'){
		return score;
	}else if(c=='B'){
		return score/1.5;
	}else{
		return score*1.5;
	}
}

void change(string &s){
	int i;
	for(i=0;i<s.length();i++){
		if(s[i]>='A' && s[i]<='Z'){
			s[i]-=('A'-'a');
		}
	}
}

int main(){
	int N,i,j,k,score;
	string id,school;
	map<string,College> list;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>id>>score>>school;
		change(school);
		if(list.find(school)!=list.end()){
			list.find(school)->second.num++;
			list.find(school)->second.score+=add(id[0],score);
		}else{
			list.insert(pair<string,College>(school,College{add(id[0],score),1}));
		}
	}
	map<int,map<int,vector<string>>> ranklist;
	for(auto iter=list.begin();iter!=list.end();iter++){
		auto it1=ranklist.find((int)iter->second.score);
		if(it1!=ranklist.end()){
			auto it2=it1->second.find(iter->second.num);
			if(it2!=it1->second.end()){
				it2->second.push_back(iter->first);
			}else{
				vector<string> vectmp;
				vectmp.push_back(iter->first);
				it1->second.insert(pair<int,vector<string>>(iter->second.num,vectmp));
			}
		}else{
			vector<string> vectmp;
			map<int,vector<string>> maptmp;
			vectmp.push_back(iter->first);
			maptmp.insert(pair<int,vector<string>>(iter->second.num,vectmp));
			ranklist.insert(pair<int,map<int,vector<string>>>((int)iter->second.score,maptmp));
		}
	}
	j=1;
	cout<<list.size()<<endl;
	for(auto it1=ranklist.rbegin();it1!=ranklist.rend();it1++){
		k=0;
		for(auto it2=it1->second.begin();it2!=it1->second.end();it2++){
			for(i=0;i<it2->second.size();i++){
				cout<<j<<" "<<it2->second[i]<<" "<<(int)list.find(it2->second[i])->second.score<<" "<<list.find(it2->second[i])->second.num<<endl;
			}
			k+=it2->second.size();
		}
		j+=k;
	} 
	return 0;
} 
