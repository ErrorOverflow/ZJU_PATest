#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int N,M,K;
int max_score[10];
int list[10100][10]={0};
string id[10100];

int main(){
	int i,j,partial_score_obtained,problem_id,n;
	string user_id;
	cin>>N>>K>>M;
	for(i=1;i<=K;i++){
		cin>>max_score[i];
	}
	for(i=0;i<M;i++){
		cin>>user_id>>problem_id>>partial_score_obtained;
		id[stoi(user_id)]=user_id;
		if(list[stoi(user_id)][problem_id]<partial_score_obtained+2){
			list[stoi(user_id)][problem_id]=partial_score_obtained+2;
		}
	}
	map<int,map<int,vector<int>>> rank; 
	bool submit;
	for(i=1;i<=N;i++){
		submit=false;
		for(j=1;j<=K;j++){
			if(list[i][j]==0 || list[i][j]==1) continue;
			else list[i][6]+=list[i][j]-2;
			if(list[i][j]==max_score[j]+2){
				list[i][7]++;
			}
			submit=true;
		}
		if(list[i][6]==0 && !submit){
			continue;
		}
		auto iter_rank = rank.find(-list[i][6]);
		if(iter_rank==rank.end()){
			vector<int> vec_tmp;
			map<int,vector<int>> map_tmp;
			vec_tmp.push_back(i);
			map_tmp.insert(pair<int,vector<int>>(-list[i][7],vec_tmp));
			rank.insert(pair<int,map<int,vector<int>>>(-list[i][6],map_tmp));
		}else{
			auto iter_map = iter_rank->second.find(-list[i][7]);
			if(iter_map == iter_rank->second.end()){
				vector<int> vec_tmp;
				vec_tmp.push_back(i);
				iter_rank->second.insert(pair<int,vector<int>>(-list[i][7],vec_tmp));
			}else{
				iter_map->second.push_back(i);
			}
		}
	}
	auto iter = rank.begin();
	n=1;
	while(iter!=rank.end()){
		auto it = iter->second.begin();
		while(it!=iter->second.end()){
			for(j=0;j<it->second.size();j++){
				cout<<n<<" ";
				cout<<id[it->second[j]]<<" ";
				cout<<list[it->second[j]][6];
				for(i=1;i<=K;i++){
					if(list[it->second[j]][i]==0){
						cout<<" -";
					}else{
						if(list[it->second[j]][i]-2>=0)
							cout<<" "<<list[it->second[j]][i]-2;
						else
							cout<<" 0";
					}
				}
				cout<<endl;
			}
			it++;
		}
		n+=iter->second.size();
		iter++;
	}
	return 0;
} 
