#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N,K,M,DS;

struct Road{
	vector<int> next;
	vector<int> len;
};

Road loc[2010];

void DFS(int p, bool *isVisit, int *distance){
	int i;
	for(i=0;i<loc[p].next.size();i++){
		if(!isVisit[loc[p].next[i]]){
			//cout<<p<<"->"<<loc[p].next[i];
			isVisit[loc[p].next[i]]=true;
			if(distance[loc[p].next[i]]>distance[p]+loc[p].len[i] || distance[loc[p].next[i]]==0){
				distance[loc[p].next[i]]=distance[p]+loc[p].len[i];
			}
			//cout<<" "<<distance[loc[p].next[i]]<<endl;
			DFS(loc[p].next[i],isVisit,distance);
			isVisit[loc[p].next[i]]=false;
		}
	}
}

int main(){
	int i,j;
	string a,b;
	int P1,P2,dist;
	cin>>N>>M>>K>>DS;
	for(i=0;i<N;i++){
		loc[i]=Road{};
	}
	for(i=0;i<K;i++){
		cin>>a>>b>>dist;
		if(a[0]=='G'){
			a.erase(0,1);
			P1=stoi(a)+N;
		}else{
			P1=stoi(a);
		}
		if(b[0]=='G'){
			b.erase(0,1);
			P2=stoi(b)+N;
		}else{
			P2=stoi(b);
		}
		loc[P1].next.push_back(P2);
		loc[P1].len.push_back(dist);
		loc[P2].next.push_back(P1);
		loc[P2].len.push_back(dist);
	}
	int min=0;
	int min_ave=1e9+7;
	int candidate=-1;
	int now;
	for(i=N+1;i<=N+M;i++){
		bool isConnect=true;
		bool isVisit[2010]={false};
		int distance[2010]={0};
		int total=0;
		int min_dis=1e9+7;
		//cout<<"-------------------G"<<i-N<<endl;
		isVisit[i]=true;
		DFS(i,isVisit,distance);
		for(j=1;j<=N;j++){
			//cout<<distance[j]<<" ";
			if(distance[j]==0 || distance[j]>DS){
				isConnect=false;
				break;
			}
			if(distance[j]<min_dis){
				min_dis=distance[j];
			}
			total+=distance[j];
		}
		//cout<<"#"<<min_dis<<endl;
		if(isConnect){
			if(min_dis>min){
				min=min_dis;
				candidate=i;
				min_ave=total;
			}else if(min_dis==min){
				if(total<min_ave){
					candidate=i;
					min_ave=total;
				}
			}
		}
	}
	if(candidate==-1){
		cout<<"No Solution";
	}else{
		cout<<"G"<<candidate-N<<endl;
		printf("%.1f %.1f",float(min),float(min_ave)/float(N));
	}
	return 0;
}
