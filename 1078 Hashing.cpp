#include<iostream>
#include<math.h>

using namespace std;

int main(){
	int M,N,i,j,step;
	bool isFill[10010]={false};
	bool isPrime;
	cin>>M>>N;
	for(;M>2;M++){
		if(M%2==0){
			continue;
		}
		isPrime=true;
		for(i=3;i<=sqrt(M);i+=2){
			if(M%i==0){
				isPrime=false;
				break;
			}
		}
		if(isPrime){
			break;
		}
	}
	if(M<2){
		M=2;
	}
	bool isFind;
	for(i=0;i<N;i++){
		cin>>j;
		if(!isFill[j%M]){
			cout<<j%M;
			isFill[j%M]=true;
		}else{
			isFind=true;
			for(step=1;step<=M-1;step++){
				if(!isFill[(j+(int)pow(step,2))%M]){
					cout<<(j+(int)pow(step,2))%M;
					isFill[(j+(int)pow(step,2))%M]=true;
					isFind=false;
					break;
				}
			}
			if(isFind){
				cout<<"-";
			}
		}
		if(i!=N-1){
			cout<<" ";
		}
	}
	return 0;
} 
