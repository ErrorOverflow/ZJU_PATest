#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> coins;
vector<int> res[101];
bool vis[]
int N,P;
bool isFind;

int main(){
	scanf("%d%d",&N,&P);
	coins.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&coins[i]);
	}
	sort(coins.begin(),coins.end());
	for(int i=1;i<=P)
	printf("No Solution");
	return 0;
}
