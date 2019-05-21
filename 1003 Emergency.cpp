#include<iostream>
#include<string.h>

using namespace std;

struct CITY{
	int num;
	int connect[500]={0};
};
CITY city[501];
int isRun[500]={0};
int C2;
int N;
int rescue[501];
int MaxRescue=0;
int MinLen=999999;
int PathNum=0;
int FindPath(int start,int rescue_num,int length){
	int i,k;
	if(length>MinLen)
		return start;
	if(start==C2){
		if(MinLen==length)
			PathNum++;
		else if(MinLen>length){
			PathNum=1;
			MinLen=length;
			MaxRescue=0;
		}
		if(rescue_num+rescue[C2]>MaxRescue)
			MaxRescue=rescue_num+rescue[C2];
		return start;
	}
	for(i=0;i<N;i++){
		if(isRun[i]==1)
			continue;
		if(city[start].connect[i]==0)
			continue;
		else{
			isRun[i]=1;
			k=FindPath(i,rescue_num+rescue[start],length+city[start].connect[i]);
			isRun[k]=0;
		}
	}
	return start;
}

int main(){
	int i,j,M,C1,c1,c2,L;
	cin>>N>>M>>C1>>C2;
	for(i=0;i<N;i++){
		cin>>rescue[i];
	}
	for(i=0;i<M;i++){
		cin>>c1>>c2>>L;
		city[c1].connect[c2]=L;
		city[c2].connect[c1]=L;
	}
	isRun[C1]=1;
	FindPath(C1,0,0);
	cout<<PathNum<<" "<<MaxRescue;
	return 0;
} 
