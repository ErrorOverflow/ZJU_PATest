#include<iostream>
#include<vector>
#include<malloc.h>

using namespace std;

vector<int*> res;

int main(){
	int i,j,N,pay,total=0,min=-1;
	int chain[100010];
	cin>>N>>pay;
	for(i=0;i<N;i++){
		cin>>chain[i];
	}
	for(i=0;i<N;i++){
		for(j=i;j<N;j++){
			total+=chain[j];
			if(total>=pay){
				if(min==-1 || min==total){
					min=total;
					int* tmp=(int *)malloc(2*sizeof(int));
					tmp[0]=i;
					tmp[1]=j;
					res.push_back(tmp);
				}
				else if(min>total){
					res.clear();
					min=total;
					int* tmp=(int *)malloc(2*sizeof(int));
					tmp[0]=i;
					tmp[1]=j;
					res.push_back(tmp);
				}
				break;
			}	
		}
		total=0;
	}
	for(i=0;i<res.size();i++){
		cout<<res[i][0]+1<<"-"<<res[i][1]+1;
		if(i!=res.size()-1){
			cout<<endl;
		}
	}
	return 0;
} 
