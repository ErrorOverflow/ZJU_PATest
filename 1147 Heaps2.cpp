#include<vector>
#include<iostream>

using namespace std;
int n,m;
vector<int> v;
int post(int p){
	if(p>=n){
		return 0;
	}
	post(p*2+1);
	post(p*2+2);
	printf("%d%c",v[p],p==0?'\n':' ');
	return 0;
}
int main(){
	int i,j,k,t,state;
	scanf("%d%d",&m,&n);
	v.resize(n);
	for(t=0;t<m;t++){
		for(i=0;i<n;i++){
			scanf("%d",&v[i]);
		}
		state=(v[0]>v[1])?1:2;
		for(i=0;i<=(n-1)/2;i++){
			if((i*2+1<n && v[i]>v[i*2+1] && state==2) || (i*2+2<n && v[i]<v[i*2+2] && state==1)){
				printf("Not Heap\n");
				state=0;
				break;
			}
		}
		if(state==1){
			printf("Max Heap\n");
		}else if(state==2){
			printf("Min Heap\n");
		}
		post(0);
	}
	return 0;
}
