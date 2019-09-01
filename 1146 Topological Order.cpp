#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N,M,Q,i,j,k,a,b;
	vector<int> res;
	scanf("%d%d",&N,&M);
	int edge[N+1][N+1]={0};
	for(i=0;i<M;i++){
		cin>>a>>b;
		edge[a][b]=1;
		edge[b][a]=2;
	}
	scanf("%d",&Q);
	for(i=0;i<Q;i++){
		bool isG=true;
		vector<int> num;
		for(j=0;j<N;j++){
			scanf("%d",&a);
			num.push_back(a);
		}
		for(j=0;j<N-1 && isG;j++){
			for(k=j+1;k<N;k++){
				if(edge[num[j]][num[k]]==2){
					//cout<<num[j]<<" "<<num[k]<<endl;
					res.push_back(i);
					isG=false;
					break;
				}
			}
		}
	}
	for(i=0;i<res.size();i++){
		printf("%d",res[i]);
		if(i!=res.size()-1){
			printf(" ");
		}
	}
	return 0;
}
