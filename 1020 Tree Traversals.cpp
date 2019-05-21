#include<iostream>
#include<vector>

using namespace std;

int post[31],isDefined[31]={0},total;
int in[32];
int N;
vector<int> result[31];

int findDex(int *n,int num){
	int i,j,max=0;
	for(i=0;i<num;i++){
		for(j=0;j<N;j++){
			if(post[j]==n[i]){
				if(max<j){
					max=j;
				}
			}
		}
	}
	return max;
}

int travel(int *n,int num,int p,int index){
	int i,j,k,count;
	int num1[31],num2[32];
	if(num<=1){
		return 0;
	}
	for(i=0;i<num;i++){
		if(p==n[i]){
			k=i;
		}
	}
	for(i=0;i<k;i++){
		num1[i]=n[i];
	}
	for(i=k+1;i<num;i++){
		num2[i-k-1]=n[i];
	}
	if(k>0)
		result[index].push_back(post[findDex(num1,k)]);
	if(num-k-1>0)
		result[index].push_back(post[findDex(num2,num-k-1)]);
	if(k>0){
		
		travel(num1,k,post[findDex(num1,k)],index+1);
	}
	if(num-k-1>0){
		
		travel(num2,num-k-1,post[findDex(num2,num-k-1)],index+1);
	}
		
	return 0;
}

int main(){
	int queue[31];
	int i,j,k,count,n[31];
	cin>>N;
	for(i=0;i<N;i++){
		cin>>post[i];
	}
	for(i=0;i<N;i++){
		cin>>in[i];
	}
	total=N;
	result[0].push_back(post[N-1]);
	travel(in,N,post[N-1],1);
	for(j=0;j<N;j++){
		for(i=0;i<result[j].size();i++){
			cout<<result[j][i];
			if(!((j==N-1 || result[j+1].size()==0) && i==result[j].size()-1)){
				cout<<" ";
			}
		}		
	}
} 
