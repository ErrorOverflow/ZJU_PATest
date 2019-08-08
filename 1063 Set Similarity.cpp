#include<iostream>
#include<set>

using namespace std;

set<int> num[51];

int main(){
	int i,j,N,M,K,a,b,n,dif,common;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>M;
		for(j=0;j<M;j++){
			cin>>n;
			if(num[i].find(n)==num[i].end()){
				num[i].insert(n);
			}
		}
	}
	cin>>K;
	for(i=0;i<K;i++){
		cin>>a>>b;
		a--;b--;
		dif=0,common=0;
		//cout<<num[a].size()<<"size"<<num[b].size()<<endl;
		if(num[a].size()<num[b].size()){
			auto iter=num[a].begin();
			dif+=num[b].size();
			while(iter!=num[a].end()){
				if(num[b].find(*iter)==num[b].end()){
					dif++;
				}else{
					common++;
				}
				iter++;
				//cout<<common<<" "<<dif<<endl;
			}
		}else{
			auto iter=num[b].begin();
			dif+=num[a].size();
			while(iter!=num[b].end()){
				if(num[a].find(*iter)==num[a].end()){
					dif++;
				}else{
					common++;
				}
				iter++;
			}			
		}
		printf("%.1f\%\n",float(common)/float(dif)*100);
	}
	return 0;
}
