#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<int> hobby[1001];
vector<int> people[1001];
vector<int> cluster;
bool isused[1001]={false};
bool isvisit[1001]={false};

int BFS(int h){
	vector<int> list;
	int i,j,tmp;
	for(i=0;i<hobby[h].size();i++){
		if(!isvisit[hobby[h][i]]){
			//cout<<h<<":"<<hobby[h][i]<<" ";
			cluster[cluster.size()-1]++;
			isvisit[hobby[h][i]]=true;
		}else{
			continue;
		}
		for(j=0;j<people[hobby[h][i]].size();j++){
			tmp=people[hobby[h][i]][j];
			if(!isused[tmp]){
				isused[tmp]=true;
				list.push_back(tmp);
			}
		}
	}
	for(i=0;i<list.size();i++){
		BFS(list[i]);
	}
	return 0;
}

int main(){
	cin>>N;
	int i,j,k,t;
	for(i=0;i<=1000;i++){
		isused[i]=true;
	}
	for(i=0;i<N;i++){
		scanf("%d:",&k);
		for(j=0;j<k;j++){
			cin>>t;
			isused[t]=false;
			people[i+1].push_back(t);
			hobby[t].push_back(i+1);
		}
	}
	bool isFinish;
	while(true){
		isFinish=true;
		for(i=0;i<=1000;i++){
			if(!isused[i]){
				isFinish=false;
				break;
			}
		}
		if(isFinish){
			break;
		}
		cluster.push_back(0);
		BFS(i);
		//cout<<endl;
	}
	cout<<cluster.size()<<endl;
	sort(cluster.begin(),cluster.end());
	for(i=cluster.size()-1;i>=0;i--){
		cout<<cluster[i];
		if(i!=0){
			cout<<" ";
		}
	}
	return 0;
}
