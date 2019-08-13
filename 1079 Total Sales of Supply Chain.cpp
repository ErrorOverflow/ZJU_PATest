#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;
double P,r;
int sup[100010]={0};
int pre[100010]={0};

int main(){
	int i,j,pro,K,ID,level,tmp,retail_n=0,sell_n=0;
	long double sum=0;
	int retailer[100010];
	int sell[100010];
	cin>>N>>P>>r;
	for(i=0;i<N;i++){
		cin>>K;
		if(K==0){
			cin>>pro;
			retailer[retail_n++]=i;
			sell[sell_n++]=pro;
		}else{
			for(j=0;j<K;j++){
				cin>>ID;
				sup[ID]=i;
			}
		}
	}
	for(i=0;i<retail_n;i++){
		level=0;
		tmp=retailer[i];
		while(tmp!=0){
			tmp=sup[tmp];
			level++;
		}
		sum+=sell[i]*P*pow(1+(double)r/100,level);
	}
	printf("%.1Lf",sum);
	return 0;
} 
