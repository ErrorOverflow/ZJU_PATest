#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct node{
	int left=-1;
	int right=-1;
};

vector<int> num;
bool isRB;
int bnum,bfinal;

int build(int low,int high){
	int i;
	if(!isRB){
		return 0;
	}
	if(num[low]>0){
		bnum++;
	}
	if(low==high){
		if(bfinal!=-1 && bfinal!=bnum){
			isRB=false;
		}
		bfinal=bnum;
		if(num[low]>0){
			bnum--;
		}
		return 1;
	}
	int l=0,h=0;
	for(i=low+1;i<=high && abs(num[i])<abs(num[low]);i++);
	bool isleaf=true;
	if(abs(num[low+1])<abs(num[low])){
		if(num[low]<0 && num[low+1]<0){
			isRB=false;
		}
		l=build(low+1,i-1);
	}else{
		if(bfinal!=-1 && bfinal!=bnum){
			isRB=false;
		}
		bfinal=bnum;		
	}
	if(i<=high){
		if(num[low]<0 && num[i]<0){
			isRB=false;
		}
		h=build(i,high);
	}else{
		if(bfinal!=-1 && bfinal!=bnum){
			isRB=false;
		}
		bfinal=bnum;		
	}
	if(num[low]>0){
		bnum--;
	}
	return max(l,h)+1;
}

int main(){
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int N;
		isRB=true;
		scanf("%d",&N);
		num.clear();
		num.resize(N);
		bnum=0;
		bfinal=-1;
		for(int j=0;j<N;j++){
			scanf("%d",&num[j]);
		}
		if(num[0]<0){
			printf("No\n");
			continue;
		}
		build(0,N-1);
		if(isRB){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
