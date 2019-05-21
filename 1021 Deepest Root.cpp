#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int N;
int maxDep=-1;
int nowDep;
vector<int> res;
int isUsed[10010]={0};
int now;
int sep=0;
int isInsert=0;

struct Tree{
	vector<int> next;
}point[10010];

int DFS(int p){
	//cout<<p;
	int i,len=nowDep;
	if(nowDep>maxDep){
		res.clear();
		res.push_back(now);
		maxDep=nowDep;
		isInsert=1;
	}
	else if(nowDep==maxDep && isInsert==0){
		res.push_back(now);	
		isInsert=1;
	}
	for(i=0;i<point[p].next.size();i++){
		if(isUsed[point[p].next[i]]==1){
			continue;
		}
		isUsed[point[p].next[i]]=1;
		nowDep++;
		DFS(point[p].next[i]);
		nowDep=len;
	}
	return 0;
}

int check(int p){
	int i;
	for(i=0;i<point[p].next.size();i++){
		if(isUsed[point[p].next[i]]==1){
			continue;
		}
		isUsed[point[p].next[i]]=1;
		check(point[p].next[i]);
	}
}

int main(){
	int i,j,a,b,isEnd;
	cin>>N;
	for(i=1;i<N;i++){
		cin>>a>>b;
		point[a].next.push_back(b);
		point[b].next.push_back(a);
	
	}
	while(true){
		isEnd=1;
		for(i=1;i<=N;i++){
			if(isUsed[i]==0){
				isEnd=0;
				break;
			}
		}
		if(isEnd==1){
			break;
		}
		isUsed[i]=1;
		check(i);
		sep++;
	}
	
	if(sep>1){
		cout<<"Error: "<<sep<<" components";
		return 0;
	}
	
	for(i=1;i<=N;i++){
		nowDep=1;
		now=i;
		memset(isUsed,0,10010*sizeof(int));
		//for(j=1;j<=N;j++){
		//	isUsed[j]=0;
		//}
		isUsed[i]=1;
		isInsert=0;
		//cout<<"#"<<now<<" "<<maxDep<<endl;
		DFS(i);
		//cout<<endl;
	}
	for(i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
}
