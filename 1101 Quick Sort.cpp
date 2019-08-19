#include<iostream>
#include<set>
#include<map>
using namespace std;

int main(){
	int N,i,j;
	long long origin[100010];
	map<long long,int> num;
	map<long long,int> loc;
	long long rnum[100010];
	set<long long> R;
	set<long long> res;
	cin>>N;
	for(i=0;i<N;i++){
		//cin>>origin[i];
		scanf("%lld",&origin[i]);
		R.insert(origin[i]);
		loc[origin[i]]=i;
	}
	i=0;
	for(auto iter=R.begin();iter!=R.end();iter++,i++){
		num[*iter]=i;
		rnum[i]=*iter;
	}
	for(i=0;i<N;){
		if(i!=num[origin[i]]){
			if(loc[rnum[i]]>i){
				i=loc[rnum[i]]+1;
			}else{
				i++;
			}
			continue;
		}else{
			res.insert(origin[i]);
			i++;
		}
	}
	i=0;
	printf("%d\n",res.size());
	for(auto iter=res.begin();i<res.size();iter++,i++){
		if(i) printf(" ");
		printf("%lld",*iter);
	}
	return 0;
} 
