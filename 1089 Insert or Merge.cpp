#include<iostream>
#include<vector>

using namespace std;

int N;
int before[101];
int after[101];

void swap(int* list, int a,int b){
	int i,tmp;
	tmp=list[b];
	for(i=b;i>a;i--){
		list[i]=list[i-1];
	}
	list[a]=tmp;
}

void sort(int *list ,int a,int b){
	int i,j,tmp;
	for(i=a+1;i<=b;i++){
		for(j=a;j<i;j++){
			if(list[j]>list[i]){
				tmp=list[j];
				list[j]=list[i];
				list[i]=tmp;
			}
		}
	}
}

int main(){
	int i,j,mid[101],pre=-1,round;
	bool isInsert=false;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>before[i];
		mid[i]=before[i];
	}
	for(i=0;i<N;i++){
		cin>>after[i];
	}
	for(i=0;i<N;i++){
		if(mid[i]<pre){
			for(j=0;j<i;j++){
				if(mid[j]>mid[i]){
					swap(mid,j,i);
					break;
				}
			}
		}
		isInsert=true;
		for(j=0;j<N;j++){
			if(mid[j]!=after[j]){
				isInsert=false;
				break;
			}
		}
		if(isInsert){
			break;
		}
		pre=mid[i];
	}
	round=i;
	if(isInsert){
		cout<<"Insertion Sort"<<endl;
		for(i=round;i<N;i++){
			if(mid[i]<pre){
				for(j=0;j<i;j++){
					if(mid[j]>mid[i]){
						swap(mid,j,i);
						break;
					}
				}
				break;
			}
			pre=mid[i];
		}
		for(j=0;j<N;j++){
			cout<<mid[j];
			if(j!=N-1){
				cout<<" ";
			}
		}
	}else{
		cout<<"Merge Sort"<<endl;
		int tmp,size;
		bool isMerge=false;
		for(i=0;i<N;i++){
			mid[i]=before[i];
		}
		for(size=2;size<=N;size*=2){
			for(i=0;i<=N-size;i+=size){
				sort(mid,i,i+size-1);
			}
			sort(mid,i,N-1);
			if(isMerge){
				break;
			}
			isMerge=true;
			for(j=0;j<N;j++){
				if(mid[j]!=after[j]){
					isMerge=false;
					break;
				}
			}
		}
		for(j=0;j<N;j++){
			cout<<mid[j];
			if(j!=N-1){
				cout<<" ";
			}
		}
	}
	return 0;
} 
