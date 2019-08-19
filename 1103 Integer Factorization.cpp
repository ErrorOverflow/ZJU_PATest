#include<iostream>
#include<cmath>
#include<set>

using namespace std;

int N,K,P,maxs=0,maxn,ave,pre=-1;
multiset<int> res;
int now[400];

int round(int index){
	int i,j;
	now[index]=ave;
	for(i=0;i<=maxn-ave;i++){
		if(index>0 && now[index]>=now[index-1]){
			break;
		}
		if(pre>N && pre!=-1){
			break;
		}
		now[index]++;
		if(index==K-1){
			int sum=0,add=0;
			for(j=0;j<K;j++){
				//cout<<now[j]<<" ";
				sum+=pow(now[j],P);
				add+=now[j];
			}
			pre=sum;
			//cout<<sum<<endl;
			if(sum==N){
				if(add>maxs){
					maxs=add;
					res.clear();
					for(j=0;j<K;j++){
						res.insert(now[j]);
					}
				}
			}
		}else{
			round(index+1);
		}	
	}
	now[index]=ave;
	pre=-1;
	for(i=0;i<ave;i++){
		if(pre<N && pre!=-1){
			break;
		}
		now[index]--;
		if(index==K-1){
			int sum=0,add;
			for(j=0;j<K;j++){
				//cout<<now[j]<<" ";
				sum+=pow(now[j],P);
				add+=now[j];
			}
			pre=sum;
			//cout<<sum<<endl;
			if(sum==N){
				if(add>maxs){
					maxs=add;
					res.clear();
					for(j=0;j<K;j++){
						res.insert(now[j]);
					}
				}
			}
		}else{
			round(index+1);
		}
	}
	if(res.size()!=0){
		cout<<N<<" =";
		i=0;
		for(auto iter=res.rbegin();iter!=res.rend();iter++,i++){
			cout<<" "<<*iter<<"^"<<P;
			if(i!=res.size()-1){
				cout<<" +";
			}
		}
		exit(0);
	}
	return 0;
}

int main(){
	int i,j,k,bias,range,ave;
	cin>>N>>K>>P;
	maxn=(int)pow(N-K+1,1/(double)P);
	ave=(int)pow((double)N/(double)K,1/(double)P);
	//cout<<maxn<<" "<<ave<<endl;
	round(0);
	cout<<"Impossible";
	return 0;
} 
