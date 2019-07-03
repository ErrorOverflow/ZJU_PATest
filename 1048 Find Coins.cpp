#include<iostream>
#include<set>

using namespace std;

set<int> coin;
int coinNum[100100]={0};

int main(){
	int N,M,i,tmp;
	cin>>N>>M;
	for(i=0;i<N;i++){
		cin>>tmp;
		if(coin.find(tmp)!=coin.end()){
			coinNum[tmp]++;
		}else{
			coin.insert(tmp); 
		}
	}
	auto iter=coin.begin();
	auto end=coin.end();
	while(iter!=coin.end()){
		if(*iter+*iter==M && coinNum[*iter]>0){
			cout<<*iter<<" "<<*iter;
			return 0;
		}
		end=coin.end();
		end--;
		while(end!=iter){
			if(*iter+*end<M){
				break;
			}else if(*iter+*end==M){
				cout<<*iter<<" "<<*end;
				return 0;
			}
			end--;
		}	
		iter++;
	}
	cout<<"No Solution";
	return 0;
} 
