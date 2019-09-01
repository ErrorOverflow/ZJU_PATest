#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> num;
	vector<int> ranklist;
	vector<int> res;
	int N;
	scanf("%d",&N);
	num.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
	}
	ranklist.assign(num.begin(),num.end());
	sort(ranklist.begin(),ranklist.end());
	for(int i=0;i<N;i++){
		if(ranklist[i]==num[i]){
			res.push_back(num[i]);
		}else if(num[i]>ranklist[i]){
			int j;
			for(j=N-1;num[j]!=ranklist[i];j--);
//			if(j>i)
				i=j;
		}
	}
	printf("%d\n",res.size());
	for(int i=0;i<res.size();i++){
		printf("%d%s",res[i],i==res.size()-1?"":" ");
	}
	printf("\n");
	return 0;
} 
