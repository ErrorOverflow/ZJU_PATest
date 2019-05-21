#include<iostream>
#include<vector>

#define CMAX 101

#define NMAX 501 

using namespace std;

struct Point{
	int next[NMAX]={0};
}point[NMAX];

int bike[NMAX]={0};
int C,N,S,M;
vector<int> Min;
vector<int> result;
int totalSent=0;
int totalLen=0;
int totalGet=0;
int minSent=999999;
int minLen=999999;
int finalGet=0;
int isUsed[NMAX]={0};

int DFS(int now){
	int i,len=totalLen,sent=totalSent,get=totalGet;
	if(now==S){
		if(totalLen<minLen){
			Min.clear();
			Min.assign(result.begin(),result.end());
			minLen=totalLen;
			minSent=totalSent;
			finalGet=totalGet;
		}else if(totalLen==minLen && totalSent<minSent){
			Min.clear();
			Min.assign(result.begin(),result.end());
			minSent=totalSent;
			finalGet=totalGet;
		}
		return 0;
	}
	for(i=1;i<=N;i++){
		if(i==now || isUsed[i]){
			continue;
		}
		if(point[now].next[i]!=999999){
			result.push_back(i);
			totalLen+=point[now].next[i];
			if(bike[i]>C/2){
				totalGet+=bike[i]-C/2;
			}else if(bike[i]<C/2){
				if(totalGet>C/2-bike[i]){
					totalGet-=C/2-bike[i];
				}else{
					totalSent+=(C/2-bike[i]-totalGet);
					totalGet=0;
				}
			}
			//cout<<i<<" "<<totalSent<<" "<<totalGet<<endl;
			isUsed[i]=1;
			DFS(i);
			isUsed[i]=0;
			result.pop_back();
			totalSent=sent;
			totalGet=get;
			totalLen=len;
		}
	}
	return 0;
}

int main(){
	int i,j,a,b,c;
	cin>>C>>N>>S>>M;
	for(i=0;i<=N;i++){
		for(j=0;j<=N;j++){
			point[i].next[j]=999999;
		}
	}
	for(i=0;i<N;i++){
		cin>>a;
		bike[i+1]=a;
	}
	for(i=0;i<M;i++){
		cin>>a>>b>>c;
		point[a].next[b]=c;
		point[b].next[a]=c;
	}
	isUsed[0]=1;
	result.push_back(0);
	DFS(0);
	cout<<minSent<<" ";
	for(i=0;i<Min.size();i++){
		cout<<Min[i];
		if(i!=Min.size()-1){
			cout<<"->";
		}else{
			cout<<" ";
		}
	}
	cout<<finalGet;
	return 0;
}
