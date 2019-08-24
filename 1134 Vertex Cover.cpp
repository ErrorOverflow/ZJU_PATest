#include<iostream>
#include<set>
using namespace std;

int main(){
	int i,j,t,k,a,b,N,M,Q;
	cin>>N>>M;
	int cover[M][2];
	bool isR;
	for(i=0;i<M;i++){
		cin>>a>>b;
		cover[i][0]=a;
		cover[i][1]=b;
	}
	cin>>Q;
	for(i=0;i<Q;i++){
		cin>>k;
		set<int> list;
		for(j=0;j<k;j++){
			cin>>a;
			list.insert(a);
		}
		isR=true; 
		for(j=0;j<M;j++){
			if(list.find(cover[j][0])==list.end() && list.find(cover[j][1])==list.end()){
				isR=false;
				cout<<"No"<<endl;
				break;
			}
		}
		if(isR){
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
