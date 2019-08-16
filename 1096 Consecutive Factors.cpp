#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	int i,j,N,tmp,max=0;
	vector<int> res;
	vector<int> now;
	cin>>N;
	if(N==2){
		cout<<1<<endl<<2;
		return 0;
	}
	for(i=2;i<=sqrt(N);i++){
		tmp=N;
		now.clear();
		for(j=i;j<=N;j++){
			if(tmp%j==0){
				tmp/=j;
				now.push_back(j);
			}else{
				if(now.size()>max){
					max=now.size();
					res.assign(now.begin(),now.end());
				}
				break;
			}
		}
	}
	if(res.size()==0){
		cout<<1<<endl<<N;
		return 0;
	}
	cout<<res.size()<<endl;
	for(i=0;i<res.size();i++){
		cout<<res[i];
		if(i!=res.size()-1){
			cout<<"*";
		}
	}
	return 0;
}
