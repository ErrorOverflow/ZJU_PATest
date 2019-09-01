#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int msize,N,M,num,i,j,flag;
	cin>>msize>>N>>M;
	while(true){
		if(msize<=2){
			msize=2;
			break;
		}
		for(i=2,flag=0;i<msize;i++){
			if(msize%i==0){
				flag=1;
				break;
			}
		}
		if(flag){
			msize++;
		}else{
			break;
		}
	}
	int list[msize]={0};
	bool isFill[msize]={false};
	for(i=0;i<N;i++){
		cin>>num;
		if(!isFill[num%msize]){
			list[num%msize]=num;
			isFill[num%msize]=true;
			//cout<<num<<"->"<<num%msize<<endl;
		}else{
			bool isFind=false;
			for(j=1;j<msize;j++){
				if(!isFill[(num+(int)pow(j,2))%msize]){
					isFill[(num+(int)pow(j,2))%msize]=true;
					list[(num+(int)pow(j,2))%msize]=num;
					isFind=true;
					//cout<<num<<"->"<<(num+(int)pow(j,2))%msize<<endl;
					break;
				}
			}
			if(!isFind){
				printf("%d cannot be inserted.\n",num);
			}
		}
	}
	double time=0;
	for(i=0;i<M;i++){
		cin>>num;
		for(j=0;j<=msize;j++){
			//cout<<num<<"add"<<time<<endl;
			time++;
			if(list[(num+(int)pow(j,2))%msize]==num || list[(num+(int)pow(j,2))%msize]==0){
				break;
			}
		}
	}
	printf("%.1f",time/M);
	return 0;
} 
