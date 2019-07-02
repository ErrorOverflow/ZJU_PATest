#include<iostream>
#include<map>

using namespace std;

int N,M,L;
int favo[201];
int chain[1010];
int MaxLen=0;
int isFavo[201]={0};

int getMax(int low,int bias){
	int i,j,high,newBias,max=0,tmp;
	map<int,int> list;
	map<int,int>::iterator iter;
	for(i=low;i<L;i++){
		if(isFavo[chain[i]]!=0){
			high=i;
			newBias=isFavo[chain[i]]-1;
			break;
		}
	}
	for(i=bias;i<=newBias;i++){
		for(j=low;j<L;j++){
			if(chain[j]==favo[i]){
				list.insert(pair<int,int>(i,j));
				//cout<<i<<" "<<j<<endl;
			}
		}
	} 
	if(list.size()==0){
		return 0;
	}
	iter=list.begin();
	while(iter!=list.end()){
		tmp=getMax(iter->second+1,iter->first);
		if(tmp>max){
			max=tmp;
		}
		iter++;
	}
	return max+1;
}

int main(){
	int i;
	cin>>N;
	cin>>M;
	for(i=0;i<M;i++){
		cin>>favo[i];
		if(isFavo[favo[i]]==0)
			isFavo[favo[i]]=i+1;
	}
	cin>>L;
	for(i=0;i<L;i++){
		cin>>chain[i];
	}
	cout<<getMax(0,0);
	return 0;
} 
