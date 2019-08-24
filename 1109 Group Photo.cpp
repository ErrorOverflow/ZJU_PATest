#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

map<int,set<string>> list;

int main(){
	int N,r,i,j,k,tall,size;
	string name;
	cin>>N>>r;
	for(i=0;i<N;i++){
		cin>>name>>tall;
		if(list.find(tall)==list.end()){
			set<string> settmp;
			settmp.insert(name);
			list.insert(pair<int,set<string>>(tall,settmp));
		}else{
			list.find(tall)->second.insert(name);
		}
	}
	string row[21];
	auto iter=list.rbegin();
	int p;
	bool isFill;
	auto it=iter->second.begin();
	for(i=0;i<N/r;i++){
		if(i==0){
			size=r+N%r;
		}else{
			size=r;
		}
		isFill=false;
		p=size/2;
		k=0;
		while(true){
			for(;it!=iter->second.end();it++){
				row[p+k]=*it;
				//cout<<i<<" "<<p+k<<endl;
				if((p+k==0 && size%2==0) || (p+k==size-1 && size%2==1)){
					isFill=true;
					it++;
					break;
				} 
				k*=-1; 
				if(k>=0){
					k-=1;
				}
			}
			if(isFill){
				break;
			}
			iter++;
			it=iter->second.begin();
		}
		for(j=0;j<size;j++){
			cout<<row[j];
			if(j!=size-1){
				cout<<" ";
			}
		}
		if(i!=N/r-1){
			cout<<endl;
		}
	}
	return 0;
} 
