#include<iostream>
#include<set>
#include<map>

using namespace std;

int N,C;

struct Student{
	string name;
	int score;
};

map<string,Student> Id;
map<string,Student>::iterator it_id;
map<string,set<string>> Name;
map<string,set<string>>::iterator it_name;
map<int,set<string>> Score;
map<int,set<string>>::iterator it_score;

set<string>::iterator iter;

int i,j;
string id,name;
int score;
int main(){
	cin>>N>>C;
	for(i=0;i<N;i++){
		cin>>id>>name>>score;
		Id.insert(pair<string,Student>(id,Student{name,score}));
		Name[name].insert(id);
		Score[score].insert(id);
	}
	switch(C){
		case 1:{
			it_id=Id.begin();
			while(it_id!=Id.end()){
				printf("%s %s %d\n",it_id->first.c_str(),it_id->second.name.c_str(),it_id->second.score);
				it_id++;
			}
			break;
		}
		case 2:{
			it_name=Name.begin();
			while(it_name!=Name.end()){
				iter=it_name->second.begin();
				while(iter!=it_name->second.end()){
					printf("%s %s %d\n",(*iter).c_str(),it_name->first.c_str(),Id[*iter].score);
					iter++;
				}
				it_name++;
			}
			break;
		}
		case 3:{
			it_score=Score.begin();
			while(it_score!=Score.end()){
				iter=it_score->second.begin();
				while(iter!=it_score->second.end()){
					printf("%s %s %d\n",(*iter).c_str(),Id[*iter].name.c_str(),it_score->first);
					iter++;
				}
				it_score++;
			}
			break;
		}
	}
	return 0;
}
