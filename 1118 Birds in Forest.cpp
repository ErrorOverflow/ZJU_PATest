#include<iostream>
#include<vector>
using namespace std;

vector<int> picture[1000];

int main(){
	int N,Q,K,a,b,i,j,k,count=0;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>K;
		for(j=0;j<K;j++){
			cin>>b;
			picture[i].push_back(b);
		}
		count+=K;
	}
	int isvisit[K+1]={0};
	int tree=1;
	for(i=0;i<N;i++){
		for(j=0;j<picture[i].size();j++){
			
		}
	}
	cin>>Q;
	for(i=0;i<Q;i++){
		cin>>a>>b;
	}
	return 0;
}
