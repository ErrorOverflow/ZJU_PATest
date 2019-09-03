#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> pick(11);
vector<int> list(50001);
bool vis[50001];

int main(){
	int N,K,i,t;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++){
		while(i!=0){
			if(vis[t]) break;
			if(list[pick[K-1]]<list[t] || (t<pick[K-1] && list[pick[K-1]]==list[t])){
				vis[pick[K-1]]=false;
				pick[K-1]=t;
				vis[t]=true;
			}else{
				break;
			}
			break;
		}
		for(int k=K-1;k>=1;k--){
			if(list[pick[k-1]]<list[pick[k]] || (pick[k-1]>pick[k] && list[pick[k-1]]==list[pick[k]])){
				swap(pick[k-1],pick[k]);
			}
		}
		scanf("%d",&t);
		list[t]++;
		if(i!=0){
			printf("%d: ",t);
			for(int k=0;k<K;k++){
				if(pick[k]==0) break;
				printf("%s%d",k==0?"":" ",pick[k]);
			}
			printf("\n");			
		}
	}
	return 0;
}
