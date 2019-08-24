#include<iostream>
#include<map>
#include<cmath>

using namespace std;

int main(){
	int N,K,i,j,k;
	string id;
	map<string,int> ranklist;
	map<string,bool> check;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>id;
		ranklist.insert(pair<string,int>(id,i));
	}
	cin>>K;
	for(i=0;i<K;i++){
		cin>>id;
		if(ranklist.find(id)==ranklist.end()){
			cout<<id<<": Are you kidding?"<<endl;
		}else{
			if(check.find(id)==check.end()){
				check.insert(pair<string,bool>(id,true));
				j=ranklist.find(id)->second;
				bool isPrime=true;
				if(j==0){
					cout<<id<<": Mystery Award"<<endl;
					continue;
				}else{
					j++;
					if(j==2){
						cout<<id<<": Minion"<<endl;
						continue;
					}
					if(j%2==0){
						cout<<id<<": Chocolate"<<endl;
						continue;
					}
					for(k=3;k<=sqrt(j);k+=2){
						if(j%k==0){
							cout<<id<<": Chocolate"<<endl;
							isPrime=false;
							break;
						}
					}
					if(isPrime){
						cout<<id<<": Minion"<<endl;
					}
				}
			}else{
				cout<<id<<": Checked"<<endl;
			}
		}
	}
} 
