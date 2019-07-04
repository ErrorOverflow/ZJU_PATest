#include<iostream>

using namespace std;

int num[1010];
int M,N,K;
bool isNo=false;

int main(){
	int i,j,k,seq,pre;
	cin>>M>>N>>K;
	for(i=0;i<K;i++){
		seq=1;
		pre=0;
		isNo=false;
		bool isUsed[1010]={false};
		for(j=0;j<N;j++){
			cin>>num[j];
			if(num[j]==pre-1){
				seq++;
				if(seq>M){
					isNo=true;
					//cout<<seq<<" ";
				}
			}else{
				seq=1;
			}
			if(pre>num[j]){
				for(k=num[j]+1;k<pre;k++){
					if(!isUsed[k]){
						isNo=true;
						//cout<<"list ";
						break;
					}
				}
			}
			pre=num[j];
			isUsed[num[j]]=true;
		}
		if(isNo)
			cout<<"No"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
} 
