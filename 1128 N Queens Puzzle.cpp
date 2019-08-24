#include<iostream>
#include<set>
using namespace std;

int main(){
	int N,K,q,i,j;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>K;
		set<int> row;
		set<int> dia;
		bool isSolu=true;
		for(j=0;j<K;j++){
			cin>>q;
			if(!isSolu){
				continue;
			}
			//cout<<q<<" "<<q+j<<endl;
			if(row.find(q)!=row.end() || dia.find(q+j)!=dia.end()){
				cout<<"NO"<<endl;
				isSolu=false;
			}
			row.insert(q);
			dia.insert(q+j);
		}
		if(isSolu){
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
