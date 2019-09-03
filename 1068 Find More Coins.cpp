#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> coins;
vector<int> res;
int N,P;
bool isFind;

void display(){
	for(int i=0;i<res.size();i++){
		printf("%d%s",res[i],i==res.size()-1?"":" ");
	}
}

int dfs(int index,int pay){
	//cout<<index<<" "<<pay<<endl;
	if(pay+coins[index]==P){
		res.push_back(coins[index]);
		display();
		exit(0);
	}else if(pay+coins[index]<P){
		res.push_back(coins[index]);
		dfs(index+1,pay+coins[index]);
		res.pop_back();
		dfs(index+1,pay);
	}
	return 0; 
}

int main(){
	scanf("%d%d",&N,&P);
	coins.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&coins[i]);
	}
	sort(coins.begin(),coins.end());
	dfs(0,0);
	printf("No Solution");
	return 0;
}
