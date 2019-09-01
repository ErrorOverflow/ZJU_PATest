#include<iostream>
#include<vector>
using namespace std;

int N,pre[31],post[31];
bool unique=true;
vector<int> in;

int check(int prel,int prer,int postl,int postr){
	if(prer==prel){
		in.push_back(pre[prer]);
		return 0;
	}
	if(pre[prel]==post[postr]){
		int pren=prel;
		while(pre[pren]!=post[postr-1])pren++;
		if(pren==prel+1){
			unique=false;
			in.push_back(pre[prel]);
			check(pren,prer,postl+pren-prel-1,postr-1);
		}else{
			check(prel+1,pren-1,postl,postl+pren-prel-2);
			in.push_back(pre[prel]);
			check(pren,prer,postl+pren-prel-1,postr-1);
		}		
	}
	return 0;
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&post[i]);
	}
	check(0,N-1,0,N-1);
    printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    printf("\n");
	return 0;
}
