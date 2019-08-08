#include<iostream>
using namespace std;

int main(){
	int i,j,count,N,tmp,num[100010],loc[100010];
	cin>>N;
	for(i=0;i<N;i++){
		cin>>tmp;
		num[i]=tmp;
		loc[tmp]=i;
	}
	count=0;
	while(true){
		if(loc[0]==0){
			for(j=1;j<N;j++){
				if(num[j]!=j){
					swap(loc[0],loc[num[j]]);
					swap(num[0],num[j]);
					count++;
					break;
				}
			}
			if(j==N){
				break;
			}
		}else{
			swap(num[loc[0]], num[loc[loc[0]]]);
			swap(loc[0],loc[loc[0]]);
			count++;
		}
	}
	cout<<count;
	return 0;
}
